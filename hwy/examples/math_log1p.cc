// Copyright 2020 Google LLC
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>

#include <cfloat>  // FLT_MAX
#include <cmath>   // std::abs

// clang-format off
#undef HWY_TARGET_INCLUDE
#define HWY_TARGET_INCLUDE "hwy/examples/math_log1p.cc"
#include "hwy/foreach_target.h"  // IWYU pragma: keep
#include "hwy/highway.h"
#include "hwy/contrib/math/math-inl.h"
#include "hwy/tests/test_util-inl.h"
// clang-format on

HWY_BEFORE_NAMESPACE();
namespace hwy {
namespace HWY_NAMESPACE {

template <class Out, class In>
inline Out BitCast(const In& in) {
  static_assert(sizeof(Out) == sizeof(In), "");
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}

template <class T, class D>
HWY_NOINLINE void TestMath(const char* name, T (*fx1)(T),
                           Vec<D> (*fxN)(D, VecArg<Vec<D>>), D d, T min, T max,
                           uint64_t max_error_ulp) {
  using UintT = MakeUnsigned<T>;

  const UintT min_bits = BitCast<UintT>(min);
  const UintT max_bits = BitCast<UintT>(max);

  // If min is negative and max is positive, the range needs to be broken into
  // two pieces, [+0, max] and [-0, min], otherwise [min, max].
  int range_count = 1;
  UintT ranges[2][2] = {{min_bits, max_bits}, {0, 0}};
  if ((min < 0.0) && (max > 0.0)) {
    ranges[0][0] = BitCast<UintT>(static_cast<T>(+0.0));
    ranges[0][1] = max_bits;
    ranges[1][0] = BitCast<UintT>(static_cast<T>(-0.0));
    ranges[1][1] = min_bits;
    range_count = 2;
  }

  uint64_t max_ulp = 0;
  // Emulation is slower, so cannot afford as many.
  constexpr UintT kSamplesPerRange = static_cast<UintT>(AdjustedReps(4000));
  for (int range_index = 0; range_index < range_count; ++range_index) {
    const UintT start = ranges[range_index][0];
    const UintT stop = ranges[range_index][1];
    const UintT step = HWY_MAX(1, ((stop - start) / kSamplesPerRange));
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      // For reasons unknown, the HWY_MAX is necessary on RVV, otherwise
      // value_bits can be less than start, and thus possibly NaN.
      const T value = BitCast<T>(HWY_MIN(HWY_MAX(start, value_bits), stop));
      const T actual = GetLane(fxN(d, Set(d, value)));
      const T expected = fx1(value);

      // Skip small inputs and outputs on armv7, it flushes subnormals to zero.
#if HWY_TARGET <= HWY_NEON_WITHOUT_AES && HWY_ARCH_ARM_V7
      if ((std::abs(value) < 1e-37f) || (std::abs(expected) < 1e-37f)) {
        continue;
      }
#endif

      const auto ulp = hwy::detail::ComputeUlpDelta(actual, expected);
      max_ulp = HWY_MAX(max_ulp, ulp);
      if (ulp > max_error_ulp) {
        fprintf(stderr, "KO %s: %s(%.17g) expected %.17g actual %.17g ulp %g max ulp %u\n",
                hwy::TypeName(T(), Lanes(d)).c_str(), name, value, expected,
                actual, static_cast<double>(ulp),
                static_cast<uint32_t>(max_error_ulp));
	if( value == 5.526720574244119e-20 && expected == 5.526720574244119e-20 && actual == 0) exit(42);
      } else {
        fprintf(stderr, "OK %s: %s(%.17g) expected %.17g actual %.17g ulp %g max ulp %u\n",
                hwy::TypeName(T(), Lanes(d)).c_str(), name, value, expected,
                actual, static_cast<double>(ulp),
                static_cast<uint32_t>(max_error_ulp));

      }
    }
  }
  fprintf(stderr, "%s: %s max_ulp %g\n", hwy::TypeName(T(), Lanes(d)).c_str(),
          name, static_cast<double>(max_ulp));
  //HWY_ASSERT(max_ulp <= max_error_ulp);
}

#define DEFINE_MATH_TEST_FUNC(NAME)                 \
  HWY_NOINLINE void TestAll##NAME() {               \
    ForFloatTypes(ForPartialVectors<Test##NAME>()); \
  }

#undef DEFINE_MATH_TEST
#define DEFINE_MATH_TEST(NAME, F32x1, F32xN, F32_MIN, F32_MAX, F32_ERROR, \
                         F64x1, F64xN, F64_MIN, F64_MAX, F64_ERROR)       \
  struct Test##NAME {                                                     \
    template <class T, class D>                                           \
    HWY_NOINLINE void operator()(T, D d) {                                \
      if (sizeof(T) == 4) {                                               \
        TestMath<T, D>(HWY_STR(NAME), F32x1, F32xN, d, F32_MIN, F32_MAX,  \
                       F32_ERROR);                                        \
      } else {                                                            \
        TestMath<T, D>(HWY_STR(NAME), F64x1, F64xN, d,                    \
                       static_cast<T>(F64_MIN), static_cast<T>(F64_MAX),  \
                       F64_ERROR);                                        \
      }                                                                   \
    }                                                                     \
  };                                                                      \
  DEFINE_MATH_TEST_FUNC(NAME)

// Floating point values closest to but less than 1.0
const float kNearOneF = BitCast<float>(0x3F7FFFFF);
const double kNearOneD = BitCast<double>(0x3FEFFFFFFFFFFFFFULL);

// clang-format off
DEFINE_MATH_TEST(Log1p,
  std::log1p, CallLog1p, +0.0f,      +1e37f,      3,  // NEON is 3 instead of 2
  std::log1p, CallLog1p, +0.0,       +DBL_MAX,    2)
// clang-format on


// NOLINTNEXTLINE(google-readability-namespace-comments)
}  // namespace HWY_NAMESPACE
}  // namespace hwy
HWY_AFTER_NAMESPACE();

#if HWY_ONCE

namespace hwy {
HWY_EXPORT(TestAllLog1p);
void Run() {
  for (int64_t target : SupportedAndGeneratedTargets()) {
    SetSupportedTargetsForTest(target);
    HWY_DYNAMIC_DISPATCH(TestAllLog1p)();
  }
  SetSupportedTargetsForTest(0);  // Reset the mask afterwards.
}


}  // namespace hwy

int main(int /*argc*/, char** /*argv*/) {
  hwy::Run();
  return 0;
}

#endif

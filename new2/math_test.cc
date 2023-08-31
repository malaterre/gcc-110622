#include "hwy/highway.h"
// Copyright 2021 Google LLC
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

#ifndef HWY_TESTS_TEST_UTIL_H_
#define HWY_TESTS_TEST_UTIL_H_

// Target-independent helper functions for use by *_test.cc.

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <cmath>  // std::isnan
#include <string>

#include "hwy/aligned_allocator.h"
#include "hwy/base.h"
#include "hwy/highway.h"
#include "hwy/highway_export.h"
#include "hwy/print.h"

namespace hwy {

// The maximum vector size used in tests when defining test data. DEPRECATED.
//constexpr size_t kTestMaxVectorSize = 64;

// 64-bit random generator (Xorshift128+). Much smaller state than std::mt19937,
// which triggers a compiler bug.
class RandomState {
 public:
  explicit RandomState(const uint64_t seed = 0x123456789ull) {
    s0_ = SplitMix64(seed + 0x9E3779B97F4A7C15ull);
    s1_ = SplitMix64(s0_);
  }

  HWY_INLINE uint64_t operator()() {
    uint64_t s1 = s0_;
    const uint64_t s0 = s1_;
    const uint64_t bits = s1 + s0;
    s0_ = s0;
    s1 ^= s1 << 23;
    s1 ^= s0 ^ (s1 >> 18) ^ (s0 >> 5);
    s1_ = s1;
    return bits;
  }

 private:
  static uint64_t SplitMix64(uint64_t z) {
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ull;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBull;
    return z ^ (z >> 31);
  }

  uint64_t s0_;
  uint64_t s1_;
};

HWY_TEST_DLLEXPORT bool BytesEqual(const void* p1, const void* p2,
                                   const size_t size, size_t* pos = nullptr);

void AssertStringEqual(const char* expected, const char* actual,
                       const char* target_name, const char* filename, int line);

namespace detail {

template <typename T, typename TU = MakeUnsigned<T>>
TU ComputeUlpDelta(const T expected, const T actual) {
  // Handle -0 == 0 and infinities.
  if (expected == actual) return 0;

  // Consider "equal" if both are NaN, so we can verify an expected NaN.
  // Needs a special case because there are many possible NaN representations.
  if (std::isnan(expected) && std::isnan(actual)) return 0;

  // Compute the difference in units of last place. We do not need to check for
  // differing signs; they will result in large differences, which is fine.
  TU ux, uy;
  CopySameSize(&expected, &ux);
  CopySameSize(&actual, &uy);

  // Avoid unsigned->signed cast: 2's complement is only guaranteed by C++20.
  const TU ulp = HWY_MAX(ux, uy) - HWY_MIN(ux, uy);
  return ulp;
}

HWY_TEST_DLLEXPORT bool IsEqual(const TypeInfo& info, const void* expected_ptr,
                                const void* actual_ptr);

HWY_TEST_DLLEXPORT HWY_NORETURN void PrintMismatchAndAbort(
    const TypeInfo& info, const void* expected_ptr, const void* actual_ptr,
    const char* target_name, const char* filename, int line, size_t lane = 0,
    size_t num_lanes = 1);

HWY_TEST_DLLEXPORT void AssertArrayEqual(const TypeInfo& info,
                                         const void* expected_void,
                                         const void* actual_void, size_t N,
                                         const char* target_name,
                                         const char* filename, int line);

}  // namespace detail

// Returns a name for the vector/part/scalar. The type prefix is u/i/f for
// unsigned/signed/floating point, followed by the number of bits per lane;
// then 'x' followed by the number of lanes. Example: u8x16. This is useful for
// understanding which instantiation of a generic test failed.
template <typename T>
std::string TypeName(T /*unused*/, size_t N) {
  char string100[100];
  detail::TypeName(detail::MakeTypeInfo<T>(), N, string100);
  return string100;
}

// Compare non-vector, non-string T.
template <typename T>
HWY_INLINE bool IsEqual(const T expected, const T actual) {
  const auto info = detail::MakeTypeInfo<T>();
  return detail::IsEqual(info, &expected, &actual);
}

template <typename T>
HWY_INLINE void AssertEqual(const T expected, const T actual,
                            const char* target_name, const char* filename,
                            int line, size_t lane = 0) {
  const auto info = detail::MakeTypeInfo<T>();
  if (!detail::IsEqual(info, &expected, &actual)) {
    detail::PrintMismatchAndAbort(info, &expected, &actual, target_name,
                                  filename, line, lane);
  }
}

template <typename T>
HWY_INLINE void AssertArrayEqual(const T* expected, const T* actual,
                                 size_t count, const char* target_name,
                                 const char* filename, int line) {
  const auto info = hwy::detail::MakeTypeInfo<T>();
  detail::AssertArrayEqual(info, expected, actual, count, target_name, filename,
                           line);
}

}  // namespace hwy

#endif  // HWY_TESTS_TEST_UTIL_H_
namespace hwy {
namespace N_EMU128 {
template <class v, class w> w ad(v d, w x) { return ae(d, x); }
template <class> struct ag {
  template <class v, class w> Vec<Rebind<int32_t, v>> ah(v, w x) {
    Rebind<int32_t, v> ai, aj;
    auto ak = Set(ai, 5);
    BitCast(aj, x);
    return ak;
  }
};
template <class v, class w, int> w at(w x) {
  v d;
  using au = TFromD<v>;
  ag<au> af;
  bool av = 0;
  w aw, ax, ay = Set(d, 1.0), az, ba, bj;
  using bb = MakeSigned<au>;
  Rebind<bb, v> bc;
  using bd = decltype(Zero(bc));
  bd be = Set(bc, 4294967295);
  bd bf;
  bd bg;
  bd bh;
  bd z = Set(bc, av);
  bd bi;
  auto bk = Lt(x, az);
  IfThenElse(bk, ba, x);
  bd bl = bh;
  Add(bl, af.ah(d, bi));
  Sub(bg, bf);
  w y = Or(And(x, BitCast(d, be)), BitCast(d, z));
  w bm = Sub(y, ay);
  return MulSub(bj, aw, Sub(ax, bm));
}
template <class v, class w> w ae(v d, w x) {
  using au = TFromD<v>;
  w ay = Set(d, au(1.0)), y = Add(x, ay), bp = at<v, w, false>(y);
  auto bn = Eq(y, ay);
  auto bo = Sub(IfThenZeroElse(bn, y), ay);
  auto bq = Mul(bp, Div(x, bo));
  return IfThenElse(bn, x, bq);
}
} // namespace HWY_NAMESPACE
} // namespace hwy
namespace hwy {
namespace N_EMU128 {
template <typename au, size_t, size_t br, class bs> struct bt {
  static void bu(size_t bv, size_t bw) {
    CappedTag<au, br> d;
    size_t bx = Lanes(d);
    if (bx < bv)
      return;
    if (bw)
      bs()(int(), d);
  }
};
template <class bs> class by {
public:
  template <typename au> void operator()(au t) {
    (void)t;
    bt<au, 1, 1, bs>::bu(1, 1);
  }
};
struct ca;
by<ca> bz;
template <class a, class b> a al(b c) {
  a f;
  CopyBytes<sizeof(f)>(&c, &f);
  return f;
}
template <class e, class h>
void am(e an(e), Vec<h> g(h, VecArg<Vec<h>>), h d, e k, e i, uint64_t j) {
  using l = MakeUnsigned<e>;
  l m(k), n = al<l>(i), s(4000);
  l o[][2]{{m, n}};
  uint64_t p = 0;
  for (int ao = 0; ao < 1; ++ao) {
    l ap = o[ao][0], aq = o[ao][1], ar(s);
    for (l as = ap; as <= aq; as += ar) {
      e q = al<e>(as), ab = an(q);
      VFromD<h> r = Set(d, q);
      e aa = GetLane(g(d, r));
      auto ac = hwy::detail::ComputeUlpDelta(aa, ab);
      p = p ?: ac;
    }
  }
  if (!(p <= j))
    Abort("", 9, "r <= m");
}
struct ca {
  template <class e, class h> void operator()(e, h d) {
    am(log1p, ad, d, 0.0f, 1e37f, 3);
  }
};
void u() { bz(float()); }
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() { hwy::N_EMU128::u(); }

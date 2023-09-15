#include "hwy/contrib/math/math-inl.h"
#include "hwy/tests/test_util-inl.h"
namespace hwy {
namespace HWY_NAMESPACE {
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class T, class D>
void TestMath(const char *name, T fx1(T), Vec<D> fxN(D, VecArg<Vec<D>>), D d,
              T min, T max, uint64_t max_error_ulp) {
  using UintT = MakeUnsigned<T>;
  UintT min_bits(min);
  UintT max_bits = BitCast<UintT>(max);
  UintT ranges[][2]{{min_bits, max_bits}};
  uint64_t max_ulp = 0;
  UintT kSamplesPerRange(4000);
  for (int range_index = 0; range_index < 1; ++range_index) {
    UintT start = ranges[range_index][0];
    UintT stop = ranges[range_index][1];
    UintT step(stop / kSamplesPerRange);
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      T value = BitCast<T> HWY_MIN(value_bits, stop);
      T actual = GetLane(fxN(d, Set(d, value)));
      T expected = fx1(value);
      auto ulp = hwy::detail::ComputeUlpDelta(actual, expected);
      max_ulp = HWY_MAX(max_ulp, ulp);
      int __trans_tmp_1(max_error_ulp);
      fprintf(
          stderr,
          "%s: %s(%.17g) expected %.17g actual %.17g ulp %.17g max ulp %u\n",
          TypeName(T(), 0).c_str(), name, value, expected, actual, double(ulp),
          __trans_tmp_1);
    }
  }
}
#define DEFINE_MATH_TEST(NAME, F32x1, F32xN, F32_MIN, F32_MAX, F32_ERROR,      \
                         F64x1, F64xN, F64_MIN, F64_MAX, F64_ERROR)            \
  struct Test##NAME {                                                          \
    template <class T, class D> void operator()(T, D d) {                      \
      TestMath(HWY_STR(NAME), F64x1, F64xN, d, F64_MIN, F64_MAX, F64_ERROR);   \
    }                                                                          \
  }
double kNearOneD;
uint64_t Cos64ULP;
                                DEFINE_MATH_TEST(Log1p, , , , , , log1p,
                                                 CallLog1p, 0.0, DBL_MAX, 2);
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() {
  double b1{};
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::N_EMU128::TestLog1p testLog1p;
  testLog1p(b1, b2);
}

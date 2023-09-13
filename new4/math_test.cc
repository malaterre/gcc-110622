#include "hwy/contrib/math/math-inl.h"
#include "hwy/tests/test_util-inl.h"
namespace hwy {
namespace HWY_NAMESPACE {
template < class Out, class In > Out BitCast(const In in) {
  Out out;
  CopyBytes< sizeof(out) >(&in, &out);
  return out;
}
template < class T, class D >
void TestMath(const char *name, T (fx1)(T),
                           Vec< D > (fxN)(D, VecArg< Vec< D > >), D d, T min,
                           T max, uint64_t max_error_ulp) {
  using UintT = MakeUnsigned< T >;
  UintT min_bits = BitCast< UintT >(min);
  UintT max_bits = BitCast< UintT >(max);
  int range_count = 1;
  UintT ranges[][2] {{min_bits, max_bits}};
  uint64_t max_ulp = 0;
  UintT kSamplesPerRange = static_cast< UintT >((4000));
  for (int range_index = 0; range_index < range_count; ++range_index) {
    UintT start = ranges[range_index][0];
    UintT stop = ranges[range_index][1];
    UintT step HWY_MAX(1, ((stop - start) / kSamplesPerRange));
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      T value = BitCast< T >(HWY_MIN(HWY_MAX(start, value_bits), stop));
      T actual = GetLane(fxN(d, Set(d, value)));
      T expected = fx1(value);
      auto ulp = hwy::detail::ComputeUlpDelta(actual, expected);
      max_ulp = HWY_MAX(max_ulp, ulp);
      if (ulp > max_error_ulp)
        fprintf(
            stderr,
            "%s: %s(%.17g) expected %.17g actual %.17g ulp %.17g max ulp %u\n",
            hwy::TypeName(T(), 0).c_str(), name, value, expected, actual,
            static_cast< double >(ulp), static_cast< uint32_t >(max_error_ulp));
    }
  }
}
#define DEFINE_MATH_TEST_FUNC() void TestAll##NAME();
#define DEFINE_MATH_TEST(NAME, F32x1, F32xN, F32_MIN, F32_MAX, F32_ERROR,                               F64x1, F64xN, F64_MIN, F64_MAX, F64_ERROR)              struct Test##NAME {                                                              template < class T, class D > void operator()(T, D d) {             TestMath(HWY_STR(NAME), F64x1, F64xN, d, static_cast< T >(F64_MIN),                     static_cast< T >(F64_MAX), F64_ERROR);                              }                                                                            };                                                                             DEFINE_MATH_TEST_FUNC()
double kNearOneD = BitCast< double >(0x3FEFFFFFFFFFFFFFULL);
uint64_t Cos64ULP();
DEFINE_MATH_TEST(, , , , , , ::acos,
                 CallAcos, 1.0, 1.0, 2)
DEFINE_MATH_TEST(Acosh, , , , , ,
                 ::acosh, CallAcosh, 1.0, DBL_MAX,
                 3) DEFINE_MATH_TEST(Asin, , , , , ,
                                     ::asin, CallAsin, 1.0, 1.0, 2)
    DEFINE_MATH_TEST(Asinh, , , , , ,
                     ::asinh, CallAsinh, DBL_MAX, DBL_MAX,
                     3) DEFINE_MATH_TEST(Atan, std::atan, CallAtan, -FLT_MAX,
                                         +FLT_MAX, 3, std::atan, CallAtan,
                                         -DBL_MAX, +DBL_MAX, 3)
        DEFINE_MATH_TEST(Atanh, std::atanh, CallAtanh, -kNearOneF, +kNearOneF,
                         4, std::atanh, CallAtanh, -kNearOneD, +kNearOneD, 3)
            DEFINE_MATH_TEST(Cos, std::cos, CallCos, -39000.0f, +39000.0f, 3,
                             std::cos, CallCos, -39000.0, +39000.0, Cos64ULP)
                DEFINE_MATH_TEST(Exp, std::exp, CallExp, -FLT_MAX, +104.0f, 1,
                                 std::exp, CallExp, -DBL_MAX, +104.0, 1)
                    DEFINE_MATH_TEST(Expm1, std::expm1, CallExpm1, -FLT_MAX,
                                     +104.0f, 4, std::expm1, CallExpm1,
                                     -DBL_MAX, +104.0, 4)
                        DEFINE_MATH_TEST(Log, std::log, CallLog, +FLT_MIN,
                                         +FLT_MAX, 1, std::log, CallLog,
                                         +DBL_MIN, +DBL_MAX, 1)
                            DEFINE_MATH_TEST(Log10, std::log10, CallLog10,
                                             +FLT_MIN, +FLT_MAX, 2, std::log10,
                                             CallLog10, +DBL_MIN, +DBL_MAX, 2)
                                DEFINE_MATH_TEST(Log1p, std::log1p, CallLog1p,
                                                 +0.0f, +1e37f, 3, std::log1p,
                                                 CallLog1p, +0.0, +DBL_MAX, 2);
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() {
  double b1{};
  hwy::N_EMU128::Simd< double, 1u, 0 > b2;
  hwy::N_EMU128::TestLog1p testLog1p;
  testLog1p.operator()(b1, b2);
}

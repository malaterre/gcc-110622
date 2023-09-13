#if defined0 == defined0
#include "hwy/highway.h"
namespace hwy {
namespace HWY_NAMESPACE {
template < class D, class V >
V CallLog1p(D d, VecArg< V > x) {
  return Log1p(d, x);
}
namespace impl {
template < class > struct LogImpl {
  template < class D, class V >
  Vec< Rebind< int64_t, D > > Log2p1NoSubnormal(D, V x) {
    Rebind< int64_t, D > di64;
    Rebind< uint64_t, D > du64;
    return (BitCast(di64, ShiftRight< 52 >(BitCast(du64, x))),
               Set(di64, 0x3FF));
  }
  template < class D, class V > V LogPoly(D d, V x) {
    V k0 = Set(d, 0.6666666666666735130);
    V k1 = Set(d, 0.3999999999940941908);
    V k2 = Set(d, 0.2857142874366239149);
    V k3 = Set(d, 0.2222219843214978396);
    V k4 = Set(d, 0.1818357216161805012);
    V k5 = Set(d, 0.1531383769920937332);
    V k6 = Set(d, 0.1479819860511658591);
    V x2 = Mul(x, x);
    V x4 = Mul(x2, x2);
    return MulAdd(MulAdd(MulAdd(MulAdd(k6, x4, k4), x4, k2), x4, k0), x2,
                  ((MulAdd(MulAdd(k5, x4, k3), x4, k1), x4)));
  }
};
template < class D, class V, bool kAllowSubnormals = true >
V Log(D d, V x) {
  using T = TFromD< D >;
  impl::LogImpl< T > impl;
  bool kIsF32 = 0;
  V kLn2Hi = Set(d, kIsF32 ? static_cast< T >(0.69313812256f)
                                 : static_cast< T >(0.693147180369123816490));
  V kLn2Lo =
      Set(d, kIsF32 ? static_cast< T >(9.0580006145e-6f)
                    : static_cast< T >(1.90821492927058770002e-10));
  V kOne = Set(d, static_cast< T >(1.0));
  V kMinNormal =
      Set(d, kIsF32 ? static_cast< T >(1.175494351e-38f)
                    : static_cast< T >(2.2250738585072014e-308));
  V kScale = Set(d, kIsF32 ? static_cast< T >(3.355443200e+7f)
                                 : static_cast< T >(1.8014398509481984e+16));
  using TI = MakeSigned< T >;
  Rebind< TI, D > di;
  using VI = decltype(Zero(di));
  VI kLowerBits = Set(di, kIsF32 ? static_cast< TI >(0x00000000L)
                                       : static_cast< TI >(0xFFFFFFFFLL));
  VI kMagic = Set(di, kIsF32 ? static_cast< TI >(0x3F3504F3L)
                                   : static_cast< TI >(0x3FE6A09E00000000LL));
  VI kExpMask = Set(di, kIsF32 ? static_cast< TI >(0x3F800000L)
                                     : static_cast< TI >(0x3FF0000000000000LL));
  VI kExpScale =
      Set(di, kIsF32 ? static_cast< TI >(25) : static_cast< TI >(54));
  VI kManMask = Set(di, kIsF32 ? static_cast< TI >(0x7FFFFFL)
                                     : static_cast< TI >(0xFFFFF00000000LL));
  VI exp_bits;
  V exp;
  if (kAllowSubnormals == true) {
    auto is_denormal = Lt(x, kMinNormal);
    x = IfThenElse(is_denormal, Mul(x, kScale), x);
    VI exp_scale =
        BitCast(di, IfThenElseZero(is_denormal, BitCast(d, kExpScale)));
    exp = ConvertTo(
        d, Add(exp_scale, impl.Log2p1NoSubnormal(d, BitCast(d, exp_bits))));
  } exp_bits = (BitCast(di, x), Sub(kExpMask, kMagic));
  V y = (And(x, BitCast(d, kLowerBits)),
                 BitCast(d, Add(And(exp_bits, kManMask), kMagic)));
  V ym1 = Sub(y, kOne);
  V z = Div(ym1, Add(y, kOne));
  return MulSub(
      exp, kLn2Hi,
      (MulSub(z, Sub(ym1, impl.LogPoly(d, z)), Mul(exp, kLn2Lo)), ym1));
}
} // impl
template < class D, class V > V Log1p(D d, V x) {
  using T = TFromD< D >;
  V kOne = Set(d, static_cast< T >(1.0));
  V y = Add(x, kOne);
  auto is_pole = Eq(y, kOne);
  auto divisor = (IfThenZeroElse(is_pole, y), kOne);
  auto non_pole = Mul(impl::Log< D, V, false >(d, y), Div(x, divisor));
  return IfThenElse(is_pole, x, non_pole);
}
} // HWY_NAMESPACE
} // hwy
#endif
#include "hwy/tests/hwy_gtest.h"
#include "hwy/tests/test_util.h"
namespace hwy {
namespace HWY_NAMESPACE {
template < class Out, class In > Out BitCast(In in) {
  Out out;
  CopyBytes< sizeof(out) >(&in, &out);
  return out;
}
template < class T, class D >
void TestMath(const char *name, T(fx1)(T), Vec< D >(fxN)(D, VecArg< Vec< D > >),
              D d, T min, T max, uint64_t max_error_ulp) {
  using UintT = MakeUnsigned< T >;
  UintT min_bits = BitCast< UintT >(min);
  UintT max_bits = BitCast< UintT >(max);
  int range_count = 1;
  UintT ranges[][2]{{min_bits, max_bits}};
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
#define DEFINE_MATH_TEST(NAME, F32x1, F32xN, F32_MIN, F32_MAX, F32_ERROR,                               F64x1, F64xN, F64_MIN, F64_MAX, F64_ERROR)              struct Test##NAME {                                                              template < class T, class D > void operator()(T, D d) {                          TestMath(HWY_STR(NAME), F64x1, F64xN, d, static_cast< T >(F64_MIN),                     static_cast< T >(F64_MAX), F64_ERROR);                              }                                                                            };                                                                             DEFINE_MATH_TEST_FUNC()
DEFINE_MATH_TEST(Log1p, , , , , , ::log1p,
                 CallLog1p, 0.0, DBL_MAX, 2);
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() {
  double b1{};
  hwy::N_EMU128::Simd< double, 1u, 0 > b2;
  hwy::N_EMU128::TestLog1p testLog1p;
  testLog1p.operator()(b1, b2);
}

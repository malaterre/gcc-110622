#include "hwy/highway.h"
#include <cstdio>
#include <inttypes.h>
#include <cassert>
#include <cfenv>
namespace hwy {
namespace HWY_NAMESPACE {
template <class D, class V> V CallLog1p(D d, V x) { return Log1p(d, x); }
namespace impl {
template <class> struct LogImpl {
  template <class D, class V>
  Vec<Rebind<int64_t, D>> Log2p1NoSubnormal(D, V x) {
    Rebind<int64_t, D> di64;
    Rebind<uint64_t, D> du64;
    return Sub(BitCast(di64, ShiftRight<52>(BitCast(du64, x))),
               Set(di64, 1023));
  }
  template <class D, class V> V LogPoly(D d, V x) {
    V k0 = Set(d, 0.6666666666666735130), k2 = Set(d, 0.2857142874366239149),
      k3 = Set(d, 0.2222219843214978396), k4 = Set(d, 0.1818357216161805012),
      k5 = Set(d, 0.1531383769920937332), x2 = Mul(x, x), x4 = Mul(x2, x2),
      k1 = Set(d, 0.3999999999940941908), k6 = Set(d, 0.1479819860511658591);
    return MulAdd(MulAdd(MulAdd(MulAdd(k6, x4, k4), x4, k2), x4, k0), x2,
                  Mul(MulAdd(MulAdd(k5, x4, k3), x4, k1), x4));
  }
};
template <class D, class V, bool> HWY_INLINE V Log(D d, V x) {
  using T = TFromD<D>;
  LogImpl<T> impl;
  V kLn2Hi = Set(d, 0.693147180369123816490);
  V kLn2Lo = Set(d, 1.90821492927058770002e-10);
  V kOne = Set(d, 1.0);
  using TI = MakeSigned<T>;
  Rebind<TI, D> di;
  using VI = decltype(Zero(di));
  VI kLowerBits = Set(di, 4294967295);
  VI kMagic = Set(di, 4604544269498187776);
  VI kExpMask = Set(di, 4607182418800017408);
  VI kManMask = Set(di, 4503595332403200);
  VI exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
  V exp = ConvertTo(d, impl.Log2p1NoSubnormal(d, exp_bits));
  V y = Or(And(x, BitCast(d, kLowerBits)),
           BitCast(d, Add(And(exp_bits, kManMask), kMagic)));
  V ym1 = Sub(y, kOne);
  V z = Div(ym1, Add(y, kOne));
  return MulSub(
      exp, kLn2Hi,
      Sub(MulSub(z, Sub(ym1, impl.LogPoly(d, z)), Mul(exp, kLn2Lo)), ym1));
}
} // namespace impl
template <class D, class V> V Log1p(D d, V x) {
  using T = TFromD<D>;
  V kOne = Set(d, T(1.0));
  const V y = Add(x, kOne);
  auto is_pole = Eq(y, kOne);
#if 0
  auto divisor = Sub(IfThenZeroElse(is_pole, y), kOne);
#else
  auto tmp1 = IfThenZeroElse(is_pole, y);
  volatile auto dbg4 = tmp1;
  volatile auto dbg5 = kOne;
  auto divisor = Sub(tmp1, kOne);
  volatile auto dbg6 = divisor;
  (void)dbg4;
  (void)dbg5;
  (void)dbg6;
#endif
#if 1
  auto non_pole = Mul(impl::Log<D, V, false>(d, y), Div(x, divisor));
#else
  volatile auto dbg3 = y;
  volatile auto dbg0 = divisor;
  auto tmp1 = impl::Log<D, V, false>(d, y);
  auto tmp2 = Div(x, divisor);
  volatile auto dbg1 = tmp1;
  volatile auto dbg2 = tmp2;
  (void)dbg0;
  (void)dbg1;
  (void)dbg2;
  (void)dbg3;
  auto non_pole = Mul( tmp1, tmp2);
#endif
  return IfThenElse(is_pole, x, non_pole);
}
} // namespace HWY_NAMESPACE
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class D> void TestMath(D d) {
  uint64_t kSamplesPerRange = 4000, start = 0, stop = 9218868437227405311;
  uint64_t step(stop / kSamplesPerRange);
  for (uint64_t value_bits = start; value_bits <= stop; value_bits += step) {
    double value = BitCast<double>(value_bits),
           actual = GetLane(CallLog1p(d, Set(d, value))),
           expected = log1p(value);
#if 1
    fprintf(stderr,
            "%" PRIu64 " - Log1p(%.17g) expected %.17g actual %.17g %a\n",
            value_bits, value, expected, actual, actual);
#else
    (void)actual;
    (void)expected;
    assert( actual >= 0.0 );
#endif
  }
}
} // namespace hwy
int main() {
  feenableexcept(FE_INVALID | FE_DIVBYZERO );
//  feenableexcept( FE_INVALID );
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::TestMath(b2);
}

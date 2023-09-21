#include <cmath>
#include <cstdio>
#include <inttypes.h>
template <size_t kBytes, typename From, typename To>
static void CopyBytes(From from, To to) {
  __builtin_memcpy(to, static_cast<void *>(from), kBytes);
}
template <typename From, typename To>
static void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
struct Relations {
  using Unsigned = uint64_t;
  using Signed = int64_t;
};
template <typename> using MakeUnsigned = Relations::Unsigned;
template <typename> using MakeSigned = Relations::Signed;
namespace N_EMU128 {
template <typename Lane, size_t, int> struct Simd {
  using T = Lane;
  static constexpr size_t kPrivateLanes = 1;
  template <typename> static constexpr int RebindPow2() { return 0; }
  template <int, size_t> static constexpr size_t NewN() { return 0; }
  template <typename NewT>
  using Rebind =
      Simd<NewT, NewN<RebindPow2<NewT>(), kPrivateLanes>(), RebindPow2<NewT>()>;
};
template <class D> using TFromD = typename D::T;
#define HWY_MAX_LANES_D(D) D::kPrivateLanes
template <class D> size_t MaxLanes(D) { return HWY_MAX_LANES_D(D); }
template <class T, class D> using Rebind = typename D::template Rebind<T>;
template <class D> using RebindToUnsigned = Rebind<MakeUnsigned<D>, D>;
template <typename T, size_t N> struct Vec128 {
  using PrivateT = T;
  static constexpr size_t kPrivateN = N;
  T raw[16 / sizeof(T)]{};
};
template <typename T, size_t = sizeof(T)> struct Mask128 {
  using Raw = MakeUnsigned<T>;
  static Raw FromBool(bool b) { return b ? ~Raw{} : 0; }
  Raw bits[16 / sizeof(T)];
};
template <class V> using DFromV = Simd<typename V::PrivateT, V::kPrivateN, 0>;
template <class D> Vec128<TFromD<D>, HWY_MAX_LANES_D(D)> Zero(D) {
  Vec128<TFromD<D>, HWY_MAX_LANES_D(D)> v;
  return v;
}
template <class D> using VFromD = decltype(Zero(D()));
template <class D, class VFrom> VFromD<D> BitCast(D, VFrom v) {
  VFromD<D> to;
  CopySameSize(&v, &to);
  return to;
}
template <class D, typename T2> VFromD<D> Set(D d, T2 t) {
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i)
    v.raw[i] = t;
  return v;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> And(Vec128<T, N> a,
                                                       Vec128<T, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a), bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return BitCast(d, au);
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Or(Vec128<T, N> a,
                                                      Vec128<T, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a), bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i)
    au.raw[i] |= bu.raw[i];
  return BitCast(d, au);
}
template <typename T, size_t N>
Vec128<T, N> IfVecThenElse(Vec128<T, N> mask, Vec128<T, N> yes,
                           Vec128<T, N> no) {
  Vec128<T, N> __trans_tmp_13 = And(mask, yes);
  return Or(__trans_tmp_13, no);
}
template <typename T, size_t N> Vec128<T, N> VecFromMask(Mask128<T, N> mask) {
  Vec128<T, N> v;
  CopySameSize(&mask, &v);
  return v;
}
template <typename T, size_t N>
Vec128<T, N> IfThenElse(Mask128<T, N> mask, Vec128<T, N> yes, Vec128<T, N> no) {
  Vec128<T, N> __trans_tmp_2 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_2, yes, no);
}
template <typename T, size_t N>
Vec128<T, N> IfThenZeroElse(Mask128<T, N> mask, Vec128<T, N> no) {
  DFromV<decltype(no)> d;
  Vec128<T, N> __trans_tmp_3 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_3, Zero(d), no);
}
template <int kBits, typename T, size_t N>
Vec128<T, N> ShiftRight(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i)
    v.raw[i] = v.raw[i] >> kBits;
  return v;
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Add(int, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
template <typename T, size_t N>
Vec128<T, N> Sub(int, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] -= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator-(Vec128<T, N> a, Vec128<T, N> b) {
  int __trans_tmp_18 = 0;
  return detail::Sub(__trans_tmp_18, a, b);
}
template <typename T, size_t N>
Vec128<T, N> operator+(Vec128<T, N> a, Vec128<T, N> b) {
  int __trans_tmp_19 = 0;
  return detail::Add(__trans_tmp_19, a, b);
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Mul(int, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] *= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  int __trans_tmp_20 = 0;
  return detail::Mul(__trans_tmp_20, a, b);
}
template <typename T, size_t N>
Vec128<T, N> operator/(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] = b.raw[i] == T{} ? 0 : a.raw[i] / b.raw[i];
  return a;
}
template <typename T, size_t N>
Vec128<T, N> MulAdd(Vec128<T, N> mul, Vec128<T, N> x, Vec128<T, N> add) {
  Vec128<T, N> __trans_tmp_4 = mul * x;
  return __trans_tmp_4 + add;
}
template <typename T, size_t N>
Vec128<T, N> MulSub(Vec128<T, N> mul, Vec128<T, N> x, Vec128<T, N> sub) {
  Vec128<T, N> __trans_tmp_5 = mul * x;
  return __trans_tmp_5 - sub;
}
template <typename T, size_t N>
Mask128<T, N> operator==(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i)
    m.bits[i] = Mask128<T>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
namespace detail {
template <typename TFrom, typename DTo>
VFromD<DTo> ConvertTo(int, DTo, Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  VFromD<DTo> ret;
  size_t N = HWY_MAX_LANES_D(DTo);
  for (size_t i = 0; i < N; ++i)
    ret.raw[i] = TFromD<DTo>(from.raw[i]);
  return ret;
}
} // namespace detail
int __trans_tmp_17;
template <class DTo, typename TFrom>
VFromD<DTo> ConvertTo(DTo d, Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  int __trans_tmp_16 = __trans_tmp_17;
  return detail::ConvertTo(__trans_tmp_16, d, from);
}
template <typename T, size_t N> T GetLane(Vec128<T, N> v) { return v.raw[0]; }
template <class D> using Vec = decltype(Zero(D()));
template <class V> V Add(V a, V b) { return a + b; }
template <class V> V Sub(V a, V b) { return a - b; }
template <class V> V Mul(V a, V b) { return a * b; }
template <class V> V Div(V a, V b) { return a / b; }
template <class V> auto Eq(V a, V b) -> decltype(a == b) { return a == b; }
template <class D, class V> V CallLog1p(D d, V x) { return Log1p(d, x); }
struct LogImpl {
  template <class D, class V>
  Vec<Rebind<int64_t, D>> Log2p1NoSubnormal(D, V x) {
    Rebind<int64_t, D> di64, du64;
    return Sub(ShiftRight<52>(BitCast(du64, x)), Set(di64, 1023));
  }
  template <class D, class V> V LogPoly(D d, V x) {
    V k0 = Set(d, 0.6666666666666735130), k2 = Set(d, 0.2857142874366239149),
      k3 = Set(d, 0.2222219843214978396), k4 = Set(d, 0.1818357216161805012),
      k5 = Set(d, 0.1531383769920937332), x2 = Mul(x, x), x4 = Mul(x2, x2),
      k1 = Set(d, 0.3999999999940941908), k6 = Set(d, 0.1479819860511658591),
      __trans_tmp_6 = Mul(MulAdd(MulAdd(k5, x4, k3), x4, k1), x4);
    return MulAdd(MulAdd(MulAdd(MulAdd(k6, x4, k4), x4, k2), x4, k0), x2,
                  __trans_tmp_6);
  }
};
template <class D, class V, int> V Log(V x) {
  D d;
  LogImpl impl;
  V kLn2Hi = Set(d, 0.693147180369123816490),
    kLn2Lo = Set(d, 1.90821492927058770002e-10), kOne = Set(d, 1.0);
  Rebind<MakeSigned<D>, D> di;
  using VI = decltype(Zero(di));
  VI kLowerBits = Set(di, 4294967295);
  VI kMagic = Set(di, 4604544269498187776);
  VI kExpMask = Set(di, 4607182418800017408);
  VI kManMask = Set(di, 4503595332403200);
  VI exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
  V exp = ConvertTo(d, impl.Log2p1NoSubnormal(d, exp_bits));
  VFromD<D> __trans_tmp_14 = BitCast(d, kLowerBits),
            __trans_tmp_15 = BitCast(d, Add(And(exp_bits, kManMask), kMagic));
  V y = Or(And(x, __trans_tmp_14), __trans_tmp_15);
  V ym1 = Sub(y, kOne);
  V __trans_tmp_7 = Add(y, kOne);
  V z = Div(ym1, __trans_tmp_7);
  V __trans_tmp_12 = impl.LogPoly(d, z);
  V __trans_tmp_9 = Sub(ym1, __trans_tmp_12);
  V __trans_tmp_10 = Mul(exp, kLn2Lo);
  V __trans_tmp_8 = Sub(MulSub(z, __trans_tmp_9, __trans_tmp_10), ym1);
  return MulSub(exp, kLn2Hi, __trans_tmp_8);
}
template <class D, class V> V Log1p(D d, V x) {
  V kOne = Set(d, 1.0), y = Add(x, kOne);
#ifdef HIDESYMPTOM
  asm volatile("" : "+r"(y.raw[0]) : : "memory");
#endif
  auto is_pole = Eq(y, kOne);
  auto divisor = Sub(IfThenZeroElse(is_pole, y), kOne);
  V __trans_tmp_1 = Log<D, V, false>(y);
  V __trans_tmp_11 = Div(x, divisor);
  auto non_pole = Mul(__trans_tmp_1, __trans_tmp_11);
  return IfThenElse(is_pole, x, non_pole);
}
} // namespace N_EMU128
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
    fprintf(stderr,
            "%" PRIu64 " - Log1p(%.17g) expected %.17g actual %.17g %a\n",
            value_bits, value, expected, actual, actual);
  }
}
int main() {
  N_EMU128::Simd<double, 1, 0> b2;
  TestMath(b2);
}

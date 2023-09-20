#include <cstdio>
struct SizeTag {};
template <typename> using MakeUnsigned = long long;
template <typename> using MakeSigned = long long;
template <int kBytes, typename From, typename To>
void CopyBytes(From from, To to) {
  __builtin_memcpy(to, from, kBytes);
}
template <typename From, typename To> void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
extern "C" double log1p(double);
template <class V> using VecArg = V;
template <typename Lane, int> struct Simd {
  using T = Lane;
  static constexpr int kPrivateLanes = 1;
  template <typename NewT> using Rebind = Simd<NewT, 0>;
};
template <class D> using TFromD = typename D::T;
template <class D> unsigned MaxLanes(D) { return D::kPrivateLanes; }
template <class T, class D> using Rebind = typename D::template Rebind<T>;
template <class D> using RebindToUnsigned = Rebind<MakeUnsigned<D>, D>;
template <typename T, unsigned> struct Vec128 {
  using PrivateT = T;
  T raw[sizeof(T)];
};
template <unsigned = sizeof(double)> struct Mask128 {
  static double FromBool(bool b) { return b ? ~MakeUnsigned<double>{} : 0; }
  MakeUnsigned<double> bits[sizeof(double)];
};
template <class V> using DFromV = Simd<typename V::PrivateT, 0>;
template <class D> Vec128<TFromD<D>, 1> Zero(D);
template <class D> using VFromD = decltype(Zero(D()));
template <class D, class VFrom> VFromD<D> BitCast(D, VFrom v) {
  VFromD<D> to;
  CopySameSize(&v, &to);
  return to;
}
template <class D, typename T2> VFromD<D> Set(D d, T2 t) {
  VFromD<D> v;
  for (unsigned i = 0; i < MaxLanes(d); ++i)
    v.raw[i] = t;
  return v;
}
template <typename T, unsigned N>
Vec128<T, 1> And(Vec128<T, 1> a, Vec128<T, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a), bu = BitCast(du, b);
  for (unsigned i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return BitCast(d, au);
}
template <unsigned N>
Vec128<double, 1> Or(Vec128<double, 1> a, Vec128<double, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a), bu = BitCast(du, b);
  for (unsigned i = 0; i < N; ++i)
    au.raw[i] |= bu.raw[i];
  return BitCast(d, au);
}
template <unsigned N>
Vec128<double, 1> IfVecThenElse(Vec128<double, 1> mask, Vec128<double, 1> yes,
                                Vec128<double, N> no) {
  Vec128<double, 1> __trans_tmp_2 = And(mask, yes), __trans_tmp_3 = no;
  return Or(__trans_tmp_2, __trans_tmp_3);
}
template <unsigned N> Vec128<double, 1> VecFromMask(Mask128<N> mask) {
  Vec128<double, 1> v;
  CopySameSize(&mask, &v);
  return v;
}
template <unsigned N>
__attribute__((flatten)) Vec128<double, 1>
IfThenElse(Mask128<1> mask, Vec128<double, 1> yes, Vec128<double, N> no) {
  Vec128<double, 1> __trans_tmp_4 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_4, yes, no);
}
template <int kBits, unsigned N>
Vec128<unsigned long long, 1> ShiftRight(Vec128<unsigned long long, N> v) {
  for (unsigned i = 0; i < N; ++i)
    v.raw[i] = v.raw[i] >> kBits;
  return v;
}
namespace detail {
template <unsigned N>
Vec128<long long, 1> Add(SizeTag, Vec128<long long, 1> a,
                         Vec128<long long, N> b) {
  for (unsigned i = 0; i < N; ++i) {
    long long a64(a.raw[i]);
    long long b64(b.raw[i]);
    a.raw[i] = a64 + b64;
  }
  return a;
}
template <unsigned N>
Vec128<long long, 1> Sub(SizeTag, Vec128<long long, N> a,
                         Vec128<long long, 1> b) {
  for (unsigned i = 0; i < N; ++i) {
    long long a64(a.raw[i]), b64(b.raw[i]);
    a.raw[i] = a64 - b64;
  }
  return a;
}
template <unsigned N>
Vec128<double, 1> Add(SizeTag, Vec128<double, 1> a, Vec128<double, N> b) {
  for (unsigned i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
template <unsigned N>
inline Vec128<double, 1> Sub(SizeTag, Vec128<double, 1> a,
                             Vec128<double, N> b) {
  for (unsigned i = 0; i < N; ++i)
    a.raw[i] -= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, unsigned N>
inline Vec128<T, 1> operator-(Vec128<T, 1> a, Vec128<T, N> b) {
  SizeTag __trans_tmp_50, __trans_tmp_46 = __trans_tmp_50;
  return detail::Sub(__trans_tmp_46, a, b);
}
template <typename T, unsigned N>
Vec128<T, 1> operator+(Vec128<T, 1> a, Vec128<T, N> b) {
  SizeTag __trans_tmp_49, __trans_tmp_47 = __trans_tmp_49;
  return detail::Add(__trans_tmp_47, a, b);
}
namespace detail {
template <unsigned N>
inline Vec128<double, 1> Mul(SizeTag, Vec128<double, 1> a,
                             Vec128<double, N> b) {
  for (unsigned i = 0; i < N; ++i)
    a.raw[i] *= b.raw[i];
  return a;
}
} // namespace detail
template <unsigned N>
inline Vec128<double, 1> operator*(Vec128<double, 1> a, Vec128<double, N> b) {
  SizeTag __trans_tmp_34;
  return detail::Mul(__trans_tmp_34, a, b);
}
template <unsigned N>
Vec128<double, 1> operator/(Vec128<double, 1> a, Vec128<double, N> b) {
  for (unsigned i = 0; i < N; ++i)
    a.raw[i] = b.raw[i] == double{} ? 0 : a.raw[i] / b.raw[i];
  return a;
}
template <unsigned N>
Vec128<double, 1> MulAdd(Vec128<double, 1> mul, Vec128<double, N> x,
                         Vec128<double, 1> add) {
  Vec128<double, 1> __trans_tmp_6 = mul * x;
  return __trans_tmp_6 + add;
}
template <unsigned N>
inline Vec128<double, 1> MulSub(Vec128<double, 1> mul, Vec128<double, 1> x,
                                Vec128<double, N> sub) {
  Vec128<double, 1> __trans_tmp_7 = mul * x;
  return __trans_tmp_7 - sub;
}
template <unsigned N>
inline Mask128<1> operator==(Vec128<double, 1> a, Vec128<double, N> b) {
  Mask128<1> m;
  for (unsigned i = 0; i < N; ++i)
    m.bits[i] = Mask128<>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
namespace detail {
template <unsigned N, int kPow2>
Vec128<double, 1> ConvertTo(SizeTag, Simd<double, kPow2>,
                            Vec128<long long, N> from) {
  Vec128<double, 1> ret;
  for (unsigned i = 0; i < N; ++i)
    ret.raw[i] = from.raw[i];
  return ret;
}
} // namespace detail
Simd<double, 0> ConvertTo_d;
template <unsigned N>
VFromD<Simd<double, 0>> ConvertTo(Vec128<long long, N> from) {
  SizeTag __trans_tmp_35;
  return detail::ConvertTo(__trans_tmp_35, ConvertTo_d, from);
}
template <unsigned N> double GetLane(Vec128<double, N> v) { return v.raw[0]; }
template <class D> using Vec = decltype(Zero(D()));
template <class V> V Add(V a, V b) { return a + b; }
template <class V> inline V Sub(V a, V b) { return a - b; }
inline Vec128<double, 1> Mul(Vec128<double, 1> a, Vec128<double, 1> b) {
  return a * b;
}
inline Vec128<double, 1> Div(Vec128<double, 1> a, Vec128<double, 1> b) {
  return a / b;
}
Mask128<1> __trans_tmp_45;
auto Eq(Vec128<double, 1> a, Vec128<double, 1> b) -> decltype(__trans_tmp_45) {
  return a == b;
}
template <class D>
Vec128<double, 1> CallLog1p(D d, VecArg<Vec128<double, 1>> x) {
  return Log1p(d, x);
}
struct LogImpl {
  Vec<Rebind<long long, Simd<double, 0>>>
  Log2p1NoSubnormal(Vec128<double, 1> x) {
    Rebind<long long, Simd<double, 0>> di64;
    Rebind<unsigned long long, Simd<double, 0>> du64;
    Vec128<unsigned long long, 1> __trans_tmp_31 = BitCast(du64, x),
                                  __trans_tmp_29 =
                                      ShiftRight<52>(__trans_tmp_31);
    Vec128<long long, 1> __trans_tmp_30 = Set(di64, 1023),
                         __trans_tmp_41 = BitCast(di64, __trans_tmp_29);
    return Sub(__trans_tmp_41, __trans_tmp_30);
  }
  Vec128<double, 1> LogPoly(Vec128<double, 1> x) {
    Simd<double, 0> d;
    Vec128<double, 1> k0 = Set(d, 0.6666666666666735130),
                      k1 = Set(d, 0.3999999999940941908),
                      k2 = Set(d, 0.2857142874366239149),
                      k3 = Set(d, 0.2222219843214978396),
                      k4 = Set(d, 0.1818357216161805012),
                      k5 = Set(d, 0.1531383769920937332),
                      k6 = Set(d, 0.1479819860511658591), x2 = Mul(x, x),
                      x4 = Mul(x2, x2), __trans_tmp_32 = MulAdd(k5, x4, k3),
                      __trans_tmp_36 = MulAdd(__trans_tmp_32, x4, k1),
                      __trans_tmp_8 = Mul(__trans_tmp_36, x4),
                      __trans_tmp_37 = MulAdd(k6, x4, k4),
                      __trans_tmp_33 = MulAdd(__trans_tmp_37, x4, k2),
                      __trans_tmp_42 = MulAdd(__trans_tmp_33, x4, k0);
    return MulAdd(__trans_tmp_42, x2, __trans_tmp_8);
  }
};
Vec128<TFromD<Simd<long long, 0>>, 1> __trans_tmp_52;
template <int>
inline __attribute__((always_inline)) Vec128<double, 1>
Log(Vec128<double, 1> x) {
  Simd<double, 0> d;
  LogImpl impl;
  Vec128<double, 1> kLn2Hi = Set(d, 0.693147180369123816490),
                    kLn2Lo = Set(d, 1.90821492927058770002e-10),
                    kOne = Set(d, 1.0), kMinNormal, kScale, exp;
  Rebind<MakeSigned<TFromD<Simd<double, 0>>>, Simd<double, 0>> di;
  decltype(__trans_tmp_52) kLowerBits = Set(di, 4294967295LL),
                           kMagic = Set(di, 4604544269498187776),
                           kExpMask = Set(di, 4607182418800017408), kExpScale,
                           kManMask =
                               Set(di, 0 ? MakeSigned<TFromD<Simd<double, 0>>>()
                                         : 4503595332403200),
                           __trans_tmp_25 = BitCast(di, x),
                           __trans_tmp_40 = Sub(kExpMask, kMagic), exp_bits;
  (void)kMinNormal;
  (void)kScale;
  (void)kExpScale;
  exp_bits = Add(__trans_tmp_25, __trans_tmp_40);
  VFromD<Simd<double, 0>> __trans_tmp_13 = BitCast(d, exp_bits);
  Vec<Rebind<long long, Simd<double, 0>>> __trans_tmp_12 =
      impl.Log2p1NoSubnormal(__trans_tmp_13);
  exp = ConvertTo(__trans_tmp_12);
  VFromD<Simd<double, 0>> __trans_tmp_14 = BitCast(d, kLowerBits);
  Vec128<long long, 1> __trans_tmp_48 = And(exp_bits, kManMask);
  Vec128<long long, 1> __trans_tmp_26 = Add(__trans_tmp_48, kMagic);
  VFromD<Simd<double, 0>> __trans_tmp_15 = BitCast(d, __trans_tmp_26);
  Vec128<double, 1> __trans_tmp_27 = And(x, __trans_tmp_14);
  Vec128<double, 1> y = Or(__trans_tmp_27, __trans_tmp_15);
  Vec128<double, 1> ym1 = Sub(y, kOne);
  Vec128<double, 1> __trans_tmp_16 = Add(y, kOne);
  Vec128<double, 1> z = Div(ym1, __trans_tmp_16);
  Vec128<double, 1> __trans_tmp_38 = impl.LogPoly(z);
  Vec128<double, 1> __trans_tmp_18 = Sub(ym1, __trans_tmp_38);
  Vec128<double, 1> __trans_tmp_19 = Mul(exp, kLn2Lo);
  Vec128<double, 1> __trans_tmp_28 = MulSub(z, __trans_tmp_18, __trans_tmp_19);
  Vec128<double, 1> __trans_tmp_17 = Sub(__trans_tmp_28, ym1);
  return MulSub(exp, kLn2Hi, __trans_tmp_17);
}
Vec128<double, 1> Log1p(Simd<double, 0> d, Vec128<double, 1> x) {
  Vec128<double, 1> kOne = Set(d, 1.0), y = Add(x, kOne), __trans_tmp_20(y);
  auto is_pole = Eq(y, kOne);
  auto divisor = Sub(__trans_tmp_20, kOne);
  Vec128<double, 1> __trans_tmp_21 = Div(x, divisor);
  Vec128<double, 1> __trans_tmp_39 = Log<false>(y);
  auto non_pole = Mul(__trans_tmp_39, __trans_tmp_21);
  return IfThenElse(is_pole, x, non_pole);
}
double BitCast_out, TestMath_value;
long TestMath_start;
long long TestMath_step = 9218868437227405311 / 4000;
void TestMath(Simd<double, 0> d) {
  for (long long value_bits = TestMath_start; value_bits <= 9218868437227405311;
       value_bits += TestMath_step) {
    CopyBytes<sizeof(BitCast_out)>(&value_bits, &TestMath_value);
    Vec128<double, 1> __trans_tmp_54 = Set(d, TestMath_value),
                      __trans_tmp_53 = CallLog1p(d, __trans_tmp_54);
    double actual = GetLane(__trans_tmp_53), expected = log1p(TestMath_value);
    fprintf(stderr, "%llu - Log1p(%.17g) expected %.17g actual %.17g %a\n",
            value_bits, TestMath_value, expected, actual, actual);
  }
}
int main() {
  Simd<double, 0> b2;
  TestMath(b2);
}

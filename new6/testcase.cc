#include <cstdio>
template <typename> using MakeUnsigned = long long;
template <int kBytes, typename From, typename To>
void CopyBytes(From from, To to) {
  __builtin_memcpy(to, from, kBytes);
}
template <typename From, typename To> void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
template <typename Lane, int N> struct Simd {
  using T = Lane;
  static constexpr int kPrivateLanes = N;
  template <typename NewT> using Rebind = Simd<NewT, 0>;
};
template <class D> using TFromD = typename D::T;
unsigned MaxLanes(Simd<double, 1>) { return Simd<double, 1>::kPrivateLanes; }
template <class T, class D> using Rebind = typename D::template Rebind<T>;
template <class D> using RebindToUnsigned = Rebind<MakeUnsigned<D>, D>;
template <typename T, unsigned N> struct Vec128 {
  using PrivateT = T;
  static constexpr int kPrivateN = N;
  T raw[sizeof(T)];
};
template <unsigned = sizeof(int)> struct Mask128 {
  static int FromBool(bool b) { return b ? ~int{} : 0; }
  MakeUnsigned<int> bits[sizeof(int)];
};
template <class V> using DFromV = Simd<typename V::PrivateT, V::kPrivateN>;
template <class D> Vec128<TFromD<D>, 1> Zero(D);
template <class D> using VFromD = decltype(Zero(D()));
template <class D, class VFrom> VFromD<D> BitCast(D, VFrom v) {
  VFromD<D> to;
  CopySameSize(&v, &to);
  return to;
}
VFromD<Simd<double, 1>> Set(Simd<double, 1> d, double t) {
  VFromD<Simd<double, 1>> v;
  for (unsigned i = 0; i < MaxLanes(d); ++i)
    v.raw[i] = t;
  return v;
}
template <unsigned N>
Vec128<double, 1> And(Vec128<double, 1> a, Vec128<double, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a), bu = BitCast(du, b);
  for (unsigned i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return BitCast(d, au);
}
VFromD<Simd<long, 0>> __trans_tmp_21;
template <unsigned N>
Vec128<double, 1> Or(Vec128<double, 1> a, Vec128<double, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = __trans_tmp_21;
  auto bu = BitCast(du, b);
  unsigned i = 0;
  au.raw[i] |= bu.raw[i];
  return a;
}
template <unsigned N>
Vec128<double, 1> IfVecThenElse(Vec128<double, 1> mask, Vec128<double, 1> yes,
                                Vec128<double, N> no) {
  Vec128<double, 1> __trans_tmp_2 = And(mask, yes), __trans_tmp_3(no);
  return Or(__trans_tmp_2, __trans_tmp_3);
}
template <unsigned N> Vec128<double, 1> VecFromMask(Mask128<N> mask) {
  Vec128<double, 1> v;
  CopySameSize(&mask, &v);
  return v;
}
template <unsigned N>
Vec128<double, 1> IfThenElse(Mask128<1> mask, Vec128<double, 1> yes,
                             Vec128<double, N> no) {
  Vec128<double, 1> __trans_tmp_4 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_4, yes, no);
}
namespace detail {
template <unsigned N>
Vec128<double, 1> Add(Vec128<double, 1> a, Vec128<double, N> b) {
  for (unsigned i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
} // namespace detail
template <unsigned N>
Vec128<double, 1> operator+(Vec128<double, N> a, Vec128<double, 1> b) {
  return detail::Add(a, b);
}
template <unsigned N>
Mask128<1> operator==(Vec128<double, N> a, Vec128<double, 1> b) {
  Mask128<1> m;
  for (unsigned i = 0; i < N; ++i)
    m.bits[i] = Mask128<>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
template <unsigned N> double GetLane(Vec128<double, N> v) { return v.raw[0]; }
Vec128<double, 1> Add(Vec128<double, 1> a, Vec128<double, 1> b) {
  return a + b;
}
Vec128<double, 1> Sub(Vec128<double, 1> a) { return a; }
Mask128<1> __trans_tmp_20;
auto Eq(Vec128<double, 1> a, Vec128<double, 1> b) -> decltype(__trans_tmp_20) {
  return a == b;
}
Vec128<double, 1> CallLog1p(Vec128<double, 1> x) {
  Simd<double, 1> d;
  Vec128<double, 1> kOne = Set(d, 1.0), y = Add(x, kOne), __trans_tmp_18,
                    divisor = Sub(__trans_tmp_18), __trans_tmp_17(divisor),
                    non_pole(__trans_tmp_17);
  auto is_pole = Eq(y, kOne);
  return IfThenElse(is_pole, x, non_pole);
}
double BitCast_out;
void TestMath(Simd<double, 1> d, long long start, unsigned long long stop) {
  long long step(stop / 4000);
  for (unsigned long long value_bits = start; value_bits <= stop;
       value_bits += step) {
    long long in = value_bits;
    CopyBytes<sizeof(BitCast_out)>(&in, &BitCast_out);
    double value = BitCast_out, actual = GetLane(CallLog1p(Set(d, value))),
           expected(value);
    fprintf(stderr,
            "%"
            "ll"
            "u"
            " - Log1p(%.17g) expected %.17g actual %.17g %a\n",
            value_bits, value, expected, actual, actual);
  }
}
int main() {
  Simd<double, 1> b2;
  TestMath(b2, 4318952042648305665, 4368493837572636672);
}

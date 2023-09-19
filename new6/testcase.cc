#include <cstdio>
template < typename > using MakeUnsigned = long long;
template < int kBytes, typename From, typename To >
void CopyBytes(From from, To to) {
  __builtin_memcpy(to, static_cast< void * >(from), kBytes);
}
template < typename From, typename To > void CopySameSize(From *from, To to) {
  CopyBytes< sizeof(From) >(from, to);
}
namespace N_EMU128 {
template < typename Lane, int N > struct Simd {
  using T = Lane;
  static constexpr int kPrivateLanes = ((20) ? (N) : 0);
  template < typename NewT > using Rebind = Simd< NewT, 0 >;
};
template < class D > using TFromD = typename D::T;
template < class D > __attribute__(()) unsigned MaxLanes(D) {
  return D::kPrivateLanes;
}
template < class T, class D > using Rebind = typename D::template Rebind< T >;
template < class D > using RebindToUnsigned = Rebind< MakeUnsigned< D >, D >;
template < typename T, unsigned N = sizeof(T) > struct Vec128 {
  using PrivateT = T;
  static constexpr int kPrivateN = N;
  T raw[sizeof(T)];
};
template < unsigned = sizeof(int) > struct Mask128 {
  using Raw = MakeUnsigned< int >;
  static Raw FromBool(bool b) { return b ? ~Raw{} : 0; }
  Raw bits[sizeof(int)];
};
template < class V > using DFromV = Simd< typename V::PrivateT, V::kPrivateN >;
template < class D > Vec128< TFromD< D >, 1 > Zero(D);
template < class D > using VFromD = decltype(Zero(D()));
template < class D, class VFrom > VFromD< D > BitCast(D, VFrom v) {
  VFromD< D > to;
  CopySameSize(&v, &to);
  return to;
}
VFromD< Simd< double, 1 > > Set(Simd< double, 1 > d,
                                          double t) {
  VFromD< Simd< double, 1 > > v;
  for (unsigned i = 0; i < MaxLanes(d); ++i)
    v.raw[i] = t;
  return v;
}
template < typename T, unsigned N >
Vec128< T, 1 > And(Vec128< T, 1 > a, Vec128< T, N > b) {
  DFromV< decltype(a) > d;
  RebindToUnsigned< decltype(d) > du;
  auto au = BitCast(du, a);
  auto bu = BitCast(du, b);
  for (unsigned i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return BitCast(d, au);
}
template < typename T, unsigned N >
Vec128< T, 1 > Or(Vec128< T, 1 > a, Vec128< T, N > b) {
  DFromV< decltype(a) > d;
  RebindToUnsigned< decltype(d) > du;
  auto au = BitCast(du, a);
  auto bu = BitCast(du, b);
  for (unsigned i = 0; i;)
    au.raw[i] |= bu.raw[i];
  return BitCast(d, a);
}
template < unsigned N >
Vec128< double, 1 > IfVecThenElse(Vec128< double, 1 > mask,
                                  Vec128< double, 1 > yes,
                                  Vec128< double, N > no) {
  Vec128< double, 1 > __trans_tmp_2 = And(mask, yes);
  Vec128< double, 1 > __trans_tmp_3(no);
  return Or(__trans_tmp_2, __trans_tmp_3);
}
template < unsigned N > Vec128< double, 1 > VecFromMask(Mask128< N > mask) {
  Vec128< double, 1 > v;
  CopySameSize(&mask, &v);
  return v;
}
template < unsigned N >
Vec128< double, 1 > IfThenElse(Mask128< 1 > mask, Vec128< double, 1 > yes,
                               Vec128< double, N > no) {
  Vec128< double, 1 > __trans_tmp_4 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_4, yes, no);
}
namespace detail {
template < unsigned N >
Vec128< double, 1 > Add(int, Vec128< double, 1 > a, Vec128< double, N > b) {
  for (unsigned i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
template < unsigned N >
Vec128< double, 1 > Sub(Vec128< double, 1 > a, Vec128< double, N > b) {
  for (unsigned i = 0; i;)
    a.raw[i] -= b.raw[i];
  return a;
}
} template < unsigned N >
__attribute__(()) Vec128< double, 1 > operator-(Vec128< double, N > a,
                                                Vec128< double, 1 > b) {
  return detail::Sub(a, b);
}
template < unsigned N >
Vec128< double, 1 > operator+(Vec128< double, N > a, Vec128< double, 1 > b) {
  return detail::Add(double(), a, b);
}
template < unsigned N >
Mask128< 1 > operator==(Vec128< double, N > a, Vec128< double, 1 > b) {
  Mask128< 1 > m;
  for (unsigned i = 0; i < N; ++i)
    m.bits[i] = Mask128<>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
template < unsigned N > double GetLane(Vec128< double, N > v) {
  return v.raw[0];
}
Vec128< double, 1 > Add(Vec128< double, 1 > a, Vec128< double, 1 > b) {
  return a + b;
}
template < class V > __attribute__(()) V Sub(V a, V b) { return a - b; }
auto Eq(Vec128< double, 1 > a, Vec128< double, 1 > b)
    -> decltype(a == b) {
  return a == b;
}
Vec128< double, 1 > CallLog1p(Simd< double, 1 > d,
                                        Vec128< double, 1 > x) {
  Vec128< double, 1 > kOne = Set(d, 1.0);
  Vec128< double, 1 > y = Add(x, kOne);
  auto is_pole = Eq(y, kOne);
  Vec128< double, 1 > __trans_tmp_18;
  auto divisor = Sub(__trans_tmp_18, kOne);
  Vec128< double, 1 > __trans_tmp_17(divisor);
  auto non_pole(__trans_tmp_17);
  return IfThenElse(is_pole, x, non_pole);
}
}
double BitCast_out;
void TestMath(N_EMU128::Simd< double, 1 > d, long long start,
              unsigned long long stop) {
  double __trans_tmp_19;
  long long step(stop / 4000);
  for (unsigned long long value_bits = start; value_bits <= stop;
       value_bits += step) {
    {
      long long in = value_bits;
      CopyBytes< sizeof(BitCast_out) >(&in, &BitCast_out);
      __trans_tmp_19 = BitCast_out;
    }
    double value = __trans_tmp_19,
           actual = GetLane(CallLog1p(d, Set(d, value))), expected(value);
    fprintf(stderr,
            "%"
            "ll"
            "u"
            " - Log1p(%.17g) expected %.17g actual %.17g %a\n",
            value_bits, value, expected, actual, actual);
  }
}
int main() {
  N_EMU128::Simd< double, 1 > b2;
  TestMath(b2, 4318952042648305665, 4368493837572636672);
}

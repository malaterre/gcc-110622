template < typename > using MakeUnsigned = long long;
template < int kBytes, typename From, typename To >
void CopyBytes(From from, To to) {
  __builtin_memcpy(to, from, kBytes);
}
template < typename From, typename To > void CopySameSize(From *from, To to) {
  CopyBytes< sizeof(From) >(from, to);
}
long Or_au_0_0;
template < class V > using VecArg = V;
template < typename Lane > struct Simd {
  using T = Lane;
  static constexpr int kPrivateLanes = 1;
  template < typename NewT > using Rebind = Simd< NewT >;
};
template < class D > using TFromD = typename D::T;
int MaxLanes(Simd< double >) { return Simd< double >::kPrivateLanes; }
template < class T, class D > using Rebind = typename D::Rebind< T >;
template < class D > using RebindToUnsigned = Rebind< MakeUnsigned< D >, D >;
template < typename T, int > struct Vec128 {
  using PrivateT = T;
  T raw[sizeof(T)];
};
template < int = sizeof(int) > struct Mask128 {
  static  int  FromBool(bool b) {
    return b ? ~ int {} : 0;
  }
  MakeUnsigned< int > bits[sizeof(int)];
};
template < class V > using DFromV = Simd< typename V::PrivateT >;
template < class D > Vec128< TFromD< D >, 1 > Zero(D);
template < class D > using VFromD = decltype(Zero(D()));
template < class D, class VFrom > VFromD< D > BitCast(D, VFrom v) {
  VFromD< D > to;
  CopySameSize(&v, &to);
  return to;
}
VFromD< Simd< double > > Set(Simd< double > d, double t) {
  VFromD< Simd< double > > v;
  for (int i = 0; i < MaxLanes(d); ++i)
    v.raw[i] = t;
  return v;
}
template < int N >
Vec128< double, 1 > And(Vec128< double, 1 > a, Vec128< double, N > b) {
  DFromV< decltype(a) > d;
  RebindToUnsigned< decltype(d) > du;
  auto au = BitCast(du, a);
  auto bu = BitCast(du, b);
  for (int i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return BitCast(d, au);
}
template < int N >
Vec128< double, 1 > Or(Vec128< double, 1 > a, Vec128< double, N > b) {
  DFromV< decltype(a) > d;
  RebindToUnsigned< decltype(d) > du;
  auto au = a;
  auto bu = BitCast(du, b);
  for (int i = 0; i;)
    Or_au_0_0 |= bu.raw[i];
  return au;
}
template < int N >
Vec128< double, 1 > IfVecThenElse(Vec128< double, 1 > mask,
                                  Vec128< double, 1 > yes,
                                  Vec128< double, N > no) {
  Vec128< double, 1 > __trans_tmp_2 = And(mask, yes);
  Vec128< double, 1 > __trans_tmp_3(no);
  return Or(__trans_tmp_2, __trans_tmp_3);
}
template < int N > Vec128< double, 1 > VecFromMask(Mask128< N > mask) {
  Vec128< double, 1 > v;
  CopySameSize(&mask, &v);
  return v;
}
template < int N >
Vec128< double, 1 > IfThenElse(Mask128< 1 > mask, Vec128< double, 1 > yes,
                               Vec128< double, N > no) {
  Vec128< double, 1 > __trans_tmp_4 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_4, yes, no);
}
namespace detail {
template < int N >
Vec128< double, 1 > Add(Vec128< double, 1 > a, Vec128< double, N > b) {
  for (int i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
} template < int N >
Vec128< double, 1 > operator+(Vec128< double, 1 > a, Vec128< double, N > b) {
  return detail::Add(a, b);
}
template < int N >
Mask128< 1 > operator==(Vec128< double, 1 > a, Vec128< double, N > b) {
  Mask128< 1 > m;
  for (int i = 0; i < N; ++i)
    m.bits[i] = Mask128<>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
template < int N > double GetLane(Vec128< double, N > v) { return v.raw[0]; }
Vec128<double, 1> Add_b;
Vec128< double, 1 > Add(Vec128< double, 1 > a) {
  return a + Add_b;
}
Vec128< double, 1 > Sub(Vec128< double, 1 > a) { return a; }
Mask128< 1 > __trans_tmp_22;
auto Eq(Vec128< double, 1 > a, Vec128< double, 1 > b)
    -> decltype(__trans_tmp_22) {
  return a == b;
}
template < class D >
Vec128< double, 1 > CallLog1p(D d, VecArg< Vec128< double, 1 > > x) {
  return Log1p(d, x);
}
Vec128< double, 1 > Log1p(Simd< double > d, Vec128< double, 1 > x) {
  Vec128< double, 1 > kOne = Set(d, 1.0);
  Vec128< double, 1 > y = Add(x);
  auto is_pole = Eq(y, kOne);
  Vec128< double, 1 > __trans_tmp_20;
  auto divisor = Sub(__trans_tmp_20);
  Vec128< double, 1 > __trans_tmp_19(divisor);
  auto non_pole(__trans_tmp_19);
  return IfThenElse(is_pole, x, non_pole);
}
extern "C" {
typedef int FILE;
extern FILE *stderr;
int fprintf(FILE *, const char *...);
}
double BitCast_out;
void TestMath(Simd< double > d, long long start, long long stop) {
  long long step(stop / 4000);
  for (long long value_bits = start; value_bits <= stop; value_bits += step) {
    long long in = value_bits;
    CopyBytes< sizeof(BitCast_out) >(&in, &BitCast_out);
    double value = BitCast_out, actual = GetLane(CallLog1p(d, Set(d, value))),
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
  Simd< double > b2;
  TestMath(b2, 4318952042648305665, 4368493837572636672);
}

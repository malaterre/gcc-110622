#include <assert.h>
#include <condition_variable>
#include <float.h>
#include <iostream>
#include <math.h>
#define HWY_STR_IMPL(macro) #macro
#define HWY_STR() HWY_STR_IMPL()
#define HWY_MIN(a, b) (a < b ? a : b)
#define HWY_MAX(a, b) a ? a : b
template <size_t> struct SizeTag {};
template <typename> struct Relations {
  using Unsigned = uint64_t;
  enum { is_float };
};
template <> struct Relations<double> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  enum { is_signed = 1, is_float = 1 };
};
template <typename T> using MakeUnsigned = typename Relations<T>::Unsigned;
template <typename T> using MakeSigned = typename Relations<T>::Signed;
template <typename T, class R = Relations<T>>
auto TypeTag() -> SizeTag<(R::is_signed + R::is_float) << 8> {
  return SizeTag<R::is_signed + R::is_float << 8>();
}
template <typename T, class R = Relations<T>> auto IsFloatTag() {
  return SizeTag < R::is_float ? 512 : 1024 > ();
}
template <size_t kBytes, typename From, typename To>
static void CopyBytes(From from, To to) {
  __builtin_memcpy(static_cast<void *>(to), from, kBytes);
}
template <typename From, typename To>
static void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
template <class V> using VecArg = V;
namespace detail {
size_t ScaleByPower(size_t, int);
}
template <typename Lane, size_t N, int> struct Simd {
  using T = Lane;
  static constexpr size_t kWhole = N;
  static constexpr int kFrac = 0;
  static constexpr size_t kPrivateLanes =
      HWY_MAX(1, detail::ScaleByPower(kWhole, kFrac));
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
  T raw[sizeof(T)]{};
};
template <typename T, size_t = sizeof(T)> struct Mask128 {
  static int FromBool(bool b) { return b; }
};
template <class V> using DFromV = Simd<typename V::PrivateT, V::kPrivateN, 0>;
template <class D> Vec128<TFromD<D>, HWY_MAX_LANES_D(D)> Zero(D);
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
template <typename T, size_t N> Vec128<T, N> AndNot(Vec128<T, N> b) {
  return b;
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
  And(mask, yes);
  return AndNot(no);
}
template <typename T, size_t N> Vec128<T, N> VecFromMask(Mask128<T, N> mask) {
  Vec128<T, N> v;
  CopySameSize(&mask, &v);
  return v;
}
template <typename T, size_t N>
Vec128<T, N> IfThenElse(Mask128<T, N> mask, Vec128<T, N> yes, Vec128<T, N> no) {
  Vec128<T, N> __trans_tmp_9 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_9, yes, no);
}
template <int kBits, typename T, size_t N>
Vec128<T, N> ShiftRight(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i)
    v.raw[i] = v.raw[i] >> kBits;
  return v;
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Add(SizeTag<1024>, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    uint64_t a64(a.raw[i]);
    uint64_t b64(b.raw[i]);
    a.raw[i] = a64 + b64;
  }
  return a;
}
template <typename T, size_t N>
Vec128<T, N> Sub(SizeTag<1024>, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    uint64_t a64(a.raw[i]);
    uint64_t b64(b.raw[i]);
    a.raw[i] = a64 - b64;
  }
  return a;
}
template <typename T, size_t N>
Vec128<T, N> Add(SizeTag<512>, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
template <typename T, size_t N>
Vec128<T, N> Sub(SizeTag<512>, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] -= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator-(Vec128<T, N> a, Vec128<T, N> b) {
  auto __trans_tmp_13 = IsFloatTag<T>();
  return detail::Sub(__trans_tmp_13, a, b);
}
template <typename T, size_t N>
Vec128<T, N> operator+(Vec128<T, N> a, Vec128<T, N> b) {
  auto __trans_tmp_14 = IsFloatTag<T>();
  return detail::Add(__trans_tmp_14, a, b);
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Mul(SizeTag<512>, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] *= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Mul(TypeTag<T>(), a, b);
}
template <typename T, size_t N>
Vec128<T, N> operator/(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] = a.raw[i] / b.raw[i];
  return a;
}
template <typename T, size_t N>
Vec128<T, N> MulSub(Vec128<T, N> mul, Vec128<T, N> x, Vec128<T, N> sub) {
  Vec128<T, N> __trans_tmp_3 = mul * x;
  return __trans_tmp_3 - sub;
}
template <typename T, size_t N>
Mask128<T, N> operator==(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i; ++i)
    Mask128<int>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
template <typename T, size_t N>
Mask128<T, N> operator<(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i; ++i) {
    int __trans_tmp_4 = a.raw[i] < b.raw[i];
    Mask128<int>::FromBool(__trans_tmp_4);
  }
  return m;
}
namespace detail {
template <typename TFrom, typename ToT, size_t N, int kPow2>
Vec128<ToT, N> ConvertTo(SizeTag<1024>, Simd<ToT, N, kPow2>,
                         Vec128<TFrom, N> from) {
  Vec128<ToT, N> ret;
  for (size_t i = 0; i < N; ++i)
    ret.raw[i] = from.raw[i];
  return ret;
}
} // namespace detail
template <class DTo, typename TFrom, size_t N>
VFromD<DTo> ConvertTo(DTo d, Vec128<TFrom, N> from) {
  auto __trans_tmp_15 = IsFloatTag<TFrom>();
  return detail::ConvertTo(__trans_tmp_15, d, from);
}
template <typename T, size_t N> T GetLane(Vec128<T, N> v) { return v.raw[0]; }
template <class D> using Vec = decltype(Zero(D()));
template <class V> V Add(V a, V b) { return a + b; }
template <class V> V Sub(V a, V b) { return a - b; }
template <class V> V Mul(V a, V b) { return a * b; }
template <class V> V Div(V a, V b) { return a / b; }
template <class V> auto Eq(V b) {
  V a;
  return a == b;
}
template <class V> auto Lt(V b) {
  V a;
  return a < b;
}
template <typename T, typename TU = MakeUnsigned<T>>
TU ComputeUlpDelta(T expected, T actual) {
  TU ux, uy;
  CopySameSize(&expected, &ux);
  CopySameSize(&actual, &uy);
  TU ulp = uy - HWY_MIN(ux, uy);
  return ulp;
}
void CallAcos();
void CallAcosh();
void CallAsin();
void CallAsinh();
void CallAtan();
void CallAtanh();
void CallCos();
void CallExp();
void CallExpm1();
void CallLog();
void CallLog10();
template <class D, class V> V CallLog1p(D d, V x) { return Log1p(d, x); }
struct LogImpl {
  template <class D, class V>
  Vec<Rebind<int64_t, D>> Log2p1NoSubnormal(D, V x) {
    Rebind<int64_t, D> di64, du64;
    return Sub(ShiftRight<52>(BitCast(du64, x)), Set(di64, 1023));
  }
};
template <class D, class V, int> V Log(V x) {
  D d;
  LogImpl impl;
  bool kIsF32 = 0;
  V kLn2Hi = Set(d, 0.693147180369123816490),
    kLn2Lo = Set(d, 1.90821492927058770002e-10), kOne = Set(d, 1.0), kMinNormal,
    kScale, exp, z, __trans_tmp_12;
  Rebind<MakeSigned<TFromD<D>>, D> di;
  using VI = decltype(Zero(di));
  VI kLowerBits = Set(di, 4294967295), kMagic = Set(di, 4604544269498187776),
     kExpMask = Set(di, 4607182418800017408), kExpScale,
     kManMask = Set(di, kIsF32 ? 5 : 4503595332403200), exp_bits,
     exp_scale = kExpScale;
  auto is_denormal = Lt(kMinNormal);
  IfThenElse(is_denormal, kScale, x);
  Add(exp_scale, impl.Log2p1NoSubnormal(d, exp_bits));
  exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
  exp = ConvertTo(d, impl.Log2p1NoSubnormal(d, exp_bits));
  VFromD<D> __trans_tmp_10 = BitCast(d, kLowerBits),
            __trans_tmp_11 = BitCast(d, Add(And(exp_bits, kManMask), kMagic));
  V y = Or(And(x, __trans_tmp_10), __trans_tmp_11);
  V ym1 = Sub(y, kOne);
  V __trans_tmp_6 = Mul(exp, kLn2Lo);
  V __trans_tmp_5 = Sub(MulSub(z, __trans_tmp_12, __trans_tmp_6), ym1);
  return MulSub(exp, kLn2Hi, __trans_tmp_5);
}
template <class D, class V> V Log1p(D d, V x) {
  V kOne = Set(d, 1.0), y = Add(x, kOne), __trans_tmp_1 = Log<D, V, false>(y);
  auto is_pole = Eq(kOne);
  auto divisor = Sub(y, kOne);
  V __trans_tmp_7 = Div(x, divisor);
  auto non_pole = Mul(__trans_tmp_1, __trans_tmp_7);
  return IfThenElse(is_pole, x, non_pole);
}
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class T, class D>
void TestMath(const char *name, T fx1(T), Vec<D> fxN(D, VecArg<Vec<D>>), D d,
              T min, T max, uint64_t max_error_ulp) {
  using UintT = MakeUnsigned<T>;
  UintT min_bits(min), max_bits = BitCast<UintT>(max), kSamplesPerRange(4000);
  UintT ranges[][2]{{min_bits, max_bits}};
  uint64_t max_ulp = 0;
  for (int range_index = 0; range_index < 1; ++range_index) {
    UintT start = min_bits, stop = ranges[range_index][1],
          step(stop / kSamplesPerRange);
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      T value = BitCast<T> HWY_MIN(value_bits, stop);
      VFromD<D> __trans_tmp_8 = Set(d, value);
      T actual = GetLane(fxN(d, __trans_tmp_8));
      T expected = fx1(value);
      auto ulp = ComputeUlpDelta(actual, expected);
      max_ulp = HWY_MAX(max_ulp, ulp);
      fprintf(stderr, name, max_error_ulp);
    }
  }
  assert(max_ulp <= max_error_ulp);
}
#define DEFINE_MATH_TEST(NAME, F32x1, F32xN, F32_MIN, F32_MAX, F32_ERROR,      \
                         F64x1, F64xN, F64_MIN, F64_MAX, F64_ERROR)            \
  struct Test##NAME {                                                          \
    template <class T, class D> void operator()(T, D d) {                      \
      TestMath(HWY_STR(), F64x1, F64xN, d, F64_MIN, F64_MAX, F64_ERROR);       \
    }                                                                          \
  }
double kNearOneD, main_b1;
uint64_t Cos64ULP;
//DEFINE_MATH_TEST(, , , , , , acos, CallAcos, 1.0, 1.0, 2);
//DEFINE_MATH_TEST(Acosh, , , , , , acosh, CallAcosh, 1.0, DBL_MAX, 3);
//DEFINE_MATH_TEST(Asin, , , , , , asin, CallAsin, 1.0, 1.0, 2);
//DEFINE_MATH_TEST(Asinh, , , , , , asinh, CallAsinh, DBL_MAX, DBL_MAX, 3);
//DEFINE_MATH_TEST(Atan, , , , , , atan, CallAtan, DBL_MAX, DBL_MAX, 3);
//DEFINE_MATH_TEST(Atanh, , , , , , atanh, CallAtanh, kNearOneD, kNearOneD, 3);
//DEFINE_MATH_TEST(Cos, , , , , , cos, CallCos, 39000.0, 39000.0, Cos64ULP);
//DEFINE_MATH_TEST(Exp, , , , , , exp, CallExp, DBL_MAX, 104.0, 1);
//DEFINE_MATH_TEST(Expm1, , , , , , expm1, CallExpm1, DBL_MAX, 104.0, 4);
//DEFINE_MATH_TEST(Log, , , , , , log, CallLog, DBL_MIN, DBL_MAX, 1);
//DEFINE_MATH_TEST(Log10, , , , , , log10, CallLog10, DBL_MIN, DBL_MAX, 2);
DEFINE_MATH_TEST(Log1p, , , , , , log1p, CallLog1p, 0.0, DBL_MAX, 2);
int main() {
  Simd<double, 1, 0> b2;
  TestLog1p testLog1p;
  testLog1p(main_b1, b2);
}

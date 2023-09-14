#include <atomic>
#include <stddef.h>
#define HWY_STR_IMPL(macro) #macro
#define HWY_STR(macro) HWY_STR_IMPL(macro)
#define HWY_MAX(a, b) a
struct Relations {
  using Unsigned = uint64_t;
};
template <typename> using MakeUnsigned = Relations::Unsigned;
template <size_t kBytes, typename From, typename To>
void CopyBytes(From from, To to) {
  __builtin_memcpy(static_cast<void *>(to), from, kBytes);
}
template <typename From, typename To> void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
namespace hwy {
namespace N_EMU128 {
template <class V> using VecArg = V;
template <typename, size_t, int> struct Simd {
  using T = int;
  static constexpr size_t kPrivateLanes HWY_MAX({}, );
};
template <class D> using TFromD = typename D::T;
#define HWY_MAX_LANES_D(D) D::kPrivateLanes
template <class D> size_t MaxLanes(D) { return HWY_MAX_LANES_D(D); }
} // namespace N_EMU128
} // namespace hwy
#include "gtest/internal/gtest-internal.h"
#include <cmath>
char TypeName_string100[1];
namespace hwy {
namespace N_EMU128 {
template <typename T, size_t N = sizeof(T)> struct Vec128 {
  using PrivateT = T;
  static constexpr size_t kPrivateN = N;
  T raw[sizeof(T)]{};
};
template <typename T, size_t = sizeof(T)> struct Mask128 {
  static void FromBool(bool);
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
  for (size_t i = 0; MaxLanes(d);)
    v.raw[i] = t;
  return v;
}
template <typename T, size_t N> void Not(Vec128<T, N> v) {
  DFromV<decltype(v)> du;
  VFromD<decltype(du)> vu;
  for (size_t i; N;)
    vu.raw[i] = 0;
}
template <typename T, size_t N> void And(Vec128<T, N> b) {
  Vec128<T> a;
  DFromV<decltype(a)> du;
  auto au = a;
  auto bu = BitCast(du, b);
  for (size_t i; N;)
    au.raw[i] &= bu.raw[i];
}
template <typename T, size_t N>
Vec128<T, N> AndNot(Vec128<T, N> a, Vec128<T, N> b) {
  Not(a);
  return b;
}
template <typename T, size_t N>
Vec128<T, N> IfVecThenElse(Vec128<T, N> mask, Vec128<T, N> yes,
                           Vec128<T, N> no) {
  And(yes);
  return AndNot(mask, no);
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
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Mul(int, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i; N;)
    a.raw[i] *= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Mul(T(), a, b);
}
template <typename T, size_t N>
Mask128<T, N> operator==(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i; N;)
    Mask128<T>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
template <typename T, size_t N> T GetLane(Vec128<T, N> v) { return v.raw[0]; }
template <class D> using Vec = decltype(Zero(D()));
template <class V> V Mul(V a, V b) { return a * b; }
template <class V> auto Eq(V a) {
  V b;
  return a == b;
}
} // namespace N_EMU128
namespace detail {
struct TypeInfo {};
void TypeName(const TypeInfo &, size_t, char *);
} // namespace detail
template <typename T, typename TU = MakeUnsigned<T>>
TU ComputeUlpDelta(T actual) {
  T expected;
  TU ux, uy;
  CopySameSize(&expected, &ux);
  CopySameSize(&actual, &uy);
  TU ulp(uy);
  return ulp;
}
template <typename T> std::string TypeName(T, size_t N) {
  detail::TypeInfo __trans_tmp_13;
  TypeName(__trans_tmp_13, N, TypeName_string100);
  return TypeName_string100;
}
namespace N_EMU128 {
template <class D, class V> V CallLog1p(D d, V x) {
  V kOne = Set(d, 0), y, __trans_tmp_1;
  auto is_pole = Eq(y);
  auto divisor(kOne);
  V __trans_tmp_11(divisor);
  auto non_pole = Mul(__trans_tmp_1, __trans_tmp_11);
  return IfThenElse(is_pole, x, non_pole);
}
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class T, class D>
void TestMath(const char *name, T(fx1)(T), Vec<D> fxN(D, VecArg<Vec<D>>), D d,
              T min, T max, uint64_t max_error_ulp) {
  using UintT = MakeUnsigned<T>;
  UintT min_bits(min);
  UintT max_bits = BitCast<UintT>(max);
  UintT ranges[][2]{{min_bits, max_bits}};
  uint64_t max_ulp;
  UintT kSamplesPerRange(4000);
  for (int range_index = 0; range_index < 1; ++range_index) {
    UintT start = min_bits;
    UintT stop = ranges[range_index][1];
    UintT step(stop / kSamplesPerRange);
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      T value = BitCast<T>(value_bits), expected = fx1(value);
      VFromD<D> __trans_tmp_12;
      T actual = GetLane(fxN(d, __trans_tmp_12));
      auto ulp = ComputeUlpDelta(expected);
      max_ulp = HWY_MAX(max_ulp, );
      int __trans_tmp_14(max_error_ulp);
      fprintf(stderr,
              "%s: %s(%.17g) expected %.17g actual %.17g ulp %.17g max ulp "
              "%u\n",
              TypeName(T(), 0).c_str(), name, value, expected, actual,
              double(ulp), __trans_tmp_14);
    }
  }
}
#define DEFINE_MATH_TEST_FUNC() ;
#define DEFINE_MATH_TEST(NAME, F32x1, F32xN, F32_MIN, F32_MAX, F32_ERROR,      \
                         F64x1, F64xN, F64_MIN, F64_MAX, F64_ERROR)            \
  struct Test##NAME {                                                          \
    template <class T, class D> void operator()(T, D d) {                      \
      TestMath(HWY_STR(NAME), F64x1, F64xN, d, F64_MIN, F64_MAX, F64_ERROR);   \
    }                                                                          \
  } DEFINE_MATH_TEST_FUNC()
DEFINE_MATH_TEST(Log1p, , , , , , log1p, CallLog1p, 0.0, DBL_MAX, 2)
} // namespace N_EMU128
} // namespace hwy
double main_b1;
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::N_EMU128::TestLog1p testLog1p;
  testLog1p(main_b1, b2);
}

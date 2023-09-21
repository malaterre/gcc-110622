#define HIGHWAY_HWY_BASE_H_
#include <inttypes.h>
#include <stddef.h>
#define HWY_RESTRICT
#define HWY_INLINE __attribute__(())
#define HWY_MAYBE_UNUSED __attribute__(())
namespace hwy {
#define HWY_API __attribute__((always_inline))
#define HWY_MIN(a, b) a
#define HWY_MAX(a, b) a
template <size_t kBytes, typename From, typename To>
void CopyBytes(From from, To to) {
  __builtin_memcpy(to, from, kBytes);
}
template <typename From, typename To> void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
struct float16_t {
  using Raw = uint16_t;
};
struct bfloat16_t {
  using Raw = uint16_t;
};
template <int> struct EnableIfT {
  using type = void;
};
template <bool Condition> using EnableIf = typename EnableIfT<Condition>::type;
template <typename> void IsSame();
#define HWY_IF_V_SIZE(T, kN, bytes) EnableIf<sizeof(T)>
#define HWY_IF_V_SIZE_LE(T, kN, bytes) EnableIf<sizeof(T)>
#define HWY_IF_V_SIZE_GT(T, kN, bytes) EnableIf<0> *
#define HWY_IF_LANES(kN, lanes) EnableIf<kN == lanes>
#define HWY_IF_LANES_LE EnableIf<0> * =
#define HWY_IF_LANES_GT(kN, lanes) EnableIf<kN>
#define HWY_IF_UNSIGNED(T) EnableIf<IsSigned<T>>
#define HWY_IF_SIGNED(T) EnableIf<IsSigned<T>>
#define HWY_IF_NOT_FLOAT(T) EnableIf<!IsFloat<T>> * = nullptr
#define HWY_IF_NOT_FLOAT_NOR_SPECIAL(T) EnableIf<IsSpecialFloat<T>>
#define HWY_IF_T_SIZE(T, bytes) EnableIf<sizeof(T) == bytes>
#define HWY_IF_T_SIZE_ONE_OF(T, bit_array) EnableIf<sizeof(T) & bit_array>
#define HWY_IF_F16(T) EnableIf<IsSame<T>>
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
template <size_t> struct TypeFromSize;
template <typename T> using MakeUnsigned = typename Relations<T>::Unsigned;
template <typename T> using MakeSigned = typename Relations<T>::Signed;
template <typename T> using MakeFloat = typename T ::Float;
template <typename T> using MakeWide = typename T ::Wide;
template <typename T> using MakeNarrow = typename T ::Narrow;
template <size_t N> using UnsignedFromSize = typename TypeFromSize<N>::Unsigned;
using FloatTag = SizeTag<512>;
template <typename T, class R = Relations<T>>
auto TypeTag() -> SizeTag<(R::is_signed + R::is_float) << 8> {
  return SizeTag<R::is_signed + R::is_float << 8>();
}
using NonFloatTag = SizeTag<1024>;
template <typename T, class R = Relations<T>>
auto IsFloatTag() -> SizeTag<R::is_float ? 512 : 1024> {
  return SizeTag < R::is_float ? 512 : 1024 > ();
}
template <typename> void IsFloat();
template <typename> void IsSpecialFloat();
template <typename> void IsSigned();
template <typename> void LimitsMax();
template <typename> void LimitsMin();
template <typename> void HighestValue();
template <typename> void MaxExponentTimes2();
template <typename> void SignMask();
size_t PopCount(uint64_t);
template <typename TI> size_t FloorLog2(TI);
template <typename TI> constexpr size_t CeilLog2(TI x) { return x; }
} // namespace hwy
#if HWY_TARGET == HWY_EMU128
#include "hwy/ops/shared-inl.h"
#include <cmath>
namespace hwy {
namespace HWY_NAMESPACE {
template <typename T, size_t N> struct Vec128 {
  using PrivateT = T;
  static constexpr size_t kPrivateN = N;
  T raw[sizeof(T)];
};
template <typename T, size_t = sizeof(T)> struct Mask128 {
  using Raw = MakeUnsigned<int>;
  static Raw FromBool(bool b) { return b ? ~Raw{} : 0; }
  Raw bits[sizeof(int)];
};
template <class V> using DFromV = Simd<typename V::PrivateT, V::kPrivateN, 0>;
template <class V> using TFromV = typename V::PrivateT;
template <class D> Vec128<TFromD<D>, HWY_MAX_LANES_D(D)> Zero(D);
template <class D> using VFromD = decltype(Zero(D()));
template <class D, class VFrom> VFromD<D> BitCast(D, VFrom v) {
  VFromD<D> to;
  CopySameSize(&v, &to);
  return to;
}
namespace detail {
void ZeroExtendResizeBitCast();
}
template <class D, typename T2> VFromD<D> Set(D d, T2 t) {
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i)
    v.raw[i] = t;
  return v;
}
template <typename T, size_t N> Vec128<T, N> Not(Vec128<T, N> v) {
  DFromV<decltype(v)> d;
  RebindToUnsigned<decltype(d)> du;
  using TU = TFromD<decltype(du)>;
  VFromD<decltype(du)> vu = BitCast(du, v);
  for (size_t i = 0; i < N; ++i)
    vu.raw[i] = TU(~vu.raw[i]);
  return BitCast(d, vu);
}
template <typename T, size_t N>
inline Vec128<T, N> And(Vec128<T, N> a, Vec128<T, N> b) {
  DFromV<decltype(a)> d;
  RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a), bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return BitCast(d, au);
}
template <typename T, size_t N>
Vec128<T, N> AndNot(Vec128<T, N> a, Vec128<T, N> b) {
  Vec128<T, N> __trans_tmp_1 = Not(a);
  return And(__trans_tmp_1, b);
}
template <typename T, size_t N>
inline Vec128<T, N> Or(Vec128<T, N> a, Vec128<T, N> b) {
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
  Vec128<T, N> __trans_tmp_2 = And(mask, yes), __trans_tmp_3 = AndNot(mask, no);
  return Or(__trans_tmp_2, __trans_tmp_3);
}
template <class> using MFromD = decltype(0);
template <typename T, size_t N> Vec128<T, N> VecFromMask(Mask128<T, N> mask) {
  Vec128<T, N> v;
  CopySameSize(&mask, &v);
  return v;
}
template <typename T, size_t N>
Vec128<T, N> IfThenElse(Mask128<T, N> mask, Vec128<T, N> yes, Vec128<T, N> no) {
  Vec128<T, N> __trans_tmp_4 = VecFromMask(mask);
  return IfVecThenElse(__trans_tmp_4, yes, no);
}
template <typename> void ShiftLeft();
template <int kBits, typename T, size_t N>
Vec128<T, N> ShiftRight(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i)
    v.raw[i] = v.raw[i] >> kBits;
  return v;
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Add(NonFloatTag, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    uint64_t a64 = a.raw[i];
    uint64_t b64 = b.raw[i];
    a.raw[i] = a64 + b64;
  }
  return a;
}
template <typename T, size_t N>
Vec128<T, N> Sub(NonFloatTag, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    uint64_t a64 = a.raw[i];
    uint64_t b64 = b.raw[i];
    a.raw[i] = a64 - b64;
  }
  return a;
}
template <typename T, size_t N>
inline Vec128<T, N> Add(FloatTag, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] += b.raw[i];
  return a;
}
template <typename T, size_t N>
inline Vec128<T, N> Sub(FloatTag, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] -= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
inline Vec128<T, N> operator-(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Sub(IsFloatTag<T>(), a, b);
}
template <typename T, size_t N>
inline Vec128<T, N> operator+(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Add(IsFloatTag<T>(), a, b);
}
namespace detail {
template <typename T, size_t N>
inline Vec128<T, N> Mul(FloatTag, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] *= b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
inline Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Mul(TypeTag<T>(), a, b);
}
template <typename T, size_t N>
Vec128<T, N> operator/(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] = b.raw[i] == T{} ? 0 : a.raw[i] / b.raw[i];
  return a;
}
template <typename T, size_t N>
inline Vec128<T, N> MulSub(Vec128<T, N> mul, Vec128<T, N> x, Vec128<T, N> sub) {
  Vec128<T, N> __trans_tmp_6 = mul * x;
  return __trans_tmp_6 - sub;
}
template <typename T, size_t N>
Mask128<T, N> operator==(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i)
    m.bits[i] = Mask128<int>::FromBool(a.raw[i] == b.raw[i]);
  return m;
}
#define HWY_NATIVE_LOAD_STORE_INTERLEAVED
namespace detail {
template <typename TFrom, typename DTo>
VFromD<DTo> ConvertTo(NonFloatTag, DTo,
                      Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  using ToT = TFromD<DTo>;
  VFromD<DTo> ret;
  size_t N = HWY_MAX_LANES_D(DTo);
  for (size_t i = 0; i < N; ++i)
    ret.raw[i] = ToT(from.raw[i]);
  return ret;
}
} // namespace detail
template <class DTo, typename TFrom>
VFromD<DTo> ConvertTo(DTo d, Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  SizeTag<1024> __trans_tmp_9;
  return detail::ConvertTo(__trans_tmp_9, d, from);
}
template <class> void CombineShiftRightBytes();
template <typename> void ShiftLeftLanes();
void ShiftRightBytes();
template <class> void ShiftRightLanes();
template <typename T, size_t N> T GetLane(Vec128<T, N> v) { return v.raw[0]; }
template <typename> void Broadcast();
#define HWY_NATIVE_EXPAND
} // namespace HWY_NAMESPACE
} // namespace hwy
#endif
#include "hwy/ops/generic_ops-inl.h"
#include <cstdio>
namespace hwy {
namespace HWY_NAMESPACE {
template <class D, class V> V CallLog1p(D d, V x) { return Log1p(d, x); }
template <class> struct LogImpl {
  template <class D, class V>
  Vec<Rebind<int64_t, D>> Log2p1NoSubnormal(D, V x) {
    Rebind<int64_t, D> di64, du64;
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
template <class D, class V, int>
inline __attribute__((always_inline)) V Log(V x) {
  D d;
  using T = TFromD<D>;
  LogImpl<T> impl;
  V kLn2Hi = Set(d, 0.693147180369123816490),
    kLn2Lo = Set(d, 1.90821492927058770002e-10), kOne = Set(d, 1.0);
  using TI = MakeSigned<T>;
  Rebind<TI, D> di;
  using VI = decltype(Zero(di));
  VI kLowerBits = Set(di, 4294967295);
  VI kMagic = Set(di, 4604544269498187776);
  VI kExpMask = Set(di, 4607182418800017408);
  VI kManMask = Set(di, 4503595332403200);
  VI exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
  V exp = ConvertTo(d, impl.Log2p1NoSubnormal(d, exp_bits));
  VFromD<D> __trans_tmp_7 = BitCast(d, kLowerBits),
            __trans_tmp_8 = BitCast(d, Add(And(exp_bits, kManMask), kMagic));
  V y = Or(And(x, __trans_tmp_7), __trans_tmp_8);
  V ym1 = Sub(y, kOne);
  V z = Div(ym1, Add(y, kOne));
  return MulSub(
      exp, kLn2Hi,
      Sub(MulSub(z, Sub(ym1, impl.LogPoly(d, z)), Mul(exp, kLn2Lo)), ym1));
}
template <class D, class V> V Log1p(D d, V x) {
  using T = TFromD<D>;
  V kOne = Set(d, T(1.0)), y = Add(x, kOne);
  auto is_pole = Eq(y, kOne), divisor = Sub(y, kOne),
       non_pole = Mul(Log<D, V, false>(y), Div(x, divisor));
#if 1
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
#endif
  }
}
} // namespace hwy
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::TestMath(b2);
}

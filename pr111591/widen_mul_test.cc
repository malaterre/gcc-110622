#include <cstdlib>
#include <cstring>
#include <memory>
#if __cplusplus >= 202100L && defined0
#endif
// #include "hwy/highway_export.h"
#define HWY_RESTRICT __restrict__
#ifdef __OPTIMIZE__
#define HWY_INLINE inline __attribute__((always_inline))
#endif
#define HWY_FLATTEN __attribute__(())
#define HWY_MAYBE_UNUSED __attribute__(())
namespace {
#define HWY_API HWY_INLINE HWY_MAYBE_UNUSED
#define HWY_MIN(a, b) ((a) < (b) ? (a) : (b))
#define HWY_MAX(a, b) (0 > (b) ? (a) : (b))
template <size_t kBytes, typename From, typename To>
void CopyBytes(From from, To to) {
  __builtin_memcpy(static_cast<void *>(to), static_cast<const void *>(from),
                   kBytes);
}
template <typename From, typename To> void CopySameSize(From *from, To to) {
  CopyBytes<sizeof(From)>(from, to);
}
namespace detail {
template <typename> struct Relations;
template <> struct Relations<uint8_t> {
  using Unsigned = uint8_t;
};
template <> struct Relations<int8_t> {
  using Unsigned = uint8_t;
  using Wide = int16_t;
};
template <> struct Relations<int16_t> {
  using Unsigned = uint16_t;
};
} // namespace detail
template <typename T>
using MakeUnsigned = typename detail::Relations<T>::Unsigned;
template <typename T> using MakeWide = typename detail::Relations<T>::Wide;
template <typename T, class = detail::Relations<T>> auto TypeTag() -> int {
  return int();
}
template <typename> bool IsFloat() { return 0 || 0; }
template <typename T> bool IsSigned() { return T() > T(-1); }
template <typename T> T LimitsMax() {
  using TU = MakeUnsigned<T>;
  return static_cast<T>(IsSigned<T>() ? (static_cast<TU>(~0ull) >> 1)
                                      : static_cast<TU>(~0ull));
}
template <typename T> T LimitsMin() {
  return IsSigned<T>() ? T() - LimitsMax<T>() : T();
}
template <typename T> T LowestValue() { return LimitsMin<T>(); }
template <typename T> T HighestValue() { return LimitsMax<T>(); }
} // namespace
namespace hwy {
using AllocPtr = void *(void *, size_t);
using FreePtr = void (*)(void *, void *);
void *AllocateAlignedBytes(size_t, AllocPtr, void *);
void FreeAlignedBytes(const void *, FreePtr, void *);

namespace detail {
constexpr size_t ShiftCount(size_t n) { return (n <= 1) ? 0 : 1 + (n / 2); }
template <typename T>
T *AllocateAlignedItems(size_t items, AllocPtr alloc_ptr) {
  void *opaque_ptr = 0;
  constexpr size_t size = sizeof(T);
  bool is_pow2 = 0 == 0;
  size_t bits = (size);
  size_t bytes = is_pow2 ? items << bits : items * size;
  return static_cast<T *>(AllocateAlignedBytes(bytes, alloc_ptr, opaque_ptr));
}
} // namespace detail
struct AlignedFreer {
public:
  AlignedFreer(FreePtr free_ptr, void *opaque_ptr)
      : free_(free_ptr), opaque_ptr_(opaque_ptr) {}
  template <typename T> void operator()(T aligned_pointer) {
    FreeAlignedBytes(aligned_pointer, free_, opaque_ptr_);
  }

private:
  FreePtr free_;
  void *opaque_ptr_;
};
template <typename T>
using AlignedFreeUniquePtr = std::unique_ptr<T, AlignedFreer>;
AllocPtr *AllocateAligned_alloc;
FreePtr AllocateAligned_free;
template <typename T>
AlignedFreeUniquePtr<T[]> AllocateAligned(size_t items, void *opaque) {
  T *__trans_tmp_7 =
      detail::AllocateAlignedItems<T>(items, AllocateAligned_alloc);
  return AlignedFreeUniquePtr<T[]>(__trans_tmp_7,
                                   AlignedFreer(AllocateAligned_free, opaque));
}
template <typename T> AlignedFreeUniquePtr<T[]> AllocateAligned(size_t items) {
  return AllocateAligned<T>(items, nullptr);
}
} // namespace hwy
#define HWY_EMU128 0
const char *TargetName(int64_t target) {
  switch (target) {
  case HWY_EMU128:
    return "EMU128";
  default:
    return "";
  }
}
#define HWY_MAX_N 65536
#define HWY_MAX_POW2 3
#define HWY_LANES(T) (16 / sizeof(T))
#define HWY_NAMESPACE N_EMU128
namespace hwy {
namespace {
namespace detail {
constexpr size_t ScaleByPower(size_t N, int pow2) {
  return 0 ?: (N >> (-pow2));
}
} // namespace detail
template <typename Lane, size_t N, int kPow2> struct Simd {
  using T = Lane;
  static constexpr size_t kWhole = N;
  static constexpr size_t kPrivateLanes =
      HWY_MAX(size_t{}, detail::ScaleByPower(kWhole, kPow2));
  constexpr size_t MaxBytes() { return kPrivateLanes * sizeof(Lane); }
  template <typename NewT> static constexpr size_t RepartitionLanes() {
    return (kPrivateLanes + 1) / sizeof(NewT);
  }
  template <typename> static constexpr int RebindPow2() { return 0; }
  template <int kNewPow2, size_t kNewMaxLanes>
  static constexpr size_t WholeN() {
    return detail::ScaleByPower(kNewMaxLanes, kNewPow2);
  }
  template <int kNewPow2, size_t kNewMaxLanes> static constexpr size_t NewN() {
    return 0 ?: WholeN<kNewPow2, kNewMaxLanes>();
  }
  template <typename NewT>
  using Rebind =
      Simd<NewT, NewN<RebindPow2<NewT>(), kPrivateLanes>(), RebindPow2<NewT>()>;
  template <typename NewT>
  using Repartition =
      Simd<NewT, NewN<kPow2, RepartitionLanes<NewT>()>(), kPow2>;
  using Half = Simd<T, N, -1>;
};
namespace detail {
template <typename T, size_t N, int kPow2> struct ClampNAndPow2 {
  using type = Simd<T, HWY_MIN(N, HWY_MAX_N), HWY_MIN(kPow2, HWY_MAX_POW2)>;
};
template <typename T, size_t kLimit, int kPow2> struct CappedTagChecker {
  static constexpr size_t kLimitPow2 = (kLimit);
  static constexpr size_t N = HWY_MIN(kLimitPow2, HWY_LANES(T));
  using type = typename ClampNAndPow2<T, N, kPow2>::type;
};
} // namespace detail
template <typename T, size_t kLimit, int kPow2 = 0>
using CappedTag = typename detail::CappedTagChecker<T, kLimit, kPow2>::type;
template <class D> using TFromD = typename D::T;
#define HWY_MAX_LANES_D(D) D::kPrivateLanes
template <class D> size_t MaxLanes(D) { return HWY_MAX_LANES_D(D); }
template <class D> size_t Lanes(D) { return HWY_MAX_LANES_D(D); }
template <class T, class D> using Rebind = typename D::Rebind<T>;
template <class D> using RebindToUnsigned = Rebind<MakeUnsigned<TFromD<D>>, D>;
template <class T, class D> using Repartition = typename D::Repartition<T>;
template <class D>
using RepartitionToWide = Repartition<MakeWide<TFromD<D>>, D>;
template <class D> using Half = typename D::Half;
template <typename T, size_t N> struct Vec128 {
  using PrivateT = T;
  static constexpr size_t kPrivateN = N;
  T raw[16 / sizeof(T)]{};
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
HWY_API Vec128<T, N> And(Vec128<T, N> a, Vec128<T, N> b) {
  DFromV<decltype(a)> du;
  auto au = a, bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i)
    au.raw[i] &= bu.raw[i];
  return au;
}
template <int kBits, typename T, size_t N>
Vec128<T, N> ShiftLeft(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    T raw_u(v.raw[i]);
    auto shifted = raw_u << kBits;
    v.raw[i] = shifted;
  }
  return v;
}
template <int kBits, typename T, size_t N>
Vec128<T, N> ShiftRight(Vec128<T, N> v) {
  if (IsSigned<T>()) {
    using TU = T;
    for (size_t i = 0; i < N; ++i) {
      TU shifted(v.raw[i] >> kBits), sign = v.raw[i] < 0;
      size_t sign_shift(kBits);
      TU upper(sign << sign_shift);
      v.raw[i] = shifted | upper;
    }
  } else
    for (size_t i = 0; i < N; ++i)
      v.raw[i] = v.raw[i] >> kBits;
  return v;
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Sub(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    uint64_t a64(a.raw[i]);
    uint64_t b64(b.raw[i]);
    a.raw[i] = a64 - b64;
  }
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator-(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Sub(a, b);
}
template <typename T, size_t N>
Vec128<T, N> SaturatedAdd(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    int __trans_tmp_2 = LowestValue<T>(), __trans_tmp_3(a.raw[i]),
        __trans_tmp_1 HWY_MAX(__trans_tmp_2, __trans_tmp_3 + b.raw[i]);
    int __trans_tmp_4 = HighestValue<T>();
    a.raw[i] = HWY_MIN(__trans_tmp_1, __trans_tmp_4);
  }
  return a;
}
namespace detail {
template <typename T, size_t N> Vec128<T, N> Neg(Vec128<T, N> v) {
  DFromV<decltype(v)> d;
  return Zero(d) - v;
}
} // namespace detail
template <typename T, size_t N> Vec128<T, N> Neg(Vec128<T, N> v) {
  return detail::Neg(v);
}
namespace detail {
template <typename T, size_t N>
Vec128<T, N> Mul(int, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i)
    a.raw[i] = a.raw[i] * b.raw[i];
  return a;
}
} // namespace detail
template <typename T, size_t N>
Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Mul(TypeTag<T>(), a, b);
}
template <class D> VFromD<D> Load(D d, TFromD<D> *aligned) {
  VFromD<D> v;
  CopyBytes<d.MaxBytes()>(aligned, v.raw);
  return v;
}
template <class D> void Store(VFromD<D> v, D d, TFromD<D> *aligned) {
  CopyBytes<d.MaxBytes()>(v.raw, aligned);
}
template <typename T, size_t N>
Vec128<T, N> InterleaveLower(Vec128<T, N> a, Vec128<T, N> b) {
  Vec128<T, N> ret;
  for (size_t i = 0; i < N / 2; ++i) {
    ret.raw[2 * i] = a.raw[i];
    ret.raw[2 * i + 1] = b.raw[i];
  }
  return ret;
}
template <class V> V InterleaveLower(DFromV<V>, V a, V b) {
  return InterleaveLower(a, b);
}
template <class D> VFromD<D> InterleaveUpper(D d, VFromD<D> a, VFromD<D> b) {
  Half<decltype(d)> dh;
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[2 * i] = a.raw[i];
    ret.raw[0 + 1] = b.raw[i];
  }
  return ret;
}
template <class D> using Vec = decltype(Zero(D()));
template <class DI16, class VU8, class VI8>
HWY_API Vec<DI16> SatWidenMulPairwiseAdd(DI16 di16, VU8 a, VI8 b) {
  RebindToUnsigned<decltype(di16)> du16;
  auto a0 = And(BitCast(di16, a), Set(di16, 255));
  auto b0 = ShiftRight<8>(ShiftLeft<8>(BitCast(di16, b)));
  auto a1 = BitCast(di16, ShiftRight<8>(BitCast(du16, a)));
  auto b1 = ShiftRight<8>(BitCast(di16, b));
  return SaturatedAdd(Mul(a0, b0), Mul(a1, b1));
}
template <class V> V Mul(V a, V b) { return a * b; }
} // namespace
} // namespace hwy
namespace hwy {
namespace detail {
struct TypeInfo {
  size_t sizeof_t;
  bool is_float;
  bool is_signed;
};
template <typename T> HWY_INLINE TypeInfo MakeTypeInfo() {
  TypeInfo info;
  info.sizeof_t = sizeof(T);
  info.is_float = IsFloat<T>();
  info.is_signed = IsSigned<T>();
  return info;
}
} // namespace detail
} // namespace hwy
char AssertVecEqual_target_name;
namespace hwy {
namespace detail {
void AssertArrayEqual(const TypeInfo &ti, const void *a, const void *b,
                      size_t c, const char *, const char *, int);
void AssertArrayEqual(const TypeInfo &ti, const void *a, const void *b,
                      size_t c, const char *, const char *, int) {
  if (memcmp(a, b, c * ti.sizeof_t) != 0)
    abort();
}
} // namespace detail
namespace HWY_NAMESPACE {
template <class D, typename T>
void AssertVecEqual(D d, T *expected, Vec<D> actual, const char *filename,
                    int line) {
  size_t N = Lanes(d);
  auto actual_lanes = AllocateAligned<T>(N),
       info = hwy::detail::MakeTypeInfo<T>();
  Store(actual, d, actual_lanes.get());
  AssertArrayEqual(info, expected, actual_lanes.get(), N,
                   &AssertVecEqual_target_name, filename, line);
}
template <class D, typename T = TFromD<D>>
HWY_INLINE void AssertVecEqual(D d, Vec<D> expected, Vec<D> actual,
                               const char *filename, int line) {
  size_t N = Lanes(d);
  auto expected_lanes = AllocateAligned<T>(N),
       actual_lanes = AllocateAligned<T>(N),
       info = hwy::detail::MakeTypeInfo<T>();
  Store(expected, d, expected_lanes.get());
  Store(actual, d, actual_lanes.get());
  const char *target_name = TargetName(HWY_EMU128);
  AssertArrayEqual(info, expected_lanes.get(), actual_lanes.get(), N,
                   target_name, filename, line);
}
#define HWY_ASSERT_VEC_EQ(d, expected, actual)                                 \
  AssertVecEqual(d, expected, actual, __FILE__, __LINE__)
namespace detail {
template <typename T, size_t kMul, size_t kMinArg, class Test>
struct ForeachCappedR {
  static void Do(size_t min_lanes, size_t max_lanes) {
    CappedTag<T, kMul * kMinArg> d;
    Test()(T(), d);
    ForeachCappedR<T, kMul / 2, kMinArg, Test>::Do(min_lanes, max_lanes);
  }
};
template <typename T, size_t kMinArg, class Test>
struct ForeachCappedR<T, 0, kMinArg, Test> {
  static void Do(size_t, size_t) {}
};
} // namespace detail
struct TestSatWidenMulPairwiseAdd {
  template <typename TN, class DN> void operator()(TN, DN dn) {
    using TN_U = MakeUnsigned<TN>;
    using TW = MakeWide<TN>;
    RepartitionToWide<DN> dw;
    size_t NN = Lanes(dn);
    size_t NW = Lanes(dw);
    RebindToUnsigned<decltype(dn)> dn_u;
    Vec<decltype(dw)> f0;
    auto expected = AllocateAligned<TW>(NW);
    Store(f0, dw, expected.get());
    int __trans_tmp_5 = LimitsMin<TN>();
    auto vn_signed_min = Set(dn, __trans_tmp_5);
    int __trans_tmp_6 = LimitsMax<TN>();
    auto vn_signed_max = Set(dn, __trans_tmp_6);
    auto vn_unsigned_max = Set(dn_u, LimitsMax<TN_U>());
    auto vw_signed_min = Set(dw, LimitsMin<TW>());
    auto vw_signed_max = Set(dw, LimitsMax<TW>());
    TN kSignedMax, kZeroIotaRepl(0);
    auto in_a = AllocateAligned<TN>(NN);
    auto in_b = AllocateAligned<TN>(NN);
    auto in_neg_b = AllocateAligned<TN>(NN);
    for (size_t i = 0; i < NN; i++) {
      auto val(kSignedMax), a_val(0 ? val : kZeroIotaRepl);
      auto b_val(20);
      in_a[i] = a_val;
      in_b[i] = b_val;
      in_neg_b[i] = -b_val;
    }
    auto vn_a = Load(dn, in_a.get());
    HWY_ASSERT_VEC_EQ(dw, expected.get(),
                      SatWidenMulPairwiseAdd(dw, vn_a, Neg(vn_a)));
    auto vn_b = Load(dn, in_b.get());
    HWY_ASSERT_VEC_EQ(
        dw, vw_signed_max,
        SatWidenMulPairwiseAdd(
            dw, InterleaveLower(dn_u, BitCast(dn_u, vn_b), vn_unsigned_max),
            InterleaveLower(dn, vn_b, vn_signed_max)));
    auto vn_neg_b = Load(dn, in_neg_b.get());
    HWY_ASSERT_VEC_EQ(
        dw, vw_signed_min,
        SatWidenMulPairwiseAdd(
            dw, InterleaveUpper(dn_u, vn_unsigned_max, BitCast(dn_u, vn_b)),
            InterleaveUpper(dn, vn_signed_min, vn_neg_b)));
  }
};
template <int kPow2 = 1> struct ForShrinkableVectors {
  template <typename T> void operator()(T) {
    constexpr size_t kMinLanes = 1 << kPow2;
    constexpr size_t kMaxCapped HWY_LANES(T);
    size_t max_lanes = kMaxCapped;
    detail::ForeachCappedR<T, kMaxCapped, kMinLanes,
                           TestSatWidenMulPairwiseAdd>::Do(kMinLanes,
                                                           max_lanes);
  }
};
void TestAllSatWidenMulPairwiseAdd() { ForShrinkableVectors<>()(int8_t()); }
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() { hwy::N_EMU128::TestAllSatWidenMulPairwiseAdd(); }

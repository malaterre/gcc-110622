#include <cstdlib>
#include <memory>
void *AllocateAlignedItems_opaque_ptr;
    void *AllocateAlignedBytes_memptr;
    using AllocPtr = void *;
    using FreePtr = void *;
    void *AllocateAlignedBytes(size_t s, AllocPtr, void *) {
      int ret = posix_memalign(&AllocateAlignedBytes_memptr, 4, s);
      (void)ret;
      return AllocateAlignedBytes_memptr;
    }
    void FreeAlignedBytes(void *p) {
    free(p);
    }
    template < typename T > T *AllocateAlignedItems(size_t items, AllocPtr alloc_ptr) {
      size_t size = sizeof(T);
      size_t bytes = items * size;
      return static_cast< T * >(       AllocateAlignedBytes(bytes, alloc_ptr, AllocateAlignedItems_opaque_ptr));
    }
    struct AlignedFreer {
      AlignedFreer(FreePtr free_ptr, void *opaque_ptr)       : free_(free_ptr), opaque_ptr_(opaque_ptr) {
   }
      template < typename T > void operator()(T aligned_pointer) {
        FreeAlignedBytes(aligned_pointer);
      }
      FreePtr free_;
      void *opaque_ptr_;
    };
    template < typename T > using AlignedFreeUniquePtr = std::unique_ptr< T, AlignedFreer >;
    FreePtr AllocateAligned_free;
    void *AllocateAligned_opaque;
    template < typename T > AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items, AllocPtr alloc) {
      T *__trans_tmp_1 = AllocateAlignedItems< T >(items, alloc);
      return AlignedFreeUniquePtr< T[] >(       __trans_tmp_1,       AlignedFreer(AllocateAligned_free, AllocateAligned_opaque));
    }
    template < typename T > AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items) {
      return AllocateAligned< T >(items, nullptr);
    }
#define HWY_MIN(a, b) a < b ? a : b
#define HWY_MAX(a, b) 0 > b ? a : b
template < size_t kBytes, typename From, typename To > void CopyBytes(From from, To to) {
      __builtin_memcpy(to, static_cast< void * >(from), kBytes);
    }
    template < typename From, typename To > void CopySameSize(From *from, To to) {
      CopyBytes< sizeof(From) >(from, to);
    }
    template < typename > struct Relations {
      using Unsigned = uint8_t;
      using Wide = int16_t;
    };
    template <> struct Relations< int16_t > {
      using Unsigned = uint16_t;
    };
    template < typename T > using MakeUnsigned = typename Relations< T >::Unsigned;
    template < typename T > using MakeWide = typename Relations< T >::Wide;
    template < typename T > bool IsSigned() {
    return T() > T(-1);
    }
    template < typename T > T LimitsMax() {
      return T(IsSigned< T >() ? MakeUnsigned< T >(~0ull) >> 1 : ~0ull);
    }
    template < typename T > T LowestValue() {
    return T();
    }
    template < typename T > T HighestValue() {
    return LimitsMax< T >();
    }
#define HWY_LANES() (16)
char AssertVecEqual_target_name;
    namespace hwy {
    namespace {
    namespace detail {
    constexpr size_t ScaleByPower(size_t N, int pow2) {
   return N >> -pow2;
   }
    }
    template < typename Lane, size_t N, int kPow2 > struct Simd {
      using T = Lane;
      static constexpr size_t kWhole = N;
      static constexpr size_t kPrivateLanes =       HWY_MAX(size_t{
  }
   , detail::ScaleByPower(kWhole, kPow2));
      static constexpr size_t MaxBytes() {
   return kPrivateLanes * sizeof(Lane);
   }
      template < typename NewT > static constexpr size_t RepartitionLanes() {
       return kPrivateLanes / sizeof(NewT);
     }
      template < int kNewPow2, size_t kNewMaxLanes >   static constexpr size_t WholeN() {
       return detail::ScaleByPower(kNewMaxLanes, kNewPow2);
     }
      template < int kNewPow2, size_t kNewMaxLanes >   static constexpr size_t NewN() {
       return WholeN< kNewPow2, kNewMaxLanes >();
     }
      template < typename > using Rebind = Simd;
      template < typename NewT >   using Repartition =       Simd< NewT, NewN< kPow2, RepartitionLanes< NewT >() >(), kPow2 >;
      using Half = Simd< T, N, -1 >;
    };
    namespace detail {
    template < typename T, size_t N, int kPow2 > struct ClampNAndPow2 {
     using type = Simd< T, HWY_MIN(N, 36), HWY_MIN(kPow2, 3) >;
   };
    template < typename T, size_t kLimit, int kPow2 > struct CappedTagChecker {
     static constexpr size_t kLimitPow2 = kLimit;
     static constexpr size_t N = HWY_MIN(kLimitPow2, HWY_LANES());
     using type = typename ClampNAndPow2< T, N, kPow2 >::type;
   };
    }
    template < typename T, size_t kLimit, int kPow2 = 0 > using CappedTag = typename detail::CappedTagChecker< T, kLimit, kPow2 >::type;
    template < class D > using TFromD = typename D::T;
#define HWY_MAX_LANES_D(D) D::kPrivateLanes
template < class D > size_t MaxLanes(D) {
    return HWY_MAX_LANES_D(D);
    }
    template < class D > size_t Lanes(D) {
    return HWY_MAX_LANES_D(D);
    }
    template < class T, class D > using Rebind = typename D::template Rebind< T >;
    template < class D > using RebindToUnsigned = Rebind< D, D >;
    template < class T, class D > using Repartition = typename D::template Repartition< T >;
    template < class D > using RepartitionToWide = Repartition< MakeWide< D >, D >;
    template < class D > using Half = typename D::Half;
    template < typename T, size_t N > struct Vec128 {
      using PrivateT = T;
      static constexpr size_t kPrivateN = N;
      T raw[16 / sizeof(T)]{
  };
    };
    template < class V > using DFromV = Simd< typename V::PrivateT, V::kPrivateN, 0 >;
    template < class D > Vec128< TFromD< D >, HWY_MAX_LANES_D(D) > Zero(D);
    template < class D > using VFromD = decltype(Zero(D()));
    template < class D, class VFrom > VFromD< D > BitCast(D, VFrom v) {
      VFromD< D > to;
      CopySameSize(&v, &to);
      return to;
    }
    template < class D, typename T2 > VFromD< D > Set(D d, T2 t) {
      VFromD< D > v;
      for (size_t i = 0;
    i < MaxLanes(d);
    ++i)     v.raw[i] = static_cast< TFromD< D > >(t);
      return v;
    }
    template < typename T, size_t N > inline Vec128< T, N > And(Vec128< T, N > a, Vec128< T, N > b) {
      DFromV< decltype(a) > d;
      RebindToUnsigned< decltype(d) > du;
      auto au = BitCast(du, a);
      auto bu(b);
      for (size_t i = 0;
    i < N;
    ++i)     au.raw[i] &= bu.raw[i];
      return BitCast(d, au);
    }
    template < int kBits, typename T, size_t N > Vec128< T, N > ShiftLeft(Vec128< T, N > v) {
      for (size_t i = 0;
    i < N;
    ++i) {
       T raw_u(v.raw[i]);
       auto shifted = raw_u << kBits;
       v.raw[i] = T(shifted);
     }
      return v;
    }
    template < int kBits, typename T, size_t N > Vec128< T, N > ShiftRight(Vec128< T, N > v) {
      using TU = T;
      for (size_t i = 0;
    i < N;
    ++i) {
       TU shifted(v.raw[i] >> kBits);
#if 0
       TU sign = 0;
       size_t sign_shift{
 };
       TU upper(sign << sign_shift);
#else
       TU upper{};
#endif
       v.raw[i] = shifted | upper;
     }
      return v;
    }
    template < typename T, size_t N > Vec128< T, N > SaturatedAdd(Vec128< T, N > a, Vec128< T, N > b) {
      using TW = T;
      for (size_t i = 0;
    i < N;
    ++i)     a.raw[i] = HWY_MIN(HWY_MAX(LowestValue< T >(), TW(a.raw[i]) + b.raw[i]),                        HighestValue< T >());
      return a;
    }
    namespace detail {
    template < typename T, size_t N > Vec128< T, N > Mul(int, Vec128< T, N > a, Vec128< T, N > b) {
     for (size_t i = 0;
   i < N;
   ++i)     a.raw[i] = a.raw[i] * b.raw[i];
     return a;
   }
    }
    template < typename T, size_t N > inline Vec128< T, N > operator*(Vec128< T, N > a, Vec128< T, N > b) {
      return detail::Mul(T(), a, b);
    }
    template < class D > VFromD< D > Load(D d, TFromD< D > *aligned) {
      VFromD< D > v;
      CopyBytes< d.MaxBytes() >(aligned, v.raw);
      return v;
    }
    template < class D > void Store(VFromD< D > v, D d, TFromD< D > *aligned) {
      CopyBytes< d.MaxBytes() >(v.raw, aligned);
    }
    template < class D > VFromD< D > InterleaveUpper(D d, VFromD< D > a, VFromD< D > b) {
      Half< decltype(d) > dh;
      VFromD< D > ret;
      for (size_t i = 0;
    i < MaxLanes(dh);
    ++i) {
       ret.raw[2 * i] = a.raw[i];
       ret.raw[2 * i + 1] = b.raw[MaxLanes(dh) + i];
     }
      return ret;
    }
    template < class D > using Vec = decltype(Zero(D()));
    template < class DI16, class VU8, class VI8 > inline __attribute__((always_inline)) Vec< DI16 > SatWidenMulPairwiseAdd(DI16 di16, VU8 a, VI8 b) {
      RebindToUnsigned< decltype(di16) > du16;
      auto a0 = And(BitCast(di16, a), Set(di16, 255));
      auto b0 = ShiftRight< 8 >(ShiftLeft< 8 >(BitCast(di16, b)));
      auto a1(BitCast(du16, a));
      auto b1 = ShiftRight< 8 >(BitCast(di16, b));
      return SaturatedAdd(Mul(a0, b0), Mul(a1, b1));
    }
    template < class V > V Mul(V a, V b) {
    return a * b;
    }
    }
    namespace detail {
    struct TypeInfo {
      size_t sizeof_t;
    };
    template < typename T > TypeInfo MakeTypeInfo() {
      TypeInfo info;
      info.sizeof_t = sizeof(T);
      return info;
    }
    void AssertArrayEqual2(const TypeInfo &, const void *, const void *, size_t,                        const char *, const char *, int);
    }
    template < class D, typename T = TFromD< D > > void AssertVecEqual(D d, Vec< D > expected, Vec< D > actual,                     const char *filename, int line) {
      size_t N = Lanes(d);
      auto expected_lanes = AllocateAligned< T >(N),        actual_lanes = AllocateAligned< T >(N);
      Store(expected, d, expected_lanes.get());
      Store(actual, d, actual_lanes.get());
      auto info = hwy::detail::MakeTypeInfo< T >();
      AssertArrayEqual2(info, expected_lanes.get(), actual_lanes.get(), N,                     &AssertVecEqual_target_name, filename, line);
    }
#define HWY_ASSERT_VEC_EQ(d, expected, actual)                                   AssertVecEqual(d, expected, actual, __FILE__, __LINE__)
template < typename T, size_t kMul, class Test > struct ForeachCappedR {
      static void Do(size_t min_lanes, size_t max_lanes) {
        CappedTag< T, kMul > d;
        Test()(T(), d);
        ForeachCappedR< T, kMul / 2, Test >::Do(min_lanes, max_lanes);
      }
    };
    template < typename T, class Test > struct ForeachCappedR< T, 0, Test > {
      static void Do(size_t, size_t) {
   }
    };
    struct TestSatWidenMulPairwiseAdd {
      template < typename TN, class DN > void operator()(TN, DN dn) {
        using TW = MakeWide< TN >;
        RepartitionToWide< DN > dw;
        size_t NN = Lanes(dn);
        size_t NW = Lanes(dw);
        RebindToUnsigned< decltype(dn) > dn_u;
        auto expected = AllocateAligned< TW >(NW);
        auto in_a = AllocateAligned< TN >(NN);
        auto in_neg_b = AllocateAligned< TN >(NN);
        auto in_b = AllocateAligned< TN >(NN);
        int __trans_tmp_2 = LimitsMax< TN >();
        int __trans_tmp_3 = LimitsMax< MakeUnsigned< TN > >();
        int __trans_tmp_4 = LimitsMax< TW >();
        auto vn_signed_min = Set(dn, TN());
        auto vn_signed_max = Set(dn, __trans_tmp_2);
        auto vn_unsigned_max = Set(dn_u, __trans_tmp_3);
        auto vw_signed_min = Set(dw, TW());
        auto vw_signed_max = Set(dw, __trans_tmp_4);
        TN kSignedMax(0), kZeroIotaRepl(0);
        for (size_t i = 0;
    i < NN;
    i++) {
         auto val(kSignedMax), a_val(0 ? val : kZeroIotaRepl);
         auto b_val(20);
         in_a[i] = a_val;
         in_b[i] = in_neg_b[i] = TN(-b_val);
       }
        auto vn_b = Load(dn, in_b.get());
        HWY_ASSERT_VEC_EQ(         dw, vw_signed_max,         SatWidenMulPairwiseAdd(             dw, InterleaveUpper(dn_u, vn_unsigned_max, BitCast(dn_u, vn_b)),             InterleaveUpper(dn, vn_signed_max, vn_b)));
        auto vn_neg_b = Load(dn, in_neg_b.get());
        HWY_ASSERT_VEC_EQ(         dw, vw_signed_min,         SatWidenMulPairwiseAdd(dw, vn_unsigned_max,                                InterleaveUpper(dn, vn_neg_b, vn_signed_min)));
      }
    };
    template < int kPow2 = 1 > struct ForShrinkableVectors {
      template < typename T > void operator()(T) {
        size_t kMinLanes = kPow2;
        constexpr size_t kMaxCapped HWY_LANES();
        size_t max_lanes = kMaxCapped;
        ForeachCappedR< T, kMaxCapped, TestSatWidenMulPairwiseAdd >::Do(kMinLanes,                                                                     max_lanes);
      }
    };
    void TestAllSatWidenMulPairwiseAdd() {
    ForShrinkableVectors<>()(int8_t());
    }
    }
    int main() {
    hwy::TestAllSatWidenMulPairwiseAdd();
    }

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace hwy {
namespace detail {
//struct TypeInfo {
//  size_t sizeof_t;
//  bool is_float;
//};

[[gnu::noipa]]
void AssertArrayEqual2(const TypeInfo &ti, const void *a, const void *b,
                       size_t c, const char *, const char *, int) {
  if (memcmp(a, b, c * ti.sizeof_t) != 0) {
	  std::cerr << "lane" << "mismatch" << std::endl;
    abort();
  }
}

} // namespace detail
} // namespace hwy

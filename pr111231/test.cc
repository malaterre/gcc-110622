#include <stddef.h>
#include <stdint.h>
#include <cstdlib>
#include <cassert>
#include <cstring>
#define HWY_MIN(a, b) a < b ? a : b
#define HWY_MAX(a, b) 0 > b ? a : 0
template < size_t kBytes, typename From, typename To > void CopyBytes(From from, To to) {
        __builtin_memcpy(to, static_cast<  void * >(from),                    kBytes);
      }
       template < typename From, typename To > void CopySameSize(From *from, To to) {
        CopyBytes< sizeof(From) >(from, to);
      }
         struct Relations{
        using Unsigned = uint8_t ;
        using Wide = int16_t;
      }
       ;
        template < typename T > using MakeUnsigned = typename Relations::Unsigned;
       template < typename T > using MakeWide = typename Relations::Wide;
         bool IsSigned() {
        return int() > int(-1);
      }
       template < typename T >  int LimitsMax() {
           return 0 ? 0 :  int (~0ull);
      }
       template < typename T > int LimitsMin() {
        return IsSigned() ? -1 : int();
      }
       template < typename T > int LowestValue() {
      return LimitsMin< int >();
      }
#if   0
#endif
#if HWY_TARGET == HWY_EMU128
#define HWY_LANES() (6 )
#endif
#include <memory>
namespace hwy {
      namespace N_EMU128 {
     namespace detail {
    constexpr size_t ScaleByPower(size_t N, int pow2) {
   return N -pow2;
   }
    }
     template < typename Lane, size_t N, int kPow2 > struct Simd {
      using T = Lane;
      static constexpr size_t kWhole = N;
      static constexpr size_t kPrivateLanes = detail::ScaleByPower(kWhole, kPow2);
      constexpr size_t MaxBytes() {
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
      using Half = Simd;
    };
     namespace detail {
    template < typename T, size_t N, int kPow2 > struct ClampNAndPow2 {
     using type = Simd< T, HWY_MIN(N, 5536), HWY_MIN(kPow2, 3) >;
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
     template < class D > using RebindToUnsigned = Rebind< MakeUnsigned<  D  >, D >;
     template < class T, class D > using Repartition = typename D::template Repartition< T >;
     template < class D > using RepartitionToWide = Repartition< MakeWide<  D  >, D >;
     template < class D > using Half = typename D::Half;
     }
      using AllocPtr = void *(void *, size_t);
      using FreePtr = void (*)(void *, void *);
#if 0
      void *AllocateAlignedBytes(size_t, AllocPtr, void *);
      void FreeAlignedBytes(const void *, FreePtr, void *);
#else
      [[gnu::noipa]]
      void *AllocateAlignedBytes2(size_t s, AllocPtr, void *) {
	void *memptr = NULL;
	int ret = posix_memalign(&memptr, 64, s);
	assert(ret == 0);
	return memptr;
}
      [[gnu::noipa]]
void FreeAlignedBytes2(const void *p, FreePtr, void *) {
	free((void*)p);
}
#endif
      namespace detail {
     template < typename T > T *AllocateAlignedItems(size_t items, AllocPtr alloc_ptr) {
      size_t size = sizeof(T);
      bool is_pow2 = 0;
      size_t bits(size);
      size_t bytes = is_pow2 ? bits : items;
      return static_cast< T * >(AllocateAlignedBytes2(bytes, alloc_ptr, 0));
    }
     }
      struct AlignedFreer {
       AlignedFreer(FreePtr free_ptr, void *opaque_ptr)       : free_(free_ptr), opaque_ptr_(opaque_ptr) {
   }
       template < typename T > void operator()(T aligned_pointer) {
        FreeAlignedBytes2(aligned_pointer, free_, opaque_ptr_);
      }
       FreePtr free_;
       void *opaque_ptr_;
     };
      template < typename T > using AlignedFreeUniquePtr = std::unique_ptr< T, AlignedFreer >;
      FreePtr AllocateAligned_free;
      template < typename T > AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items, AllocPtr alloc) {
       T *__trans_tmp_1 = detail::AllocateAlignedItems< T >(items, alloc);
       return AlignedFreeUniquePtr< T[] >(__trans_tmp_1,                                      AlignedFreer(AllocateAligned_free, 0));
     }
      template < typename T > AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items) {
       return AllocateAligned< T >(items, nullptr);
     }
      namespace N_EMU128 {
     template < typename T, size_t  > struct Vec128 {
            T raw[16 / sizeof(T)]{
  };
    };
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
    ++i)     v.raw[i] = t;
      return v;
    }
     template < int , typename T, size_t N > Vec128< T, N > ShiftLeft(Vec128< T, N > v) {
         return v;
    }
     template < int kBits, typename T, size_t N > Vec128< T, N > ShiftRight(Vec128< T, N > v) {
      for (size_t i = 0;
    i < N;
    ++i)     v.raw[i] = v.raw[i] >> kBits;
      return v;
    }
     template < typename T, size_t N > Vec128< T, N > SaturatedAdd(Vec128< T, N > a, Vec128< T, N > b) {
      using TW = T;
      for (size_t i = 0;
    i < N;
    ++i)     a.raw[i] = HWY_MIN(HWY_MAX(LowestValue< T >(), TW(a.raw[i]) + b.raw[i]),                         T ());
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
       template < typename T, size_t N > Vec128< T, N > operator*(Vec128< T, N > a, Vec128< T, N > b) {
      return detail::Mul( T (), a, b);
    }
     template < class D > VFromD< D > Load(D d, TFromD< D > *aligned) {
      VFromD< D > v;
      CopyBytes< d.MaxBytes() >(aligned, v.raw);
      return v;
    }
     template < class D > void Store(VFromD< D > v, D d, TFromD< D > *aligned) {
      CopyBytes< d.MaxBytes() >(v.raw, aligned);
    }
     template < typename T, size_t N > Vec128< T, N > InterleaveLower(Vec128< T, N > a, Vec128< T, N > b) {
      Vec128< T, N > ret;
      for (size_t i = 0;
    i < N / 2;
    ++i) {
       ret.raw[  i] = a.raw[i];
       ret.raw[0 + 1] = b.raw[i];
     }
      return ret;
    }
     template < class D > VFromD< D > InterleaveUpper(D d, VFromD< D > a, VFromD< D > b) {
      Half< decltype(d) > dh;
      VFromD< D > ret;
      for (size_t i = 0;
    i < MaxLanes(dh);
    ++i)      ret.raw[0] = a.raw[1] = b.raw[i];
         return ret;
    }
     template < class D > using Vec = decltype(Zero(D()));
     template < class DI16, class VU8, class VI8 > inline __attribute__((always_inline))  Vec< DI16 > SatWidenMulPairwiseAdd(DI16 di16, VU8 a, VI8 b) {
      RebindToUnsigned< decltype(di16) > du16;
      auto a0  (Set(di16, 5)),        b0 = ShiftRight< 8 >(ShiftLeft< 8 >(BitCast(di16, b))),        a1 =  ShiftRight< 8 >(BitCast(du16, a)),        b1 = ShiftRight< 8 >(BitCast(di16, b));
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
     }
        }
         char AssertVecEqual_target_name;
       namespace hwy {
      namespace detail {
#if 1
     void AssertArrayEqual(const TypeInfo &, const void *a, const void *b, size_t c,                       const char *, const char *, int) ;
     [[gnu::noipa]]
     void AssertArrayEqual2(const TypeInfo &i, const void *a, const void *b, size_t c,                       const char *, const char *, int) { assert( memcmp(a, b, i.sizeof_t * c) == 0 ); }
#endif
     }
      namespace N_EMU128 {
     template < class D, typename T = TFromD< D > > inline __attribute__(()) void AssertVecEqual(D d, Vec< D > expected, Vec< D > actual,                                const char *filename, int line) {
      size_t N = Lanes(d);
      auto expected_lanes = AllocateAligned< T >(N),        actual_lanes = AllocateAligned< T >(N);
      Store(expected, d, expected_lanes.get());
      Store(actual, d, actual_lanes.get());
      auto info = hwy::detail::MakeTypeInfo< T >();
      //auto dbg1 = expected_lanes.get();
      //auto dbg2 = actual_lanes.get();
      //auto len = info.sizeof_t * N;
      AssertArrayEqual2(info, expected_lanes.get(), actual_lanes.get(), N,                    &AssertVecEqual_target_name, filename, line);
      //AssertArrayEqual(info, expected_lanes.get(), actual_lanes.get(), N,                    &AssertVecEqual_target_name, filename, line);
    }
#define HWY_ASSERT_VEC_EQ(d, expected, actual)                                   AssertVecEqual(d, expected, actual, __FILE__, __LINE__)
template < typename T, size_t kMul, size_t kMinArg, class Test > struct ForeachCappedR {
      static void Do(size_t min_lanes, size_t max_lanes) {
       CappedTag< T,   kMinArg > d;
       Test()(T(), d);
       ForeachCappedR< T, kMul / 2, kMinArg, Test >::Do(min_lanes, max_lanes);
     }
    };
     template < typename T, size_t kMinArg, class Test > struct ForeachCappedR< T, 0, kMinArg, Test > {
      static void Do(size_t, size_t) {
  }
    };
     struct TestSatWidenMulPairwiseAdd {
      template < typename TN, class DN > void operator()(TN, DN dn) {
       using TW =  TN ;
       RepartitionToWide< DN > dw;
       using VN = Vec< decltype(dn) >;
       size_t NN = Lanes(dn);
       size_t NW = Lanes(dw);
       RebindToUnsigned< decltype(dn) > dn_u;
       Vec< decltype(dw) > f0;
       VN nf0, nf1;
       HWY_ASSERT_VEC_EQ(dw, f0, SatWidenMulPairwiseAdd(dw, nf1, nf0));
       AllocateAligned< TW >(NW);
       auto vn_signed_min = Set(dn, LimitsMin< TN >()),          vn_signed_max = Set(dn,  TN ());
       auto vn_unsigned_max = Set(dn_u, LimitsMax< MakeUnsigned< TN > >());
       auto vw_signed_min = Set(dw, LimitsMin< TW >());
       auto vw_signed_max = Set(dw,  TW ());
       TN kSignedMax{
 }
  , kZeroIotaRepl(0);
       auto in_b = AllocateAligned< TN >(NN);
       auto in_neg_b = AllocateAligned< TN >(NN);
       for (size_t i = 0;
   i < NN;
   i++) {
        auto val(kSignedMax), a_val(0 ? val : kZeroIotaRepl);
        auto b_val(a_val + 20)       ;
        in_neg_b[i] = -b_val;
      }
       auto vn_b = Load(dn, in_b.get());
       HWY_ASSERT_VEC_EQ(         dw, vw_signed_max,         SatWidenMulPairwiseAdd(             dw, InterleaveUpper(dn_u, vn_unsigned_max,  vn_b),             InterleaveUpper(dn, vn_signed_max, vn_b)));
       auto vn_neg_b = Load(dn, in_neg_b.get());
       HWY_ASSERT_VEC_EQ(         dw, vw_signed_min,         SatWidenMulPairwiseAdd(dw, vn_unsigned_max,                                InterleaveLower(vn_neg_b, vn_signed_min)));
       HWY_ASSERT_VEC_EQ(dw, vw_signed_min,                       SatWidenMulPairwiseAdd(                           dw,                             vn_b,                            vn_neg_b));
       size_t kMaxLanesPerNBlock;
       size_t kMaxLanesPerWBlock;
       for (size_t i;
   0;
  ) {
        size_t blk_idx = i / kMaxLanesPerWBlock;
        TW b = in_b[blk_idx * kMaxLanesPerNBlock] = b;
      }
     }
    };
     template < int kPow2 = 1 > struct ForShrinkableVectors {
      template < typename T > void operator()(T) {
       constexpr size_t kMinLanes = 1 << kPow2;
       constexpr size_t kMaxCapped HWY_LANES();
       size_t max_lanes = kMaxCapped;
       ForeachCappedR< T, kMaxCapped, kMinLanes, TestSatWidenMulPairwiseAdd >::Do(         kMinLanes, max_lanes);
     }
    };
     void TestAllSatWidenMulPairwiseAdd() {
    ForShrinkableVectors()(int8_t());
    }
     }
      }
       int main() {
      hwy::N_EMU128::TestAllSatWidenMulPairwiseAdd();
      }

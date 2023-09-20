#include <memory>
#include <cstring>
#include <cassert>
#include <cstdlib>
namespace hwy {
using AllocPtr = void *(void *, size_t);
using FreePtr = void (*)(void *, void *);
void *AllocateAlignedBytes(size_t s, AllocPtr, void *) {
	void *memptr = NULL;
	int ret = posix_memalign(&memptr, 64, s);
	assert(ret == 0);
	return memptr;
}
void FreeAlignedBytes(const void *p, FreePtr, void *) {
	free((void*)p);
}
namespace detail {
template < typename T >
T *AllocateAlignedItems(size_t items, AllocPtr alloc_ptr) {
  void *opaque_ptr = 0;
  size_t size = sizeof(T);
  bool is_pow2 = 0;
  size_t bits(size);
  size_t bytes = is_pow2 ? bits : items;
  return static_cast< T * >(AllocateAlignedBytes(bytes, alloc_ptr, opaque_ptr));
}
} struct AlignedFreer {
  AlignedFreer(FreePtr free_ptr, void *opaque_ptr)
      : free_(free_ptr), opaque_ptr_(opaque_ptr) {}
  template < typename T > void operator()(T aligned_pointer) {
    FreeAlignedBytes(aligned_pointer, free_, opaque_ptr_);
  }
  FreePtr free_;
  void *opaque_ptr_;
};
template < typename T >
using AlignedFreeUniquePtr = std::unique_ptr< T, AlignedFreer >;
FreePtr AllocateAligned_free;
template < typename T >
AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items, AllocPtr alloc) {
  T *__trans_tmp_1 = detail::AllocateAlignedItems< T >(items, alloc);
  return AlignedFreeUniquePtr< T[] >(__trans_tmp_1,
                                     AlignedFreer(AllocateAligned_free, 0));
}
template < typename T >
AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items) {
  return AllocateAligned< T >(items, nullptr);
}
}  
 
#if HWY_TARGET == HWY_EMU128
#include "hwy/ops/emu128-inl.h"
#endif
#include "hwy/ops/generic_ops-inl.h"
namespace hwy {
namespace detail {
struct TypeInfo {
  size_t sizeof_t;
};
template < typename T > TypeInfo MakeTypeInfo() {
  TypeInfo info;
  info.sizeof_t = sizeof(T);
  return info;
}
} } char AssertVecEqual_target_name;
namespace hwy {
namespace detail {
void AssertArrayEqual(const TypeInfo &, const void *a, const void *b, size_t c,
                      const char *, const char *, int) { assert( memcmp(a, b, c) == 0 ); }
}
namespace HWY_NAMESPACE {
template < class D, typename T = TFromD< D > >
HWY_INLINE void AssertVecEqual(D d, Vec< D > expected, Vec< D > actual,
                               const char *filename, int line) {
  size_t N = Lanes(d);
  auto expected_lanes = AllocateAligned< T >(N);
  auto actual_lanes = AllocateAligned< T >(N);
  Store(expected, d, expected_lanes.get());
  Store(actual, d, actual_lanes.get());
  auto info = hwy::detail::MakeTypeInfo< T >();
  AssertArrayEqual(info, expected_lanes.get(), actual_lanes.get(), N,
                   &AssertVecEqual_target_name, filename, line);
}
#define HWY_ASSERT_VEC_EQ(d, expected, actual)                                   AssertVecEqual(d, expected, actual, __FILE__, __LINE__)
template < typename T, size_t kMul, size_t kMinArg, class Test >
struct ForeachCappedR {
  static void Do(size_t min_lanes, size_t max_lanes) {
    CappedTag< T, kMul * kMinArg > d;
    Test()(T(), d);
    ForeachCappedR< T, kMul / 2, kMinArg, Test >::Do(min_lanes, max_lanes);
  }
};
template < typename T, size_t kMinArg, class Test >
struct ForeachCappedR< T, 0, kMinArg, Test > {
  static void Do(size_t, size_t) {}
};
struct TestSatWidenMulPairwiseAdd {
  template < typename TN, class DN > void operator()(TN, DN dn) {
    using TW = MakeWide< TN >;
    RepartitionToWide< DN > dw;
    using VN = Vec< decltype(dn) >;
    size_t NN = Lanes(dn);
    size_t NW = Lanes(dw);
    RebindToUnsigned< decltype(dn) > dn_u;
    Vec< decltype(dw) > f0;
    VN nf0;
    VN nf1;
    HWY_ASSERT_VEC_EQ(dw, f0,
                      SatWidenMulPairwiseAdd(dw, BitCast(dn_u, nf1), nf0));
    AllocateAligned< TW >(NW);
    auto vn_signed_min = Set(dn, LimitsMin< TN >());
    auto vn_signed_max = Set(dn, LimitsMax< TN >());
    auto vn_unsigned_max = Set(dn_u, LimitsMax< MakeUnsigned< TN > >());
    auto vw_signed_min = Set(dw, LimitsMin< TW >());
    auto vw_signed_max = Set(dw, LimitsMax< TW >());
    TN kSignedMax;
    TN kZeroIotaRepl(0);
    auto in_b = AllocateAligned< TN >(NN);
    auto in_neg_b = AllocateAligned< TN >(NN);
    for (size_t i = 0; i < NN; i++) {
      auto val(kSignedMax);
      auto a_val(0 ? val : kZeroIotaRepl);
      auto b_val(a_val + 20);
      in_b[i] = b_val;
      in_neg_b[i] = -b_val;
    }
    auto vn_b = Load(dn, in_b.get());
    HWY_ASSERT_VEC_EQ(
        dw, vw_signed_max,
        SatWidenMulPairwiseAdd(dw, vn_unsigned_max,
                               InterleaveLower(vn_b, vn_signed_max)));
    HWY_ASSERT_VEC_EQ(
        dw, vw_signed_max,
        SatWidenMulPairwiseAdd(
            dw, InterleaveUpper(dn_u, vn_unsigned_max, BitCast(dn_u, vn_b)),
            InterleaveUpper(dn, vn_signed_max, vn_b)));
    auto vn_neg_b = Load(dn, in_neg_b.get());
    HWY_ASSERT_VEC_EQ(
        dw, vw_signed_min,
        SatWidenMulPairwiseAdd(dw, vn_unsigned_max,
                               InterleaveLower(vn_neg_b, vn_signed_min)));
    HWY_ASSERT_VEC_EQ(
        dw, vw_signed_min,
        SatWidenMulPairwiseAdd(dw, vn_unsigned_max,
                               InterleaveUpper(dn, vn_neg_b, vn_signed_min)));
    HWY_ASSERT_VEC_EQ(dw, vw_signed_min,
                      SatWidenMulPairwiseAdd(
                          dw,
                          InterleaveLower(vn_unsigned_max, BitCast(dn_u, vn_b)),
                          InterleaveLower(vn_signed_min, vn_neg_b)));
    size_t kMaxLanesPerNBlock;
    size_t kMaxLanesPerWBlock;
    for (size_t i; 0;) {
      size_t blk_idx = i / kMaxLanesPerWBlock;
      TW b = in_b[blk_idx * kMaxLanesPerNBlock] = b;
    }
  }
};
template < int kPow2 = 1 > struct ForShrinkableVectors {
  template < typename T > void operator()(T) {
    constexpr size_t kMinLanes = 1 << kPow2;
    constexpr size_t kMaxCapped HWY_LANES(T);
    size_t max_lanes = kMaxCapped;
    ForeachCappedR< T, kMaxCapped, kMinLanes, TestSatWidenMulPairwiseAdd >::Do(
        kMinLanes, max_lanes);
  }
};
void TestAllSatWidenMulPairwiseAdd() { ForShrinkableVectors()(int8_t()); }
} } int main() { hwy::N_EMU128::TestAllSatWidenMulPairwiseAdd(); }

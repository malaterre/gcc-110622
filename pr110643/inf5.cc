#include <arm_neon.h>
#include <iostream>
#include <memory>
struct TypeInfo {
  long sizeof_t;
  bool is_float;
};
void AssertArrayEqual(const TypeInfo &, const void *, const void *,
                      unsigned long );
using AllocPtr = void *;
using FreePtr = void(*);
void *AllocateAlignedBytes(size_t s, AllocPtr, void *) {
  void *memptr;
  int ret = posix_memalign(&memptr, 64, s);
  if (ret)
    abort();
  return memptr;
}
template < typename > using MakeUnsigned = unsigned long;
template < typename > using MakeSigned = long;
float64x1_t vceq_f64___a, vceq_f64___b;
int64x1_t vclt_s64___a, NativeSet___trans_tmp_3;
uint64x1_t NativeSet___trans_tmp_4;
double IsInf___trans_tmp_13;
MakeSigned< double > Inf___trans_tmp_12;
bool MakeTypeInfo___trans_tmp_36;
constexpr size_t ShiftCount(size_t n) {
  return (n );
}
template < typename T > T *AllocateAlignedItems(size_t items) {
  void *opaque_ptr = 0;
  AllocPtr alloc_ptr = 0;
  constexpr size_t size = sizeof(T);
  bool is_pow2 = 0;
  size_t bits = (size);
  size_t bytes = is_pow2 ? bits : items * size;
  return static_cast< T * >(AllocateAlignedBytes(bytes, alloc_ptr, opaque_ptr));
}
void FreeAlignedBytes(void *, FreePtr, void *) {}
struct AlignedFreer {
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
AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items, void *opaque) {
  T *__trans_tmp_34 = AllocateAlignedItems< T >(items);
  return AlignedFreeUniquePtr< T[] >(
      __trans_tmp_34, AlignedFreer(AllocateAligned_free, opaque));
}
template < typename T >
AlignedFreeUniquePtr< T[] > AllocateAligned(size_t items) {
  return AllocateAligned< T >(items, nullptr);
}
TypeInfo MakeTypeInfo() {
  TypeInfo info;
  info.sizeof_t = sizeof(double);
  MakeTypeInfo___trans_tmp_36 = true;
  info.is_float = MakeTypeInfo___trans_tmp_36;
  return info;
}
template < class V > using VecArg = V;
template < typename Lane > struct Simd {
  using T = Lane;
  static constexpr long kPrivateLanes = 1;
  template < typename NewT > using Rebind = Simd< NewT >;
};
template < typename, long, int > using CappedTag = Simd< double >;
template < typename T > using Full64 = Simd< T >;
template < class D > using TFromD = typename D::T;
long Lanes() { return Simd< double >::kPrivateLanes; }
template < class T, class D > using Rebind = typename D::template Rebind< T >;
template < class D > using RebindToSigned = Rebind< MakeSigned< D >, D >;
template < class D > using RebindToUnsigned = Rebind< MakeUnsigned< D >, D >;
template < typename > struct Raw128 {
  using type = uint8x8_t;
};
template <> struct Raw128< unsigned long > {
  using type = uint64x1_t;
};
template <> struct Raw128< __int64_t > {
  using type = int64x1_t;
};
template <> struct Raw128< double > {
  using type = float64x1_t;
};
template < typename T, unsigned long > struct Vec128 {
  using Raw = typename Raw128< T >::type;
  using PrivateT = T;
  Vec128();
  Vec128(Raw raw) : raw(raw) {}
  Raw raw;
};
template < typename T > using Vec64 = Vec128< T, 8 / sizeof(T) >;
template < long > struct Mask128 {
  Mask128(Raw128< MakeUnsigned< int > >::type raw) : raw(raw) {}
  Raw128< MakeUnsigned< int > >::type raw;
};
template < class V > using DFromV = Simd< typename V::PrivateT >;
Vec128< __int64_t, 1 > NativeSet(Simd< __int64_t >, __int64_t t) {
  __int64_t __a = t;
  NativeSet___trans_tmp_3 = (int64x1_t)__a;
  return NativeSet___trans_tmp_3;
}
Vec128< unsigned long, 1 > NativeSet(Simd< unsigned long >, long t) {
  long __a = t;
  NativeSet___trans_tmp_4 = (uint64x1_t)__a;
  return NativeSet___trans_tmp_4;
}
Vec128< double, 1 > NativeSet(Simd< double >, double) {
  float64x1_t __trans_tmp_5{};
  return __trans_tmp_5;
}
template < class D, typename T > Vec128< TFromD< D >, 1 > Set(D, T t) {
  Full64< TFromD< D > > dfull;
  return NativeSet(dfull, t);
}
template < class D > using VFromD = decltype(Set(D(), D()));
template < class D > VFromD< D > Zero(D d) { return Set(d, TFromD< D >{}); }
VFromD< Simd< long > > Iota0(Simd< long > d) { return Zero(d); }
Vec128< unsigned char, 8 > BitCastToByte(Vec128< double, 1 > v) {
  return vreinterpret_u8_f64(v.raw);
}
Vec128< unsigned char, 8 > BitCastToByte(Vec128< unsigned long, 1 > v) {
  return vreinterpret_u8_u64(v.raw);
}
Vec64< __int64_t > BitCastFromByte(Simd< long >, Vec64< unsigned char > v) {
  return vreinterpret_s64_u8(v.raw);
}
template < class D >
Vec64< double > BitCastFromByte(D, Vec64< unsigned char > v) {
  return vreinterpret_f64_u8(v.raw);
}
template < class D, class FromT >
VFromD< D > BitCast(D d, Vec128< FromT, 1 > v) {
  Vec128 __trans_tmp_16 = BitCastToByte(v);
  return BitCastFromByte(d, __trans_tmp_16);
}
Vec128< __int64_t, 1 > operator+(Vec128< __int64_t, 1 > a,
                                 Vec128< __int64_t, 1 > b) {
  return a.raw + b.raw;
}
template < unsigned long N > Mask128< 1 > MaskFromVec(Vec128< double, N >);
template < class D > using MFromD = decltype(MaskFromVec(VFromD< D >()));
Simd< double > VecFromMask_d;
VFromD< Simd< double > > VecFromMask(MFromD< Simd< double > > m) {
  RebindToUnsigned< Simd< double > > du;
  return BitCast(VecFromMask_d, VFromD< decltype(du) >(m.raw));
}
template < long NFrom, class DTo >
MFromD< DTo > RebindMask(Mask128< NFrom > m) {
  m;
}
Mask128< 1 > operator==(Vec128< double, 1 >, Vec128< double, 1 >) {
  uint64x1_t __trans_tmp_7 = vceq_f64___a == vceq_f64___b;
  return __trans_tmp_7;
}
Mask128< 1 > operator==(Vec128< __int64_t, 1 > a, Vec128< __int64_t, 1 > b) {
  uint64x1_t __trans_tmp_9;
  int64x1_t __a = a.raw, __b = b.raw;
  __trans_tmp_9 = __a == __b;
  return __trans_tmp_9;
}
Mask128< 1 > operator<(Vec128< __int64_t, 1 >, Vec128< __int64_t, 1 > b) {
  uint64x1_t __trans_tmp_11;
  int64x1_t __b = b.raw;
  __trans_tmp_11 = vclt_s64___a < __b;
  return __trans_tmp_11;
}
Simd< double > FirstN_d;
MFromD< Simd< double > > FirstN(long num) {
  RebindToSigned< decltype(FirstN_d) > di;
  Vec128 __trans_tmp_18 = Iota0(di);
  Vec128 __trans_tmp_19 = Set(di, num);
  Mask128 __trans_tmp_17 = __trans_tmp_18 < __trans_tmp_19;
  return __trans_tmp_17;
}
void StoreU(Vec64< double > v, double *p) { vst1_f64(p, v.raw); }
void Store(VFromD< Simd< double > > v, TFromD< Simd< double > > *aligned) {
  StoreU(v, aligned);
}
template < unsigned long N > Mask128< 1 > IsInf(Vec128< double, N > v) {
  DFromV< decltype(v) > d;
  RebindToSigned< decltype(d) > di;
  VFromD< decltype(di) > vi = BitCast(di, v);
  IsInf___trans_tmp_13 = -(MakeSigned< double >{1} << 1);
  double __trans_tmp_2 = IsInf___trans_tmp_13;
  Vec128 __trans_tmp_20 = Add(vi, vi);
  return Eq(__trans_tmp_20, Set(di, __trans_tmp_2));
}
template < class D > using Vec = decltype(Zero(D()));
template < class D > using Mask = decltype(MaskFromVec(Zero(D())));
Simd< double > Inf_d;
Vec< Simd< double > > Inf() {
  RebindToUnsigned< Simd< double > > du;
  Inf___trans_tmp_12 = -MakeSigned< TFromD< Simd< double > > >{1};
  TFromD< decltype(du) > max_x2(Inf___trans_tmp_12);
  Vec128 __trans_tmp_22 = Set(du, max_x2 >> 1);
  return BitCast(Inf_d, __trans_tmp_22);
}
Vec128< long, 1 > Add(Vec128< long, 1 > a, Vec128< long, 1 > b) {
  return a + b;
}
template < class V > auto Eq(V a, V b) { return a == b; }
auto Lt(Vec128< long, 1 > a, Vec128< long, 1 > b) { return a < b; }
void AssertVecEqual(Vec< Simd< double > > expected,
                    Vec< Simd< double > > actual) {
  long N(Simd< double >::kPrivateLanes);
  auto expected_lanes = AllocateAligned< double >(1),
       actual_lanes = AllocateAligned< double >(1);
  double *__trans_tmp_23 = expected_lanes.get(),
         *__trans_tmp_24 = actual_lanes.get();
  Store(expected, __trans_tmp_23);
  Store(actual, __trans_tmp_24);
  auto info = MakeTypeInfo();
  double __trans_tmp_25 = *expected_lanes.get(),
         __trans_tmp_26 = *actual_lanes.get();
  AssertArrayEqual(info, &__trans_tmp_25, &__trans_tmp_26, N);
}
void AssertMaskEqual(VecArg< Mask< Simd< double > > > a,
                     VecArg< Mask< Simd< double > > > b) {
  Vec< Simd< double > > va = VecFromMask(a), vb = VecFromMask(b);
  AssertVecEqual(va, vb);
}
Mask< Simd< double > > MaskTrue() {
  long __trans_tmp_29(Simd< double >::kPrivateLanes);
  return FirstN(__trans_tmp_29);
}
template < int, int kMinArg, class Test, int kPow2 > struct ForeachCappedR {
  static void Do(long, long) {
    CappedTag< int, kMinArg, kPow2 > d;
    Test()(int(), d);
  }
};
struct TestIsInf {
  void operator()(double, Simd< double > d) {
    Vec< Simd< double > > v1 = Set(d, 0), neg = Set(d, double{});
    Vec128 __trans_tmp_30 = Set(d, double{});
    Vec128 __trans_tmp_31 = Inf();
    Eq(v1, __trans_tmp_30);
    Vec< Simd< double > > inf(__trans_tmp_31);
    Mask128 __trans_tmp_32 = MaskTrue();
    Mask128 __trans_tmp_33 = IsInf(inf);
    AssertMaskEqual(__trans_tmp_32, __trans_tmp_33);
    (void)(neg);
  }
};
template < int kPow2 = 1 > struct ForExtendableVectors {
  template < typename T > void operator()(T) {
    constexpr long kMaxCapped(sizeof(T));
    long max_lanes = kPow2;
    constexpr long kMul = kMaxCapped;
    constexpr long kMinArg{};
    ForeachCappedR< kMul, kMinArg, TestIsInf, kPow2 >::Do(1, max_lanes);
  }
};
struct {
  void operator()(double t) { ForExtendableVectors()(t); }
} ForFloat64Types_func;
int main() { ForFloat64Types_func(double()); }

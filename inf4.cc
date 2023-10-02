#include <cstring>
#include <cmath>
#include <iostream>
namespace hwy {
namespace detail {
struct TypeInfo {
  long sizeof_t;
  bool is_float;
};
void AssertArrayEqual(const TypeInfo &ti, const void *a, const void *b,
                      unsigned long c, const char *, const char *, int) {
  if (memcmp(a, b, c * ti.sizeof_t) != 0) {
	  if( ti.sizeof_t == 8  && ti.is_float && c == 1 ) {
		  double da, db;
		  memcpy(&da, a, sizeof da);
		  memcpy(&db, b, sizeof db);
		  volatile bool sba = std::signbit( da ); (void)sba;
		  volatile bool ina = std::isnan( da ); (void)ina;
		  volatile bool zero = db == 0.0; (void)zero;
		  if( sba && ina && zero ) {
static const char msg[] =  "NEON_WITHOUT_AES, f64x1 lane 0 mismatch: expected '-nan', got '0.000000000000000000'.";
std::cout << msg << std::endl;
    abort();
		  }
	  }
  }
}
} 
} 
namespace hwy {
	using AllocPtr = void *(void *, size_t);
	using FreePtr = void (*)(void *, void *);
	void *AllocateAlignedBytes(size_t s, AllocPtr, void *) {
		  void *memptr = NULL;
		    int ret = posix_memalign(&memptr, 64, s);
		      if (ret != 0)
			          abort();
		        return memptr;
	}
	
} 
typedef long __int64_t;
template <int __v> struct integral_constant {
  static constexpr int value = __v;
};
template <bool, typename _Tp> using __enable_if_t = _Tp;
template <unsigned long, typename> struct tuple_element;
template <long __i, typename _Tp>
using __tuple_element_t = typename tuple_element<__i, _Tp>::type;
template <long, typename...> struct _Nth_type;
template <typename _Tp0, typename... _Rest>
struct _Nth_type<0, _Tp0, _Rest...> {
  using type = _Tp0;
};
template <typename...> class tuple;
template <typename _Head> struct _Head_base {
  template <typename _UHead> _Head_base(_UHead __h) : _M_head_impl(__h) {}
  static _Head _M_head(_Head_base &__b) { return __b._M_head_impl; }
  _Head _M_head_impl;
};
template <unsigned long, typename...> struct _Tuple_impl;
template <unsigned long _Idx, typename _Head, typename... _Tail>
struct _Tuple_impl<_Idx, _Head, _Tail...> : _Tuple_impl<1, _Tail...>,
                                            _Head_base<_Head> {
  template <typename _UHead, typename... _UTail>
  _Tuple_impl(_UHead __head, _UTail... __tail)
      : _Tuple_impl<1, _Tail...>(__tail...), _Head_base<_Head>(__head) {}
};
template <unsigned long _Idx, typename _Head>
struct _Tuple_impl<_Idx, _Head> : _Head_base<_Head> {
  template <typename _UHead>
  _Tuple_impl(_UHead __head) : _Head_base<_Head>(__head) {}
};
template <typename _T1, typename _T2>
struct tuple<_T1, _T2> : _Tuple_impl<0, _T1, _T2> {
  template <typename _U1, typename _U2>
  tuple(_U1 __a1, _U2 __a2) : _Tuple_impl<0, _T1, _T2>(__a1, __a2) {}
};
template <unsigned long __i, typename... _Types>
struct tuple_element<__i, tuple<_Types...>> {
  using type = typename _Nth_type<__i, _Types...>::type;
};
template <unsigned long __i, typename _Head, typename... _Tail>
_Head __get_helper(_Tuple_impl<__i, _Head, _Tail...> &__t) {
  return _Tuple_impl<__i, _Head>::_M_head(__t);
}
template <int __i, typename... _Elements>
__tuple_element_t<__i, tuple<_Elements...>> get(tuple<_Elements...> __t) {
  return __get_helper(__t);
}
template <int> void CopyBytes(unsigned long *, unsigned char *) {}
template <typename> using MakeUnsigned = unsigned long;
template <typename> using MakeSigned = long;
template <typename> void IsFloat3264();
#pragma GCC aarch64 "arm_neon.h"
typedef __Int64x1_t int64x1_t;
typedef __Uint8x8_t uint8x8_t;
typedef __Float64x1_t float64x1_t;
typedef __Uint64x1_t uint64x1_t;
float64x1_t vceq_f64___a, vceq_f64___b;
int64x1_t vclt_s64___a, NativeSet___trans_tmp_3;
void vst1_f64(double *__a, float64x1_t __b) { *__a = __b[0]; }
template <typename _Tp, typename _Dp> struct __uniq_ptr_impl {
  template <typename _Up> struct _Ptr {
    using type = _Up *;
  };
  using pointer = typename _Ptr<_Tp>::type;
  template <typename _Del>
  __uniq_ptr_impl(pointer __p, _Del __d) : _M_t(__p, __d) {}
  pointer _M_ptr() { return get<0>(_M_t); }
  tuple<pointer, _Dp> _M_t;
};
template <typename _Tp, typename _Dp>
struct __uniq_ptr_data : __uniq_ptr_impl<_Tp, _Dp> {
  using __uniq_ptr_impl<_Tp, _Dp>::__uniq_ptr_impl;
};
template <typename, typename> class unique_ptr;
template <typename _Tp, typename _Dp> struct unique_ptr<_Tp[], _Dp> {
  __uniq_ptr_data<_Tp, _Dp> _M_t;
  template <typename _Up, typename _Del>
  unique_ptr(_Up __p, __enable_if_t<integral_constant<false>::value, _Del> __d)
      : _M_t(__p, __d) {}
  typename __uniq_ptr_impl<_Tp, _Dp>::pointer get() { return _M_t._M_ptr(); }
};
uint64x1_t NativeSet___trans_tmp_4;
double IsInf___trans_tmp_13;
unsigned long StoreMaskBits_mask_bits;
MakeSigned<double> Inf___trans_tmp_12;
bool MakeTypeInfo___trans_tmp_36;
namespace hwy {
using AllocPtr = void *(void *, unsigned long);
void *AllocateAlignedBytes(unsigned long, AllocPtr, void *);
namespace detail {
AllocPtr *AllocateAlignedItems_alloc_ptr;
void *AllocateAlignedItems_opaque_ptr;
template <typename T> T *AllocateAlignedItems() {
  long size = sizeof(T), bytes = size;
  return static_cast<T *>(AllocateAlignedBytes(
      bytes, AllocateAlignedItems_alloc_ptr, AllocateAlignedItems_opaque_ptr));
}
} 
struct AlignedFreer {
  AlignedFreer(void *) {}
};
template <typename T> using AlignedFreeUniquePtr = unique_ptr<T, AlignedFreer>;
void *AllocateAligned_opaque;
template <typename T> AlignedFreeUniquePtr<T[]> AllocateAligned() {
  return AlignedFreeUniquePtr<T[]>(detail::AllocateAlignedItems<T>(),
                                   AllocateAligned_opaque);
}
AlignedFreeUniquePtr<int[]> AllocateAligned(long) {
  return AllocateAligned<int>();
}
namespace detail {
template <typename T> TypeInfo MakeTypeInfo() {
  TypeInfo info;
  info.sizeof_t = sizeof(T);
  MakeTypeInfo___trans_tmp_36 = 0 || IsFloat3264<T>;
  info.is_float = MakeTypeInfo___trans_tmp_36;
  return info;
}
void AssertArrayEqual(const TypeInfo &, const void *, const void *,
                      unsigned long, const char *, const char *, int);
} 
template <class V> using VecArg = V;
template <typename Lane> struct Simd {
  using T = Lane;
  static constexpr long kPrivateLanes = 1;
  template <typename NewT> using Rebind = Simd<NewT>;
  template <typename> using Repartition = Simd;
};
template <typename, long, int> using CappedTag = Simd<double>;
template <typename T> using Full64 = Simd<T>;
template <class D> using TFromD = typename D::T;
long Lanes(Simd<double>) { return Simd<double>::kPrivateLanes; }
template <class T, class D> using Rebind = typename D::Rebind<T>;
template <class D> using RebindToSigned = Rebind<MakeSigned<D>, D>;
template <class D> using RebindToUnsigned = Rebind<MakeUnsigned<D>, D>;
template <class T, class D> using Repartition = typename D::Repartition<T>;
template <typename> struct Raw128 {
  using type = uint8x8_t;
};
template <> struct Raw128<unsigned long> {
  using type = uint64x1_t;
};
template <> struct Raw128<__int64_t> {
  using type = int64x1_t;
};
template <> struct Raw128<double> {
  using type = float64x1_t;
};
template <typename T, unsigned long> struct Vec128 {
  using Raw = typename Raw128<T>::type;
  using PrivateT = T;
  Vec128();
  Vec128(Raw raw) : raw(raw) {}
  Raw raw;
};
template <typename T> using Vec64 = Vec128<T, 8 / sizeof(T)>;
template <unsigned long> struct Mask128 {
  Mask128(Raw128<MakeUnsigned<int>>::type raw) : raw(raw) {}
  Raw128<MakeUnsigned<int>>::type raw;
};
template <class V> using DFromV = Simd<typename V::PrivateT>;
Vec128<__int64_t, 1> NativeSet(Simd<__int64_t>, __int64_t t) {
  __int64_t __a = t;
  NativeSet___trans_tmp_3 = (int64x1_t)__a;
  return NativeSet___trans_tmp_3;
}
Vec128<unsigned long, 1> NativeSet(Simd<unsigned long>, long t) {
  long __a = t;
  NativeSet___trans_tmp_4 = (uint64x1_t)__a;
  return NativeSet___trans_tmp_4;
}
Vec128<double, 1> NativeSet(Simd<double>, double) {
  float64x1_t __trans_tmp_5{};
  return __trans_tmp_5;
}
template <class D, typename T> Vec128<TFromD<D>, 1> Set(D, T t) {
  Full64<TFromD<D>> dfull;
  return NativeSet(dfull, t);
}
template <class D> using VFromD = decltype(Set(D(), D()));
template <class D> VFromD<D> Zero(D d) { return Set(d, TFromD<D>{}); }
VFromD<Simd<long>> Iota0(Simd<long> d) { return Zero(d); }
Vec128<unsigned char, 8> BitCastToByte(Vec128<double, 1> v) {
  return vreinterpret_u8_f64(v.raw);
}
Vec128<unsigned char, 8> BitCastToByte(Vec128<unsigned long, 1> v) {
  return vreinterpret_u8_u64(v.raw);
}
Vec64<__int64_t> BitCastFromByte(Simd<long>, Vec64<unsigned char> v) {
  return vreinterpret_s64_u8(v.raw);
}
template <class D> Vec64<double> BitCastFromByte(D, Vec64<unsigned char> v) {
  return vreinterpret_f64_u8(v.raw);
}
template <class D, class FromT> VFromD<D> BitCast(D d, Vec128<FromT, 1> v) {
  Vec128 __trans_tmp_16 = BitCastToByte(v);
  return BitCastFromByte(d, __trans_tmp_16);
}
Vec128<__int64_t, 1> operator+(Vec128<__int64_t, 1> a, Vec128<__int64_t, 1> b) {
  return a.raw + b.raw;
}
template <unsigned long N> Mask128<1> MaskFromVec(Vec128<double, N>);
template <class D> using MFromD = decltype(MaskFromVec(VFromD<D>()));
Simd<double> VecFromMask_d;
VFromD<Simd<double>> VecFromMask(MFromD<Simd<double>> m) {
  RebindToUnsigned<Simd<double>> du;
  return BitCast(VecFromMask_d, VFromD<decltype(du)>(m.raw));
}
template <unsigned long NFrom, class DTo>
MFromD<DTo> RebindMask(DTo, Mask128<NFrom> m) {
  return m;
}
Mask128<1> operator==(Vec128<double, 1>, Vec128<double, 1>) {
  uint64x1_t __trans_tmp_7 = vceq_f64___a == vceq_f64___b;
  return __trans_tmp_7;
}
Mask128<1> operator==(Vec128<__int64_t, 1> a, Vec128<__int64_t, 1> b) {
  uint64x1_t __trans_tmp_9;
  int64x1_t __a = a.raw, __b = b.raw;
  __trans_tmp_9 = __a == __b;
  return __trans_tmp_9;
}
Mask128<1> operator<(Vec128<__int64_t, 1>, Vec128<__int64_t, 1> b) {
  uint64x1_t __trans_tmp_11;
  int64x1_t __b = b.raw;
  __trans_tmp_11 = vclt_s64___a < __b;
  return __trans_tmp_11;
}
Simd<double> FirstN_d;
MFromD<Simd<double>> FirstN(long num) {
  RebindToSigned<decltype(FirstN_d)> di;
  Vec128 __trans_tmp_18 = Iota0(di);
  Vec128 __trans_tmp_19 = Set(di, num);
  Mask128 __trans_tmp_17 = __trans_tmp_18 < __trans_tmp_19;
  return __trans_tmp_17;
}
void StoreU(Vec64<double> v, double *p) { vst1_f64(p, v.raw); }
void Store(VFromD<Simd<double>> v, TFromD<Simd<double>> *aligned) {
  StoreU(v, aligned);
}
template <unsigned long N> Mask128<1> IsInf(Vec128<double, N> v) {
  DFromV<decltype(v)> d;
  RebindToSigned<decltype(d)> di;
  VFromD<decltype(di)> vi = BitCast(di, v);
  IsInf___trans_tmp_13 = -(MakeSigned<double>{1} << 1);
  double __trans_tmp_2 = IsInf___trans_tmp_13;
  Vec128 __trans_tmp_20 = Add(vi, vi);
  return Eq(__trans_tmp_20, Set(di, __trans_tmp_2));
}
template <class D> using Vec = decltype(Zero(D()));
template <class D> using Mask = decltype(MaskFromVec(Zero(D())));
Simd<double> Inf_d;
Vec<Simd<double>> Inf() {
  RebindToUnsigned<Simd<double>> du;
  Inf___trans_tmp_12 = -MakeSigned<TFromD<Simd<double>>>{1};
  TFromD<decltype(du)> max_x2(Inf___trans_tmp_12);
  Vec128 __trans_tmp_22 = Set(du, max_x2 >> 1);
  return BitCast(Inf_d, __trans_tmp_22);
}
Vec128<long, 1> Add(Vec128<long, 1> a, Vec128<long, 1> b) { return a + b; }
template <class V> auto Eq(V a, V b) { return a == b; }
auto Lt(Vec128<long, 1> a, Vec128<long, 1> b) { return a < b; }
char AssertVecEqual_filename;
int AssertVecEqual_line;
void AssertVecEqual(Vec<Simd<double>> expected, Vec<Simd<double>> actual) {
  long N(Simd<double>::kPrivateLanes);
  auto expected_lanes = AllocateAligned<double>(),
       actual_lanes = AllocateAligned<double>();
  double *__trans_tmp_23 = expected_lanes.get(),
         *__trans_tmp_24 = actual_lanes.get();
  Store(expected, __trans_tmp_23);
  Store(actual, __trans_tmp_24);
  auto info = detail::MakeTypeInfo<double>();
  double __trans_tmp_25 = *expected_lanes.get(),
         __trans_tmp_26 = *actual_lanes.get();
  AssertArrayEqual(info, &__trans_tmp_25, &__trans_tmp_26, N,
                   "NEON_WITHOUT_AES", &AssertVecEqual_filename,
                   AssertVecEqual_line);
}
void AssertMaskEqual(VecArg<Mask<Simd<double>>> a,
                     VecArg<Mask<Simd<double>>> b) {
  Vec<Simd<double>> va = VecFromMask(a), vb = VecFromMask(b);
  AssertVecEqual(va, vb);
  Repartition<char, Simd<double>> d8;
  long N8 = Lanes(d8);
  auto bits_a = AllocateAligned<char>();
  auto bits_b = AllocateAligned(N8);
  char __trans_tmp_27 = *bits_a.get(), __trans_tmp_28 = *bits_b.get();
  unsigned char bits = __trans_tmp_27;
  bits = __trans_tmp_28;
  CopyBytes<8>(&StoreMaskBits_mask_bits, &bits);
}
Mask<Simd<double>> MaskTrue() {
  long __trans_tmp_29(Simd<double>::kPrivateLanes);
  return FirstN(__trans_tmp_29);
}
Mask<Simd<double>> MaskFalse() {
  Simd<double> d;
  RebindToSigned<Simd<double>> di;
  Vec<decltype(di)> zero = Zero(di);
  return RebindMask(d, Lt(zero, zero));
}
template <int, int kMinArg, class Test, int kPow2> struct ForeachCappedR {
  static void Do(long, long) {
    CappedTag<int, kMinArg, kPow2> d;
    Test()(int(), d);
  }
};
struct TestIsInf {
  void operator()(double, Simd<double> d) {
    Vec<Simd<double>> v1 = Set(d, 0), neg = Set(d, double{});
    Vec128 __trans_tmp_30 = Set(d, double{});
    Vec128 __trans_tmp_31 = Inf();
    Eq(v1, __trans_tmp_30);
    Vec<Simd<double>> inf(__trans_tmp_31);
    Mask128 __trans_tmp_32 = MaskTrue();
    Mask128 __trans_tmp_33 = IsInf(inf);
    AssertMaskEqual(__trans_tmp_32, __trans_tmp_33);
    (MaskFalse(), neg);
  }
};
template <int kPow2 = 1> struct ForExtendableVectors {
  template <typename T> void operator()(T) {
    constexpr long kMaxCapped(sizeof(T));
    long max_lanes = kPow2;
    constexpr long kMul = kMaxCapped;
    constexpr long kMinArg{};
    ForeachCappedR<kMul, kMinArg, TestIsInf, kPow2>::Do(1, max_lanes);
  }
};
struct {
  void operator()(double t) { ForExtendableVectors()(t); }
} ForFloat64Types_func;
void TestAllIsInf() { ForFloat64Types_func(double()); }
} 
int main() { hwy::TestAllIsInf(); }

#include <cstring>
#include <cstdlib>
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
struct _Head_base {
  template <typename _UHead> _Head_base(_UHead) {}
  int _M_head_impl;
};
template <unsigned long, typename...> struct _Tuple_impl;
template <unsigned long _Idx, typename _Head, typename... _Tail>
struct _Tuple_impl<_Idx, _Head, _Tail...> : _Tuple_impl<1, _Tail...> {
  template <typename _UHead, typename... _UTail>
  _Tuple_impl(_UHead, _UTail... __tail) : _Tuple_impl<1, _Tail...>(__tail...) {}
};
template <unsigned long _Idx, typename _Head>
struct _Tuple_impl<_Idx, _Head> : _Head_base {
  template <typename _UHead> _Tuple_impl(_UHead __head) : _Head_base(__head) {}
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
template <int __i, typename... _Elements>
__tuple_element_t<__i, tuple<_Elements...>> get(tuple<_Elements...>) {
  double __trans_tmp_23{};
  double *__trans_tmp_21 = &__trans_tmp_23;
  return __trans_tmp_21;
}
template <typename> using MakeUnsigned = unsigned long;
template <typename> using MakeSigned = long;
#pragma GCC aarch64 "arm_neon.h"
typedef __Int64x1_t int64x1_t;
typedef __Uint8x8_t uint8x8_t;
typedef __Float64x1_t float64x1_t;
typedef __Uint64x1_t uint64x1_t;
int64x1_t vclt_s64___a, NativeSet___trans_tmp_2;
void vst1_f64(double *__a, float64x1_t __b) { *__a = __b[0]; }
struct __uniq_ptr_impl {
  __uniq_ptr_impl(double *__p, int __d) : _M_t(__p, __d) {}
  double *_M_ptr() { return get<0>(_M_t); }
  tuple<double *, int> _M_t;
};
struct __uniq_ptr_data : __uniq_ptr_impl {
  using __uniq_ptr_impl::__uniq_ptr_impl;
};
double unique_ptr___p;
__enable_if_t<integral_constant<false>::value, int> unique_ptr___d;
struct unique_ptr {
  __uniq_ptr_data _M_t;
  unique_ptr() : _M_t(&unique_ptr___p, unique_ptr___d) {}
  double *get() { return _M_t._M_ptr(); }
};
namespace hwy {
template <typename> using AlignedFreeUniquePtr = unique_ptr;
namespace detail {
struct TypeInfo {
  long sizeof_t;
};
TypeInfo MakeTypeInfo() {
  TypeInfo info;
  info.sizeof_t = sizeof(double);
  return info;
}
//void AssertArrayEqual(const TypeInfo &, const void *, const void *, unsigned long, const char *, const char *, int);
//[[gnu::noipa]]
		void AssertArrayEqual(const TypeInfo &ti, const void *a, const void *b, unsigned long c,
				                                      const char *, const char *, int) { if( memcmp(a, b, c * ti.sizeof_t) != 0 ) abort(); }

} // namespace detail
template <class V> using VecArg = V;
template <typename Lane> struct Simd {
  using T = Lane;
  static constexpr long kPrivateLanes = 0 >= 0;
  template <typename NewT> using Rebind = Simd<NewT>;
};
template <typename, long, int> using CappedTag = Simd<double>;
template <class D> using TFromD = typename D::T;
template <class T, class D> using Rebind = typename D::Rebind<T>;
template <class D> using RebindToSigned = Rebind<MakeSigned<D>, D>;
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
  Vec128();
  Vec128(Raw raw) : raw(raw) {}
  Raw raw;
};
template <typename T> using Vec64 = Vec128<T, 8 / sizeof(T)>;
struct Mask128 {
  Mask128(Raw128<MakeUnsigned<int>>::type raw) : raw(raw) {}
  Raw128<MakeUnsigned<int>>::type raw;
};
Vec128<__int64_t, 1> NativeSet(__int64_t t) {
  NativeSet___trans_tmp_2 = (int64x1_t)t;
  return NativeSet___trans_tmp_2;
}
template <class D, typename T> Vec128<TFromD<D>, 1> Set(D, T t) {
  return NativeSet(t);
}
template <class D> using VFromD = decltype(Set(D(), D()));
template <class D> VFromD<D> Zero(D d) { return Set(d, TFromD<D>{}); }
VFromD<Simd<long>> Iota0(Simd<long> d) { return Zero(d); }
Vec128<unsigned char, 8> BitCastToByte(Vec128<unsigned long, 1> v) {
  return vreinterpret_u8_u64(v.raw);
}
Vec64<double> BitCastFromByte(Simd<double>, Vec64<unsigned char> v) {
  return vreinterpret_f64_u8(v.raw);
}
VFromD<Simd<double>> BitCast(Vec128<unsigned long, 1> v) {
  Simd<double> d;
  Vec128 __trans_tmp_10 = BitCastToByte(v);
  return BitCastFromByte(d, __trans_tmp_10);
}
template <unsigned long N> Mask128 MaskFromVec(Vec128<double, N>);
template <class D> using MFromD = decltype(MaskFromVec(VFromD<D>()));
VFromD<Simd<double>> VecFromMask(MFromD<Simd<double>> m) {
  return BitCast(m.raw);
}
Mask128 operator<(Vec128<__int64_t, 1>, Vec128<__int64_t, 1> b) {
  uint64x1_t __trans_tmp_7 = vclt_s64___a < b.raw;
  return __trans_tmp_7;
}
Simd<double> FirstN_d;
MFromD<Simd<double>> FirstN(unsigned num) {
  RebindToSigned<decltype(FirstN_d)> di;
  Vec128 __trans_tmp_12 = Iota0(di);
  Vec128 __trans_tmp_13 = Set(di, num);
  Mask128 __trans_tmp_11 = __trans_tmp_12 < __trans_tmp_13;
  return __trans_tmp_11;
}
void StoreU(Vec64<double> v, double *p) { vst1_f64(p, v.raw); }
void Store(VFromD<Simd<double>> v, TFromD<Simd<double>> *aligned) {
  StoreU(v, aligned);
}
template <class D> using Vec = decltype(Zero(D()));
template <class D> using Mask = decltype(MaskFromVec(Zero(D())));
char AssertVecEqual_filename;
int AssertVecEqual_line;
AlignedFreeUniquePtr<double> __trans_tmp_27;
void AssertVecEqual(Vec<Simd<double>> expected) {
  AlignedFreeUniquePtr<double> __trans_tmp_25{}, expected_lanes = __trans_tmp_27,
                                               actual_lanes = __trans_tmp_25;
  double *__trans_tmp_15 = expected_lanes.get();
  Store(expected, __trans_tmp_15);
  auto info = detail::MakeTypeInfo();
  double __trans_tmp_17 = *expected_lanes.get(),
         __trans_tmp_20 = *actual_lanes.get();
  AssertArrayEqual(info, &__trans_tmp_17, &__trans_tmp_20,
                   Simd<double>::kPrivateLanes, "NEON_WITHOUT_AES",
                   &AssertVecEqual_filename, AssertVecEqual_line);
}
void AssertMaskEqual(VecArg<Mask<Simd<double>>> a) {
  Vec<Simd<double>> va = VecFromMask(a);
  AssertVecEqual(va);
}
Mask<Simd<double>> MaskTrue() { return FirstN(Simd<double>::kPrivateLanes); }
struct TestIsInf {
  void operator()(double, Simd<double>) {
    Mask128 __trans_tmp_18 = MaskTrue();
    AssertMaskEqual(__trans_tmp_18);
  }
};
template <int kPow2> struct ForExtendableVectors {
  template <typename T> void operator()(T) {
    constexpr long kMinArg{};
    CappedTag<T, kMinArg, kPow2> d;
    TestIsInf()(T(), d);
  }
};
struct {
  void operator()(double t) { ForExtendableVectors<0>()(t); }
} ForFloat64Types_func;
void TestAllIsInf() { ForFloat64Types_func(double()); }
} // namespace hwy
int main() { hwy::TestAllIsInf(); }

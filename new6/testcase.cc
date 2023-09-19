typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
  __float128 __max_align_f128 __attribute__((__aligned__(__alignof(__float128))));
} max_align_t;
  typedef decltype(nullptr) nullptr_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
__extension__ typedef long long int __intmax_t;
__extension__ typedef unsigned long long int __uintmax_t;
__extension__ typedef __uint64_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __uint64_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __int64_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __uint64_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;
__extension__ typedef __int64_t __suseconds64_t;
__extension__ typedef int __daddr_t;
__extension__ typedef int __key_t;
__extension__ typedef int __clockid_t;
__extension__ typedef void * __timer_t;
__extension__ typedef long int __blksize_t;
__extension__ typedef long int __blkcnt_t;
__extension__ typedef __int64_t __blkcnt64_t;
__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __uint64_t __fsblkcnt64_t;
__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __uint64_t __fsfilcnt64_t;
__extension__ typedef int __fsword_t;
__extension__ typedef int __ssize_t;
__extension__ typedef long int __syscall_slong_t;
__extension__ typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
__extension__ typedef int __intptr_t;
__extension__ typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
__extension__ typedef __int64_t __time64_t;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__
typedef long long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__
typedef unsigned long long int uint_fast64_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
       
       
namespace std
{
  typedef unsigned int size_t;
  typedef int ptrdiff_t;
  typedef decltype(nullptr) nullptr_t;
#pragma GCC visibility push(default)
  extern "C++" __attribute__ ((__noreturn__, __always_inline__))
  inline void __terminate() noexcept
  {
    void terminate() noexcept __attribute__ ((__noreturn__));
    terminate();
  }
#pragma GCC visibility pop
}
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace std
{
#pragma GCC visibility push(default)
  constexpr inline bool
  __is_constant_evaluated() noexcept
  {
    return __builtin_is_constant_evaluated();
  }
#pragma GCC visibility pop
}
       
       
extern "C++" {
namespace std __attribute__ ((__visibility__ ("default")))
{
  class exception
  {
  public:
    exception() noexcept { }
    virtual ~exception() noexcept;
    exception(const exception&) = default;
    exception& operator=(const exception&) = default;
    exception(exception&&) = default;
    exception& operator=(exception&&) = default;
    virtual const char*
    what() const noexcept;
  };
}
}
#pragma GCC visibility push(default)
extern "C++" {
namespace std
{
  class bad_alloc : public exception
  {
  public:
    bad_alloc() throw() { }
    bad_alloc(const bad_alloc&) = default;
    bad_alloc& operator=(const bad_alloc&) = default;
    virtual ~bad_alloc() throw();
    virtual const char* what() const throw();
  };
  class bad_array_new_length : public bad_alloc
  {
  public:
    bad_array_new_length() throw() { }
    virtual ~bad_array_new_length() throw();
    virtual const char* what() const throw();
  };
  struct nothrow_t
  {
    explicit nothrow_t() = default;
  };
  extern const nothrow_t nothrow;
  typedef void (*new_handler)();
  new_handler set_new_handler(new_handler) throw();
  new_handler get_new_handler() noexcept;
}
 void* operator new(std::size_t)
  __attribute__((__externally_visible__));
 void* operator new[](std::size_t)
  __attribute__((__externally_visible__));
void operator delete(void*) noexcept
  __attribute__((__externally_visible__));
void operator delete[](void*) noexcept
  __attribute__((__externally_visible__));
 void* operator new(std::size_t, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__, __alloc_size__ (1), __malloc__));
 void* operator new[](std::size_t, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__, __alloc_size__ (1), __malloc__));
void operator delete(void*, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__));
void operator delete[](void*, const std::nothrow_t&) noexcept
  __attribute__((__externally_visible__));
 inline void* operator new(std::size_t, void* __p) noexcept
{ return __p; }
 inline void* operator new[](std::size_t, void* __p) noexcept
{ return __p; }
inline void operator delete (void*, void*) noexcept { }
inline void operator delete[](void*, void*) noexcept { }
}
#pragma GCC visibility pop
       
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp>
    class reference_wrapper;
  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
      static constexpr _Tp value = __v;
      typedef _Tp value_type;
      typedef integral_constant<_Tp, __v> type;
      constexpr operator value_type() const noexcept { return value; }
    };
  template<typename _Tp, _Tp __v>
    constexpr _Tp integral_constant<_Tp, __v>::value;
  using true_type = integral_constant<bool, true>;
  using false_type = integral_constant<bool, false>;
  template<bool __v>
    using __bool_constant = integral_constant<bool, __v>;
  template<bool, typename _Tp = void>
    struct enable_if
    { };
  template<typename _Tp>
    struct enable_if<true, _Tp>
    { typedef _Tp type; };
  template<bool _Cond, typename _Tp = void>
    using __enable_if_t = typename enable_if<_Cond, _Tp>::type;
  template<bool>
    struct __conditional
    {
      template<typename _Tp, typename>
 using type = _Tp;
    };
  template<>
    struct __conditional<false>
    {
      template<typename, typename _Up>
 using type = _Up;
    };
  template<bool _Cond, typename _If, typename _Else>
    using __conditional_t
      = typename __conditional<_Cond>::template type<_If, _Else>;
  template <typename _Type>
    struct __type_identity
    { using type = _Type; };
  template<typename _Tp>
    using __type_identity_t = typename __type_identity<_Tp>::type;
  namespace __detail
  {
    template<typename _Tp, typename...>
      using __first_t = _Tp;
    template<typename... _Bn>
      auto __or_fn(int) -> __first_t<false_type,
         __enable_if_t<!bool(_Bn::value)>...>;
    template<typename... _Bn>
      auto __or_fn(...) -> true_type;
    template<typename... _Bn>
      auto __and_fn(int) -> __first_t<true_type,
          __enable_if_t<bool(_Bn::value)>...>;
    template<typename... _Bn>
      auto __and_fn(...) -> false_type;
  }
  template<typename... _Bn>
    struct __or_
    : decltype(__detail::__or_fn<_Bn...>(0))
    { };
  template<typename... _Bn>
    struct __and_
    : decltype(__detail::__and_fn<_Bn...>(0))
    { };
  template<typename _Pp>
    struct __not_
    : __bool_constant<!bool(_Pp::value)>
    { };
  template<typename>
    struct is_reference;
  template<typename>
    struct is_function;
  template<typename>
    struct is_void;
  template<typename>
    struct remove_cv;
  template<typename>
    struct is_const;
  template<typename>
    struct __is_array_unknown_bounds;
  template <typename _Tp, size_t = sizeof(_Tp)>
    constexpr true_type __is_complete_or_unbounded(__type_identity<_Tp>)
    { return {}; }
  template <typename _TypeIdentity,
      typename _NestedType = typename _TypeIdentity::type>
    constexpr typename __or_<
      is_reference<_NestedType>,
      is_function<_NestedType>,
      is_void<_NestedType>,
      __is_array_unknown_bounds<_NestedType>
    >::type __is_complete_or_unbounded(_TypeIdentity)
    { return {}; }
  template<typename _Tp>
    using __remove_cv_t = typename remove_cv<_Tp>::type;
  template<typename _Tp>
    struct is_void
    : public false_type { };
  template<>
    struct is_void<void>
    : public true_type { };
  template<>
    struct is_void<const void>
    : public true_type { };
  template<>
    struct is_void<volatile void>
    : public true_type { };
  template<>
    struct is_void<const volatile void>
    : public true_type { };
  template<typename>
    struct __is_integral_helper
    : public false_type { };
  template<>
    struct __is_integral_helper<bool>
    : public true_type { };
  template<>
    struct __is_integral_helper<char>
    : public true_type { };
  template<>
    struct __is_integral_helper<signed char>
    : public true_type { };
  template<>
    struct __is_integral_helper<unsigned char>
    : public true_type { };
  template<>
    struct __is_integral_helper<wchar_t>
    : public true_type { };
  template<>
    struct __is_integral_helper<char16_t>
    : public true_type { };
  template<>
    struct __is_integral_helper<char32_t>
    : public true_type { };
  template<>
    struct __is_integral_helper<short>
    : public true_type { };
  template<>
    struct __is_integral_helper<unsigned short>
    : public true_type { };
  template<>
    struct __is_integral_helper<int>
    : public true_type { };
  template<>
    struct __is_integral_helper<unsigned int>
    : public true_type { };
  template<>
    struct __is_integral_helper<long>
    : public true_type { };
  template<>
    struct __is_integral_helper<unsigned long>
    : public true_type { };
  template<>
    struct __is_integral_helper<long long>
    : public true_type { };
  template<>
    struct __is_integral_helper<unsigned long long>
    : public true_type { };
  template<typename _Tp>
    struct is_integral
    : public __is_integral_helper<__remove_cv_t<_Tp>>::type
    { };
  template<typename>
    struct __is_floating_point_helper
    : public false_type { };
  template<>
    struct __is_floating_point_helper<float>
    : public true_type { };
  template<>
    struct __is_floating_point_helper<double>
    : public true_type { };
  template<>
    struct __is_floating_point_helper<long double>
    : public true_type { };
  template<typename _Tp>
    struct is_floating_point
    : public __is_floating_point_helper<__remove_cv_t<_Tp>>::type
    { };
  template<typename>
    struct is_array
    : public false_type { };
  template<typename _Tp, std::size_t _Size>
    struct is_array<_Tp[_Size]>
    : public true_type { };
  template<typename _Tp>
    struct is_array<_Tp[]>
    : public true_type { };
  template<typename>
    struct __is_pointer_helper
    : public false_type { };
  template<typename _Tp>
    struct __is_pointer_helper<_Tp*>
    : public true_type { };
  template<typename _Tp>
    struct is_pointer
    : public __is_pointer_helper<__remove_cv_t<_Tp>>::type
    { };
  template<typename>
    struct is_lvalue_reference
    : public false_type { };
  template<typename _Tp>
    struct is_lvalue_reference<_Tp&>
    : public true_type { };
  template<typename>
    struct is_rvalue_reference
    : public false_type { };
  template<typename _Tp>
    struct is_rvalue_reference<_Tp&&>
    : public true_type { };
  template<typename>
    struct __is_member_object_pointer_helper
    : public false_type { };
  template<typename _Tp, typename _Cp>
    struct __is_member_object_pointer_helper<_Tp _Cp::*>
    : public __not_<is_function<_Tp>>::type { };
  template<typename _Tp>
    struct is_member_object_pointer
    : public __is_member_object_pointer_helper<__remove_cv_t<_Tp>>::type
    { };
  template<typename>
    struct __is_member_function_pointer_helper
    : public false_type { };
  template<typename _Tp, typename _Cp>
    struct __is_member_function_pointer_helper<_Tp _Cp::*>
    : public is_function<_Tp>::type { };
  template<typename _Tp>
    struct is_member_function_pointer
    : public __is_member_function_pointer_helper<__remove_cv_t<_Tp>>::type
    { };
  template<typename _Tp>
    struct is_enum
    : public integral_constant<bool, __is_enum(_Tp)>
    { };
  template<typename _Tp>
    struct is_union
    : public integral_constant<bool, __is_union(_Tp)>
    { };
  template<typename _Tp>
    struct is_class
    : public integral_constant<bool, __is_class(_Tp)>
    { };
  template<typename _Tp>
    struct is_function
    : public __bool_constant<!is_const<const _Tp>::value> { };
  template<typename _Tp>
    struct is_function<_Tp&>
    : public false_type { };
  template<typename _Tp>
    struct is_function<_Tp&&>
    : public false_type { };
  template<typename _Tp>
    struct is_null_pointer
    : public false_type { };
  template<>
    struct is_null_pointer<std::nullptr_t>
    : public true_type { };
  template<>
    struct is_null_pointer<const std::nullptr_t>
    : public true_type { };
  template<>
    struct is_null_pointer<volatile std::nullptr_t>
    : public true_type { };
  template<>
    struct is_null_pointer<const volatile std::nullptr_t>
    : public true_type { };
  template<typename _Tp>
    struct __is_nullptr_t
    : public is_null_pointer<_Tp>
    { } __attribute__ ((__deprecated__ ("use '" "std::is_null_pointer" "' instead")));
  template<typename _Tp>
    struct is_reference
    : public false_type
    { };
  template<typename _Tp>
    struct is_reference<_Tp&>
    : public true_type
    { };
  template<typename _Tp>
    struct is_reference<_Tp&&>
    : public true_type
    { };
  template<typename _Tp>
    struct is_arithmetic
    : public __or_<is_integral<_Tp>, is_floating_point<_Tp>>::type
    { };
  template<typename _Tp>
    struct is_fundamental
    : public __or_<is_arithmetic<_Tp>, is_void<_Tp>,
     is_null_pointer<_Tp>>::type
    { };
  template<typename _Tp>
    struct is_object
    : public __not_<__or_<is_function<_Tp>, is_reference<_Tp>,
                          is_void<_Tp>>>::type
    { };
  template<typename>
    struct is_member_pointer;
  template<typename _Tp>
    struct is_scalar
    : public __or_<is_arithmetic<_Tp>, is_enum<_Tp>, is_pointer<_Tp>,
                   is_member_pointer<_Tp>, is_null_pointer<_Tp>>::type
    { };
  template<typename _Tp>
    struct is_compound
    : public __not_<is_fundamental<_Tp>>::type { };
  template<typename _Tp>
    struct __is_member_pointer_helper
    : public false_type { };
  template<typename _Tp, typename _Cp>
    struct __is_member_pointer_helper<_Tp _Cp::*>
    : public true_type { };
  template<typename _Tp>
    struct is_member_pointer
    : public __is_member_pointer_helper<__remove_cv_t<_Tp>>::type
    { };
  template<typename, typename>
    struct is_same;
  template<typename _Tp, typename... _Types>
    using __is_one_of = __or_<is_same<_Tp, _Types>...>;
  __extension__
  template<typename _Tp>
    using __is_signed_integer = __is_one_of<__remove_cv_t<_Tp>,
   signed char, signed short, signed int, signed long,
   signed long long
   >;
  __extension__
  template<typename _Tp>
    using __is_unsigned_integer = __is_one_of<__remove_cv_t<_Tp>,
   unsigned char, unsigned short, unsigned int, unsigned long,
   unsigned long long
   >;
  template<typename _Tp>
    using __is_standard_integer
      = __or_<__is_signed_integer<_Tp>, __is_unsigned_integer<_Tp>>;
  template<typename...> using __void_t = void;
  template<typename>
    struct is_const
    : public false_type { };
  template<typename _Tp>
    struct is_const<_Tp const>
    : public true_type { };
  template<typename>
    struct is_volatile
    : public false_type { };
  template<typename _Tp>
    struct is_volatile<_Tp volatile>
    : public true_type { };
  template<typename _Tp>
    struct is_trivial
    : public integral_constant<bool, __is_trivial(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_trivially_copyable
    : public integral_constant<bool, __is_trivially_copyable(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_standard_layout
    : public integral_constant<bool, __is_standard_layout(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct
   
    is_pod
    : public integral_constant<bool, __is_pod(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct
   
    is_literal_type
    : public integral_constant<bool, __is_literal_type(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_empty
    : public integral_constant<bool, __is_empty(_Tp)>
    { };
  template<typename _Tp>
    struct is_polymorphic
    : public integral_constant<bool, __is_polymorphic(_Tp)>
    { };
  template<typename _Tp>
    struct is_abstract
    : public integral_constant<bool, __is_abstract(_Tp)>
    { };
  template<typename _Tp,
    bool = is_arithmetic<_Tp>::value>
    struct __is_signed_helper
    : public false_type { };
  template<typename _Tp>
    struct __is_signed_helper<_Tp, true>
    : public integral_constant<bool, _Tp(-1) < _Tp(0)>
    { };
  template<typename _Tp>
    struct is_signed
    : public __is_signed_helper<_Tp>::type
    { };
  template<typename _Tp>
    struct is_unsigned
    : public __and_<is_arithmetic<_Tp>, __not_<is_signed<_Tp>>>::type
    { };
  template<typename _Tp, typename _Up = _Tp&&>
    _Up
    __declval(int);
  template<typename _Tp>
    _Tp
    __declval(long);
  template<typename _Tp>
    auto declval() noexcept -> decltype(__declval<_Tp>(0));
  template<typename>
    struct remove_all_extents;
  template<typename _Tp>
    struct __is_array_known_bounds
    : public false_type
    { };
  template<typename _Tp, size_t _Size>
    struct __is_array_known_bounds<_Tp[_Size]>
    : public true_type
    { };
  template<typename _Tp>
    struct __is_array_unknown_bounds
    : public false_type
    { };
  template<typename _Tp>
    struct __is_array_unknown_bounds<_Tp[]>
    : public true_type
    { };
  struct __do_is_destructible_impl
  {
    template<typename _Tp, typename = decltype(declval<_Tp&>().~_Tp())>
      static true_type __test(int);
    template<typename>
      static false_type __test(...);
  };
  template<typename _Tp>
    struct __is_destructible_impl
    : public __do_is_destructible_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };
  template<typename _Tp,
           bool = __or_<is_void<_Tp>,
                        __is_array_unknown_bounds<_Tp>,
                        is_function<_Tp>>::value,
           bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
    struct __is_destructible_safe;
  template<typename _Tp>
    struct __is_destructible_safe<_Tp, false, false>
    : public __is_destructible_impl<typename
               remove_all_extents<_Tp>::type>::type
    { };
  template<typename _Tp>
    struct __is_destructible_safe<_Tp, true, false>
    : public false_type { };
  template<typename _Tp>
    struct __is_destructible_safe<_Tp, false, true>
    : public true_type { };
  template<typename _Tp>
    struct is_destructible
    : public __is_destructible_safe<_Tp>::type
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  struct __do_is_nt_destructible_impl
  {
    template<typename _Tp>
      static __bool_constant<noexcept(declval<_Tp&>().~_Tp())>
      __test(int);
    template<typename>
      static false_type __test(...);
  };
  template<typename _Tp>
    struct __is_nt_destructible_impl
    : public __do_is_nt_destructible_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };
  template<typename _Tp,
           bool = __or_<is_void<_Tp>,
                        __is_array_unknown_bounds<_Tp>,
                        is_function<_Tp>>::value,
           bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
    struct __is_nt_destructible_safe;
  template<typename _Tp>
    struct __is_nt_destructible_safe<_Tp, false, false>
    : public __is_nt_destructible_impl<typename
               remove_all_extents<_Tp>::type>::type
    { };
  template<typename _Tp>
    struct __is_nt_destructible_safe<_Tp, true, false>
    : public false_type { };
  template<typename _Tp>
    struct __is_nt_destructible_safe<_Tp, false, true>
    : public true_type { };
  template<typename _Tp>
    struct is_nothrow_destructible
    : public __is_nt_destructible_safe<_Tp>::type
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename... _Args>
    using __is_constructible_impl
      = __bool_constant<__is_constructible(_Tp, _Args...)>;
  template<typename _Tp, typename... _Args>
    struct is_constructible
      : public __is_constructible_impl<_Tp, _Args...>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_default_constructible
    : public __is_constructible_impl<_Tp>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename = void>
    struct __add_lvalue_reference_helper
    { using type = _Tp; };
  template<typename _Tp>
    struct __add_lvalue_reference_helper<_Tp, __void_t<_Tp&>>
    { using type = _Tp&; };
  template<typename _Tp>
    using __add_lval_ref_t = typename __add_lvalue_reference_helper<_Tp>::type;
  template<typename _Tp>
    struct is_copy_constructible
    : public __is_constructible_impl<_Tp, __add_lval_ref_t<const _Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename = void>
    struct __add_rvalue_reference_helper
    { using type = _Tp; };
  template<typename _Tp>
    struct __add_rvalue_reference_helper<_Tp, __void_t<_Tp&&>>
    { using type = _Tp&&; };
  template<typename _Tp>
    using __add_rval_ref_t = typename __add_rvalue_reference_helper<_Tp>::type;
  template<typename _Tp>
    struct is_move_constructible
    : public __is_constructible_impl<_Tp, __add_rval_ref_t<_Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename... _Args>
    using __is_nothrow_constructible_impl
      = __bool_constant<__is_nothrow_constructible(_Tp, _Args...)>;
  template<typename _Tp, typename... _Args>
    struct is_nothrow_constructible
    : public __is_nothrow_constructible_impl<_Tp, _Args...>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_nothrow_default_constructible
    : public __is_nothrow_constructible_impl<_Tp>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_nothrow_copy_constructible
    : public __is_nothrow_constructible_impl<_Tp, __add_lval_ref_t<const _Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_nothrow_move_constructible
    : public __is_nothrow_constructible_impl<_Tp, __add_rval_ref_t<_Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename _Up>
    using __is_assignable_impl = __bool_constant<__is_assignable(_Tp, _Up)>;
  template<typename _Tp, typename _Up>
    struct is_assignable
    : public __is_assignable_impl<_Tp, _Up>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_copy_assignable
    : public __is_assignable_impl<__add_lval_ref_t<_Tp>,
      __add_lval_ref_t<const _Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_move_assignable
    : public __is_assignable_impl<__add_lval_ref_t<_Tp>, __add_rval_ref_t<_Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename _Up>
    using __is_nothrow_assignable_impl
      = __bool_constant<__is_nothrow_assignable(_Tp, _Up)>;
  template<typename _Tp, typename _Up>
    struct is_nothrow_assignable
    : public __is_nothrow_assignable_impl<_Tp, _Up>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_nothrow_copy_assignable
    : public __is_nothrow_assignable_impl<__add_lval_ref_t<_Tp>,
       __add_lval_ref_t<const _Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_nothrow_move_assignable
    : public __is_nothrow_assignable_impl<__add_lval_ref_t<_Tp>,
       __add_rval_ref_t<_Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename... _Args>
    using __is_trivially_constructible_impl
      = __bool_constant<__is_trivially_constructible(_Tp, _Args...)>;
  template<typename _Tp, typename... _Args>
    struct is_trivially_constructible
    : public __is_trivially_constructible_impl<_Tp, _Args...>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_trivially_default_constructible
    : public __is_trivially_constructible_impl<_Tp>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  struct __do_is_implicitly_default_constructible_impl
  {
    template <typename _Tp>
    static void __helper(const _Tp&);
    template <typename _Tp>
    static true_type __test(const _Tp&,
                            decltype(__helper<const _Tp&>({}))* = 0);
    static false_type __test(...);
  };
  template<typename _Tp>
    struct __is_implicitly_default_constructible_impl
    : public __do_is_implicitly_default_constructible_impl
    {
      typedef decltype(__test(declval<_Tp>())) type;
    };
  template<typename _Tp>
    struct __is_implicitly_default_constructible_safe
    : public __is_implicitly_default_constructible_impl<_Tp>::type
    { };
  template <typename _Tp>
    struct __is_implicitly_default_constructible
    : public __and_<__is_constructible_impl<_Tp>,
      __is_implicitly_default_constructible_safe<_Tp>>::type
    { };
  template<typename _Tp>
    struct is_trivially_copy_constructible
    : public __is_trivially_constructible_impl<_Tp, __add_lval_ref_t<const _Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_trivially_move_constructible
    : public __is_trivially_constructible_impl<_Tp, __add_rval_ref_t<_Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp, typename _Up>
    using __is_trivially_assignable_impl
      = __bool_constant<__is_trivially_assignable(_Tp, _Up)>;
  template<typename _Tp, typename _Up>
    struct is_trivially_assignable
    : public __is_trivially_assignable_impl<_Tp, _Up>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_trivially_copy_assignable
    : public __is_trivially_assignable_impl<__add_lval_ref_t<_Tp>,
         __add_lval_ref_t<const _Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_trivially_move_assignable
    : public __is_trivially_assignable_impl<__add_lval_ref_t<_Tp>,
         __add_rval_ref_t<_Tp>>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct is_trivially_destructible
    : public __and_<__is_destructible_safe<_Tp>,
      __bool_constant<__has_trivial_destructor(_Tp)>>::type
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct has_virtual_destructor
    : public integral_constant<bool, __has_virtual_destructor(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename _Tp>
    struct alignment_of
    : public integral_constant<std::size_t, alignof(_Tp)>
    {
      static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
 "template argument must be a complete class or an unbounded array");
    };
  template<typename>
    struct rank
    : public integral_constant<std::size_t, 0> { };
  template<typename _Tp, std::size_t _Size>
    struct rank<_Tp[_Size]>
    : public integral_constant<std::size_t, 1 + rank<_Tp>::value> { };
  template<typename _Tp>
    struct rank<_Tp[]>
    : public integral_constant<std::size_t, 1 + rank<_Tp>::value> { };
  template<typename, unsigned _Uint = 0>
    struct extent
    : public integral_constant<size_t, 0> { };
  template<typename _Tp, size_t _Size>
    struct extent<_Tp[_Size], 0>
    : public integral_constant<size_t, _Size> { };
  template<typename _Tp, unsigned _Uint, size_t _Size>
    struct extent<_Tp[_Size], _Uint>
    : public extent<_Tp, _Uint - 1>::type { };
  template<typename _Tp>
    struct extent<_Tp[], 0>
    : public integral_constant<size_t, 0> { };
  template<typename _Tp, unsigned _Uint>
    struct extent<_Tp[], _Uint>
    : public extent<_Tp, _Uint - 1>::type { };
  template<typename _Tp, typename _Up>
    struct is_same
    : public integral_constant<bool, __is_same(_Tp, _Up)>
    { };
  template<typename _Base, typename _Derived>
    struct is_base_of
    : public integral_constant<bool, __is_base_of(_Base, _Derived)>
    { };
  template<typename _From, typename _To>
    struct is_convertible
    : public __bool_constant<__is_convertible(_From, _To)>
    { };
  template<typename _ToElementType, typename _FromElementType>
    using __is_array_convertible
      = is_convertible<_FromElementType(*)[], _ToElementType(*)[]>;
  template<typename _Tp>
    struct remove_const
    { typedef _Tp type; };
  template<typename _Tp>
    struct remove_const<_Tp const>
    { typedef _Tp type; };
  template<typename _Tp>
    struct remove_volatile
    { typedef _Tp type; };
  template<typename _Tp>
    struct remove_volatile<_Tp volatile>
    { typedef _Tp type; };
  template<typename _Tp>
    struct remove_cv
    { using type = __remove_cv(_Tp); };
  template<typename _Tp>
    struct add_const
    { using type = _Tp const; };
  template<typename _Tp>
    struct add_volatile
    { using type = _Tp volatile; };
  template<typename _Tp>
    struct add_cv
    { using type = _Tp const volatile; };
  template<typename _Tp>
    struct remove_reference
    { using type = __remove_reference(_Tp); };
  template<typename _Tp>
    struct add_lvalue_reference
    { using type = __add_lval_ref_t<_Tp>; };
  template<typename _Tp>
    struct add_rvalue_reference
    { using type = __add_rval_ref_t<_Tp>; };
  template<typename _Unqualified, bool _IsConst, bool _IsVol>
    struct __cv_selector;
  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, false, false>
    { typedef _Unqualified __type; };
  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, false, true>
    { typedef volatile _Unqualified __type; };
  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, true, false>
    { typedef const _Unqualified __type; };
  template<typename _Unqualified>
    struct __cv_selector<_Unqualified, true, true>
    { typedef const volatile _Unqualified __type; };
  template<typename _Qualified, typename _Unqualified,
    bool _IsConst = is_const<_Qualified>::value,
    bool _IsVol = is_volatile<_Qualified>::value>
    class __match_cv_qualifiers
    {
      typedef __cv_selector<_Unqualified, _IsConst, _IsVol> __match;
    public:
      typedef typename __match::__type __type;
    };
  template<typename _Tp>
    struct __make_unsigned
    { typedef _Tp __type; };
  template<>
    struct __make_unsigned<char>
    { typedef unsigned char __type; };
  template<>
    struct __make_unsigned<signed char>
    { typedef unsigned char __type; };
  template<>
    struct __make_unsigned<short>
    { typedef unsigned short __type; };
  template<>
    struct __make_unsigned<int>
    { typedef unsigned int __type; };
  template<>
    struct __make_unsigned<long>
    { typedef unsigned long __type; };
  template<>
    struct __make_unsigned<long long>
    { typedef unsigned long long __type; };
  template<typename _Tp,
    bool _IsInt = is_integral<_Tp>::value,
    bool _IsEnum = is_enum<_Tp>::value>
    class __make_unsigned_selector;
  template<typename _Tp>
    class __make_unsigned_selector<_Tp, true, false>
    {
      using __unsigned_type
 = typename __make_unsigned<__remove_cv_t<_Tp>>::__type;
    public:
      using __type
 = typename __match_cv_qualifiers<_Tp, __unsigned_type>::__type;
    };
  class __make_unsigned_selector_base
  {
  protected:
    template<typename...> struct _List { };
    template<typename _Tp, typename... _Up>
      struct _List<_Tp, _Up...> : _List<_Up...>
      { static constexpr size_t __size = sizeof(_Tp); };
    template<size_t _Sz, typename _Tp, bool = (_Sz <= _Tp::__size)>
      struct __select;
    template<size_t _Sz, typename _Uint, typename... _UInts>
      struct __select<_Sz, _List<_Uint, _UInts...>, true>
      { using __type = _Uint; };
    template<size_t _Sz, typename _Uint, typename... _UInts>
      struct __select<_Sz, _List<_Uint, _UInts...>, false>
      : __select<_Sz, _List<_UInts...>>
      { };
  };
  template<typename _Tp>
    class __make_unsigned_selector<_Tp, false, true>
    : __make_unsigned_selector_base
    {
      using _UInts = _List<unsigned char, unsigned short, unsigned int,
      unsigned long, unsigned long long>;
      using __unsigned_type = typename __select<sizeof(_Tp), _UInts>::__type;
    public:
      using __type
 = typename __match_cv_qualifiers<_Tp, __unsigned_type>::__type;
    };
  template<>
    struct __make_unsigned<wchar_t>
    {
      using __type
 = typename __make_unsigned_selector<wchar_t, false, true>::__type;
    };
  template<>
    struct __make_unsigned<char16_t>
    {
      using __type
 = typename __make_unsigned_selector<char16_t, false, true>::__type;
    };
  template<>
    struct __make_unsigned<char32_t>
    {
      using __type
 = typename __make_unsigned_selector<char32_t, false, true>::__type;
    };
  template<typename _Tp>
    struct make_unsigned
    { typedef typename __make_unsigned_selector<_Tp>::__type type; };
  template<> struct make_unsigned<bool>;
  template<> struct make_unsigned<bool const>;
  template<> struct make_unsigned<bool volatile>;
  template<> struct make_unsigned<bool const volatile>;
  template<typename _Tp>
    struct __make_signed
    { typedef _Tp __type; };
  template<>
    struct __make_signed<char>
    { typedef signed char __type; };
  template<>
    struct __make_signed<unsigned char>
    { typedef signed char __type; };
  template<>
    struct __make_signed<unsigned short>
    { typedef signed short __type; };
  template<>
    struct __make_signed<unsigned int>
    { typedef signed int __type; };
  template<>
    struct __make_signed<unsigned long>
    { typedef signed long __type; };
  template<>
    struct __make_signed<unsigned long long>
    { typedef signed long long __type; };
  template<typename _Tp,
    bool _IsInt = is_integral<_Tp>::value,
    bool _IsEnum = is_enum<_Tp>::value>
    class __make_signed_selector;
  template<typename _Tp>
    class __make_signed_selector<_Tp, true, false>
    {
      using __signed_type
 = typename __make_signed<__remove_cv_t<_Tp>>::__type;
    public:
      using __type
 = typename __match_cv_qualifiers<_Tp, __signed_type>::__type;
    };
  template<typename _Tp>
    class __make_signed_selector<_Tp, false, true>
    {
      typedef typename __make_unsigned_selector<_Tp>::__type __unsigned_type;
    public:
      typedef typename __make_signed_selector<__unsigned_type>::__type __type;
    };
  template<>
    struct __make_signed<wchar_t>
    {
      using __type
 = typename __make_signed_selector<wchar_t, false, true>::__type;
    };
  template<>
    struct __make_signed<char16_t>
    {
      using __type
 = typename __make_signed_selector<char16_t, false, true>::__type;
    };
  template<>
    struct __make_signed<char32_t>
    {
      using __type
 = typename __make_signed_selector<char32_t, false, true>::__type;
    };
  template<typename _Tp>
    struct make_signed
    { typedef typename __make_signed_selector<_Tp>::__type type; };
  template<> struct make_signed<bool>;
  template<> struct make_signed<bool const>;
  template<> struct make_signed<bool volatile>;
  template<> struct make_signed<bool const volatile>;
  template<typename _Tp>
    struct remove_extent
    { typedef _Tp type; };
  template<typename _Tp, std::size_t _Size>
    struct remove_extent<_Tp[_Size]>
    { typedef _Tp type; };
  template<typename _Tp>
    struct remove_extent<_Tp[]>
    { typedef _Tp type; };
  template<typename _Tp>
    struct remove_all_extents
    { typedef _Tp type; };
  template<typename _Tp, std::size_t _Size>
    struct remove_all_extents<_Tp[_Size]>
    { typedef typename remove_all_extents<_Tp>::type type; };
  template<typename _Tp>
    struct remove_all_extents<_Tp[]>
    { typedef typename remove_all_extents<_Tp>::type type; };
  template<typename _Tp, typename>
    struct __remove_pointer_helper
    { typedef _Tp type; };
  template<typename _Tp, typename _Up>
    struct __remove_pointer_helper<_Tp, _Up*>
    { typedef _Up type; };
  template<typename _Tp>
    struct remove_pointer
    : public __remove_pointer_helper<_Tp, __remove_cv_t<_Tp>>
    { };
  template<typename _Tp, typename = void>
    struct __add_pointer_helper
    { using type = _Tp; };
  template<typename _Tp>
    struct __add_pointer_helper<_Tp, __void_t<_Tp*>>
    { using type = _Tp*; };
  template<typename _Tp>
    struct add_pointer
    : public __add_pointer_helper<_Tp>
    { };
  template<typename _Tp>
    struct add_pointer<_Tp&>
    { using type = _Tp*; };
  template<typename _Tp>
    struct add_pointer<_Tp&&>
    { using type = _Tp*; };
  template<std::size_t _Len>
    struct __aligned_storage_msa
    {
      union __type
      {
 unsigned char __data[_Len];
 struct __attribute__((__aligned__)) { } __align;
      };
    };
  template<std::size_t _Len, std::size_t _Align =
    __alignof__(typename __aligned_storage_msa<_Len>::__type)>
    struct
   
    aligned_storage
    {
      union type
      {
 unsigned char __data[_Len];
 struct __attribute__((__aligned__((_Align)))) { } __align;
      };
    };
  template <typename... _Types>
    struct __strictest_alignment
    {
      static const size_t _S_alignment = 0;
      static const size_t _S_size = 0;
    };
  template <typename _Tp, typename... _Types>
    struct __strictest_alignment<_Tp, _Types...>
    {
      static const size_t _S_alignment =
        alignof(_Tp) > __strictest_alignment<_Types...>::_S_alignment
 ? alignof(_Tp) : __strictest_alignment<_Types...>::_S_alignment;
      static const size_t _S_size =
        sizeof(_Tp) > __strictest_alignment<_Types...>::_S_size
 ? sizeof(_Tp) : __strictest_alignment<_Types...>::_S_size;
    };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template <size_t _Len, typename... _Types>
    struct
   
    aligned_union
    {
    private:
      static_assert(sizeof...(_Types) != 0, "At least one type is required");
      using __strictest = __strictest_alignment<_Types...>;
      static const size_t _S_len = _Len > __strictest::_S_size
 ? _Len : __strictest::_S_size;
    public:
      static const size_t alignment_value = __strictest::_S_alignment;
      typedef typename aligned_storage<_S_len, alignment_value>::type type;
    };
  template <size_t _Len, typename... _Types>
    const size_t aligned_union<_Len, _Types...>::alignment_value;
#pragma GCC diagnostic pop
  template<typename _Up>
    struct __decay_selector
    : __conditional_t<is_const<const _Up>::value,
        remove_cv<_Up>,
        add_pointer<_Up>>
    { };
  template<typename _Up, size_t _Nm>
    struct __decay_selector<_Up[_Nm]>
    { using type = _Up*; };
  template<typename _Up>
    struct __decay_selector<_Up[]>
    { using type = _Up*; };
  template<typename _Tp>
    struct decay
    { using type = typename __decay_selector<_Tp>::type; };
  template<typename _Tp>
    struct decay<_Tp&>
    { using type = typename __decay_selector<_Tp>::type; };
  template<typename _Tp>
    struct decay<_Tp&&>
    { using type = typename __decay_selector<_Tp>::type; };
  template<typename _Tp>
    struct __strip_reference_wrapper
    {
      typedef _Tp __type;
    };
  template<typename _Tp>
    struct __strip_reference_wrapper<reference_wrapper<_Tp> >
    {
      typedef _Tp& __type;
    };
  template<typename _Tp>
    using __decay_t = typename decay<_Tp>::type;
  template<typename _Tp>
    using __decay_and_strip = __strip_reference_wrapper<__decay_t<_Tp>>;
  template<typename... _Cond>
    using _Require = __enable_if_t<__and_<_Cond...>::value>;
  template<typename _Tp>
    using __remove_cvref_t
     = typename remove_cv<typename remove_reference<_Tp>::type>::type;
  template<bool _Cond, typename _Iftrue, typename _Iffalse>
    struct conditional
    { typedef _Iftrue type; };
  template<typename _Iftrue, typename _Iffalse>
    struct conditional<false, _Iftrue, _Iffalse>
    { typedef _Iffalse type; };
  template<typename... _Tp>
    struct common_type;
  template<typename _Tp>
    struct __success_type
    { typedef _Tp type; };
  struct __failure_type
  { };
  struct __do_common_type_impl
  {
    template<typename _Tp, typename _Up>
      using __cond_t
 = decltype(true ? std::declval<_Tp>() : std::declval<_Up>());
    template<typename _Tp, typename _Up>
      static __success_type<__decay_t<__cond_t<_Tp, _Up>>>
      _S_test(int);
    template<typename, typename>
      static __failure_type
      _S_test_2(...);
    template<typename _Tp, typename _Up>
      static decltype(_S_test_2<_Tp, _Up>(0))
      _S_test(...);
  };
  template<>
    struct common_type<>
    { };
  template<typename _Tp0>
    struct common_type<_Tp0>
    : public common_type<_Tp0, _Tp0>
    { };
  template<typename _Tp1, typename _Tp2,
    typename _Dp1 = __decay_t<_Tp1>, typename _Dp2 = __decay_t<_Tp2>>
    struct __common_type_impl
    {
      using type = common_type<_Dp1, _Dp2>;
    };
  template<typename _Tp1, typename _Tp2>
    struct __common_type_impl<_Tp1, _Tp2, _Tp1, _Tp2>
    : private __do_common_type_impl
    {
      using type = decltype(_S_test<_Tp1, _Tp2>(0));
    };
  template<typename _Tp1, typename _Tp2>
    struct common_type<_Tp1, _Tp2>
    : public __common_type_impl<_Tp1, _Tp2>::type
    { };
  template<typename...>
    struct __common_type_pack
    { };
  template<typename, typename, typename = void>
    struct __common_type_fold;
  template<typename _Tp1, typename _Tp2, typename... _Rp>
    struct common_type<_Tp1, _Tp2, _Rp...>
    : public __common_type_fold<common_type<_Tp1, _Tp2>,
    __common_type_pack<_Rp...>>
    { };
  template<typename _CTp, typename... _Rp>
    struct __common_type_fold<_CTp, __common_type_pack<_Rp...>,
         __void_t<typename _CTp::type>>
    : public common_type<typename _CTp::type, _Rp...>
    { };
  template<typename _CTp, typename _Rp>
    struct __common_type_fold<_CTp, _Rp, void>
    { };
  template<typename _Tp, bool = is_enum<_Tp>::value>
    struct __underlying_type_impl
    {
      using type = __underlying_type(_Tp);
    };
  template<typename _Tp>
    struct __underlying_type_impl<_Tp, false>
    { };
  template<typename _Tp>
    struct underlying_type
    : public __underlying_type_impl<_Tp>
    { };
  template<typename _Tp>
    struct __declval_protector
    {
      static const bool __stop = false;
    };
  template<typename _Tp>
    auto declval() noexcept -> decltype(__declval<_Tp>(0))
    {
      static_assert(__declval_protector<_Tp>::__stop,
      "declval() must not be used!");
      return __declval<_Tp>(0);
    }
  template<typename _Signature>
    struct result_of;
  struct __invoke_memfun_ref { };
  struct __invoke_memfun_deref { };
  struct __invoke_memobj_ref { };
  struct __invoke_memobj_deref { };
  struct __invoke_other { };
  template<typename _Tp, typename _Tag>
    struct __result_of_success : __success_type<_Tp>
    { using __invoke_type = _Tag; };
  struct __result_of_memfun_ref_impl
  {
    template<typename _Fp, typename _Tp1, typename... _Args>
      static __result_of_success<decltype(
      (std::declval<_Tp1>().*std::declval<_Fp>())(std::declval<_Args>()...)
      ), __invoke_memfun_ref> _S_test(int);
    template<typename...>
      static __failure_type _S_test(...);
  };
  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_memfun_ref
    : private __result_of_memfun_ref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
    };
  struct __result_of_memfun_deref_impl
  {
    template<typename _Fp, typename _Tp1, typename... _Args>
      static __result_of_success<decltype(
      ((*std::declval<_Tp1>()).*std::declval<_Fp>())(std::declval<_Args>()...)
      ), __invoke_memfun_deref> _S_test(int);
    template<typename...>
      static __failure_type _S_test(...);
  };
  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_memfun_deref
    : private __result_of_memfun_deref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
    };
  struct __result_of_memobj_ref_impl
  {
    template<typename _Fp, typename _Tp1>
      static __result_of_success<decltype(
      std::declval<_Tp1>().*std::declval<_Fp>()
      ), __invoke_memobj_ref> _S_test(int);
    template<typename, typename>
      static __failure_type _S_test(...);
  };
  template<typename _MemPtr, typename _Arg>
    struct __result_of_memobj_ref
    : private __result_of_memobj_ref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
    };
  struct __result_of_memobj_deref_impl
  {
    template<typename _Fp, typename _Tp1>
      static __result_of_success<decltype(
      (*std::declval<_Tp1>()).*std::declval<_Fp>()
      ), __invoke_memobj_deref> _S_test(int);
    template<typename, typename>
      static __failure_type _S_test(...);
  };
  template<typename _MemPtr, typename _Arg>
    struct __result_of_memobj_deref
    : private __result_of_memobj_deref_impl
    {
      typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
    };
  template<typename _MemPtr, typename _Arg>
    struct __result_of_memobj;
  template<typename _Res, typename _Class, typename _Arg>
    struct __result_of_memobj<_Res _Class::*, _Arg>
    {
      typedef __remove_cvref_t<_Arg> _Argval;
      typedef _Res _Class::* _MemPtr;
      typedef typename __conditional_t<__or_<is_same<_Argval, _Class>,
        is_base_of<_Class, _Argval>>::value,
        __result_of_memobj_ref<_MemPtr, _Arg>,
        __result_of_memobj_deref<_MemPtr, _Arg>
      >::type type;
    };
  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_memfun;
  template<typename _Res, typename _Class, typename _Arg, typename... _Args>
    struct __result_of_memfun<_Res _Class::*, _Arg, _Args...>
    {
      typedef typename remove_reference<_Arg>::type _Argval;
      typedef _Res _Class::* _MemPtr;
      typedef typename __conditional_t<is_base_of<_Class, _Argval>::value,
        __result_of_memfun_ref<_MemPtr, _Arg, _Args...>,
        __result_of_memfun_deref<_MemPtr, _Arg, _Args...>
      >::type type;
    };
  template<typename _Tp, typename _Up = __remove_cvref_t<_Tp>>
    struct __inv_unwrap
    {
      using type = _Tp;
    };
  template<typename _Tp, typename _Up>
    struct __inv_unwrap<_Tp, reference_wrapper<_Up>>
    {
      using type = _Up&;
    };
  template<bool, bool, typename _Functor, typename... _ArgTypes>
    struct __result_of_impl
    {
      typedef __failure_type type;
    };
  template<typename _MemPtr, typename _Arg>
    struct __result_of_impl<true, false, _MemPtr, _Arg>
    : public __result_of_memobj<__decay_t<_MemPtr>,
    typename __inv_unwrap<_Arg>::type>
    { };
  template<typename _MemPtr, typename _Arg, typename... _Args>
    struct __result_of_impl<false, true, _MemPtr, _Arg, _Args...>
    : public __result_of_memfun<__decay_t<_MemPtr>,
    typename __inv_unwrap<_Arg>::type, _Args...>
    { };
  struct __result_of_other_impl
  {
    template<typename _Fn, typename... _Args>
      static __result_of_success<decltype(
      std::declval<_Fn>()(std::declval<_Args>()...)
      ), __invoke_other> _S_test(int);
    template<typename...>
      static __failure_type _S_test(...);
  };
  template<typename _Functor, typename... _ArgTypes>
    struct __result_of_impl<false, false, _Functor, _ArgTypes...>
    : private __result_of_other_impl
    {
      typedef decltype(_S_test<_Functor, _ArgTypes...>(0)) type;
    };
  template<typename _Functor, typename... _ArgTypes>
    struct __invoke_result
    : public __result_of_impl<
        is_member_object_pointer<
          typename remove_reference<_Functor>::type
        >::value,
        is_member_function_pointer<
          typename remove_reference<_Functor>::type
        >::value,
 _Functor, _ArgTypes...
      >::type
    { };
  template<typename _Functor, typename... _ArgTypes>
    struct result_of<_Functor(_ArgTypes...)>
    : public __invoke_result<_Functor, _ArgTypes...>
    { } ;
  template<typename _Default, typename _AlwaysVoid,
    template<typename...> class _Op, typename... _Args>
    struct __detector
    {
      using type = _Default;
      using __is_detected = false_type;
    };
  template<typename _Default, template<typename...> class _Op,
     typename... _Args>
    struct __detector<_Default, __void_t<_Op<_Args...>>, _Op, _Args...>
    {
      using type = _Op<_Args...>;
      using __is_detected = true_type;
    };
  template<typename _Default, template<typename...> class _Op,
    typename... _Args>
    using __detected_or = __detector<_Default, void, _Op, _Args...>;
  template<typename _Default, template<typename...> class _Op,
    typename... _Args>
    using __detected_or_t
      = typename __detected_or<_Default, _Op, _Args...>::type;
  template <typename _Tp>
    struct __is_swappable;
  template <typename _Tp>
    struct __is_nothrow_swappable;
  template<typename>
    struct __is_tuple_like_impl : false_type
    { };
  template<typename _Tp>
    struct __is_tuple_like
    : public __is_tuple_like_impl<__remove_cvref_t<_Tp>>::type
    { };
  template<typename _Tp>
   
    inline
    _Require<__not_<__is_tuple_like<_Tp>>,
      is_move_constructible<_Tp>,
      is_move_assignable<_Tp>>
    swap(_Tp&, _Tp&)
    noexcept(__and_<is_nothrow_move_constructible<_Tp>,
             is_nothrow_move_assignable<_Tp>>::value);
  template<typename _Tp, size_t _Nm>
   
    inline
    __enable_if_t<__is_swappable<_Tp>::value>
    swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm])
    noexcept(__is_nothrow_swappable<_Tp>::value);
  namespace __swappable_details {
    using std::swap;
    struct __do_is_swappable_impl
    {
      template<typename _Tp, typename
               = decltype(swap(std::declval<_Tp&>(), std::declval<_Tp&>()))>
        static true_type __test(int);
      template<typename>
        static false_type __test(...);
    };
    struct __do_is_nothrow_swappable_impl
    {
      template<typename _Tp>
        static __bool_constant<
          noexcept(swap(std::declval<_Tp&>(), std::declval<_Tp&>()))
        > __test(int);
      template<typename>
        static false_type __test(...);
    };
  }
  template<typename _Tp>
    struct __is_swappable_impl
    : public __swappable_details::__do_is_swappable_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };
  template<typename _Tp>
    struct __is_nothrow_swappable_impl
    : public __swappable_details::__do_is_nothrow_swappable_impl
    {
      typedef decltype(__test<_Tp>(0)) type;
    };
  template<typename _Tp>
    struct __is_swappable
    : public __is_swappable_impl<_Tp>::type
    { };
  template<typename _Tp>
    struct __is_nothrow_swappable
    : public __is_nothrow_swappable_impl<_Tp>::type
    { };
  template<typename _Result, typename _Ret,
    bool = is_void<_Ret>::value, typename = void>
    struct __is_invocable_impl
    : false_type
    {
      using __nothrow_conv = false_type;
    };
  template<typename _Result, typename _Ret>
    struct __is_invocable_impl<_Result, _Ret,
                                true,
          __void_t<typename _Result::type>>
    : true_type
    {
      using __nothrow_conv = true_type;
    };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
  template<typename _Result, typename _Ret>
    struct __is_invocable_impl<_Result, _Ret,
                                false,
          __void_t<typename _Result::type>>
    {
    private:
      using _Res_t = typename _Result::type;
      static _Res_t _S_get() noexcept;
      template<typename _Tp>
 static void _S_conv(__type_identity_t<_Tp>) noexcept;
      template<typename _Tp,
        bool _Nothrow = noexcept(_S_conv<_Tp>(_S_get())),
        typename = decltype(_S_conv<_Tp>(_S_get())),
        bool _Dangle = __reference_converts_from_temporary(_Tp, _Res_t)
       >
 static __bool_constant<_Nothrow && !_Dangle>
 _S_test(int);
      template<typename _Tp, bool = false>
 static false_type
 _S_test(...);
    public:
      using type = decltype(_S_test<_Ret, true>(1));
      using __nothrow_conv = decltype(_S_test<_Ret>(1));
    };
#pragma GCC diagnostic pop
  template<typename _Fn, typename... _ArgTypes>
    struct __is_invocable
    : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>::type
    { };
  template<typename _Fn, typename _Tp, typename... _Args>
    constexpr bool __call_is_nt(__invoke_memfun_ref)
    {
      using _Up = typename __inv_unwrap<_Tp>::type;
      return noexcept((std::declval<_Up>().*std::declval<_Fn>())(
     std::declval<_Args>()...));
    }
  template<typename _Fn, typename _Tp, typename... _Args>
    constexpr bool __call_is_nt(__invoke_memfun_deref)
    {
      return noexcept(((*std::declval<_Tp>()).*std::declval<_Fn>())(
     std::declval<_Args>()...));
    }
  template<typename _Fn, typename _Tp>
    constexpr bool __call_is_nt(__invoke_memobj_ref)
    {
      using _Up = typename __inv_unwrap<_Tp>::type;
      return noexcept(std::declval<_Up>().*std::declval<_Fn>());
    }
  template<typename _Fn, typename _Tp>
    constexpr bool __call_is_nt(__invoke_memobj_deref)
    {
      return noexcept((*std::declval<_Tp>()).*std::declval<_Fn>());
    }
  template<typename _Fn, typename... _Args>
    constexpr bool __call_is_nt(__invoke_other)
    {
      return noexcept(std::declval<_Fn>()(std::declval<_Args>()...));
    }
  template<typename _Result, typename _Fn, typename... _Args>
    struct __call_is_nothrow
    : __bool_constant<
 std::__call_is_nt<_Fn, _Args...>(typename _Result::__invoke_type{})
      >
    { };
  template<typename _Fn, typename... _Args>
    using __call_is_nothrow_
      = __call_is_nothrow<__invoke_result<_Fn, _Args...>, _Fn, _Args...>;
  template<typename _Fn, typename... _Args>
    struct __is_nothrow_invocable
    : __and_<__is_invocable<_Fn, _Args...>,
             __call_is_nothrow_<_Fn, _Args...>>::type
    { };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
  struct __nonesuchbase {};
  struct __nonesuch : private __nonesuchbase {
    ~__nonesuch() = delete;
    __nonesuch(__nonesuch const&) = delete;
    void operator=(__nonesuch const&) = delete;
  };
#pragma GCC diagnostic pop

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp>
    inline constexpr _Tp*
    __addressof(_Tp& __r) noexcept
    { return __builtin_addressof(__r); }
  template<typename _Tp>
   
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Tp&&>(__t); }
  template<typename _Tp>
   
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type&& __t) noexcept
    {
      static_assert(!std::is_lvalue_reference<_Tp>::value,
   "std::forward must not be used to convert an rvalue to an lvalue");
      return static_cast<_Tp&&>(__t);
    }
  template<typename _Tp>
   
    constexpr typename std::remove_reference<_Tp>::type&&
    move(_Tp&& __t) noexcept
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
  template<typename _Tp>
    struct __move_if_noexcept_cond
    : public __and_<__not_<is_nothrow_move_constructible<_Tp>>,
                    is_copy_constructible<_Tp>>::type { };
  template<typename _Tp>
   
    constexpr
    __conditional_t<__move_if_noexcept_cond<_Tp>::value, const _Tp&, _Tp&&>
    move_if_noexcept(_Tp& __x) noexcept
    { return std::move(__x); }
  template<typename _Tp>
   
    inline _Tp*
    addressof(_Tp& __r) noexcept
    { return std::__addressof(__r); }
  template<typename _Tp>
    const _Tp* addressof(const _Tp&&) = delete;
  template <typename _Tp, typename _Up = _Tp>
   
    inline _Tp
    __exchange(_Tp& __obj, _Up&& __new_val)
    {
      _Tp __old_val = std::move(__obj);
      __obj = std::forward<_Up>(__new_val);
      return __old_val;
    }
  template<typename _Tp>
   
    inline
    typename enable_if<__and_<__not_<__is_tuple_like<_Tp>>,
         is_move_constructible<_Tp>,
         is_move_assignable<_Tp>>::value>::type
    swap(_Tp& __a, _Tp& __b)
    noexcept(__and_<is_nothrow_move_constructible<_Tp>, is_nothrow_move_assignable<_Tp>>::value)
    {
      _Tp __tmp = std::move(__a);
      __a = std::move(__b);
      __b = std::move(__tmp);
    }
  template<typename _Tp, size_t _Nm>
   
    inline
    typename enable_if<__is_swappable<_Tp>::value>::type
    swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm])
    noexcept(__is_nothrow_swappable<_Tp>::value)
    {
      for (size_t __n = 0; __n < _Nm; ++__n)
 swap(__a[__n], __b[__n]);
    }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  typedef enum memory_order
    {
      memory_order_relaxed,
      memory_order_consume,
      memory_order_acquire,
      memory_order_release,
      memory_order_acq_rel,
      memory_order_seq_cst
    } memory_order;
  enum __memory_order_modifier
    {
      __memory_order_mask = 0x0ffff,
      __memory_order_modifier_mask = 0xffff0000,
      __memory_order_hle_acquire = 0x10000,
      __memory_order_hle_release = 0x20000
    };
  constexpr memory_order
  operator|(memory_order __m, __memory_order_modifier __mod)
  {
    return memory_order(int(__m) | int(__mod));
  }
  constexpr memory_order
  operator&(memory_order __m, __memory_order_modifier __mod)
  {
    return memory_order(int(__m) & int(__mod));
  }
  constexpr memory_order
  __cmpexch_failure_order2(memory_order __m) noexcept
  {
    return __m == memory_order_acq_rel ? memory_order_acquire
      : __m == memory_order_release ? memory_order_relaxed : __m;
  }
  constexpr memory_order
  __cmpexch_failure_order(memory_order __m) noexcept
  {
    return memory_order(__cmpexch_failure_order2(__m & __memory_order_mask)
      | __memory_order_modifier(__m & __memory_order_modifier_mask));
  }
  constexpr bool
  __is_valid_cmpexch_failure_order(memory_order __m) noexcept
  {
    return (__m & __memory_order_mask) != memory_order_release
 && (__m & __memory_order_mask) != memory_order_acq_rel;
  }
  template<typename _IntTp>
    struct __atomic_base;
  inline __attribute__((__always_inline__)) void
  atomic_thread_fence(memory_order __m) noexcept
  { __atomic_thread_fence(int(__m)); }
  inline __attribute__((__always_inline__)) void
  atomic_signal_fence(memory_order __m) noexcept
  { __atomic_signal_fence(int(__m)); }
  template<typename _Tp>
    inline _Tp
    kill_dependency(_Tp __y) noexcept
    {
      _Tp __ret(__y);
      return __ret;
    }
  template<typename _Tp>
    struct atomic;
  template<typename _Tp>
    struct atomic<_Tp*>;
    typedef bool __atomic_flag_data_type;
  extern "C" {
  struct __atomic_flag_base
  {
    __atomic_flag_data_type _M_i ;
  };
  }
  struct atomic_flag : public __atomic_flag_base
  {
    atomic_flag() noexcept = default;
    ~atomic_flag() noexcept = default;
    atomic_flag(const atomic_flag&) = delete;
    atomic_flag& operator=(const atomic_flag&) = delete;
    atomic_flag& operator=(const atomic_flag&) volatile = delete;
    constexpr atomic_flag(bool __i) noexcept
      : __atomic_flag_base{ _S_init(__i) }
    { }
    inline __attribute__((__always_inline__)) bool
    test_and_set(memory_order __m = memory_order_seq_cst) noexcept
    {
      return __atomic_test_and_set (&_M_i, int(__m));
    }
    inline __attribute__((__always_inline__)) bool
    test_and_set(memory_order __m = memory_order_seq_cst) volatile noexcept
    {
      return __atomic_test_and_set (&_M_i, int(__m));
    }
    inline __attribute__((__always_inline__)) void
    clear(memory_order __m = memory_order_seq_cst) noexcept
    {
      memory_order __b __attribute__ ((__unused__))
 = __m & __memory_order_mask;
      do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_consume)) __builtin_unreachable(); } while (false);
      do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acquire)) __builtin_unreachable(); } while (false);
      do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
      __atomic_clear (&_M_i, int(__m));
    }
    inline __attribute__((__always_inline__)) void
    clear(memory_order __m = memory_order_seq_cst) volatile noexcept
    {
      memory_order __b __attribute__ ((__unused__))
 = __m & __memory_order_mask;
      do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_consume)) __builtin_unreachable(); } while (false);
      do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acquire)) __builtin_unreachable(); } while (false);
      do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
      __atomic_clear (&_M_i, int(__m));
    }
  private:
    static constexpr __atomic_flag_data_type
    _S_init(bool __i)
    { return __i ? 1 : 0; }
  };
  template<typename _ITp>
    struct __atomic_base
    {
      using value_type = _ITp;
      using difference_type = value_type;
    private:
      typedef _ITp __int_type;
      static constexpr int _S_alignment =
 sizeof(_ITp) > alignof(_ITp) ? sizeof(_ITp) : alignof(_ITp);
      alignas(_S_alignment) __int_type _M_i ;
    public:
      __atomic_base() noexcept = default;
      ~__atomic_base() noexcept = default;
      __atomic_base(const __atomic_base&) = delete;
      __atomic_base& operator=(const __atomic_base&) = delete;
      __atomic_base& operator=(const __atomic_base&) volatile = delete;
      constexpr __atomic_base(__int_type __i) noexcept : _M_i (__i) { }
      operator __int_type() const noexcept
      { return load(); }
      operator __int_type() const volatile noexcept
      { return load(); }
      __int_type
      operator=(__int_type __i) noexcept
      {
 store(__i);
 return __i;
      }
      __int_type
      operator=(__int_type __i) volatile noexcept
      {
 store(__i);
 return __i;
      }
      __int_type
      operator++(int) noexcept
      { return fetch_add(1); }
      __int_type
      operator++(int) volatile noexcept
      { return fetch_add(1); }
      __int_type
      operator--(int) noexcept
      { return fetch_sub(1); }
      __int_type
      operator--(int) volatile noexcept
      { return fetch_sub(1); }
      __int_type
      operator++() noexcept
      { return __atomic_add_fetch(&_M_i, 1, int(memory_order_seq_cst)); }
      __int_type
      operator++() volatile noexcept
      { return __atomic_add_fetch(&_M_i, 1, int(memory_order_seq_cst)); }
      __int_type
      operator--() noexcept
      { return __atomic_sub_fetch(&_M_i, 1, int(memory_order_seq_cst)); }
      __int_type
      operator--() volatile noexcept
      { return __atomic_sub_fetch(&_M_i, 1, int(memory_order_seq_cst)); }
      __int_type
      operator+=(__int_type __i) noexcept
      { return __atomic_add_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator+=(__int_type __i) volatile noexcept
      { return __atomic_add_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator-=(__int_type __i) noexcept
      { return __atomic_sub_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator-=(__int_type __i) volatile noexcept
      { return __atomic_sub_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator&=(__int_type __i) noexcept
      { return __atomic_and_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator&=(__int_type __i) volatile noexcept
      { return __atomic_and_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator|=(__int_type __i) noexcept
      { return __atomic_or_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator|=(__int_type __i) volatile noexcept
      { return __atomic_or_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator^=(__int_type __i) noexcept
      { return __atomic_xor_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      __int_type
      operator^=(__int_type __i) volatile noexcept
      { return __atomic_xor_fetch(&_M_i, __i, int(memory_order_seq_cst)); }
      bool
      is_lock_free() const noexcept
      {
 return __atomic_is_lock_free(sizeof(_M_i),
     reinterpret_cast<void *>(-_S_alignment));
      }
      bool
      is_lock_free() const volatile noexcept
      {
 return __atomic_is_lock_free(sizeof(_M_i),
     reinterpret_cast<void *>(-_S_alignment));
      }
      inline __attribute__((__always_inline__)) void
      store(__int_type __i, memory_order __m = memory_order_seq_cst) noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acquire)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_consume)) __builtin_unreachable(); } while (false);
 __atomic_store_n(&_M_i, __i, int(__m));
      }
      inline __attribute__((__always_inline__)) void
      store(__int_type __i,
     memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acquire)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_consume)) __builtin_unreachable(); } while (false);
 __atomic_store_n(&_M_i, __i, int(__m));
      }
      inline __attribute__((__always_inline__)) __int_type
      load(memory_order __m = memory_order_seq_cst) const noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_release)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 return __atomic_load_n(&_M_i, int(__m));
      }
      inline __attribute__((__always_inline__)) __int_type
      load(memory_order __m = memory_order_seq_cst) const volatile noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_release)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 return __atomic_load_n(&_M_i, int(__m));
      }
      inline __attribute__((__always_inline__)) __int_type
      exchange(__int_type __i,
        memory_order __m = memory_order_seq_cst) noexcept
      {
 return __atomic_exchange_n(&_M_i, __i, int(__m));
      }
      inline __attribute__((__always_inline__)) __int_type
      exchange(__int_type __i,
        memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return __atomic_exchange_n(&_M_i, __i, int(__m));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_weak(__int_type& __i1, __int_type __i2,
       memory_order __m1, memory_order __m2) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_i, &__i1, __i2, 1,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_weak(__int_type& __i1, __int_type __i2,
       memory_order __m1,
       memory_order __m2) volatile noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_i, &__i1, __i2, 1,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_weak(__int_type& __i1, __int_type __i2,
       memory_order __m = memory_order_seq_cst) noexcept
      {
 return compare_exchange_weak(__i1, __i2, __m,
         __cmpexch_failure_order(__m));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_weak(__int_type& __i1, __int_type __i2,
     memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return compare_exchange_weak(__i1, __i2, __m,
         __cmpexch_failure_order(__m));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_strong(__int_type& __i1, __int_type __i2,
         memory_order __m1, memory_order __m2) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_i, &__i1, __i2, 0,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_strong(__int_type& __i1, __int_type __i2,
         memory_order __m1,
         memory_order __m2) volatile noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_i, &__i1, __i2, 0,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_strong(__int_type& __i1, __int_type __i2,
         memory_order __m = memory_order_seq_cst) noexcept
      {
 return compare_exchange_strong(__i1, __i2, __m,
           __cmpexch_failure_order(__m));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_strong(__int_type& __i1, __int_type __i2,
   memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return compare_exchange_strong(__i1, __i2, __m,
           __cmpexch_failure_order(__m));
      }
      inline __attribute__((__always_inline__)) __int_type
      fetch_add(__int_type __i,
  memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_add(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_add(__int_type __i,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_add(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_sub(__int_type __i,
  memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_sub(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_sub(__int_type __i,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_sub(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_and(__int_type __i,
  memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_and(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_and(__int_type __i,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_and(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_or(__int_type __i,
        memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_or(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_or(__int_type __i,
        memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_or(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_xor(__int_type __i,
  memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_xor(&_M_i, __i, int(__m)); }
      inline __attribute__((__always_inline__)) __int_type
      fetch_xor(__int_type __i,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_xor(&_M_i, __i, int(__m)); }
    };
  template<typename _PTp>
    struct __atomic_base<_PTp*>
    {
    private:
      typedef _PTp* __pointer_type;
      __pointer_type _M_p ;
      constexpr ptrdiff_t
      _M_type_size(ptrdiff_t __d) const { return __d * sizeof(_PTp); }
      constexpr ptrdiff_t
      _M_type_size(ptrdiff_t __d) const volatile { return __d * sizeof(_PTp); }
    public:
      __atomic_base() noexcept = default;
      ~__atomic_base() noexcept = default;
      __atomic_base(const __atomic_base&) = delete;
      __atomic_base& operator=(const __atomic_base&) = delete;
      __atomic_base& operator=(const __atomic_base&) volatile = delete;
      constexpr __atomic_base(__pointer_type __p) noexcept : _M_p (__p) { }
      operator __pointer_type() const noexcept
      { return load(); }
      operator __pointer_type() const volatile noexcept
      { return load(); }
      __pointer_type
      operator=(__pointer_type __p) noexcept
      {
 store(__p);
 return __p;
      }
      __pointer_type
      operator=(__pointer_type __p) volatile noexcept
      {
 store(__p);
 return __p;
      }
      __pointer_type
      operator++(int) noexcept
      { return fetch_add(1); }
      __pointer_type
      operator++(int) volatile noexcept
      { return fetch_add(1); }
      __pointer_type
      operator--(int) noexcept
      { return fetch_sub(1); }
      __pointer_type
      operator--(int) volatile noexcept
      { return fetch_sub(1); }
      __pointer_type
      operator++() noexcept
      { return __atomic_add_fetch(&_M_p, _M_type_size(1),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator++() volatile noexcept
      { return __atomic_add_fetch(&_M_p, _M_type_size(1),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator--() noexcept
      { return __atomic_sub_fetch(&_M_p, _M_type_size(1),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator--() volatile noexcept
      { return __atomic_sub_fetch(&_M_p, _M_type_size(1),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator+=(ptrdiff_t __d) noexcept
      { return __atomic_add_fetch(&_M_p, _M_type_size(__d),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator+=(ptrdiff_t __d) volatile noexcept
      { return __atomic_add_fetch(&_M_p, _M_type_size(__d),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator-=(ptrdiff_t __d) noexcept
      { return __atomic_sub_fetch(&_M_p, _M_type_size(__d),
      int(memory_order_seq_cst)); }
      __pointer_type
      operator-=(ptrdiff_t __d) volatile noexcept
      { return __atomic_sub_fetch(&_M_p, _M_type_size(__d),
      int(memory_order_seq_cst)); }
      bool
      is_lock_free() const noexcept
      {
 return __atomic_is_lock_free(sizeof(_M_p),
     reinterpret_cast<void *>(-__alignof(_M_p)));
      }
      bool
      is_lock_free() const volatile noexcept
      {
 return __atomic_is_lock_free(sizeof(_M_p),
     reinterpret_cast<void *>(-__alignof(_M_p)));
      }
      inline __attribute__((__always_inline__)) void
      store(__pointer_type __p,
     memory_order __m = memory_order_seq_cst) noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acquire)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_consume)) __builtin_unreachable(); } while (false);
 __atomic_store_n(&_M_p, __p, int(__m));
      }
      inline __attribute__((__always_inline__)) void
      store(__pointer_type __p,
     memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acquire)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_consume)) __builtin_unreachable(); } while (false);
 __atomic_store_n(&_M_p, __p, int(__m));
      }
      inline __attribute__((__always_inline__)) __pointer_type
      load(memory_order __m = memory_order_seq_cst) const noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_release)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 return __atomic_load_n(&_M_p, int(__m));
      }
      inline __attribute__((__always_inline__)) __pointer_type
      load(memory_order __m = memory_order_seq_cst) const volatile noexcept
      {
 memory_order __b __attribute__ ((__unused__))
   = __m & __memory_order_mask;
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_release)) __builtin_unreachable(); } while (false);
 do { if (std::__is_constant_evaluated() && !bool(__b != memory_order_acq_rel)) __builtin_unreachable(); } while (false);
 return __atomic_load_n(&_M_p, int(__m));
      }
      inline __attribute__((__always_inline__)) __pointer_type
      exchange(__pointer_type __p,
        memory_order __m = memory_order_seq_cst) noexcept
      {
 return __atomic_exchange_n(&_M_p, __p, int(__m));
      }
      inline __attribute__((__always_inline__)) __pointer_type
      exchange(__pointer_type __p,
        memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return __atomic_exchange_n(&_M_p, __p, int(__m));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_weak(__pointer_type& __p1, __pointer_type __p2,
       memory_order __m1,
       memory_order __m2) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_p, &__p1, __p2, 1,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_weak(__pointer_type& __p1, __pointer_type __p2,
       memory_order __m1,
       memory_order __m2) volatile noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_p, &__p1, __p2, 1,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_strong(__pointer_type& __p1, __pointer_type __p2,
         memory_order __m1,
         memory_order __m2) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_p, &__p1, __p2, 0,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) bool
      compare_exchange_strong(__pointer_type& __p1, __pointer_type __p2,
         memory_order __m1,
         memory_order __m2) volatile noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__m2))) __builtin_unreachable(); } while (false);
 return __atomic_compare_exchange_n(&_M_p, &__p1, __p2, 0,
        int(__m1), int(__m2));
      }
      inline __attribute__((__always_inline__)) __pointer_type
      fetch_add(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_add(&_M_p, _M_type_size(__d), int(__m)); }
      inline __attribute__((__always_inline__)) __pointer_type
      fetch_add(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_add(&_M_p, _M_type_size(__d), int(__m)); }
      inline __attribute__((__always_inline__)) __pointer_type
      fetch_sub(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_sub(&_M_p, _M_type_size(__d), int(__m)); }
      inline __attribute__((__always_inline__)) __pointer_type
      fetch_sub(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      { return __atomic_fetch_sub(&_M_p, _M_type_size(__d), int(__m)); }
    };
  namespace __atomic_impl
  {
    template<typename _Tp>
      constexpr bool
      __maybe_has_padding()
      {
 return !__has_unique_object_representations(_Tp)
   && !is_same<_Tp, float>::value && !is_same<_Tp, double>::value;
      }
    template<typename _Tp>
      inline __attribute__((__always_inline__)) _Tp*
      __clear_padding(_Tp& __val) noexcept
      {
 auto* __ptr = std::__addressof(__val);
 if (__atomic_impl::__maybe_has_padding<_Tp>())
   __builtin_clear_padding(__ptr);
 return __ptr;
      }
    template<typename _Tp>
      using _Val = typename remove_volatile<_Tp>::type;
    template<typename _Tp>
      inline __attribute__((__always_inline__)) bool
      __compare_exchange(_Tp& __val, _Val<_Tp>& __e, _Val<_Tp>& __i,
    bool __is_weak,
    memory_order __s, memory_order __f) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(__is_valid_cmpexch_failure_order(__f))) __builtin_unreachable(); } while (false);
 using _Vp = _Val<_Tp>;
 if (__atomic_impl::__maybe_has_padding<_Vp>())
   {
     alignas(_Vp) unsigned char __buf[sizeof(_Vp)];
     _Vp* __exp = ::new((void*)__buf) _Vp(__e);
     __atomic_impl::__clear_padding(*__exp);
     if (__atomic_compare_exchange(std::__addressof(__val), __exp,
       __atomic_impl::__clear_padding(__i),
       __is_weak, int(__s), int(__f)))
       return true;
     __builtin_memcpy(std::__addressof(__e), __exp, sizeof(_Vp));
     return false;
   }
 else
   return __atomic_compare_exchange(std::__addressof(__val),
        std::__addressof(__e),
        std::__addressof(__i),
        __is_weak, int(__s), int(__f));
      }
  }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp>
    struct atomic;
  template<>
  struct atomic<bool>
  {
    using value_type = bool;
  private:
    __atomic_base<bool> _M_base;
  public:
    atomic() noexcept = default;
    ~atomic() noexcept = default;
    atomic(const atomic&) = delete;
    atomic& operator=(const atomic&) = delete;
    atomic& operator=(const atomic&) volatile = delete;
    constexpr atomic(bool __i) noexcept : _M_base(__i) { }
    bool
    operator=(bool __i) noexcept
    { return _M_base.operator=(__i); }
    bool
    operator=(bool __i) volatile noexcept
    { return _M_base.operator=(__i); }
    operator bool() const noexcept
    { return _M_base.load(); }
    operator bool() const volatile noexcept
    { return _M_base.load(); }
    bool
    is_lock_free() const noexcept { return _M_base.is_lock_free(); }
    bool
    is_lock_free() const volatile noexcept { return _M_base.is_lock_free(); }
    void
    store(bool __i, memory_order __m = memory_order_seq_cst) noexcept
    { _M_base.store(__i, __m); }
    void
    store(bool __i, memory_order __m = memory_order_seq_cst) volatile noexcept
    { _M_base.store(__i, __m); }
    bool
    load(memory_order __m = memory_order_seq_cst) const noexcept
    { return _M_base.load(__m); }
    bool
    load(memory_order __m = memory_order_seq_cst) const volatile noexcept
    { return _M_base.load(__m); }
    bool
    exchange(bool __i, memory_order __m = memory_order_seq_cst) noexcept
    { return _M_base.exchange(__i, __m); }
    bool
    exchange(bool __i,
      memory_order __m = memory_order_seq_cst) volatile noexcept
    { return _M_base.exchange(__i, __m); }
    bool
    compare_exchange_weak(bool& __i1, bool __i2, memory_order __m1,
     memory_order __m2) noexcept
    { return _M_base.compare_exchange_weak(__i1, __i2, __m1, __m2); }
    bool
    compare_exchange_weak(bool& __i1, bool __i2, memory_order __m1,
     memory_order __m2) volatile noexcept
    { return _M_base.compare_exchange_weak(__i1, __i2, __m1, __m2); }
    bool
    compare_exchange_weak(bool& __i1, bool __i2,
     memory_order __m = memory_order_seq_cst) noexcept
    { return _M_base.compare_exchange_weak(__i1, __i2, __m); }
    bool
    compare_exchange_weak(bool& __i1, bool __i2,
       memory_order __m = memory_order_seq_cst) volatile noexcept
    { return _M_base.compare_exchange_weak(__i1, __i2, __m); }
    bool
    compare_exchange_strong(bool& __i1, bool __i2, memory_order __m1,
       memory_order __m2) noexcept
    { return _M_base.compare_exchange_strong(__i1, __i2, __m1, __m2); }
    bool
    compare_exchange_strong(bool& __i1, bool __i2, memory_order __m1,
       memory_order __m2) volatile noexcept
    { return _M_base.compare_exchange_strong(__i1, __i2, __m1, __m2); }
    bool
    compare_exchange_strong(bool& __i1, bool __i2,
       memory_order __m = memory_order_seq_cst) noexcept
    { return _M_base.compare_exchange_strong(__i1, __i2, __m); }
    bool
    compare_exchange_strong(bool& __i1, bool __i2,
      memory_order __m = memory_order_seq_cst) volatile noexcept
    { return _M_base.compare_exchange_strong(__i1, __i2, __m); }
  };
  template<typename _Tp>
    struct atomic
    {
      using value_type = _Tp;
    private:
      static constexpr int _S_min_alignment
 = (sizeof(_Tp) & (sizeof(_Tp) - 1)) || sizeof(_Tp) > 16
 ? 0 : sizeof(_Tp);
      static constexpr int _S_alignment
        = _S_min_alignment > alignof(_Tp) ? _S_min_alignment : alignof(_Tp);
      alignas(_S_alignment) _Tp _M_i ;
      static_assert(__is_trivially_copyable(_Tp),
      "std::atomic requires a trivially copyable type");
      static_assert(sizeof(_Tp) > 0,
      "Incomplete or zero-sized types are not supported");
    public:
      atomic() = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(_Tp __i) noexcept : _M_i(__i)
      {
      }
      operator _Tp() const noexcept
      { return load(); }
      operator _Tp() const volatile noexcept
      { return load(); }
      _Tp
      operator=(_Tp __i) noexcept
      { store(__i); return __i; }
      _Tp
      operator=(_Tp __i) volatile noexcept
      { store(__i); return __i; }
      bool
      is_lock_free() const noexcept
      {
 return __atomic_is_lock_free(sizeof(_M_i),
     reinterpret_cast<void *>(-_S_alignment));
      }
      bool
      is_lock_free() const volatile noexcept
      {
 return __atomic_is_lock_free(sizeof(_M_i),
     reinterpret_cast<void *>(-_S_alignment));
      }
      void
      store(_Tp __i, memory_order __m = memory_order_seq_cst) noexcept
      {
 __atomic_store(std::__addressof(_M_i),
         __atomic_impl::__clear_padding(__i),
         int(__m));
      }
      void
      store(_Tp __i, memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 __atomic_store(std::__addressof(_M_i),
         __atomic_impl::__clear_padding(__i),
         int(__m));
      }
      _Tp
      load(memory_order __m = memory_order_seq_cst) const noexcept
      {
 alignas(_Tp) unsigned char __buf[sizeof(_Tp)];
 _Tp* __ptr = reinterpret_cast<_Tp*>(__buf);
 __atomic_load(std::__addressof(_M_i), __ptr, int(__m));
 return *__ptr;
      }
      _Tp
      load(memory_order __m = memory_order_seq_cst) const volatile noexcept
      {
        alignas(_Tp) unsigned char __buf[sizeof(_Tp)];
 _Tp* __ptr = reinterpret_cast<_Tp*>(__buf);
 __atomic_load(std::__addressof(_M_i), __ptr, int(__m));
 return *__ptr;
      }
      _Tp
      exchange(_Tp __i, memory_order __m = memory_order_seq_cst) noexcept
      {
        alignas(_Tp) unsigned char __buf[sizeof(_Tp)];
 _Tp* __ptr = reinterpret_cast<_Tp*>(__buf);
 __atomic_exchange(std::__addressof(_M_i),
     __atomic_impl::__clear_padding(__i),
     __ptr, int(__m));
 return *__ptr;
      }
      _Tp
      exchange(_Tp __i,
        memory_order __m = memory_order_seq_cst) volatile noexcept
      {
        alignas(_Tp) unsigned char __buf[sizeof(_Tp)];
 _Tp* __ptr = reinterpret_cast<_Tp*>(__buf);
 __atomic_exchange(std::__addressof(_M_i),
     __atomic_impl::__clear_padding(__i),
     __ptr, int(__m));
 return *__ptr;
      }
      bool
      compare_exchange_weak(_Tp& __e, _Tp __i, memory_order __s,
       memory_order __f) noexcept
      {
 return __atomic_impl::__compare_exchange(_M_i, __e, __i, true,
       __s, __f);
      }
      bool
      compare_exchange_weak(_Tp& __e, _Tp __i, memory_order __s,
       memory_order __f) volatile noexcept
      {
 return __atomic_impl::__compare_exchange(_M_i, __e, __i, true,
       __s, __f);
      }
      bool
      compare_exchange_weak(_Tp& __e, _Tp __i,
       memory_order __m = memory_order_seq_cst) noexcept
      { return compare_exchange_weak(__e, __i, __m,
                                     __cmpexch_failure_order(__m)); }
      bool
      compare_exchange_weak(_Tp& __e, _Tp __i,
       memory_order __m = memory_order_seq_cst) volatile noexcept
      { return compare_exchange_weak(__e, __i, __m,
                                     __cmpexch_failure_order(__m)); }
      bool
      compare_exchange_strong(_Tp& __e, _Tp __i, memory_order __s,
         memory_order __f) noexcept
      {
 return __atomic_impl::__compare_exchange(_M_i, __e, __i, false,
       __s, __f);
      }
      bool
      compare_exchange_strong(_Tp& __e, _Tp __i, memory_order __s,
         memory_order __f) volatile noexcept
      {
 return __atomic_impl::__compare_exchange(_M_i, __e, __i, false,
       __s, __f);
      }
      bool
      compare_exchange_strong(_Tp& __e, _Tp __i,
          memory_order __m = memory_order_seq_cst) noexcept
      { return compare_exchange_strong(__e, __i, __m,
                                       __cmpexch_failure_order(__m)); }
      bool
      compare_exchange_strong(_Tp& __e, _Tp __i,
       memory_order __m = memory_order_seq_cst) volatile noexcept
      { return compare_exchange_strong(__e, __i, __m,
                                       __cmpexch_failure_order(__m)); }
    };
  template<typename _Tp>
    struct atomic<_Tp*>
    {
      using value_type = _Tp*;
      using difference_type = ptrdiff_t;
      typedef _Tp* __pointer_type;
      typedef __atomic_base<_Tp*> __base_type;
      __base_type _M_b;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__pointer_type __p) noexcept : _M_b(__p) { }
      operator __pointer_type() const noexcept
      { return __pointer_type(_M_b); }
      operator __pointer_type() const volatile noexcept
      { return __pointer_type(_M_b); }
      __pointer_type
      operator=(__pointer_type __p) noexcept
      { return _M_b.operator=(__p); }
      __pointer_type
      operator=(__pointer_type __p) volatile noexcept
      { return _M_b.operator=(__p); }
      __pointer_type
      operator++(int) noexcept
      {
 return _M_b++;
      }
      __pointer_type
      operator++(int) volatile noexcept
      {
 return _M_b++;
      }
      __pointer_type
      operator--(int) noexcept
      {
 return _M_b--;
      }
      __pointer_type
      operator--(int) volatile noexcept
      {
 return _M_b--;
      }
      __pointer_type
      operator++() noexcept
      {
 return ++_M_b;
      }
      __pointer_type
      operator++() volatile noexcept
      {
 return ++_M_b;
      }
      __pointer_type
      operator--() noexcept
      {
 return --_M_b;
      }
      __pointer_type
      operator--() volatile noexcept
      {
 return --_M_b;
      }
      __pointer_type
      operator+=(ptrdiff_t __d) noexcept
      {
 return _M_b.operator+=(__d);
      }
      __pointer_type
      operator+=(ptrdiff_t __d) volatile noexcept
      {
 return _M_b.operator+=(__d);
      }
      __pointer_type
      operator-=(ptrdiff_t __d) noexcept
      {
 return _M_b.operator-=(__d);
      }
      __pointer_type
      operator-=(ptrdiff_t __d) volatile noexcept
      {
 return _M_b.operator-=(__d);
      }
      bool
      is_lock_free() const noexcept
      { return _M_b.is_lock_free(); }
      bool
      is_lock_free() const volatile noexcept
      { return _M_b.is_lock_free(); }
      void
      store(__pointer_type __p,
     memory_order __m = memory_order_seq_cst) noexcept
      { return _M_b.store(__p, __m); }
      void
      store(__pointer_type __p,
     memory_order __m = memory_order_seq_cst) volatile noexcept
      { return _M_b.store(__p, __m); }
      __pointer_type
      load(memory_order __m = memory_order_seq_cst) const noexcept
      { return _M_b.load(__m); }
      __pointer_type
      load(memory_order __m = memory_order_seq_cst) const volatile noexcept
      { return _M_b.load(__m); }
      __pointer_type
      exchange(__pointer_type __p,
        memory_order __m = memory_order_seq_cst) noexcept
      { return _M_b.exchange(__p, __m); }
      __pointer_type
      exchange(__pointer_type __p,
        memory_order __m = memory_order_seq_cst) volatile noexcept
      { return _M_b.exchange(__p, __m); }
      bool
      compare_exchange_weak(__pointer_type& __p1, __pointer_type __p2,
       memory_order __m1, memory_order __m2) noexcept
      { return _M_b.compare_exchange_weak(__p1, __p2, __m1, __m2); }
      bool
      compare_exchange_weak(__pointer_type& __p1, __pointer_type __p2,
       memory_order __m1,
       memory_order __m2) volatile noexcept
      { return _M_b.compare_exchange_weak(__p1, __p2, __m1, __m2); }
      bool
      compare_exchange_weak(__pointer_type& __p1, __pointer_type __p2,
       memory_order __m = memory_order_seq_cst) noexcept
      {
 return compare_exchange_weak(__p1, __p2, __m,
         __cmpexch_failure_order(__m));
      }
      bool
      compare_exchange_weak(__pointer_type& __p1, __pointer_type __p2,
      memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return compare_exchange_weak(__p1, __p2, __m,
         __cmpexch_failure_order(__m));
      }
      bool
      compare_exchange_strong(__pointer_type& __p1, __pointer_type __p2,
         memory_order __m1, memory_order __m2) noexcept
      { return _M_b.compare_exchange_strong(__p1, __p2, __m1, __m2); }
      bool
      compare_exchange_strong(__pointer_type& __p1, __pointer_type __p2,
         memory_order __m1,
         memory_order __m2) volatile noexcept
      { return _M_b.compare_exchange_strong(__p1, __p2, __m1, __m2); }
      bool
      compare_exchange_strong(__pointer_type& __p1, __pointer_type __p2,
         memory_order __m = memory_order_seq_cst) noexcept
      {
 return _M_b.compare_exchange_strong(__p1, __p2, __m,
         __cmpexch_failure_order(__m));
      }
      bool
      compare_exchange_strong(__pointer_type& __p1, __pointer_type __p2,
      memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return _M_b.compare_exchange_strong(__p1, __p2, __m,
         __cmpexch_failure_order(__m));
      }
      __pointer_type
      fetch_add(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) noexcept
      {
 return _M_b.fetch_add(__d, __m);
      }
      __pointer_type
      fetch_add(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return _M_b.fetch_add(__d, __m);
      }
      __pointer_type
      fetch_sub(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) noexcept
      {
 return _M_b.fetch_sub(__d, __m);
      }
      __pointer_type
      fetch_sub(ptrdiff_t __d,
  memory_order __m = memory_order_seq_cst) volatile noexcept
      {
 return _M_b.fetch_sub(__d, __m);
      }
    };
  template<>
    struct atomic<char> : __atomic_base<char>
    {
      typedef char __integral_type;
      typedef __atomic_base<char> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<signed char> : __atomic_base<signed char>
    {
      typedef signed char __integral_type;
      typedef __atomic_base<signed char> __base_type;
      atomic() noexcept= default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<unsigned char> : __atomic_base<unsigned char>
    {
      typedef unsigned char __integral_type;
      typedef __atomic_base<unsigned char> __base_type;
      atomic() noexcept= default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<short> : __atomic_base<short>
    {
      typedef short __integral_type;
      typedef __atomic_base<short> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<unsigned short> : __atomic_base<unsigned short>
    {
      typedef unsigned short __integral_type;
      typedef __atomic_base<unsigned short> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<int> : __atomic_base<int>
    {
      typedef int __integral_type;
      typedef __atomic_base<int> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<unsigned int> : __atomic_base<unsigned int>
    {
      typedef unsigned int __integral_type;
      typedef __atomic_base<unsigned int> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<long> : __atomic_base<long>
    {
      typedef long __integral_type;
      typedef __atomic_base<long> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<unsigned long> : __atomic_base<unsigned long>
    {
      typedef unsigned long __integral_type;
      typedef __atomic_base<unsigned long> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<long long> : __atomic_base<long long>
    {
      typedef long long __integral_type;
      typedef __atomic_base<long long> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<unsigned long long> : __atomic_base<unsigned long long>
    {
      typedef unsigned long long __integral_type;
      typedef __atomic_base<unsigned long long> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<wchar_t> : __atomic_base<wchar_t>
    {
      typedef wchar_t __integral_type;
      typedef __atomic_base<wchar_t> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<char16_t> : __atomic_base<char16_t>
    {
      typedef char16_t __integral_type;
      typedef __atomic_base<char16_t> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  template<>
    struct atomic<char32_t> : __atomic_base<char32_t>
    {
      typedef char32_t __integral_type;
      typedef __atomic_base<char32_t> __base_type;
      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;
      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }
      using __base_type::operator __integral_type;
      using __base_type::operator=;
    };
  typedef atomic<bool> atomic_bool;
  typedef atomic<char> atomic_char;
  typedef atomic<signed char> atomic_schar;
  typedef atomic<unsigned char> atomic_uchar;
  typedef atomic<short> atomic_short;
  typedef atomic<unsigned short> atomic_ushort;
  typedef atomic<int> atomic_int;
  typedef atomic<unsigned int> atomic_uint;
  typedef atomic<long> atomic_long;
  typedef atomic<unsigned long> atomic_ulong;
  typedef atomic<long long> atomic_llong;
  typedef atomic<unsigned long long> atomic_ullong;
  typedef atomic<wchar_t> atomic_wchar_t;
  typedef atomic<char16_t> atomic_char16_t;
  typedef atomic<char32_t> atomic_char32_t;
  typedef atomic<int8_t> atomic_int8_t;
  typedef atomic<uint8_t> atomic_uint8_t;
  typedef atomic<int16_t> atomic_int16_t;
  typedef atomic<uint16_t> atomic_uint16_t;
  typedef atomic<int32_t> atomic_int32_t;
  typedef atomic<uint32_t> atomic_uint32_t;
  typedef atomic<int64_t> atomic_int64_t;
  typedef atomic<uint64_t> atomic_uint64_t;
  typedef atomic<int_least8_t> atomic_int_least8_t;
  typedef atomic<uint_least8_t> atomic_uint_least8_t;
  typedef atomic<int_least16_t> atomic_int_least16_t;
  typedef atomic<uint_least16_t> atomic_uint_least16_t;
  typedef atomic<int_least32_t> atomic_int_least32_t;
  typedef atomic<uint_least32_t> atomic_uint_least32_t;
  typedef atomic<int_least64_t> atomic_int_least64_t;
  typedef atomic<uint_least64_t> atomic_uint_least64_t;
  typedef atomic<int_fast8_t> atomic_int_fast8_t;
  typedef atomic<uint_fast8_t> atomic_uint_fast8_t;
  typedef atomic<int_fast16_t> atomic_int_fast16_t;
  typedef atomic<uint_fast16_t> atomic_uint_fast16_t;
  typedef atomic<int_fast32_t> atomic_int_fast32_t;
  typedef atomic<uint_fast32_t> atomic_uint_fast32_t;
  typedef atomic<int_fast64_t> atomic_int_fast64_t;
  typedef atomic<uint_fast64_t> atomic_uint_fast64_t;
  typedef atomic<intptr_t> atomic_intptr_t;
  typedef atomic<uintptr_t> atomic_uintptr_t;
  typedef atomic<size_t> atomic_size_t;
  typedef atomic<ptrdiff_t> atomic_ptrdiff_t;
  typedef atomic<intmax_t> atomic_intmax_t;
  typedef atomic<uintmax_t> atomic_uintmax_t;
  inline bool
  atomic_flag_test_and_set_explicit(atomic_flag* __a,
        memory_order __m) noexcept
  { return __a->test_and_set(__m); }
  inline bool
  atomic_flag_test_and_set_explicit(volatile atomic_flag* __a,
        memory_order __m) noexcept
  { return __a->test_and_set(__m); }
  inline void
  atomic_flag_clear_explicit(atomic_flag* __a, memory_order __m) noexcept
  { __a->clear(__m); }
  inline void
  atomic_flag_clear_explicit(volatile atomic_flag* __a,
        memory_order __m) noexcept
  { __a->clear(__m); }
  inline bool
  atomic_flag_test_and_set(atomic_flag* __a) noexcept
  { return atomic_flag_test_and_set_explicit(__a, memory_order_seq_cst); }
  inline bool
  atomic_flag_test_and_set(volatile atomic_flag* __a) noexcept
  { return atomic_flag_test_and_set_explicit(__a, memory_order_seq_cst); }
  inline void
  atomic_flag_clear(atomic_flag* __a) noexcept
  { atomic_flag_clear_explicit(__a, memory_order_seq_cst); }
  inline void
  atomic_flag_clear(volatile atomic_flag* __a) noexcept
  { atomic_flag_clear_explicit(__a, memory_order_seq_cst); }
  template<typename _Tp>
    using __atomic_val_t = __type_identity_t<_Tp>;
  template<typename _Tp>
    using __atomic_diff_t = typename atomic<_Tp>::difference_type;
  template<typename _ITp>
    inline bool
    atomic_is_lock_free(const atomic<_ITp>* __a) noexcept
    { return __a->is_lock_free(); }
  template<typename _ITp>
    inline bool
    atomic_is_lock_free(const volatile atomic<_ITp>* __a) noexcept
    { return __a->is_lock_free(); }
  template<typename _ITp>
    inline void
    atomic_init(atomic<_ITp>* __a, __atomic_val_t<_ITp> __i) noexcept
    { __a->store(__i, memory_order_relaxed); }
  template<typename _ITp>
    inline void
    atomic_init(volatile atomic<_ITp>* __a, __atomic_val_t<_ITp> __i) noexcept
    { __a->store(__i, memory_order_relaxed); }
  template<typename _ITp>
    inline void
    atomic_store_explicit(atomic<_ITp>* __a, __atomic_val_t<_ITp> __i,
     memory_order __m) noexcept
    { __a->store(__i, __m); }
  template<typename _ITp>
    inline void
    atomic_store_explicit(volatile atomic<_ITp>* __a, __atomic_val_t<_ITp> __i,
     memory_order __m) noexcept
    { __a->store(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_load_explicit(const atomic<_ITp>* __a, memory_order __m) noexcept
    { return __a->load(__m); }
  template<typename _ITp>
    inline _ITp
    atomic_load_explicit(const volatile atomic<_ITp>* __a,
    memory_order __m) noexcept
    { return __a->load(__m); }
  template<typename _ITp>
    inline _ITp
    atomic_exchange_explicit(atomic<_ITp>* __a, __atomic_val_t<_ITp> __i,
        memory_order __m) noexcept
    { return __a->exchange(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_exchange_explicit(volatile atomic<_ITp>* __a,
        __atomic_val_t<_ITp> __i,
        memory_order __m) noexcept
    { return __a->exchange(__i, __m); }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_weak_explicit(atomic<_ITp>* __a,
       __atomic_val_t<_ITp>* __i1,
       __atomic_val_t<_ITp> __i2,
       memory_order __m1,
       memory_order __m2) noexcept
    { return __a->compare_exchange_weak(*__i1, __i2, __m1, __m2); }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_weak_explicit(volatile atomic<_ITp>* __a,
       __atomic_val_t<_ITp>* __i1,
       __atomic_val_t<_ITp> __i2,
       memory_order __m1,
       memory_order __m2) noexcept
    { return __a->compare_exchange_weak(*__i1, __i2, __m1, __m2); }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_strong_explicit(atomic<_ITp>* __a,
         __atomic_val_t<_ITp>* __i1,
         __atomic_val_t<_ITp> __i2,
         memory_order __m1,
         memory_order __m2) noexcept
    { return __a->compare_exchange_strong(*__i1, __i2, __m1, __m2); }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_strong_explicit(volatile atomic<_ITp>* __a,
         __atomic_val_t<_ITp>* __i1,
         __atomic_val_t<_ITp> __i2,
         memory_order __m1,
         memory_order __m2) noexcept
    { return __a->compare_exchange_strong(*__i1, __i2, __m1, __m2); }
  template<typename _ITp>
    inline void
    atomic_store(atomic<_ITp>* __a, __atomic_val_t<_ITp> __i) noexcept
    { atomic_store_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline void
    atomic_store(volatile atomic<_ITp>* __a, __atomic_val_t<_ITp> __i) noexcept
    { atomic_store_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_load(const atomic<_ITp>* __a) noexcept
    { return atomic_load_explicit(__a, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_load(const volatile atomic<_ITp>* __a) noexcept
    { return atomic_load_explicit(__a, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_exchange(atomic<_ITp>* __a, __atomic_val_t<_ITp> __i) noexcept
    { return atomic_exchange_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_exchange(volatile atomic<_ITp>* __a,
      __atomic_val_t<_ITp> __i) noexcept
    { return atomic_exchange_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_weak(atomic<_ITp>* __a,
     __atomic_val_t<_ITp>* __i1,
     __atomic_val_t<_ITp> __i2) noexcept
    {
      return atomic_compare_exchange_weak_explicit(__a, __i1, __i2,
         memory_order_seq_cst,
         memory_order_seq_cst);
    }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_weak(volatile atomic<_ITp>* __a,
     __atomic_val_t<_ITp>* __i1,
     __atomic_val_t<_ITp> __i2) noexcept
    {
      return atomic_compare_exchange_weak_explicit(__a, __i1, __i2,
         memory_order_seq_cst,
         memory_order_seq_cst);
    }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_strong(atomic<_ITp>* __a,
       __atomic_val_t<_ITp>* __i1,
       __atomic_val_t<_ITp> __i2) noexcept
    {
      return atomic_compare_exchange_strong_explicit(__a, __i1, __i2,
           memory_order_seq_cst,
           memory_order_seq_cst);
    }
  template<typename _ITp>
    inline bool
    atomic_compare_exchange_strong(volatile atomic<_ITp>* __a,
       __atomic_val_t<_ITp>* __i1,
       __atomic_val_t<_ITp> __i2) noexcept
    {
      return atomic_compare_exchange_strong_explicit(__a, __i1, __i2,
           memory_order_seq_cst,
           memory_order_seq_cst);
    }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_add_explicit(atomic<_ITp>* __a,
         __atomic_diff_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_add(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_add_explicit(volatile atomic<_ITp>* __a,
         __atomic_diff_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_add(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_sub_explicit(atomic<_ITp>* __a,
         __atomic_diff_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_sub(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_sub_explicit(volatile atomic<_ITp>* __a,
         __atomic_diff_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_sub(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_and_explicit(__atomic_base<_ITp>* __a,
         __atomic_val_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_and(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_and_explicit(volatile __atomic_base<_ITp>* __a,
         __atomic_val_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_and(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_or_explicit(__atomic_base<_ITp>* __a,
        __atomic_val_t<_ITp> __i,
        memory_order __m) noexcept
    { return __a->fetch_or(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_or_explicit(volatile __atomic_base<_ITp>* __a,
        __atomic_val_t<_ITp> __i,
        memory_order __m) noexcept
    { return __a->fetch_or(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_xor_explicit(__atomic_base<_ITp>* __a,
         __atomic_val_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_xor(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_xor_explicit(volatile __atomic_base<_ITp>* __a,
         __atomic_val_t<_ITp> __i,
         memory_order __m) noexcept
    { return __a->fetch_xor(__i, __m); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_add(atomic<_ITp>* __a,
       __atomic_diff_t<_ITp> __i) noexcept
    { return atomic_fetch_add_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_add(volatile atomic<_ITp>* __a,
       __atomic_diff_t<_ITp> __i) noexcept
    { return atomic_fetch_add_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_sub(atomic<_ITp>* __a,
       __atomic_diff_t<_ITp> __i) noexcept
    { return atomic_fetch_sub_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_sub(volatile atomic<_ITp>* __a,
       __atomic_diff_t<_ITp> __i) noexcept
    { return atomic_fetch_sub_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_and(__atomic_base<_ITp>* __a,
       __atomic_val_t<_ITp> __i) noexcept
    { return atomic_fetch_and_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_and(volatile __atomic_base<_ITp>* __a,
       __atomic_val_t<_ITp> __i) noexcept
    { return atomic_fetch_and_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_or(__atomic_base<_ITp>* __a,
      __atomic_val_t<_ITp> __i) noexcept
    { return atomic_fetch_or_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_or(volatile __atomic_base<_ITp>* __a,
      __atomic_val_t<_ITp> __i) noexcept
    { return atomic_fetch_or_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_xor(__atomic_base<_ITp>* __a,
       __atomic_val_t<_ITp> __i) noexcept
    { return atomic_fetch_xor_explicit(__a, __i, memory_order_seq_cst); }
  template<typename _ITp>
    inline _ITp
    atomic_fetch_xor(volatile __atomic_base<_ITp>* __a,
       __atomic_val_t<_ITp> __i) noexcept
    { return atomic_fetch_xor_explicit(__a, __i, memory_order_seq_cst); }

}
namespace hwy {
static constexpr __attribute__((unused)) size_t kMaxVectorSize = 64;
#pragma pack(push, 1)
struct float16_t {
  uint16_t bits;
};
struct bfloat16_t {
  uint16_t bits;
};
#pragma pack(pop)
using float32_t = float;
using float64_t = double;
#pragma pack(push, 1)
struct alignas(16) uint128_t {
  uint64_t lo;
  uint64_t hi;
};
struct alignas(16) K64V64 {
  uint64_t value;
  uint64_t key;
};
struct alignas(8) K32V32 {
  uint32_t value;
  uint32_t key;
};
#pragma pack(pop)
static inline __attribute__((unused)) bool operator<(const uint128_t& a,
                                              const uint128_t& b) {
  return (a.hi == b.hi) ? a.lo < b.lo : a.hi < b.hi;
}
static inline __attribute__((unused)) bool operator>(const uint128_t& a,
                                              const uint128_t& b) {
  return b < a;
}
static inline __attribute__((unused)) bool operator==(const uint128_t& a,
                                               const uint128_t& b) {
  return a.lo == b.lo && a.hi == b.hi;
}
static inline __attribute__((unused)) bool operator<(const K64V64& a,
                                              const K64V64& b) {
  return a.key < b.key;
}
static inline __attribute__((unused)) bool operator>(const K64V64& a,
                                              const K64V64& b) {
  return b < a;
}
static inline __attribute__((unused)) bool operator==(const K64V64& a,
                                               const K64V64& b) {
  return a.key == b.key;
}
static inline __attribute__((unused)) bool operator<(const K32V32& a,
                                              const K32V32& b) {
  return a.key < b.key;
}
static inline __attribute__((unused)) bool operator>(const K32V32& a,
                                              const K32V32& b) {
  return b < a;
}
static inline __attribute__((unused)) bool operator==(const K32V32& a,
                                               const K32V32& b) {
  return a.key == b.key;
}
template <bool Condition>
struct EnableIfT {};
template <>
struct EnableIfT<true> {
  using type = void;
};
template <bool Condition>
using EnableIf = typename EnableIfT<Condition>::type;
template <typename T, typename U>
struct IsSameT {
  enum { value = 0 };
};
template <typename T>
struct IsSameT<T, T> {
  enum { value = 1 };
};
template <typename T, typename U>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr bool IsSame() {
  return IsSameT<T, U>::value;
}
template <size_t N>
struct SizeTag {};
template <class T>
struct RemoveConstT {
  using type = T;
};
template <class T>
struct RemoveConstT<const T> {
  using type = T;
};
template <class T>
using RemoveConst = typename RemoveConstT<T>::type;
template <class T>
struct RemoveRefT {
  using type = T;
};
template <class T>
struct RemoveRefT<T&> {
  using type = T;
};
template <class T>
using RemoveRef = typename RemoveRefT<T>::type;
namespace detail {
template <typename T>
struct Relations;
template <>
struct Relations<uint8_t> {
  using Unsigned = uint8_t;
  using Signed = int8_t;
  using Wide = uint16_t;
  enum { is_signed = 0, is_float = 0 };
};
template <>
struct Relations<int8_t> {
  using Unsigned = uint8_t;
  using Signed = int8_t;
  using Wide = int16_t;
  enum { is_signed = 1, is_float = 0 };
};
template <>
struct Relations<uint16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Wide = uint32_t;
  using Narrow = uint8_t;
  enum { is_signed = 0, is_float = 0 };
};
template <>
struct Relations<int16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Wide = int32_t;
  using Narrow = int8_t;
  enum { is_signed = 1, is_float = 0 };
};
template <>
struct Relations<uint32_t> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
  using Wide = uint64_t;
  using Narrow = uint16_t;
  enum { is_signed = 0, is_float = 0 };
};
template <>
struct Relations<int32_t> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
  using Wide = int64_t;
  using Narrow = int16_t;
  enum { is_signed = 1, is_float = 0 };
};
template <>
struct Relations<uint64_t> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
  using Wide = uint128_t;
  using Narrow = uint32_t;
  enum { is_signed = 0, is_float = 0 };
};
template <>
struct Relations<int64_t> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
  using Narrow = int32_t;
  enum { is_signed = 1, is_float = 0 };
};
template <>
struct Relations<uint128_t> {
  using Unsigned = uint128_t;
  using Narrow = uint64_t;
  enum { is_signed = 0, is_float = 0 };
};
template <>
struct Relations<float16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Float = float16_t;
  using Wide = float;
  enum { is_signed = 1, is_float = 1 };
};
template <>
struct Relations<bfloat16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Wide = float;
  enum { is_signed = 1, is_float = 1 };
};
template <>
struct Relations<float> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
  using Wide = double;
  using Narrow = float16_t;
  enum { is_signed = 1, is_float = 1 };
};
template <>
struct Relations<double> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
  using Narrow = float;
  enum { is_signed = 1, is_float = 1 };
};
template <size_t N>
struct TypeFromSize;
template <>
struct TypeFromSize<1> {
  using Unsigned = uint8_t;
  using Signed = int8_t;
};
template <>
struct TypeFromSize<2> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
};
template <>
struct TypeFromSize<4> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
};
template <>
struct TypeFromSize<8> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
};
template <>
struct TypeFromSize<16> {
  using Unsigned = uint128_t;
};
}
template <typename T>
using MakeUnsigned = typename detail::Relations<T>::Unsigned;
template <typename T>
using MakeSigned = typename detail::Relations<T>::Signed;
template <typename T>
using MakeFloat = typename detail::Relations<T>::Float;
template <typename T>
using MakeWide = typename detail::Relations<T>::Wide;
template <typename T>
using MakeNarrow = typename detail::Relations<T>::Narrow;
template <size_t N>
using UnsignedFromSize = typename detail::TypeFromSize<N>::Unsigned;
template <size_t N>
using SignedFromSize = typename detail::TypeFromSize<N>::Signed;
template <size_t N>
using FloatFromSize = typename detail::TypeFromSize<N>::Float;
using UnsignedTag = SizeTag<0>;
using SignedTag = SizeTag<0x100>;
using FloatTag = SizeTag<0x200>;
template <typename T, class R = detail::Relations<T>>
constexpr auto TypeTag() -> hwy::SizeTag<((R::is_signed + R::is_float) << 8)> {
  return hwy::SizeTag<((R::is_signed + R::is_float) << 8)>();
}
using NonFloatTag = SizeTag<0x400>;
template <typename T, class R = detail::Relations<T>>
constexpr auto IsFloatTag() -> hwy::SizeTag<(R::is_float ? 0x200 : 0x400)> {
  return hwy::SizeTag<(R::is_float ? 0x200 : 0x400)>();
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr bool IsFloat() {
  return IsSame<T, float>() || IsSame<T, double>();
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr bool IsSpecialFloat() {
  return IsSame<T, float16_t>() || IsSame<T, bfloat16_t>();
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr bool IsSigned() {
  return T(0) > T(-1);
}
template <>
constexpr bool IsSigned<float16_t>() {
  return true;
}
template <>
constexpr bool IsSigned<bfloat16_t>() {
  return true;
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr T LimitsMax() {
  static_assert(!IsFloat<T>(), "Only for integer types");
  using TU = MakeUnsigned<T>;
  return static_cast<T>(IsSigned<T>() ? (static_cast<TU>(~0ull) >> 1)
                                      : static_cast<TU>(~0ull));
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr T LimitsMin() {
  static_assert(!IsFloat<T>(), "Only for integer types");
  return IsSigned<T>() ? T(-1) - LimitsMax<T>() : T(0);
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr T LowestValue() {
  return LimitsMin<T>();
}
template <>
constexpr float LowestValue<float>() {
  return -3.402823466e+38F;
}
template <>
constexpr double LowestValue<double>() {
  return -1.7976931348623158e+308;
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr T HighestValue() {
  return LimitsMax<T>();
}
template <>
constexpr float HighestValue<float>() {
  return 3.402823466e+38F;
}
template <>
constexpr double HighestValue<double>() {
  return 1.7976931348623158e+308;
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) constexpr T Epsilon() {
  return 1;
}
template <>
constexpr float Epsilon<float>() {
  return 1.192092896e-7f;
}
template <>
constexpr double Epsilon<double>() {
  return 2.2204460492503131e-16;
}
template <typename T>
constexpr int MantissaBits() {
  static_assert(sizeof(T) == 0, "Only instantiate the specializations");
  return 0;
}
template <>
constexpr int MantissaBits<float>() {
  return 23;
}
template <>
constexpr int MantissaBits<double>() {
  return 52;
}
template <typename T>
constexpr MakeSigned<T> MaxExponentTimes2() {
  return -(MakeSigned<T>{1} << (MantissaBits<T>() + 1));
}
template <typename T>
constexpr MakeUnsigned<T> SignMask() {
  return MakeUnsigned<T>{1} << (sizeof(T) * 8 - 1);
}
template <typename T>
constexpr MakeUnsigned<T> ExponentMask() {
  return (~(MakeUnsigned<T>{1} << MantissaBits<T>()) + 1) & ~SignMask<T>();
}
template <typename T>
constexpr MakeUnsigned<T> MantissaMask() {
  return (MakeUnsigned<T>{1} << MantissaBits<T>()) - 1;
}
template <typename T>
constexpr T MantissaEnd() {
  static_assert(sizeof(T) == 0, "Only instantiate the specializations");
  return 0;
}
template <>
constexpr float MantissaEnd<float>() {
  return 8388608.0f;
}
template <>
constexpr double MantissaEnd<double>() {
  return 4503599627370496.0;
}
template <typename T>
constexpr int ExponentBits() {
  return 8 * sizeof(T) - 1 - MantissaBits<T>();
}
template <typename T>
constexpr MakeSigned<T> MaxExponentField() {
  return (MakeSigned<T>{1} << ExponentBits<T>()) - 1;
}
template <typename T1, typename T2>
constexpr inline T1 DivCeil(T1 a, T2 b) {
  return (a + b - 1) / b;
}
constexpr inline size_t RoundUpTo(size_t what, size_t align) {
  return DivCeil(what, align) * align;
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t Num0BitsBelowLS1Bit_Nonzero32(const uint32_t x) {
  return static_cast<size_t>(__builtin_ctz(x));
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t Num0BitsBelowLS1Bit_Nonzero64(const uint64_t x) {
  return static_cast<size_t>(__builtin_ctzll(x));
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t Num0BitsAboveMS1Bit_Nonzero32(const uint32_t x) {
  return static_cast<size_t>(__builtin_clz(x));
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t Num0BitsAboveMS1Bit_Nonzero64(const uint64_t x) {
  return static_cast<size_t>(__builtin_clzll(x));
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t PopCount(uint64_t x) {
  return static_cast<size_t>(__builtin_popcountll(x));
}
template <typename TI>
            constexpr size_t FloorLog2(TI x) {
  return x == TI{1}
             ? 0
             : static_cast<size_t>(FloorLog2(static_cast<TI>(x >> 1)) + 1);
}
template <typename TI>
            constexpr size_t CeilLog2(TI x) {
  return x == TI{1}
             ? 0
             : static_cast<size_t>(FloorLog2(static_cast<TI>(x - 1)) + 1);
}
template <typename T>
inline __attribute__((always_inline)) constexpr T AddWithWraparound(hwy::FloatTag , T t, size_t n) {
  return t + static_cast<T>(n);
}
template <typename T>
inline __attribute__((always_inline)) constexpr T AddWithWraparound(hwy::NonFloatTag , T t,
                                         size_t n) {
  using TU = MakeUnsigned<T>;
  return static_cast<T>(
      static_cast<TU>(static_cast<TU>(t) + static_cast<TU>(n)) &
      hwy::LimitsMax<TU>());
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) uint64_t Mul128(uint64_t a, uint64_t b, uint64_t* __restrict__ upper) {
  constexpr uint64_t kLo32 = 0xFFFFFFFFU;
  const uint64_t lo_lo = (a & kLo32) * (b & kLo32);
  const uint64_t hi_lo = (a >> 32) * (b & kLo32);
  const uint64_t lo_hi = (a & kLo32) * (b >> 32);
  const uint64_t hi_hi = (a >> 32) * (b >> 32);
  const uint64_t t = (lo_lo >> 32) + (hi_lo & kLo32) + lo_hi;
  *upper = (hi_lo >> 32) + (t >> 32) + hi_hi;
  return (t << 32) | (lo_lo & kLo32);
}
template <size_t kBytes, typename From, typename To>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void CopyBytes(const From* from, To* to) {
  __builtin_memcpy(
      static_cast<void*>(to), static_cast<const void*>(from), kBytes);
}
template <typename From, typename To>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void CopySameSize(const From* __restrict__ from, To* __restrict__ to) {
  static_assert(sizeof(From) == sizeof(To), "");
  CopyBytes<sizeof(From)>(from, to);
}
template <size_t kBytes, typename To>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void ZeroBytes(To* to) {
  __builtin_memset(to, 0, kBytes);
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) float F32FromBF16(bfloat16_t bf) {
  uint32_t bits = bf.bits;
  bits <<= 16;
  float f;
  CopySameSize(&bits, &f);
  return f;
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) bfloat16_t BF16FromF32(float f) {
  uint32_t bits;
  CopySameSize(&f, &bits);
  bfloat16_t bf;
  bf.bits = static_cast<uint16_t>(bits >> 16);
  return bf;
}
 __attribute__((noreturn)) void __attribute__((__format__(__printf__, 3, 4)))
    Abort(const char* file, int line, const char* format, ...);
template <class T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void PreventElision(T&& output) {
  asm volatile("" : "+r"(output) : : "memory");
}
}
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  void
  __throw_bad_exception(void) __attribute__((__noreturn__));
  void
  __throw_bad_alloc(void) __attribute__((__noreturn__));
  void
  __throw_bad_array_new_length(void) __attribute__((__noreturn__));
  void
  __throw_bad_cast(void) __attribute__((__noreturn__));
  void
  __throw_bad_typeid(void) __attribute__((__noreturn__));
  void
  __throw_logic_error(const char*) __attribute__((__noreturn__));
  void
  __throw_domain_error(const char*) __attribute__((__noreturn__));
  void
  __throw_invalid_argument(const char*) __attribute__((__noreturn__));
  void
  __throw_length_error(const char*) __attribute__((__noreturn__));
  void
  __throw_out_of_range(const char*) __attribute__((__noreturn__));
  void
  __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))
    __attribute__((__format__(__gnu_printf__, 1, 2)));
  void
  __throw_runtime_error(const char*) __attribute__((__noreturn__));
  void
  __throw_range_error(const char*) __attribute__((__noreturn__));
  void
  __throw_overflow_error(const char*) __attribute__((__noreturn__));
  void
  __throw_underflow_error(const char*) __attribute__((__noreturn__));
  void
  __throw_ios_failure(const char*) __attribute__((__noreturn__));
  void
  __throw_ios_failure(const char*, int) __attribute__((__noreturn__));
  void
  __throw_system_error(int) __attribute__((__noreturn__));
  void
  __throw_future_error(int) __attribute__((__noreturn__));
  void
  __throw_bad_function_call() __attribute__((__noreturn__));

}
       
extern "C++" {
namespace std __attribute__ ((__visibility__ ("default")))
{

  struct __true_type { };
  struct __false_type { };
  template<bool>
    struct __truth_type
    { typedef __false_type __type; };
  template<>
    struct __truth_type<true>
    { typedef __true_type __type; };
  template<class _Sp, class _Tp>
    struct __traitor
    {
      enum { __value = bool(_Sp::__value) || bool(_Tp::__value) };
      typedef typename __truth_type<__value>::__type __type;
    };
  template<typename, typename>
    struct __are_same
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<typename _Tp>
    struct __are_same<_Tp, _Tp>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Tp>
    struct __is_void
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<>
    struct __is_void<void>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Tp>
    struct __is_integer
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<>
    struct __is_integer<bool>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<signed char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<unsigned char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<wchar_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<char16_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<char32_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<short>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<unsigned short>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<int>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<unsigned int>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<unsigned long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<long long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_integer<unsigned long long>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Tp>
    struct __is_floating
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<>
    struct __is_floating<float>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_floating<double>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_floating<long double>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Tp>
    struct __is_pointer
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<typename _Tp>
    struct __is_pointer<_Tp*>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Tp>
    struct __is_arithmetic
    : public __traitor<__is_integer<_Tp>, __is_floating<_Tp> >
    { };
  template<typename _Tp>
    struct __is_scalar
    : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp> >
    { };
  template<typename _Tp>
    struct __is_char
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<>
    struct __is_char<char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_char<wchar_t>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Tp>
    struct __is_byte
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<>
    struct __is_byte<char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_byte<signed char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<>
    struct __is_byte<unsigned char>
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename> struct iterator_traits;
  template<typename _Tp>
    struct __is_nonvolatile_trivially_copyable
    {
      enum { __value = __is_trivially_copyable(_Tp) };
    };
  template<typename _Tp>
    struct __is_nonvolatile_trivially_copyable<volatile _Tp>
    {
      enum { __value = 0 };
    };
  template<typename _OutputIter, typename _InputIter>
    struct __memcpyable
    {
      enum { __value = 0 };
    };
  template<typename _Tp>
    struct __memcpyable<_Tp*, _Tp*>
    : __is_nonvolatile_trivially_copyable<_Tp>
    { };
  template<typename _Tp>
    struct __memcpyable<_Tp*, const _Tp*>
    : __is_nonvolatile_trivially_copyable<_Tp>
    { };
  template<typename _Iter1, typename _Iter2>
    struct __memcmpable
    {
      enum { __value = 0 };
    };
  template<typename _Tp>
    struct __memcmpable<_Tp*, _Tp*>
    : __is_nonvolatile_trivially_copyable<_Tp>
    { };
  template<typename _Tp>
    struct __memcmpable<const _Tp*, _Tp*>
    : __is_nonvolatile_trivially_copyable<_Tp>
    { };
  template<typename _Tp>
    struct __memcmpable<_Tp*, const _Tp*>
    : __is_nonvolatile_trivially_copyable<_Tp>
    { };
  template<typename _Tp, bool _TreatAsBytes =
 __is_byte<_Tp>::__value
    >
    struct __is_memcmp_ordered
    {
      static const bool __value = _Tp(-1) > _Tp(1);
    };
  template<typename _Tp>
    struct __is_memcmp_ordered<_Tp, false>
    {
      static const bool __value = false;
    };
  template<typename _Tp, typename _Up, bool = sizeof(_Tp) == sizeof(_Up)>
    struct __is_memcmp_ordered_with
    {
      static const bool __value = __is_memcmp_ordered<_Tp>::__value
 && __is_memcmp_ordered<_Up>::__value;
    };
  template<typename _Tp, typename _Up>
    struct __is_memcmp_ordered_with<_Tp, _Up, false>
    {
      static const bool __value = false;
    };
  template<typename _Tp>
    struct __is_move_iterator
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
  template<typename _Iterator>
   
    inline _Iterator
    __miter_base(_Iterator __it)
    { return __it; }

}
}
       
extern "C++" {
namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

  template<bool, typename>
    struct __enable_if
    { };
  template<typename _Tp>
    struct __enable_if<true, _Tp>
    { typedef _Tp __type; };
  template<bool _Cond, typename _Iftrue, typename _Iffalse>
    struct __conditional_type
    { typedef _Iftrue __type; };
  template<typename _Iftrue, typename _Iffalse>
    struct __conditional_type<false, _Iftrue, _Iffalse>
    { typedef _Iffalse __type; };
  template<typename _Tp>
    struct __add_unsigned
    {
    private:
      typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;
    public:
      typedef typename __if_type::__type __type;
    };
  template<>
    struct __add_unsigned<char>
    { typedef unsigned char __type; };
  template<>
    struct __add_unsigned<signed char>
    { typedef unsigned char __type; };
  template<>
    struct __add_unsigned<short>
    { typedef unsigned short __type; };
  template<>
    struct __add_unsigned<int>
    { typedef unsigned int __type; };
  template<>
    struct __add_unsigned<long>
    { typedef unsigned long __type; };
  template<>
    struct __add_unsigned<long long>
    { typedef unsigned long long __type; };
  template<>
    struct __add_unsigned<bool>;
  template<>
    struct __add_unsigned<wchar_t>;
  template<typename _Tp>
    struct __remove_unsigned
    {
    private:
      typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;
    public:
      typedef typename __if_type::__type __type;
    };
  template<>
    struct __remove_unsigned<char>
    { typedef signed char __type; };
  template<>
    struct __remove_unsigned<unsigned char>
    { typedef signed char __type; };
  template<>
    struct __remove_unsigned<unsigned short>
    { typedef short __type; };
  template<>
    struct __remove_unsigned<unsigned int>
    { typedef int __type; };
  template<>
    struct __remove_unsigned<unsigned long>
    { typedef long __type; };
  template<>
    struct __remove_unsigned<unsigned long long>
    { typedef long long __type; };
  template<>
    struct __remove_unsigned<bool>;
  template<>
    struct __remove_unsigned<wchar_t>;
  template<typename _Type>
    constexpr
    inline bool
    __is_null_pointer(_Type* __ptr)
    { return __ptr == 0; }
  template<typename _Type>
    constexpr
    inline bool
    __is_null_pointer(_Type)
    { return false; }
  constexpr bool
  __is_null_pointer(std::nullptr_t)
  { return true; }
  template<typename _Tp, bool = std::__is_integer<_Tp>::__value>
    struct __promote
    { typedef double __type; };
  template<typename _Tp>
    struct __promote<_Tp, false>
    { };
  template<>
    struct __promote<long double>
    { typedef long double __type; };
  template<>
    struct __promote<double>
    { typedef double __type; };
  template<>
    struct __promote<float>
    { typedef float __type; };
  template<typename _Tp, typename _Up,
           typename _Tp2 = typename __promote<_Tp>::__type,
           typename _Up2 = typename __promote<_Up>::__type>
    struct __promote_2
    {
      typedef __typeof__(_Tp2() + _Up2()) __type;
    };
  template<typename _Tp, typename _Up, typename _Vp,
           typename _Tp2 = typename __promote<_Tp>::__type,
           typename _Up2 = typename __promote<_Up>::__type,
           typename _Vp2 = typename __promote<_Vp>::__type>
    struct __promote_3
    {
      typedef __typeof__(_Tp2() + _Up2() + _Vp2()) __type;
    };
  template<typename _Tp, typename _Up, typename _Vp, typename _Wp,
           typename _Tp2 = typename __promote<_Tp>::__type,
           typename _Up2 = typename __promote<_Up>::__type,
           typename _Vp2 = typename __promote<_Vp>::__type,
           typename _Wp2 = typename __promote<_Wp>::__type>
    struct __promote_4
    {
      typedef __typeof__(_Tp2() + _Up2() + _Vp2() + _Wp2()) __type;
    };

}
}
       
namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp>
    struct __is_integer_nonstrict
    : public std::__is_integer<_Tp>
    {
      using std::__is_integer<_Tp>::__value;
      enum { __width = __value ? sizeof(_Tp) * 8 : 0 };
    };
  template<typename _Value>
    struct __numeric_traits_integer
    {
      static_assert(__is_integer_nonstrict<_Value>::__value,
      "invalid specialization");
      static const bool __is_signed = (_Value)(-1) < 0;
      static const int __digits
 = __is_integer_nonstrict<_Value>::__width - __is_signed;
      static const _Value __max = __is_signed
 ? (((((_Value)1 << (__digits - 1)) - 1) << 1) + 1)
 : ~(_Value)0;
      static const _Value __min = __is_signed ? -__max - 1 : (_Value)0;
    };
  template<typename _Value>
    const _Value __numeric_traits_integer<_Value>::__min;
  template<typename _Value>
    const _Value __numeric_traits_integer<_Value>::__max;
  template<typename _Value>
    const bool __numeric_traits_integer<_Value>::__is_signed;
  template<typename _Value>
    const int __numeric_traits_integer<_Value>::__digits;
  template<typename _Tp>
    using __int_traits = __numeric_traits_integer<_Tp>;
  template<typename _Value>
    struct __numeric_traits_floating
    {
      static const int __max_digits10 = (2 + (std::__are_same<_Value, float>::__value ? 24 : std::__are_same<_Value, double>::__value ? 53 : 64) * 643L / 2136);
      static const bool __is_signed = true;
      static const int __digits10 = (std::__are_same<_Value, float>::__value ? 6 : std::__are_same<_Value, double>::__value ? 15 : 18);
      static const int __max_exponent10 = (std::__are_same<_Value, float>::__value ? 38 : std::__are_same<_Value, double>::__value ? 308 : 4932);
    };
  template<typename _Value>
    const int __numeric_traits_floating<_Value>::__max_digits10;
  template<typename _Value>
    const bool __numeric_traits_floating<_Value>::__is_signed;
  template<typename _Value>
    const int __numeric_traits_floating<_Value>::__digits10;
  template<typename _Value>
    const int __numeric_traits_floating<_Value>::__max_exponent10;
  template<typename _Value>
    struct __numeric_traits
    : public __numeric_traits_integer<_Value>
    { };
  template<>
    struct __numeric_traits<float>
    : public __numeric_traits_floating<float>
    { };
  template<>
    struct __numeric_traits<double>
    : public __numeric_traits_floating<double>
    { };
  template<>
    struct __numeric_traits<long double>
    : public __numeric_traits_floating<long double>
    { };

}
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp>
    struct tuple_size;
  template<typename _Tp,
    typename _Up = typename remove_cv<_Tp>::type,
    typename = typename enable_if<is_same<_Tp, _Up>::value>::type,
    size_t = tuple_size<_Tp>::value>
    using __enable_if_has_tuple_size = _Tp;
  template<typename _Tp>
    struct tuple_size<const __enable_if_has_tuple_size<_Tp>>
    : public tuple_size<_Tp> { };
  template<typename _Tp>
    struct tuple_size<volatile __enable_if_has_tuple_size<_Tp>>
    : public tuple_size<_Tp> { };
  template<typename _Tp>
    struct tuple_size<const volatile __enable_if_has_tuple_size<_Tp>>
    : public tuple_size<_Tp> { };
  template<size_t __i, typename _Tp>
    struct tuple_element;
  template<size_t __i, typename _Tp>
    using __tuple_element_t = typename tuple_element<__i, _Tp>::type;
  template<size_t __i, typename _Tp>
    struct tuple_element<__i, const _Tp>
    {
      using type = const __tuple_element_t<__i, _Tp>;
    };
  template<size_t __i, typename _Tp>
    struct tuple_element<__i, volatile _Tp>
    {
      using type = volatile __tuple_element_t<__i, _Tp>;
    };
  template<size_t __i, typename _Tp>
    struct tuple_element<__i, const volatile _Tp>
    {
      using type = const volatile __tuple_element_t<__i, _Tp>;
    };
  template<size_t... _Indexes> struct _Index_tuple { };
  template<size_t _Num>
    struct _Build_index_tuple
    {
      using __type = _Index_tuple<__integer_pack(_Num)...>;
    };
  template<size_t _Np, typename... _Types>
    struct _Nth_type
    { };
  template<typename _Tp0, typename... _Rest>
    struct _Nth_type<0, _Tp0, _Rest...>
    { using type = _Tp0; };
  template<typename _Tp0, typename _Tp1, typename... _Rest>
    struct _Nth_type<1, _Tp0, _Tp1, _Rest...>
    { using type = _Tp1; };
  template<typename _Tp0, typename _Tp1, typename _Tp2, typename... _Rest>
    struct _Nth_type<2, _Tp0, _Tp1, _Tp2, _Rest...>
    { using type = _Tp2; };
  template<size_t _Np, typename _Tp0, typename _Tp1, typename _Tp2,
    typename... _Rest>
    struct _Nth_type<_Np, _Tp0, _Tp1, _Tp2, _Rest...>
    : _Nth_type<_Np - 3, _Rest...>
    { };
  template<typename _Tp0, typename _Tp1, typename... _Rest>
    struct _Nth_type<0, _Tp0, _Tp1, _Rest...>
    { using type = _Tp0; };
  template<typename _Tp0, typename _Tp1, typename _Tp2, typename... _Rest>
    struct _Nth_type<0, _Tp0, _Tp1, _Tp2, _Rest...>
    { using type = _Tp0; };
  template<typename _Tp0, typename _Tp1, typename _Tp2, typename... _Rest>
    struct _Nth_type<1, _Tp0, _Tp1, _Tp2, _Rest...>
    { using type = _Tp1; };

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  struct piecewise_construct_t { explicit piecewise_construct_t() = default; };
  constexpr piecewise_construct_t piecewise_construct =
    piecewise_construct_t();
  template<typename...>
    class tuple;
  template<size_t...>
    struct _Index_tuple;
  template <bool, typename _T1, typename _T2>
    struct _PCC
    {
      template <typename _U1, typename _U2>
      static constexpr bool _ConstructiblePair()
      {
 return __and_<is_constructible<_T1, const _U1&>,
        is_constructible<_T2, const _U2&>>::value;
      }
      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyConvertiblePair()
      {
 return __and_<is_convertible<const _U1&, _T1>,
        is_convertible<const _U2&, _T2>>::value;
      }
      template <typename _U1, typename _U2>
      static constexpr bool _MoveConstructiblePair()
      {
 return __and_<is_constructible<_T1, _U1&&>,
        is_constructible<_T2, _U2&&>>::value;
      }
      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyMoveConvertiblePair()
      {
 return __and_<is_convertible<_U1&&, _T1>,
        is_convertible<_U2&&, _T2>>::value;
      }
    };
  template <typename _T1, typename _T2>
    struct _PCC<false, _T1, _T2>
    {
      template <typename _U1, typename _U2>
      static constexpr bool _ConstructiblePair()
      {
 return false;
      }
      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyConvertiblePair()
      {
 return false;
      }
      template <typename _U1, typename _U2>
      static constexpr bool _MoveConstructiblePair()
      {
 return false;
      }
      template <typename _U1, typename _U2>
      static constexpr bool _ImplicitlyMoveConvertiblePair()
      {
 return false;
      }
    };
  template<typename _U1, typename _U2> class __pair_base
  {
    template<typename _T1, typename _T2> friend struct pair;
    __pair_base() = default;
    ~__pair_base() = default;
    __pair_base(const __pair_base&) = default;
    __pair_base& operator=(const __pair_base&) = delete;
  };
  template<typename _T1, typename _T2>
    struct pair
    : public __pair_base<_T1, _T2>
    {
      typedef _T1 first_type;
      typedef _T2 second_type;
      _T1 first;
      _T2 second;
      constexpr pair(const pair&) = default;
      constexpr pair(pair&&) = default;
      template<typename... _Args1, typename... _Args2>

 pair(piecewise_construct_t, tuple<_Args1...>, tuple<_Args2...>);
      void
      swap(pair& __p)
      noexcept(__and_<__is_nothrow_swappable<_T1>,
        __is_nothrow_swappable<_T2>>::value)
      {
 using std::swap;
 swap(first, __p.first);
 swap(second, __p.second);
      }
    private:
      template<typename... _Args1, size_t... _Indexes1,
        typename... _Args2, size_t... _Indexes2>

 pair(tuple<_Args1...>&, tuple<_Args2...>&,
      _Index_tuple<_Indexes1...>, _Index_tuple<_Indexes2...>);
    public:
      template <typename _U1 = _T1,
                typename _U2 = _T2,
                typename enable_if<__and_<
                                     __is_implicitly_default_constructible<_U1>,
                                     __is_implicitly_default_constructible<_U2>>
                                   ::value, bool>::type = true>
      constexpr pair()
      : first(), second() { }
      template <typename _U1 = _T1,
                typename _U2 = _T2,
                typename enable_if<__and_<
                       is_default_constructible<_U1>,
                       is_default_constructible<_U2>,
                       __not_<
                         __and_<__is_implicitly_default_constructible<_U1>,
                                __is_implicitly_default_constructible<_U2>>>>
                                   ::value, bool>::type = false>
      explicit constexpr pair()
      : first(), second() { }
      using _PCCP = _PCC<true, _T1, _T2>;
      template<typename _U1 = _T1, typename _U2=_T2, typename
        enable_if<_PCCP::template
      _ConstructiblePair<_U1, _U2>()
                  && _PCCP::template
      _ImplicitlyConvertiblePair<_U1, _U2>(),
                         bool>::type=true>
      constexpr pair(const _T1& __a, const _T2& __b)
      : first(__a), second(__b) { }
       template<typename _U1 = _T1, typename _U2=_T2, typename
  enable_if<_PCCP::template
       _ConstructiblePair<_U1, _U2>()
                   && !_PCCP::template
       _ImplicitlyConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
      explicit constexpr pair(const _T1& __a, const _T2& __b)
      : first(__a), second(__b) { }
      template <typename _U1, typename _U2>
        using _PCCFP = _PCC<!is_same<_T1, _U1>::value
       || !is_same<_T2, _U2>::value,
       _T1, _T2>;
      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _ConstructiblePair<_U1, _U2>()
                  && _PCCFP<_U1, _U2>::template
      _ImplicitlyConvertiblePair<_U1, _U2>(),
     bool>::type=true>
 constexpr pair(const pair<_U1, _U2>& __p)
 : first(__p.first), second(__p.second)
 { ; }
      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _ConstructiblePair<_U1, _U2>()
    && !_PCCFP<_U1, _U2>::template
      _ImplicitlyConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
 explicit constexpr pair(const pair<_U1, _U2>& __p)
 : first(__p.first), second(__p.second)
 { ; }
    private:
      struct __zero_as_null_pointer_constant
      {
 __zero_as_null_pointer_constant(int __zero_as_null_pointer_constant::*)
 { }
 template<typename _Tp,
   typename = __enable_if_t<is_null_pointer<_Tp>::value>>
 __zero_as_null_pointer_constant(_Tp) = delete;
      };
    public:
      template<typename _U1,
        __enable_if_t<__and_<__not_<is_reference<_U1>>,
        is_pointer<_T2>,
        is_constructible<_T1, _U1>,
        __not_<is_constructible<_T1, const _U1&>>,
        is_convertible<_U1, _T1>>::value,
        bool> = true>
 __attribute__ ((__deprecated__ ("use 'nullptr' instead of '0' to " "initialize std::pair of move-only " "type and pointer")))
 constexpr
 pair(_U1&& __x, __zero_as_null_pointer_constant, ...)
 : first(std::forward<_U1>(__x)), second(nullptr)
 { ; }
      template<typename _U1,
        __enable_if_t<__and_<__not_<is_reference<_U1>>,
        is_pointer<_T2>,
        is_constructible<_T1, _U1>,
        __not_<is_constructible<_T1, const _U1&>>,
        __not_<is_convertible<_U1, _T1>>>::value,
        bool> = false>
 __attribute__ ((__deprecated__ ("use 'nullptr' instead of '0' to " "initialize std::pair of move-only " "type and pointer")))
 explicit constexpr
 pair(_U1&& __x, __zero_as_null_pointer_constant, ...)
 : first(std::forward<_U1>(__x)), second(nullptr)
 { ; }
      template<typename _U2,
        __enable_if_t<__and_<is_pointer<_T1>,
        __not_<is_reference<_U2>>,
        is_constructible<_T2, _U2>,
        __not_<is_constructible<_T2, const _U2&>>,
        is_convertible<_U2, _T2>>::value,
        bool> = true>
 __attribute__ ((__deprecated__ ("use 'nullptr' instead of '0' to " "initialize std::pair of move-only " "type and pointer")))
 constexpr
 pair(__zero_as_null_pointer_constant, _U2&& __y, ...)
 : first(nullptr), second(std::forward<_U2>(__y))
 { ; }
      template<typename _U2,
        __enable_if_t<__and_<is_pointer<_T1>,
        __not_<is_reference<_U2>>,
        is_constructible<_T2, _U2>,
        __not_<is_constructible<_T2, const _U2&>>,
        __not_<is_convertible<_U2, _T2>>>::value,
        bool> = false>
 __attribute__ ((__deprecated__ ("use 'nullptr' instead of '0' to " "initialize std::pair of move-only " "type and pointer")))
 explicit constexpr
 pair(__zero_as_null_pointer_constant, _U2&& __y, ...)
 : first(nullptr), second(std::forward<_U2>(__y))
 { ; }
      template<typename _U1, typename _U2, typename
        enable_if<_PCCP::template
      _MoveConstructiblePair<_U1, _U2>()
     && _PCCP::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=true>
 constexpr pair(_U1&& __x, _U2&& __y)
 : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y))
 { ; }
      template<typename _U1, typename _U2, typename
        enable_if<_PCCP::template
      _MoveConstructiblePair<_U1, _U2>()
     && !_PCCP::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
 explicit constexpr pair(_U1&& __x, _U2&& __y)
 : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y))
 { ; }
      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _MoveConstructiblePair<_U1, _U2>()
     && _PCCFP<_U1, _U2>::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=true>
 constexpr pair(pair<_U1, _U2>&& __p)
 : first(std::forward<_U1>(__p.first)),
   second(std::forward<_U2>(__p.second))
 { ; }
      template<typename _U1, typename _U2, typename
        enable_if<_PCCFP<_U1, _U2>::template
      _MoveConstructiblePair<_U1, _U2>()
     && !_PCCFP<_U1, _U2>::template
      _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
                         bool>::type=false>
 explicit constexpr pair(pair<_U1, _U2>&& __p)
 : first(std::forward<_U1>(__p.first)),
   second(std::forward<_U2>(__p.second))
 { ; }
      pair&
      operator=(__conditional_t<__and_<is_copy_assignable<_T1>,
           is_copy_assignable<_T2>>::value,
    const pair&, const __nonesuch&> __p)
      {
 first = __p.first;
 second = __p.second;
 return *this;
      }
      pair&
      operator=(__conditional_t<__and_<is_move_assignable<_T1>,
           is_move_assignable<_T2>>::value,
    pair&&, __nonesuch&&> __p)
      noexcept(__and_<is_nothrow_move_assignable<_T1>,
        is_nothrow_move_assignable<_T2>>::value)
      {
 first = std::forward<first_type>(__p.first);
 second = std::forward<second_type>(__p.second);
 return *this;
      }
      template<typename _U1, typename _U2>
 typename enable_if<__and_<is_assignable<_T1&, const _U1&>,
      is_assignable<_T2&, const _U2&>>::value,
      pair&>::type
 operator=(const pair<_U1, _U2>& __p)
 {
   first = __p.first;
   second = __p.second;
   return *this;
 }
      template<typename _U1, typename _U2>
 typename enable_if<__and_<is_assignable<_T1&, _U1&&>,
      is_assignable<_T2&, _U2&&>>::value,
      pair&>::type
 operator=(pair<_U1, _U2>&& __p)
 {
   first = std::forward<_U1>(__p.first);
   second = std::forward<_U2>(__p.second);
   return *this;
 }
    };
  template<typename _T1, typename _T2>
    inline constexpr bool
    operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first == __y.first && __x.second == __y.second; }
  template<typename _T1, typename _T2>
    inline constexpr bool
    operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first < __y.first
      || (!(__y.first < __x.first) && __x.second < __y.second); }
  template<typename _T1, typename _T2>
    inline constexpr bool
    operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x == __y); }
  template<typename _T1, typename _T2>
    inline constexpr bool
    operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __y < __x; }
  template<typename _T1, typename _T2>
    inline constexpr bool
    operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__y < __x); }
  template<typename _T1, typename _T2>
    inline constexpr bool
    operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x < __y); }
  template<typename _T1, typename _T2>
    inline
    void
    swap(pair<_T1, _T2>& __x, pair<_T1, _T2>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }
  template<typename _T1, typename _T2>
    constexpr pair<typename __decay_and_strip<_T1>::__type,
                   typename __decay_and_strip<_T2>::__type>
    make_pair(_T1&& __x, _T2&& __y)
    {
      typedef typename __decay_and_strip<_T1>::__type __ds_type1;
      typedef typename __decay_and_strip<_T2>::__type __ds_type2;
      typedef pair<__ds_type1, __ds_type2> __pair_type;
      return __pair_type(std::forward<_T1>(__x), std::forward<_T2>(__y));
    }
  template<typename _T1, typename _T2>
    struct __is_tuple_like_impl<pair<_T1, _T2>> : true_type
    { };
  template<class _Tp1, class _Tp2>
    struct tuple_size<pair<_Tp1, _Tp2>>
    : public integral_constant<size_t, 2> { };
  template<class _Tp1, class _Tp2>
    struct tuple_element<0, pair<_Tp1, _Tp2>>
    { typedef _Tp1 type; };
  template<class _Tp1, class _Tp2>
    struct tuple_element<1, pair<_Tp1, _Tp2>>
    { typedef _Tp2 type; };
  template<size_t _Int>
    struct __pair_get;
  template<>
    struct __pair_get<0>
    {
      template<typename _Tp1, typename _Tp2>
 static constexpr _Tp1&
 __get(pair<_Tp1, _Tp2>& __pair) noexcept
 { return __pair.first; }
      template<typename _Tp1, typename _Tp2>
 static constexpr _Tp1&&
 __move_get(pair<_Tp1, _Tp2>&& __pair) noexcept
 { return std::forward<_Tp1>(__pair.first); }
      template<typename _Tp1, typename _Tp2>
 static constexpr const _Tp1&
 __const_get(const pair<_Tp1, _Tp2>& __pair) noexcept
 { return __pair.first; }
      template<typename _Tp1, typename _Tp2>
 static constexpr const _Tp1&&
 __const_move_get(const pair<_Tp1, _Tp2>&& __pair) noexcept
 { return std::forward<const _Tp1>(__pair.first); }
    };
  template<>
    struct __pair_get<1>
    {
      template<typename _Tp1, typename _Tp2>
 static constexpr _Tp2&
 __get(pair<_Tp1, _Tp2>& __pair) noexcept
 { return __pair.second; }
      template<typename _Tp1, typename _Tp2>
 static constexpr _Tp2&&
 __move_get(pair<_Tp1, _Tp2>&& __pair) noexcept
 { return std::forward<_Tp2>(__pair.second); }
      template<typename _Tp1, typename _Tp2>
 static constexpr const _Tp2&
 __const_get(const pair<_Tp1, _Tp2>& __pair) noexcept
 { return __pair.second; }
      template<typename _Tp1, typename _Tp2>
 static constexpr const _Tp2&&
 __const_move_get(const pair<_Tp1, _Tp2>&& __pair) noexcept
 { return std::forward<const _Tp2>(__pair.second); }
    };
  template<size_t _Int, class _Tp1, class _Tp2>
    constexpr typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type&
    get(pair<_Tp1, _Tp2>& __in) noexcept
    { return __pair_get<_Int>::__get(__in); }
  template<size_t _Int, class _Tp1, class _Tp2>
    constexpr typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type&&
    get(pair<_Tp1, _Tp2>&& __in) noexcept
    { return __pair_get<_Int>::__move_get(std::move(__in)); }
  template<size_t _Int, class _Tp1, class _Tp2>
    constexpr const typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type&
    get(const pair<_Tp1, _Tp2>& __in) noexcept
    { return __pair_get<_Int>::__const_get(__in); }
  template<size_t _Int, class _Tp1, class _Tp2>
    constexpr const typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type&&
    get(const pair<_Tp1, _Tp2>&& __in) noexcept
    { return __pair_get<_Int>::__const_move_get(std::move(__in)); }

}
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  struct input_iterator_tag { };
  struct output_iterator_tag { };
  struct forward_iterator_tag : public input_iterator_tag { };
  struct bidirectional_iterator_tag : public forward_iterator_tag { };
  struct random_access_iterator_tag : public bidirectional_iterator_tag { };
  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {
      typedef _Category iterator_category;
      typedef _Tp value_type;
      typedef _Distance difference_type;
      typedef _Pointer pointer;
      typedef _Reference reference;
    };
  template<typename _Iterator>
    struct iterator_traits;
  template<typename _Iterator, typename = __void_t<>>
    struct __iterator_traits { };
  template<typename _Iterator>
    struct __iterator_traits<_Iterator,
        __void_t<typename _Iterator::iterator_category,
          typename _Iterator::value_type,
          typename _Iterator::difference_type,
          typename _Iterator::pointer,
          typename _Iterator::reference>>
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type value_type;
      typedef typename _Iterator::difference_type difference_type;
      typedef typename _Iterator::pointer pointer;
      typedef typename _Iterator::reference reference;
    };
  template<typename _Iterator>
    struct iterator_traits
    : public __iterator_traits<_Iterator> { };
  template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef _Tp& reference;
    };
  template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef const _Tp* pointer;
      typedef const _Tp& reference;
    };
  template<typename _Iter>
    __attribute__((__always_inline__))
    inline constexpr
    typename iterator_traits<_Iter>::iterator_category
    __iterator_category(const _Iter&)
    { return typename iterator_traits<_Iter>::iterator_category(); }
  template<typename _Iter>
    using __iterator_category_t
      = typename iterator_traits<_Iter>::iterator_category;
  template<typename _InIter>
    using _RequireInputIter =
      __enable_if_t<is_convertible<__iterator_category_t<_InIter>,
       input_iterator_tag>::value>;
  template<typename _It,
    typename _Cat = __iterator_category_t<_It>>
    struct __is_random_access_iter
      : is_base_of<random_access_iterator_tag, _Cat>
    {
      typedef is_base_of<random_access_iterator_tag, _Cat> _Base;
      enum { __value = _Base::value };
    };

}
       
       
namespace std __attribute__ ((__visibility__ ("default")))
{


  template <typename> struct _List_iterator;
  template <typename> struct _List_const_iterator;

  template<typename _InputIterator>
    inline
    typename iterator_traits<_InputIterator>::difference_type
    __distance(_InputIterator __first, _InputIterator __last,
               input_iterator_tag)
    {
     
      typename iterator_traits<_InputIterator>::difference_type __n = 0;
      while (__first != __last)
 {
   ++__first;
   ++__n;
 }
      return __n;
    }
  template<typename _RandomAccessIterator>
    __attribute__((__always_inline__))
    inline
    typename iterator_traits<_RandomAccessIterator>::difference_type
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
               random_access_iterator_tag)
    {
     
      return __last - __first;
    }
  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_iterator<_Tp>,
        std::_List_iterator<_Tp>,
        input_iterator_tag);
  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_const_iterator<_Tp>,
        std::_List_const_iterator<_Tp>,
        input_iterator_tag);
  template<typename _OutputIterator>
    void
    __distance(_OutputIterator, _OutputIterator, output_iterator_tag) = delete;
  template<typename _InputIterator>
    __attribute__((__always_inline__))
    inline
    typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last)
    {
      return std::__distance(__first, __last,
        std::__iterator_category(__first));
    }
  template<typename _InputIterator, typename _Distance>
    inline void
    __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
    {
     
      do { if (std::__is_constant_evaluated() && !bool(__n >= 0)) __builtin_unreachable(); } while (false);
      while (__n--)
 ++__i;
    }
  template<typename _BidirectionalIterator, typename _Distance>
    inline void
    __advance(_BidirectionalIterator& __i, _Distance __n,
       bidirectional_iterator_tag)
    {
     
      if (__n > 0)
        while (__n--)
   ++__i;
      else
        while (__n++)
   --__i;
    }
  template<typename _RandomAccessIterator, typename _Distance>
    inline void
    __advance(_RandomAccessIterator& __i, _Distance __n,
              random_access_iterator_tag)
    {
     
      if (__builtin_constant_p(__n) && __n == 1)
 ++__i;
      else if (__builtin_constant_p(__n) && __n == -1)
 --__i;
      else
 __i += __n;
    }
  template<typename _OutputIterator, typename _Distance>
    void
    __advance(_OutputIterator&, _Distance, output_iterator_tag) = delete;
  template<typename _InputIterator, typename _Distance>
    __attribute__((__always_inline__))
    inline void
    advance(_InputIterator& __i, _Distance __n)
    {
      typename iterator_traits<_InputIterator>::difference_type __d = __n;
      std::__advance(__i, __d, std::__iterator_category(__i));
    }
  template<typename _InputIterator>
    [[__gnu__::__always_inline__]]
    inline _InputIterator
    next(_InputIterator __x, typename
  iterator_traits<_InputIterator>::difference_type __n = 1)
    {
     
      std::advance(__x, __n);
      return __x;
    }
  template<typename _BidirectionalIterator>
    [[__gnu__::__always_inline__]]
    inline _BidirectionalIterator
    prev(_BidirectionalIterator __x, typename
  iterator_traits<_BidirectionalIterator>::difference_type __n = 1)
    {
     
      std::advance(__x, -__n);
      return __x;
    }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  class __undefined;
  template<typename _Tp>
    struct __get_first_arg
    { using type = __undefined; };
  template<template<typename, typename...> class _SomeTemplate, typename _Tp,
           typename... _Types>
    struct __get_first_arg<_SomeTemplate<_Tp, _Types...>>
    { using type = _Tp; };
  template<typename _Tp, typename _Up>
    struct __replace_first_arg
    { };
  template<template<typename, typename...> class _SomeTemplate, typename _Up,
           typename _Tp, typename... _Types>
    struct __replace_first_arg<_SomeTemplate<_Tp, _Types...>, _Up>
    { using type = _SomeTemplate<_Up, _Types...>; };
  template<typename _Ptr, typename = void>
    struct __ptr_traits_elem : __get_first_arg<_Ptr>
    { };
  template<typename _Ptr>
    struct __ptr_traits_elem<_Ptr, __void_t<typename _Ptr::element_type>>
    { using type = typename _Ptr::element_type; };
  template<typename _Ptr>
    using __ptr_traits_elem_t = typename __ptr_traits_elem<_Ptr>::type;
  template<typename _Ptr, typename _Elt, bool = is_void<_Elt>::value>
    struct __ptr_traits_ptr_to
    {
      using pointer = _Ptr;
      using element_type = _Elt;
      static pointer
      pointer_to(element_type& __r)
      { return pointer::pointer_to(__r); }
    };
  template<typename _Ptr, typename _Elt>
    struct __ptr_traits_ptr_to<_Ptr, _Elt, true>
    { };
  template<typename _Tp>
    struct __ptr_traits_ptr_to<_Tp*, _Tp, false>
    {
      using pointer = _Tp*;
      using element_type = _Tp;
      static pointer
      pointer_to(element_type& __r) noexcept
      { return std::addressof(__r); }
    };
  template<typename _Ptr, typename _Elt>
    struct __ptr_traits_impl : __ptr_traits_ptr_to<_Ptr, _Elt>
    {
    private:
      template<typename _Tp>
 using __diff_t = typename _Tp::difference_type;
      template<typename _Tp, typename _Up>
 using __rebind = __type_identity<typename _Tp::template rebind<_Up>>;
    public:
      using pointer = _Ptr;
      using element_type = _Elt;
      using difference_type = __detected_or_t<ptrdiff_t, __diff_t, _Ptr>;
      template<typename _Up>
 using rebind = typename __detected_or_t<__replace_first_arg<_Ptr, _Up>,
      __rebind, _Ptr, _Up>::type;
    };
  template<typename _Ptr>
    struct __ptr_traits_impl<_Ptr, __undefined>
    { };
  template<typename _Ptr>
    struct pointer_traits : __ptr_traits_impl<_Ptr, __ptr_traits_elem_t<_Ptr>>
    { };
  template<typename _Tp>
    struct pointer_traits<_Tp*> : __ptr_traits_ptr_to<_Tp*, _Tp>
    {
      typedef _Tp* pointer;
      typedef _Tp element_type;
      typedef ptrdiff_t difference_type;
      template<typename _Up> using rebind = _Up*;
    };
  template<typename _Ptr, typename _Tp>
    using __ptr_rebind = typename pointer_traits<_Ptr>::template rebind<_Tp>;
  template<typename _Tp>
    constexpr _Tp*
    __to_address(_Tp* __ptr) noexcept
    {
      static_assert(!std::is_function<_Tp>::value, "not a function pointer");
      return __ptr;
    }
  template<typename _Ptr>
    constexpr typename std::pointer_traits<_Ptr>::element_type*
    __to_address(const _Ptr& __ptr)
    { return std::__to_address(__ptr.operator->()); }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

 
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Iterator>
    class reverse_iterator
    : public iterator<typename iterator_traits<_Iterator>::iterator_category,
        typename iterator_traits<_Iterator>::value_type,
        typename iterator_traits<_Iterator>::difference_type,
        typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
    {
      template<typename _Iter>
 friend class reverse_iterator;
    protected:
      _Iterator current;
      typedef iterator_traits<_Iterator> __traits_type;
    public:
      typedef _Iterator iterator_type;
      typedef typename __traits_type::pointer pointer;
      typedef typename __traits_type::difference_type difference_type;
      typedef typename __traits_type::reference reference;
     
      reverse_iterator()
      noexcept(noexcept(_Iterator()))
      : current()
      { }
      explicit
      reverse_iterator(iterator_type __x)
      noexcept(noexcept(_Iterator(__x)))
      : current(__x)
      { }
     
      reverse_iterator(const reverse_iterator& __x)
      noexcept(noexcept(_Iterator(__x.current)))
      : current(__x.current)
      { }
      reverse_iterator& operator=(const reverse_iterator&) = default;
      template<typename _Iter>

        reverse_iterator(const reverse_iterator<_Iter>& __x)
 noexcept(noexcept(_Iterator(__x.current)))
 : current(__x.current)
 { }
      template<typename _Iter>

 reverse_iterator&
 operator=(const reverse_iterator<_Iter>& __x)
 noexcept(noexcept(current = __x.current))
 {
   current = __x.current;
   return *this;
 }
     
      iterator_type
      base() const
      noexcept(noexcept(_Iterator(current)))
      { return current; }
     
      reference
      operator*() const
      {
 _Iterator __tmp = current;
 return *--__tmp;
      }
     
      pointer
      operator->() const
      {
 _Iterator __tmp = current;
 --__tmp;
 return _S_to_pointer(__tmp);
      }
      reverse_iterator&
      operator++()
      {
 --current;
 return *this;
      }
      reverse_iterator
      operator++(int)
      {
 reverse_iterator __tmp = *this;
 --current;
 return __tmp;
      }
      reverse_iterator&
      operator--()
      {
 ++current;
 return *this;
      }
      reverse_iterator
      operator--(int)
      {
 reverse_iterator __tmp = *this;
 ++current;
 return __tmp;
      }
     
      reverse_iterator
      operator+(difference_type __n) const
      { return reverse_iterator(current - __n); }
      reverse_iterator&
      operator+=(difference_type __n)
      {
 current -= __n;
 return *this;
      }
     
      reverse_iterator
      operator-(difference_type __n) const
      { return reverse_iterator(current + __n); }
      reverse_iterator&
      operator-=(difference_type __n)
      {
 current += __n;
 return *this;
      }
     
      reference
      operator[](difference_type __n) const
      { return *(*this + __n); }
    private:
      template<typename _Tp>
 static _Tp*
 _S_to_pointer(_Tp* __p)
        { return __p; }
      template<typename _Tp>
 static pointer
 _S_to_pointer(_Tp __t)
        { return __t.operator->(); }
    };
  template<typename _Iterator>
   
    inline bool
    operator==(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return __x.base() == __y.base(); }
  template<typename _Iterator>
   
    inline bool
    operator<(const reverse_iterator<_Iterator>& __x,
       const reverse_iterator<_Iterator>& __y)
    { return __y.base() < __x.base(); }
  template<typename _Iterator>
   
    inline bool
    operator!=(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return !(__x == __y); }
  template<typename _Iterator>
   
    inline bool
    operator>(const reverse_iterator<_Iterator>& __x,
       const reverse_iterator<_Iterator>& __y)
    { return __y < __x; }
  template<typename _Iterator>
   
    inline bool
    operator<=(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return !(__y < __x); }
  template<typename _Iterator>
   
    inline bool
    operator>=(const reverse_iterator<_Iterator>& __x,
        const reverse_iterator<_Iterator>& __y)
    { return !(__x < __y); }
  template<typename _IteratorL, typename _IteratorR>
   
    inline bool
    operator==(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return __x.base() == __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
   
    inline bool
    operator<(const reverse_iterator<_IteratorL>& __x,
       const reverse_iterator<_IteratorR>& __y)
    { return __x.base() > __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
   
    inline bool
    operator!=(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return __x.base() != __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
   
    inline bool
    operator>(const reverse_iterator<_IteratorL>& __x,
       const reverse_iterator<_IteratorR>& __y)
    { return __x.base() < __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<=(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return __x.base() >= __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
   
    inline bool
    operator>=(const reverse_iterator<_IteratorL>& __x,
        const reverse_iterator<_IteratorR>& __y)
    { return __x.base() <= __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline auto
    operator-(const reverse_iterator<_IteratorL>& __x,
       const reverse_iterator<_IteratorR>& __y)
    -> decltype(__y.base() - __x.base())
    { return __y.base() - __x.base(); }
  template<typename _Iterator>
   
    inline reverse_iterator<_Iterator>
    operator+(typename reverse_iterator<_Iterator>::difference_type __n,
       const reverse_iterator<_Iterator>& __x)
    { return reverse_iterator<_Iterator>(__x.base() - __n); }
  template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    __make_reverse_iterator(_Iterator __i)
    { return reverse_iterator<_Iterator>(__i); }
  template<typename _Iterator>
   
    auto
    __niter_base(reverse_iterator<_Iterator> __it)
    -> decltype(__make_reverse_iterator(__niter_base(__it.base())))
    { return __make_reverse_iterator(__niter_base(__it.base())); }
  template<typename _Iterator>
    struct __is_move_iterator<reverse_iterator<_Iterator> >
      : __is_move_iterator<_Iterator>
    { };
  template<typename _Iterator>
   
    auto
    __miter_base(reverse_iterator<_Iterator> __it)
    -> decltype(__make_reverse_iterator(__miter_base(__it.base())))
    { return __make_reverse_iterator(__miter_base(__it.base())); }
  template<typename _Container>
    class back_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;
    public:
      typedef _Container container_type;
      explicit
      back_insert_iterator(_Container& __x)
      : container(std::__addressof(__x)) { }
     
      back_insert_iterator&
      operator=(const typename _Container::value_type& __value)
      {
 container->push_back(__value);
 return *this;
      }
     
      back_insert_iterator&
      operator=(typename _Container::value_type&& __value)
      {
 container->push_back(std::move(__value));
 return *this;
      }
     
      back_insert_iterator&
      operator*()
      { return *this; }
     
      back_insert_iterator&
      operator++()
      { return *this; }
     
      back_insert_iterator
      operator++(int)
      { return *this; }
    };
  template<typename _Container>
   
    inline back_insert_iterator<_Container>
    back_inserter(_Container& __x)
    { return back_insert_iterator<_Container>(__x); }
  template<typename _Container>
    class front_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;
    public:
      typedef _Container container_type;
      explicit
      front_insert_iterator(_Container& __x)
      : container(std::__addressof(__x)) { }
     
      front_insert_iterator&
      operator=(const typename _Container::value_type& __value)
      {
 container->push_front(__value);
 return *this;
      }
     
      front_insert_iterator&
      operator=(typename _Container::value_type&& __value)
      {
 container->push_front(std::move(__value));
 return *this;
      }
     
      front_insert_iterator&
      operator*()
      { return *this; }
     
      front_insert_iterator&
      operator++()
      { return *this; }
     
      front_insert_iterator
      operator++(int)
      { return *this; }
    };
  template<typename _Container>
   
    inline front_insert_iterator<_Container>
    front_inserter(_Container& __x)
    { return front_insert_iterator<_Container>(__x); }
  template<typename _Container>
    class insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
      typedef typename _Container::iterator _Iter;
    protected:
      _Container* container;
      _Iter iter;
    public:
      typedef _Container container_type;
     
      insert_iterator(_Container& __x, _Iter __i)
      : container(std::__addressof(__x)), iter(__i) {}
     
      insert_iterator&
      operator=(const typename _Container::value_type& __value)
      {
 iter = container->insert(iter, __value);
 ++iter;
 return *this;
      }
     
      insert_iterator&
      operator=(typename _Container::value_type&& __value)
      {
 iter = container->insert(iter, std::move(__value));
 ++iter;
 return *this;
      }
     
      insert_iterator&
      operator*()
      { return *this; }
     
      insert_iterator&
      operator++()
      { return *this; }
     
      insert_iterator&
      operator++(int)
      { return *this; }
    };
#pragma GCC diagnostic pop
  template<typename _Container>
   
    inline insert_iterator<_Container>
    inserter(_Container& __x, typename _Container::iterator __i)
    { return insert_iterator<_Container>(__x, __i); }

}
namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

  template<typename _Iterator, typename _Container>
    class __normal_iterator
    {
    protected:
      _Iterator _M_current;
      typedef std::iterator_traits<_Iterator> __traits_type;
      template<typename _Iter>
 using __convertible_from
   = std::__enable_if_t<std::is_convertible<_Iter, _Iterator>::value>;
    public:
      typedef _Iterator iterator_type;
      typedef typename __traits_type::iterator_category iterator_category;
      typedef typename __traits_type::value_type value_type;
      typedef typename __traits_type::difference_type difference_type;
      typedef typename __traits_type::reference reference;
      typedef typename __traits_type::pointer pointer;
      constexpr __normal_iterator() noexcept
      : _M_current(_Iterator()) { }
      explicit
      __normal_iterator(const _Iterator& __i) noexcept
      : _M_current(__i) { }
      template<typename _Iter, typename = __convertible_from<_Iter>>

 __normal_iterator(const __normal_iterator<_Iter, _Container>& __i)
 noexcept
        : _M_current(__i.base()) { }
     
      reference
      operator*() const noexcept
      { return *_M_current; }
     
      pointer
      operator->() const noexcept
      { return _M_current; }
     
      __normal_iterator&
      operator++() noexcept
      {
 ++_M_current;
 return *this;
      }
     
      __normal_iterator
      operator++(int) noexcept
      { return __normal_iterator(_M_current++); }
     
      __normal_iterator&
      operator--() noexcept
      {
 --_M_current;
 return *this;
      }
     
      __normal_iterator
      operator--(int) noexcept
      { return __normal_iterator(_M_current--); }
     
      reference
      operator[](difference_type __n) const noexcept
      { return _M_current[__n]; }
     
      __normal_iterator&
      operator+=(difference_type __n) noexcept
      { _M_current += __n; return *this; }
     
      __normal_iterator
      operator+(difference_type __n) const noexcept
      { return __normal_iterator(_M_current + __n); }
     
      __normal_iterator&
      operator-=(difference_type __n) noexcept
      { _M_current -= __n; return *this; }
     
      __normal_iterator
      operator-(difference_type __n) const noexcept
      { return __normal_iterator(_M_current - __n); }
     
      const _Iterator&
      base() const noexcept
      { return _M_current; }
    };
  template<typename _IteratorL, typename _IteratorR, typename _Container>
   
    inline bool
    operator==(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() == __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline bool
    operator==(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() == __rhs.base(); }
  template<typename _IteratorL, typename _IteratorR, typename _Container>
   
    inline bool
    operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline bool
    operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }
  template<typename _IteratorL, typename _IteratorR, typename _Container>
   
    inline bool
    operator<(const __normal_iterator<_IteratorL, _Container>& __lhs,
       const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline bool
    operator<(const __normal_iterator<_Iterator, _Container>& __lhs,
       const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }
  template<typename _IteratorL, typename _IteratorR, typename _Container>
   
    inline bool
    operator>(const __normal_iterator<_IteratorL, _Container>& __lhs,
       const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline bool
    operator>(const __normal_iterator<_Iterator, _Container>& __lhs,
       const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }
  template<typename _IteratorL, typename _IteratorR, typename _Container>
   
    inline bool
    operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline bool
    operator<=(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }
  template<typename _IteratorL, typename _IteratorR, typename _Container>
   
    inline bool
    operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs,
        const __normal_iterator<_IteratorR, _Container>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline bool
    operator>=(const __normal_iterator<_Iterator, _Container>& __lhs,
        const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }
  template<typename _IteratorL, typename _IteratorR, typename _Container>
    [[__nodiscard__]]
    inline auto
    operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
       const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept
    -> decltype(__lhs.base() - __rhs.base())
    { return __lhs.base() - __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline typename __normal_iterator<_Iterator, _Container>::difference_type
    operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
       const __normal_iterator<_Iterator, _Container>& __rhs)
    noexcept
    { return __lhs.base() - __rhs.base(); }
  template<typename _Iterator, typename _Container>
   
    inline __normal_iterator<_Iterator, _Container>
    operator+(typename __normal_iterator<_Iterator, _Container>::difference_type
       __n, const __normal_iterator<_Iterator, _Container>& __i)
    noexcept
    { return __normal_iterator<_Iterator, _Container>(__i.base() + __n); }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Iterator, typename _Container>
   
    _Iterator
    __niter_base(__gnu_cxx::__normal_iterator<_Iterator, _Container> __it)
    noexcept(std::is_nothrow_copy_constructible<_Iterator>::value)
    { return __it.base(); }
  template<typename _Iterator, typename _Container>
    constexpr auto
    __to_address(const __gnu_cxx::__normal_iterator<_Iterator,
          _Container>& __it) noexcept
    -> decltype(std::__to_address(__it.base()))
    { return std::__to_address(__it.base()); }
  namespace __detail
  {
  }
  template<typename _Iterator>
    class move_iterator
    {
      _Iterator _M_current;
      using __traits_type = iterator_traits<_Iterator>;
      using __base_ref = typename __traits_type::reference;
      template<typename _Iter2>
 friend class move_iterator;
    public:
      using iterator_type = _Iterator;
      typedef typename __traits_type::iterator_category iterator_category;
      typedef typename __traits_type::value_type value_type;
      typedef typename __traits_type::difference_type difference_type;
      typedef _Iterator pointer;
      using reference
 = __conditional_t<is_reference<__base_ref>::value,
     typename remove_reference<__base_ref>::type&&,
     __base_ref>;
     
      move_iterator()
      : _M_current() { }
      explicit
      move_iterator(iterator_type __i)
      : _M_current(std::move(__i)) { }
      template<typename _Iter>

 move_iterator(const move_iterator<_Iter>& __i)
 : _M_current(__i._M_current) { }
      template<typename _Iter>

 move_iterator& operator=(const move_iterator<_Iter>& __i)
 {
   _M_current = __i._M_current;
   return *this;
 }
      [[__nodiscard__]]
      iterator_type
      base() const
      { return _M_current; }
      [[__nodiscard__]]
      reference
      operator*() const
      { return static_cast<reference>(*_M_current); }
      [[__nodiscard__]]
      pointer
      operator->() const
      { return _M_current; }
      move_iterator&
      operator++()
      {
 ++_M_current;
 return *this;
      }
      move_iterator
      operator++(int)
      {
 move_iterator __tmp = *this;
 ++_M_current;
 return __tmp;
      }
      move_iterator&
      operator--()
      {
 --_M_current;
 return *this;
      }
      move_iterator
      operator--(int)
      {
 move_iterator __tmp = *this;
 --_M_current;
 return __tmp;
      }
      [[__nodiscard__]]
      move_iterator
      operator+(difference_type __n) const
      { return move_iterator(_M_current + __n); }
      move_iterator&
      operator+=(difference_type __n)
      {
 _M_current += __n;
 return *this;
      }
      [[__nodiscard__]]
      move_iterator
      operator-(difference_type __n) const
      { return move_iterator(_M_current - __n); }
      move_iterator&
      operator-=(difference_type __n)
      {
 _M_current -= __n;
 return *this;
      }
      [[__nodiscard__]]
      reference
      operator[](difference_type __n) const
      { return std::move(_M_current[__n]); }
    };
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline bool
    operator==(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return __x.base() == __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline bool
    operator!=(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return !(__x == __y); }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline bool
    operator<(const move_iterator<_IteratorL>& __x,
       const move_iterator<_IteratorR>& __y)
    { return __x.base() < __y.base(); }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline bool
    operator<=(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return !(__y < __x); }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline bool
    operator>(const move_iterator<_IteratorL>& __x,
       const move_iterator<_IteratorR>& __y)
    { return __y < __x; }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline bool
    operator>=(const move_iterator<_IteratorL>& __x,
        const move_iterator<_IteratorR>& __y)
    { return !(__x < __y); }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline bool
    operator==(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return __x.base() == __y.base(); }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline bool
    operator!=(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return !(__x == __y); }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline bool
    operator<(const move_iterator<_Iterator>& __x,
       const move_iterator<_Iterator>& __y)
    { return __x.base() < __y.base(); }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline bool
    operator<=(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return !(__y < __x); }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline bool
    operator>(const move_iterator<_Iterator>& __x,
       const move_iterator<_Iterator>& __y)
    { return __y < __x; }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline bool
    operator>=(const move_iterator<_Iterator>& __x,
        const move_iterator<_Iterator>& __y)
    { return !(__x < __y); }
  template<typename _IteratorL, typename _IteratorR>
    [[__nodiscard__]]
    inline auto
    operator-(const move_iterator<_IteratorL>& __x,
       const move_iterator<_IteratorR>& __y)
    -> decltype(__x.base() - __y.base())
    { return __x.base() - __y.base(); }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline move_iterator<_Iterator>
    operator+(typename move_iterator<_Iterator>::difference_type __n,
       const move_iterator<_Iterator>& __x)
    { return __x + __n; }
  template<typename _Iterator>
    [[__nodiscard__]]
    inline move_iterator<_Iterator>
    make_move_iterator(_Iterator __i)
    { return move_iterator<_Iterator>(std::move(__i)); }
  template<typename _Iterator, typename _ReturnType
    = __conditional_t<__move_if_noexcept_cond
      <typename iterator_traits<_Iterator>::value_type>::value,
  _Iterator, move_iterator<_Iterator>>>
    inline _ReturnType
    __make_move_if_noexcept_iterator(_Iterator __i)
    { return _ReturnType(__i); }
  template<typename _Tp, typename _ReturnType
    = __conditional_t<__move_if_noexcept_cond<_Tp>::value,
        const _Tp*, move_iterator<_Tp*>>>
    inline _ReturnType
    __make_move_if_noexcept_iterator(_Tp* __i)
    { return _ReturnType(__i); }
  template<typename _Iterator>
   
    auto
    __niter_base(move_iterator<_Iterator> __it)
    -> decltype(make_move_iterator(__niter_base(__it.base())))
    { return make_move_iterator(__niter_base(__it.base())); }
  template<typename _Iterator>
    struct __is_move_iterator<move_iterator<_Iterator> >
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };
  template<typename _Iterator>
   
    auto
    __miter_base(move_iterator<_Iterator> __it)
    -> decltype(__miter_base(__it.base()))
    { return __miter_base(__it.base()); }

}
namespace std
{
  namespace __debug { }
}
namespace __gnu_debug
{
  using namespace std::__debug;
  template<typename _Ite, typename _Seq, typename _Cat>
    struct _Safe_iterator;
}
namespace __gnu_cxx
{
namespace __ops
{
  struct _Iter_less_iter
  {
    template<typename _Iterator1, typename _Iterator2>
     
      bool
      operator()(_Iterator1 __it1, _Iterator2 __it2) const
      { return *__it1 < *__it2; }
  };
 
  inline _Iter_less_iter
  __iter_less_iter()
  { return _Iter_less_iter(); }
  struct _Iter_less_val
  {
    constexpr _Iter_less_val() = default;
   
    explicit
    _Iter_less_val(_Iter_less_iter) { }
    template<typename _Iterator, typename _Value>
     
      bool
      operator()(_Iterator __it, _Value& __val) const
      { return *__it < __val; }
  };
 
  inline _Iter_less_val
  __iter_less_val()
  { return _Iter_less_val(); }
 
  inline _Iter_less_val
  __iter_comp_val(_Iter_less_iter)
  { return _Iter_less_val(); }
  struct _Val_less_iter
  {
    constexpr _Val_less_iter() = default;
   
    explicit
    _Val_less_iter(_Iter_less_iter) { }
    template<typename _Value, typename _Iterator>
     
      bool
      operator()(_Value& __val, _Iterator __it) const
      { return __val < *__it; }
  };
 
  inline _Val_less_iter
  __val_less_iter()
  { return _Val_less_iter(); }
 
  inline _Val_less_iter
  __val_comp_iter(_Iter_less_iter)
  { return _Val_less_iter(); }
  struct _Iter_equal_to_iter
  {
    template<typename _Iterator1, typename _Iterator2>
     
      bool
      operator()(_Iterator1 __it1, _Iterator2 __it2) const
      { return *__it1 == *__it2; }
  };
 
  inline _Iter_equal_to_iter
  __iter_equal_to_iter()
  { return _Iter_equal_to_iter(); }
  struct _Iter_equal_to_val
  {
    template<typename _Iterator, typename _Value>
     
      bool
      operator()(_Iterator __it, _Value& __val) const
      { return *__it == __val; }
  };
 
  inline _Iter_equal_to_val
  __iter_equal_to_val()
  { return _Iter_equal_to_val(); }
 
  inline _Iter_equal_to_val
  __iter_comp_val(_Iter_equal_to_iter)
  { return _Iter_equal_to_val(); }
  template<typename _Compare>
    struct _Iter_comp_iter
    {
      _Compare _M_comp;
      explicit
      _Iter_comp_iter(_Compare __comp)
 : _M_comp(std::move(__comp))
      { }
      template<typename _Iterator1, typename _Iterator2>
       
        bool
        operator()(_Iterator1 __it1, _Iterator2 __it2)
        { return bool(_M_comp(*__it1, *__it2)); }
    };
  template<typename _Compare>
   
    inline _Iter_comp_iter<_Compare>
    __iter_comp_iter(_Compare __comp)
    { return _Iter_comp_iter<_Compare>(std::move(__comp)); }
  template<typename _Compare>
    struct _Iter_comp_val
    {
      _Compare _M_comp;
     
      explicit
      _Iter_comp_val(_Compare __comp)
 : _M_comp(std::move(__comp))
      { }
     
      explicit
      _Iter_comp_val(const _Iter_comp_iter<_Compare>& __comp)
 : _M_comp(__comp._M_comp)
      { }
     
      explicit
      _Iter_comp_val(_Iter_comp_iter<_Compare>&& __comp)
 : _M_comp(std::move(__comp._M_comp))
      { }
      template<typename _Iterator, typename _Value>

 bool
 operator()(_Iterator __it, _Value& __val)
 { return bool(_M_comp(*__it, __val)); }
    };
  template<typename _Compare>
   
    inline _Iter_comp_val<_Compare>
    __iter_comp_val(_Compare __comp)
    { return _Iter_comp_val<_Compare>(std::move(__comp)); }
  template<typename _Compare>
   
    inline _Iter_comp_val<_Compare>
    __iter_comp_val(_Iter_comp_iter<_Compare> __comp)
    { return _Iter_comp_val<_Compare>(std::move(__comp)); }
  template<typename _Compare>
    struct _Val_comp_iter
    {
      _Compare _M_comp;
     
      explicit
      _Val_comp_iter(_Compare __comp)
 : _M_comp(std::move(__comp))
      { }
     
      explicit
      _Val_comp_iter(const _Iter_comp_iter<_Compare>& __comp)
 : _M_comp(__comp._M_comp)
      { }
     
      explicit
      _Val_comp_iter(_Iter_comp_iter<_Compare>&& __comp)
 : _M_comp(std::move(__comp._M_comp))
      { }
      template<typename _Value, typename _Iterator>

 bool
 operator()(_Value& __val, _Iterator __it)
 { return bool(_M_comp(__val, *__it)); }
    };
  template<typename _Compare>
   
    inline _Val_comp_iter<_Compare>
    __val_comp_iter(_Compare __comp)
    { return _Val_comp_iter<_Compare>(std::move(__comp)); }
  template<typename _Compare>
   
    inline _Val_comp_iter<_Compare>
    __val_comp_iter(_Iter_comp_iter<_Compare> __comp)
    { return _Val_comp_iter<_Compare>(std::move(__comp)); }
  template<typename _Value>
    struct _Iter_equals_val
    {
      _Value& _M_value;
     
      explicit
      _Iter_equals_val(_Value& __value)
 : _M_value(__value)
      { }
      template<typename _Iterator>

 bool
 operator()(_Iterator __it)
 { return *__it == _M_value; }
    };
  template<typename _Value>
   
    inline _Iter_equals_val<_Value>
    __iter_equals_val(_Value& __val)
    { return _Iter_equals_val<_Value>(__val); }
  template<typename _Iterator1>
    struct _Iter_equals_iter
    {
      _Iterator1 _M_it1;
     
      explicit
      _Iter_equals_iter(_Iterator1 __it1)
 : _M_it1(__it1)
      { }
      template<typename _Iterator2>

 bool
 operator()(_Iterator2 __it2)
 { return *__it2 == *_M_it1; }
    };
  template<typename _Iterator>
   
    inline _Iter_equals_iter<_Iterator>
    __iter_comp_iter(_Iter_equal_to_iter, _Iterator __it)
    { return _Iter_equals_iter<_Iterator>(__it); }
  template<typename _Predicate>
    struct _Iter_pred
    {
      _Predicate _M_pred;
     
      explicit
      _Iter_pred(_Predicate __pred)
 : _M_pred(std::move(__pred))
      { }
      template<typename _Iterator>

 bool
 operator()(_Iterator __it)
 { return bool(_M_pred(*__it)); }
    };
  template<typename _Predicate>
   
    inline _Iter_pred<_Predicate>
    __pred_iter(_Predicate __pred)
    { return _Iter_pred<_Predicate>(std::move(__pred)); }
  template<typename _Compare, typename _Value>
    struct _Iter_comp_to_val
    {
      _Compare _M_comp;
      _Value& _M_value;
     
      _Iter_comp_to_val(_Compare __comp, _Value& __value)
 : _M_comp(std::move(__comp)), _M_value(__value)
      { }
      template<typename _Iterator>

 bool
 operator()(_Iterator __it)
 { return bool(_M_comp(*__it, _M_value)); }
    };
  template<typename _Compare, typename _Value>
    _Iter_comp_to_val<_Compare, _Value>
   
    __iter_comp_val(_Compare __comp, _Value &__val)
    {
      return _Iter_comp_to_val<_Compare, _Value>(std::move(__comp), __val);
    }
  template<typename _Compare, typename _Iterator1>
    struct _Iter_comp_to_iter
    {
      _Compare _M_comp;
      _Iterator1 _M_it1;
     
      _Iter_comp_to_iter(_Compare __comp, _Iterator1 __it1)
 : _M_comp(std::move(__comp)), _M_it1(__it1)
      { }
      template<typename _Iterator2>

 bool
 operator()(_Iterator2 __it2)
 { return bool(_M_comp(*__it2, *_M_it1)); }
    };
  template<typename _Compare, typename _Iterator>
   
    inline _Iter_comp_to_iter<_Compare, _Iterator>
    __iter_comp_iter(_Iter_comp_iter<_Compare> __comp, _Iterator __it)
    {
      return _Iter_comp_to_iter<_Compare, _Iterator>(
   std::move(__comp._M_comp), __it);
    }
  template<typename _Predicate>
    struct _Iter_negate
    {
      _Predicate _M_pred;
     
      explicit
      _Iter_negate(_Predicate __pred)
 : _M_pred(std::move(__pred))
      { }
      template<typename _Iterator>

 bool
 operator()(_Iterator __it)
 { return !bool(_M_pred(*__it)); }
    };
  template<typename _Predicate>
   
    inline _Iter_negate<_Predicate>
    __negate(_Iter_pred<_Predicate> __pred)
    { return _Iter_negate<_Predicate>(std::move(__pred._M_pred)); }
}
}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp, typename _Up>
   
    inline int
    __memcmp(const _Tp* __first1, const _Up* __first2, size_t __num)
    {
      static_assert(sizeof(_Tp) == sizeof(_Up), "can be compared with memcmp");
 return __builtin_memcmp(__first1, __first2, sizeof(_Tp) * __num);
    }
  template<typename _ForwardIterator1, typename _ForwardIterator2>
   
    inline void
    iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
    {
     
     
      swap(*__a, *__b);
    }
  template<typename _ForwardIterator1, typename _ForwardIterator2>
   
    _ForwardIterator2
    swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
  _ForwardIterator2 __first2)
    {
     
     
      ;
      for (; __first1 != __last1; ++__first1, (void)++__first2)
 std::iter_swap(__first1, __first2);
      return __first2;
    }
  template<typename _Tp>
   
    inline const _Tp&
    min(const _Tp& __a, const _Tp& __b)
    {
     
      if (__b < __a)
 return __b;
      return __a;
    }
  template<typename _Tp>
   
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b)
    {
     
      if (__a < __b)
 return __b;
      return __a;
    }
  template<typename _Tp, typename _Compare>
   
    inline const _Tp&
    min(const _Tp& __a, const _Tp& __b, _Compare __comp)
    {
      if (__comp(__b, __a))
 return __b;
      return __a;
    }
  template<typename _Tp, typename _Compare>
   
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b, _Compare __comp)
    {
      if (__comp(__a, __b))
 return __b;
      return __a;
    }
  template<typename _Iterator>
   
    inline _Iterator
    __niter_base(_Iterator __it)
    noexcept(std::is_nothrow_copy_constructible<_Iterator>::value)
    { return __it; }
  template<typename _Ite, typename _Seq>
    _Ite
    __niter_base(const ::__gnu_debug::_Safe_iterator<_Ite, _Seq,
   std::random_access_iterator_tag>&);
  template<typename _From, typename _To>
   
    inline _From
    __niter_wrap(_From __from, _To __res)
    { return __from + (__res - std::__niter_base(__from)); }
  template<typename _Iterator>
   
    inline _Iterator
    __niter_wrap(const _Iterator&, _Iterator __res)
    { return __res; }
  template<bool _IsMove, bool _IsSimple, typename _Category>
    struct __copy_move
    {
      template<typename _II, typename _OI>

 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   for (; __first != __last; ++__result, (void)++__first)
     *__result = *__first;
   return __result;
 }
    };
  template<typename _Category>
    struct __copy_move<true, false, _Category>
    {
      template<typename _II, typename _OI>

 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   for (; __first != __last; ++__result, (void)++__first)
     *__result = std::move(*__first);
   return __result;
 }
    };
  template<>
    struct __copy_move<false, false, random_access_iterator_tag>
    {
      template<typename _II, typename _OI>

 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   typedef typename iterator_traits<_II>::difference_type _Distance;
   for(_Distance __n = __last - __first; __n > 0; --__n)
     {
       *__result = *__first;
       ++__first;
       ++__result;
     }
   return __result;
 }
      template<typename _Tp, typename _Up>
 static void
 __assign_one(_Tp* __to, _Up* __from)
 { *__to = *__from; }
    };
  template<>
    struct __copy_move<true, false, random_access_iterator_tag>
    {
      template<typename _II, typename _OI>

 static _OI
 __copy_m(_II __first, _II __last, _OI __result)
 {
   typedef typename iterator_traits<_II>::difference_type _Distance;
   for(_Distance __n = __last - __first; __n > 0; --__n)
     {
       *__result = std::move(*__first);
       ++__first;
       ++__result;
     }
   return __result;
 }
      template<typename _Tp, typename _Up>
 static void
 __assign_one(_Tp* __to, _Up* __from)
 { *__to = std::move(*__from); }
    };
  template<bool _IsMove>
    struct __copy_move<_IsMove, true, random_access_iterator_tag>
    {
      template<typename _Tp, typename _Up>

 static _Up*
 __copy_m(_Tp* __first, _Tp* __last, _Up* __result)
 {
   const ptrdiff_t _Num = __last - __first;
   if (__builtin_expect(_Num > 1, true))
     __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
   else if (_Num == 1)
     std::__copy_move<_IsMove, false, random_access_iterator_tag>::
       __assign_one(__result, __first);
   return __result + _Num;
 }
    };

  template<typename _Tp, typename _Ref, typename _Ptr>
    struct _Deque_iterator;
  struct _Bit_iterator;

  template<typename _CharT>
    struct char_traits;
  template<typename _CharT, typename _Traits>
    class istreambuf_iterator;
  template<typename _CharT, typename _Traits>
    class ostreambuf_iterator;
  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT> > >::__type
    __copy_move_a2(_CharT*, _CharT*,
     ostreambuf_iterator<_CharT, char_traits<_CharT> >);
  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT> > >::__type
    __copy_move_a2(const _CharT*, const _CharT*,
     ostreambuf_iterator<_CharT, char_traits<_CharT> >);
  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value,
        _CharT*>::__type
    __copy_move_a2(istreambuf_iterator<_CharT, char_traits<_CharT> >,
     istreambuf_iterator<_CharT, char_traits<_CharT> >, _CharT*);
  template<bool _IsMove, typename _CharT>
    typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      std::_Deque_iterator<_CharT, _CharT&, _CharT*> >::__type
    __copy_move_a2(
 istreambuf_iterator<_CharT, char_traits<_CharT> >,
 istreambuf_iterator<_CharT, char_traits<_CharT> >,
 std::_Deque_iterator<_CharT, _CharT&, _CharT*>);
  template<bool _IsMove, typename _II, typename _OI>
   
    inline _OI
    __copy_move_a2(_II __first, _II __last, _OI __result)
    {
      typedef typename iterator_traits<_II>::iterator_category _Category;
      return std::__copy_move<_IsMove, __memcpyable<_OI, _II>::__value,
         _Category>::__copy_m(__first, __last, __result);
    }
  template<bool _IsMove,
    typename _Tp, typename _Ref, typename _Ptr, typename _OI>
    _OI
    __copy_move_a1(std::_Deque_iterator<_Tp, _Ref, _Ptr>,
     std::_Deque_iterator<_Tp, _Ref, _Ptr>,
     _OI);
  template<bool _IsMove,
    typename _ITp, typename _IRef, typename _IPtr, typename _OTp>
    std::_Deque_iterator<_OTp, _OTp&, _OTp*>
    __copy_move_a1(std::_Deque_iterator<_ITp, _IRef, _IPtr>,
     std::_Deque_iterator<_ITp, _IRef, _IPtr>,
     std::_Deque_iterator<_OTp, _OTp&, _OTp*>);
  template<bool _IsMove, typename _II, typename _Tp>
    typename __gnu_cxx::__enable_if<
      __is_random_access_iter<_II>::__value,
      std::_Deque_iterator<_Tp, _Tp&, _Tp*> >::__type
    __copy_move_a1(_II, _II, std::_Deque_iterator<_Tp, _Tp&, _Tp*>);
  template<bool _IsMove, typename _II, typename _OI>
   
    inline _OI
    __copy_move_a1(_II __first, _II __last, _OI __result)
    { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
  template<bool _IsMove, typename _II, typename _OI>
   
    inline _OI
    __copy_move_a(_II __first, _II __last, _OI __result)
    {
      return std::__niter_wrap(__result,
  std::__copy_move_a1<_IsMove>(std::__niter_base(__first),
          std::__niter_base(__last),
          std::__niter_base(__result)));
    }
  template<bool _IsMove,
    typename _Ite, typename _Seq, typename _Cat, typename _OI>
    _OI
    __copy_move_a(const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&,
    const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&,
    _OI);
  template<bool _IsMove,
    typename _II, typename _Ite, typename _Seq, typename _Cat>
    __gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>
    __copy_move_a(_II, _II,
    const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&);
  template<bool _IsMove,
    typename _IIte, typename _ISeq, typename _ICat,
    typename _OIte, typename _OSeq, typename _OCat>
    ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat>
    __copy_move_a(const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat>&,
    const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat>&,
    const ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat>&);
  template<typename _InputIterator, typename _Size, typename _OutputIterator>
   
    _OutputIterator
    __copy_n_a(_InputIterator __first, _Size __n, _OutputIterator __result,
        bool)
    {
      if (__n > 0)
 {
   while (true)
     {
       *__result = *__first;
       ++__result;
       if (--__n > 0)
  ++__first;
       else
  break;
     }
 }
      return __result;
    }
  template<typename _CharT, typename _Size>
    typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value, _CharT*>::__type
    __copy_n_a(istreambuf_iterator<_CharT, char_traits<_CharT> >,
        _Size, _CharT*, bool);
  template<typename _CharT, typename _Size>
    typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      std::_Deque_iterator<_CharT, _CharT&, _CharT*> >::__type
    __copy_n_a(istreambuf_iterator<_CharT, char_traits<_CharT> >, _Size,
        std::_Deque_iterator<_CharT, _CharT&, _CharT*>,
        bool);
  template<typename _II, typename _OI>
   
    inline _OI
    copy(_II __first, _II __last, _OI __result)
    {
     
     
      ;
      return std::__copy_move_a<__is_move_iterator<_II>::__value>
      (std::__miter_base(__first), std::__miter_base(__last), __result);
    }
  template<typename _II, typename _OI>
   
    inline _OI
    move(_II __first, _II __last, _OI __result)
    {
     
     
      ;
      return std::__copy_move_a<true>(std::__miter_base(__first),
          std::__miter_base(__last), __result);
    }
  template<bool _IsMove, bool _IsSimple, typename _Category>
    struct __copy_move_backward
    {
      template<typename _BI1, typename _BI2>

 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   while (__first != __last)
     *--__result = *--__last;
   return __result;
 }
    };
  template<typename _Category>
    struct __copy_move_backward<true, false, _Category>
    {
      template<typename _BI1, typename _BI2>

 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   while (__first != __last)
     *--__result = std::move(*--__last);
   return __result;
 }
    };
  template<>
    struct __copy_move_backward<false, false, random_access_iterator_tag>
    {
      template<typename _BI1, typename _BI2>

 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   typename iterator_traits<_BI1>::difference_type
     __n = __last - __first;
   for (; __n > 0; --__n)
     *--__result = *--__last;
   return __result;
 }
    };
  template<>
    struct __copy_move_backward<true, false, random_access_iterator_tag>
    {
      template<typename _BI1, typename _BI2>

 static _BI2
 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
 {
   typename iterator_traits<_BI1>::difference_type
     __n = __last - __first;
   for (; __n > 0; --__n)
     *--__result = std::move(*--__last);
   return __result;
 }
    };
  template<bool _IsMove>
    struct __copy_move_backward<_IsMove, true, random_access_iterator_tag>
    {
      template<typename _Tp, typename _Up>

 static _Up*
 __copy_move_b(_Tp* __first, _Tp* __last, _Up* __result)
 {
   const ptrdiff_t _Num = __last - __first;
   if (__builtin_expect(_Num > 1, true))
     __builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
   else if (_Num == 1)
     std::__copy_move<_IsMove, false, random_access_iterator_tag>::
       __assign_one(__result - 1, __first);
   return __result - _Num;
 }
    };
  template<bool _IsMove, typename _BI1, typename _BI2>
   
    inline _BI2
    __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result)
    {
      typedef typename iterator_traits<_BI1>::iterator_category _Category;
      return std::__copy_move_backward<_IsMove,
           __memcpyable<_BI2, _BI1>::__value,
           _Category>::__copy_move_b(__first,
         __last,
         __result);
    }
  template<bool _IsMove, typename _BI1, typename _BI2>
   
    inline _BI2
    __copy_move_backward_a1(_BI1 __first, _BI1 __last, _BI2 __result)
    { return std::__copy_move_backward_a2<_IsMove>(__first, __last, __result); }
  template<bool _IsMove,
    typename _Tp, typename _Ref, typename _Ptr, typename _OI>
    _OI
    __copy_move_backward_a1(std::_Deque_iterator<_Tp, _Ref, _Ptr>,
       std::_Deque_iterator<_Tp, _Ref, _Ptr>,
       _OI);
  template<bool _IsMove,
    typename _ITp, typename _IRef, typename _IPtr, typename _OTp>
    std::_Deque_iterator<_OTp, _OTp&, _OTp*>
    __copy_move_backward_a1(
   std::_Deque_iterator<_ITp, _IRef, _IPtr>,
   std::_Deque_iterator<_ITp, _IRef, _IPtr>,
   std::_Deque_iterator<_OTp, _OTp&, _OTp*>);
  template<bool _IsMove, typename _II, typename _Tp>
    typename __gnu_cxx::__enable_if<
      __is_random_access_iter<_II>::__value,
      std::_Deque_iterator<_Tp, _Tp&, _Tp*> >::__type
    __copy_move_backward_a1(_II, _II,
       std::_Deque_iterator<_Tp, _Tp&, _Tp*>);
  template<bool _IsMove, typename _II, typename _OI>
   
    inline _OI
    __copy_move_backward_a(_II __first, _II __last, _OI __result)
    {
      return std::__niter_wrap(__result,
  std::__copy_move_backward_a1<_IsMove>
    (std::__niter_base(__first), std::__niter_base(__last),
     std::__niter_base(__result)));
    }
  template<bool _IsMove,
    typename _Ite, typename _Seq, typename _Cat, typename _OI>
    _OI
    __copy_move_backward_a(
  const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&,
  const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&,
  _OI);
  template<bool _IsMove,
    typename _II, typename _Ite, typename _Seq, typename _Cat>
    __gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>
    __copy_move_backward_a(_II, _II,
  const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&);
  template<bool _IsMove,
    typename _IIte, typename _ISeq, typename _ICat,
    typename _OIte, typename _OSeq, typename _OCat>
    ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat>
    __copy_move_backward_a(
  const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat>&,
  const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat>&,
  const ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat>&);
  template<typename _BI1, typename _BI2>
   
    inline _BI2
    copy_backward(_BI1 __first, _BI1 __last, _BI2 __result)
    {
     
     
     
      ;
      return std::__copy_move_backward_a<__is_move_iterator<_BI1>::__value>
      (std::__miter_base(__first), std::__miter_base(__last), __result);
    }
  template<typename _BI1, typename _BI2>
   
    inline _BI2
    move_backward(_BI1 __first, _BI1 __last, _BI2 __result)
    {
     
     
     
      ;
      return std::__copy_move_backward_a<true>(std::__miter_base(__first),
            std::__miter_base(__last),
            __result);
    }
  template<typename _ForwardIterator, typename _Tp>
   
    inline typename
    __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type
    __fill_a1(_ForwardIterator __first, _ForwardIterator __last,
       const _Tp& __value)
    {
      for (; __first != __last; ++__first)
 *__first = __value;
    }
  template<typename _ForwardIterator, typename _Tp>
   
    inline typename
    __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type
    __fill_a1(_ForwardIterator __first, _ForwardIterator __last,
       const _Tp& __value)
    {
      const _Tp __tmp = __value;
      for (; __first != __last; ++__first)
 *__first = __tmp;
    }
  template<typename _Tp>
   
    inline typename
    __gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type
    __fill_a1(_Tp* __first, _Tp* __last, const _Tp& __c)
    {
      const _Tp __tmp = __c;
      if (const size_t __len = __last - __first)
 __builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
    }
  template<typename _Ite, typename _Cont, typename _Tp>
   
    inline void
    __fill_a1(::__gnu_cxx::__normal_iterator<_Ite, _Cont> __first,
       ::__gnu_cxx::__normal_iterator<_Ite, _Cont> __last,
       const _Tp& __value)
    { std::__fill_a1(__first.base(), __last.base(), __value); }
  template<typename _Tp, typename _VTp>
    void
    __fill_a1(const std::_Deque_iterator<_Tp, _Tp&, _Tp*>&,
       const std::_Deque_iterator<_Tp, _Tp&, _Tp*>&,
       const _VTp&);
 
  void
  __fill_a1(std::_Bit_iterator, std::_Bit_iterator,
     const bool&);
  template<typename _FIte, typename _Tp>
   
    inline void
    __fill_a(_FIte __first, _FIte __last, const _Tp& __value)
    { std::__fill_a1(__first, __last, __value); }
  template<typename _Ite, typename _Seq, typename _Cat, typename _Tp>
    void
    __fill_a(const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&,
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>&,
      const _Tp&);
  template<typename _ForwardIterator, typename _Tp>
   
    inline void
    fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value)
    {
     
      ;
      std::__fill_a(__first, __last, __value);
    }
  inline constexpr int
  __size_to_integer(int __n) { return __n; }
  inline constexpr unsigned
  __size_to_integer(unsigned __n) { return __n; }
  inline constexpr long
  __size_to_integer(long __n) { return __n; }
  inline constexpr unsigned long
  __size_to_integer(unsigned long __n) { return __n; }
  inline constexpr long long
  __size_to_integer(long long __n) { return __n; }
  inline constexpr unsigned long long
  __size_to_integer(unsigned long long __n) { return __n; }
  inline constexpr long long
  __size_to_integer(float __n) { return (long long)__n; }
  inline constexpr long long
  __size_to_integer(double __n) { return (long long)__n; }
  inline constexpr long long
  __size_to_integer(long double __n) { return (long long)__n; }
  template<typename _OutputIterator, typename _Size, typename _Tp>
   
    inline typename
    __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, _OutputIterator>::__type
    __fill_n_a1(_OutputIterator __first, _Size __n, const _Tp& __value)
    {
      for (; __n > 0; --__n, (void) ++__first)
 *__first = __value;
      return __first;
    }
  template<typename _OutputIterator, typename _Size, typename _Tp>
   
    inline typename
    __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, _OutputIterator>::__type
    __fill_n_a1(_OutputIterator __first, _Size __n, const _Tp& __value)
    {
      const _Tp __tmp = __value;
      for (; __n > 0; --__n, (void) ++__first)
 *__first = __tmp;
      return __first;
    }
  template<typename _Ite, typename _Seq, typename _Cat, typename _Size,
    typename _Tp>
    ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>
    __fill_n_a(const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>& __first,
        _Size __n, const _Tp& __value,
        std::input_iterator_tag);
  template<typename _OutputIterator, typename _Size, typename _Tp>
   
    inline _OutputIterator
    __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value,
        std::output_iterator_tag)
    {
      static_assert(is_integral<_Size>{}, "fill_n must pass integral size");
      return __fill_n_a1(__first, __n, __value);
    }
  template<typename _OutputIterator, typename _Size, typename _Tp>
   
    inline _OutputIterator
    __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value,
        std::input_iterator_tag)
    {
      static_assert(is_integral<_Size>{}, "fill_n must pass integral size");
      return __fill_n_a1(__first, __n, __value);
    }
  template<typename _OutputIterator, typename _Size, typename _Tp>
   
    inline _OutputIterator
    __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value,
        std::random_access_iterator_tag)
    {
      static_assert(is_integral<_Size>{}, "fill_n must pass integral size");
      if (__n <= 0)
 return __first;
      ;
      std::__fill_a(__first, __first + __n, __value);
      return __first + __n;
    }
  template<typename _OI, typename _Size, typename _Tp>
   
    inline _OI
    fill_n(_OI __first, _Size __n, const _Tp& __value)
    {
     
      return std::__fill_n_a(__first, std::__size_to_integer(__n), __value,
          std::__iterator_category(__first));
    }
  template<bool _BoolType>
    struct __equal
    {
      template<typename _II1, typename _II2>

 static bool
 equal(_II1 __first1, _II1 __last1, _II2 __first2)
 {
   for (; __first1 != __last1; ++__first1, (void) ++__first2)
     if (!(*__first1 == *__first2))
       return false;
   return true;
 }
    };
  template<>
    struct __equal<true>
    {
      template<typename _Tp>

 static bool
 equal(const _Tp* __first1, const _Tp* __last1, const _Tp* __first2)
 {
   if (const size_t __len = (__last1 - __first1))
     return !std::__memcmp(__first1, __first2, __len);
   return true;
 }
    };
  template<typename _Tp, typename _Ref, typename _Ptr, typename _II>
    typename __gnu_cxx::__enable_if<
      __is_random_access_iter<_II>::__value, bool>::__type
    __equal_aux1(std::_Deque_iterator<_Tp, _Ref, _Ptr>,
   std::_Deque_iterator<_Tp, _Ref, _Ptr>,
   _II);
  template<typename _Tp1, typename _Ref1, typename _Ptr1,
    typename _Tp2, typename _Ref2, typename _Ptr2>
    bool
    __equal_aux1(std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
   std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
   std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>);
  template<typename _II, typename _Tp, typename _Ref, typename _Ptr>
    typename __gnu_cxx::__enable_if<
      __is_random_access_iter<_II>::__value, bool>::__type
    __equal_aux1(_II, _II,
  std::_Deque_iterator<_Tp, _Ref, _Ptr>);
  template<typename _II1, typename _II2>
   
    inline bool
    __equal_aux1(_II1 __first1, _II1 __last1, _II2 __first2)
    {
      typedef typename iterator_traits<_II1>::value_type _ValueType1;
      const bool __simple = ((__is_integer<_ValueType1>::__value
         || __is_pointer<_ValueType1>::__value)
        && __memcmpable<_II1, _II2>::__value);
      return std::__equal<__simple>::equal(__first1, __last1, __first2);
    }
  template<typename _II1, typename _II2>
   
    inline bool
    __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2)
    {
      return std::__equal_aux1(std::__niter_base(__first1),
          std::__niter_base(__last1),
          std::__niter_base(__first2));
    }
  template<typename _II1, typename _Seq1, typename _Cat1, typename _II2>
    bool
    __equal_aux(const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1>&,
  const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1>&,
  _II2);
  template<typename _II1, typename _II2, typename _Seq2, typename _Cat2>
    bool
    __equal_aux(_II1, _II1,
  const ::__gnu_debug::_Safe_iterator<_II2, _Seq2, _Cat2>&);
  template<typename _II1, typename _Seq1, typename _Cat1,
    typename _II2, typename _Seq2, typename _Cat2>
    bool
    __equal_aux(const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1>&,
  const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1>&,
  const ::__gnu_debug::_Safe_iterator<_II2, _Seq2, _Cat2>&);
  template<typename, typename>
    struct __lc_rai
    {
      template<typename _II1, typename _II2>

 static _II1
 __newlast1(_II1, _II1 __last1, _II2, _II2)
 { return __last1; }
      template<typename _II>

 static bool
 __cnd2(_II __first, _II __last)
 { return __first != __last; }
    };
  template<>
    struct __lc_rai<random_access_iterator_tag, random_access_iterator_tag>
    {
      template<typename _RAI1, typename _RAI2>

 static _RAI1
 __newlast1(_RAI1 __first1, _RAI1 __last1,
     _RAI2 __first2, _RAI2 __last2)
 {
   const typename iterator_traits<_RAI1>::difference_type
     __diff1 = __last1 - __first1;
   const typename iterator_traits<_RAI2>::difference_type
     __diff2 = __last2 - __first2;
   return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
 }
      template<typename _RAI>
 static bool
 __cnd2(_RAI, _RAI)
 { return true; }
    };
  template<typename _II1, typename _II2, typename _Compare>
   
    bool
    __lexicographical_compare_impl(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2,
       _Compare __comp)
    {
      typedef typename iterator_traits<_II1>::iterator_category _Category1;
      typedef typename iterator_traits<_II2>::iterator_category _Category2;
      typedef std::__lc_rai<_Category1, _Category2> __rai_type;
      __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
      for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2);
    ++__first1, (void)++__first2)
 {
   if (__comp(__first1, __first2))
     return true;
   if (__comp(__first2, __first1))
     return false;
 }
      return __first1 == __last1 && __first2 != __last2;
    }
  template<bool _BoolType>
    struct __lexicographical_compare
    {
      template<typename _II1, typename _II2>

 static bool
 __lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
 {
   using __gnu_cxx::__ops::__iter_less_iter;
   return std::__lexicographical_compare_impl(__first1, __last1,
           __first2, __last2,
           __iter_less_iter());
 }
      template<typename _II1, typename _II2>

 static int
 __3way(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
 {
   while (__first1 != __last1)
     {
       if (__first2 == __last2)
  return +1;
       if (*__first1 < *__first2)
  return -1;
       if (*__first2 < *__first1)
  return +1;
       ++__first1;
       ++__first2;
     }
   return int(__first2 == __last2) - 1;
 }
    };
  template<>
    struct __lexicographical_compare<true>
    {
      template<typename _Tp, typename _Up>

 static bool
 __lc(const _Tp* __first1, const _Tp* __last1,
      const _Up* __first2, const _Up* __last2)
 { return __3way(__first1, __last1, __first2, __last2) < 0; }
      template<typename _Tp, typename _Up>

 static ptrdiff_t
 __3way(const _Tp* __first1, const _Tp* __last1,
        const _Up* __first2, const _Up* __last2)
 {
   const size_t __len1 = __last1 - __first1;
   const size_t __len2 = __last2 - __first2;
   if (const size_t __len = std::min(__len1, __len2))
     if (int __result = std::__memcmp(__first1, __first2, __len))
       return __result;
   return ptrdiff_t(__len1 - __len2);
 }
    };
  template<typename _II1, typename _II2>
   
    inline bool
    __lexicographical_compare_aux1(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2)
    {
      typedef typename iterator_traits<_II1>::value_type _ValueType1;
      typedef typename iterator_traits<_II2>::value_type _ValueType2;
      const bool __simple =
 (__is_memcmp_ordered_with<_ValueType1, _ValueType2>::__value
  && __is_pointer<_II1>::__value
  && __is_pointer<_II2>::__value
  );
      return std::__lexicographical_compare<__simple>::__lc(__first1, __last1,
           __first2, __last2);
    }
  template<typename _Tp1, typename _Ref1, typename _Ptr1,
    typename _Tp2>
    bool
    __lexicographical_compare_aux1(
 std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
 std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
 _Tp2*, _Tp2*);
  template<typename _Tp1,
    typename _Tp2, typename _Ref2, typename _Ptr2>
    bool
    __lexicographical_compare_aux1(_Tp1*, _Tp1*,
 std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>,
 std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>);
  template<typename _Tp1, typename _Ref1, typename _Ptr1,
    typename _Tp2, typename _Ref2, typename _Ptr2>
    bool
    __lexicographical_compare_aux1(
 std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
 std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
 std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>,
 std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>);
  template<typename _II1, typename _II2>
   
    inline bool
    __lexicographical_compare_aux(_II1 __first1, _II1 __last1,
      _II2 __first2, _II2 __last2)
    {
      return std::__lexicographical_compare_aux1(std::__niter_base(__first1),
       std::__niter_base(__last1),
       std::__niter_base(__first2),
       std::__niter_base(__last2));
    }
  template<typename _Iter1, typename _Seq1, typename _Cat1,
    typename _II2>
    bool
    __lexicographical_compare_aux(
  const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1>&,
  const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1>&,
  _II2, _II2);
  template<typename _II1,
    typename _Iter2, typename _Seq2, typename _Cat2>
    bool
    __lexicographical_compare_aux(
  _II1, _II1,
  const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2>&,
  const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2>&);
  template<typename _Iter1, typename _Seq1, typename _Cat1,
    typename _Iter2, typename _Seq2, typename _Cat2>
    bool
    __lexicographical_compare_aux(
  const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1>&,
  const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1>&,
  const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2>&,
  const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2>&);
  template<typename _ForwardIterator, typename _Tp, typename _Compare>
   
    _ForwardIterator
    __lower_bound(_ForwardIterator __first, _ForwardIterator __last,
    const _Tp& __val, _Compare __comp)
    {
      typedef typename iterator_traits<_ForwardIterator>::difference_type
 _DistanceType;
      _DistanceType __len = std::distance(__first, __last);
      while (__len > 0)
 {
   _DistanceType __half = __len >> 1;
   _ForwardIterator __middle = __first;
   std::advance(__middle, __half);
   if (__comp(__middle, __val))
     {
       __first = __middle;
       ++__first;
       __len = __len - __half - 1;
     }
   else
     __len = __half;
 }
      return __first;
    }
  template<typename _ForwardIterator, typename _Tp>
   
    inline _ForwardIterator
    lower_bound(_ForwardIterator __first, _ForwardIterator __last,
  const _Tp& __val)
    {
     
     
      ;
      return std::__lower_bound(__first, __last, __val,
    __gnu_cxx::__ops::__iter_less_val());
    }
  template<typename _Tp>
    inline constexpr _Tp
    __lg(_Tp __n)
    {
      const int __sz = sizeof(+__n);
      int __w = __sz * 8 - 1;
      if (__sz == sizeof(long long))
 __w -= __builtin_clzll(+__n);
      else if (__sz == sizeof(long))
 __w -= __builtin_clzl(+__n);
      else if (__sz == sizeof(int))
 __w -= __builtin_clz(+__n);
      return __w;
    }

  template<typename _II1, typename _II2>
   
    inline bool
    equal(_II1 __first1, _II1 __last1, _II2 __first2)
    {
     
     
     
      ;
      return std::__equal_aux(__first1, __last1, __first2);
    }
  template<typename _IIter1, typename _IIter2, typename _BinaryPredicate>
   
    inline bool
    equal(_IIter1 __first1, _IIter1 __last1,
   _IIter2 __first2, _BinaryPredicate __binary_pred)
    {
     
     
      ;
      for (; __first1 != __last1; ++__first1, (void)++__first2)
 if (!bool(__binary_pred(*__first1, *__first2)))
   return false;
      return true;
    }
  template<typename _II1, typename _II2>
   
    inline bool
    __equal4(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
    {
      using _RATag = random_access_iterator_tag;
      using _Cat1 = typename iterator_traits<_II1>::iterator_category;
      using _Cat2 = typename iterator_traits<_II2>::iterator_category;
      using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
      if (_RAIters())
 {
   auto __d1 = std::distance(__first1, __last1);
   auto __d2 = std::distance(__first2, __last2);
   if (__d1 != __d2)
     return false;
   return std::equal(__first1, __last1, __first2);
 }
      for (; __first1 != __last1 && __first2 != __last2;
   ++__first1, (void)++__first2)
 if (!(*__first1 == *__first2))
   return false;
      return __first1 == __last1 && __first2 == __last2;
    }
  template<typename _II1, typename _II2, typename _BinaryPredicate>
   
    inline bool
    __equal4(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2,
      _BinaryPredicate __binary_pred)
    {
      using _RATag = random_access_iterator_tag;
      using _Cat1 = typename iterator_traits<_II1>::iterator_category;
      using _Cat2 = typename iterator_traits<_II2>::iterator_category;
      using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
      if (_RAIters())
 {
   auto __d1 = std::distance(__first1, __last1);
   auto __d2 = std::distance(__first2, __last2);
   if (__d1 != __d2)
     return false;
   return std::equal(__first1, __last1, __first2,
           __binary_pred);
 }
      for (; __first1 != __last1 && __first2 != __last2;
   ++__first1, (void)++__first2)
 if (!bool(__binary_pred(*__first1, *__first2)))
   return false;
      return __first1 == __last1 && __first2 == __last2;
    }
  template<typename _II1, typename _II2>
   
    inline bool
    lexicographical_compare(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2)
    {
     
     
     
     
      ;
      ;
      return std::__lexicographical_compare_aux(__first1, __last1,
      __first2, __last2);
    }
  template<typename _II1, typename _II2, typename _Compare>
   
    inline bool
    lexicographical_compare(_II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2, _Compare __comp)
    {
     
     
      ;
      ;
      return std::__lexicographical_compare_impl
 (__first1, __last1, __first2, __last2,
  __gnu_cxx::__ops::__iter_comp_iter(__comp));
    }
  template<typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate>
   
    pair<_InputIterator1, _InputIterator2>
    __mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _BinaryPredicate __binary_pred)
    {
      while (__first1 != __last1 && __binary_pred(__first1, __first2))
 {
   ++__first1;
   ++__first2;
 }
      return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
    }
  template<typename _InputIterator1, typename _InputIterator2>
   
    inline pair<_InputIterator1, _InputIterator2>
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2)
    {
     
     
     
      ;
      return std::__mismatch(__first1, __last1, __first2,
        __gnu_cxx::__ops::__iter_equal_to_iter());
    }
  template<typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate>
   
    inline pair<_InputIterator1, _InputIterator2>
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _BinaryPredicate __binary_pred)
    {
     
     
      ;
      return std::__mismatch(__first1, __last1, __first2,
 __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
    }

  template<typename _InputIterator, typename _Predicate>
   
    inline _InputIterator
    __find_if(_InputIterator __first, _InputIterator __last,
       _Predicate __pred, input_iterator_tag)
    {
      while (__first != __last && !__pred(__first))
 ++__first;
      return __first;
    }
  template<typename _RandomAccessIterator, typename _Predicate>
   
    _RandomAccessIterator
    __find_if(_RandomAccessIterator __first, _RandomAccessIterator __last,
       _Predicate __pred, random_access_iterator_tag)
    {
      typename iterator_traits<_RandomAccessIterator>::difference_type
 __trip_count = (__last - __first) >> 2;
      for (; __trip_count > 0; --__trip_count)
 {
   if (__pred(__first))
     return __first;
   ++__first;
   if (__pred(__first))
     return __first;
   ++__first;
   if (__pred(__first))
     return __first;
   ++__first;
   if (__pred(__first))
     return __first;
   ++__first;
 }
      switch (__last - __first)
 {
 case 3:
   if (__pred(__first))
     return __first;
   ++__first;
 case 2:
   if (__pred(__first))
     return __first;
   ++__first;
 case 1:
   if (__pred(__first))
     return __first;
   ++__first;
 case 0:
 default:
   return __last;
 }
    }
  template<typename _Iterator, typename _Predicate>
   
    inline _Iterator
    __find_if(_Iterator __first, _Iterator __last, _Predicate __pred)
    {
      return __find_if(__first, __last, __pred,
         std::__iterator_category(__first));
    }
  template<typename _InputIterator, typename _Predicate>
   
    typename iterator_traits<_InputIterator>::difference_type
    __count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    {
      typename iterator_traits<_InputIterator>::difference_type __n = 0;
      for (; __first != __last; ++__first)
 if (__pred(__first))
   ++__n;
      return __n;
    }
  template<typename _ForwardIterator, typename _Predicate>
   
    _ForwardIterator
    __remove_if(_ForwardIterator __first, _ForwardIterator __last,
  _Predicate __pred)
    {
      __first = std::__find_if(__first, __last, __pred);
      if (__first == __last)
 return __first;
      _ForwardIterator __result = __first;
      ++__first;
      for (; __first != __last; ++__first)
 if (!__pred(__first))
   {
     *__result = std::move(*__first);
     ++__result;
   }
      return __result;
    }
  template<typename _ForwardIterator1, typename _ForwardIterator2,
    typename _BinaryPredicate>
   
    bool
    __is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _BinaryPredicate __pred)
    {
      for (; __first1 != __last1; ++__first1, (void)++__first2)
 if (!__pred(__first1, __first2))
   break;
      if (__first1 == __last1)
 return true;
      _ForwardIterator2 __last2 = __first2;
      std::advance(__last2, std::distance(__first1, __last1));
      for (_ForwardIterator1 __scan = __first1; __scan != __last1; ++__scan)
 {
   if (__scan != std::__find_if(__first1, __scan,
     __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan)))
     continue;
   auto __matches
     = std::__count_if(__first2, __last2,
   __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan));
   if (0 == __matches ||
       std::__count_if(__scan, __last1,
   __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan))
       != __matches)
     return false;
 }
      return true;
    }
  template<typename _ForwardIterator1, typename _ForwardIterator2>
   
    inline bool
    is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
     _ForwardIterator2 __first2)
    {
     
     
     
      ;
      return std::__is_permutation(__first1, __last1, __first2,
       __gnu_cxx::__ops::__iter_equal_to_iter());
    }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp>
    class __new_allocator
    {
    public:
      typedef _Tp value_type;
      typedef std::size_t size_type;
      typedef std::ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp& reference;
      typedef const _Tp& const_reference;
      template<typename _Tp1>
 struct rebind
 { typedef __new_allocator<_Tp1> other; };
      typedef std::true_type propagate_on_container_move_assignment;
      __attribute__((__always_inline__))
     
      __new_allocator() noexcept { }
      __attribute__((__always_inline__))
     
      __new_allocator(const __new_allocator&) noexcept { }
      template<typename _Tp1>
 __attribute__((__always_inline__))

 __new_allocator(const __new_allocator<_Tp1>&) noexcept { }
      ~__new_allocator() noexcept { }
      pointer
      address(reference __x) const noexcept
      { return std::__addressof(__x); }
      const_pointer
      address(const_reference __x) const noexcept
      { return std::__addressof(__x); }
      _Tp*
      allocate(size_type __n, const void* = static_cast<const void*>(0))
      {
 static_assert(sizeof(_Tp) != 0, "cannot allocate incomplete types");
 if (__builtin_expect(__n > this->_M_max_size(), false))
   {
     if (__n > (std::size_t(-1) / sizeof(_Tp)))
       std::__throw_bad_array_new_length();
     std::__throw_bad_alloc();
   }
 return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
      }
      void
      deallocate(_Tp* __p, size_type __n __attribute__ ((__unused__)))
      {
 ::operator delete((__p));
      }
      __attribute__((__always_inline__))
      size_type
      max_size() const noexcept
      { return _M_max_size(); }
      template<typename _Up, typename... _Args>
 __attribute__((__always_inline__))
 void
 construct(_Up* __p, _Args&&... __args)
 noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
 { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      template<typename _Up>
 __attribute__((__always_inline__))
 void
 destroy(_Up* __p)
 noexcept(std::is_nothrow_destructible<_Up>::value)
 { __p->~_Up(); }
      template<typename _Up>
 friend __attribute__((__always_inline__)) bool
 operator==(const __new_allocator&, const __new_allocator<_Up>&)
 noexcept
 { return true; }
      template<typename _Up>
 friend __attribute__((__always_inline__)) bool
 operator!=(const __new_allocator&, const __new_allocator<_Up>&)
 noexcept
 { return false; }
    private:
      __attribute__((__always_inline__))
      constexpr size_type
      _M_max_size() const noexcept
      {
 return std::size_t(0x7fffffff) / sizeof(_Tp);
      }
    };

}
namespace std
{
  template<typename _Tp>
    using __allocator_base = __new_allocator<_Tp>;
}
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename>
    class allocator;
  template<>
    class allocator<void>;
  template<typename, typename>
    struct uses_allocator;
  template<typename>
    struct allocator_traits;

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<>
    class allocator<void>
    {
    public:
      typedef void value_type;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef void* pointer;
      typedef const void* const_pointer;
      template<typename _Tp1>
 struct rebind
 { typedef allocator<_Tp1> other; };
      using propagate_on_container_move_assignment = true_type;
      using is_always_equal

 = true_type;
    };
  template<typename _Tp>
    class allocator : public __allocator_base<_Tp>
    {
    public:
      typedef _Tp value_type;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp& reference;
      typedef const _Tp& const_reference;
      template<typename _Tp1>
 struct rebind
 { typedef allocator<_Tp1> other; };
      using propagate_on_container_move_assignment = true_type;
      using is_always_equal

 = true_type;
      __attribute__((__always_inline__))
     
      allocator() noexcept { }
      __attribute__((__always_inline__))
     
      allocator(const allocator& __a) noexcept
      : __allocator_base<_Tp>(__a) { }
      allocator& operator=(const allocator&) = default;
      template<typename _Tp1>
 __attribute__((__always_inline__))

 allocator(const allocator<_Tp1>&) noexcept { }
      __attribute__((__always_inline__))
      ~allocator() noexcept { }
      friend __attribute__((__always_inline__))
      bool
      operator==(const allocator&, const allocator&) noexcept
      { return true; }
      friend __attribute__((__always_inline__))
      bool
      operator!=(const allocator&, const allocator&) noexcept
      { return false; }
    };
  template<typename _T1, typename _T2>
    __attribute__((__always_inline__))
    inline bool
    operator==(const allocator<_T1>&, const allocator<_T2>&)
    noexcept
    { return true; }
  template<typename _T1, typename _T2>
    __attribute__((__always_inline__))
    inline bool
    operator!=(const allocator<_T1>&, const allocator<_T2>&)
    noexcept
    { return false; }
  template<typename _Tp>
    class allocator<const _Tp>
    {
    public:
      typedef _Tp value_type;
      template<typename _Up> allocator(const allocator<_Up>&) { }
    };
  template<typename _Tp>
    class allocator<volatile _Tp>
    {
    public:
      typedef _Tp value_type;
      template<typename _Up> allocator(const allocator<_Up>&) { }
    };
  template<typename _Tp>
    class allocator<const volatile _Tp>
    {
    public:
      typedef _Tp value_type;
      template<typename _Up> allocator(const allocator<_Up>&) { }
    };
  extern template class allocator<char>;
  extern template class allocator<wchar_t>;

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp, typename... _Args>
   
    inline void
    _Construct(_Tp* __p, _Args&&... __args)
    {
      ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
    }
  template<typename _T1>
    inline void
    _Construct_novalue(_T1* __p)
    { ::new((void*)__p) _T1; }
  template<typename _ForwardIterator>
    void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last);
  template<typename _Tp>
    inline void
    _Destroy(_Tp* __pointer)
    {
      __pointer->~_Tp();
    }
  template<bool>
    struct _Destroy_aux
    {
      template<typename _ForwardIterator>
 static void
 __destroy(_ForwardIterator __first, _ForwardIterator __last)
 {
   for (; __first != __last; ++__first)
     std::_Destroy(std::__addressof(*__first));
 }
    };
  template<>
    struct _Destroy_aux<true>
    {
      template<typename _ForwardIterator>
        static void
        __destroy(_ForwardIterator, _ForwardIterator) { }
    };
  template<typename _ForwardIterator>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
                       _Value_type;
      static_assert(is_destructible<_Value_type>::value,
      "value type is destructible");
      std::_Destroy_aux<__has_trivial_destructor(_Value_type)>::
 __destroy(__first, __last);
    }
  template<bool>
    struct _Destroy_n_aux
    {
      template<typename _ForwardIterator, typename _Size>
 static _ForwardIterator
 __destroy_n(_ForwardIterator __first, _Size __count)
 {
   for (; __count > 0; (void)++__first, --__count)
     std::_Destroy(std::__addressof(*__first));
   return __first;
 }
    };
  template<>
    struct _Destroy_n_aux<true>
    {
      template<typename _ForwardIterator, typename _Size>
        static _ForwardIterator
        __destroy_n(_ForwardIterator __first, _Size __count)
 {
   std::advance(__first, __count);
   return __first;
 }
    };
  template<typename _ForwardIterator, typename _Size>
    inline _ForwardIterator
    _Destroy_n(_ForwardIterator __first, _Size __count)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
                       _Value_type;
      static_assert(is_destructible<_Value_type>::value,
      "value type is destructible");
      return std::_Destroy_n_aux<__has_trivial_destructor(_Value_type)>::
 __destroy_n(__first, __count);
    }

}
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  struct __allocator_traits_base
  {
    template<typename _Tp, typename _Up, typename = void>
      struct __rebind : __replace_first_arg<_Tp, _Up>
      {
 static_assert(is_same<
   typename __replace_first_arg<_Tp, typename _Tp::value_type>::type,
   _Tp>::value,
   "allocator_traits<A>::rebind_alloc<A::value_type> must be A");
      };
    template<typename _Tp, typename _Up>
      struct __rebind<_Tp, _Up,
        __void_t<typename _Tp::template rebind<_Up>::other>>
      {
 using type = typename _Tp::template rebind<_Up>::other;
 static_assert(is_same<
   typename _Tp::template rebind<typename _Tp::value_type>::other,
   _Tp>::value,
   "allocator_traits<A>::rebind_alloc<A::value_type> must be A");
      };
  protected:
    template<typename _Tp>
      using __pointer = typename _Tp::pointer;
    template<typename _Tp>
      using __c_pointer = typename _Tp::const_pointer;
    template<typename _Tp>
      using __v_pointer = typename _Tp::void_pointer;
    template<typename _Tp>
      using __cv_pointer = typename _Tp::const_void_pointer;
    template<typename _Tp>
      using __pocca = typename _Tp::propagate_on_container_copy_assignment;
    template<typename _Tp>
      using __pocma = typename _Tp::propagate_on_container_move_assignment;
    template<typename _Tp>
      using __pocs = typename _Tp::propagate_on_container_swap;
    template<typename _Tp>
      using __equal = __type_identity<typename _Tp::is_always_equal>;
  };
  template<typename _Alloc, typename _Up>
    using __alloc_rebind
      = typename __allocator_traits_base::template __rebind<_Alloc, _Up>::type;
  template<typename _Alloc>
    struct allocator_traits : __allocator_traits_base
    {
      typedef _Alloc allocator_type;
      typedef typename _Alloc::value_type value_type;
      using pointer = __detected_or_t<value_type*, __pointer, _Alloc>;
    private:
      template<template<typename> class _Func, typename _Tp, typename = void>
 struct _Ptr
 {
   using type = typename pointer_traits<pointer>::template rebind<_Tp>;
 };
      template<template<typename> class _Func, typename _Tp>
 struct _Ptr<_Func, _Tp, __void_t<_Func<_Alloc>>>
 {
   using type = _Func<_Alloc>;
 };
      template<typename _A2, typename _PtrT, typename = void>
 struct _Diff
 { using type = typename pointer_traits<_PtrT>::difference_type; };
      template<typename _A2, typename _PtrT>
 struct _Diff<_A2, _PtrT, __void_t<typename _A2::difference_type>>
 { using type = typename _A2::difference_type; };
      template<typename _A2, typename _DiffT, typename = void>
 struct _Size : make_unsigned<_DiffT> { };
      template<typename _A2, typename _DiffT>
 struct _Size<_A2, _DiffT, __void_t<typename _A2::size_type>>
 { using type = typename _A2::size_type; };
    public:
      using const_pointer = typename _Ptr<__c_pointer, const value_type>::type;
      using void_pointer = typename _Ptr<__v_pointer, void>::type;
      using const_void_pointer = typename _Ptr<__cv_pointer, const void>::type;
      using difference_type = typename _Diff<_Alloc, pointer>::type;
      using size_type = typename _Size<_Alloc, difference_type>::type;
      using propagate_on_container_copy_assignment
 = __detected_or_t<false_type, __pocca, _Alloc>;
      using propagate_on_container_move_assignment
 = __detected_or_t<false_type, __pocma, _Alloc>;
      using propagate_on_container_swap
 = __detected_or_t<false_type, __pocs, _Alloc>;
      using is_always_equal
 = typename __detected_or_t<is_empty<_Alloc>, __equal, _Alloc>::type;
      template<typename _Tp>
 using rebind_alloc = __alloc_rebind<_Alloc, _Tp>;
      template<typename _Tp>
 using rebind_traits = allocator_traits<rebind_alloc<_Tp>>;
    private:
      template<typename _Alloc2>
 static constexpr auto
 _S_allocate(_Alloc2& __a, size_type __n, const_void_pointer __hint, int)
 -> decltype(__a.allocate(__n, __hint))
 { return __a.allocate(__n, __hint); }
      template<typename _Alloc2>
 static constexpr pointer
 _S_allocate(_Alloc2& __a, size_type __n, const_void_pointer, ...)
 { return __a.allocate(__n); }
      template<typename _Tp, typename... _Args>
 struct __construct_helper
 {
   template<typename _Alloc2,
     typename = decltype(std::declval<_Alloc2*>()->construct(
    std::declval<_Tp*>(), std::declval<_Args>()...))>
     static true_type __test(int);
   template<typename>
     static false_type __test(...);
   using type = decltype(__test<_Alloc>(0));
 };
      template<typename _Tp, typename... _Args>
 using __has_construct
   = typename __construct_helper<_Tp, _Args...>::type;
      template<typename _Tp, typename... _Args>
 static _Require<__has_construct<_Tp, _Args...>>
 _S_construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
 noexcept(noexcept(__a.construct(__p, std::forward<_Args>(__args)...)))
 { __a.construct(__p, std::forward<_Args>(__args)...); }
      template<typename _Tp, typename... _Args>
 static
 _Require<__and_<__not_<__has_construct<_Tp, _Args...>>,
          is_constructible<_Tp, _Args...>>>
 _S_construct(_Alloc&, _Tp* __p, _Args&&... __args)
 noexcept(std::is_nothrow_constructible<_Tp, _Args...>::value)
 {
   ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
 }
      template<typename _Alloc2, typename _Tp>
 static auto
 _S_destroy(_Alloc2& __a, _Tp* __p, int)
 noexcept(noexcept(__a.destroy(__p)))
 -> decltype(__a.destroy(__p))
 { __a.destroy(__p); }
      template<typename _Alloc2, typename _Tp>
 static void
 _S_destroy(_Alloc2&, _Tp* __p, ...)
 noexcept(std::is_nothrow_destructible<_Tp>::value)
 { std::_Destroy(__p); }
      template<typename _Alloc2>
 static constexpr auto
 _S_max_size(_Alloc2& __a, int)
 -> decltype(__a.max_size())
 { return __a.max_size(); }
      template<typename _Alloc2>
 static constexpr size_type
 _S_max_size(_Alloc2&, ...)
 {
   return __gnu_cxx::__numeric_traits<size_type>::__max
     / sizeof(value_type);
 }
      template<typename _Alloc2>
 static constexpr auto
 _S_select(_Alloc2& __a, int)
 -> decltype(__a.select_on_container_copy_construction())
 { return __a.select_on_container_copy_construction(); }
      template<typename _Alloc2>
 static constexpr _Alloc2
 _S_select(_Alloc2& __a, ...)
 { return __a; }
    public:
      static pointer
      allocate(_Alloc& __a, size_type __n)
      { return __a.allocate(__n); }
      static pointer
      allocate(_Alloc& __a, size_type __n, const_void_pointer __hint)
      { return _S_allocate(__a, __n, __hint, 0); }
      static void
      deallocate(_Alloc& __a, pointer __p, size_type __n)
      { __a.deallocate(__p, __n); }
      template<typename _Tp, typename... _Args>
 static auto
 construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
 noexcept(noexcept(_S_construct(__a, __p,
           std::forward<_Args>(__args)...)))
 -> decltype(_S_construct(__a, __p, std::forward<_Args>(__args)...))
 { _S_construct(__a, __p, std::forward<_Args>(__args)...); }
      template<typename _Tp>
 static void
 destroy(_Alloc& __a, _Tp* __p)
 noexcept(noexcept(_S_destroy(__a, __p, 0)))
 { _S_destroy(__a, __p, 0); }
      static size_type
      max_size(const _Alloc& __a) noexcept
      { return _S_max_size(__a, 0); }
      static _Alloc
      select_on_container_copy_construction(const _Alloc& __rhs)
      { return _S_select(__rhs, 0); }
    };
  template<typename _Tp>
    struct allocator_traits<allocator<_Tp>>
    {
      using allocator_type = allocator<_Tp>;
      using value_type = _Tp;
      using pointer = _Tp*;
      using const_pointer = const _Tp*;
      using void_pointer = void*;
      using const_void_pointer = const void*;
      using difference_type = std::ptrdiff_t;
      using size_type = std::size_t;
      using propagate_on_container_copy_assignment = false_type;
      using propagate_on_container_move_assignment = true_type;
      using propagate_on_container_swap = false_type;
      using is_always_equal = true_type;
      template<typename _Up>
 using rebind_alloc = allocator<_Up>;
      template<typename _Up>
 using rebind_traits = allocator_traits<allocator<_Up>>;
      [[__nodiscard__,__gnu__::__always_inline__]]
      static pointer
      allocate(allocator_type& __a, size_type __n)
      { return __a.allocate(__n); }
      [[__nodiscard__,__gnu__::__always_inline__]]
      static pointer
      allocate(allocator_type& __a, size_type __n, const_void_pointer __hint)
      {
 return __a.allocate(__n, __hint);
      }
      [[__gnu__::__always_inline__]]
      static void
      deallocate(allocator_type& __a, pointer __p, size_type __n)
      { __a.deallocate(__p, __n); }
      template<typename _Up, typename... _Args>
 [[__gnu__::__always_inline__]]
 static void
 construct(allocator_type& __a __attribute__((__unused__)), _Up* __p,
    _Args&&... __args)
 noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
 {
   __a.construct(__p, std::forward<_Args>(__args)...);
 }
      template<typename _Up>
 [[__gnu__::__always_inline__]]
 static void
 destroy(allocator_type& __a __attribute__((__unused__)), _Up* __p)
 noexcept(is_nothrow_destructible<_Up>::value)
 {
   __a.destroy(__p);
 }
      [[__gnu__::__always_inline__]]
      static size_type
      max_size(const allocator_type& __a __attribute__((__unused__))) noexcept
      {
 return __a.max_size();
      }
      [[__gnu__::__always_inline__]]
      static allocator_type
      select_on_container_copy_construction(const allocator_type& __rhs)
      { return __rhs; }
    };
  template<>
    struct allocator_traits<allocator<void>>
    {
      using allocator_type = allocator<void>;
      using value_type = void;
      using pointer = void*;
      using const_pointer = const void*;
      using void_pointer = void*;
      using const_void_pointer = const void*;
      using difference_type = std::ptrdiff_t;
      using size_type = std::size_t;
      using propagate_on_container_copy_assignment = false_type;
      using propagate_on_container_move_assignment = true_type;
      using propagate_on_container_swap = false_type;
      using is_always_equal = true_type;
      template<typename _Up>
 using rebind_alloc = allocator<_Up>;
      template<typename _Up>
 using rebind_traits = allocator_traits<allocator<_Up>>;
      static void*
      allocate(allocator_type&, size_type, const void* = nullptr) = delete;
      static void
      deallocate(allocator_type&, void*, size_type) = delete;
      template<typename _Up, typename... _Args>
 [[__gnu__::__always_inline__]]
 static void
 construct(allocator_type&, _Up* __p, _Args&&... __args)
 noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
 { std::_Construct(__p, std::forward<_Args>(__args)...); }
      template<typename _Up>
 [[__gnu__::__always_inline__]]
 static void
 destroy(allocator_type&, _Up* __p)
 noexcept(is_nothrow_destructible<_Up>::value)
 { std::_Destroy(__p); }
      static size_type
      max_size(const allocator_type&) = delete;
      [[__gnu__::__always_inline__]]
      static allocator_type
      select_on_container_copy_construction(const allocator_type& __rhs)
      { return __rhs; }
    };
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void
    __do_alloc_on_copy(_Alloc& __one, const _Alloc& __two, true_type)
    { __one = __two; }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void
    __do_alloc_on_copy(_Alloc&, const _Alloc&, false_type)
    { }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void
    __alloc_on_copy(_Alloc& __one, const _Alloc& __two)
    {
      using __traits = allocator_traits<_Alloc>;
      using __pocca =
 typename __traits::propagate_on_container_copy_assignment::type;
      __do_alloc_on_copy(__one, __two, __pocca());
    }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    constexpr _Alloc
    __alloc_on_copy(const _Alloc& __a)
    {
      typedef allocator_traits<_Alloc> __traits;
      return __traits::select_on_container_copy_construction(__a);
    }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void __do_alloc_on_move(_Alloc& __one, _Alloc& __two, true_type)
    { __one = std::move(__two); }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void __do_alloc_on_move(_Alloc&, _Alloc&, false_type)
    { }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void
    __alloc_on_move(_Alloc& __one, _Alloc& __two)
    {
      using __traits = allocator_traits<_Alloc>;
      using __pocma
 = typename __traits::propagate_on_container_move_assignment::type;
      __do_alloc_on_move(__one, __two, __pocma());
    }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void __do_alloc_on_swap(_Alloc& __one, _Alloc& __two, true_type)
    {
      using std::swap;
      swap(__one, __two);
    }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void __do_alloc_on_swap(_Alloc&, _Alloc&, false_type)
    { }
  template<typename _Alloc>
    [[__gnu__::__always_inline__]]
    inline void
    __alloc_on_swap(_Alloc& __one, _Alloc& __two)
    {
      using __traits = allocator_traits<_Alloc>;
      using __pocs = typename __traits::propagate_on_container_swap::type;
      __do_alloc_on_swap(__one, __two, __pocs());
    }
  template<typename _Alloc, typename _Tp,
    typename _ValueT = __remove_cvref_t<typename _Alloc::value_type>,
    typename = void>
    struct __is_alloc_insertable_impl
    : false_type
    { };
  template<typename _Alloc, typename _Tp, typename _ValueT>
    struct __is_alloc_insertable_impl<_Alloc, _Tp, _ValueT,
      __void_t<decltype(allocator_traits<_Alloc>::construct(
     std::declval<_Alloc&>(), std::declval<_ValueT*>(),
     std::declval<_Tp>()))>>
    : true_type
    { };
  template<typename _Alloc>
    struct __is_copy_insertable
    : __is_alloc_insertable_impl<_Alloc,
     typename _Alloc::value_type const&>::type
    { };
  template<typename _Tp>
    struct __is_copy_insertable<allocator<_Tp>>
    : is_copy_constructible<_Tp>
    { };
  template<typename _Alloc>
    struct __is_move_insertable
    : __is_alloc_insertable_impl<_Alloc, typename _Alloc::value_type>::type
    { };
  template<typename _Tp>
    struct __is_move_insertable<allocator<_Tp>>
    : is_move_constructible<_Tp>
    { };
  template<typename _Alloc, typename = void>
    struct __is_allocator : false_type { };
  template<typename _Alloc>
    struct __is_allocator<_Alloc,
      __void_t<typename _Alloc::value_type,
        decltype(std::declval<_Alloc&>().allocate(size_t{}))>>
    : true_type { };
  template<typename _Alloc>
    using _RequireAllocator
      = typename enable_if<__is_allocator<_Alloc>::value, _Alloc>::type;
  template<typename _Alloc>
    using _RequireNotAllocator
      = typename enable_if<!__is_allocator<_Alloc>::value, _Alloc>::type;
  template<typename _Alloc, bool = __is_empty(_Alloc)>
    struct __alloc_swap
    { static void _S_do_it(_Alloc&, _Alloc&) noexcept { } };
  template<typename _Alloc>
    struct __alloc_swap<_Alloc, false>
    {
      static void
      _S_do_it(_Alloc& __one, _Alloc& __two) noexcept
      {
 if (__one != __two)
   swap(__one, __two);
      }
    };
  template<typename _Tp, bool
    = __or_<is_copy_constructible<typename _Tp::value_type>,
            is_nothrow_move_constructible<typename _Tp::value_type>>::value>
    struct __shrink_to_fit_aux
    { static bool _S_do_it(_Tp&) noexcept { return false; } };
  template<typename _Tp>
    struct __shrink_to_fit_aux<_Tp, true>
    {
     
      static bool
      _S_do_it(_Tp& __c) noexcept
      {
 try
   {
     _Tp(__make_move_if_noexcept_iterator(__c.begin()),
  __make_move_if_noexcept_iterator(__c.end()),
  __c.get_allocator()).swap(__c);
     return true;
   }
 catch(...)
   { return false; }
      }
    };
  template<typename _ForwardIterator, typename _Allocator>
   
    void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
      _Allocator& __alloc)
    {
      for (; __first != __last; ++__first)
 allocator_traits<_Allocator>::destroy(__alloc,
           std::__addressof(*__first));
    }
  template<typename _ForwardIterator, typename _Tp>
    __attribute__((__always_inline__))
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
      allocator<_Tp>&)
    {
      std::_Destroy(__first, __last);
    }

}
namespace __gnu_cxx __attribute__ ((__visibility__ ("default")))
{

template<typename _Alloc, typename = typename _Alloc::value_type>
  struct __alloc_traits
  : std::allocator_traits<_Alloc>
  {
    typedef _Alloc allocator_type;
    typedef std::allocator_traits<_Alloc> _Base_type;
    typedef typename _Base_type::value_type value_type;
    typedef typename _Base_type::pointer pointer;
    typedef typename _Base_type::const_pointer const_pointer;
    typedef typename _Base_type::size_type size_type;
    typedef typename _Base_type::difference_type difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    using _Base_type::allocate;
    using _Base_type::deallocate;
    using _Base_type::construct;
    using _Base_type::destroy;
    using _Base_type::max_size;
  private:
    template<typename _Ptr>
      using __is_custom_pointer
 = std::__and_<std::is_same<pointer, _Ptr>,
        std::__not_<std::is_pointer<_Ptr>>>;
  public:
    template<typename _Ptr, typename... _Args>
      [[__gnu__::__always_inline__]]
      static
      std::__enable_if_t<__is_custom_pointer<_Ptr>::value>
      construct(_Alloc& __a, _Ptr __p, _Args&&... __args)
      noexcept(noexcept(_Base_type::construct(__a, std::__to_address(__p),
           std::forward<_Args>(__args)...)))
      {
 _Base_type::construct(__a, std::__to_address(__p),
         std::forward<_Args>(__args)...);
      }
    template<typename _Ptr>
      [[__gnu__::__always_inline__]]
      static
      std::__enable_if_t<__is_custom_pointer<_Ptr>::value>
      destroy(_Alloc& __a, _Ptr __p)
      noexcept(noexcept(_Base_type::destroy(__a, std::__to_address(__p))))
      { _Base_type::destroy(__a, std::__to_address(__p)); }
    [[__gnu__::__always_inline__]]
    static constexpr _Alloc _S_select_on_copy(const _Alloc& __a)
    { return _Base_type::select_on_container_copy_construction(__a); }
    [[__gnu__::__always_inline__]]
    static void _S_on_swap(_Alloc& __a, _Alloc& __b)
    { std::__alloc_on_swap(__a, __b); }
    [[__gnu__::__always_inline__]]
    static constexpr bool _S_propagate_on_copy_assign()
    { return _Base_type::propagate_on_container_copy_assignment::value; }
    [[__gnu__::__always_inline__]]
    static constexpr bool _S_propagate_on_move_assign()
    { return _Base_type::propagate_on_container_move_assignment::value; }
    [[__gnu__::__always_inline__]]
    static constexpr bool _S_propagate_on_swap()
    { return _Base_type::propagate_on_container_swap::value; }
    [[__gnu__::__always_inline__]]
    static constexpr bool _S_always_equal()
    { return _Base_type::is_always_equal::value; }
    __attribute__((__always_inline__))
    static constexpr bool _S_nothrow_move()
    { return _S_propagate_on_move_assign() || _S_always_equal(); }
    template<typename _Tp>
      struct rebind
      { typedef typename _Base_type::template rebind_alloc<_Tp> other; };
  };

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _ValueType, typename _Tp>
    constexpr bool
    __check_constructible()
    {
      static_assert(is_constructible<_ValueType, _Tp>::value,
   "result type must be constructible from input type");
      return true;
    }
  template<typename _InputIterator, typename _ForwardIterator>
   
    _ForwardIterator
    __do_uninit_copy(_InputIterator __first, _InputIterator __last,
       _ForwardIterator __result)
    {
      _ForwardIterator __cur = __result;
      try
 {
   for (; __first != __last; ++__first, (void)++__cur)
     std::_Construct(std::__addressof(*__cur), *__first);
   return __cur;
 }
      catch(...)
 {
   std::_Destroy(__result, __cur);
   throw;
 }
    }
  template<bool _TrivialValueTypes>
    struct __uninitialized_copy
    {
      template<typename _InputIterator, typename _ForwardIterator>
        static _ForwardIterator
        __uninit_copy(_InputIterator __first, _InputIterator __last,
        _ForwardIterator __result)
 { return std::__do_uninit_copy(__first, __last, __result); }
    };
  template<>
    struct __uninitialized_copy<true>
    {
      template<typename _InputIterator, typename _ForwardIterator>
        static _ForwardIterator
        __uninit_copy(_InputIterator __first, _InputIterator __last,
        _ForwardIterator __result)
        { return std::copy(__first, __last, __result); }
    };
  template<typename _InputIterator, typename _ForwardIterator>
    inline _ForwardIterator
    uninitialized_copy(_InputIterator __first, _InputIterator __last,
         _ForwardIterator __result)
    {
      typedef typename iterator_traits<_InputIterator>::value_type
 _ValueType1;
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType2;
      const bool __can_memmove = __is_trivial(_ValueType1);
      using _From = decltype(*__first);
      const bool __assignable
 = __is_trivial(_ValueType2) && __is_assignable(_ValueType2&, _From) && std::__check_constructible<_ValueType2, _From>();
      return std::__uninitialized_copy<__can_memmove && __assignable>::
 __uninit_copy(__first, __last, __result);
    }
  template<typename _ForwardIterator, typename _Tp>
    void
    __do_uninit_fill(_ForwardIterator __first, _ForwardIterator __last,
       const _Tp& __x)
    {
      _ForwardIterator __cur = __first;
      try
 {
   for (; __cur != __last; ++__cur)
     std::_Construct(std::__addressof(*__cur), __x);
 }
      catch(...)
 {
   std::_Destroy(__first, __cur);
   throw;
 }
    }
  template<bool _TrivialValueType>
    struct __uninitialized_fill
    {
      template<typename _ForwardIterator, typename _Tp>
        static void
        __uninit_fill(_ForwardIterator __first, _ForwardIterator __last,
        const _Tp& __x)
 { std::__do_uninit_fill(__first, __last, __x); }
    };
  template<>
    struct __uninitialized_fill<true>
    {
      template<typename _ForwardIterator, typename _Tp>
        static void
        __uninit_fill(_ForwardIterator __first, _ForwardIterator __last,
        const _Tp& __x)
        { std::fill(__first, __last, __x); }
    };
  template<typename _ForwardIterator, typename _Tp>
    inline void
    uninitialized_fill(_ForwardIterator __first, _ForwardIterator __last,
         const _Tp& __x)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType;
      const bool __can_fill
 = __is_trivial(_ValueType) && __is_assignable(_ValueType&, const _Tp&) && std::__check_constructible<_ValueType, const _Tp&>();
      std::__uninitialized_fill<__can_fill>::
 __uninit_fill(__first, __last, __x);
    }
  template<typename _ForwardIterator, typename _Size, typename _Tp>
   
    _ForwardIterator
    __do_uninit_fill_n(_ForwardIterator __first, _Size __n, const _Tp& __x)
    {
      _ForwardIterator __cur = __first;
      try
 {
   for (; __n > 0; --__n, (void) ++__cur)
     std::_Construct(std::__addressof(*__cur), __x);
   return __cur;
 }
      catch(...)
 {
   std::_Destroy(__first, __cur);
   throw;
 }
    }
  template<bool _TrivialValueType>
    struct __uninitialized_fill_n
    {
      template<typename _ForwardIterator, typename _Size, typename _Tp>
 static _ForwardIterator
        __uninit_fill_n(_ForwardIterator __first, _Size __n,
   const _Tp& __x)
 { return std::__do_uninit_fill_n(__first, __n, __x); }
    };
  template<>
    struct __uninitialized_fill_n<true>
    {
      template<typename _ForwardIterator, typename _Size, typename _Tp>
 static _ForwardIterator
        __uninit_fill_n(_ForwardIterator __first, _Size __n,
   const _Tp& __x)
        { return std::fill_n(__first, __n, __x); }
    };
  template<typename _ForwardIterator, typename _Size, typename _Tp>
    inline _ForwardIterator
    uninitialized_fill_n(_ForwardIterator __first, _Size __n, const _Tp& __x)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType;
      const bool __can_fill
 = __is_trivial(_ValueType) && __is_assignable(_ValueType&, const _Tp&) && std::__check_constructible<_ValueType, const _Tp&>()
 && __is_integer<_Size>::__value;
      return __uninitialized_fill_n<__can_fill>::
 __uninit_fill_n(__first, __n, __x);
    }
  template<typename _InputIterator, typename _ForwardIterator,
    typename _Allocator>
   
    _ForwardIterator
    __uninitialized_copy_a(_InputIterator __first, _InputIterator __last,
      _ForwardIterator __result, _Allocator& __alloc)
    {
      _ForwardIterator __cur = __result;
      try
 {
   typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
   for (; __first != __last; ++__first, (void)++__cur)
     __traits::construct(__alloc, std::__addressof(*__cur), *__first);
   return __cur;
 }
      catch(...)
 {
   std::_Destroy(__result, __cur, __alloc);
   throw;
 }
    }
  template<typename _InputIterator, typename _ForwardIterator, typename _Tp>
   
    inline _ForwardIterator
    __uninitialized_copy_a(_InputIterator __first, _InputIterator __last,
      _ForwardIterator __result, allocator<_Tp>&)
    {
      return std::uninitialized_copy(__first, __last, __result);
    }
  template<typename _InputIterator, typename _ForwardIterator,
    typename _Allocator>
   
    inline _ForwardIterator
    __uninitialized_move_a(_InputIterator __first, _InputIterator __last,
      _ForwardIterator __result, _Allocator& __alloc)
    {
      return std::__uninitialized_copy_a(std::make_move_iterator(__first),
      std::make_move_iterator(__last),
      __result, __alloc);
    }
  template<typename _InputIterator, typename _ForwardIterator,
    typename _Allocator>
   
    inline _ForwardIterator
    __uninitialized_move_if_noexcept_a(_InputIterator __first,
           _InputIterator __last,
           _ForwardIterator __result,
           _Allocator& __alloc)
    {
      return std::__uninitialized_copy_a
 (std::__make_move_if_noexcept_iterator(__first),
  std::__make_move_if_noexcept_iterator(__last), __result, __alloc);
    }
  template<typename _ForwardIterator, typename _Tp, typename _Allocator>
   
    void
    __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last,
      const _Tp& __x, _Allocator& __alloc)
    {
      _ForwardIterator __cur = __first;
      try
 {
   typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
   for (; __cur != __last; ++__cur)
     __traits::construct(__alloc, std::__addressof(*__cur), __x);
 }
      catch(...)
 {
   std::_Destroy(__first, __cur, __alloc);
   throw;
 }
    }
  template<typename _ForwardIterator, typename _Tp, typename _Tp2>
   
    inline void
    __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last,
      const _Tp& __x, allocator<_Tp2>&)
    {
      std::uninitialized_fill(__first, __last, __x);
    }
  template<typename _ForwardIterator, typename _Size, typename _Tp,
    typename _Allocator>
    
    _ForwardIterator
    __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n,
        const _Tp& __x, _Allocator& __alloc)
    {
      _ForwardIterator __cur = __first;
      try
 {
   typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
   for (; __n > 0; --__n, (void) ++__cur)
     __traits::construct(__alloc, std::__addressof(*__cur), __x);
   return __cur;
 }
      catch(...)
 {
   std::_Destroy(__first, __cur, __alloc);
   throw;
 }
    }
  template<typename _ForwardIterator, typename _Size, typename _Tp,
    typename _Tp2>
   
    inline _ForwardIterator
    __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n,
        const _Tp& __x, allocator<_Tp2>&)
    {
      return std::uninitialized_fill_n(__first, __n, __x);
    }
  template<typename _InputIterator1, typename _InputIterator2,
    typename _ForwardIterator, typename _Allocator>
    inline _ForwardIterator
    __uninitialized_copy_move(_InputIterator1 __first1,
         _InputIterator1 __last1,
         _InputIterator2 __first2,
         _InputIterator2 __last2,
         _ForwardIterator __result,
         _Allocator& __alloc)
    {
      _ForwardIterator __mid = std::__uninitialized_copy_a(__first1, __last1,
          __result,
          __alloc);
      try
 {
   return std::__uninitialized_move_a(__first2, __last2, __mid, __alloc);
 }
      catch(...)
 {
   std::_Destroy(__result, __mid, __alloc);
   throw;
 }
    }
  template<typename _InputIterator1, typename _InputIterator2,
    typename _ForwardIterator, typename _Allocator>
    inline _ForwardIterator
    __uninitialized_move_copy(_InputIterator1 __first1,
         _InputIterator1 __last1,
         _InputIterator2 __first2,
         _InputIterator2 __last2,
         _ForwardIterator __result,
         _Allocator& __alloc)
    {
      _ForwardIterator __mid = std::__uninitialized_move_a(__first1, __last1,
          __result,
          __alloc);
      try
 {
   return std::__uninitialized_copy_a(__first2, __last2, __mid, __alloc);
 }
      catch(...)
 {
   std::_Destroy(__result, __mid, __alloc);
   throw;
 }
    }
  template<typename _ForwardIterator, typename _Tp, typename _InputIterator,
    typename _Allocator>
    inline _ForwardIterator
    __uninitialized_fill_move(_ForwardIterator __result, _ForwardIterator __mid,
         const _Tp& __x, _InputIterator __first,
         _InputIterator __last, _Allocator& __alloc)
    {
      std::__uninitialized_fill_a(__result, __mid, __x, __alloc);
      try
 {
   return std::__uninitialized_move_a(__first, __last, __mid, __alloc);
 }
      catch(...)
 {
   std::_Destroy(__result, __mid, __alloc);
   throw;
 }
    }
  template<typename _InputIterator, typename _ForwardIterator, typename _Tp,
    typename _Allocator>
    inline void
    __uninitialized_move_fill(_InputIterator __first1, _InputIterator __last1,
         _ForwardIterator __first2,
         _ForwardIterator __last2, const _Tp& __x,
         _Allocator& __alloc)
    {
      _ForwardIterator __mid2 = std::__uninitialized_move_a(__first1, __last1,
           __first2,
           __alloc);
      try
 {
   std::__uninitialized_fill_a(__mid2, __last2, __x, __alloc);
 }
      catch(...)
 {
   std::_Destroy(__first2, __mid2, __alloc);
   throw;
 }
    }
  template<bool _TrivialValueType>
    struct __uninitialized_default_1
    {
      template<typename _ForwardIterator>
        static void
        __uninit_default(_ForwardIterator __first, _ForwardIterator __last)
        {
   _ForwardIterator __cur = __first;
   try
     {
       for (; __cur != __last; ++__cur)
  std::_Construct(std::__addressof(*__cur));
     }
   catch(...)
     {
       std::_Destroy(__first, __cur);
       throw;
     }
 }
    };
  template<>
    struct __uninitialized_default_1<true>
    {
      template<typename _ForwardIterator>
        static void
        __uninit_default(_ForwardIterator __first, _ForwardIterator __last)
        {
   if (__first == __last)
     return;
   typename iterator_traits<_ForwardIterator>::value_type* __val
     = std::__addressof(*__first);
   std::_Construct(__val);
   if (++__first != __last)
     std::fill(__first, __last, *__val);
 }
    };
  template<bool _TrivialValueType>
    struct __uninitialized_default_n_1
    {
      template<typename _ForwardIterator, typename _Size>

        static _ForwardIterator
        __uninit_default_n(_ForwardIterator __first, _Size __n)
        {
   _ForwardIterator __cur = __first;
   try
     {
       for (; __n > 0; --__n, (void) ++__cur)
  std::_Construct(std::__addressof(*__cur));
       return __cur;
     }
   catch(...)
     {
       std::_Destroy(__first, __cur);
       throw;
     }
 }
    };
  template<>
    struct __uninitialized_default_n_1<true>
    {
      template<typename _ForwardIterator, typename _Size>

        static _ForwardIterator
        __uninit_default_n(_ForwardIterator __first, _Size __n)
        {
   if (__n > 0)
     {
       typename iterator_traits<_ForwardIterator>::value_type* __val
  = std::__addressof(*__first);
       std::_Construct(__val);
       ++__first;
       __first = std::fill_n(__first, __n - 1, *__val);
     }
   return __first;
 }
    };
  template<typename _ForwardIterator>
    inline void
    __uninitialized_default(_ForwardIterator __first,
       _ForwardIterator __last)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType;
      const bool __assignable = is_copy_assignable<_ValueType>::value;
      std::__uninitialized_default_1<__is_trivial(_ValueType)
         && __assignable>::
 __uninit_default(__first, __last);
    }
  template<typename _ForwardIterator, typename _Size>
   
    inline _ForwardIterator
    __uninitialized_default_n(_ForwardIterator __first, _Size __n)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType;
      constexpr bool __can_fill
 = __and_<is_integral<_Size>, is_copy_assignable<_ValueType>>::value;
      return __uninitialized_default_n_1<__is_trivial(_ValueType)
      && __can_fill>::
 __uninit_default_n(__first, __n);
    }
  template<typename _ForwardIterator, typename _Allocator>
    void
    __uninitialized_default_a(_ForwardIterator __first,
         _ForwardIterator __last,
         _Allocator& __alloc)
    {
      _ForwardIterator __cur = __first;
      try
 {
   typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
   for (; __cur != __last; ++__cur)
     __traits::construct(__alloc, std::__addressof(*__cur));
 }
      catch(...)
 {
   std::_Destroy(__first, __cur, __alloc);
   throw;
 }
    }
  template<typename _ForwardIterator, typename _Tp>
    inline void
    __uninitialized_default_a(_ForwardIterator __first,
         _ForwardIterator __last,
         allocator<_Tp>&)
    { std::__uninitialized_default(__first, __last); }
  template<typename _ForwardIterator, typename _Size, typename _Allocator>
    _ForwardIterator
    __uninitialized_default_n_a(_ForwardIterator __first, _Size __n,
    _Allocator& __alloc)
    {
      _ForwardIterator __cur = __first;
      try
 {
   typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
   for (; __n > 0; --__n, (void) ++__cur)
     __traits::construct(__alloc, std::__addressof(*__cur));
   return __cur;
 }
      catch(...)
 {
   std::_Destroy(__first, __cur, __alloc);
   throw;
 }
    }
  template<typename _ForwardIterator, typename _Size, typename _Tp>
   
    inline _ForwardIterator
    __uninitialized_default_n_a(_ForwardIterator __first, _Size __n,
    allocator<_Tp>&)
    { return std::__uninitialized_default_n(__first, __n); }
  template<bool _TrivialValueType>
    struct __uninitialized_default_novalue_1
    {
      template<typename _ForwardIterator>
 static void
 __uninit_default_novalue(_ForwardIterator __first,
     _ForwardIterator __last)
 {
   _ForwardIterator __cur = __first;
   try
     {
       for (; __cur != __last; ++__cur)
  std::_Construct_novalue(std::__addressof(*__cur));
     }
   catch(...)
     {
       std::_Destroy(__first, __cur);
       throw;
     }
 }
    };
  template<>
    struct __uninitialized_default_novalue_1<true>
    {
      template<typename _ForwardIterator>
        static void
        __uninit_default_novalue(_ForwardIterator __first,
     _ForwardIterator __last)
 {
 }
    };
  template<bool _TrivialValueType>
    struct __uninitialized_default_novalue_n_1
    {
      template<typename _ForwardIterator, typename _Size>
 static _ForwardIterator
 __uninit_default_novalue_n(_ForwardIterator __first, _Size __n)
 {
   _ForwardIterator __cur = __first;
   try
     {
       for (; __n > 0; --__n, (void) ++__cur)
  std::_Construct_novalue(std::__addressof(*__cur));
       return __cur;
     }
   catch(...)
     {
       std::_Destroy(__first, __cur);
       throw;
     }
 }
    };
  template<>
    struct __uninitialized_default_novalue_n_1<true>
    {
      template<typename _ForwardIterator, typename _Size>
 static _ForwardIterator
 __uninit_default_novalue_n(_ForwardIterator __first, _Size __n)
 { return std::next(__first, __n); }
    };
  template<typename _ForwardIterator>
    inline void
    __uninitialized_default_novalue(_ForwardIterator __first,
        _ForwardIterator __last)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType;
      std::__uninitialized_default_novalue_1<
 is_trivially_default_constructible<_ValueType>::value>::
 __uninit_default_novalue(__first, __last);
    }
  template<typename _ForwardIterator, typename _Size>
    inline _ForwardIterator
    __uninitialized_default_novalue_n(_ForwardIterator __first, _Size __n)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType;
      return __uninitialized_default_novalue_n_1<
 is_trivially_default_constructible<_ValueType>::value>::
 __uninit_default_novalue_n(__first, __n);
    }
  template<typename _InputIterator, typename _Size,
    typename _ForwardIterator>
    _ForwardIterator
    __uninitialized_copy_n(_InputIterator __first, _Size __n,
      _ForwardIterator __result, input_iterator_tag)
    {
      _ForwardIterator __cur = __result;
      try
 {
   for (; __n > 0; --__n, (void) ++__first, ++__cur)
     std::_Construct(std::__addressof(*__cur), *__first);
   return __cur;
 }
      catch(...)
 {
   std::_Destroy(__result, __cur);
   throw;
 }
    }
  template<typename _RandomAccessIterator, typename _Size,
    typename _ForwardIterator>
    inline _ForwardIterator
    __uninitialized_copy_n(_RandomAccessIterator __first, _Size __n,
      _ForwardIterator __result,
      random_access_iterator_tag)
    { return std::uninitialized_copy(__first, __first + __n, __result); }
  template<typename _InputIterator, typename _Size,
    typename _ForwardIterator>
    pair<_InputIterator, _ForwardIterator>
    __uninitialized_copy_n_pair(_InputIterator __first, _Size __n,
      _ForwardIterator __result, input_iterator_tag)
    {
      _ForwardIterator __cur = __result;
      try
 {
   for (; __n > 0; --__n, (void) ++__first, ++__cur)
     std::_Construct(std::__addressof(*__cur), *__first);
   return {__first, __cur};
 }
      catch(...)
 {
   std::_Destroy(__result, __cur);
   throw;
 }
    }
  template<typename _RandomAccessIterator, typename _Size,
    typename _ForwardIterator>
    inline pair<_RandomAccessIterator, _ForwardIterator>
    __uninitialized_copy_n_pair(_RandomAccessIterator __first, _Size __n,
      _ForwardIterator __result,
      random_access_iterator_tag)
    {
      auto __second_res = uninitialized_copy(__first, __first + __n, __result);
      auto __first_res = std::next(__first, __n);
      return {__first_res, __second_res};
    }
  template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    inline _ForwardIterator
    uninitialized_copy_n(_InputIterator __first, _Size __n,
    _ForwardIterator __result)
    { return std::__uninitialized_copy_n(__first, __n, __result,
      std::__iterator_category(__first)); }
  template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    inline pair<_InputIterator, _ForwardIterator>
    __uninitialized_copy_n_pair(_InputIterator __first, _Size __n,
         _ForwardIterator __result)
    {
      return
 std::__uninitialized_copy_n_pair(__first, __n, __result,
      std::__iterator_category(__first));
    }
  template<typename _Tp, typename _Up, typename _Allocator>
   
    inline void
    __relocate_object_a(_Tp* __restrict __dest, _Up* __restrict __orig,
   _Allocator& __alloc)
    noexcept(noexcept(std::allocator_traits<_Allocator>::construct(__alloc,
    __dest, std::move(*__orig)))
      && noexcept(std::allocator_traits<_Allocator>::destroy(
       __alloc, std::__addressof(*__orig))))
    {
      typedef std::allocator_traits<_Allocator> __traits;
      __traits::construct(__alloc, __dest, std::move(*__orig));
      __traits::destroy(__alloc, std::__addressof(*__orig));
    }
  template<typename _Tp, typename = void>
    struct __is_bitwise_relocatable
    : is_trivial<_Tp> { };
  template <typename _InputIterator, typename _ForwardIterator,
     typename _Allocator>
   
    inline _ForwardIterator
    __relocate_a_1(_InputIterator __first, _InputIterator __last,
     _ForwardIterator __result, _Allocator& __alloc)
    noexcept(noexcept(std::__relocate_object_a(std::addressof(*__result),
            std::addressof(*__first),
            __alloc)))
    {
      typedef typename iterator_traits<_InputIterator>::value_type
 _ValueType;
      typedef typename iterator_traits<_ForwardIterator>::value_type
 _ValueType2;
      static_assert(std::is_same<_ValueType, _ValueType2>::value,
   "relocation is only possible for values of the same type");
      _ForwardIterator __cur = __result;
      for (; __first != __last; ++__first, (void)++__cur)
 std::__relocate_object_a(std::__addressof(*__cur),
     std::__addressof(*__first), __alloc);
      return __cur;
    }
  template <typename _Tp, typename _Up>
   
    inline __enable_if_t<std::__is_bitwise_relocatable<_Tp>::value, _Tp*>
    __relocate_a_1(_Tp* __first, _Tp* __last,
     _Tp* __result,
     [[__maybe_unused__]] allocator<_Up>& __alloc) noexcept
    {
      ptrdiff_t __count = __last - __first;
      if (__count > 0)
 {
   __builtin_memmove(__result, __first, __count * sizeof(_Tp));
 }
      return __result + __count;
    }
  template <typename _InputIterator, typename _ForwardIterator,
     typename _Allocator>
   
    inline _ForwardIterator
    __relocate_a(_InputIterator __first, _InputIterator __last,
   _ForwardIterator __result, _Allocator& __alloc)
    noexcept(noexcept(__relocate_a_1(std::__niter_base(__first),
         std::__niter_base(__last),
         std::__niter_base(__result), __alloc)))
    {
      return std::__relocate_a_1(std::__niter_base(__first),
     std::__niter_base(__last),
     std::__niter_base(__result), __alloc);
    }

}
       
namespace std __attribute__ ((__visibility__ ("default")))
{
  template<class _E>
    class initializer_list
    {
    public:
      typedef _E value_type;
      typedef const _E& reference;
      typedef const _E& const_reference;
      typedef size_t size_type;
      typedef const _E* iterator;
      typedef const _E* const_iterator;
    private:
      iterator _M_array;
      size_type _M_len;
      constexpr initializer_list(const_iterator __a, size_type __l)
      : _M_array(__a), _M_len(__l) { }
    public:
      constexpr initializer_list() noexcept
      : _M_array(0), _M_len(0) { }
      constexpr size_type
      size() const noexcept { return _M_len; }
      constexpr const_iterator
      begin() const noexcept { return _M_array; }
      constexpr const_iterator
      end() const noexcept { return begin() + size(); }
    };
  template<class _Tp>
    constexpr const _Tp*
    begin(initializer_list<_Tp> __ils) noexcept
    { return __ils.begin(); }
  template<class _Tp>
    constexpr const _Tp*
    end(initializer_list<_Tp> __ils) noexcept
    { return __ils.end(); }
}
namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Tp, typename _Alloc>
    struct _Vector_base
    {
      typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
 rebind<_Tp>::other _Tp_alloc_type;
      typedef typename __gnu_cxx::__alloc_traits<_Tp_alloc_type>::pointer
        pointer;
      struct _Vector_impl_data
      {
 pointer _M_start;
 pointer _M_finish;
 pointer _M_end_of_storage;

 _Vector_impl_data() noexcept
 : _M_start(), _M_finish(), _M_end_of_storage()
 { }

 _Vector_impl_data(_Vector_impl_data&& __x) noexcept
 : _M_start(__x._M_start), _M_finish(__x._M_finish),
   _M_end_of_storage(__x._M_end_of_storage)
 { __x._M_start = __x._M_finish = __x._M_end_of_storage = pointer(); }

 void
 _M_copy_data(_Vector_impl_data const& __x) noexcept
 {
   _M_start = __x._M_start;
   _M_finish = __x._M_finish;
   _M_end_of_storage = __x._M_end_of_storage;
 }

 void
 _M_swap_data(_Vector_impl_data& __x) noexcept
 {
   _Vector_impl_data __tmp;
   __tmp._M_copy_data(*this);
   _M_copy_data(__x);
   __x._M_copy_data(__tmp);
 }
      };
      struct _Vector_impl
 : public _Tp_alloc_type, public _Vector_impl_data
      {

 _Vector_impl() noexcept(is_nothrow_default_constructible<_Tp_alloc_type>::value)
 : _Tp_alloc_type()
 { }

 _Vector_impl(_Tp_alloc_type const& __a) noexcept
 : _Tp_alloc_type(__a)
 { }

 _Vector_impl(_Vector_impl&& __x) noexcept
 : _Tp_alloc_type(std::move(__x)), _Vector_impl_data(std::move(__x))
 { }

 _Vector_impl(_Tp_alloc_type&& __a) noexcept
 : _Tp_alloc_type(std::move(__a))
 { }

 _Vector_impl(_Tp_alloc_type&& __a, _Vector_impl&& __rv) noexcept
 : _Tp_alloc_type(std::move(__a)), _Vector_impl_data(std::move(__rv))
 { }
      };
    public:
      typedef _Alloc allocator_type;
     
      _Tp_alloc_type&
      _M_get_Tp_allocator() noexcept
      { return this->_M_impl; }
     
      const _Tp_alloc_type&
      _M_get_Tp_allocator() const noexcept
      { return this->_M_impl; }
     
      allocator_type
      get_allocator() const noexcept
      { return allocator_type(_M_get_Tp_allocator()); }
      _Vector_base() = default;
     
      _Vector_base(const allocator_type& __a) noexcept
      : _M_impl(__a) { }
     
      _Vector_base(size_t __n)
      : _M_impl()
      { _M_create_storage(__n); }
     
      _Vector_base(size_t __n, const allocator_type& __a)
      : _M_impl(__a)
      { _M_create_storage(__n); }
      _Vector_base(_Vector_base&&) = default;
     
      _Vector_base(_Tp_alloc_type&& __a) noexcept
      : _M_impl(std::move(__a)) { }
     
      _Vector_base(_Vector_base&& __x, const allocator_type& __a)
      : _M_impl(__a)
      {
 if (__x.get_allocator() == __a)
   this->_M_impl._M_swap_data(__x._M_impl);
 else
   {
     size_t __n = __x._M_impl._M_finish - __x._M_impl._M_start;
     _M_create_storage(__n);
   }
      }
     
      _Vector_base(const allocator_type& __a, _Vector_base&& __x)
      : _M_impl(_Tp_alloc_type(__a), std::move(__x._M_impl))
      { }
     
      ~_Vector_base() noexcept
      {
 _M_deallocate(_M_impl._M_start,
        _M_impl._M_end_of_storage - _M_impl._M_start);
      }
    public:
      _Vector_impl _M_impl;
     
      pointer
      _M_allocate(size_t __n)
      {
 typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
 return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
      }
     
      void
      _M_deallocate(pointer __p, size_t __n)
      {
 typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
 if (__p)
   _Tr::deallocate(_M_impl, __p, __n);
      }
    protected:
     
      void
      _M_create_storage(size_t __n)
      {
 this->_M_impl._M_start = this->_M_allocate(__n);
 this->_M_impl._M_finish = this->_M_impl._M_start;
 this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
      }
    };
  template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
    {
      static_assert(is_same<typename remove_cv<_Tp>::type, _Tp>::value,
   "std::vector must have a non-const, non-volatile value_type");
      static_assert(is_same<typename _Alloc::value_type, _Tp>::value,
   "std::vector must have the same value_type as its allocator");
      typedef _Vector_base<_Tp, _Alloc> _Base;
      typedef typename _Base::_Tp_alloc_type _Tp_alloc_type;
      typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Alloc_traits;
    public:
      typedef _Tp value_type;
      typedef typename _Base::pointer pointer;
      typedef typename _Alloc_traits::const_pointer const_pointer;
      typedef typename _Alloc_traits::reference reference;
      typedef typename _Alloc_traits::const_reference const_reference;
      typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
      typedef __gnu_cxx::__normal_iterator<const_pointer, vector>
      const_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Alloc allocator_type;
    private:
      static constexpr bool
      _S_nothrow_relocate(true_type)
      {
 return noexcept(std::__relocate_a(std::declval<pointer>(),
       std::declval<pointer>(),
       std::declval<pointer>(),
       std::declval<_Tp_alloc_type&>()));
      }
      static constexpr bool
      _S_nothrow_relocate(false_type)
      { return false; }
      static constexpr bool
      _S_use_relocate()
      {
 return _S_nothrow_relocate(__is_move_insertable<_Tp_alloc_type>{});
      }
      static pointer
      _S_do_relocate(pointer __first, pointer __last, pointer __result,
       _Tp_alloc_type& __alloc, true_type) noexcept
      {
 return std::__relocate_a(__first, __last, __result, __alloc);
      }
      static pointer
      _S_do_relocate(pointer, pointer, pointer __result,
       _Tp_alloc_type&, false_type) noexcept
      { return __result; }
      static pointer
      _S_relocate(pointer __first, pointer __last, pointer __result,
    _Tp_alloc_type& __alloc) noexcept
      {
 using __do_it = __bool_constant<_S_use_relocate()>;
 return _S_do_relocate(__first, __last, __result, __alloc, __do_it{});
      }
    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_M_impl;
      using _Base::_M_get_Tp_allocator;
    public:
      vector() = default;
      explicit
     
      vector(const allocator_type& __a) noexcept
      : _Base(__a) { }
      explicit
     
      vector(size_type __n, const allocator_type& __a = allocator_type())
      : _Base(_S_check_init_len(__n, __a), __a)
      { _M_default_initialize(__n); }
     
      vector(size_type __n, const value_type& __value,
      const allocator_type& __a = allocator_type())
      : _Base(_S_check_init_len(__n, __a), __a)
      { _M_fill_initialize(__n, __value); }
     
      vector(const vector& __x)
      : _Base(__x.size(),
 _Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator()))
      {
 this->_M_impl._M_finish =
   std::__uninitialized_copy_a(__x.begin(), __x.end(),
          this->_M_impl._M_start,
          _M_get_Tp_allocator());
      }
      vector(vector&&) noexcept = default;
     
      vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      : _Base(__x.size(), __a)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_copy_a(__x.begin(), __x.end(),
          this->_M_impl._M_start,
          _M_get_Tp_allocator());
      }
    private:
     
      vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      : _Base(__m, std::move(__rv))
      { }
     
      vector(vector&& __rv, const allocator_type& __m, false_type)
      : _Base(__m)
      {
 if (__rv.get_allocator() == __m)
   this->_M_impl._M_swap_data(__rv._M_impl);
 else if (!__rv.empty())
   {
     this->_M_create_storage(__rv.size());
     this->_M_impl._M_finish =
       std::__uninitialized_move_a(__rv.begin(), __rv.end(),
       this->_M_impl._M_start,
       _M_get_Tp_allocator());
     __rv.clear();
   }
      }
    public:
     
      vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      noexcept( noexcept(
 vector(std::declval<vector&&>(), std::declval<const allocator_type&>(),
        std::declval<typename _Alloc_traits::is_always_equal>())) )
      : vector(std::move(__rv), __m, typename _Alloc_traits::is_always_equal{})
      { }
     
      vector(initializer_list<value_type> __l,
      const allocator_type& __a = allocator_type())
      : _Base(__a)
      {
 _M_range_initialize(__l.begin(), __l.end(),
       random_access_iterator_tag());
      }
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>

 vector(_InputIterator __first, _InputIterator __last,
        const allocator_type& __a = allocator_type())
 : _Base(__a)
 {
   _M_range_initialize(__first, __last,
         std::__iterator_category(__first));
 }
     
      ~vector() noexcept
      {
 std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
        _M_get_Tp_allocator());
 ;
      }
     
      vector&
      operator=(const vector& __x);
     
      vector&
      operator=(vector&& __x) noexcept(_Alloc_traits::_S_nothrow_move())
      {
 constexpr bool __move_storage =
   _Alloc_traits::_S_propagate_on_move_assign()
   || _Alloc_traits::_S_always_equal();
 _M_move_assign(std::move(__x), __bool_constant<__move_storage>());
 return *this;
      }
     
      vector&
      operator=(initializer_list<value_type> __l)
      {
 this->_M_assign_aux(__l.begin(), __l.end(),
       random_access_iterator_tag());
 return *this;
      }
     
      void
      assign(size_type __n, const value_type& __val)
      { _M_fill_assign(__n, __val); }
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>

 void
 assign(_InputIterator __first, _InputIterator __last)
 { _M_assign_aux(__first, __last, std::__iterator_category(__first)); }
     
      void
      assign(initializer_list<value_type> __l)
      {
 this->_M_assign_aux(__l.begin(), __l.end(),
       random_access_iterator_tag());
      }
      using _Base::get_allocator;
     
      iterator
      begin() noexcept
      { return iterator(this->_M_impl._M_start); }
     
      const_iterator
      begin() const noexcept
      { return const_iterator(this->_M_impl._M_start); }
     
      iterator
      end() noexcept
      { return iterator(this->_M_impl._M_finish); }
     
      const_iterator
      end() const noexcept
      { return const_iterator(this->_M_impl._M_finish); }
     
      reverse_iterator
      rbegin() noexcept
      { return reverse_iterator(end()); }
     
      const_reverse_iterator
      rbegin() const noexcept
      { return const_reverse_iterator(end()); }
     
      reverse_iterator
      rend() noexcept
      { return reverse_iterator(begin()); }
     
      const_reverse_iterator
      rend() const noexcept
      { return const_reverse_iterator(begin()); }
      [[__nodiscard__]]
      const_iterator
      cbegin() const noexcept
      { return const_iterator(this->_M_impl._M_start); }
      [[__nodiscard__]]
      const_iterator
      cend() const noexcept
      { return const_iterator(this->_M_impl._M_finish); }
      [[__nodiscard__]]
      const_reverse_iterator
      crbegin() const noexcept
      { return const_reverse_iterator(end()); }
      [[__nodiscard__]]
      const_reverse_iterator
      crend() const noexcept
      { return const_reverse_iterator(begin()); }
     
      size_type
      size() const noexcept
      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
     
      size_type
      max_size() const noexcept
      { return _S_max_size(_M_get_Tp_allocator()); }
     
      void
      resize(size_type __new_size)
      {
 if (__new_size > size())
   _M_default_append(__new_size - size());
 else if (__new_size < size())
   _M_erase_at_end(this->_M_impl._M_start + __new_size);
      }
     
      void
      resize(size_type __new_size, const value_type& __x)
      {
 if (__new_size > size())
   _M_fill_insert(end(), __new_size - size(), __x);
 else if (__new_size < size())
   _M_erase_at_end(this->_M_impl._M_start + __new_size);
      }
     
      void
      shrink_to_fit()
      { _M_shrink_to_fit(); }
     
      size_type
      capacity() const noexcept
      { return size_type(this->_M_impl._M_end_of_storage
    - this->_M_impl._M_start); }
     
      bool
      empty() const noexcept
      { return begin() == end(); }
     
      void
      reserve(size_type __n);
     
      reference
      operator[](size_type __n) noexcept
      {
 ;
 return *(this->_M_impl._M_start + __n);
      }
     
      const_reference
      operator[](size_type __n) const noexcept
      {
 ;
 return *(this->_M_impl._M_start + __n);
      }
    protected:
     
      void
      _M_range_check(size_type __n) const
      {
 if (__n >= this->size())
   __throw_out_of_range_fmt(("vector::_M_range_check: __n " "(which is %zu) >= this->size() " "(which is %zu)"),
       __n, this->size());
      }
    public:
     
      reference
      at(size_type __n)
      {
 _M_range_check(__n);
 return (*this)[__n];
      }
     
      const_reference
      at(size_type __n) const
      {
 _M_range_check(__n);
 return (*this)[__n];
      }
     
      reference
      front() noexcept
      {
 ;
 return *begin();
      }
     
      const_reference
      front() const noexcept
      {
 ;
 return *begin();
      }
     
      reference
      back() noexcept
      {
 ;
 return *(end() - 1);
      }
     
      const_reference
      back() const noexcept
      {
 ;
 return *(end() - 1);
      }
     
      _Tp*
      data() noexcept
      { return _M_data_ptr(this->_M_impl._M_start); }
     
      const _Tp*
      data() const noexcept
      { return _M_data_ptr(this->_M_impl._M_start); }
     
      void
      push_back(const value_type& __x)
      {
 if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
   {
     ;
     _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
         __x);
     ++this->_M_impl._M_finish;
     ;
   }
 else
   _M_realloc_insert(end(), __x);
      }
     
      void
      push_back(value_type&& __x)
      { emplace_back(std::move(__x)); }
      template<typename... _Args>
 void
 emplace_back(_Args&&... __args);
     
      void
      pop_back() noexcept
      {
 ;
 --this->_M_impl._M_finish;
 _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
 ;
      }
      template<typename... _Args>

 iterator
 emplace(const_iterator __position, _Args&&... __args)
 { return _M_emplace_aux(__position, std::forward<_Args>(__args)...); }
     
      iterator
      insert(const_iterator __position, const value_type& __x);
     
      iterator
      insert(const_iterator __position, value_type&& __x)
      { return _M_insert_rval(__position, std::move(__x)); }
     
      iterator
      insert(const_iterator __position, initializer_list<value_type> __l)
      {
 auto __offset = __position - cbegin();
 _M_range_insert(begin() + __offset, __l.begin(), __l.end(),
   std::random_access_iterator_tag());
 return begin() + __offset;
      }
     
      iterator
      insert(const_iterator __position, size_type __n, const value_type& __x)
      {
 difference_type __offset = __position - cbegin();
 _M_fill_insert(begin() + __offset, __n, __x);
 return begin() + __offset;
      }
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>

 iterator
 insert(const_iterator __position, _InputIterator __first,
        _InputIterator __last)
 {
   difference_type __offset = __position - cbegin();
   _M_range_insert(begin() + __offset, __first, __last,
     std::__iterator_category(__first));
   return begin() + __offset;
 }
     
      iterator
      erase(const_iterator __position)
      { return _M_erase(begin() + (__position - cbegin())); }
     
      iterator
      erase(const_iterator __first, const_iterator __last)
      {
 const auto __beg = begin();
 const auto __cbeg = cbegin();
 return _M_erase(__beg + (__first - __cbeg), __beg + (__last - __cbeg));
      }
     
      void
      swap(vector& __x) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(_Alloc_traits::propagate_on_container_swap::value || _M_get_Tp_allocator() == __x._M_get_Tp_allocator())) __builtin_unreachable(); } while (false);
 this->_M_impl._M_swap_data(__x._M_impl);
 _Alloc_traits::_S_on_swap(_M_get_Tp_allocator(),
      __x._M_get_Tp_allocator());
      }
     
      void
      clear() noexcept
      { _M_erase_at_end(this->_M_impl._M_start); }
    protected:
      template<typename _ForwardIterator>

 pointer
 _M_allocate_and_copy(size_type __n,
        _ForwardIterator __first, _ForwardIterator __last)
 {
   pointer __result = this->_M_allocate(__n);
   try
     {
       std::__uninitialized_copy_a(__first, __last, __result,
       _M_get_Tp_allocator());
       return __result;
     }
   catch(...)
     {
       _M_deallocate(__result, __n);
       throw;
     }
 }
      template<typename _InputIterator>

 void
 _M_range_initialize(_InputIterator __first, _InputIterator __last,
       std::input_iterator_tag)
 {
   try {
     for (; __first != __last; ++__first)
       emplace_back(*__first);
   } catch(...) {
     clear();
     throw;
   }
 }
      template<typename _ForwardIterator>

 void
 _M_range_initialize(_ForwardIterator __first, _ForwardIterator __last,
       std::forward_iterator_tag)
 {
   const size_type __n = std::distance(__first, __last);
   this->_M_impl._M_start
     = this->_M_allocate(_S_check_init_len(__n, _M_get_Tp_allocator()));
   this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
   this->_M_impl._M_finish =
     std::__uninitialized_copy_a(__first, __last,
     this->_M_impl._M_start,
     _M_get_Tp_allocator());
 }
     
      void
      _M_fill_initialize(size_type __n, const value_type& __value)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_fill_n_a(this->_M_impl._M_start, __n, __value,
     _M_get_Tp_allocator());
      }
     
      void
      _M_default_initialize(size_type __n)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_default_n_a(this->_M_impl._M_start, __n,
        _M_get_Tp_allocator());
      }
      template<typename _Integer>

 void
 _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
 { _M_fill_assign(__n, __val); }
      template<typename _InputIterator>

 void
 _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
      __false_type)
 { _M_assign_aux(__first, __last, std::__iterator_category(__first)); }
      template<typename _InputIterator>

 void
 _M_assign_aux(_InputIterator __first, _InputIterator __last,
        std::input_iterator_tag);
      template<typename _ForwardIterator>

 void
 _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
        std::forward_iterator_tag);
     
      void
      _M_fill_assign(size_type __n, const value_type& __val);
      template<typename _Integer>

 void
 _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
      __true_type)
 { _M_fill_insert(__pos, __n, __val); }
      template<typename _InputIterator>

 void
 _M_insert_dispatch(iterator __pos, _InputIterator __first,
      _InputIterator __last, __false_type)
 {
   _M_range_insert(__pos, __first, __last,
     std::__iterator_category(__first));
 }
      template<typename _InputIterator>

 void
 _M_range_insert(iterator __pos, _InputIterator __first,
   _InputIterator __last, std::input_iterator_tag);
      template<typename _ForwardIterator>

 void
 _M_range_insert(iterator __pos, _ForwardIterator __first,
   _ForwardIterator __last, std::forward_iterator_tag);
     
      void
      _M_fill_insert(iterator __pos, size_type __n, const value_type& __x);
     
      void
      _M_default_append(size_type __n);
     
      bool
      _M_shrink_to_fit();
      struct _Temporary_value
      {
 template<typename... _Args>
   explicit
   _Temporary_value(vector* __vec, _Args&&... __args) : _M_this(__vec)
   {
     _Alloc_traits::construct(_M_this->_M_impl, _M_ptr(),
         std::forward<_Args>(__args)...);
   }

 ~_Temporary_value()
 { _Alloc_traits::destroy(_M_this->_M_impl, _M_ptr()); }
 value_type&
 _M_val() noexcept { return _M_storage._M_val; }
      private:
 _Tp*
 _M_ptr() noexcept { return std::__addressof(_M_storage._M_val); }
 union _Storage
 {
   constexpr _Storage() : _M_byte() { }
   ~_Storage() { }
   _Storage& operator=(const _Storage&) = delete;
   unsigned char _M_byte;
   _Tp _M_val;
 };
 vector* _M_this;
 _Storage _M_storage;
      };
      template<typename _Arg>

 void
 _M_insert_aux(iterator __position, _Arg&& __arg);
      template<typename... _Args>

 void
 _M_realloc_insert(iterator __position, _Args&&... __args);
     
      iterator
      _M_insert_rval(const_iterator __position, value_type&& __v);
      template<typename... _Args>

 iterator
 _M_emplace_aux(const_iterator __position, _Args&&... __args);
     
      iterator
      _M_emplace_aux(const_iterator __position, value_type&& __v)
      { return _M_insert_rval(__position, std::move(__v)); }
     
      size_type
      _M_check_len(size_type __n, const char* __s) const
      {
 if (max_size() - size() < __n)
   __throw_length_error((__s));
 const size_type __len = size() + (std::max)(size(), __n);
 return (__len < size() || __len > max_size()) ? max_size() : __len;
      }
      static size_type
      _S_check_init_len(size_type __n, const allocator_type& __a)
      {
 if (__n > _S_max_size(_Tp_alloc_type(__a)))
   __throw_length_error(
       ("cannot create std::vector larger than max_size()"));
 return __n;
      }
      static size_type
      _S_max_size(const _Tp_alloc_type& __a) noexcept
      {
 const size_t __diffmax
   = __gnu_cxx::__numeric_traits<ptrdiff_t>::__max / sizeof(_Tp);
 const size_t __allocmax = _Alloc_traits::max_size(__a);
 return (std::min)(__diffmax, __allocmax);
      }
     
      void
      _M_erase_at_end(pointer __pos) noexcept
      {
 if (size_type __n = this->_M_impl._M_finish - __pos)
   {
     std::_Destroy(__pos, this->_M_impl._M_finish,
     _M_get_Tp_allocator());
     this->_M_impl._M_finish = __pos;
     ;
   }
      }
     
      iterator
      _M_erase(iterator __position);
     
      iterator
      _M_erase(iterator __first, iterator __last);
    private:
     
      void
      _M_move_assign(vector&& __x, true_type) noexcept
      {
 vector __tmp(get_allocator());
 this->_M_impl._M_swap_data(__x._M_impl);
 __tmp._M_impl._M_swap_data(__x._M_impl);
 std::__alloc_on_move(_M_get_Tp_allocator(), __x._M_get_Tp_allocator());
      }
     
      void
      _M_move_assign(vector&& __x, false_type)
      {
 if (__x._M_get_Tp_allocator() == this->_M_get_Tp_allocator())
   _M_move_assign(std::move(__x), true_type());
 else
   {
     this->_M_assign_aux(std::make_move_iterator(__x.begin()),
           std::make_move_iterator(__x.end()),
    std::random_access_iterator_tag());
     __x.clear();
   }
      }
      template<typename _Up>

 _Up*
 _M_data_ptr(_Up* __ptr) const noexcept
 { return __ptr; }
      template<typename _Ptr>

 typename std::pointer_traits<_Ptr>::element_type*
 _M_data_ptr(_Ptr __ptr) const
 { return empty() ? nullptr : std::__to_address(__ptr); }
    };
  template<typename _Tp, typename _Alloc>
   
    inline bool
    operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return (__x.size() == __y.size()
       && std::equal(__x.begin(), __x.end(), __y.begin())); }
  template<typename _Tp, typename _Alloc>
    inline bool
    operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return std::lexicographical_compare(__x.begin(), __x.end(),
       __y.begin(), __y.end()); }
  template<typename _Tp, typename _Alloc>
    inline bool
    operator!=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__x == __y); }
  template<typename _Tp, typename _Alloc>
    inline bool
    operator>(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return __y < __x; }
  template<typename _Tp, typename _Alloc>
    inline bool
    operator<=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__y < __x); }
  template<typename _Tp, typename _Alloc>
    inline bool
    operator>=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__x < __y); }
  template<typename _Tp, typename _Alloc>
   
    inline void
    swap(vector<_Tp, _Alloc>& __x, vector<_Tp, _Alloc>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }


}
       
       
namespace std
{

  size_t
  _Hash_bytes(const void* __ptr, size_t __len, size_t __seed);
  size_t
  _Fnv_hash_bytes(const void* __ptr, size_t __len, size_t __seed);

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Result, typename _Arg>
    struct __hash_base
    {
      typedef _Result result_type ;
      typedef _Arg argument_type ;
    };
  template<typename _Tp>
    struct hash;
  template<typename _Tp, typename = void>
    struct __poison_hash
    {
      static constexpr bool __enable_hash_call = false;
    private:
      __poison_hash(__poison_hash&&);
      ~__poison_hash();
    };
  template<typename _Tp>
    struct __poison_hash<_Tp, __void_t<decltype(hash<_Tp>()(declval<_Tp>()))>>
    {
      static constexpr bool __enable_hash_call = true;
    };
  template<typename _Tp, bool = is_enum<_Tp>::value>
    struct __hash_enum
    {
    private:
      __hash_enum(__hash_enum&&);
      ~__hash_enum();
    };
  template<typename _Tp>
    struct __hash_enum<_Tp, true> : public __hash_base<size_t, _Tp>
    {
      size_t
      operator()(_Tp __val) const noexcept
      {
       using __type = typename underlying_type<_Tp>::type;
       return hash<__type>{}(static_cast<__type>(__val));
      }
    };
  template<typename _Tp>
    struct hash : __hash_enum<_Tp>
    { };
  template<typename _Tp>
    struct hash<_Tp*> : public __hash_base<size_t, _Tp*>
    {
      size_t
      operator()(_Tp* __p) const noexcept
      { return reinterpret_cast<size_t>(__p); }
    };
  template<> struct hash<bool> : public __hash_base<size_t, bool> { size_t operator()(bool __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<char> : public __hash_base<size_t, char> { size_t operator()(char __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<signed char> : public __hash_base<size_t, signed char> { size_t operator()(signed char __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<unsigned char> : public __hash_base<size_t, unsigned char> { size_t operator()(unsigned char __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<wchar_t> : public __hash_base<size_t, wchar_t> { size_t operator()(wchar_t __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<char16_t> : public __hash_base<size_t, char16_t> { size_t operator()(char16_t __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<char32_t> : public __hash_base<size_t, char32_t> { size_t operator()(char32_t __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<short> : public __hash_base<size_t, short> { size_t operator()(short __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<int> : public __hash_base<size_t, int> { size_t operator()(int __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<long> : public __hash_base<size_t, long> { size_t operator()(long __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<long long> : public __hash_base<size_t, long long> { size_t operator()(long long __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<unsigned short> : public __hash_base<size_t, unsigned short> { size_t operator()(unsigned short __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<unsigned int> : public __hash_base<size_t, unsigned int> { size_t operator()(unsigned int __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<unsigned long> : public __hash_base<size_t, unsigned long> { size_t operator()(unsigned long __val) const noexcept { return static_cast<size_t>(__val); } };
  template<> struct hash<unsigned long long> : public __hash_base<size_t, unsigned long long> { size_t operator()(unsigned long long __val) const noexcept { return static_cast<size_t>(__val); } };
  struct _Hash_impl
  {
    static size_t
    hash(const void* __ptr, size_t __clength,
  size_t __seed = static_cast<size_t>(0xc70f6907UL))
    { return _Hash_bytes(__ptr, __clength, __seed); }
    template<typename _Tp>
      static size_t
      hash(const _Tp& __val)
      { return hash(&__val, sizeof(__val)); }
    template<typename _Tp>
      static size_t
      __hash_combine(const _Tp& __val, size_t __hash)
      { return hash(&__val, sizeof(__val), __hash); }
  };
  struct _Fnv_hash_impl
  {
    static size_t
    hash(const void* __ptr, size_t __clength,
  size_t __seed = static_cast<size_t>(2166136261UL))
    { return _Fnv_hash_bytes(__ptr, __clength, __seed); }
    template<typename _Tp>
      static size_t
      hash(const _Tp& __val)
      { return hash(&__val, sizeof(__val)); }
    template<typename _Tp>
      static size_t
      __hash_combine(const _Tp& __val, size_t __hash)
      { return hash(&__val, sizeof(__val), __hash); }
  };
  template<>
    struct hash<float> : public __hash_base<size_t, float>
    {
      size_t
      operator()(float __val) const noexcept
      {
 return __val != 0.0f ? std::_Hash_impl::hash(__val) : 0;
      }
    };
  template<>
    struct hash<double> : public __hash_base<size_t, double>
    {
      size_t
      operator()(double __val) const noexcept
      {
 return __val != 0.0 ? std::_Hash_impl::hash(__val) : 0;
      }
    };
  template<>
    struct hash<long double>
    : public __hash_base<size_t, long double>
    {
      __attribute__ ((__pure__)) size_t
      operator()(long double __val) const noexcept;
    };
  template<typename _Hash>
    struct __is_fast_hash : public std::true_type
    { };
  template<>
    struct __is_fast_hash<hash<long double>> : public std::false_type
    { };

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  typedef unsigned long _Bit_type;
  enum { _S_word_bit = int(8 * sizeof(_Bit_type)) };
  __attribute__((__nonnull__))
 
  void
  __fill_bvector_n(_Bit_type*, size_t, bool) noexcept;

  struct _Bit_reference
  {
    _Bit_type * _M_p;
    _Bit_type _M_mask;
   
    _Bit_reference(_Bit_type * __x, _Bit_type __y)
    : _M_p(__x), _M_mask(__y) { }
   
    _Bit_reference() noexcept : _M_p(0), _M_mask(0) { }
    _Bit_reference(const _Bit_reference&) = default;
   
    operator bool() const noexcept
    { return !!(*_M_p & _M_mask); }
   
    _Bit_reference&
    operator=(bool __x) noexcept
    {
      if (__x)
 *_M_p |= _M_mask;
      else
 *_M_p &= ~_M_mask;
      return *this;
    }
   
    _Bit_reference&
    operator=(const _Bit_reference& __x) noexcept
    { return *this = bool(__x); }
   
    bool
    operator==(const _Bit_reference& __x) const
    { return bool(*this) == bool(__x); }
   
    bool
    operator<(const _Bit_reference& __x) const
    { return !bool(*this) && bool(__x); }
   
    void
    flip() noexcept
    { *_M_p ^= _M_mask; }
   
    friend void
    swap(_Bit_reference __x, _Bit_reference __y) noexcept
    {
      bool __tmp = __x;
      __x = __y;
      __y = __tmp;
    }
   
    friend void
    swap(_Bit_reference __x, bool& __y) noexcept
    {
      bool __tmp = __x;
      __x = __y;
      __y = __tmp;
    }
   
    friend void
    swap(bool& __x, _Bit_reference __y) noexcept
    {
      bool __tmp = __x;
      __x = __y;
      __y = __tmp;
    }
  };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  struct _Bit_iterator_base
  : public std::iterator<std::random_access_iterator_tag, bool>
  {
    _Bit_type * _M_p;
    unsigned int _M_offset;
   
    _Bit_iterator_base(_Bit_type * __x, unsigned int __y)
    : _M_p(__x), _M_offset(__y) { }
   
    void
    _M_bump_up()
    {
      if (_M_offset++ == int(_S_word_bit) - 1)
 {
   _M_offset = 0;
   ++_M_p;
 }
    }
   
    void
    _M_bump_down()
    {
      if (_M_offset-- == 0)
 {
   _M_offset = int(_S_word_bit) - 1;
   --_M_p;
 }
    }
   
    void
    _M_incr(ptrdiff_t __i)
    {
      difference_type __n = __i + _M_offset;
      _M_p += __n / int(_S_word_bit);
      __n = __n % int(_S_word_bit);
      if (__n < 0)
 {
   __n += int(_S_word_bit);
   --_M_p;
 }
      _M_offset = static_cast<unsigned int>(__n);
    }
   
    friend bool
    operator==(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    { return __x._M_p == __y._M_p && __x._M_offset == __y._M_offset; }
   
    friend bool
    operator<(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    {
      return __x._M_p < __y._M_p
     || (__x._M_p == __y._M_p && __x._M_offset < __y._M_offset);
    }
   
    friend bool
    operator!=(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    { return !(__x == __y); }
   
    friend bool
    operator>(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    { return __y < __x; }
   
    friend bool
    operator<=(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    { return !(__y < __x); }
   
    friend bool
    operator>=(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    { return !(__x < __y); }
    friend ptrdiff_t
    operator-(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
    {
      return (int(_S_word_bit) * (__x._M_p - __y._M_p)
       + __x._M_offset - __y._M_offset);
    }
  };
#pragma GCC diagnostic pop
  struct _Bit_iterator : public _Bit_iterator_base
  {
    typedef _Bit_reference reference;
    typedef _Bit_reference* pointer;
    typedef _Bit_iterator iterator;
   
    _Bit_iterator() : _Bit_iterator_base(0, 0) { }
   
    _Bit_iterator(_Bit_type * __x, unsigned int __y)
    : _Bit_iterator_base(__x, __y) { }
   
    iterator
    _M_const_cast() const
    { return *this; }
   
    reference
    operator*() const
    { return reference(_M_p, 1UL << _M_offset); }
   
    iterator&
    operator++()
    {
      _M_bump_up();
      return *this;
    }
   
    iterator
    operator++(int)
    {
      iterator __tmp = *this;
      _M_bump_up();
      return __tmp;
    }
   
    iterator&
    operator--()
    {
      _M_bump_down();
      return *this;
    }
   
    iterator
    operator--(int)
    {
      iterator __tmp = *this;
      _M_bump_down();
      return __tmp;
    }
   
    iterator&
    operator+=(difference_type __i)
    {
      _M_incr(__i);
      return *this;
    }
   
    iterator&
    operator-=(difference_type __i)
    {
      *this += -__i;
      return *this;
    }
   
    reference
    operator[](difference_type __i) const
    { return *(*this + __i); }
   
    friend iterator
    operator+(const iterator& __x, difference_type __n)
    {
      iterator __tmp = __x;
      __tmp += __n;
      return __tmp;
    }
   
    friend iterator
    operator+(difference_type __n, const iterator& __x)
    { return __x + __n; }
   
    friend iterator
    operator-(const iterator& __x, difference_type __n)
    {
      iterator __tmp = __x;
      __tmp -= __n;
      return __tmp;
    }
  };
  struct _Bit_const_iterator : public _Bit_iterator_base
  {
    typedef bool reference;
    typedef bool const_reference;
    typedef const bool* pointer;
    typedef _Bit_const_iterator const_iterator;
   
    _Bit_const_iterator() : _Bit_iterator_base(0, 0) { }
   
    _Bit_const_iterator(_Bit_type * __x, unsigned int __y)
    : _Bit_iterator_base(__x, __y) { }
   
    _Bit_const_iterator(const _Bit_iterator& __x)
    : _Bit_iterator_base(__x._M_p, __x._M_offset) { }
   
    _Bit_iterator
    _M_const_cast() const
    { return _Bit_iterator(_M_p, _M_offset); }
   
    const_reference
    operator*() const
    { return _Bit_reference(_M_p, 1UL << _M_offset); }
   
    const_iterator&
    operator++()
    {
      _M_bump_up();
      return *this;
    }
   
    const_iterator
    operator++(int)
    {
      const_iterator __tmp = *this;
      _M_bump_up();
      return __tmp;
    }
   
    const_iterator&
    operator--()
    {
      _M_bump_down();
      return *this;
    }
   
    const_iterator
    operator--(int)
    {
      const_iterator __tmp = *this;
      _M_bump_down();
      return __tmp;
    }
   
    const_iterator&
    operator+=(difference_type __i)
    {
      _M_incr(__i);
      return *this;
    }
   
    const_iterator&
    operator-=(difference_type __i)
    {
      *this += -__i;
      return *this;
    }
   
    const_reference
    operator[](difference_type __i) const
    { return *(*this + __i); }
   
    friend const_iterator
    operator+(const const_iterator& __x, difference_type __n)
    {
      const_iterator __tmp = __x;
      __tmp += __n;
      return __tmp;
    }
   
    friend const_iterator
    operator-(const const_iterator& __x, difference_type __n)
    {
      const_iterator __tmp = __x;
      __tmp -= __n;
      return __tmp;
    }
   
    friend const_iterator
    operator+(difference_type __n, const const_iterator& __x)
    { return __x + __n; }
  };
  template<typename _Alloc>
    struct _Bvector_base
    {
      typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
        rebind<_Bit_type>::other _Bit_alloc_type;
      typedef typename __gnu_cxx::__alloc_traits<_Bit_alloc_type>
 _Bit_alloc_traits;
      typedef typename _Bit_alloc_traits::pointer _Bit_pointer;
      struct _Bvector_impl_data
      {
 _Bit_iterator _M_start;
 _Bit_iterator _M_finish;
 _Bit_pointer _M_end_of_storage;

 _Bvector_impl_data() noexcept
 : _M_start(), _M_finish(), _M_end_of_storage()
 { }
 _Bvector_impl_data(const _Bvector_impl_data&) = default;
 _Bvector_impl_data&
 operator=(const _Bvector_impl_data&) = default;

 _Bvector_impl_data(_Bvector_impl_data&& __x) noexcept
 : _Bvector_impl_data(__x)
 { __x._M_reset(); }

 void
 _M_move_data(_Bvector_impl_data&& __x) noexcept
 {
   *this = __x;
   __x._M_reset();
 }

 void
 _M_reset() noexcept
 { *this = _Bvector_impl_data(); }

 void
 _M_swap_data(_Bvector_impl_data& __x) noexcept
 {
   std::swap(*this, __x);
 }
      };
      struct _Bvector_impl
 : public _Bit_alloc_type, public _Bvector_impl_data
      {

 _Bvector_impl() noexcept(is_nothrow_default_constructible<_Bit_alloc_type>::value)
 : _Bit_alloc_type()
 { }

 _Bvector_impl(const _Bit_alloc_type& __a) noexcept
 : _Bit_alloc_type(__a)
 { }

 _Bvector_impl(_Bvector_impl&& __x) noexcept
 : _Bit_alloc_type(std::move(__x)), _Bvector_impl_data(std::move(__x))
 { }

 _Bvector_impl(_Bit_alloc_type&& __a, _Bvector_impl&& __x) noexcept
 : _Bit_alloc_type(std::move(__a)), _Bvector_impl_data(std::move(__x))
 { }

 _Bit_type*
 _M_end_addr() const noexcept
 {
   if (this->_M_end_of_storage)
     return std::__addressof(this->_M_end_of_storage[-1]) + 1;
   return 0;
 }
      };
    public:
      typedef _Alloc allocator_type;
     
      _Bit_alloc_type&
      _M_get_Bit_allocator() noexcept
      { return this->_M_impl; }
     
      const _Bit_alloc_type&
      _M_get_Bit_allocator() const noexcept
      { return this->_M_impl; }
     
      allocator_type
      get_allocator() const noexcept
      { return allocator_type(_M_get_Bit_allocator()); }
      _Bvector_base() = default;
     
      _Bvector_base(const allocator_type& __a)
      : _M_impl(__a) { }
      _Bvector_base(_Bvector_base&&) = default;
     
      _Bvector_base(_Bvector_base&& __x, const allocator_type& __a) noexcept
      : _M_impl(_Bit_alloc_type(__a), std::move(__x._M_impl))
      { }
     
      ~_Bvector_base()
      { this->_M_deallocate(); }
    protected:
      _Bvector_impl _M_impl;
     
      _Bit_pointer
      _M_allocate(size_t __n)
      {
 _Bit_pointer __p = _Bit_alloc_traits::allocate(_M_impl, _S_nword(__n));
 return __p;
      }
     
      void
      _M_deallocate()
      {
 if (_M_impl._M_start._M_p)
   {
     const size_t __n = _M_impl._M_end_addr() - _M_impl._M_start._M_p;
     _Bit_alloc_traits::deallocate(_M_impl,
       _M_impl._M_end_of_storage - __n,
       __n);
     _M_impl._M_reset();
   }
      }
     
      void
      _M_move_data(_Bvector_base&& __x) noexcept
      { _M_impl._M_move_data(std::move(__x._M_impl)); }
      constexpr
      static size_t
      _S_nword(size_t __n)
      { return (__n + int(_S_word_bit) - 1) / int(_S_word_bit); }
    };
  template<typename _Alloc>
    class vector<bool, _Alloc> : protected _Bvector_base<_Alloc>
    {
      typedef _Bvector_base<_Alloc> _Base;
      typedef typename _Base::_Bit_pointer _Bit_pointer;
      typedef typename _Base::_Bit_alloc_traits _Bit_alloc_traits;
      friend struct std::hash<vector>;
    public:
      typedef bool value_type;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Bit_reference reference;
      typedef bool const_reference;
      typedef _Bit_reference* pointer;
      typedef const bool* const_pointer;
      typedef _Bit_iterator iterator;
      typedef _Bit_const_iterator const_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef _Alloc allocator_type;
     
      allocator_type
      get_allocator() const
      { return _Base::get_allocator(); }
    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_S_nword;
      using _Base::_M_get_Bit_allocator;
    public:
      vector() = default;
     
      explicit
      vector(const allocator_type& __a)
      : _Base(__a) { }
     
      explicit
      vector(size_type __n, const allocator_type& __a = allocator_type())
      : vector(__n, false, __a)
      { }
     
      vector(size_type __n, const bool& __value,
      const allocator_type& __a = allocator_type())
      : _Base(__a)
      {
 _M_initialize(__n);
 _M_initialize_value(__value);
      }
     
      vector(const vector& __x)
      : _Base(_Bit_alloc_traits::_S_select_on_copy(__x._M_get_Bit_allocator()))
      {
 const_iterator __xbegin = __x.begin(), __xend = __x.end();
 _M_initialize(__x.size());
 _M_copy_aligned(__xbegin, __xend, begin());
      }
      vector(vector&&) = default;
    private:
     
      vector(vector&& __x, const allocator_type& __a, true_type) noexcept
      : _Base(std::move(__x), __a)
      { }
     
      vector(vector&& __x, const allocator_type& __a, false_type)
      : _Base(__a)
      {
 if (__x.get_allocator() == __a)
   this->_M_move_data(std::move(__x));
 else
   {
     _M_initialize(__x.size());
     _M_copy_aligned(__x.begin(), __x.end(), begin());
     __x.clear();
   }
      }
    public:
     
      vector(vector&& __x, const __type_identity_t<allocator_type>& __a)
      noexcept(_Bit_alloc_traits::_S_always_equal())
      : vector(std::move(__x), __a,
        typename _Bit_alloc_traits::is_always_equal{})
      { }
     
      vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      : _Base(__a)
      {
 _M_initialize(__x.size());
 _M_copy_aligned(__x.begin(), __x.end(), begin());
      }
     
      vector(initializer_list<bool> __l,
      const allocator_type& __a = allocator_type())
      : _Base(__a)
      {
 _M_initialize_range(__l.begin(), __l.end(),
       random_access_iterator_tag());
      }
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>

 vector(_InputIterator __first, _InputIterator __last,
        const allocator_type& __a = allocator_type())
 : _Base(__a)
 {
   _M_initialize_range(__first, __last,
         std::__iterator_category(__first));
 }
     
      ~vector() noexcept { }
     
      vector&
      operator=(const vector& __x)
      {
 if (&__x == this)
   return *this;
 if (_Bit_alloc_traits::_S_propagate_on_copy_assign())
   {
     if (this->_M_get_Bit_allocator() != __x._M_get_Bit_allocator())
       {
  this->_M_deallocate();
  std::__alloc_on_copy(_M_get_Bit_allocator(),
         __x._M_get_Bit_allocator());
  _M_initialize(__x.size());
       }
     else
       std::__alloc_on_copy(_M_get_Bit_allocator(),
       __x._M_get_Bit_allocator());
   }
 if (__x.size() > capacity())
   {
     this->_M_deallocate();
     _M_initialize(__x.size());
   }
 this->_M_impl._M_finish = _M_copy_aligned(__x.begin(), __x.end(),
        begin());
 return *this;
      }
     
      vector&
      operator=(vector&& __x) noexcept(_Bit_alloc_traits::_S_nothrow_move())
      {
 if (_Bit_alloc_traits::_S_propagate_on_move_assign()
     || this->_M_get_Bit_allocator() == __x._M_get_Bit_allocator())
   {
     this->_M_deallocate();
     this->_M_move_data(std::move(__x));
     std::__alloc_on_move(_M_get_Bit_allocator(),
     __x._M_get_Bit_allocator());
   }
 else
   {
     if (__x.size() > capacity())
       {
  this->_M_deallocate();
  _M_initialize(__x.size());
       }
     this->_M_impl._M_finish = _M_copy_aligned(__x.begin(), __x.end(),
            begin());
     __x.clear();
   }
 return *this;
      }
     
      vector&
      operator=(initializer_list<bool> __l)
      {
 this->assign(__l.begin(), __l.end());
 return *this;
      }
     
      void
      assign(size_type __n, const bool& __x)
      { _M_fill_assign(__n, __x); }
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>

 void
 assign(_InputIterator __first, _InputIterator __last)
 { _M_assign_aux(__first, __last, std::__iterator_category(__first)); }
     
      void
      assign(initializer_list<bool> __l)
      { _M_assign_aux(__l.begin(), __l.end(), random_access_iterator_tag()); }
     
      iterator
      begin() noexcept
      { return iterator(this->_M_impl._M_start._M_p, 0); }
     
      const_iterator
      begin() const noexcept
      { return const_iterator(this->_M_impl._M_start._M_p, 0); }
     
      iterator
      end() noexcept
      { return this->_M_impl._M_finish; }
     
      const_iterator
      end() const noexcept
      { return this->_M_impl._M_finish; }
     
      reverse_iterator
      rbegin() noexcept
      { return reverse_iterator(end()); }
     
      const_reverse_iterator
      rbegin() const noexcept
      { return const_reverse_iterator(end()); }
     
      reverse_iterator
      rend() noexcept
      { return reverse_iterator(begin()); }
     
      const_reverse_iterator
      rend() const noexcept
      { return const_reverse_iterator(begin()); }
      [[__nodiscard__]]
      const_iterator
      cbegin() const noexcept
      { return const_iterator(this->_M_impl._M_start._M_p, 0); }
      [[__nodiscard__]]
      const_iterator
      cend() const noexcept
      { return this->_M_impl._M_finish; }
      [[__nodiscard__]]
      const_reverse_iterator
      crbegin() const noexcept
      { return const_reverse_iterator(end()); }
      [[__nodiscard__]]
      const_reverse_iterator
      crend() const noexcept
      { return const_reverse_iterator(begin()); }
     
      size_type
      size() const noexcept
      { return size_type(end() - begin()); }
     
      size_type
      max_size() const noexcept
      {
 const size_type __isize =
   __gnu_cxx::__numeric_traits<difference_type>::__max
   - int(_S_word_bit) + 1;
 const size_type __asize
   = _Bit_alloc_traits::max_size(_M_get_Bit_allocator());
 return (__asize <= __isize / int(_S_word_bit)
  ? __asize * int(_S_word_bit) : __isize);
      }
     
      size_type
      capacity() const noexcept
      { return size_type(const_iterator(this->_M_impl._M_end_addr(), 0)
    - begin()); }
     
      bool
      empty() const noexcept
      { return begin() == end(); }
     
      reference
      operator[](size_type __n)
      { return begin()[__n]; }
     
      const_reference
      operator[](size_type __n) const
      { return begin()[__n]; }
    protected:
     
      void
      _M_range_check(size_type __n) const
      {
 if (__n >= this->size())
   __throw_out_of_range_fmt(("vector<bool>::_M_range_check: __n " "(which is %zu) >= this->size() " "(which is %zu)"),
       __n, this->size());
      }
    public:
     
      reference
      at(size_type __n)
      {
 _M_range_check(__n);
 return (*this)[__n];
      }
     
      const_reference
      at(size_type __n) const
      {
 _M_range_check(__n);
 return (*this)[__n];
      }
     
      void
      reserve(size_type __n)
      {
 if (__n > max_size())
   __throw_length_error(("vector::reserve"));
 if (capacity() < __n)
   _M_reallocate(__n);
      }
     
      reference
      front()
      { return *begin(); }
     
      const_reference
      front() const
      { return *begin(); }
     
      reference
      back()
      { return *(end() - 1); }
     
      const_reference
      back() const
      { return *(end() - 1); }
     
      void
      push_back(bool __x)
      {
 if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
   *this->_M_impl._M_finish++ = __x;
 else
   _M_insert_aux(end(), __x);
      }
     
      void
      swap(vector& __x) noexcept
      {
 do { if (std::__is_constant_evaluated() && !bool(_Bit_alloc_traits::propagate_on_container_swap::value || _M_get_Bit_allocator() == __x._M_get_Bit_allocator())) __builtin_unreachable(); } while (false);
 this->_M_impl._M_swap_data(__x._M_impl);
 _Bit_alloc_traits::_S_on_swap(_M_get_Bit_allocator(),
          __x._M_get_Bit_allocator());
      }
     
      static void
      swap(reference __x, reference __y) noexcept
      {
 bool __tmp = __x;
 __x = __y;
 __y = __tmp;
      }
     
      iterator
      insert(const_iterator __position, const bool& __x)
      {
 const difference_type __n = __position - begin();
 if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr()
     && __position == end())
   *this->_M_impl._M_finish++ = __x;
 else
   _M_insert_aux(__position._M_const_cast(), __x);
 return begin() + __n;
      }
      __attribute__ ((__deprecated__ ("use '" "insert(position, false)" "' instead")))
      iterator
      insert(const_iterator __position)
      { return this->insert(__position._M_const_cast(), false); }
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>

 iterator
 insert(const_iterator __position,
        _InputIterator __first, _InputIterator __last)
 {
   difference_type __offset = __position - cbegin();
   _M_insert_range(__position._M_const_cast(),
     __first, __last,
     std::__iterator_category(__first));
   return begin() + __offset;
 }
     
      iterator
      insert(const_iterator __position, size_type __n, const bool& __x)
      {
 difference_type __offset = __position - cbegin();
 _M_fill_insert(__position._M_const_cast(), __n, __x);
 return begin() + __offset;
      }
     
      iterator
      insert(const_iterator __p, initializer_list<bool> __l)
      { return this->insert(__p, __l.begin(), __l.end()); }
     
      void
      pop_back()
      { --this->_M_impl._M_finish; }
     
      iterator
      erase(const_iterator __position)
      { return _M_erase(__position._M_const_cast()); }
     
      iterator
      erase(const_iterator __first, const_iterator __last)
      { return _M_erase(__first._M_const_cast(), __last._M_const_cast()); }
     
      void
      resize(size_type __new_size, bool __x = bool())
      {
 if (__new_size < size())
   _M_erase_at_end(begin() + difference_type(__new_size));
 else
   insert(end(), __new_size - size(), __x);
      }
     
      void
      shrink_to_fit()
      { _M_shrink_to_fit(); }
     
      void
      flip() noexcept
      {
 _Bit_type * const __end = this->_M_impl._M_end_addr();
 for (_Bit_type * __p = this->_M_impl._M_start._M_p; __p != __end; ++__p)
   *__p = ~*__p;
      }
     
      void
      clear() noexcept
      { _M_erase_at_end(begin()); }
      template<typename... _Args>
 void
 emplace_back(_Args&&... __args)
 {
   push_back(bool(__args...));
 }
      template<typename... _Args>

 iterator
 emplace(const_iterator __pos, _Args&&... __args)
 { return insert(__pos, bool(__args...)); }
    protected:
     
      iterator
      _M_copy_aligned(const_iterator __first, const_iterator __last,
        iterator __result)
      {
 _Bit_type* __q = std::copy(__first._M_p, __last._M_p, __result._M_p);
 return std::copy(const_iterator(__last._M_p, 0), __last,
    iterator(__q, 0));
      }
     
      void
      _M_initialize(size_type __n)
      {
 if (__n)
   {
     _Bit_pointer __q = this->_M_allocate(__n);
     this->_M_impl._M_end_of_storage = __q + _S_nword(__n);
     iterator __start = iterator(std::__addressof(*__q), 0);
     this->_M_impl._M_start = __start;
     this->_M_impl._M_finish = __start + difference_type(__n);
   }
      }
     
      void
      _M_initialize_value(bool __x) noexcept
      {
 if (_Bit_type* __p = this->_M_impl._M_start._M_p)
   __fill_bvector_n(__p, this->_M_impl._M_end_addr() - __p, __x);
      }
     
      void
      _M_reallocate(size_type __n);
     
      bool
      _M_shrink_to_fit();
      template<typename _InputIterator>

 void
 _M_initialize_range(_InputIterator __first, _InputIterator __last,
       std::input_iterator_tag)
 {
   for (; __first != __last; ++__first)
     push_back(*__first);
 }
      template<typename _ForwardIterator>

 void
 _M_initialize_range(_ForwardIterator __first, _ForwardIterator __last,
       std::forward_iterator_tag)
 {
   const size_type __n = std::distance(__first, __last);
   _M_initialize(__n);
   std::copy(__first, __last, begin());
 }
     
      void
      _M_fill_assign(size_t __n, bool __x)
      {
 if (__n > size())
   {
     _M_initialize_value(__x);
     insert(end(), __n - size(), __x);
   }
 else
   {
     _M_erase_at_end(begin() + __n);
     _M_initialize_value(__x);
   }
      }
      template<typename _InputIterator>

 void
 _M_assign_aux(_InputIterator __first, _InputIterator __last,
        std::input_iterator_tag)
 {
   iterator __cur = begin();
   for (; __first != __last && __cur != end(); ++__cur, (void)++__first)
     *__cur = *__first;
   if (__first == __last)
     _M_erase_at_end(__cur);
   else
     insert(end(), __first, __last);
 }
      template<typename _ForwardIterator>

 void
 _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
        std::forward_iterator_tag)
 {
   const size_type __len = std::distance(__first, __last);
   if (__len < size())
     _M_erase_at_end(std::copy(__first, __last, begin()));
   else
     {
       _ForwardIterator __mid = __first;
       std::advance(__mid, size());
       std::copy(__first, __mid, begin());
       insert(end(), __mid, __last);
     }
 }
     
      void
      _M_fill_insert(iterator __position, size_type __n, bool __x);
      template<typename _InputIterator>

 void
 _M_insert_range(iterator __pos, _InputIterator __first,
   _InputIterator __last, std::input_iterator_tag)
 {
   for (; __first != __last; ++__first)
     {
       __pos = insert(__pos, *__first);
       ++__pos;
     }
 }
      template<typename _ForwardIterator>

 void
 _M_insert_range(iterator __position, _ForwardIterator __first,
   _ForwardIterator __last, std::forward_iterator_tag);
     
      void
      _M_insert_aux(iterator __position, bool __x);
     
      size_type
      _M_check_len(size_type __n, const char* __s) const
      {
 if (max_size() - size() < __n)
   __throw_length_error((__s));
 const size_type __len = size() + std::max(size(), __n);
 return (__len < size() || __len > max_size()) ? max_size() : __len;
      }
     
      void
      _M_erase_at_end(iterator __pos)
      { this->_M_impl._M_finish = __pos; }
     
      iterator
      _M_erase(iterator __pos);
     
      iterator
      _M_erase(iterator __first, iterator __last);
    protected:
      void data() = delete;
    };

 
  inline void
  __fill_bvector(_Bit_type* __v, unsigned int __first, unsigned int __last,
   bool __x) noexcept
  {
    const _Bit_type __fmask = ~0ul << __first;
    const _Bit_type __lmask = ~0ul >> (_S_word_bit - __last);
    const _Bit_type __mask = __fmask & __lmask;
    if (__x)
      *__v |= __mask;
    else
      *__v &= ~__mask;
  }
  __attribute__((__nonnull__))
 
  inline void
  __fill_bvector_n(_Bit_type* __p, size_t __n, bool __x) noexcept
  {
    __builtin_memset(__p, __x ? ~0 : 0, __n * sizeof(_Bit_type));
  }
 
  inline void
  __fill_a1(std::_Bit_iterator __first,
     std::_Bit_iterator __last, const bool& __x)
  {
    if (__first._M_p != __last._M_p)
      {
 _Bit_type* __first_p = __first._M_p;
 if (__first._M_offset != 0)
   __fill_bvector(__first_p++, __first._M_offset, _S_word_bit, __x);
 __fill_bvector_n(__first_p, __last._M_p - __first_p, __x);
 if (__last._M_offset != 0)
   __fill_bvector(__last._M_p, 0, __last._M_offset, __x);
      }
    else if (__first._M_offset != __last._M_offset)
      __fill_bvector(__first._M_p, __first._M_offset, __last._M_offset, __x);
  }
  template<typename _Alloc>
    struct hash<std::vector<bool, _Alloc>>
    : public __hash_base<size_t, std::vector<bool, _Alloc>>
    {
      size_t
      operator()(const std::vector<bool, _Alloc>&) const noexcept;
    };

}
       
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Tp, typename _Up = typename __inv_unwrap<_Tp>::type>
    constexpr _Up&&
    __invfwd(typename remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Up&&>(__t); }
  template<typename _Res, typename _Fn, typename... _Args>
    constexpr _Res
    __invoke_impl(__invoke_other, _Fn&& __f, _Args&&... __args)
    { return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...); }
  template<typename _Res, typename _MemFun, typename _Tp, typename... _Args>
    constexpr _Res
    __invoke_impl(__invoke_memfun_ref, _MemFun&& __f, _Tp&& __t,
    _Args&&... __args)
    { return (__invfwd<_Tp>(__t).*__f)(std::forward<_Args>(__args)...); }
  template<typename _Res, typename _MemFun, typename _Tp, typename... _Args>
    constexpr _Res
    __invoke_impl(__invoke_memfun_deref, _MemFun&& __f, _Tp&& __t,
    _Args&&... __args)
    {
      return ((*std::forward<_Tp>(__t)).*__f)(std::forward<_Args>(__args)...);
    }
  template<typename _Res, typename _MemPtr, typename _Tp>
    constexpr _Res
    __invoke_impl(__invoke_memobj_ref, _MemPtr&& __f, _Tp&& __t)
    { return __invfwd<_Tp>(__t).*__f; }
  template<typename _Res, typename _MemPtr, typename _Tp>
    constexpr _Res
    __invoke_impl(__invoke_memobj_deref, _MemPtr&& __f, _Tp&& __t)
    { return (*std::forward<_Tp>(__t)).*__f; }
  template<typename _Callable, typename... _Args>
    constexpr typename __invoke_result<_Callable, _Args...>::type
    __invoke(_Callable&& __fn, _Args&&... __args)
    noexcept(__is_nothrow_invocable<_Callable, _Args...>::value)
    {
      using __result = __invoke_result<_Callable, _Args...>;
      using __type = typename __result::type;
      using __tag = typename __result::__invoke_type;
      return std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
     std::forward<_Args>(__args)...);
    }
  template<typename _Res, typename _Callable, typename... _Args>
    constexpr __enable_if_t<!is_void<_Res>::value, _Res>
    __invoke_r(_Callable&& __fn, _Args&&... __args)
    {
      using __result = __invoke_result<_Callable, _Args...>;
      using __type = typename __result::type;
      static_assert(!__reference_converts_from_temporary(_Res, __type),
      "INVOKE<R> must not create a dangling reference");
      using __tag = typename __result::__invoke_type;
      return std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
     std::forward<_Args>(__args)...);
    }
  template<typename _Res, typename _Callable, typename... _Args>
    __enable_if_t<is_void<_Res>::value, _Res>
    __invoke_r(_Callable&& __fn, _Args&&... __args)
    {
      using __result = __invoke_result<_Callable, _Args...>;
      using __type = typename __result::type;
      using __tag = typename __result::__invoke_type;
      std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
     std::forward<_Args>(__args)...);
    }

}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Arg, typename _Result>
    struct unary_function
    {
      typedef _Arg argument_type;
      typedef _Result result_type;
    } __attribute__ ((__deprecated__));
  template<typename _Arg1, typename _Arg2, typename _Result>
    struct binary_function
    {
      typedef _Arg1 first_argument_type;
      typedef _Arg2 second_argument_type;
      typedef _Result result_type;
    } __attribute__ ((__deprecated__));
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Tp>
    struct plus : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x + __y; }
    };
  template<typename _Tp>
    struct minus : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x - __y; }
    };
  template<typename _Tp>
    struct multiplies : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x * __y; }
    };
  template<typename _Tp>
    struct divides : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x / __y; }
    };
  template<typename _Tp>
    struct modulus : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x % __y; }
    };
  template<typename _Tp>
    struct negate : public unary_function<_Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x) const
      { return -__x; }
    };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Tp>
    struct equal_to : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x == __y; }
    };
  template<typename _Tp>
    struct not_equal_to : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x != __y; }
    };
  template<typename _Tp>
    struct greater : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x > __y; }
    };
  template<typename _Tp>
    struct less : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x < __y; }
    };
  template<typename _Tp>
    struct greater_equal : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x >= __y; }
    };
  template<typename _Tp>
    struct less_equal : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x <= __y; }
    };
  template<typename _Tp>
    struct greater<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {
 return (unsigned int)__x > (unsigned int)__y;
      }
    };
  template<typename _Tp>
    struct less<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {
 return (unsigned int)__x < (unsigned int)__y;
      }
    };
  template<typename _Tp>
    struct greater_equal<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {
 return (unsigned int)__x >= (unsigned int)__y;
      }
    };
  template<typename _Tp>
    struct less_equal<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      bool
      operator()(_Tp* __x, _Tp* __y) const noexcept
      {
 return (unsigned int)__x <= (unsigned int)__y;
      }
    };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Tp>
    struct logical_and : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x && __y; }
    };
  template<typename _Tp>
    struct logical_or : public binary_function<_Tp, _Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x || __y; }
    };
  template<typename _Tp>
    struct logical_not : public unary_function<_Tp, bool>
    {
     
      bool
      operator()(const _Tp& __x) const
      { return !__x; }
    };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Tp>
    struct bit_and : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x & __y; }
    };
  template<typename _Tp>
    struct bit_or : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x | __y; }
    };
  template<typename _Tp>
    struct bit_xor : public binary_function<_Tp, _Tp, _Tp>
    {
     
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x ^ __y; }
    };
  template<typename _Tp>
    struct bit_not : public unary_function<_Tp, _Tp>
    {
   
      _Tp
      operator()(const _Tp& __x) const
      { return ~__x; }
    };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Predicate>
    class unary_negate
    : public unary_function<typename _Predicate::argument_type, bool>
    {
    protected:
      _Predicate _M_pred;
    public:
     
      explicit
      unary_negate(const _Predicate& __x) : _M_pred(__x) { }
     
      bool
      operator()(const typename _Predicate::argument_type& __x) const
      { return !_M_pred(__x); }
    };
  template<typename _Predicate>
   
   
    inline unary_negate<_Predicate>
    not1(const _Predicate& __pred)
    { return unary_negate<_Predicate>(__pred); }
  template<typename _Predicate>
    class binary_negate
    : public binary_function<typename _Predicate::first_argument_type,
        typename _Predicate::second_argument_type, bool>
    {
    protected:
      _Predicate _M_pred;
    public:
     
      explicit
      binary_negate(const _Predicate& __x) : _M_pred(__x) { }
     
      bool
      operator()(const typename _Predicate::first_argument_type& __x,
   const typename _Predicate::second_argument_type& __y) const
      { return !_M_pred(__x, __y); }
    };
  template<typename _Predicate>
   
   
    inline binary_negate<_Predicate>
    not2(const _Predicate& __pred)
    { return binary_negate<_Predicate>(__pred); }
  template<typename _Arg, typename _Result>
    class pointer_to_unary_function : public unary_function<_Arg, _Result>
    {
    protected:
      _Result (*_M_ptr)(_Arg);
    public:
      pointer_to_unary_function() { }
      explicit
      pointer_to_unary_function(_Result (*__x)(_Arg))
      : _M_ptr(__x) { }
      _Result
      operator()(_Arg __x) const
      { return _M_ptr(__x); }
    } __attribute__ ((__deprecated__));
  template<typename _Arg, typename _Result>
    __attribute__ ((__deprecated__ ("use '" "std::function" "' instead")))
    inline pointer_to_unary_function<_Arg, _Result>
    ptr_fun(_Result (*__x)(_Arg))
    { return pointer_to_unary_function<_Arg, _Result>(__x); }
  template<typename _Arg1, typename _Arg2, typename _Result>
    class pointer_to_binary_function
    : public binary_function<_Arg1, _Arg2, _Result>
    {
    protected:
      _Result (*_M_ptr)(_Arg1, _Arg2);
    public:
      pointer_to_binary_function() { }
      explicit
      pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
      : _M_ptr(__x) { }
      _Result
      operator()(_Arg1 __x, _Arg2 __y) const
      { return _M_ptr(__x, __y); }
    } __attribute__ ((__deprecated__));
  template<typename _Arg1, typename _Arg2, typename _Result>
    __attribute__ ((__deprecated__ ("use '" "std::function" "' instead")))
    inline pointer_to_binary_function<_Arg1, _Arg2, _Result>
    ptr_fun(_Result (*__x)(_Arg1, _Arg2))
    { return pointer_to_binary_function<_Arg1, _Arg2, _Result>(__x); }
  template<typename _Tp>
    struct _Identity
    : public unary_function<_Tp, _Tp>
    {
      _Tp&
      operator()(_Tp& __x) const
      { return __x; }
      const _Tp&
      operator()(const _Tp& __x) const
      { return __x; }
    };
  template<typename _Tp> struct _Identity<const _Tp> : _Identity<_Tp> { };
  template<typename _Pair>
    struct _Select1st
    : public unary_function<_Pair, typename _Pair::first_type>
    {
      typename _Pair::first_type&
      operator()(_Pair& __x) const
      { return __x.first; }
      const typename _Pair::first_type&
      operator()(const _Pair& __x) const
      { return __x.first; }
      template<typename _Pair2>
        typename _Pair2::first_type&
        operator()(_Pair2& __x) const
        { return __x.first; }
      template<typename _Pair2>
        const typename _Pair2::first_type&
        operator()(const _Pair2& __x) const
        { return __x.first; }
    };
  template<typename _Pair>
    struct _Select2nd
    : public unary_function<_Pair, typename _Pair::second_type>
    {
      typename _Pair::second_type&
      operator()(_Pair& __x) const
      { return __x.second; }
      const typename _Pair::second_type&
      operator()(const _Pair& __x) const
      { return __x.second; }
    };
  template<typename _Ret, typename _Tp>
    class mem_fun_t : public unary_function<_Tp*, _Ret>
    {
    public:
      explicit
      mem_fun_t(_Ret (_Tp::*__pf)())
      : _M_f(__pf) { }
      _Ret
      operator()(_Tp* __p) const
      { return (__p->*_M_f)(); }
    private:
      _Ret (_Tp::*_M_f)();
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp>
    class const_mem_fun_t : public unary_function<const _Tp*, _Ret>
    {
    public:
      explicit
      const_mem_fun_t(_Ret (_Tp::*__pf)() const)
      : _M_f(__pf) { }
      _Ret
      operator()(const _Tp* __p) const
      { return (__p->*_M_f)(); }
    private:
      _Ret (_Tp::*_M_f)() const;
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp>
    class mem_fun_ref_t : public unary_function<_Tp, _Ret>
    {
    public:
      explicit
      mem_fun_ref_t(_Ret (_Tp::*__pf)())
      : _M_f(__pf) { }
      _Ret
      operator()(_Tp& __r) const
      { return (__r.*_M_f)(); }
    private:
      _Ret (_Tp::*_M_f)();
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp>
    class const_mem_fun_ref_t : public unary_function<_Tp, _Ret>
    {
    public:
      explicit
      const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const)
      : _M_f(__pf) { }
      _Ret
      operator()(const _Tp& __r) const
      { return (__r.*_M_f)(); }
    private:
      _Ret (_Tp::*_M_f)() const;
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp, typename _Arg>
    class mem_fun1_t : public binary_function<_Tp*, _Arg, _Ret>
    {
    public:
      explicit
      mem_fun1_t(_Ret (_Tp::*__pf)(_Arg))
      : _M_f(__pf) { }
      _Ret
      operator()(_Tp* __p, _Arg __x) const
      { return (__p->*_M_f)(__x); }
    private:
      _Ret (_Tp::*_M_f)(_Arg);
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp, typename _Arg>
    class const_mem_fun1_t : public binary_function<const _Tp*, _Arg, _Ret>
    {
    public:
      explicit
      const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const)
      : _M_f(__pf) { }
      _Ret
      operator()(const _Tp* __p, _Arg __x) const
      { return (__p->*_M_f)(__x); }
    private:
      _Ret (_Tp::*_M_f)(_Arg) const;
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp, typename _Arg>
    class mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret>
    {
    public:
      explicit
      mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg))
      : _M_f(__pf) { }
      _Ret
      operator()(_Tp& __r, _Arg __x) const
      { return (__r.*_M_f)(__x); }
    private:
      _Ret (_Tp::*_M_f)(_Arg);
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp, typename _Arg>
    class const_mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret>
    {
    public:
      explicit
      const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const)
      : _M_f(__pf) { }
      _Ret
      operator()(const _Tp& __r, _Arg __x) const
      { return (__r.*_M_f)(__x); }
    private:
      _Ret (_Tp::*_M_f)(_Arg) const;
    } __attribute__ ((__deprecated__));
  template<typename _Ret, typename _Tp>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline mem_fun_t<_Ret, _Tp>
    mem_fun(_Ret (_Tp::*__f)())
    { return mem_fun_t<_Ret, _Tp>(__f); }
  template<typename _Ret, typename _Tp>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline const_mem_fun_t<_Ret, _Tp>
    mem_fun(_Ret (_Tp::*__f)() const)
    { return const_mem_fun_t<_Ret, _Tp>(__f); }
  template<typename _Ret, typename _Tp>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline mem_fun_ref_t<_Ret, _Tp>
    mem_fun_ref(_Ret (_Tp::*__f)())
    { return mem_fun_ref_t<_Ret, _Tp>(__f); }
  template<typename _Ret, typename _Tp>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline const_mem_fun_ref_t<_Ret, _Tp>
    mem_fun_ref(_Ret (_Tp::*__f)() const)
    { return const_mem_fun_ref_t<_Ret, _Tp>(__f); }
  template<typename _Ret, typename _Tp, typename _Arg>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline mem_fun1_t<_Ret, _Tp, _Arg>
    mem_fun(_Ret (_Tp::*__f)(_Arg))
    { return mem_fun1_t<_Ret, _Tp, _Arg>(__f); }
  template<typename _Ret, typename _Tp, typename _Arg>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline const_mem_fun1_t<_Ret, _Tp, _Arg>
    mem_fun(_Ret (_Tp::*__f)(_Arg) const)
    { return const_mem_fun1_t<_Ret, _Tp, _Arg>(__f); }
  template<typename _Ret, typename _Tp, typename _Arg>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline mem_fun1_ref_t<_Ret, _Tp, _Arg>
    mem_fun_ref(_Ret (_Tp::*__f)(_Arg))
    { return mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f); }
  template<typename _Ret, typename _Tp, typename _Arg>
    __attribute__ ((__deprecated__ ("use '" "std::mem_fn" "' instead")))
    inline const_mem_fun1_ref_t<_Ret, _Tp, _Arg>
    mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const)
    { return const_mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f); }
#pragma GCC diagnostic pop

}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Operation>
    class binder1st
    : public unary_function<typename _Operation::second_argument_type,
       typename _Operation::result_type>
    {
    protected:
      _Operation op;
      typename _Operation::first_argument_type value;
    public:
      binder1st(const _Operation& __x,
  const typename _Operation::first_argument_type& __y)
      : op(__x), value(__y) { }
      typename _Operation::result_type
      operator()(const typename _Operation::second_argument_type& __x) const
      { return op(value, __x); }
      typename _Operation::result_type
      operator()(typename _Operation::second_argument_type& __x) const
      { return op(value, __x); }
    } __attribute__ ((__deprecated__ ("use '" "std::bind" "' instead")));
  template<typename _Operation, typename _Tp>
    __attribute__ ((__deprecated__ ("use '" "std::bind" "' instead")))
    inline binder1st<_Operation>
    bind1st(const _Operation& __fn, const _Tp& __x)
    {
      typedef typename _Operation::first_argument_type _Arg1_type;
      return binder1st<_Operation>(__fn, _Arg1_type(__x));
    }
  template<typename _Operation>
    class binder2nd
    : public unary_function<typename _Operation::first_argument_type,
       typename _Operation::result_type>
    {
    protected:
      _Operation op;
      typename _Operation::second_argument_type value;
    public:
      binder2nd(const _Operation& __x,
  const typename _Operation::second_argument_type& __y)
      : op(__x), value(__y) { }
      typename _Operation::result_type
      operator()(const typename _Operation::first_argument_type& __x) const
      { return op(__x, value); }
      typename _Operation::result_type
      operator()(typename _Operation::first_argument_type& __x) const
      { return op(__x, value); }
    } __attribute__ ((__deprecated__ ("use '" "std::bind" "' instead")));
  template<typename _Operation, typename _Tp>
    __attribute__ ((__deprecated__ ("use '" "std::bind" "' instead")))
    inline binder2nd<_Operation>
    bind2nd(const _Operation& __fn, const _Tp& __x)
    {
      typedef typename _Operation::second_argument_type _Arg2_type;
      return binder2nd<_Operation>(__fn, _Arg2_type(__x));
    }

}
#pragma GCC diagnostic pop
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Res, typename... _ArgTypes>
    struct _Maybe_unary_or_binary_function { };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Res, typename _T1>
    struct _Maybe_unary_or_binary_function<_Res, _T1>
    : std::unary_function<_T1, _Res> { };
  template<typename _Res, typename _T1, typename _T2>
    struct _Maybe_unary_or_binary_function<_Res, _T1, _T2>
    : std::binary_function<_T1, _T2, _Res> { };
#pragma GCC diagnostic pop
  template<typename _Signature>
    struct _Mem_fn_traits;
  template<typename _Res, typename _Class, typename... _ArgTypes>
    struct _Mem_fn_traits_base
    {
      using __result_type = _Res;
      using __maybe_type
 = _Maybe_unary_or_binary_function<_Res, _Class*, _ArgTypes...>;
      using __arity = integral_constant<size_t, sizeof...(_ArgTypes)>;
    };
template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) > : _Mem_fn_traits_base<_Res, _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) > : _Mem_fn_traits_base<_Res, _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) const > : _Mem_fn_traits_base<_Res, const _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) const > : _Mem_fn_traits_base<_Res, const _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) volatile > : _Mem_fn_traits_base<_Res, volatile _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) volatile > : _Mem_fn_traits_base<_Res, volatile _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) const volatile > : _Mem_fn_traits_base<_Res, const volatile _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) const volatile > : _Mem_fn_traits_base<_Res, const volatile _Class, _ArgTypes...> { using __vararg = true_type; };
template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) &> : _Mem_fn_traits_base<_Res, _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) &> : _Mem_fn_traits_base<_Res, _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) const &> : _Mem_fn_traits_base<_Res, const _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) const &> : _Mem_fn_traits_base<_Res, const _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) volatile &> : _Mem_fn_traits_base<_Res, volatile _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) volatile &> : _Mem_fn_traits_base<_Res, volatile _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) const volatile &> : _Mem_fn_traits_base<_Res, const volatile _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) const volatile &> : _Mem_fn_traits_base<_Res, const volatile _Class, _ArgTypes...> { using __vararg = true_type; };
template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) &&> : _Mem_fn_traits_base<_Res, _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) &&> : _Mem_fn_traits_base<_Res, _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) const &&> : _Mem_fn_traits_base<_Res, const _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) const &&> : _Mem_fn_traits_base<_Res, const _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) volatile &&> : _Mem_fn_traits_base<_Res, volatile _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) volatile &&> : _Mem_fn_traits_base<_Res, volatile _Class, _ArgTypes...> { using __vararg = true_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes...) const volatile &&> : _Mem_fn_traits_base<_Res, const volatile _Class, _ArgTypes...> { using __vararg = false_type; }; template<typename _Res, typename _Class, typename... _ArgTypes> struct _Mem_fn_traits<_Res (_Class::*)(_ArgTypes... ...) const volatile &&> : _Mem_fn_traits_base<_Res, const volatile _Class, _ArgTypes...> { using __vararg = true_type; };
  template<typename _Functor, typename = __void_t<>>
    struct _Maybe_get_result_type
    { };
  template<typename _Functor>
    struct _Maybe_get_result_type<_Functor,
      __void_t<typename _Functor::result_type>>
    { typedef typename _Functor::result_type result_type; };
  template<typename _Functor>
    struct _Weak_result_type_impl
    : _Maybe_get_result_type<_Functor>
    { };
  template<typename _Res, typename... _ArgTypes >
    struct _Weak_result_type_impl<_Res(_ArgTypes...) >
    { typedef _Res result_type; };
  template<typename _Res, typename... _ArgTypes >
    struct _Weak_result_type_impl<_Res(_ArgTypes......) >
    { typedef _Res result_type; };
  template<typename _Res, typename... _ArgTypes >
    struct _Weak_result_type_impl<_Res(*)(_ArgTypes...) >
    { typedef _Res result_type; };
  template<typename _Res, typename... _ArgTypes >
    struct
    _Weak_result_type_impl<_Res(*)(_ArgTypes......) >
    { typedef _Res result_type; };
  template<typename _Functor,
    bool = is_member_function_pointer<_Functor>::value>
    struct _Weak_result_type_memfun
    : _Weak_result_type_impl<_Functor>
    { };
  template<typename _MemFunPtr>
    struct _Weak_result_type_memfun<_MemFunPtr, true>
    {
      using result_type = typename _Mem_fn_traits<_MemFunPtr>::__result_type;
    };
  template<typename _Func, typename _Class>
    struct _Weak_result_type_memfun<_Func _Class::*, false>
    { };
  template<typename _Functor>
    struct _Weak_result_type
    : _Weak_result_type_memfun<typename remove_cv<_Functor>::type>
    { };
  template<typename _Tp, typename = __void_t<>>
    struct _Refwrap_base_arg1
    { };
  template<typename _Tp>
    struct _Refwrap_base_arg1<_Tp,
         __void_t<typename _Tp::argument_type>>
    {
      typedef typename _Tp::argument_type argument_type;
    };
  template<typename _Tp, typename = __void_t<>>
    struct _Refwrap_base_arg2
    { };
  template<typename _Tp>
    struct _Refwrap_base_arg2<_Tp,
         __void_t<typename _Tp::first_argument_type,
           typename _Tp::second_argument_type>>
    {
      typedef typename _Tp::first_argument_type first_argument_type;
      typedef typename _Tp::second_argument_type second_argument_type;
    };
  template<typename _Tp>
    struct _Reference_wrapper_base
    : _Weak_result_type<_Tp>, _Refwrap_base_arg1<_Tp>, _Refwrap_base_arg2<_Tp>
    { };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  template<typename _Res, typename _T1 >
    struct _Reference_wrapper_base<_Res(_T1) >
    : unary_function<_T1, _Res>
    { };
  template<typename _Res, typename _T1>
    struct _Reference_wrapper_base<_Res(_T1) const>
    : unary_function<_T1, _Res>
    { };
  template<typename _Res, typename _T1>
    struct _Reference_wrapper_base<_Res(_T1) volatile>
    : unary_function<_T1, _Res>
    { };
  template<typename _Res, typename _T1>
    struct _Reference_wrapper_base<_Res(_T1) const volatile>
    : unary_function<_T1, _Res>
    { };
  template<typename _Res, typename _T1, typename _T2 >
    struct _Reference_wrapper_base<_Res(_T1, _T2) >
    : binary_function<_T1, _T2, _Res>
    { };
  template<typename _Res, typename _T1, typename _T2>
    struct _Reference_wrapper_base<_Res(_T1, _T2) const>
    : binary_function<_T1, _T2, _Res>
    { };
  template<typename _Res, typename _T1, typename _T2>
    struct _Reference_wrapper_base<_Res(_T1, _T2) volatile>
    : binary_function<_T1, _T2, _Res>
    { };
  template<typename _Res, typename _T1, typename _T2>
    struct _Reference_wrapper_base<_Res(_T1, _T2) const volatile>
    : binary_function<_T1, _T2, _Res>
    { };
  template<typename _Res, typename _T1 >
    struct _Reference_wrapper_base<_Res(*)(_T1) >
    : unary_function<_T1, _Res>
    { };
  template<typename _Res, typename _T1, typename _T2 >
    struct _Reference_wrapper_base<_Res(*)(_T1, _T2) >
    : binary_function<_T1, _T2, _Res>
    { };
  template<typename _Tp, bool = is_member_function_pointer<_Tp>::value>
    struct _Reference_wrapper_base_memfun
    : _Reference_wrapper_base<_Tp>
    { };
  template<typename _MemFunPtr>
    struct _Reference_wrapper_base_memfun<_MemFunPtr, true>
    : _Mem_fn_traits<_MemFunPtr>::__maybe_type
    {
      using result_type = typename _Mem_fn_traits<_MemFunPtr>::__result_type;
    };
#pragma GCC diagnostic pop
  template<typename _Tp>
    class reference_wrapper
    : public _Reference_wrapper_base_memfun<typename remove_cv<_Tp>::type>
    {
      _Tp* _M_data;
     
      static _Tp* _S_fun(_Tp& __r) noexcept { return std::__addressof(__r); }
      static void _S_fun(_Tp&&) = delete;
      template<typename _Up, typename _Up2 = __remove_cvref_t<_Up>>
 using __not_same
   = typename enable_if<!is_same<reference_wrapper, _Up2>::value>::type;
    public:
      typedef _Tp type;
      template<typename _Up, typename = __not_same<_Up>, typename
  = decltype(reference_wrapper::_S_fun(std::declval<_Up>()))>

 reference_wrapper(_Up&& __uref)
 noexcept(noexcept(reference_wrapper::_S_fun(std::declval<_Up>())))
 : _M_data(reference_wrapper::_S_fun(std::forward<_Up>(__uref)))
 { }
      reference_wrapper(const reference_wrapper&) = default;
      reference_wrapper&
      operator=(const reference_wrapper&) = default;
     
      operator _Tp&() const noexcept
      { return this->get(); }
     
      _Tp&
      get() const noexcept
      { return *_M_data; }
      template<typename... _Args>

 typename __invoke_result<_Tp&, _Args...>::type
 operator()(_Args&&... __args) const
 noexcept(__is_nothrow_invocable<_Tp&, _Args...>::value)
 {
   return std::__invoke(get(), std::forward<_Args>(__args)...);
 }
    };
  template<typename _Tp>
   
    inline reference_wrapper<_Tp>
    ref(_Tp& __t) noexcept
    { return reference_wrapper<_Tp>(__t); }
  template<typename _Tp>
   
    inline reference_wrapper<const _Tp>
    cref(const _Tp& __t) noexcept
    { return reference_wrapper<const _Tp>(__t); }
  template<typename _Tp>
    void ref(const _Tp&&) = delete;
  template<typename _Tp>
    void cref(const _Tp&&) = delete;
  template<typename _Tp>
   
    inline reference_wrapper<_Tp>
    ref(reference_wrapper<_Tp> __t) noexcept
    { return __t; }
  template<typename _Tp>
   
    inline reference_wrapper<const _Tp>
    cref(reference_wrapper<_Tp> __t) noexcept
    { return { __t.get() }; }

}
       
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Container>
    [[__nodiscard__, __gnu__::__always_inline__]]
    inline auto
    begin(_Container& __cont) -> decltype(__cont.begin())
    { return __cont.begin(); }
  template<typename _Container>
    [[__nodiscard__, __gnu__::__always_inline__]]
    inline auto
    begin(const _Container& __cont) -> decltype(__cont.begin())
    { return __cont.begin(); }
  template<typename _Container>
    [[__nodiscard__, __gnu__::__always_inline__]]
    inline auto
    end(_Container& __cont) -> decltype(__cont.end())
    { return __cont.end(); }
  template<typename _Container>
    [[__nodiscard__, __gnu__::__always_inline__]]
    inline auto
    end(const _Container& __cont) -> decltype(__cont.end())
    { return __cont.end(); }
  template<typename _Tp, size_t _Nm>
    [[__nodiscard__, __gnu__::__always_inline__]]
    inline _Tp*
    begin(_Tp (&__arr)[_Nm]) noexcept
    { return __arr; }
  template<typename _Tp, size_t _Nm>
    [[__nodiscard__, __gnu__::__always_inline__]]
    inline _Tp*
    end(_Tp (&__arr)[_Nm]) noexcept
    { return __arr + _Nm; }

}
namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Tp, typename _Alloc>
   
    void
    vector<_Tp, _Alloc>::
    reserve(size_type __n)
    {
      if (__n > this->max_size())
 __throw_length_error(("vector::reserve"));
      if (this->capacity() < __n)
 {
   const size_type __old_size = size();
   pointer __tmp;
   if (_S_use_relocate())
     {
       __tmp = this->_M_allocate(__n);
       _S_relocate(this->_M_impl._M_start, this->_M_impl._M_finish,
     __tmp, _M_get_Tp_allocator());
     }
   else
     {
       __tmp = _M_allocate_and_copy(__n,
  std::__make_move_if_noexcept_iterator(this->_M_impl._M_start),
  std::__make_move_if_noexcept_iterator(this->_M_impl._M_finish));
       std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       _M_get_Tp_allocator());
     }
   ;
   _M_deallocate(this->_M_impl._M_start,
   this->_M_impl._M_end_of_storage
   - this->_M_impl._M_start);
   this->_M_impl._M_start = __tmp;
   this->_M_impl._M_finish = __tmp + __old_size;
   this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
 }
    }
  template<typename _Tp, typename _Alloc>
    template<typename... _Args>
      void
      vector<_Tp, _Alloc>::
      emplace_back(_Args&&... __args)
      {
 if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
   {
     ;
     _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
         std::forward<_Args>(__args)...);
     ++this->_M_impl._M_finish;
     ;
   }
 else
   _M_realloc_insert(end(), std::forward<_Args>(__args)...);
      }
  template<typename _Tp, typename _Alloc>
   
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::
    insert(const_iterator __position, const value_type& __x)
    {
      const size_type __n = __position - begin();
      if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
 {
   do { if (std::__is_constant_evaluated() && !bool(__position != const_iterator())) __builtin_unreachable(); } while (false);
   if (!(__position != const_iterator()))
     __builtin_unreachable();
   if (__position == end())
     {
       ;
       _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
           __x);
       ++this->_M_impl._M_finish;
       ;
     }
   else
     {
       const auto __pos = begin() + (__position - cbegin());
       _Temporary_value __x_copy(this, __x);
       _M_insert_aux(__pos, std::move(__x_copy._M_val()));
     }
 }
      else
 _M_realloc_insert(begin() + (__position - cbegin()), __x);
      return iterator(this->_M_impl._M_start + __n);
    }
  template<typename _Tp, typename _Alloc>
   
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::
    _M_erase(iterator __position)
    {
      if (__position + 1 != end())
 std::move(__position + 1, end(), __position);
      --this->_M_impl._M_finish;
      _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
      ;
      return __position;
    }
  template<typename _Tp, typename _Alloc>
   
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::
    _M_erase(iterator __first, iterator __last)
    {
      if (__first != __last)
 {
   if (__last != end())
     std::move(__last, end(), __first);
   _M_erase_at_end(__first.base() + (end() - __last));
 }
      return __first;
    }
  template<typename _Tp, typename _Alloc>
   
    vector<_Tp, _Alloc>&
    vector<_Tp, _Alloc>::
    operator=(const vector<_Tp, _Alloc>& __x)
    {
      if (std::__addressof(__x) != this)
 {
   ;
   if (_Alloc_traits::_S_propagate_on_copy_assign())
     {
       if (!_Alloc_traits::_S_always_equal()
           && _M_get_Tp_allocator() != __x._M_get_Tp_allocator())
         {
    this->clear();
    _M_deallocate(this->_M_impl._M_start,
    this->_M_impl._M_end_of_storage
    - this->_M_impl._M_start);
    this->_M_impl._M_start = nullptr;
    this->_M_impl._M_finish = nullptr;
    this->_M_impl._M_end_of_storage = nullptr;
  }
       std::__alloc_on_copy(_M_get_Tp_allocator(),
       __x._M_get_Tp_allocator());
     }
   const size_type __xlen = __x.size();
   if (__xlen > capacity())
     {
       pointer __tmp = _M_allocate_and_copy(__xlen, __x.begin(),
         __x.end());
       std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       _M_get_Tp_allocator());
       _M_deallocate(this->_M_impl._M_start,
       this->_M_impl._M_end_of_storage
       - this->_M_impl._M_start);
       this->_M_impl._M_start = __tmp;
       this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __xlen;
     }
   else if (size() >= __xlen)
     {
       std::_Destroy(std::copy(__x.begin(), __x.end(), begin()),
       end(), _M_get_Tp_allocator());
     }
   else
     {
       std::copy(__x._M_impl._M_start, __x._M_impl._M_start + size(),
   this->_M_impl._M_start);
       std::__uninitialized_copy_a(__x._M_impl._M_start + size(),
       __x._M_impl._M_finish,
       this->_M_impl._M_finish,
       _M_get_Tp_allocator());
     }
   this->_M_impl._M_finish = this->_M_impl._M_start + __xlen;
 }
      return *this;
    }
  template<typename _Tp, typename _Alloc>
   
    void
    vector<_Tp, _Alloc>::
    _M_fill_assign(size_t __n, const value_type& __val)
    {
      if (__n > capacity())
 {
   vector __tmp(__n, __val, _M_get_Tp_allocator());
   __tmp._M_impl._M_swap_data(this->_M_impl);
 }
      else if (__n > size())
 {
   std::fill(begin(), end(), __val);
   const size_type __add = __n - size();
   ;
   this->_M_impl._M_finish =
     std::__uninitialized_fill_n_a(this->_M_impl._M_finish,
       __add, __val, _M_get_Tp_allocator());
   ;
 }
      else
        _M_erase_at_end(std::fill_n(this->_M_impl._M_start, __n, __val));
    }
  template<typename _Tp, typename _Alloc>
    template<typename _InputIterator>
     
      void
      vector<_Tp, _Alloc>::
      _M_assign_aux(_InputIterator __first, _InputIterator __last,
      std::input_iterator_tag)
      {
 pointer __cur(this->_M_impl._M_start);
 for (; __first != __last && __cur != this->_M_impl._M_finish;
      ++__cur, (void)++__first)
   *__cur = *__first;
 if (__first == __last)
   _M_erase_at_end(__cur);
 else
   _M_range_insert(end(), __first, __last,
     std::__iterator_category(__first));
      }
  template<typename _Tp, typename _Alloc>
    template<typename _ForwardIterator>
     
      void
      vector<_Tp, _Alloc>::
      _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
      std::forward_iterator_tag)
      {
 const size_type __len = std::distance(__first, __last);
 if (__len > capacity())
   {
     _S_check_init_len(__len, _M_get_Tp_allocator());
     pointer __tmp(_M_allocate_and_copy(__len, __first, __last));
     std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
     _M_get_Tp_allocator());
     ;
     _M_deallocate(this->_M_impl._M_start,
     this->_M_impl._M_end_of_storage
     - this->_M_impl._M_start);
     this->_M_impl._M_start = __tmp;
     this->_M_impl._M_finish = this->_M_impl._M_start + __len;
     this->_M_impl._M_end_of_storage = this->_M_impl._M_finish;
   }
 else if (size() >= __len)
   _M_erase_at_end(std::copy(__first, __last, this->_M_impl._M_start));
 else
   {
     _ForwardIterator __mid = __first;
     std::advance(__mid, size());
     std::copy(__first, __mid, this->_M_impl._M_start);
     const size_type __attribute__((__unused__)) __n = __len - size();
     ;
     this->_M_impl._M_finish =
       std::__uninitialized_copy_a(__mid, __last,
       this->_M_impl._M_finish,
       _M_get_Tp_allocator());
     ;
   }
      }
  template<typename _Tp, typename _Alloc>
   
    auto
    vector<_Tp, _Alloc>::
    _M_insert_rval(const_iterator __position, value_type&& __v) -> iterator
    {
      const auto __n = __position - cbegin();
      if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
 if (__position == cend())
   {
     ;
     _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
         std::move(__v));
     ++this->_M_impl._M_finish;
     ;
   }
 else
   _M_insert_aux(begin() + __n, std::move(__v));
      else
 _M_realloc_insert(begin() + __n, std::move(__v));
      return iterator(this->_M_impl._M_start + __n);
    }
  template<typename _Tp, typename _Alloc>
    template<typename... _Args>
     
      auto
      vector<_Tp, _Alloc>::
      _M_emplace_aux(const_iterator __position, _Args&&... __args)
      -> iterator
      {
 const auto __n = __position - cbegin();
 if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
   if (__position == cend())
     {
       ;
       _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
           std::forward<_Args>(__args)...);
       ++this->_M_impl._M_finish;
       ;
     }
   else
     {
       _Temporary_value __tmp(this, std::forward<_Args>(__args)...);
       _M_insert_aux(begin() + __n, std::move(__tmp._M_val()));
     }
 else
   _M_realloc_insert(begin() + __n, std::forward<_Args>(__args)...);
 return iterator(this->_M_impl._M_start + __n);
      }
  template<typename _Tp, typename _Alloc>
    template<typename _Arg>
     
      void
      vector<_Tp, _Alloc>::
      _M_insert_aux(iterator __position, _Arg&& __arg)
    {
      ;
      _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
          std::move(*(this->_M_impl._M_finish - 1)));
      ++this->_M_impl._M_finish;
      ;
      std::move_backward(__position.base(), this->_M_impl._M_finish - 2, this->_M_impl._M_finish - 1);
      *__position = std::forward<_Arg>(__arg);
    }
  template<typename _Tp, typename _Alloc>
    template<typename... _Args>
     
      void
      vector<_Tp, _Alloc>::
      _M_realloc_insert(iterator __position, _Args&&... __args)
    {
      const size_type __len =
 _M_check_len(size_type(1), "vector::_M_realloc_insert");
      pointer __old_start = this->_M_impl._M_start;
      pointer __old_finish = this->_M_impl._M_finish;
      const size_type __elems_before = __position - begin();
      pointer __new_start(this->_M_allocate(__len));
      pointer __new_finish(__new_start);
      try
 {
   _Alloc_traits::construct(this->_M_impl,
       __new_start + __elems_before,
       std::forward<_Args>(__args)...);
   __new_finish = pointer();
   if (_S_use_relocate())
     {
       __new_finish = _S_relocate(__old_start, __position.base(),
      __new_start, _M_get_Tp_allocator());
       ++__new_finish;
       __new_finish = _S_relocate(__position.base(), __old_finish,
      __new_finish, _M_get_Tp_allocator());
     }
   else
     {
       __new_finish
  = std::__uninitialized_move_if_noexcept_a
  (__old_start, __position.base(),
   __new_start, _M_get_Tp_allocator());
       ++__new_finish;
       __new_finish
  = std::__uninitialized_move_if_noexcept_a
  (__position.base(), __old_finish,
   __new_finish, _M_get_Tp_allocator());
     }
 }
      catch(...)
 {
   if (!__new_finish)
     _Alloc_traits::destroy(this->_M_impl,
       __new_start + __elems_before);
   else
     std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
   _M_deallocate(__new_start, __len);
   throw;
 }
      if (!_S_use_relocate())
 std::_Destroy(__old_start, __old_finish, _M_get_Tp_allocator());
      ;
      _M_deallocate(__old_start,
      this->_M_impl._M_end_of_storage - __old_start);
      this->_M_impl._M_start = __new_start;
      this->_M_impl._M_finish = __new_finish;
      this->_M_impl._M_end_of_storage = __new_start + __len;
    }
  template<typename _Tp, typename _Alloc>
   
    void
    vector<_Tp, _Alloc>::
    _M_fill_insert(iterator __position, size_type __n, const value_type& __x)
    {
      if (__n != 0)
 {
   if (size_type(this->_M_impl._M_end_of_storage
   - this->_M_impl._M_finish) >= __n)
     {
       _Temporary_value __tmp(this, __x);
       value_type& __x_copy = __tmp._M_val();
       const size_type __elems_after = end() - __position;
       pointer __old_finish(this->_M_impl._M_finish);
       if (__elems_after > __n)
  {
    ;
    std::__uninitialized_move_a(__old_finish - __n,
           __old_finish,
           __old_finish,
           _M_get_Tp_allocator());
    this->_M_impl._M_finish += __n;
    ;
    std::move_backward(__position.base(), __old_finish - __n, __old_finish);
    std::fill(__position.base(), __position.base() + __n,
       __x_copy);
  }
       else
  {
    ;
    this->_M_impl._M_finish =
      std::__uninitialized_fill_n_a(__old_finish,
        __n - __elems_after,
        __x_copy,
        _M_get_Tp_allocator());
    ;
    std::__uninitialized_move_a(__position.base(), __old_finish,
           this->_M_impl._M_finish,
           _M_get_Tp_allocator());
    this->_M_impl._M_finish += __elems_after;
    ;
    std::fill(__position.base(), __old_finish, __x_copy);
  }
     }
   else
     {
       pointer __old_start = this->_M_impl._M_start;
       pointer __old_finish = this->_M_impl._M_finish;
       const pointer __pos = __position.base();
       const size_type __len =
  _M_check_len(__n, "vector::_M_fill_insert");
       const size_type __elems_before = __pos - __old_start;
       pointer __new_start(this->_M_allocate(__len));
       pointer __new_finish(__new_start);
       try
  {
    std::__uninitialized_fill_n_a(__new_start + __elems_before,
      __n, __x,
      _M_get_Tp_allocator());
    __new_finish = pointer();
    __new_finish
      = std::__uninitialized_move_if_noexcept_a
      (__old_start, __pos, __new_start, _M_get_Tp_allocator());
    __new_finish += __n;
    __new_finish
      = std::__uninitialized_move_if_noexcept_a
      (__pos, __old_finish, __new_finish, _M_get_Tp_allocator());
  }
       catch(...)
  {
    if (!__new_finish)
      std::_Destroy(__new_start + __elems_before,
      __new_start + __elems_before + __n,
      _M_get_Tp_allocator());
    else
      std::_Destroy(__new_start, __new_finish,
      _M_get_Tp_allocator());
    _M_deallocate(__new_start, __len);
    throw;
  }
       std::_Destroy(__old_start, __old_finish, _M_get_Tp_allocator());
       ;
       _M_deallocate(__old_start,
       this->_M_impl._M_end_of_storage - __old_start);
       this->_M_impl._M_start = __new_start;
       this->_M_impl._M_finish = __new_finish;
       this->_M_impl._M_end_of_storage = __new_start + __len;
     }
 }
    }
  template<typename _Tp, typename _Alloc>
   
    void
    vector<_Tp, _Alloc>::
    _M_default_append(size_type __n)
    {
      if (__n != 0)
 {
   const size_type __size = size();
   size_type __navail = size_type(this->_M_impl._M_end_of_storage
      - this->_M_impl._M_finish);
   if (__size > max_size() || __navail > max_size() - __size)
     __builtin_unreachable();
   if (__navail >= __n)
     {
       ;
       this->_M_impl._M_finish =
  std::__uninitialized_default_n_a(this->_M_impl._M_finish,
       __n, _M_get_Tp_allocator());
       ;
     }
   else
     {
       pointer __old_start = this->_M_impl._M_start;
       pointer __old_finish = this->_M_impl._M_finish;
       const size_type __len =
  _M_check_len(__n, "vector::_M_default_append");
       pointer __new_start(this->_M_allocate(__len));
       if (_S_use_relocate())
  {
    try
      {
        std::__uninitialized_default_n_a(__new_start + __size,
         __n, _M_get_Tp_allocator());
      }
    catch(...)
      {
        _M_deallocate(__new_start, __len);
        throw;
      }
    _S_relocate(__old_start, __old_finish,
         __new_start, _M_get_Tp_allocator());
  }
       else
  {
    pointer __destroy_from = pointer();
    try
      {
        std::__uninitialized_default_n_a(__new_start + __size,
         __n, _M_get_Tp_allocator());
        __destroy_from = __new_start + __size;
        std::__uninitialized_move_if_noexcept_a(
         __old_start, __old_finish,
         __new_start, _M_get_Tp_allocator());
      }
    catch(...)
      {
        if (__destroy_from)
   std::_Destroy(__destroy_from, __destroy_from + __n,
          _M_get_Tp_allocator());
        _M_deallocate(__new_start, __len);
        throw;
      }
    std::_Destroy(__old_start, __old_finish,
    _M_get_Tp_allocator());
  }
       ;
       _M_deallocate(__old_start,
       this->_M_impl._M_end_of_storage - __old_start);
       this->_M_impl._M_start = __new_start;
       this->_M_impl._M_finish = __new_start + __size + __n;
       this->_M_impl._M_end_of_storage = __new_start + __len;
     }
 }
    }
  template<typename _Tp, typename _Alloc>
   
    bool
    vector<_Tp, _Alloc>::
    _M_shrink_to_fit()
    {
      if (capacity() == size())
 return false;
      ;
      return std::__shrink_to_fit_aux<vector>::_S_do_it(*this);
    }
  template<typename _Tp, typename _Alloc>
    template<typename _InputIterator>
     
      void
      vector<_Tp, _Alloc>::
      _M_range_insert(iterator __pos, _InputIterator __first,
        _InputIterator __last, std::input_iterator_tag)
      {
 if (__pos == end())
   {
     for (; __first != __last; ++__first)
       insert(end(), *__first);
   }
 else if (__first != __last)
   {
     vector __tmp(__first, __last, _M_get_Tp_allocator());
     insert(__pos,
     std::make_move_iterator(__tmp.begin()),
     std::make_move_iterator(__tmp.end()));
   }
      }
  template<typename _Tp, typename _Alloc>
    template<typename _ForwardIterator>
     
      void
      vector<_Tp, _Alloc>::
      _M_range_insert(iterator __position, _ForwardIterator __first,
        _ForwardIterator __last, std::forward_iterator_tag)
      {
 if (__first != __last)
   {
     const size_type __n = std::distance(__first, __last);
     if (size_type(this->_M_impl._M_end_of_storage
     - this->_M_impl._M_finish) >= __n)
       {
  const size_type __elems_after = end() - __position;
  pointer __old_finish(this->_M_impl._M_finish);
  if (__elems_after > __n)
    {
      ;
      std::__uninitialized_move_a(this->_M_impl._M_finish - __n,
      this->_M_impl._M_finish,
      this->_M_impl._M_finish,
      _M_get_Tp_allocator());
      this->_M_impl._M_finish += __n;
      ;
      std::move_backward(__position.base(), __old_finish - __n, __old_finish);
      std::copy(__first, __last, __position);
    }
  else
    {
      _ForwardIterator __mid = __first;
      std::advance(__mid, __elems_after);
      ;
      std::__uninitialized_copy_a(__mid, __last,
      this->_M_impl._M_finish,
      _M_get_Tp_allocator());
      this->_M_impl._M_finish += __n - __elems_after;
      ;
      std::__uninitialized_move_a(__position.base(),
      __old_finish,
      this->_M_impl._M_finish,
      _M_get_Tp_allocator());
      this->_M_impl._M_finish += __elems_after;
      ;
      std::copy(__first, __mid, __position);
    }
       }
     else
       {
  pointer __old_start = this->_M_impl._M_start;
  pointer __old_finish = this->_M_impl._M_finish;
  const size_type __len =
    _M_check_len(__n, "vector::_M_range_insert");
  pointer __new_start(this->_M_allocate(__len));
  pointer __new_finish(__new_start);
  try
    {
      __new_finish
        = std::__uninitialized_move_if_noexcept_a
        (__old_start, __position.base(),
         __new_start, _M_get_Tp_allocator());
      __new_finish
        = std::__uninitialized_copy_a(__first, __last,
          __new_finish,
          _M_get_Tp_allocator());
      __new_finish
        = std::__uninitialized_move_if_noexcept_a
        (__position.base(), __old_finish,
         __new_finish, _M_get_Tp_allocator());
    }
  catch(...)
    {
      std::_Destroy(__new_start, __new_finish,
      _M_get_Tp_allocator());
      _M_deallocate(__new_start, __len);
      throw;
    }
  std::_Destroy(__old_start, __old_finish,
         _M_get_Tp_allocator());
  ;
  _M_deallocate(__old_start,
         this->_M_impl._M_end_of_storage - __old_start);
  this->_M_impl._M_start = __new_start;
  this->_M_impl._M_finish = __new_finish;
  this->_M_impl._M_end_of_storage = __new_start + __len;
       }
   }
      }
  template<typename _Alloc>
   
    void
    vector<bool, _Alloc>::
    _M_reallocate(size_type __n)
    {
      _Bit_pointer __q = this->_M_allocate(__n);
      iterator __start(std::__addressof(*__q), 0);
      iterator __finish(_M_copy_aligned(begin(), end(), __start));
      this->_M_deallocate();
      this->_M_impl._M_start = __start;
      this->_M_impl._M_finish = __finish;
      this->_M_impl._M_end_of_storage = __q + _S_nword(__n);
    }
  template<typename _Alloc>
   
    void
    vector<bool, _Alloc>::
    _M_fill_insert(iterator __position, size_type __n, bool __x)
    {
      if (__n == 0)
 return;
      if (capacity() - size() >= __n)
 {
   std::copy_backward(__position, end(),
        this->_M_impl._M_finish + difference_type(__n));
   std::fill(__position, __position + difference_type(__n), __x);
   this->_M_impl._M_finish += difference_type(__n);
 }
      else
 {
   const size_type __len =
     _M_check_len(__n, "vector<bool>::_M_fill_insert");
   _Bit_pointer __q = this->_M_allocate(__len);
   iterator __start(std::__addressof(*__q), 0);
   iterator __i = _M_copy_aligned(begin(), __position, __start);
   std::fill(__i, __i + difference_type(__n), __x);
   iterator __finish = std::copy(__position, end(),
     __i + difference_type(__n));
   this->_M_deallocate();
   this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
   this->_M_impl._M_start = __start;
   this->_M_impl._M_finish = __finish;
 }
    }
  template<typename _Alloc>
    template<typename _ForwardIterator>
     
      void
      vector<bool, _Alloc>::
      _M_insert_range(iterator __position, _ForwardIterator __first,
        _ForwardIterator __last, std::forward_iterator_tag)
      {
 if (__first != __last)
   {
     size_type __n = std::distance(__first, __last);
     if (capacity() - size() >= __n)
       {
  std::copy_backward(__position, end(),
       this->_M_impl._M_finish
       + difference_type(__n));
  std::copy(__first, __last, __position);
  this->_M_impl._M_finish += difference_type(__n);
       }
     else
       {
  const size_type __len =
    _M_check_len(__n, "vector<bool>::_M_insert_range");
  const iterator __begin = begin(), __end = end();
  _Bit_pointer __q = this->_M_allocate(__len);
  iterator __start(std::__addressof(*__q), 0);
  iterator __i = _M_copy_aligned(__begin, __position, __start);
  __i = std::copy(__first, __last, __i);
  iterator __finish = std::copy(__position, __end, __i);
  this->_M_deallocate();
  this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
  this->_M_impl._M_start = __start;
  this->_M_impl._M_finish = __finish;
       }
   }
      }
  template<typename _Alloc>
   
    void
    vector<bool, _Alloc>::
    _M_insert_aux(iterator __position, bool __x)
    {
      if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
 {
   std::copy_backward(__position, this->_M_impl._M_finish,
        this->_M_impl._M_finish + 1);
   *__position = __x;
   ++this->_M_impl._M_finish;
 }
      else
 {
   const size_type __len =
     _M_check_len(size_type(1), "vector<bool>::_M_insert_aux");
   _Bit_pointer __q = this->_M_allocate(__len);
   iterator __start(std::__addressof(*__q), 0);
   iterator __i = _M_copy_aligned(begin(), __position, __start);
   *__i++ = __x;
   iterator __finish = std::copy(__position, end(), __i);
   this->_M_deallocate();
   this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
   this->_M_impl._M_start = __start;
   this->_M_impl._M_finish = __finish;
 }
    }
  template<typename _Alloc>
   
    typename vector<bool, _Alloc>::iterator
    vector<bool, _Alloc>::
    _M_erase(iterator __position)
    {
      if (__position + 1 != end())
        std::copy(__position + 1, end(), __position);
      --this->_M_impl._M_finish;
      return __position;
    }
  template<typename _Alloc>
   
    typename vector<bool, _Alloc>::iterator
    vector<bool, _Alloc>::
    _M_erase(iterator __first, iterator __last)
    {
      if (__first != __last)
 _M_erase_at_end(std::copy(__last, end(), __first));
      return __first;
    }
  template<typename _Alloc>
   
    bool
    vector<bool, _Alloc>::
    _M_shrink_to_fit()
    {
      if (capacity() - size() < int(_S_word_bit))
 return false;
      try
 {
   if (size_type __n = size())
     _M_reallocate(__n);
   else
     {
       this->_M_deallocate();
       this->_M_impl._M_reset();
     }
   return true;
 }
      catch(...)
 { return false; }
    }


}
namespace std __attribute__ ((__visibility__ ("default")))
{

  template<typename _Alloc>
    size_t
    hash<std::vector<bool, _Alloc>>::
    operator()(const std::vector<bool, _Alloc>& __b) const noexcept
    {
      size_t __hash = 0;
      const size_t __words = __b.size() / _S_word_bit;
      if (__words)
 {
   const size_t __clength = __words * sizeof(_Bit_type);
   __hash = std::_Hash_impl::hash(__b._M_impl._M_start._M_p, __clength);
 }
      const size_t __extrabits = __b.size() % _S_word_bit;
      if (__extrabits)
 {
   _Bit_type __hiword = *__b._M_impl._M_finish._M_p;
   __hiword &= ~((~static_cast<_Bit_type>(0)) << __extrabits);
   const size_t __clength
     = (__extrabits + 8 - 1) / 8;
   if (__words)
     __hash = std::_Hash_impl::hash(&__hiword, __clength, __hash);
   else
     __hash = std::_Hash_impl::hash(&__hiword, __clength);
 }
      return __hash;
    }

}
namespace hwy {
 int64_t SupportedTargets();
 void DisableTargets(int64_t disabled_targets);
 void SetSupportedTargetsForTest(int64_t targets);
inline __attribute__((always_inline)) std::vector<int64_t> SupportedAndGeneratedTargets() {
  std::vector<int64_t> ret;
  for (int64_t targets = SupportedTargets() & (1LL << 61); targets != 0;
       targets = targets & (targets - 1)) {
    int64_t current_target = targets & ~(targets - 1);
    ret.push_back(current_target);
  }
  return ret;
}
static inline __attribute__((unused)) const char* TargetName(int64_t target) {
  switch (target) {
    case (1LL << 14):
      return "SSE2";
    case (1LL << 12):
      return "SSSE3";
    case (1LL << 11):
      return "SSE4";
    case (1LL << 9):
      return "AVX2";
    case (1LL << 8):
      return "AVX3";
    case (1LL << 7):
      return "AVX3_DL";
    case (1LL << 6):
      return "AVX3_ZEN4";
    case (1LL << 61):
      return "EMU128";
    case (1LL << 62):
      return "SCALAR";
    default:
      return "Unknown";
  }
}
struct ChosenTarget {
 public:
  void Update(int64_t targets) {
    StoreMask(((((targets) >> (14 + 1 - 15)) & ((1LL << 15) - 1)) << 1) | (1LL << (15 + 1)));
  }
  void DeInit() { StoreMask(1); }
  bool IsInitialized() const { return LoadMask() != 1; }
  size_t inline __attribute__((always_inline)) GetIndex() const {
    return hwy::Num0BitsBelowLS1Bit_Nonzero64(
        static_cast<uint64_t>(LoadMask() & ((((((1LL << 61)) >> (14 + 1 - 15)) & ((1LL << 15) - 1)) << 1) | (1LL << (15 + 1)) | 1LL)));
  }
 private:
  int64_t LoadMask() const { return mask_.load(); }
  void StoreMask(int64_t mask) { mask_.store(mask); }
  std::atomic<int64_t> mask_{1};
};
 ChosenTarget& GetChosenTarget();
}
namespace hwy {
template <typename RetType, typename... Args>
struct FunctionCache {
 public:
  typedef RetType(FunctionType)(Args...);
  template <FunctionType* const table[]>
  static RetType ChooseAndCall(Args... args) {
    ChosenTarget& chosen_target = GetChosenTarget();
    chosen_target.Update(SupportedTargets());
    return (table[chosen_target.GetIndex()])(args...);
  }
};
template <typename RetType, typename... Args>
FunctionCache<RetType, Args...> DeduceFunctionCache(RetType (*)(Args...)) {
  return FunctionCache<RetType, Args...>();
}
}
       
extern "C" {
typedef long double float_t;
typedef long double double_t;
enum
  {
    FP_INT_UPWARD =
      0,
    FP_INT_DOWNWARD =
      1,
    FP_INT_TOWARDZERO =
      2,
    FP_INT_TONEARESTFROMZERO =
      3,
    FP_INT_TONEAREST =
      4,
  };
extern int __fpclassify (double __value) noexcept (true)
     __attribute__ ((__const__));
extern int __signbit (double __value) noexcept (true)
     __attribute__ ((__const__));
extern int __isinf (double __value) noexcept (true)
  __attribute__ ((__const__));
extern int __finite (double __value) noexcept (true)
  __attribute__ ((__const__));
extern int __isnan (double __value) noexcept (true)
  __attribute__ ((__const__));
extern int __iseqsig (double __x, double __y) noexcept (true);
extern int __issignaling (double __value) noexcept (true)
     __attribute__ ((__const__));
 extern double acos (double __x) noexcept (true); extern double __acos (double __x) noexcept (true);
 extern double asin (double __x) noexcept (true); extern double __asin (double __x) noexcept (true);
 extern double atan (double __x) noexcept (true); extern double __atan (double __x) noexcept (true);
 extern double atan2 (double __y, double __x) noexcept (true); extern double __atan2 (double __y, double __x) noexcept (true);
 extern double cos (double __x) noexcept (true); extern double __cos (double __x) noexcept (true);
 extern double sin (double __x) noexcept (true); extern double __sin (double __x) noexcept (true);
 extern double tan (double __x) noexcept (true); extern double __tan (double __x) noexcept (true);
 extern double cosh (double __x) noexcept (true); extern double __cosh (double __x) noexcept (true);
 extern double sinh (double __x) noexcept (true); extern double __sinh (double __x) noexcept (true);
 extern double tanh (double __x) noexcept (true); extern double __tanh (double __x) noexcept (true);
 extern void sincos (double __x, double *__sinx, double *__cosx) noexcept (true); extern void __sincos (double __x, double *__sinx, double *__cosx) noexcept (true);
 extern double acosh (double __x) noexcept (true); extern double __acosh (double __x) noexcept (true);
 extern double asinh (double __x) noexcept (true); extern double __asinh (double __x) noexcept (true);
 extern double atanh (double __x) noexcept (true); extern double __atanh (double __x) noexcept (true);
 extern double exp (double __x) noexcept (true); extern double __exp (double __x) noexcept (true);
extern double frexp (double __x, int *__exponent) noexcept (true); extern double __frexp (double __x, int *__exponent) noexcept (true);
extern double ldexp (double __x, int __exponent) noexcept (true); extern double __ldexp (double __x, int __exponent) noexcept (true);
 extern double log (double __x) noexcept (true); extern double __log (double __x) noexcept (true);
 extern double log10 (double __x) noexcept (true); extern double __log10 (double __x) noexcept (true);
extern double modf (double __x, double *__iptr) noexcept (true); extern double __modf (double __x, double *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern double exp10 (double __x) noexcept (true); extern double __exp10 (double __x) noexcept (true);
 extern double expm1 (double __x) noexcept (true); extern double __expm1 (double __x) noexcept (true);
 extern double log1p (double __x) noexcept (true); extern double __log1p (double __x) noexcept (true);
extern double logb (double __x) noexcept (true); extern double __logb (double __x) noexcept (true);
 extern double exp2 (double __x) noexcept (true); extern double __exp2 (double __x) noexcept (true);
 extern double log2 (double __x) noexcept (true); extern double __log2 (double __x) noexcept (true);
 extern double pow (double __x, double __y) noexcept (true); extern double __pow (double __x, double __y) noexcept (true);
extern double sqrt (double __x) noexcept (true); extern double __sqrt (double __x) noexcept (true);
 extern double hypot (double __x, double __y) noexcept (true); extern double __hypot (double __x, double __y) noexcept (true);
 extern double cbrt (double __x) noexcept (true); extern double __cbrt (double __x) noexcept (true);
extern double ceil (double __x) noexcept (true) __attribute__ ((__const__)); extern double __ceil (double __x) noexcept (true) __attribute__ ((__const__));
extern double fabs (double __x) noexcept (true) __attribute__ ((__const__)); extern double __fabs (double __x) noexcept (true) __attribute__ ((__const__));
extern double floor (double __x) noexcept (true) __attribute__ ((__const__)); extern double __floor (double __x) noexcept (true) __attribute__ ((__const__));
extern double fmod (double __x, double __y) noexcept (true); extern double __fmod (double __x, double __y) noexcept (true);
extern int finite (double __value) noexcept (true)
  __attribute__ ((__const__));
extern double drem (double __x, double __y) noexcept (true); extern double __drem (double __x, double __y) noexcept (true);
extern double significand (double __x) noexcept (true); extern double __significand (double __x) noexcept (true);
extern double copysign (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double nan (const char *__tagb) noexcept (true); extern double __nan (const char *__tagb) noexcept (true);
extern double j0 (double) noexcept (true); extern double __j0 (double) noexcept (true);
extern double j1 (double) noexcept (true); extern double __j1 (double) noexcept (true);
extern double jn (int, double) noexcept (true); extern double __jn (int, double) noexcept (true);
extern double y0 (double) noexcept (true); extern double __y0 (double) noexcept (true);
extern double y1 (double) noexcept (true); extern double __y1 (double) noexcept (true);
extern double yn (int, double) noexcept (true); extern double __yn (int, double) noexcept (true);
 extern double erf (double) noexcept (true); extern double __erf (double) noexcept (true);
 extern double erfc (double) noexcept (true); extern double __erfc (double) noexcept (true);
extern double lgamma (double) noexcept (true); extern double __lgamma (double) noexcept (true);
extern double tgamma (double) noexcept (true); extern double __tgamma (double) noexcept (true);
extern double gamma (double) noexcept (true); extern double __gamma (double) noexcept (true);
extern double lgamma_r (double, int *__signgamp) noexcept (true); extern double __lgamma_r (double, int *__signgamp) noexcept (true);
extern double rint (double __x) noexcept (true); extern double __rint (double __x) noexcept (true);
extern double nextafter (double __x, double __y) noexcept (true); extern double __nextafter (double __x, double __y) noexcept (true);
extern double nexttoward (double __x, long double __y) noexcept (true); extern double __nexttoward (double __x, long double __y) noexcept (true);
extern double nextdown (double __x) noexcept (true); extern double __nextdown (double __x) noexcept (true);
extern double nextup (double __x) noexcept (true); extern double __nextup (double __x) noexcept (true);
extern double remainder (double __x, double __y) noexcept (true); extern double __remainder (double __x, double __y) noexcept (true);
extern double scalbn (double __x, int __n) noexcept (true); extern double __scalbn (double __x, int __n) noexcept (true);
extern int ilogb (double __x) noexcept (true); extern int __ilogb (double __x) noexcept (true);
extern long int llogb (double __x) noexcept (true); extern long int __llogb (double __x) noexcept (true);
extern double scalbln (double __x, long int __n) noexcept (true); extern double __scalbln (double __x, long int __n) noexcept (true);
extern double nearbyint (double __x) noexcept (true); extern double __nearbyint (double __x) noexcept (true);
extern double round (double __x) noexcept (true) __attribute__ ((__const__)); extern double __round (double __x) noexcept (true) __attribute__ ((__const__));
extern double trunc (double __x) noexcept (true) __attribute__ ((__const__)); extern double __trunc (double __x) noexcept (true) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) noexcept (true); extern double __remquo (double __x, double __y, int *__quo) noexcept (true);
extern long int lrint (double __x) noexcept (true); extern long int __lrint (double __x) noexcept (true);
__extension__
extern long long int llrint (double __x) noexcept (true); extern long long int __llrint (double __x) noexcept (true);
extern long int lround (double __x) noexcept (true); extern long int __lround (double __x) noexcept (true);
__extension__
extern long long int llround (double __x) noexcept (true); extern long long int __llround (double __x) noexcept (true);
extern double fdim (double __x, double __y) noexcept (true); extern double __fdim (double __x, double __y) noexcept (true);
extern double fmax (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fmin (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) noexcept (true); extern double __fma (double __x, double __y, double __z) noexcept (true);
extern double roundeven (double __x) noexcept (true) __attribute__ ((__const__)); extern double __roundeven (double __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfp (double __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfp (double __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfp (double __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfp (double __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpx (double __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpx (double __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpx (double __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpx (double __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalize (double *__cx, const double *__x) noexcept (true);
extern double fmaxmag (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmaxmag (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fminmag (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fminmag (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fmaximum (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmaximum (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fminimum (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fminimum (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fmaximum_num (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmaximum_num (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fminimum_num (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fminimum_num (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fmaximum_mag (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmaximum_mag (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fminimum_mag (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fminimum_mag (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fmaximum_mag_num (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fmaximum_mag_num (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern double fminimum_mag_num (double __x, double __y) noexcept (true) __attribute__ ((__const__)); extern double __fminimum_mag_num (double __x, double __y) noexcept (true) __attribute__ ((__const__));
extern int totalorder (const double *__x, const double *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermag (const double *__x, const double *__y) noexcept (true)
     __attribute__ ((__pure__));
extern double getpayload (const double *__x) noexcept (true); extern double __getpayload (const double *__x) noexcept (true);
extern int setpayload (double *__x, double __payload) noexcept (true);
extern int setpayloadsig (double *__x, double __payload) noexcept (true);
extern double scalb (double __x, double __n) noexcept (true); extern double __scalb (double __x, double __n) noexcept (true);
extern int __fpclassifyf (float __value) noexcept (true)
     __attribute__ ((__const__));
extern int __signbitf (float __value) noexcept (true)
     __attribute__ ((__const__));
extern int __isinff (float __value) noexcept (true)
  __attribute__ ((__const__));
extern int __finitef (float __value) noexcept (true)
  __attribute__ ((__const__));
extern int __isnanf (float __value) noexcept (true)
  __attribute__ ((__const__));
extern int __iseqsigf (float __x, float __y) noexcept (true);
extern int __issignalingf (float __value) noexcept (true)
     __attribute__ ((__const__));
 extern float acosf (float __x) noexcept (true); extern float __acosf (float __x) noexcept (true);
 extern float asinf (float __x) noexcept (true); extern float __asinf (float __x) noexcept (true);
 extern float atanf (float __x) noexcept (true); extern float __atanf (float __x) noexcept (true);
 extern float atan2f (float __y, float __x) noexcept (true); extern float __atan2f (float __y, float __x) noexcept (true);
 extern float cosf (float __x) noexcept (true); extern float __cosf (float __x) noexcept (true);
 extern float sinf (float __x) noexcept (true); extern float __sinf (float __x) noexcept (true);
 extern float tanf (float __x) noexcept (true); extern float __tanf (float __x) noexcept (true);
 extern float coshf (float __x) noexcept (true); extern float __coshf (float __x) noexcept (true);
 extern float sinhf (float __x) noexcept (true); extern float __sinhf (float __x) noexcept (true);
 extern float tanhf (float __x) noexcept (true); extern float __tanhf (float __x) noexcept (true);
 extern void sincosf (float __x, float *__sinx, float *__cosx) noexcept (true); extern void __sincosf (float __x, float *__sinx, float *__cosx) noexcept (true);
 extern float acoshf (float __x) noexcept (true); extern float __acoshf (float __x) noexcept (true);
 extern float asinhf (float __x) noexcept (true); extern float __asinhf (float __x) noexcept (true);
 extern float atanhf (float __x) noexcept (true); extern float __atanhf (float __x) noexcept (true);
 extern float expf (float __x) noexcept (true); extern float __expf (float __x) noexcept (true);
extern float frexpf (float __x, int *__exponent) noexcept (true); extern float __frexpf (float __x, int *__exponent) noexcept (true);
extern float ldexpf (float __x, int __exponent) noexcept (true); extern float __ldexpf (float __x, int __exponent) noexcept (true);
 extern float logf (float __x) noexcept (true); extern float __logf (float __x) noexcept (true);
 extern float log10f (float __x) noexcept (true); extern float __log10f (float __x) noexcept (true);
extern float modff (float __x, float *__iptr) noexcept (true); extern float __modff (float __x, float *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern float exp10f (float __x) noexcept (true); extern float __exp10f (float __x) noexcept (true);
 extern float expm1f (float __x) noexcept (true); extern float __expm1f (float __x) noexcept (true);
 extern float log1pf (float __x) noexcept (true); extern float __log1pf (float __x) noexcept (true);
extern float logbf (float __x) noexcept (true); extern float __logbf (float __x) noexcept (true);
 extern float exp2f (float __x) noexcept (true); extern float __exp2f (float __x) noexcept (true);
 extern float log2f (float __x) noexcept (true); extern float __log2f (float __x) noexcept (true);
 extern float powf (float __x, float __y) noexcept (true); extern float __powf (float __x, float __y) noexcept (true);
extern float sqrtf (float __x) noexcept (true); extern float __sqrtf (float __x) noexcept (true);
 extern float hypotf (float __x, float __y) noexcept (true); extern float __hypotf (float __x, float __y) noexcept (true);
 extern float cbrtf (float __x) noexcept (true); extern float __cbrtf (float __x) noexcept (true);
extern float ceilf (float __x) noexcept (true) __attribute__ ((__const__)); extern float __ceilf (float __x) noexcept (true) __attribute__ ((__const__));
extern float fabsf (float __x) noexcept (true) __attribute__ ((__const__)); extern float __fabsf (float __x) noexcept (true) __attribute__ ((__const__));
extern float floorf (float __x) noexcept (true) __attribute__ ((__const__)); extern float __floorf (float __x) noexcept (true) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) noexcept (true); extern float __fmodf (float __x, float __y) noexcept (true);
extern int isinff (float __value) noexcept (true)
  __attribute__ ((__const__));
extern int finitef (float __value) noexcept (true)
  __attribute__ ((__const__));
extern float dremf (float __x, float __y) noexcept (true); extern float __dremf (float __x, float __y) noexcept (true);
extern float significandf (float __x) noexcept (true); extern float __significandf (float __x) noexcept (true);
extern float copysignf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float nanf (const char *__tagb) noexcept (true); extern float __nanf (const char *__tagb) noexcept (true);
extern int isnanf (float __value) noexcept (true)
  __attribute__ ((__const__));
extern float j0f (float) noexcept (true); extern float __j0f (float) noexcept (true);
extern float j1f (float) noexcept (true); extern float __j1f (float) noexcept (true);
extern float jnf (int, float) noexcept (true); extern float __jnf (int, float) noexcept (true);
extern float y0f (float) noexcept (true); extern float __y0f (float) noexcept (true);
extern float y1f (float) noexcept (true); extern float __y1f (float) noexcept (true);
extern float ynf (int, float) noexcept (true); extern float __ynf (int, float) noexcept (true);
 extern float erff (float) noexcept (true); extern float __erff (float) noexcept (true);
 extern float erfcf (float) noexcept (true); extern float __erfcf (float) noexcept (true);
extern float lgammaf (float) noexcept (true); extern float __lgammaf (float) noexcept (true);
extern float tgammaf (float) noexcept (true); extern float __tgammaf (float) noexcept (true);
extern float gammaf (float) noexcept (true); extern float __gammaf (float) noexcept (true);
extern float lgammaf_r (float, int *__signgamp) noexcept (true); extern float __lgammaf_r (float, int *__signgamp) noexcept (true);
extern float rintf (float __x) noexcept (true); extern float __rintf (float __x) noexcept (true);
extern float nextafterf (float __x, float __y) noexcept (true); extern float __nextafterf (float __x, float __y) noexcept (true);
extern float nexttowardf (float __x, long double __y) noexcept (true); extern float __nexttowardf (float __x, long double __y) noexcept (true);
extern float nextdownf (float __x) noexcept (true); extern float __nextdownf (float __x) noexcept (true);
extern float nextupf (float __x) noexcept (true); extern float __nextupf (float __x) noexcept (true);
extern float remainderf (float __x, float __y) noexcept (true); extern float __remainderf (float __x, float __y) noexcept (true);
extern float scalbnf (float __x, int __n) noexcept (true); extern float __scalbnf (float __x, int __n) noexcept (true);
extern int ilogbf (float __x) noexcept (true); extern int __ilogbf (float __x) noexcept (true);
extern long int llogbf (float __x) noexcept (true); extern long int __llogbf (float __x) noexcept (true);
extern float scalblnf (float __x, long int __n) noexcept (true); extern float __scalblnf (float __x, long int __n) noexcept (true);
extern float nearbyintf (float __x) noexcept (true); extern float __nearbyintf (float __x) noexcept (true);
extern float roundf (float __x) noexcept (true) __attribute__ ((__const__)); extern float __roundf (float __x) noexcept (true) __attribute__ ((__const__));
extern float truncf (float __x) noexcept (true) __attribute__ ((__const__)); extern float __truncf (float __x) noexcept (true) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) noexcept (true); extern float __remquof (float __x, float __y, int *__quo) noexcept (true);
extern long int lrintf (float __x) noexcept (true); extern long int __lrintf (float __x) noexcept (true);
__extension__
extern long long int llrintf (float __x) noexcept (true); extern long long int __llrintf (float __x) noexcept (true);
extern long int lroundf (float __x) noexcept (true); extern long int __lroundf (float __x) noexcept (true);
__extension__
extern long long int llroundf (float __x) noexcept (true); extern long long int __llroundf (float __x) noexcept (true);
extern float fdimf (float __x, float __y) noexcept (true); extern float __fdimf (float __x, float __y) noexcept (true);
extern float fmaxf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fminf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) noexcept (true); extern float __fmaf (float __x, float __y, float __z) noexcept (true);
extern float roundevenf (float __x) noexcept (true) __attribute__ ((__const__)); extern float __roundevenf (float __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpf (float __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpf (float __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpf (float __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpf (float __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxf (float __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxf (float __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxf (float __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxf (float __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizef (float *__cx, const float *__x) noexcept (true);
extern float fmaxmagf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fmaxmagf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fminmagf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fminmagf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fmaximumf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fmaximumf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fminimumf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fminimumf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fmaximum_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fmaximum_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fminimum_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fminimum_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fmaximum_magf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fmaximum_magf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fminimum_magf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fminimum_magf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fmaximum_mag_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fmaximum_mag_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern float fminimum_mag_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__)); extern float __fminimum_mag_numf (float __x, float __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderf (const float *__x, const float *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagf (const float *__x, const float *__y) noexcept (true)
     __attribute__ ((__pure__));
extern float getpayloadf (const float *__x) noexcept (true); extern float __getpayloadf (const float *__x) noexcept (true);
extern int setpayloadf (float *__x, float __payload) noexcept (true);
extern int setpayloadsigf (float *__x, float __payload) noexcept (true);
extern float scalbf (float __x, float __n) noexcept (true); extern float __scalbf (float __x, float __n) noexcept (true);
extern int __fpclassifyl (long double __value) noexcept (true)
     __attribute__ ((__const__));
extern int __signbitl (long double __value) noexcept (true)
     __attribute__ ((__const__));
extern int __isinfl (long double __value) noexcept (true)
  __attribute__ ((__const__));
extern int __finitel (long double __value) noexcept (true)
  __attribute__ ((__const__));
extern int __isnanl (long double __value) noexcept (true)
  __attribute__ ((__const__));
extern int __iseqsigl (long double __x, long double __y) noexcept (true);
extern int __issignalingl (long double __value) noexcept (true)
     __attribute__ ((__const__));
 extern long double acosl (long double __x) noexcept (true); extern long double __acosl (long double __x) noexcept (true);
 extern long double asinl (long double __x) noexcept (true); extern long double __asinl (long double __x) noexcept (true);
 extern long double atanl (long double __x) noexcept (true); extern long double __atanl (long double __x) noexcept (true);
 extern long double atan2l (long double __y, long double __x) noexcept (true); extern long double __atan2l (long double __y, long double __x) noexcept (true);
 extern long double cosl (long double __x) noexcept (true); extern long double __cosl (long double __x) noexcept (true);
 extern long double sinl (long double __x) noexcept (true); extern long double __sinl (long double __x) noexcept (true);
 extern long double tanl (long double __x) noexcept (true); extern long double __tanl (long double __x) noexcept (true);
 extern long double coshl (long double __x) noexcept (true); extern long double __coshl (long double __x) noexcept (true);
 extern long double sinhl (long double __x) noexcept (true); extern long double __sinhl (long double __x) noexcept (true);
 extern long double tanhl (long double __x) noexcept (true); extern long double __tanhl (long double __x) noexcept (true);
 extern void sincosl (long double __x, long double *__sinx, long double *__cosx) noexcept (true); extern void __sincosl (long double __x, long double *__sinx, long double *__cosx) noexcept (true);
 extern long double acoshl (long double __x) noexcept (true); extern long double __acoshl (long double __x) noexcept (true);
 extern long double asinhl (long double __x) noexcept (true); extern long double __asinhl (long double __x) noexcept (true);
 extern long double atanhl (long double __x) noexcept (true); extern long double __atanhl (long double __x) noexcept (true);
 extern long double expl (long double __x) noexcept (true); extern long double __expl (long double __x) noexcept (true);
extern long double frexpl (long double __x, int *__exponent) noexcept (true); extern long double __frexpl (long double __x, int *__exponent) noexcept (true);
extern long double ldexpl (long double __x, int __exponent) noexcept (true); extern long double __ldexpl (long double __x, int __exponent) noexcept (true);
 extern long double logl (long double __x) noexcept (true); extern long double __logl (long double __x) noexcept (true);
 extern long double log10l (long double __x) noexcept (true); extern long double __log10l (long double __x) noexcept (true);
extern long double modfl (long double __x, long double *__iptr) noexcept (true); extern long double __modfl (long double __x, long double *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern long double exp10l (long double __x) noexcept (true); extern long double __exp10l (long double __x) noexcept (true);
 extern long double expm1l (long double __x) noexcept (true); extern long double __expm1l (long double __x) noexcept (true);
 extern long double log1pl (long double __x) noexcept (true); extern long double __log1pl (long double __x) noexcept (true);
extern long double logbl (long double __x) noexcept (true); extern long double __logbl (long double __x) noexcept (true);
 extern long double exp2l (long double __x) noexcept (true); extern long double __exp2l (long double __x) noexcept (true);
 extern long double log2l (long double __x) noexcept (true); extern long double __log2l (long double __x) noexcept (true);
 extern long double powl (long double __x, long double __y) noexcept (true); extern long double __powl (long double __x, long double __y) noexcept (true);
extern long double sqrtl (long double __x) noexcept (true); extern long double __sqrtl (long double __x) noexcept (true);
 extern long double hypotl (long double __x, long double __y) noexcept (true); extern long double __hypotl (long double __x, long double __y) noexcept (true);
 extern long double cbrtl (long double __x) noexcept (true); extern long double __cbrtl (long double __x) noexcept (true);
extern long double ceill (long double __x) noexcept (true) __attribute__ ((__const__)); extern long double __ceill (long double __x) noexcept (true) __attribute__ ((__const__));
extern long double fabsl (long double __x) noexcept (true) __attribute__ ((__const__)); extern long double __fabsl (long double __x) noexcept (true) __attribute__ ((__const__));
extern long double floorl (long double __x) noexcept (true) __attribute__ ((__const__)); extern long double __floorl (long double __x) noexcept (true) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) noexcept (true); extern long double __fmodl (long double __x, long double __y) noexcept (true);
extern int isinfl (long double __value) noexcept (true)
  __attribute__ ((__const__));
extern int finitel (long double __value) noexcept (true)
  __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) noexcept (true); extern long double __dreml (long double __x, long double __y) noexcept (true);
extern long double significandl (long double __x) noexcept (true); extern long double __significandl (long double __x) noexcept (true);
extern long double copysignl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double nanl (const char *__tagb) noexcept (true); extern long double __nanl (const char *__tagb) noexcept (true);
extern int isnanl (long double __value) noexcept (true)
  __attribute__ ((__const__));
extern long double j0l (long double) noexcept (true); extern long double __j0l (long double) noexcept (true);
extern long double j1l (long double) noexcept (true); extern long double __j1l (long double) noexcept (true);
extern long double jnl (int, long double) noexcept (true); extern long double __jnl (int, long double) noexcept (true);
extern long double y0l (long double) noexcept (true); extern long double __y0l (long double) noexcept (true);
extern long double y1l (long double) noexcept (true); extern long double __y1l (long double) noexcept (true);
extern long double ynl (int, long double) noexcept (true); extern long double __ynl (int, long double) noexcept (true);
 extern long double erfl (long double) noexcept (true); extern long double __erfl (long double) noexcept (true);
 extern long double erfcl (long double) noexcept (true); extern long double __erfcl (long double) noexcept (true);
extern long double lgammal (long double) noexcept (true); extern long double __lgammal (long double) noexcept (true);
extern long double tgammal (long double) noexcept (true); extern long double __tgammal (long double) noexcept (true);
extern long double gammal (long double) noexcept (true); extern long double __gammal (long double) noexcept (true);
extern long double lgammal_r (long double, int *__signgamp) noexcept (true); extern long double __lgammal_r (long double, int *__signgamp) noexcept (true);
extern long double rintl (long double __x) noexcept (true); extern long double __rintl (long double __x) noexcept (true);
extern long double nextafterl (long double __x, long double __y) noexcept (true); extern long double __nextafterl (long double __x, long double __y) noexcept (true);
extern long double nexttowardl (long double __x, long double __y) noexcept (true); extern long double __nexttowardl (long double __x, long double __y) noexcept (true);
extern long double nextdownl (long double __x) noexcept (true); extern long double __nextdownl (long double __x) noexcept (true);
extern long double nextupl (long double __x) noexcept (true); extern long double __nextupl (long double __x) noexcept (true);
extern long double remainderl (long double __x, long double __y) noexcept (true); extern long double __remainderl (long double __x, long double __y) noexcept (true);
extern long double scalbnl (long double __x, int __n) noexcept (true); extern long double __scalbnl (long double __x, int __n) noexcept (true);
extern int ilogbl (long double __x) noexcept (true); extern int __ilogbl (long double __x) noexcept (true);
extern long int llogbl (long double __x) noexcept (true); extern long int __llogbl (long double __x) noexcept (true);
extern long double scalblnl (long double __x, long int __n) noexcept (true); extern long double __scalblnl (long double __x, long int __n) noexcept (true);
extern long double nearbyintl (long double __x) noexcept (true); extern long double __nearbyintl (long double __x) noexcept (true);
extern long double roundl (long double __x) noexcept (true) __attribute__ ((__const__)); extern long double __roundl (long double __x) noexcept (true) __attribute__ ((__const__));
extern long double truncl (long double __x) noexcept (true) __attribute__ ((__const__)); extern long double __truncl (long double __x) noexcept (true) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) noexcept (true); extern long double __remquol (long double __x, long double __y, int *__quo) noexcept (true);
extern long int lrintl (long double __x) noexcept (true); extern long int __lrintl (long double __x) noexcept (true);
__extension__
extern long long int llrintl (long double __x) noexcept (true); extern long long int __llrintl (long double __x) noexcept (true);
extern long int lroundl (long double __x) noexcept (true); extern long int __lroundl (long double __x) noexcept (true);
__extension__
extern long long int llroundl (long double __x) noexcept (true); extern long long int __llroundl (long double __x) noexcept (true);
extern long double fdiml (long double __x, long double __y) noexcept (true); extern long double __fdiml (long double __x, long double __y) noexcept (true);
extern long double fmaxl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fminl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) noexcept (true); extern long double __fmal (long double __x, long double __y, long double __z) noexcept (true);
extern long double roundevenl (long double __x) noexcept (true) __attribute__ ((__const__)); extern long double __roundevenl (long double __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpl (long double __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpl (long double __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpl (long double __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpl (long double __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxl (long double __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxl (long double __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxl (long double __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxl (long double __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizel (long double *__cx, const long double *__x) noexcept (true);
extern long double fmaxmagl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fmaxmagl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fminmagl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fminmagl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fmaximuml (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fmaximuml (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fminimuml (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fminimuml (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fmaximum_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fmaximum_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fminimum_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fminimum_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fmaximum_magl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fmaximum_magl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fminimum_magl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fminimum_magl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fmaximum_mag_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fmaximum_mag_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern long double fminimum_mag_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__)); extern long double __fminimum_mag_numl (long double __x, long double __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderl (const long double *__x, const long double *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagl (const long double *__x, const long double *__y) noexcept (true)
     __attribute__ ((__pure__));
extern long double getpayloadl (const long double *__x) noexcept (true); extern long double __getpayloadl (const long double *__x) noexcept (true);
extern int setpayloadl (long double *__x, long double __payload) noexcept (true);
extern int setpayloadsigl (long double *__x, long double __payload) noexcept (true);
extern long double scalbl (long double __x, long double __n) noexcept (true); extern long double __scalbl (long double __x, long double __n) noexcept (true);
 extern _Float32 acosf32 (_Float32 __x) noexcept (true); extern _Float32 __acosf32 (_Float32 __x) noexcept (true);
 extern _Float32 asinf32 (_Float32 __x) noexcept (true); extern _Float32 __asinf32 (_Float32 __x) noexcept (true);
 extern _Float32 atanf32 (_Float32 __x) noexcept (true); extern _Float32 __atanf32 (_Float32 __x) noexcept (true);
 extern _Float32 atan2f32 (_Float32 __y, _Float32 __x) noexcept (true); extern _Float32 __atan2f32 (_Float32 __y, _Float32 __x) noexcept (true);
 extern _Float32 cosf32 (_Float32 __x) noexcept (true); extern _Float32 __cosf32 (_Float32 __x) noexcept (true);
 extern _Float32 sinf32 (_Float32 __x) noexcept (true); extern _Float32 __sinf32 (_Float32 __x) noexcept (true);
 extern _Float32 tanf32 (_Float32 __x) noexcept (true); extern _Float32 __tanf32 (_Float32 __x) noexcept (true);
 extern _Float32 coshf32 (_Float32 __x) noexcept (true); extern _Float32 __coshf32 (_Float32 __x) noexcept (true);
 extern _Float32 sinhf32 (_Float32 __x) noexcept (true); extern _Float32 __sinhf32 (_Float32 __x) noexcept (true);
 extern _Float32 tanhf32 (_Float32 __x) noexcept (true); extern _Float32 __tanhf32 (_Float32 __x) noexcept (true);
 extern void sincosf32 (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) noexcept (true); extern void __sincosf32 (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) noexcept (true);
 extern _Float32 acoshf32 (_Float32 __x) noexcept (true); extern _Float32 __acoshf32 (_Float32 __x) noexcept (true);
 extern _Float32 asinhf32 (_Float32 __x) noexcept (true); extern _Float32 __asinhf32 (_Float32 __x) noexcept (true);
 extern _Float32 atanhf32 (_Float32 __x) noexcept (true); extern _Float32 __atanhf32 (_Float32 __x) noexcept (true);
 extern _Float32 expf32 (_Float32 __x) noexcept (true); extern _Float32 __expf32 (_Float32 __x) noexcept (true);
extern _Float32 frexpf32 (_Float32 __x, int *__exponent) noexcept (true); extern _Float32 __frexpf32 (_Float32 __x, int *__exponent) noexcept (true);
extern _Float32 ldexpf32 (_Float32 __x, int __exponent) noexcept (true); extern _Float32 __ldexpf32 (_Float32 __x, int __exponent) noexcept (true);
 extern _Float32 logf32 (_Float32 __x) noexcept (true); extern _Float32 __logf32 (_Float32 __x) noexcept (true);
 extern _Float32 log10f32 (_Float32 __x) noexcept (true); extern _Float32 __log10f32 (_Float32 __x) noexcept (true);
extern _Float32 modff32 (_Float32 __x, _Float32 *__iptr) noexcept (true); extern _Float32 __modff32 (_Float32 __x, _Float32 *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern _Float32 exp10f32 (_Float32 __x) noexcept (true); extern _Float32 __exp10f32 (_Float32 __x) noexcept (true);
 extern _Float32 expm1f32 (_Float32 __x) noexcept (true); extern _Float32 __expm1f32 (_Float32 __x) noexcept (true);
 extern _Float32 log1pf32 (_Float32 __x) noexcept (true); extern _Float32 __log1pf32 (_Float32 __x) noexcept (true);
extern _Float32 logbf32 (_Float32 __x) noexcept (true); extern _Float32 __logbf32 (_Float32 __x) noexcept (true);
 extern _Float32 exp2f32 (_Float32 __x) noexcept (true); extern _Float32 __exp2f32 (_Float32 __x) noexcept (true);
 extern _Float32 log2f32 (_Float32 __x) noexcept (true); extern _Float32 __log2f32 (_Float32 __x) noexcept (true);
 extern _Float32 powf32 (_Float32 __x, _Float32 __y) noexcept (true); extern _Float32 __powf32 (_Float32 __x, _Float32 __y) noexcept (true);
extern _Float32 sqrtf32 (_Float32 __x) noexcept (true); extern _Float32 __sqrtf32 (_Float32 __x) noexcept (true);
 extern _Float32 hypotf32 (_Float32 __x, _Float32 __y) noexcept (true); extern _Float32 __hypotf32 (_Float32 __x, _Float32 __y) noexcept (true);
 extern _Float32 cbrtf32 (_Float32 __x) noexcept (true); extern _Float32 __cbrtf32 (_Float32 __x) noexcept (true);
extern _Float32 ceilf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__)); extern _Float32 __ceilf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__));
extern _Float32 fabsf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fabsf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__));
extern _Float32 floorf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__)); extern _Float32 __floorf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__));
extern _Float32 fmodf32 (_Float32 __x, _Float32 __y) noexcept (true); extern _Float32 __fmodf32 (_Float32 __x, _Float32 __y) noexcept (true);
extern _Float32 copysignf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __copysignf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 nanf32 (const char *__tagb) noexcept (true); extern _Float32 __nanf32 (const char *__tagb) noexcept (true);
extern _Float32 j0f32 (_Float32) noexcept (true); extern _Float32 __j0f32 (_Float32) noexcept (true);
extern _Float32 j1f32 (_Float32) noexcept (true); extern _Float32 __j1f32 (_Float32) noexcept (true);
extern _Float32 jnf32 (int, _Float32) noexcept (true); extern _Float32 __jnf32 (int, _Float32) noexcept (true);
extern _Float32 y0f32 (_Float32) noexcept (true); extern _Float32 __y0f32 (_Float32) noexcept (true);
extern _Float32 y1f32 (_Float32) noexcept (true); extern _Float32 __y1f32 (_Float32) noexcept (true);
extern _Float32 ynf32 (int, _Float32) noexcept (true); extern _Float32 __ynf32 (int, _Float32) noexcept (true);
 extern _Float32 erff32 (_Float32) noexcept (true); extern _Float32 __erff32 (_Float32) noexcept (true);
 extern _Float32 erfcf32 (_Float32) noexcept (true); extern _Float32 __erfcf32 (_Float32) noexcept (true);
extern _Float32 lgammaf32 (_Float32) noexcept (true); extern _Float32 __lgammaf32 (_Float32) noexcept (true);
extern _Float32 tgammaf32 (_Float32) noexcept (true); extern _Float32 __tgammaf32 (_Float32) noexcept (true);
extern _Float32 lgammaf32_r (_Float32, int *__signgamp) noexcept (true); extern _Float32 __lgammaf32_r (_Float32, int *__signgamp) noexcept (true);
extern _Float32 rintf32 (_Float32 __x) noexcept (true); extern _Float32 __rintf32 (_Float32 __x) noexcept (true);
extern _Float32 nextafterf32 (_Float32 __x, _Float32 __y) noexcept (true); extern _Float32 __nextafterf32 (_Float32 __x, _Float32 __y) noexcept (true);
extern _Float32 nextdownf32 (_Float32 __x) noexcept (true); extern _Float32 __nextdownf32 (_Float32 __x) noexcept (true);
extern _Float32 nextupf32 (_Float32 __x) noexcept (true); extern _Float32 __nextupf32 (_Float32 __x) noexcept (true);
extern _Float32 remainderf32 (_Float32 __x, _Float32 __y) noexcept (true); extern _Float32 __remainderf32 (_Float32 __x, _Float32 __y) noexcept (true);
extern _Float32 scalbnf32 (_Float32 __x, int __n) noexcept (true); extern _Float32 __scalbnf32 (_Float32 __x, int __n) noexcept (true);
extern int ilogbf32 (_Float32 __x) noexcept (true); extern int __ilogbf32 (_Float32 __x) noexcept (true);
extern long int llogbf32 (_Float32 __x) noexcept (true); extern long int __llogbf32 (_Float32 __x) noexcept (true);
extern _Float32 scalblnf32 (_Float32 __x, long int __n) noexcept (true); extern _Float32 __scalblnf32 (_Float32 __x, long int __n) noexcept (true);
extern _Float32 nearbyintf32 (_Float32 __x) noexcept (true); extern _Float32 __nearbyintf32 (_Float32 __x) noexcept (true);
extern _Float32 roundf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__)); extern _Float32 __roundf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__));
extern _Float32 truncf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__)); extern _Float32 __truncf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__));
extern _Float32 remquof32 (_Float32 __x, _Float32 __y, int *__quo) noexcept (true); extern _Float32 __remquof32 (_Float32 __x, _Float32 __y, int *__quo) noexcept (true);
extern long int lrintf32 (_Float32 __x) noexcept (true); extern long int __lrintf32 (_Float32 __x) noexcept (true);
__extension__
extern long long int llrintf32 (_Float32 __x) noexcept (true); extern long long int __llrintf32 (_Float32 __x) noexcept (true);
extern long int lroundf32 (_Float32 __x) noexcept (true); extern long int __lroundf32 (_Float32 __x) noexcept (true);
__extension__
extern long long int llroundf32 (_Float32 __x) noexcept (true); extern long long int __llroundf32 (_Float32 __x) noexcept (true);
extern _Float32 fdimf32 (_Float32 __x, _Float32 __y) noexcept (true); extern _Float32 __fdimf32 (_Float32 __x, _Float32 __y) noexcept (true);
extern _Float32 fmaxf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fmaxf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fminf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fminf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fmaf32 (_Float32 __x, _Float32 __y, _Float32 __z) noexcept (true); extern _Float32 __fmaf32 (_Float32 __x, _Float32 __y, _Float32 __z) noexcept (true);
extern _Float32 roundevenf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__)); extern _Float32 __roundevenf32 (_Float32 __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxf32 (_Float32 __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizef32 (_Float32 *__cx, const _Float32 *__x) noexcept (true);
extern _Float32 fmaxmagf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fmaxmagf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fminmagf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fminmagf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fmaximumf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fmaximumf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fminimumf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fminimumf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fmaximum_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fmaximum_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fminimum_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fminimum_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fmaximum_magf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fmaximum_magf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fminimum_magf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fminimum_magf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fmaximum_mag_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fmaximum_mag_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern _Float32 fminimum_mag_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__)); extern _Float32 __fminimum_mag_numf32 (_Float32 __x, _Float32 __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderf32 (const _Float32 *__x, const _Float32 *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagf32 (const _Float32 *__x, const _Float32 *__y) noexcept (true)
     __attribute__ ((__pure__));
extern _Float32 getpayloadf32 (const _Float32 *__x) noexcept (true); extern _Float32 __getpayloadf32 (const _Float32 *__x) noexcept (true);
extern int setpayloadf32 (_Float32 *__x, _Float32 __payload) noexcept (true);
extern int setpayloadsigf32 (_Float32 *__x, _Float32 __payload) noexcept (true);
 extern _Float64 acosf64 (_Float64 __x) noexcept (true); extern _Float64 __acosf64 (_Float64 __x) noexcept (true);
 extern _Float64 asinf64 (_Float64 __x) noexcept (true); extern _Float64 __asinf64 (_Float64 __x) noexcept (true);
 extern _Float64 atanf64 (_Float64 __x) noexcept (true); extern _Float64 __atanf64 (_Float64 __x) noexcept (true);
 extern _Float64 atan2f64 (_Float64 __y, _Float64 __x) noexcept (true); extern _Float64 __atan2f64 (_Float64 __y, _Float64 __x) noexcept (true);
 extern _Float64 cosf64 (_Float64 __x) noexcept (true); extern _Float64 __cosf64 (_Float64 __x) noexcept (true);
 extern _Float64 sinf64 (_Float64 __x) noexcept (true); extern _Float64 __sinf64 (_Float64 __x) noexcept (true);
 extern _Float64 tanf64 (_Float64 __x) noexcept (true); extern _Float64 __tanf64 (_Float64 __x) noexcept (true);
 extern _Float64 coshf64 (_Float64 __x) noexcept (true); extern _Float64 __coshf64 (_Float64 __x) noexcept (true);
 extern _Float64 sinhf64 (_Float64 __x) noexcept (true); extern _Float64 __sinhf64 (_Float64 __x) noexcept (true);
 extern _Float64 tanhf64 (_Float64 __x) noexcept (true); extern _Float64 __tanhf64 (_Float64 __x) noexcept (true);
 extern void sincosf64 (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) noexcept (true); extern void __sincosf64 (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) noexcept (true);
 extern _Float64 acoshf64 (_Float64 __x) noexcept (true); extern _Float64 __acoshf64 (_Float64 __x) noexcept (true);
 extern _Float64 asinhf64 (_Float64 __x) noexcept (true); extern _Float64 __asinhf64 (_Float64 __x) noexcept (true);
 extern _Float64 atanhf64 (_Float64 __x) noexcept (true); extern _Float64 __atanhf64 (_Float64 __x) noexcept (true);
 extern _Float64 expf64 (_Float64 __x) noexcept (true); extern _Float64 __expf64 (_Float64 __x) noexcept (true);
extern _Float64 frexpf64 (_Float64 __x, int *__exponent) noexcept (true); extern _Float64 __frexpf64 (_Float64 __x, int *__exponent) noexcept (true);
extern _Float64 ldexpf64 (_Float64 __x, int __exponent) noexcept (true); extern _Float64 __ldexpf64 (_Float64 __x, int __exponent) noexcept (true);
 extern _Float64 logf64 (_Float64 __x) noexcept (true); extern _Float64 __logf64 (_Float64 __x) noexcept (true);
 extern _Float64 log10f64 (_Float64 __x) noexcept (true); extern _Float64 __log10f64 (_Float64 __x) noexcept (true);
extern _Float64 modff64 (_Float64 __x, _Float64 *__iptr) noexcept (true); extern _Float64 __modff64 (_Float64 __x, _Float64 *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern _Float64 exp10f64 (_Float64 __x) noexcept (true); extern _Float64 __exp10f64 (_Float64 __x) noexcept (true);
 extern _Float64 expm1f64 (_Float64 __x) noexcept (true); extern _Float64 __expm1f64 (_Float64 __x) noexcept (true);
 extern _Float64 log1pf64 (_Float64 __x) noexcept (true); extern _Float64 __log1pf64 (_Float64 __x) noexcept (true);
extern _Float64 logbf64 (_Float64 __x) noexcept (true); extern _Float64 __logbf64 (_Float64 __x) noexcept (true);
 extern _Float64 exp2f64 (_Float64 __x) noexcept (true); extern _Float64 __exp2f64 (_Float64 __x) noexcept (true);
 extern _Float64 log2f64 (_Float64 __x) noexcept (true); extern _Float64 __log2f64 (_Float64 __x) noexcept (true);
 extern _Float64 powf64 (_Float64 __x, _Float64 __y) noexcept (true); extern _Float64 __powf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float64 sqrtf64 (_Float64 __x) noexcept (true); extern _Float64 __sqrtf64 (_Float64 __x) noexcept (true);
 extern _Float64 hypotf64 (_Float64 __x, _Float64 __y) noexcept (true); extern _Float64 __hypotf64 (_Float64 __x, _Float64 __y) noexcept (true);
 extern _Float64 cbrtf64 (_Float64 __x) noexcept (true); extern _Float64 __cbrtf64 (_Float64 __x) noexcept (true);
extern _Float64 ceilf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__)); extern _Float64 __ceilf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__));
extern _Float64 fabsf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fabsf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__));
extern _Float64 floorf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__)); extern _Float64 __floorf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__));
extern _Float64 fmodf64 (_Float64 __x, _Float64 __y) noexcept (true); extern _Float64 __fmodf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float64 copysignf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __copysignf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 nanf64 (const char *__tagb) noexcept (true); extern _Float64 __nanf64 (const char *__tagb) noexcept (true);
extern _Float64 j0f64 (_Float64) noexcept (true); extern _Float64 __j0f64 (_Float64) noexcept (true);
extern _Float64 j1f64 (_Float64) noexcept (true); extern _Float64 __j1f64 (_Float64) noexcept (true);
extern _Float64 jnf64 (int, _Float64) noexcept (true); extern _Float64 __jnf64 (int, _Float64) noexcept (true);
extern _Float64 y0f64 (_Float64) noexcept (true); extern _Float64 __y0f64 (_Float64) noexcept (true);
extern _Float64 y1f64 (_Float64) noexcept (true); extern _Float64 __y1f64 (_Float64) noexcept (true);
extern _Float64 ynf64 (int, _Float64) noexcept (true); extern _Float64 __ynf64 (int, _Float64) noexcept (true);
 extern _Float64 erff64 (_Float64) noexcept (true); extern _Float64 __erff64 (_Float64) noexcept (true);
 extern _Float64 erfcf64 (_Float64) noexcept (true); extern _Float64 __erfcf64 (_Float64) noexcept (true);
extern _Float64 lgammaf64 (_Float64) noexcept (true); extern _Float64 __lgammaf64 (_Float64) noexcept (true);
extern _Float64 tgammaf64 (_Float64) noexcept (true); extern _Float64 __tgammaf64 (_Float64) noexcept (true);
extern _Float64 lgammaf64_r (_Float64, int *__signgamp) noexcept (true); extern _Float64 __lgammaf64_r (_Float64, int *__signgamp) noexcept (true);
extern _Float64 rintf64 (_Float64 __x) noexcept (true); extern _Float64 __rintf64 (_Float64 __x) noexcept (true);
extern _Float64 nextafterf64 (_Float64 __x, _Float64 __y) noexcept (true); extern _Float64 __nextafterf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float64 nextdownf64 (_Float64 __x) noexcept (true); extern _Float64 __nextdownf64 (_Float64 __x) noexcept (true);
extern _Float64 nextupf64 (_Float64 __x) noexcept (true); extern _Float64 __nextupf64 (_Float64 __x) noexcept (true);
extern _Float64 remainderf64 (_Float64 __x, _Float64 __y) noexcept (true); extern _Float64 __remainderf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float64 scalbnf64 (_Float64 __x, int __n) noexcept (true); extern _Float64 __scalbnf64 (_Float64 __x, int __n) noexcept (true);
extern int ilogbf64 (_Float64 __x) noexcept (true); extern int __ilogbf64 (_Float64 __x) noexcept (true);
extern long int llogbf64 (_Float64 __x) noexcept (true); extern long int __llogbf64 (_Float64 __x) noexcept (true);
extern _Float64 scalblnf64 (_Float64 __x, long int __n) noexcept (true); extern _Float64 __scalblnf64 (_Float64 __x, long int __n) noexcept (true);
extern _Float64 nearbyintf64 (_Float64 __x) noexcept (true); extern _Float64 __nearbyintf64 (_Float64 __x) noexcept (true);
extern _Float64 roundf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__)); extern _Float64 __roundf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__));
extern _Float64 truncf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__)); extern _Float64 __truncf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__));
extern _Float64 remquof64 (_Float64 __x, _Float64 __y, int *__quo) noexcept (true); extern _Float64 __remquof64 (_Float64 __x, _Float64 __y, int *__quo) noexcept (true);
extern long int lrintf64 (_Float64 __x) noexcept (true); extern long int __lrintf64 (_Float64 __x) noexcept (true);
__extension__
extern long long int llrintf64 (_Float64 __x) noexcept (true); extern long long int __llrintf64 (_Float64 __x) noexcept (true);
extern long int lroundf64 (_Float64 __x) noexcept (true); extern long int __lroundf64 (_Float64 __x) noexcept (true);
__extension__
extern long long int llroundf64 (_Float64 __x) noexcept (true); extern long long int __llroundf64 (_Float64 __x) noexcept (true);
extern _Float64 fdimf64 (_Float64 __x, _Float64 __y) noexcept (true); extern _Float64 __fdimf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float64 fmaxf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fmaxf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fminf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fminf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) noexcept (true); extern _Float64 __fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) noexcept (true);
extern _Float64 roundevenf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__)); extern _Float64 __roundevenf64 (_Float64 __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxf64 (_Float64 __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizef64 (_Float64 *__cx, const _Float64 *__x) noexcept (true);
extern _Float64 fmaxmagf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fmaxmagf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fminmagf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fminmagf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fmaximumf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fmaximumf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fminimumf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fminimumf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fmaximum_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fmaximum_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fminimum_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fminimum_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fmaximum_magf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fmaximum_magf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fminimum_magf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fminimum_magf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fmaximum_mag_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fmaximum_mag_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern _Float64 fminimum_mag_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__)); extern _Float64 __fminimum_mag_numf64 (_Float64 __x, _Float64 __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderf64 (const _Float64 *__x, const _Float64 *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagf64 (const _Float64 *__x, const _Float64 *__y) noexcept (true)
     __attribute__ ((__pure__));
extern _Float64 getpayloadf64 (const _Float64 *__x) noexcept (true); extern _Float64 __getpayloadf64 (const _Float64 *__x) noexcept (true);
extern int setpayloadf64 (_Float64 *__x, _Float64 __payload) noexcept (true);
extern int setpayloadsigf64 (_Float64 *__x, _Float64 __payload) noexcept (true);
extern int __fpclassifyf128 (_Float128 __value) noexcept (true)
     __attribute__ ((__const__));
extern int __signbitf128 (_Float128 __value) noexcept (true)
     __attribute__ ((__const__));
extern int __isinff128 (_Float128 __value) noexcept (true)
  __attribute__ ((__const__));
extern int __finitef128 (_Float128 __value) noexcept (true)
  __attribute__ ((__const__));
extern int __isnanf128 (_Float128 __value) noexcept (true)
  __attribute__ ((__const__));
extern int __iseqsigf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern int __issignalingf128 (_Float128 __value) noexcept (true)
     __attribute__ ((__const__));
 extern _Float128 acosf128 (_Float128 __x) noexcept (true); extern _Float128 __acosf128 (_Float128 __x) noexcept (true);
 extern _Float128 asinf128 (_Float128 __x) noexcept (true); extern _Float128 __asinf128 (_Float128 __x) noexcept (true);
 extern _Float128 atanf128 (_Float128 __x) noexcept (true); extern _Float128 __atanf128 (_Float128 __x) noexcept (true);
 extern _Float128 atan2f128 (_Float128 __y, _Float128 __x) noexcept (true); extern _Float128 __atan2f128 (_Float128 __y, _Float128 __x) noexcept (true);
 extern _Float128 cosf128 (_Float128 __x) noexcept (true); extern _Float128 __cosf128 (_Float128 __x) noexcept (true);
 extern _Float128 sinf128 (_Float128 __x) noexcept (true); extern _Float128 __sinf128 (_Float128 __x) noexcept (true);
 extern _Float128 tanf128 (_Float128 __x) noexcept (true); extern _Float128 __tanf128 (_Float128 __x) noexcept (true);
 extern _Float128 coshf128 (_Float128 __x) noexcept (true); extern _Float128 __coshf128 (_Float128 __x) noexcept (true);
 extern _Float128 sinhf128 (_Float128 __x) noexcept (true); extern _Float128 __sinhf128 (_Float128 __x) noexcept (true);
 extern _Float128 tanhf128 (_Float128 __x) noexcept (true); extern _Float128 __tanhf128 (_Float128 __x) noexcept (true);
 extern void sincosf128 (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) noexcept (true); extern void __sincosf128 (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) noexcept (true);
 extern _Float128 acoshf128 (_Float128 __x) noexcept (true); extern _Float128 __acoshf128 (_Float128 __x) noexcept (true);
 extern _Float128 asinhf128 (_Float128 __x) noexcept (true); extern _Float128 __asinhf128 (_Float128 __x) noexcept (true);
 extern _Float128 atanhf128 (_Float128 __x) noexcept (true); extern _Float128 __atanhf128 (_Float128 __x) noexcept (true);
 extern _Float128 expf128 (_Float128 __x) noexcept (true); extern _Float128 __expf128 (_Float128 __x) noexcept (true);
extern _Float128 frexpf128 (_Float128 __x, int *__exponent) noexcept (true); extern _Float128 __frexpf128 (_Float128 __x, int *__exponent) noexcept (true);
extern _Float128 ldexpf128 (_Float128 __x, int __exponent) noexcept (true); extern _Float128 __ldexpf128 (_Float128 __x, int __exponent) noexcept (true);
 extern _Float128 logf128 (_Float128 __x) noexcept (true); extern _Float128 __logf128 (_Float128 __x) noexcept (true);
 extern _Float128 log10f128 (_Float128 __x) noexcept (true); extern _Float128 __log10f128 (_Float128 __x) noexcept (true);
extern _Float128 modff128 (_Float128 __x, _Float128 *__iptr) noexcept (true); extern _Float128 __modff128 (_Float128 __x, _Float128 *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern _Float128 exp10f128 (_Float128 __x) noexcept (true); extern _Float128 __exp10f128 (_Float128 __x) noexcept (true);
 extern _Float128 expm1f128 (_Float128 __x) noexcept (true); extern _Float128 __expm1f128 (_Float128 __x) noexcept (true);
 extern _Float128 log1pf128 (_Float128 __x) noexcept (true); extern _Float128 __log1pf128 (_Float128 __x) noexcept (true);
extern _Float128 logbf128 (_Float128 __x) noexcept (true); extern _Float128 __logbf128 (_Float128 __x) noexcept (true);
 extern _Float128 exp2f128 (_Float128 __x) noexcept (true); extern _Float128 __exp2f128 (_Float128 __x) noexcept (true);
 extern _Float128 log2f128 (_Float128 __x) noexcept (true); extern _Float128 __log2f128 (_Float128 __x) noexcept (true);
 extern _Float128 powf128 (_Float128 __x, _Float128 __y) noexcept (true); extern _Float128 __powf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float128 sqrtf128 (_Float128 __x) noexcept (true); extern _Float128 __sqrtf128 (_Float128 __x) noexcept (true);
 extern _Float128 hypotf128 (_Float128 __x, _Float128 __y) noexcept (true); extern _Float128 __hypotf128 (_Float128 __x, _Float128 __y) noexcept (true);
 extern _Float128 cbrtf128 (_Float128 __x) noexcept (true); extern _Float128 __cbrtf128 (_Float128 __x) noexcept (true);
extern _Float128 ceilf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__)); extern _Float128 __ceilf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__));
extern _Float128 fabsf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fabsf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__));
extern _Float128 floorf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__)); extern _Float128 __floorf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__));
extern _Float128 fmodf128 (_Float128 __x, _Float128 __y) noexcept (true); extern _Float128 __fmodf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float128 copysignf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __copysignf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 nanf128 (const char *__tagb) noexcept (true); extern _Float128 __nanf128 (const char *__tagb) noexcept (true);
extern _Float128 j0f128 (_Float128) noexcept (true); extern _Float128 __j0f128 (_Float128) noexcept (true);
extern _Float128 j1f128 (_Float128) noexcept (true); extern _Float128 __j1f128 (_Float128) noexcept (true);
extern _Float128 jnf128 (int, _Float128) noexcept (true); extern _Float128 __jnf128 (int, _Float128) noexcept (true);
extern _Float128 y0f128 (_Float128) noexcept (true); extern _Float128 __y0f128 (_Float128) noexcept (true);
extern _Float128 y1f128 (_Float128) noexcept (true); extern _Float128 __y1f128 (_Float128) noexcept (true);
extern _Float128 ynf128 (int, _Float128) noexcept (true); extern _Float128 __ynf128 (int, _Float128) noexcept (true);
 extern _Float128 erff128 (_Float128) noexcept (true); extern _Float128 __erff128 (_Float128) noexcept (true);
 extern _Float128 erfcf128 (_Float128) noexcept (true); extern _Float128 __erfcf128 (_Float128) noexcept (true);
extern _Float128 lgammaf128 (_Float128) noexcept (true); extern _Float128 __lgammaf128 (_Float128) noexcept (true);
extern _Float128 tgammaf128 (_Float128) noexcept (true); extern _Float128 __tgammaf128 (_Float128) noexcept (true);
extern _Float128 lgammaf128_r (_Float128, int *__signgamp) noexcept (true); extern _Float128 __lgammaf128_r (_Float128, int *__signgamp) noexcept (true);
extern _Float128 rintf128 (_Float128 __x) noexcept (true); extern _Float128 __rintf128 (_Float128 __x) noexcept (true);
extern _Float128 nextafterf128 (_Float128 __x, _Float128 __y) noexcept (true); extern _Float128 __nextafterf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float128 nextdownf128 (_Float128 __x) noexcept (true); extern _Float128 __nextdownf128 (_Float128 __x) noexcept (true);
extern _Float128 nextupf128 (_Float128 __x) noexcept (true); extern _Float128 __nextupf128 (_Float128 __x) noexcept (true);
extern _Float128 remainderf128 (_Float128 __x, _Float128 __y) noexcept (true); extern _Float128 __remainderf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float128 scalbnf128 (_Float128 __x, int __n) noexcept (true); extern _Float128 __scalbnf128 (_Float128 __x, int __n) noexcept (true);
extern int ilogbf128 (_Float128 __x) noexcept (true); extern int __ilogbf128 (_Float128 __x) noexcept (true);
extern long int llogbf128 (_Float128 __x) noexcept (true); extern long int __llogbf128 (_Float128 __x) noexcept (true);
extern _Float128 scalblnf128 (_Float128 __x, long int __n) noexcept (true); extern _Float128 __scalblnf128 (_Float128 __x, long int __n) noexcept (true);
extern _Float128 nearbyintf128 (_Float128 __x) noexcept (true); extern _Float128 __nearbyintf128 (_Float128 __x) noexcept (true);
extern _Float128 roundf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__)); extern _Float128 __roundf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__));
extern _Float128 truncf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__)); extern _Float128 __truncf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__));
extern _Float128 remquof128 (_Float128 __x, _Float128 __y, int *__quo) noexcept (true); extern _Float128 __remquof128 (_Float128 __x, _Float128 __y, int *__quo) noexcept (true);
extern long int lrintf128 (_Float128 __x) noexcept (true); extern long int __lrintf128 (_Float128 __x) noexcept (true);
__extension__
extern long long int llrintf128 (_Float128 __x) noexcept (true); extern long long int __llrintf128 (_Float128 __x) noexcept (true);
extern long int lroundf128 (_Float128 __x) noexcept (true); extern long int __lroundf128 (_Float128 __x) noexcept (true);
__extension__
extern long long int llroundf128 (_Float128 __x) noexcept (true); extern long long int __llroundf128 (_Float128 __x) noexcept (true);
extern _Float128 fdimf128 (_Float128 __x, _Float128 __y) noexcept (true); extern _Float128 __fdimf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float128 fmaxf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fmaxf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fminf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fminf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) noexcept (true); extern _Float128 __fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) noexcept (true);
extern _Float128 roundevenf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__)); extern _Float128 __roundevenf128 (_Float128 __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxf128 (_Float128 __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizef128 (_Float128 *__cx, const _Float128 *__x) noexcept (true);
extern _Float128 fmaxmagf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fmaxmagf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fminmagf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fminmagf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fmaximumf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fmaximumf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fminimumf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fminimumf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fmaximum_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fmaximum_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fminimum_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fminimum_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fmaximum_magf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fmaximum_magf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fminimum_magf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fminimum_magf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fmaximum_mag_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fmaximum_mag_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern _Float128 fminimum_mag_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__)); extern _Float128 __fminimum_mag_numf128 (_Float128 __x, _Float128 __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderf128 (const _Float128 *__x, const _Float128 *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagf128 (const _Float128 *__x, const _Float128 *__y) noexcept (true)
     __attribute__ ((__pure__));
extern _Float128 getpayloadf128 (const _Float128 *__x) noexcept (true); extern _Float128 __getpayloadf128 (const _Float128 *__x) noexcept (true);
extern int setpayloadf128 (_Float128 *__x, _Float128 __payload) noexcept (true);
extern int setpayloadsigf128 (_Float128 *__x, _Float128 __payload) noexcept (true);
 extern _Float32x acosf32x (_Float32x __x) noexcept (true); extern _Float32x __acosf32x (_Float32x __x) noexcept (true);
 extern _Float32x asinf32x (_Float32x __x) noexcept (true); extern _Float32x __asinf32x (_Float32x __x) noexcept (true);
 extern _Float32x atanf32x (_Float32x __x) noexcept (true); extern _Float32x __atanf32x (_Float32x __x) noexcept (true);
 extern _Float32x atan2f32x (_Float32x __y, _Float32x __x) noexcept (true); extern _Float32x __atan2f32x (_Float32x __y, _Float32x __x) noexcept (true);
 extern _Float32x cosf32x (_Float32x __x) noexcept (true); extern _Float32x __cosf32x (_Float32x __x) noexcept (true);
 extern _Float32x sinf32x (_Float32x __x) noexcept (true); extern _Float32x __sinf32x (_Float32x __x) noexcept (true);
 extern _Float32x tanf32x (_Float32x __x) noexcept (true); extern _Float32x __tanf32x (_Float32x __x) noexcept (true);
 extern _Float32x coshf32x (_Float32x __x) noexcept (true); extern _Float32x __coshf32x (_Float32x __x) noexcept (true);
 extern _Float32x sinhf32x (_Float32x __x) noexcept (true); extern _Float32x __sinhf32x (_Float32x __x) noexcept (true);
 extern _Float32x tanhf32x (_Float32x __x) noexcept (true); extern _Float32x __tanhf32x (_Float32x __x) noexcept (true);
 extern void sincosf32x (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) noexcept (true); extern void __sincosf32x (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) noexcept (true);
 extern _Float32x acoshf32x (_Float32x __x) noexcept (true); extern _Float32x __acoshf32x (_Float32x __x) noexcept (true);
 extern _Float32x asinhf32x (_Float32x __x) noexcept (true); extern _Float32x __asinhf32x (_Float32x __x) noexcept (true);
 extern _Float32x atanhf32x (_Float32x __x) noexcept (true); extern _Float32x __atanhf32x (_Float32x __x) noexcept (true);
 extern _Float32x expf32x (_Float32x __x) noexcept (true); extern _Float32x __expf32x (_Float32x __x) noexcept (true);
extern _Float32x frexpf32x (_Float32x __x, int *__exponent) noexcept (true); extern _Float32x __frexpf32x (_Float32x __x, int *__exponent) noexcept (true);
extern _Float32x ldexpf32x (_Float32x __x, int __exponent) noexcept (true); extern _Float32x __ldexpf32x (_Float32x __x, int __exponent) noexcept (true);
 extern _Float32x logf32x (_Float32x __x) noexcept (true); extern _Float32x __logf32x (_Float32x __x) noexcept (true);
 extern _Float32x log10f32x (_Float32x __x) noexcept (true); extern _Float32x __log10f32x (_Float32x __x) noexcept (true);
extern _Float32x modff32x (_Float32x __x, _Float32x *__iptr) noexcept (true); extern _Float32x __modff32x (_Float32x __x, _Float32x *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern _Float32x exp10f32x (_Float32x __x) noexcept (true); extern _Float32x __exp10f32x (_Float32x __x) noexcept (true);
 extern _Float32x expm1f32x (_Float32x __x) noexcept (true); extern _Float32x __expm1f32x (_Float32x __x) noexcept (true);
 extern _Float32x log1pf32x (_Float32x __x) noexcept (true); extern _Float32x __log1pf32x (_Float32x __x) noexcept (true);
extern _Float32x logbf32x (_Float32x __x) noexcept (true); extern _Float32x __logbf32x (_Float32x __x) noexcept (true);
 extern _Float32x exp2f32x (_Float32x __x) noexcept (true); extern _Float32x __exp2f32x (_Float32x __x) noexcept (true);
 extern _Float32x log2f32x (_Float32x __x) noexcept (true); extern _Float32x __log2f32x (_Float32x __x) noexcept (true);
 extern _Float32x powf32x (_Float32x __x, _Float32x __y) noexcept (true); extern _Float32x __powf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32x sqrtf32x (_Float32x __x) noexcept (true); extern _Float32x __sqrtf32x (_Float32x __x) noexcept (true);
 extern _Float32x hypotf32x (_Float32x __x, _Float32x __y) noexcept (true); extern _Float32x __hypotf32x (_Float32x __x, _Float32x __y) noexcept (true);
 extern _Float32x cbrtf32x (_Float32x __x) noexcept (true); extern _Float32x __cbrtf32x (_Float32x __x) noexcept (true);
extern _Float32x ceilf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__)); extern _Float32x __ceilf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__));
extern _Float32x fabsf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fabsf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__));
extern _Float32x floorf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__)); extern _Float32x __floorf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__));
extern _Float32x fmodf32x (_Float32x __x, _Float32x __y) noexcept (true); extern _Float32x __fmodf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32x copysignf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __copysignf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x nanf32x (const char *__tagb) noexcept (true); extern _Float32x __nanf32x (const char *__tagb) noexcept (true);
extern _Float32x j0f32x (_Float32x) noexcept (true); extern _Float32x __j0f32x (_Float32x) noexcept (true);
extern _Float32x j1f32x (_Float32x) noexcept (true); extern _Float32x __j1f32x (_Float32x) noexcept (true);
extern _Float32x jnf32x (int, _Float32x) noexcept (true); extern _Float32x __jnf32x (int, _Float32x) noexcept (true);
extern _Float32x y0f32x (_Float32x) noexcept (true); extern _Float32x __y0f32x (_Float32x) noexcept (true);
extern _Float32x y1f32x (_Float32x) noexcept (true); extern _Float32x __y1f32x (_Float32x) noexcept (true);
extern _Float32x ynf32x (int, _Float32x) noexcept (true); extern _Float32x __ynf32x (int, _Float32x) noexcept (true);
 extern _Float32x erff32x (_Float32x) noexcept (true); extern _Float32x __erff32x (_Float32x) noexcept (true);
 extern _Float32x erfcf32x (_Float32x) noexcept (true); extern _Float32x __erfcf32x (_Float32x) noexcept (true);
extern _Float32x lgammaf32x (_Float32x) noexcept (true); extern _Float32x __lgammaf32x (_Float32x) noexcept (true);
extern _Float32x tgammaf32x (_Float32x) noexcept (true); extern _Float32x __tgammaf32x (_Float32x) noexcept (true);
extern _Float32x lgammaf32x_r (_Float32x, int *__signgamp) noexcept (true); extern _Float32x __lgammaf32x_r (_Float32x, int *__signgamp) noexcept (true);
extern _Float32x rintf32x (_Float32x __x) noexcept (true); extern _Float32x __rintf32x (_Float32x __x) noexcept (true);
extern _Float32x nextafterf32x (_Float32x __x, _Float32x __y) noexcept (true); extern _Float32x __nextafterf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32x nextdownf32x (_Float32x __x) noexcept (true); extern _Float32x __nextdownf32x (_Float32x __x) noexcept (true);
extern _Float32x nextupf32x (_Float32x __x) noexcept (true); extern _Float32x __nextupf32x (_Float32x __x) noexcept (true);
extern _Float32x remainderf32x (_Float32x __x, _Float32x __y) noexcept (true); extern _Float32x __remainderf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32x scalbnf32x (_Float32x __x, int __n) noexcept (true); extern _Float32x __scalbnf32x (_Float32x __x, int __n) noexcept (true);
extern int ilogbf32x (_Float32x __x) noexcept (true); extern int __ilogbf32x (_Float32x __x) noexcept (true);
extern long int llogbf32x (_Float32x __x) noexcept (true); extern long int __llogbf32x (_Float32x __x) noexcept (true);
extern _Float32x scalblnf32x (_Float32x __x, long int __n) noexcept (true); extern _Float32x __scalblnf32x (_Float32x __x, long int __n) noexcept (true);
extern _Float32x nearbyintf32x (_Float32x __x) noexcept (true); extern _Float32x __nearbyintf32x (_Float32x __x) noexcept (true);
extern _Float32x roundf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__)); extern _Float32x __roundf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__));
extern _Float32x truncf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__)); extern _Float32x __truncf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__));
extern _Float32x remquof32x (_Float32x __x, _Float32x __y, int *__quo) noexcept (true); extern _Float32x __remquof32x (_Float32x __x, _Float32x __y, int *__quo) noexcept (true);
extern long int lrintf32x (_Float32x __x) noexcept (true); extern long int __lrintf32x (_Float32x __x) noexcept (true);
__extension__
extern long long int llrintf32x (_Float32x __x) noexcept (true); extern long long int __llrintf32x (_Float32x __x) noexcept (true);
extern long int lroundf32x (_Float32x __x) noexcept (true); extern long int __lroundf32x (_Float32x __x) noexcept (true);
__extension__
extern long long int llroundf32x (_Float32x __x) noexcept (true); extern long long int __llroundf32x (_Float32x __x) noexcept (true);
extern _Float32x fdimf32x (_Float32x __x, _Float32x __y) noexcept (true); extern _Float32x __fdimf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32x fmaxf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fmaxf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fminf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fminf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) noexcept (true); extern _Float32x __fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) noexcept (true);
extern _Float32x roundevenf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__)); extern _Float32x __roundevenf32x (_Float32x __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxf32x (_Float32x __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizef32x (_Float32x *__cx, const _Float32x *__x) noexcept (true);
extern _Float32x fmaxmagf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fmaxmagf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fminmagf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fminmagf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fmaximumf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fmaximumf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fminimumf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fminimumf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fmaximum_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fmaximum_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fminimum_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fminimum_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fmaximum_magf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fmaximum_magf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fminimum_magf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fminimum_magf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fmaximum_mag_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fmaximum_mag_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern _Float32x fminimum_mag_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__)); extern _Float32x __fminimum_mag_numf32x (_Float32x __x, _Float32x __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderf32x (const _Float32x *__x, const _Float32x *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagf32x (const _Float32x *__x, const _Float32x *__y) noexcept (true)
     __attribute__ ((__pure__));
extern _Float32x getpayloadf32x (const _Float32x *__x) noexcept (true); extern _Float32x __getpayloadf32x (const _Float32x *__x) noexcept (true);
extern int setpayloadf32x (_Float32x *__x, _Float32x __payload) noexcept (true);
extern int setpayloadsigf32x (_Float32x *__x, _Float32x __payload) noexcept (true);
 extern _Float64x acosf64x (_Float64x __x) noexcept (true); extern _Float64x __acosf64x (_Float64x __x) noexcept (true);
 extern _Float64x asinf64x (_Float64x __x) noexcept (true); extern _Float64x __asinf64x (_Float64x __x) noexcept (true);
 extern _Float64x atanf64x (_Float64x __x) noexcept (true); extern _Float64x __atanf64x (_Float64x __x) noexcept (true);
 extern _Float64x atan2f64x (_Float64x __y, _Float64x __x) noexcept (true); extern _Float64x __atan2f64x (_Float64x __y, _Float64x __x) noexcept (true);
 extern _Float64x cosf64x (_Float64x __x) noexcept (true); extern _Float64x __cosf64x (_Float64x __x) noexcept (true);
 extern _Float64x sinf64x (_Float64x __x) noexcept (true); extern _Float64x __sinf64x (_Float64x __x) noexcept (true);
 extern _Float64x tanf64x (_Float64x __x) noexcept (true); extern _Float64x __tanf64x (_Float64x __x) noexcept (true);
 extern _Float64x coshf64x (_Float64x __x) noexcept (true); extern _Float64x __coshf64x (_Float64x __x) noexcept (true);
 extern _Float64x sinhf64x (_Float64x __x) noexcept (true); extern _Float64x __sinhf64x (_Float64x __x) noexcept (true);
 extern _Float64x tanhf64x (_Float64x __x) noexcept (true); extern _Float64x __tanhf64x (_Float64x __x) noexcept (true);
 extern void sincosf64x (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) noexcept (true); extern void __sincosf64x (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) noexcept (true);
 extern _Float64x acoshf64x (_Float64x __x) noexcept (true); extern _Float64x __acoshf64x (_Float64x __x) noexcept (true);
 extern _Float64x asinhf64x (_Float64x __x) noexcept (true); extern _Float64x __asinhf64x (_Float64x __x) noexcept (true);
 extern _Float64x atanhf64x (_Float64x __x) noexcept (true); extern _Float64x __atanhf64x (_Float64x __x) noexcept (true);
 extern _Float64x expf64x (_Float64x __x) noexcept (true); extern _Float64x __expf64x (_Float64x __x) noexcept (true);
extern _Float64x frexpf64x (_Float64x __x, int *__exponent) noexcept (true); extern _Float64x __frexpf64x (_Float64x __x, int *__exponent) noexcept (true);
extern _Float64x ldexpf64x (_Float64x __x, int __exponent) noexcept (true); extern _Float64x __ldexpf64x (_Float64x __x, int __exponent) noexcept (true);
 extern _Float64x logf64x (_Float64x __x) noexcept (true); extern _Float64x __logf64x (_Float64x __x) noexcept (true);
 extern _Float64x log10f64x (_Float64x __x) noexcept (true); extern _Float64x __log10f64x (_Float64x __x) noexcept (true);
extern _Float64x modff64x (_Float64x __x, _Float64x *__iptr) noexcept (true); extern _Float64x __modff64x (_Float64x __x, _Float64x *__iptr) noexcept (true) __attribute__ ((__nonnull__ (2)));
 extern _Float64x exp10f64x (_Float64x __x) noexcept (true); extern _Float64x __exp10f64x (_Float64x __x) noexcept (true);
 extern _Float64x expm1f64x (_Float64x __x) noexcept (true); extern _Float64x __expm1f64x (_Float64x __x) noexcept (true);
 extern _Float64x log1pf64x (_Float64x __x) noexcept (true); extern _Float64x __log1pf64x (_Float64x __x) noexcept (true);
extern _Float64x logbf64x (_Float64x __x) noexcept (true); extern _Float64x __logbf64x (_Float64x __x) noexcept (true);
 extern _Float64x exp2f64x (_Float64x __x) noexcept (true); extern _Float64x __exp2f64x (_Float64x __x) noexcept (true);
 extern _Float64x log2f64x (_Float64x __x) noexcept (true); extern _Float64x __log2f64x (_Float64x __x) noexcept (true);
 extern _Float64x powf64x (_Float64x __x, _Float64x __y) noexcept (true); extern _Float64x __powf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64x sqrtf64x (_Float64x __x) noexcept (true); extern _Float64x __sqrtf64x (_Float64x __x) noexcept (true);
 extern _Float64x hypotf64x (_Float64x __x, _Float64x __y) noexcept (true); extern _Float64x __hypotf64x (_Float64x __x, _Float64x __y) noexcept (true);
 extern _Float64x cbrtf64x (_Float64x __x) noexcept (true); extern _Float64x __cbrtf64x (_Float64x __x) noexcept (true);
extern _Float64x ceilf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__)); extern _Float64x __ceilf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__));
extern _Float64x fabsf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fabsf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__));
extern _Float64x floorf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__)); extern _Float64x __floorf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__));
extern _Float64x fmodf64x (_Float64x __x, _Float64x __y) noexcept (true); extern _Float64x __fmodf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64x copysignf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __copysignf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x nanf64x (const char *__tagb) noexcept (true); extern _Float64x __nanf64x (const char *__tagb) noexcept (true);
extern _Float64x j0f64x (_Float64x) noexcept (true); extern _Float64x __j0f64x (_Float64x) noexcept (true);
extern _Float64x j1f64x (_Float64x) noexcept (true); extern _Float64x __j1f64x (_Float64x) noexcept (true);
extern _Float64x jnf64x (int, _Float64x) noexcept (true); extern _Float64x __jnf64x (int, _Float64x) noexcept (true);
extern _Float64x y0f64x (_Float64x) noexcept (true); extern _Float64x __y0f64x (_Float64x) noexcept (true);
extern _Float64x y1f64x (_Float64x) noexcept (true); extern _Float64x __y1f64x (_Float64x) noexcept (true);
extern _Float64x ynf64x (int, _Float64x) noexcept (true); extern _Float64x __ynf64x (int, _Float64x) noexcept (true);
 extern _Float64x erff64x (_Float64x) noexcept (true); extern _Float64x __erff64x (_Float64x) noexcept (true);
 extern _Float64x erfcf64x (_Float64x) noexcept (true); extern _Float64x __erfcf64x (_Float64x) noexcept (true);
extern _Float64x lgammaf64x (_Float64x) noexcept (true); extern _Float64x __lgammaf64x (_Float64x) noexcept (true);
extern _Float64x tgammaf64x (_Float64x) noexcept (true); extern _Float64x __tgammaf64x (_Float64x) noexcept (true);
extern _Float64x lgammaf64x_r (_Float64x, int *__signgamp) noexcept (true); extern _Float64x __lgammaf64x_r (_Float64x, int *__signgamp) noexcept (true);
extern _Float64x rintf64x (_Float64x __x) noexcept (true); extern _Float64x __rintf64x (_Float64x __x) noexcept (true);
extern _Float64x nextafterf64x (_Float64x __x, _Float64x __y) noexcept (true); extern _Float64x __nextafterf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64x nextdownf64x (_Float64x __x) noexcept (true); extern _Float64x __nextdownf64x (_Float64x __x) noexcept (true);
extern _Float64x nextupf64x (_Float64x __x) noexcept (true); extern _Float64x __nextupf64x (_Float64x __x) noexcept (true);
extern _Float64x remainderf64x (_Float64x __x, _Float64x __y) noexcept (true); extern _Float64x __remainderf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64x scalbnf64x (_Float64x __x, int __n) noexcept (true); extern _Float64x __scalbnf64x (_Float64x __x, int __n) noexcept (true);
extern int ilogbf64x (_Float64x __x) noexcept (true); extern int __ilogbf64x (_Float64x __x) noexcept (true);
extern long int llogbf64x (_Float64x __x) noexcept (true); extern long int __llogbf64x (_Float64x __x) noexcept (true);
extern _Float64x scalblnf64x (_Float64x __x, long int __n) noexcept (true); extern _Float64x __scalblnf64x (_Float64x __x, long int __n) noexcept (true);
extern _Float64x nearbyintf64x (_Float64x __x) noexcept (true); extern _Float64x __nearbyintf64x (_Float64x __x) noexcept (true);
extern _Float64x roundf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__)); extern _Float64x __roundf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__));
extern _Float64x truncf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__)); extern _Float64x __truncf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__));
extern _Float64x remquof64x (_Float64x __x, _Float64x __y, int *__quo) noexcept (true); extern _Float64x __remquof64x (_Float64x __x, _Float64x __y, int *__quo) noexcept (true);
extern long int lrintf64x (_Float64x __x) noexcept (true); extern long int __lrintf64x (_Float64x __x) noexcept (true);
__extension__
extern long long int llrintf64x (_Float64x __x) noexcept (true); extern long long int __llrintf64x (_Float64x __x) noexcept (true);
extern long int lroundf64x (_Float64x __x) noexcept (true); extern long int __lroundf64x (_Float64x __x) noexcept (true);
__extension__
extern long long int llroundf64x (_Float64x __x) noexcept (true); extern long long int __llroundf64x (_Float64x __x) noexcept (true);
extern _Float64x fdimf64x (_Float64x __x, _Float64x __y) noexcept (true); extern _Float64x __fdimf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64x fmaxf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fmaxf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fminf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fminf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) noexcept (true); extern _Float64x __fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) noexcept (true);
extern _Float64x roundevenf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__)); extern _Float64x __roundevenf64x (_Float64x __x) noexcept (true) __attribute__ ((__const__));
extern __intmax_t fromfpf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true);
extern __intmax_t fromfpxf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true); extern __intmax_t __fromfpxf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true);
extern __uintmax_t ufromfpxf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true); extern __uintmax_t __ufromfpxf64x (_Float64x __x, int __round, unsigned int __width) noexcept (true);
extern int canonicalizef64x (_Float64x *__cx, const _Float64x *__x) noexcept (true);
extern _Float64x fmaxmagf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fmaxmagf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fminmagf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fminmagf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fmaximumf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fmaximumf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fminimumf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fminimumf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fmaximum_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fmaximum_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fminimum_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fminimum_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fmaximum_magf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fmaximum_magf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fminimum_magf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fminimum_magf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fmaximum_mag_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fmaximum_mag_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern _Float64x fminimum_mag_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__)); extern _Float64x __fminimum_mag_numf64x (_Float64x __x, _Float64x __y) noexcept (true) __attribute__ ((__const__));
extern int totalorderf64x (const _Float64x *__x, const _Float64x *__y) noexcept (true)
     __attribute__ ((__pure__));
extern int totalordermagf64x (const _Float64x *__x, const _Float64x *__y) noexcept (true)
     __attribute__ ((__pure__));
extern _Float64x getpayloadf64x (const _Float64x *__x) noexcept (true); extern _Float64x __getpayloadf64x (const _Float64x *__x) noexcept (true);
extern int setpayloadf64x (_Float64x *__x, _Float64x __payload) noexcept (true);
extern int setpayloadsigf64x (_Float64x *__x, _Float64x __payload) noexcept (true);
extern float fadd (double __x, double __y) noexcept (true);
extern float fdiv (double __x, double __y) noexcept (true);
extern float ffma (double __x, double __y, double __z) noexcept (true);
extern float fmul (double __x, double __y) noexcept (true);
extern float fsqrt (double __x) noexcept (true);
extern float fsub (double __x, double __y) noexcept (true);
extern float faddl (long double __x, long double __y) noexcept (true);
extern float fdivl (long double __x, long double __y) noexcept (true);
extern float ffmal (long double __x, long double __y, long double __z) noexcept (true);
extern float fmull (long double __x, long double __y) noexcept (true);
extern float fsqrtl (long double __x) noexcept (true);
extern float fsubl (long double __x, long double __y) noexcept (true);
extern double daddl (long double __x, long double __y) noexcept (true);
extern double ddivl (long double __x, long double __y) noexcept (true);
extern double dfmal (long double __x, long double __y, long double __z) noexcept (true);
extern double dmull (long double __x, long double __y) noexcept (true);
extern double dsqrtl (long double __x) noexcept (true);
extern double dsubl (long double __x, long double __y) noexcept (true);
extern _Float32 f32addf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32 f32divf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32 f32fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) noexcept (true);
extern _Float32 f32mulf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32 f32sqrtf32x (_Float32x __x) noexcept (true);
extern _Float32 f32subf32x (_Float32x __x, _Float32x __y) noexcept (true);
extern _Float32 f32addf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32 f32divf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32 f32fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) noexcept (true);
extern _Float32 f32mulf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32 f32sqrtf64 (_Float64 __x) noexcept (true);
extern _Float32 f32subf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32 f32addf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32 f32divf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32 f32fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) noexcept (true);
extern _Float32 f32mulf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32 f32sqrtf64x (_Float64x __x) noexcept (true);
extern _Float32 f32subf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32 f32addf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32 f32divf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32 f32fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) noexcept (true);
extern _Float32 f32mulf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32 f32sqrtf128 (_Float128 __x) noexcept (true);
extern _Float32 f32subf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32x f32xaddf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32x f32xdivf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32x f32xfmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) noexcept (true);
extern _Float32x f32xmulf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32x f32xsqrtf64 (_Float64 __x) noexcept (true);
extern _Float32x f32xsubf64 (_Float64 __x, _Float64 __y) noexcept (true);
extern _Float32x f32xaddf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32x f32xdivf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32x f32xfmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) noexcept (true);
extern _Float32x f32xmulf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32x f32xsqrtf64x (_Float64x __x) noexcept (true);
extern _Float32x f32xsubf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float32x f32xaddf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32x f32xdivf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32x f32xfmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) noexcept (true);
extern _Float32x f32xmulf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float32x f32xsqrtf128 (_Float128 __x) noexcept (true);
extern _Float32x f32xsubf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64 f64addf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64 f64divf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64 f64fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) noexcept (true);
extern _Float64 f64mulf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64 f64sqrtf64x (_Float64x __x) noexcept (true);
extern _Float64 f64subf64x (_Float64x __x, _Float64x __y) noexcept (true);
extern _Float64 f64addf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64 f64divf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64 f64fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) noexcept (true);
extern _Float64 f64mulf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64 f64sqrtf128 (_Float128 __x) noexcept (true);
extern _Float64 f64subf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64x f64xaddf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64x f64xdivf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64x f64xfmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) noexcept (true);
extern _Float64x f64xmulf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern _Float64x f64xsqrtf128 (_Float128 __x) noexcept (true);
extern _Float64x f64xsubf128 (_Float128 __x, _Float128 __y) noexcept (true);
extern int signgam;
enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };
extern int __iscanonicall (long double __x)
     noexcept (true) __attribute__ ((__const__));
extern "C++" {
inline int iscanonical (float __val) { return ((void) (__typeof (__val)) (__val), 1); }
inline int iscanonical (double __val) { return ((void) (__typeof (__val)) (__val), 1); }
inline int iscanonical (long double __val) { return __iscanonicall (__val); }
inline int iscanonical (_Float128 __val) { return ((void) (__typeof (__val)) (__val), 1); }
}
extern "C++" {
inline int issignaling (float __val) { return __issignalingf (__val); }
inline int issignaling (double __val) { return __issignaling (__val); }
inline int
issignaling (long double __val)
{
  return __issignalingl (__val);
}
inline int issignaling (_Float128 __val) { return __issignalingf128 (__val); }
}
extern "C++" {
template <class __T> inline bool
iszero (__T __val)
{
  return __val == 0;
}
}
extern "C++" {
template<typename> struct __iseqsig_type;
template<> struct __iseqsig_type<float>
{
  static int __call (float __x, float __y) throw ()
  {
    return __iseqsigf (__x, __y);
  }
};
template<> struct __iseqsig_type<double>
{
  static int __call (double __x, double __y) throw ()
  {
    return __iseqsig (__x, __y);
  }
};
template<> struct __iseqsig_type<long double>
{
  static int __call (long double __x, long double __y) throw ()
  {
    return __iseqsigl (__x, __y);
  }
};
template<> struct __iseqsig_type<_Float32>
{
  static int __call (_Float32 __x, _Float32 __y) throw ()
  {
    return __iseqsigf (__x, __y);
  }
};
template<> struct __iseqsig_type<_Float64>
{
  static int __call (_Float64 __x, _Float64 __y) throw ()
  {
    return __iseqsig (__x, __y);
  }
};
template<> struct __iseqsig_type<_Float128>
{
  static int __call (_Float128 __x, _Float128 __y) throw ()
  {
    return __iseqsigf128 (__x, __y);
  }
};
template<> struct __iseqsig_type<_Float32x>
{
  static int __call (_Float32x __x, _Float32x __y) throw ()
  {
    return __iseqsig (__x, __y);
  }
};
template<> struct __iseqsig_type<_Float64x>
{
  static int __call (_Float64x __x, _Float64x __y) throw ()
  {
    return __iseqsigl (__x, __y);
  }
};
template<typename _T1, typename _T2>
inline int
iseqsig (_T1 __x, _T2 __y) throw ()
{
  typedef decltype (((__x) + (__y) + 0.0L)) _T3;
  return __iseqsig_type<_T3>::__call (__x, __y);
}
}
}
       
extern "C" {
typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) noexcept (true) ;
extern double atof (const char *__nptr)
     noexcept (true) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (const char *__nptr)
     noexcept (true) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (const char *__nptr)
     noexcept (true) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (const char *__nptr)
     noexcept (true) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) noexcept (true) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern _Float32 strtof32 (const char *__restrict __nptr,
     char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern _Float64 strtof64 (const char *__restrict __nptr,
     char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern _Float128 strtof128 (const char *__restrict __nptr,
       char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern _Float32x strtof32x (const char *__restrict __nptr,
       char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern _Float64x strtof64x (const char *__restrict __nptr,
       char **__restrict __endptr)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern int strfromd (char *__dest, size_t __size, const char *__format,
       double __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfromf (char *__dest, size_t __size, const char *__format,
       float __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfroml (char *__dest, size_t __size, const char *__format,
       long double __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfromf32 (char *__dest, size_t __size, const char * __format,
         _Float32 __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfromf64 (char *__dest, size_t __size, const char * __format,
         _Float64 __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfromf128 (char *__dest, size_t __size, const char * __format,
   _Float128 __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfromf32x (char *__dest, size_t __size, const char * __format,
   _Float32x __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
extern int strfromf64x (char *__dest, size_t __size, const char * __format,
   _Float64x __f)
     noexcept (true) __attribute__ ((__nonnull__ (3)));
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern long int strtol_l (const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     locale_t __loc) noexcept (true) __attribute__ ((__nonnull__ (1, 4)));
extern unsigned long int strtoul_l (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern long long int strtoll_l (const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 4)));
extern double strtod_l (const char *__restrict __nptr,
   char **__restrict __endptr, locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern float strtof_l (const char *__restrict __nptr,
         char **__restrict __endptr, locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern long double strtold_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32 strtof32_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64 strtof64_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern _Float128 strtof128_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32x strtof32x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64x strtof64x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     noexcept (true) __attribute__ ((__nonnull__ (1, 3)));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__leaf__)) atoi (const char *__nptr) noexcept (true)
{
  return (int) strtol (__nptr, (char **) __null, 10);
}
extern __inline __attribute__ ((__gnu_inline__)) long int
__attribute__ ((__leaf__)) atol (const char *__nptr) noexcept (true)
{
  return strtol (__nptr, (char **) __null, 10);
}
__extension__ extern __inline __attribute__ ((__gnu_inline__)) long long int
__attribute__ ((__leaf__)) atoll (const char *__nptr) noexcept (true)
{
  return strtoll (__nptr, (char **) __null, 10);
}
extern char *l64a (long int __n) noexcept (true) ;
extern long int a64l (const char *__s)
     noexcept (true) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern "C" {
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __off64_t off64_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __builtin_bswap16 (__bsx);
}
static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __builtin_bswap32 (__bsx);
}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;
extern "C" {
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
}
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;
  int __kind;
  unsigned int __nusers;
  __extension__ union
  {
    struct
    {
      short __espins;
      short __eelision;
    } __elision_data;
    __pthread_slist_t __list;
  };
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  unsigned char __flags;
  unsigned char __shared;
  signed char __rwelision;
  unsigned char __pad2;
  int __cur_writer;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data ;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[36];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
}
extern long int random (void) noexcept (true);
extern void srandom (unsigned int __seed) noexcept (true);
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) noexcept (true) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) noexcept (true) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     noexcept (true) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     noexcept (true) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) noexcept (true);
extern void srand (unsigned int __seed) noexcept (true);
extern int rand_r (unsigned int *__seed) noexcept (true);
extern double drand48 (void) noexcept (true);
extern double erand48 (unsigned short int __xsubi[3]) noexcept (true) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) noexcept (true);
extern long int nrand48 (unsigned short int __xsubi[3])
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) noexcept (true);
extern long int jrand48 (unsigned short int __xsubi[3])
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) noexcept (true);
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) noexcept (true) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     noexcept (true) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2)));
extern __uint32_t arc4random (void)
     noexcept (true) ;
extern void arc4random_buf (void *__buf, size_t __size)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     noexcept (true) ;
extern void *malloc (size_t __size) noexcept (true) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern void *calloc (size_t __nmemb, size_t __size)
     noexcept (true) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;
extern void *realloc (void *__ptr, size_t __size)
     noexcept (true) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));
extern void free (void *__ptr) noexcept (true);
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     noexcept (true) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     noexcept (true) __attribute__ ((__malloc__ (reallocarray, 1)));
extern "C" {
extern void *alloca (size_t __size) noexcept (true);
}
extern void *valloc (size_t __size) noexcept (true) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     noexcept (true) __attribute__ ((__nonnull__ (1))) ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
     noexcept (true) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;
extern void abort (void) noexcept (true) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) noexcept (true) __attribute__ ((__nonnull__ (1)));
extern "C++" int at_quick_exit (void (*__func) (void))
     noexcept (true) __asm ("at_quick_exit") __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) noexcept (true) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) noexcept (true) __attribute__ ((__noreturn__));
extern void _Exit (int __status) noexcept (true) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) noexcept (true) __attribute__ ((__nonnull__ (1))) ;
extern char *secure_getenv (const char *__name)
     noexcept (true) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) noexcept (true) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     noexcept (true) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) noexcept (true) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) noexcept (true);
extern char *mktemp (char *__template) noexcept (true) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) noexcept (true) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *canonicalize_file_name (const char *__name)
     noexcept (true) __attribute__ ((__nonnull__ (1))) __attribute__ ((__malloc__))
     __attribute__ ((__malloc__ (__builtin_free, 1))) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) noexcept (true) ;
typedef int (*__compar_fn_t) (const void *, const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t) (const void *, const void *, void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern __inline __attribute__ ((__gnu_inline__)) void *
bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size,
  __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;
      __p = (const void *) (((const char *) __base) + (__idx * __size));
      __comparison = (*__compar) (__key, __p);
      if (__comparison < 0)
 __u = __idx;
      else if (__comparison > 0)
 __l = __idx + 1;
      else
 {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
   return (void *) __p;
#pragma GCC diagnostic pop
 }
    }
  return __null;
}
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) noexcept (true) __attribute__ ((__const__)) ;
extern long int labs (long int __x) noexcept (true) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     noexcept (true) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     noexcept (true) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     noexcept (true) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     noexcept (true) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) noexcept (true) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) noexcept (true) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     noexcept (true) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     noexcept (true) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     noexcept (true) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     noexcept (true) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) noexcept (true) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) noexcept (true) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     noexcept (true) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     noexcept (true) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) noexcept (true);
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) noexcept (true);
extern int wctomb (char *__s, wchar_t __wchar) noexcept (true);
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) noexcept (true)
    __attribute__ ((__access__ (__read_only__, 2)));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     noexcept (true)
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));
extern int rpmatch (const char *__response) noexcept (true) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     noexcept (true) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int posix_openpt (int __oflag) ;
extern int grantpt (int __fd) noexcept (true);
extern int unlockpt (int __fd) noexcept (true);
extern char *ptsname (int __fd) noexcept (true) ;
extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     noexcept (true) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int getpt (void);
extern int getloadavg (double __loadavg[], int __nelem)
     noexcept (true) __attribute__ ((__nonnull__ (1)));
extern __inline __attribute__ ((__gnu_inline__)) double
__attribute__ ((__leaf__)) atof (const char *__nptr) noexcept (true)
{
  return strtod (__nptr, (char **) __null);
}
}
extern "C++"
{
namespace std __attribute__ ((__visibility__ ("default")))
{

  using ::abs;
  inline long
  abs(long __i) { return __builtin_labs(__i); }
  inline long long
  abs(long long __x) { return __builtin_llabs (__x); }
  inline constexpr double
  abs(double __x)
  { return __builtin_fabs(__x); }
  inline constexpr float
  abs(float __x)
  { return __builtin_fabsf(__x); }
  inline constexpr long double
  abs(long double __x)
  { return __builtin_fabsl(__x); }

}
}
extern "C++"
{
namespace std __attribute__ ((__visibility__ ("default")))
{

  using ::acos;
  inline constexpr float
  acos(float __x)
  { return __builtin_acosf(__x); }
  inline constexpr long double
  acos(long double __x)
  { return __builtin_acosl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    acos(_Tp __x)
    { return __builtin_acos(__x); }
  using ::asin;
  inline constexpr float
  asin(float __x)
  { return __builtin_asinf(__x); }
  inline constexpr long double
  asin(long double __x)
  { return __builtin_asinl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    asin(_Tp __x)
    { return __builtin_asin(__x); }
  using ::atan;
  inline constexpr float
  atan(float __x)
  { return __builtin_atanf(__x); }
  inline constexpr long double
  atan(long double __x)
  { return __builtin_atanl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    atan(_Tp __x)
    { return __builtin_atan(__x); }
  using ::atan2;
  inline constexpr float
  atan2(float __y, float __x)
  { return __builtin_atan2f(__y, __x); }
  inline constexpr long double
  atan2(long double __y, long double __x)
  { return __builtin_atan2l(__y, __x); }
  using ::ceil;
  inline constexpr float
  ceil(float __x)
  { return __builtin_ceilf(__x); }
  inline constexpr long double
  ceil(long double __x)
  { return __builtin_ceill(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    ceil(_Tp __x)
    { return __builtin_ceil(__x); }
  using ::cos;
  inline constexpr float
  cos(float __x)
  { return __builtin_cosf(__x); }
  inline constexpr long double
  cos(long double __x)
  { return __builtin_cosl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    cos(_Tp __x)
    { return __builtin_cos(__x); }
  using ::cosh;
  inline constexpr float
  cosh(float __x)
  { return __builtin_coshf(__x); }
  inline constexpr long double
  cosh(long double __x)
  { return __builtin_coshl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    cosh(_Tp __x)
    { return __builtin_cosh(__x); }
  using ::exp;
  inline constexpr float
  exp(float __x)
  { return __builtin_expf(__x); }
  inline constexpr long double
  exp(long double __x)
  { return __builtin_expl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    exp(_Tp __x)
    { return __builtin_exp(__x); }
  using ::fabs;
  inline constexpr float
  fabs(float __x)
  { return __builtin_fabsf(__x); }
  inline constexpr long double
  fabs(long double __x)
  { return __builtin_fabsl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    fabs(_Tp __x)
    { return __builtin_fabs(__x); }
  using ::floor;
  inline constexpr float
  floor(float __x)
  { return __builtin_floorf(__x); }
  inline constexpr long double
  floor(long double __x)
  { return __builtin_floorl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    floor(_Tp __x)
    { return __builtin_floor(__x); }
  using ::fmod;
  inline constexpr float
  fmod(float __x, float __y)
  { return __builtin_fmodf(__x, __y); }
  inline constexpr long double
  fmod(long double __x, long double __y)
  { return __builtin_fmodl(__x, __y); }
  using ::frexp;
  inline float
  frexp(float __x, int* __exp)
  { return __builtin_frexpf(__x, __exp); }
  inline long double
  frexp(long double __x, int* __exp)
  { return __builtin_frexpl(__x, __exp); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    frexp(_Tp __x, int* __exp)
    { return __builtin_frexp(__x, __exp); }
  using ::ldexp;
  inline constexpr float
  ldexp(float __x, int __exp)
  { return __builtin_ldexpf(__x, __exp); }
  inline constexpr long double
  ldexp(long double __x, int __exp)
  { return __builtin_ldexpl(__x, __exp); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    ldexp(_Tp __x, int __exp)
    { return __builtin_ldexp(__x, __exp); }
  using ::log;
  inline constexpr float
  log(float __x)
  { return __builtin_logf(__x); }
  inline constexpr long double
  log(long double __x)
  { return __builtin_logl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    log(_Tp __x)
    { return __builtin_log(__x); }
  using ::log10;
  inline constexpr float
  log10(float __x)
  { return __builtin_log10f(__x); }
  inline constexpr long double
  log10(long double __x)
  { return __builtin_log10l(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    log10(_Tp __x)
    { return __builtin_log10(__x); }
  using ::modf;
  inline float
  modf(float __x, float* __iptr)
  { return __builtin_modff(__x, __iptr); }
  inline long double
  modf(long double __x, long double* __iptr)
  { return __builtin_modfl(__x, __iptr); }
  using ::pow;
  inline constexpr float
  pow(float __x, float __y)
  { return __builtin_powf(__x, __y); }
  inline constexpr long double
  pow(long double __x, long double __y)
  { return __builtin_powl(__x, __y); }
  using ::sin;
  inline constexpr float
  sin(float __x)
  { return __builtin_sinf(__x); }
  inline constexpr long double
  sin(long double __x)
  { return __builtin_sinl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    sin(_Tp __x)
    { return __builtin_sin(__x); }
  using ::sinh;
  inline constexpr float
  sinh(float __x)
  { return __builtin_sinhf(__x); }
  inline constexpr long double
  sinh(long double __x)
  { return __builtin_sinhl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    sinh(_Tp __x)
    { return __builtin_sinh(__x); }
  using ::sqrt;
  inline constexpr float
  sqrt(float __x)
  { return __builtin_sqrtf(__x); }
  inline constexpr long double
  sqrt(long double __x)
  { return __builtin_sqrtl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    sqrt(_Tp __x)
    { return __builtin_sqrt(__x); }
  using ::tan;
  inline constexpr float
  tan(float __x)
  { return __builtin_tanf(__x); }
  inline constexpr long double
  tan(long double __x)
  { return __builtin_tanl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    tan(_Tp __x)
    { return __builtin_tan(__x); }
  using ::tanh;
  inline constexpr float
  tanh(float __x)
  { return __builtin_tanhf(__x); }
  inline constexpr long double
  tanh(long double __x)
  { return __builtin_tanhl(__x); }
  template<typename _Tp>
    inline constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    tanh(_Tp __x)
    { return __builtin_tanh(__x); }
  template<typename _Tp, typename _Up>
    inline constexpr
    typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    atan2(_Tp __y, _Up __x)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return atan2(__type(__y), __type(__x));
    }
  template<typename _Tp, typename _Up>
    inline constexpr
    typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fmod(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fmod(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    inline constexpr
    typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    pow(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return pow(__type(__x), __type(__y));
    }
  constexpr int
  fpclassify(float __x)
  { return __builtin_fpclassify(0, 1, 4,
    3, 2, __x); }
  constexpr int
  fpclassify(double __x)
  { return __builtin_fpclassify(0, 1, 4,
    3, 2, __x); }
  constexpr int
  fpclassify(long double __x)
  { return __builtin_fpclassify(0, 1, 4,
    3, 2, __x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              int>::__type
    fpclassify(_Tp __x)
    { return __x != 0 ? 4 : 2; }
  constexpr bool
  isfinite(float __x)
  { return __builtin_isfinite(__x); }
  constexpr bool
  isfinite(double __x)
  { return __builtin_isfinite(__x); }
  constexpr bool
  isfinite(long double __x)
  { return __builtin_isfinite(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isfinite(_Tp __x)
    { return true; }
  constexpr bool
  isinf(float __x)
  { return __builtin_isinf(__x); }
  constexpr bool
  isinf(double __x)
  { return __builtin_isinf(__x); }
  constexpr bool
  isinf(long double __x)
  { return __builtin_isinf(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isinf(_Tp __x)
    { return false; }
  constexpr bool
  isnan(float __x)
  { return __builtin_isnan(__x); }
  constexpr bool
  isnan(double __x)
  { return __builtin_isnan(__x); }
  constexpr bool
  isnan(long double __x)
  { return __builtin_isnan(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isnan(_Tp __x)
    { return false; }
  constexpr bool
  isnormal(float __x)
  { return __builtin_isnormal(__x); }
  constexpr bool
  isnormal(double __x)
  { return __builtin_isnormal(__x); }
  constexpr bool
  isnormal(long double __x)
  { return __builtin_isnormal(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isnormal(_Tp __x)
    { return __x != 0 ? true : false; }
  constexpr bool
  signbit(float __x)
  { return __builtin_signbit(__x); }
  constexpr bool
  signbit(double __x)
  { return __builtin_signbit(__x); }
  constexpr bool
  signbit(long double __x)
  { return __builtin_signbit(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    signbit(_Tp __x)
    { return __x < 0 ? true : false; }
  constexpr bool
  isgreater(float __x, float __y)
  { return __builtin_isgreater(__x, __y); }
  constexpr bool
  isgreater(double __x, double __y)
  { return __builtin_isgreater(__x, __y); }
  constexpr bool
  isgreater(long double __x, long double __y)
  { return __builtin_isgreater(__x, __y); }
  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
       && __is_arithmetic<_Up>::__value), bool>::__type
    isgreater(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isgreater(__type(__x), __type(__y));
    }
  constexpr bool
  isgreaterequal(float __x, float __y)
  { return __builtin_isgreaterequal(__x, __y); }
  constexpr bool
  isgreaterequal(double __x, double __y)
  { return __builtin_isgreaterequal(__x, __y); }
  constexpr bool
  isgreaterequal(long double __x, long double __y)
  { return __builtin_isgreaterequal(__x, __y); }
  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
       && __is_arithmetic<_Up>::__value), bool>::__type
    isgreaterequal(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isgreaterequal(__type(__x), __type(__y));
    }
  constexpr bool
  isless(float __x, float __y)
  { return __builtin_isless(__x, __y); }
  constexpr bool
  isless(double __x, double __y)
  { return __builtin_isless(__x, __y); }
  constexpr bool
  isless(long double __x, long double __y)
  { return __builtin_isless(__x, __y); }
  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
       && __is_arithmetic<_Up>::__value), bool>::__type
    isless(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isless(__type(__x), __type(__y));
    }
  constexpr bool
  islessequal(float __x, float __y)
  { return __builtin_islessequal(__x, __y); }
  constexpr bool
  islessequal(double __x, double __y)
  { return __builtin_islessequal(__x, __y); }
  constexpr bool
  islessequal(long double __x, long double __y)
  { return __builtin_islessequal(__x, __y); }
  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
       && __is_arithmetic<_Up>::__value), bool>::__type
    islessequal(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_islessequal(__type(__x), __type(__y));
    }
  constexpr bool
  islessgreater(float __x, float __y)
  { return __builtin_islessgreater(__x, __y); }
  constexpr bool
  islessgreater(double __x, double __y)
  { return __builtin_islessgreater(__x, __y); }
  constexpr bool
  islessgreater(long double __x, long double __y)
  { return __builtin_islessgreater(__x, __y); }
  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
       && __is_arithmetic<_Up>::__value), bool>::__type
    islessgreater(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_islessgreater(__type(__x), __type(__y));
    }
  constexpr bool
  isunordered(float __x, float __y)
  { return __builtin_isunordered(__x, __y); }
  constexpr bool
  isunordered(double __x, double __y)
  { return __builtin_isunordered(__x, __y); }
  constexpr bool
  isunordered(long double __x, long double __y)
  { return __builtin_isunordered(__x, __y); }
  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
       && __is_arithmetic<_Up>::__value), bool>::__type
    isunordered(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isunordered(__type(__x), __type(__y));
    }
  using ::double_t;
  using ::float_t;
  using ::acosh;
  using ::acoshf;
  using ::acoshl;
  using ::asinh;
  using ::asinhf;
  using ::asinhl;
  using ::atanh;
  using ::atanhf;
  using ::atanhl;
  using ::cbrt;
  using ::cbrtf;
  using ::cbrtl;
  using ::copysign;
  using ::copysignf;
  using ::copysignl;
  using ::erf;
  using ::erff;
  using ::erfl;
  using ::erfc;
  using ::erfcf;
  using ::erfcl;
  using ::exp2;
  using ::exp2f;
  using ::exp2l;
  using ::expm1;
  using ::expm1f;
  using ::expm1l;
  using ::fdim;
  using ::fdimf;
  using ::fdiml;
  using ::fma;
  using ::fmaf;
  using ::fmal;
  using ::fmax;
  using ::fmaxf;
  using ::fmaxl;
  using ::fmin;
  using ::fminf;
  using ::fminl;
  using ::hypot;
  using ::hypotf;
  using ::hypotl;
  using ::ilogb;
  using ::ilogbf;
  using ::ilogbl;
  using ::lgamma;
  using ::lgammaf;
  using ::lgammal;
  using ::llrint;
  using ::llrintf;
  using ::llrintl;
  using ::llround;
  using ::llroundf;
  using ::llroundl;
  using ::log1p;
  using ::log1pf;
  using ::log1pl;
  using ::log2;
  using ::log2f;
  using ::log2l;
  using ::logb;
  using ::logbf;
  using ::logbl;
  using ::lrint;
  using ::lrintf;
  using ::lrintl;
  using ::lround;
  using ::lroundf;
  using ::lroundl;
  using ::nan;
  using ::nanf;
  using ::nanl;
  using ::nearbyint;
  using ::nearbyintf;
  using ::nearbyintl;
  using ::nextafter;
  using ::nextafterf;
  using ::nextafterl;
  using ::nexttoward;
  using ::nexttowardf;
  using ::nexttowardl;
  using ::remainder;
  using ::remainderf;
  using ::remainderl;
  using ::remquo;
  using ::remquof;
  using ::remquol;
  using ::rint;
  using ::rintf;
  using ::rintl;
  using ::round;
  using ::roundf;
  using ::roundl;
  using ::scalbln;
  using ::scalblnf;
  using ::scalblnl;
  using ::scalbn;
  using ::scalbnf;
  using ::scalbnl;
  using ::tgamma;
  using ::tgammaf;
  using ::tgammal;
  using ::trunc;
  using ::truncf;
  using ::truncl;
  constexpr float
  acosh(float __x)
  { return __builtin_acoshf(__x); }
  constexpr long double
  acosh(long double __x)
  { return __builtin_acoshl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    acosh(_Tp __x)
    { return __builtin_acosh(__x); }
  constexpr float
  asinh(float __x)
  { return __builtin_asinhf(__x); }
  constexpr long double
  asinh(long double __x)
  { return __builtin_asinhl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    asinh(_Tp __x)
    { return __builtin_asinh(__x); }
  constexpr float
  atanh(float __x)
  { return __builtin_atanhf(__x); }
  constexpr long double
  atanh(long double __x)
  { return __builtin_atanhl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    atanh(_Tp __x)
    { return __builtin_atanh(__x); }
  constexpr float
  cbrt(float __x)
  { return __builtin_cbrtf(__x); }
  constexpr long double
  cbrt(long double __x)
  { return __builtin_cbrtl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    cbrt(_Tp __x)
    { return __builtin_cbrt(__x); }
  constexpr float
  copysign(float __x, float __y)
  { return __builtin_copysignf(__x, __y); }
  constexpr long double
  copysign(long double __x, long double __y)
  { return __builtin_copysignl(__x, __y); }
  constexpr float
  erf(float __x)
  { return __builtin_erff(__x); }
  constexpr long double
  erf(long double __x)
  { return __builtin_erfl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    erf(_Tp __x)
    { return __builtin_erf(__x); }
  constexpr float
  erfc(float __x)
  { return __builtin_erfcf(__x); }
  constexpr long double
  erfc(long double __x)
  { return __builtin_erfcl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    erfc(_Tp __x)
    { return __builtin_erfc(__x); }
  constexpr float
  exp2(float __x)
  { return __builtin_exp2f(__x); }
  constexpr long double
  exp2(long double __x)
  { return __builtin_exp2l(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    exp2(_Tp __x)
    { return __builtin_exp2(__x); }
  constexpr float
  expm1(float __x)
  { return __builtin_expm1f(__x); }
  constexpr long double
  expm1(long double __x)
  { return __builtin_expm1l(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    expm1(_Tp __x)
    { return __builtin_expm1(__x); }
  constexpr float
  fdim(float __x, float __y)
  { return __builtin_fdimf(__x, __y); }
  constexpr long double
  fdim(long double __x, long double __y)
  { return __builtin_fdiml(__x, __y); }
  constexpr float
  fma(float __x, float __y, float __z)
  { return __builtin_fmaf(__x, __y, __z); }
  constexpr long double
  fma(long double __x, long double __y, long double __z)
  { return __builtin_fmal(__x, __y, __z); }
  constexpr float
  fmax(float __x, float __y)
  { return __builtin_fmaxf(__x, __y); }
  constexpr long double
  fmax(long double __x, long double __y)
  { return __builtin_fmaxl(__x, __y); }
  constexpr float
  fmin(float __x, float __y)
  { return __builtin_fminf(__x, __y); }
  constexpr long double
  fmin(long double __x, long double __y)
  { return __builtin_fminl(__x, __y); }
  constexpr float
  hypot(float __x, float __y)
  { return __builtin_hypotf(__x, __y); }
  constexpr long double
  hypot(long double __x, long double __y)
  { return __builtin_hypotl(__x, __y); }
  constexpr int
  ilogb(float __x)
  { return __builtin_ilogbf(__x); }
  constexpr int
  ilogb(long double __x)
  { return __builtin_ilogbl(__x); }
  template<typename _Tp>
    constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    int>::__type
    ilogb(_Tp __x)
    { return __builtin_ilogb(__x); }
  constexpr float
  lgamma(float __x)
  { return __builtin_lgammaf(__x); }
  constexpr long double
  lgamma(long double __x)
  { return __builtin_lgammal(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    lgamma(_Tp __x)
    { return __builtin_lgamma(__x); }
  constexpr long long
  llrint(float __x)
  { return __builtin_llrintf(__x); }
  constexpr long long
  llrint(long double __x)
  { return __builtin_llrintl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              long long>::__type
    llrint(_Tp __x)
    { return __builtin_llrint(__x); }
  constexpr long long
  llround(float __x)
  { return __builtin_llroundf(__x); }
  constexpr long long
  llround(long double __x)
  { return __builtin_llroundl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              long long>::__type
    llround(_Tp __x)
    { return __builtin_llround(__x); }
  constexpr float
  log1p(float __x)
  { return __builtin_log1pf(__x); }
  constexpr long double
  log1p(long double __x)
  { return __builtin_log1pl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    log1p(_Tp __x)
    { return __builtin_log1p(__x); }
  constexpr float
  log2(float __x)
  { return __builtin_log2f(__x); }
  constexpr long double
  log2(long double __x)
  { return __builtin_log2l(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    log2(_Tp __x)
    { return __builtin_log2(__x); }
  constexpr float
  logb(float __x)
  { return __builtin_logbf(__x); }
  constexpr long double
  logb(long double __x)
  { return __builtin_logbl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    logb(_Tp __x)
    { return __builtin_logb(__x); }
  constexpr long
  lrint(float __x)
  { return __builtin_lrintf(__x); }
  constexpr long
  lrint(long double __x)
  { return __builtin_lrintl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              long>::__type
    lrint(_Tp __x)
    { return __builtin_lrint(__x); }
  constexpr long
  lround(float __x)
  { return __builtin_lroundf(__x); }
  constexpr long
  lround(long double __x)
  { return __builtin_lroundl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              long>::__type
    lround(_Tp __x)
    { return __builtin_lround(__x); }
  constexpr float
  nearbyint(float __x)
  { return __builtin_nearbyintf(__x); }
  constexpr long double
  nearbyint(long double __x)
  { return __builtin_nearbyintl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    nearbyint(_Tp __x)
    { return __builtin_nearbyint(__x); }
  constexpr float
  nextafter(float __x, float __y)
  { return __builtin_nextafterf(__x, __y); }
  constexpr long double
  nextafter(long double __x, long double __y)
  { return __builtin_nextafterl(__x, __y); }
  constexpr float
  nexttoward(float __x, long double __y)
  { return __builtin_nexttowardf(__x, __y); }
  constexpr long double
  nexttoward(long double __x, long double __y)
  { return __builtin_nexttowardl(__x, __y); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    nexttoward(_Tp __x, long double __y)
    { return __builtin_nexttoward(__x, __y); }
  constexpr float
  remainder(float __x, float __y)
  { return __builtin_remainderf(__x, __y); }
  constexpr long double
  remainder(long double __x, long double __y)
  { return __builtin_remainderl(__x, __y); }
  inline float
  remquo(float __x, float __y, int* __pquo)
  { return __builtin_remquof(__x, __y, __pquo); }
  inline long double
  remquo(long double __x, long double __y, int* __pquo)
  { return __builtin_remquol(__x, __y, __pquo); }
  constexpr float
  rint(float __x)
  { return __builtin_rintf(__x); }
  constexpr long double
  rint(long double __x)
  { return __builtin_rintl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    rint(_Tp __x)
    { return __builtin_rint(__x); }
  constexpr float
  round(float __x)
  { return __builtin_roundf(__x); }
  constexpr long double
  round(long double __x)
  { return __builtin_roundl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    round(_Tp __x)
    { return __builtin_round(__x); }
  constexpr float
  scalbln(float __x, long __ex)
  { return __builtin_scalblnf(__x, __ex); }
  constexpr long double
  scalbln(long double __x, long __ex)
  { return __builtin_scalblnl(__x, __ex); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    scalbln(_Tp __x, long __ex)
    { return __builtin_scalbln(__x, __ex); }
  constexpr float
  scalbn(float __x, int __ex)
  { return __builtin_scalbnf(__x, __ex); }
  constexpr long double
  scalbn(long double __x, int __ex)
  { return __builtin_scalbnl(__x, __ex); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    scalbn(_Tp __x, int __ex)
    { return __builtin_scalbn(__x, __ex); }
  constexpr float
  tgamma(float __x)
  { return __builtin_tgammaf(__x); }
  constexpr long double
  tgamma(long double __x)
  { return __builtin_tgammal(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    tgamma(_Tp __x)
    { return __builtin_tgamma(__x); }
  constexpr float
  trunc(float __x)
  { return __builtin_truncf(__x); }
  constexpr long double
  trunc(long double __x)
  { return __builtin_truncl(__x); }
  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              double>::__type
    trunc(_Tp __x)
    { return __builtin_trunc(__x); }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    copysign(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return copysign(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fdim(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fdim(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fmax(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fmax(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fmin(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fmin(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    hypot(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return hypot(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    nextafter(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return nextafter(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    remainder(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return remainder(__type(__x), __type(__y));
    }
  template<typename _Tp, typename _Up>
    inline typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    remquo(_Tp __x, _Up __y, int* __pquo)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return remquo(__type(__x), __type(__y), __pquo);
    }
  template<typename _Tp, typename _Up, typename _Vp>
    constexpr typename __gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type
    fma(_Tp __x, _Up __y, _Vp __z)
    {
      typedef typename __gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type __type;
      return fma(__type(__x), __type(__y), __type(__z));
    }

}
}
       
using std::abs;
using std::acos;
using std::asin;
using std::atan;
using std::atan2;
using std::cos;
using std::sin;
using std::tan;
using std::cosh;
using std::sinh;
using std::tanh;
using std::exp;
using std::frexp;
using std::ldexp;
using std::log;
using std::log10;
using std::modf;
using std::pow;
using std::sqrt;
using std::ceil;
using std::fabs;
using std::floor;
using std::fmod;
using std::fpclassify;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::signbit;
using std::isgreater;
using std::isgreaterequal;
using std::isless;
using std::islessequal;
using std::islessgreater;
using std::isunordered;
using std::acosh;
using std::asinh;
using std::atanh;
using std::cbrt;
using std::copysign;
using std::erf;
using std::erfc;
using std::exp2;
using std::expm1;
using std::fdim;
using std::fma;
using std::fmax;
using std::fmin;
using std::hypot;
using std::ilogb;
using std::lgamma;
using std::llrint;
using std::llround;
using std::log1p;
using std::log2;
using std::logb;
using std::lrint;
using std::lround;
using std::nearbyint;
using std::nextafter;
using std::nexttoward;
using std::remainder;
using std::remquo;
using std::rint;
using std::round;
using std::scalbln;
using std::scalbn;
using std::tgamma;
using std::trunc;
static_assert(true, "For requiring trailing semicolon");
namespace hwy {
namespace N_EMU128 {
template <class V>
using VecArg = V;
namespace detail {
constexpr size_t ScaleByPower(size_t N, int pow2) {
  return pow2 >= 0 ? (N << pow2) : (N >> (-pow2));
}
}
template <typename Lane, size_t N, int kPow2>
struct Simd {
  constexpr Simd() = default;
  using T = Lane;
 private:
  static_assert(sizeof(Lane) <= 8, "Lanes are up to 64-bit");
  static constexpr size_t kWhole = N & 0xFFFFF;
  static constexpr int kFrac = static_cast<int>(N >> 20);
  static_assert(kWhole <= 8 * 65536 && kFrac <= 3, "Out of range");
  static_assert(kFrac == 0 || kWhole == 1, "If frac, whole must be 1");
  static_assert((kWhole & (kWhole - 1)) == 0 && kWhole != 0, "Not 2^x");
  static_assert(kPow2 >= -8, "Forgot kPow2 recursion terminator?");
 public:
  static constexpr size_t kPrivateLanes =
      ((size_t{1}) > (detail::ScaleByPower(kWhole, kPow2 - kFrac)) ? (size_t{1}) : (detail::ScaleByPower(kWhole, kPow2 - kFrac)));
  constexpr size_t MaxLanes() const { return kPrivateLanes; }
  constexpr size_t MaxBytes() const { return kPrivateLanes * sizeof(Lane); }
  constexpr int Pow2() const { return kPow2; }
  template <typename NewT>
  static constexpr size_t RepartitionLanes() {
    return (kPrivateLanes * sizeof(T) + sizeof(NewT) - 1) / sizeof(NewT);
  }
  template <typename NewT>
  static constexpr int RebindPow2() {
    return kPow2 +
           ((sizeof(NewT) >= sizeof(T))
                ? static_cast<int>(CeilLog2(sizeof(NewT) / sizeof(T)))
                : -static_cast<int>(CeilLog2(sizeof(T) / sizeof(NewT))));
  }
 private:
  template <int kNewPow2, size_t kNewMaxLanes>
  static constexpr size_t WholeN() {
    return detail::ScaleByPower(kNewMaxLanes, -kNewPow2);
  }
  template <int kNewPow2, size_t kNewMaxLanes>
  static constexpr size_t FracN() {
    static_assert(65536 <= (size_t{1} << 20), "Change bit shift");
    return static_cast<size_t>(
        1 + (((0) > (kNewPow2 - static_cast<int>(CeilLog2(kNewMaxLanes))) ? (0) : (kNewPow2 - static_cast<int>(CeilLog2(kNewMaxLanes))))
             << 20));
  }
 public:
  template <int kNewPow2, size_t kNewMaxLanes>
  static constexpr size_t NewN() {
    return WholeN<kNewPow2, kNewMaxLanes>() == 0
               ? FracN<kNewPow2, kNewMaxLanes>()
               : WholeN<kNewPow2, kNewMaxLanes>();
  }
  template <typename NewT>
  using Rebind =
      Simd<NewT, NewN<RebindPow2<NewT>(), kPrivateLanes>(), RebindPow2<NewT>()>;
  template <typename NewT>
  using Repartition =
      Simd<NewT, NewN<kPow2, RepartitionLanes<NewT>()>(), kPow2>;
  using Half = Simd<T, N, kPow2 - 1>;
  using Twice = Simd<T, N, kPow2 + 1>;
};
namespace detail {
template <typename T, size_t N, int kPow2>
constexpr bool IsFull(Simd<T, N, kPow2> ) {
  return N == (16 / sizeof(T)) && kPow2 == 0;
}
template <typename T, size_t N, int kPow2>
struct ClampNAndPow2 {
  using type = Simd<T, ((N) < (65536) ? (N) : (65536)), ((kPow2) < (3) ? (kPow2) : (3))>;
};
template <typename T, int kPow2>
struct ScalableTagChecker {
  using type = typename ClampNAndPow2<T, (16 / sizeof(T)), kPow2>::type;
};
template <typename T, size_t kLimit, int kPow2>
struct CappedTagChecker {
  static_assert(kLimit != 0, "Does not make sense to have zero lanes");
  static constexpr size_t kLimitPow2 = size_t{1} << hwy::FloorLog2(kLimit);
  static constexpr size_t N = ((kLimitPow2) < ((16 / sizeof(T))) ? (kLimitPow2) : ((16 / sizeof(T))));
  using type = typename ClampNAndPow2<T, N, kPow2>::type;
};
template <typename T, size_t kNumLanes>
struct FixedTagChecker {
  static_assert(kNumLanes != 0, "Does not make sense to have zero lanes");
  static_assert(kNumLanes <= (16 / sizeof(T)), "Too many lanes");
  using type = Simd<T, kNumLanes, 0>;
};
}
template <typename T, int kPow2 = 0>
using ScalableTag = typename detail::ScalableTagChecker<T, kPow2>::type;
template <typename T, size_t kLimit, int kPow2 = 0>
using CappedTag = typename detail::CappedTagChecker<T, kLimit, kPow2>::type;
template <typename T, size_t kNumLanes>
using FixedTag = typename detail::FixedTagChecker<T, kNumLanes>::type;
template <typename T>
using Full16 = Simd<T, 2 / sizeof(T), 0>;
template <typename T>
using Full32 = Simd<T, 4 / sizeof(T), 0>;
template <typename T>
using Full64 = Simd<T, 8 / sizeof(T), 0>;
template <typename T>
using Full128 = Simd<T, 16 / sizeof(T), 0>;
template <class D>
using TFromD = typename D::T;
template <class D>
inline __attribute__((always_inline)) __attribute__((unused)) constexpr size_t MaxLanes(D) {
  return D::kPrivateLanes;
}
template <class D>
inline __attribute__((always_inline)) __attribute__((unused)) constexpr size_t Lanes(D) {
  return D::kPrivateLanes;
}
template <class T, class D>
using Rebind = typename D::template Rebind<T>;
template <class D>
using RebindToSigned = Rebind<MakeSigned<TFromD<D>>, D>;
template <class D>
using RebindToUnsigned = Rebind<MakeUnsigned<TFromD<D>>, D>;
template <class D>
using RebindToFloat = Rebind<MakeFloat<TFromD<D>>, D>;
template <class T, class D>
using Repartition = typename D::template Repartition<T>;
template <class D>
using RepartitionToWide = Repartition<MakeWide<TFromD<D>>, D>;
template <class D>
using RepartitionToNarrow = Repartition<MakeNarrow<TFromD<D>>, D>;
template <class D>
using Half = typename D::Half;
template <class D>
using Twice = typename D::Twice;
}
}
static_assert(true, "For requiring trailing semicolon");
static_assert(true, "For requiring trailing semicolon");
namespace hwy {
namespace N_EMU128 {
template <typename T>
using Full128 = Simd<T, 16 / sizeof(T), 0>;
template <typename T, size_t N = 16 / sizeof(T)>
struct Vec128 {
  using PrivateT = T;
  static constexpr size_t kPrivateN = N;
  inline __attribute__((always_inline)) Vec128() = default;
  Vec128(const Vec128&) = default;
  Vec128& operator=(const Vec128&) = default;
  inline __attribute__((always_inline)) Vec128& operator*=(const Vec128 other) {
    return *this = (*this * other);
  }
  inline __attribute__((always_inline)) Vec128& operator/=(const Vec128 other) {
    return *this = (*this / other);
  }
  inline __attribute__((always_inline)) Vec128& operator+=(const Vec128 other) {
    return *this = (*this + other);
  }
  inline __attribute__((always_inline)) Vec128& operator-=(const Vec128 other) {
    return *this = (*this - other);
  }
  inline __attribute__((always_inline)) Vec128& operator&=(const Vec128 other) {
    return *this = (*this & other);
  }
  inline __attribute__((always_inline)) Vec128& operator|=(const Vec128 other) {
    return *this = (*this | other);
  }
  inline __attribute__((always_inline)) Vec128& operator^=(const Vec128 other) {
    return *this = (*this ^ other);
  }
  T raw[16 / sizeof(T)] = {};
};
template <typename T, size_t N = 16 / sizeof(T)>
struct Mask128 {
  using Raw = hwy::MakeUnsigned<T>;
  static inline __attribute__((always_inline)) Raw FromBool(bool b) {
    return b ? static_cast<Raw>(~Raw{0}) : 0;
  }
  Raw bits[16 / sizeof(T)] = {};
};
template <class V>
using DFromV = Simd<typename V::PrivateT, V::kPrivateN, 0>;
template <class V>
using TFromV = typename V::PrivateT;
template <class D, hwy::EnableIf<D::kPrivateLanes * sizeof(TFromD<D>) <= 16>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<TFromD<D>, D::kPrivateLanes> Zero(D ) {
  Vec128<TFromD<D>, D::kPrivateLanes> v;
  return v;
}
template <class D>
using VFromD = decltype(Zero(D()));
template <class D, class VFrom>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> BitCast(D , VFrom v) {
  VFromD<D> to;
  CopySameSize(&v, &to);
  return to;
}
template <class D, typename T2>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Set(D d, const T2 t) {
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    v.raw[i] = static_cast<TFromD<D>>(t);
  }
  return v;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Undefined(D d) {
  return Zero(d);
}
template <class D, typename T = TFromD<D>, typename T2>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Iota(D d, T2 first) {
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    v.raw[i] =
        AddWithWraparound(hwy::IsFloatTag<T>(), static_cast<T>(first), i);
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Not(Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  const RebindToUnsigned<decltype(d)> du;
  using TU = TFromD<decltype(du)>;
  VFromD<decltype(du)> vu = BitCast(du, v);
  for (size_t i = 0; i < N; ++i) {
    vu.raw[i] = static_cast<TU>(~vu.raw[i]);
  }
  return BitCast(d, vu);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> And(Vec128<T, N> a, Vec128<T, N> b) {
  const DFromV<decltype(a)> d;
  const RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a);
  auto bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i) {
    au.raw[i] &= bu.raw[i];
  }
  return BitCast(d, au);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator&(Vec128<T, N> a, Vec128<T, N> b) {
  return And(a, b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> AndNot(Vec128<T, N> a, Vec128<T, N> b) {
  return And(Not(a), b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Or(Vec128<T, N> a, Vec128<T, N> b) {
  const DFromV<decltype(a)> d;
  const RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a);
  auto bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i) {
    au.raw[i] |= bu.raw[i];
  }
  return BitCast(d, au);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator|(Vec128<T, N> a, Vec128<T, N> b) {
  return Or(a, b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Xor(Vec128<T, N> a, Vec128<T, N> b) {
  const DFromV<decltype(a)> d;
  const RebindToUnsigned<decltype(d)> du;
  auto au = BitCast(du, a);
  auto bu = BitCast(du, b);
  for (size_t i = 0; i < N; ++i) {
    au.raw[i] ^= bu.raw[i];
  }
  return BitCast(d, au);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator^(Vec128<T, N> a, Vec128<T, N> b) {
  return Xor(a, b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Xor3(Vec128<T, N> x1, Vec128<T, N> x2, Vec128<T, N> x3) {
  return Xor(x1, Xor(x2, x3));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Or3(Vec128<T, N> o1, Vec128<T, N> o2, Vec128<T, N> o3) {
  return Or(o1, Or(o2, o3));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> OrAnd(Vec128<T, N> o, Vec128<T, N> a1, Vec128<T, N> a2) {
  return Or(o, And(a1, a2));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> IfVecThenElse(Vec128<T, N> mask, Vec128<T, N> yes,
                                   Vec128<T, N> no) {
  return Or(And(mask, yes), AndNot(mask, no));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> CopySign(Vec128<T, N> magn, Vec128<T, N> sign) {
  static_assert(IsFloat<T>(), "Only makes sense for floating-point");
  const DFromV<decltype(magn)> d;
  const auto msb = SignBit(d);
  return Or(AndNot(msb, magn), And(msb, sign));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> CopySignToAbs(Vec128<T, N> abs, Vec128<T, N> sign) {
  static_assert(IsFloat<T>(), "Only makes sense for floating-point");
  const DFromV<decltype(abs)> d;
  return Or(abs, And(SignBit(d), sign));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> BroadcastSignBit(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = v.raw[i] < 0 ? T(-1) : T(0);
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> MaskFromVec(Vec128<T, N> v) {
  Mask128<T, N> mask;
  CopySameSize(&v, &mask);
  return mask;
}
template <class D>
using MFromD = decltype(MaskFromVec(VFromD<D>()));
template <class DTo, class MFrom>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<DTo> RebindMask(DTo , MFrom mask) {
  MFromD<DTo> to;
  CopySameSize(&mask, &to);
  return to;
}
template <typename T, size_t N>
Vec128<T, N> VecFromMask(Mask128<T, N> mask) {
  Vec128<T, N> v;
  CopySameSize(&mask, &v);
  return v;
}
template <class D>
VFromD<D> VecFromMask(D , MFromD<D> mask) {
  return VecFromMask(mask);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> FirstN(D d, size_t n) {
  MFromD<D> m;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    m.bits[i] = MFromD<D>::FromBool(i < n);
  }
  return m;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> IfThenElse(Mask128<T, N> mask, Vec128<T, N> yes,
                                Vec128<T, N> no) {
  return IfVecThenElse(VecFromMask(mask), yes, no);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> IfThenElseZero(Mask128<T, N> mask, Vec128<T, N> yes) {
  const DFromV<decltype(yes)> d;
  return IfVecThenElse(VecFromMask(mask), yes, Zero(d));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> IfThenZeroElse(Mask128<T, N> mask, Vec128<T, N> no) {
  const DFromV<decltype(no)> d;
  return IfVecThenElse(VecFromMask(mask), Zero(d), no);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> IfNegativeThenElse(Vec128<T, N> v, Vec128<T, N> yes,
                                        Vec128<T, N> no) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = v.raw[i] < 0 ? yes.raw[i] : no.raw[i];
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ZeroIfNegative(Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return IfNegativeThenElse(v, Zero(d), v);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> Not(Mask128<T, N> m) {
  return MaskFromVec(Not(VecFromMask(Simd<T, N, 0>(), m)));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> And(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(And(VecFromMask(d, a), VecFromMask(d, b)));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> AndNot(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(AndNot(VecFromMask(d, a), VecFromMask(d, b)));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> Or(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(Or(VecFromMask(d, a), VecFromMask(d, b)));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> Xor(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(Xor(VecFromMask(d, a), VecFromMask(d, b)));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> ExclusiveNeither(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(AndNot(VecFromMask(d, a), Not(VecFromMask(d, b))));
}
template <int kBits, typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ShiftLeft(Vec128<T, N> v) {
  static_assert(0 <= kBits && kBits < sizeof(T) * 8, "Invalid shift");
  for (size_t i = 0; i < N; ++i) {
    const auto shifted = static_cast<hwy::MakeUnsigned<T>>(v.raw[i]) << kBits;
    v.raw[i] = static_cast<T>(shifted);
  }
  return v;
}
template <int kBits, typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ShiftRight(Vec128<T, N> v) {
  static_assert(0 <= kBits && kBits < sizeof(T) * 8, "Invalid shift");
  if (IsSigned<T>()) {
    using TU = hwy::MakeUnsigned<T>;
    for (size_t i = 0; i < N; ++i) {
      const TU shifted = static_cast<TU>(static_cast<TU>(v.raw[i]) >> kBits);
      const TU sign = v.raw[i] < 0 ? static_cast<TU>(~TU{0}) : 0;
      const size_t sign_shift =
          static_cast<size_t>(static_cast<int>(sizeof(TU)) * 8 - 1 - kBits);
      const TU upper = static_cast<TU>(sign << sign_shift);
      v.raw[i] = static_cast<T>(shifted | upper);
    }
  } else {
    for (size_t i = 0; i < N; ++i) {
      v.raw[i] = static_cast<T>(v.raw[i] >> kBits);
    }
  }
  return v;
}
namespace detail {
template <int kBits>
struct RotateRight {
  template <typename T, size_t N>
  inline __attribute__((always_inline)) Vec128<T, N> operator()(Vec128<T, N> v) const {
    return Or(ShiftRight<kBits>(v), ShiftLeft<sizeof(T) * 8 - kBits>(v));
  }
};
template <>
struct RotateRight<0> {
  template <typename T, size_t N>
  inline __attribute__((always_inline)) Vec128<T, N> operator()(Vec128<T, N> v) const {
    return v;
  }
};
}
template <int kBits, typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> RotateRight(Vec128<T, N> v) {
  static_assert(0 <= kBits && kBits < sizeof(T) * 8, "Invalid shift");
  return detail::RotateRight<kBits>()(v);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ShiftLeftSame(Vec128<T, N> v, int bits) {
  for (size_t i = 0; i < N; ++i) {
    const auto shifted = static_cast<hwy::MakeUnsigned<T>>(v.raw[i]) << bits;
    v.raw[i] = static_cast<T>(shifted);
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ShiftRightSame(Vec128<T, N> v, int bits) {
  if (IsSigned<T>()) {
    using TU = hwy::MakeUnsigned<T>;
    for (size_t i = 0; i < N; ++i) {
      const TU shifted = static_cast<TU>(static_cast<TU>(v.raw[i]) >> bits);
      const TU sign = v.raw[i] < 0 ? static_cast<TU>(~TU{0}) : 0;
      const size_t sign_shift =
          static_cast<size_t>(static_cast<int>(sizeof(TU)) * 8 - 1 - bits);
      const TU upper = static_cast<TU>(sign << sign_shift);
      v.raw[i] = static_cast<T>(shifted | upper);
    }
  } else {
    for (size_t i = 0; i < N; ++i) {
      v.raw[i] = static_cast<T>(v.raw[i] >> bits);
    }
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator<<(Vec128<T, N> v, Vec128<T, N> bits) {
  for (size_t i = 0; i < N; ++i) {
    const auto shifted = static_cast<hwy::MakeUnsigned<T>>(v.raw[i])
                         << bits.raw[i];
    v.raw[i] = static_cast<T>(shifted);
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator>>(Vec128<T, N> v, Vec128<T, N> bits) {
  if (IsSigned<T>()) {
    using TU = hwy::MakeUnsigned<T>;
    for (size_t i = 0; i < N; ++i) {
      const TU shifted =
          static_cast<TU>(static_cast<TU>(v.raw[i]) >> bits.raw[i]);
      const TU sign = v.raw[i] < 0 ? static_cast<TU>(~TU{0}) : 0;
      const size_t sign_shift = static_cast<size_t>(
          static_cast<int>(sizeof(TU)) * 8 - 1 - bits.raw[i]);
      const TU upper = static_cast<TU>(sign << sign_shift);
      v.raw[i] = static_cast<T>(shifted | upper);
    }
  } else {
    for (size_t i = 0; i < N; ++i) {
      v.raw[i] = static_cast<T>(v.raw[i] >> bits.raw[i]);
    }
  }
  return v;
}
namespace detail {
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Add(hwy::NonFloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    const uint64_t a64 = static_cast<uint64_t>(a.raw[i]);
    const uint64_t b64 = static_cast<uint64_t>(b.raw[i]);
    a.raw[i] = static_cast<T>((a64 + b64) & static_cast<uint64_t>(~T(0)));
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Sub(hwy::NonFloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    const uint64_t a64 = static_cast<uint64_t>(a.raw[i]);
    const uint64_t b64 = static_cast<uint64_t>(b.raw[i]);
    a.raw[i] = static_cast<T>((a64 - b64) & static_cast<uint64_t>(~T(0)));
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Add(hwy::FloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] += b.raw[i];
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Sub(hwy::FloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] -= b.raw[i];
  }
  return a;
}
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator-(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Sub(hwy::IsFloatTag<T>(), a, b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator+(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Add(hwy::IsFloatTag<T>(), a, b);
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<uint64_t, (N + 7) / 8> SumsOf8(Vec128<uint8_t, N> v) {
  Vec128<uint64_t, (N + 7) / 8> sums;
  for (size_t i = 0; i < N; ++i) {
    sums.raw[i / 8] += v.raw[i];
  }
  return sums;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> SaturatedAdd(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(
        ((((hwy::LowestValue<T>()) > (a.raw[i] + b.raw[i]) ? (hwy::LowestValue<T>()) : (a.raw[i] + b.raw[i]))) < (hwy::HighestValue<T>()) ? (((hwy::LowestValue<T>()) > (a.raw[i] + b.raw[i]) ? (hwy::LowestValue<T>()) : (a.raw[i] + b.raw[i]))) : (hwy::HighestValue<T>())));
  }
  return a;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> SaturatedSub(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(
        ((((hwy::LowestValue<T>()) > (a.raw[i] - b.raw[i]) ? (hwy::LowestValue<T>()) : (a.raw[i] - b.raw[i]))) < (hwy::HighestValue<T>()) ? (((hwy::LowestValue<T>()) > (a.raw[i] - b.raw[i]) ? (hwy::LowestValue<T>()) : (a.raw[i] - b.raw[i]))) : (hwy::HighestValue<T>())));
  }
  return a;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> AverageRound(Vec128<T, N> a, Vec128<T, N> b) {
  static_assert(!IsSigned<T>(), "Only for unsigned");
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>((a.raw[i] + b.raw[i] + 1) / 2);
  }
  return a;
}
namespace detail {
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Abs(SignedTag , Vec128<T, N> a) {
  for (size_t i = 0; i < N; ++i) {
    const T s = a.raw[i];
    const T min = hwy::LimitsMin<T>();
    a.raw[i] = static_cast<T>((s >= 0 || s == min) ? a.raw[i] : -s);
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Abs(hwy::FloatTag , Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = std::abs(v.raw[i]);
  }
  return v;
}
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Abs(Vec128<T, N> a) {
  return detail::Abs(hwy::TypeTag<T>(), a);
}
namespace detail {
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Min(hwy::NonFloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = ((a.raw[i]) < (b.raw[i]) ? (a.raw[i]) : (b.raw[i]));
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Max(hwy::NonFloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = ((a.raw[i]) > (b.raw[i]) ? (a.raw[i]) : (b.raw[i]));
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Min(hwy::FloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    if (std::isnan(a.raw[i])) {
      a.raw[i] = b.raw[i];
    } else if (std::isnan(b.raw[i])) {
    } else {
      a.raw[i] = ((a.raw[i]) < (b.raw[i]) ? (a.raw[i]) : (b.raw[i]));
    }
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Max(hwy::FloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    if (std::isnan(a.raw[i])) {
      a.raw[i] = b.raw[i];
    } else if (std::isnan(b.raw[i])) {
    } else {
      a.raw[i] = ((a.raw[i]) > (b.raw[i]) ? (a.raw[i]) : (b.raw[i]));
    }
  }
  return a;
}
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Min(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Min(hwy::IsFloatTag<T>(), a, b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Max(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Max(hwy::IsFloatTag<T>(), a, b);
}
namespace detail {
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Neg(hwy::NonFloatTag , Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return Zero(d) - v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Neg(hwy::FloatTag , Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return Xor(v, SignBit(d));
}
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Neg(Vec128<T, N> v) {
  return detail::Neg(hwy::IsFloatTag<T>(), v);
}
namespace detail {
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Mul(hwy::FloatTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] *= b.raw[i];
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Mul(SignedTag , Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(static_cast<uint64_t>(a.raw[i]) *
                              static_cast<uint64_t>(b.raw[i]));
  }
  return a;
}
template <typename T, size_t N>
inline __attribute__((always_inline)) Vec128<T, N> Mul(UnsignedTag , Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(static_cast<uint64_t>(a.raw[i]) *
                              static_cast<uint64_t>(b.raw[i]));
  }
  return a;
}
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Mul(hwy::TypeTag<T>(), a, b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> operator/(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = (b.raw[i] == T{0}) ? 0 : a.raw[i] / b.raw[i];
  }
  return a;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<int16_t, N> MulHigh(Vec128<int16_t, N> a, Vec128<int16_t, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<int16_t>((int32_t{a.raw[i]} * b.raw[i]) >> 16);
  }
  return a;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<uint16_t, N> MulHigh(Vec128<uint16_t, N> a,
                                    Vec128<uint16_t, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<uint16_t>(
        (static_cast<uint32_t>(a.raw[i]) * static_cast<uint32_t>(b.raw[i])) >>
        16);
  }
  return a;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<int16_t, N> MulFixedPoint15(Vec128<int16_t, N> a,
                                           Vec128<int16_t, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<int16_t>((2 * a.raw[i] * b.raw[i] + 32768) >> 16);
  }
  return a;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<int64_t, (N + 1) / 2> MulEven(Vec128<int32_t, N> a,
                                             Vec128<int32_t, N> b) {
  Vec128<int64_t, (N + 1) / 2> mul;
  for (size_t i = 0; i < N; i += 2) {
    const int64_t a64 = a.raw[i];
    mul.raw[i / 2] = a64 * b.raw[i];
  }
  return mul;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<uint64_t, (N + 1) / 2> MulEven(Vec128<uint32_t, N> a,
                                              Vec128<uint32_t, N> b) {
  Vec128<uint64_t, (N + 1) / 2> mul;
  for (size_t i = 0; i < N; i += 2) {
    const uint64_t a64 = a.raw[i];
    mul.raw[i / 2] = a64 * b.raw[i];
  }
  return mul;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<int64_t, (N + 1) / 2> MulOdd(Vec128<int32_t, N> a,
                                            Vec128<int32_t, N> b) {
  Vec128<int64_t, (N + 1) / 2> mul;
  for (size_t i = 0; i < N; i += 2) {
    const int64_t a64 = a.raw[i + 1];
    mul.raw[i / 2] = a64 * b.raw[i + 1];
  }
  return mul;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<uint64_t, (N + 1) / 2> MulOdd(Vec128<uint32_t, N> a,
                                             Vec128<uint32_t, N> b) {
  Vec128<uint64_t, (N + 1) / 2> mul;
  for (size_t i = 0; i < N; i += 2) {
    const uint64_t a64 = a.raw[i + 1];
    mul.raw[i / 2] = a64 * b.raw[i + 1];
  }
  return mul;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<float, N> ApproximateReciprocal(Vec128<float, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = (std::abs(v.raw[i]) == 0.0f) ? 0.0f : 1.0f / v.raw[i];
  }
  return v;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<float, N> AbsDiff(Vec128<float, N> a, Vec128<float, N> b) {
  return Abs(a - b);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> MulAdd(Vec128<T, N> mul, Vec128<T, N> x,
                            Vec128<T, N> add) {
  return mul * x + add;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> NegMulAdd(Vec128<T, N> mul, Vec128<T, N> x,
                               Vec128<T, N> add) {
  return add - mul * x;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> MulSub(Vec128<T, N> mul, Vec128<T, N> x,
                            Vec128<T, N> sub) {
  return mul * x - sub;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> NegMulSub(Vec128<T, N> mul, Vec128<T, N> x,
                               Vec128<T, N> sub) {
  return Neg(mul) * x - sub;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<float, N> ApproximateReciprocalSqrt(Vec128<float, N> v) {
  for (size_t i = 0; i < N; ++i) {
    const float half = v.raw[i] * 0.5f;
    uint32_t bits;
    CopySameSize(&v.raw[i], &bits);
    bits = 0x5F3759DF - (bits >> 1);
    CopySameSize(&bits, &v.raw[i]);
    v.raw[i] = v.raw[i] * (1.5f - (half * v.raw[i] * v.raw[i]));
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Sqrt(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = std::sqrt(v.raw[i]);
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Round(Vec128<T, N> v) {
  using TI = MakeSigned<T>;
  const Vec128<T, N> a = Abs(v);
  for (size_t i = 0; i < N; ++i) {
    if (!(a.raw[i] < MantissaEnd<T>())) {
      continue;
    }
    const T bias = v.raw[i] < T(0.0) ? T(-0.5) : T(0.5);
    const TI rounded = static_cast<TI>(v.raw[i] + bias);
    if (rounded == 0) {
      v.raw[i] = v.raw[i] < 0 ? T{-0} : T{0};
      continue;
    }
    const T rounded_f = static_cast<T>(rounded);
    if ((rounded & 1) && std::abs(rounded_f - v.raw[i]) == T(0.5)) {
      v.raw[i] = static_cast<T>(rounded - (v.raw[i] < T(0) ? -1 : 1));
      continue;
    }
    v.raw[i] = rounded_f;
  }
  return v;
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<int32_t, N> NearestInt(Vec128<float, N> v) {
  using T = float;
  using TI = int32_t;
  const Vec128<float, N> abs = Abs(v);
  Vec128<int32_t, N> ret;
  for (size_t i = 0; i < N; ++i) {
    const bool signbit = std::signbit(v.raw[i]);
    if (!(abs.raw[i] < MantissaEnd<T>())) {
      if (!(abs.raw[i] <= static_cast<T>(LimitsMax<TI>()))) {
        ret.raw[i] = signbit ? LimitsMin<TI>() : LimitsMax<TI>();
        continue;
      }
      ret.raw[i] = static_cast<TI>(v.raw[i]);
      continue;
    }
    const T bias = v.raw[i] < T(0.0) ? T(-0.5) : T(0.5);
    const TI rounded = static_cast<TI>(v.raw[i] + bias);
    if (rounded == 0) {
      ret.raw[i] = 0;
      continue;
    }
    const T rounded_f = static_cast<T>(rounded);
    if ((rounded & 1) && std::abs(rounded_f - v.raw[i]) == T(0.5)) {
      ret.raw[i] = rounded - (signbit ? -1 : 1);
      continue;
    }
    ret.raw[i] = rounded;
  }
  return ret;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Trunc(Vec128<T, N> v) {
  using TI = MakeSigned<T>;
  const Vec128<T, N> abs = Abs(v);
  for (size_t i = 0; i < N; ++i) {
    if (!(abs.raw[i] <= MantissaEnd<T>())) {
      continue;
    }
    const TI truncated = static_cast<TI>(v.raw[i]);
    if (truncated == 0) {
      v.raw[i] = v.raw[i] < 0 ? -T{0} : T{0};
      continue;
    }
    v.raw[i] = static_cast<T>(truncated);
  }
  return v;
}
template <typename Float, size_t N>
Vec128<Float, N> Ceil(Vec128<Float, N> v) {
  constexpr int kMantissaBits = MantissaBits<Float>();
  using Bits = MakeUnsigned<Float>;
  const Bits kExponentMask = MaxExponentField<Float>();
  const Bits kMantissaMask = MantissaMask<Float>();
  const Bits kBias = kExponentMask / 2;
  for (size_t i = 0; i < N; ++i) {
    const bool positive = v.raw[i] > Float(0.0);
    Bits bits;
    CopySameSize(&v.raw[i], &bits);
    const int exponent =
        static_cast<int>(((bits >> kMantissaBits) & kExponentMask) - kBias);
    if (exponent >= kMantissaBits) continue;
    if (exponent < 0) {
      v.raw[i] = positive ? Float{1} : Float{-0.0};
      continue;
    }
    const Bits mantissa_mask = kMantissaMask >> exponent;
    if ((bits & mantissa_mask) == 0) continue;
    if (positive) bits += (kMantissaMask + 1) >> exponent;
    bits &= ~mantissa_mask;
    CopySameSize(&bits, &v.raw[i]);
  }
  return v;
}
template <typename Float, size_t N>
Vec128<Float, N> Floor(Vec128<Float, N> v) {
  constexpr int kMantissaBits = MantissaBits<Float>();
  using Bits = MakeUnsigned<Float>;
  const Bits kExponentMask = MaxExponentField<Float>();
  const Bits kMantissaMask = MantissaMask<Float>();
  const Bits kBias = kExponentMask / 2;
  for (size_t i = 0; i < N; ++i) {
    const bool negative = v.raw[i] < Float(0.0);
    Bits bits;
    CopySameSize(&v.raw[i], &bits);
    const int exponent =
        static_cast<int>(((bits >> kMantissaBits) & kExponentMask) - kBias);
    if (exponent >= kMantissaBits) continue;
    if (exponent < 0) {
      v.raw[i] = negative ? Float(-1.0) : Float(0.0);
      continue;
    }
    const Bits mantissa_mask = kMantissaMask >> exponent;
    if ((bits & mantissa_mask) == 0) continue;
    if (negative) bits += (kMantissaMask + 1) >> exponent;
    bits &= ~mantissa_mask;
    CopySameSize(&bits, &v.raw[i]);
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> IsNaN(Vec128<T, N> v) {
  Mask128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    MakeUnsigned<T> bits;
    CopySameSize(&v.raw[i], &bits);
    bits += bits;
    bits >>= 1;
    ret.bits[i] = Mask128<T, N>::FromBool(bits > ExponentMask<T>());
  }
  return ret;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> IsInf(Vec128<T, N> v) {
  static_assert(IsFloat<T>(), "Only for float");
  const DFromV<decltype(v)> d;
  const RebindToSigned<decltype(d)> di;
  const VFromD<decltype(di)> vi = BitCast(di, v);
  return RebindMask(d, Eq(Add(vi, vi), Set(di, hwy::MaxExponentTimes2<T>())));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> IsFinite(Vec128<T, N> v) {
  static_assert(IsFloat<T>(), "Only for float");
  const DFromV<decltype(v)> d;
  const RebindToUnsigned<decltype(d)> du;
  const RebindToSigned<decltype(d)> di;
  using VI = VFromD<decltype(di)>;
  using VU = VFromD<decltype(du)>;
  const VU vu = BitCast(du, v);
  const VI exp =
      BitCast(di, ShiftRight<hwy::MantissaBits<T>() + 1>(Add(vu, vu)));
  return RebindMask(d, Lt(exp, Set(di, hwy::MaxExponentField<T>())));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> operator==(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] == b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> operator!=(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] != b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> TestBit(Vec128<T, N> v, Vec128<T, N> bit) {
  static_assert(!hwy::IsFloat<T>(), "Only integer vectors supported");
  return (v & bit) == bit;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> operator<(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] < b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> operator>(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] > b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> operator<=(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] <= b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<T, N> operator>=(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] >= b.raw[i]);
  }
  return m;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> Lt128(D , Vec128<uint64_t> a, Vec128<uint64_t> b) {
  const bool lt =
      (a.raw[1] < b.raw[1]) || (a.raw[1] == b.raw[1] && a.raw[0] < b.raw[0]);
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(lt);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> Lt128Upper(D , Vec128<uint64_t> a,
                             Vec128<uint64_t> b) {
  const bool lt = a.raw[1] < b.raw[1];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(lt);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> Eq128(D , Vec128<uint64_t> a, Vec128<uint64_t> b) {
  const bool eq = a.raw[1] == b.raw[1] && a.raw[0] == b.raw[0];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(eq);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Mask128<uint64_t> Ne128(D , Vec128<uint64_t> a,
                                Vec128<uint64_t> b) {
  const bool ne = a.raw[1] != b.raw[1] || a.raw[0] != b.raw[0];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(ne);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> Eq128Upper(D , Vec128<uint64_t> a,
                             Vec128<uint64_t> b) {
  const bool eq = a.raw[1] == b.raw[1];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(eq);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> Ne128Upper(D , Vec128<uint64_t> a,
                             Vec128<uint64_t> b) {
  const bool ne = a.raw[1] != b.raw[1];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(ne);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Min128(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128(d, a, b), a, b);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Max128(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128(d, b, a), a, b);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Min128Upper(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128Upper(d, a, b), a, b);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Max128Upper(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128Upper(d, b, a), a, b);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Load(D d, const TFromD<D>* __restrict__ aligned) {
  VFromD<D> v;
  CopyBytes<d.MaxBytes()>(aligned, v.raw);
  return v;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> MaskedLoad(MFromD<D> m, D d,
                             const TFromD<D>* __restrict__ p) {
  return IfThenElseZero(m, LoadU(d, p));
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> LoadU(D d, const TFromD<D>* __restrict__ p) {
  return Load(d, p);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> LoadDup128(D d, const TFromD<D>* __restrict__ aligned) {
  return Load(d, aligned);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void Store(VFromD<D> v, D d, TFromD<D>* __restrict__ aligned) {
  CopyBytes<d.MaxBytes()>(v.raw, aligned);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void StoreU(VFromD<D> v, D d, TFromD<D>* __restrict__ p) {
  Store(v, d, p);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void BlendedStore(VFromD<D> v, MFromD<D> m, D d,
                          TFromD<D>* __restrict__ p) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (m.bits[i]) p[i] = v.raw[i];
  }
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void LoadInterleaved2(D d, const T* __restrict__ unaligned,
                              VFromD<D>& v0, VFromD<D>& v1) {
  alignas(16) T buf0[MaxLanes(d)];
  alignas(16) T buf1[MaxLanes(d)];
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    buf0[i] = *unaligned++;
    buf1[i] = *unaligned++;
  }
  v0 = Load(d, buf0);
  v1 = Load(d, buf1);
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void LoadInterleaved3(D d, const T* __restrict__ unaligned,
                              VFromD<D>& v0, VFromD<D>& v1, VFromD<D>& v2) {
  alignas(16) T buf0[MaxLanes(d)];
  alignas(16) T buf1[MaxLanes(d)];
  alignas(16) T buf2[MaxLanes(d)];
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    buf0[i] = *unaligned++;
    buf1[i] = *unaligned++;
    buf2[i] = *unaligned++;
  }
  v0 = Load(d, buf0);
  v1 = Load(d, buf1);
  v2 = Load(d, buf2);
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void LoadInterleaved4(D d, const T* __restrict__ unaligned,
                              VFromD<D>& v0, VFromD<D>& v1, VFromD<D>& v2,
                              VFromD<D>& v3) {
  alignas(16) T buf0[MaxLanes(d)];
  alignas(16) T buf1[MaxLanes(d)];
  alignas(16) T buf2[MaxLanes(d)];
  alignas(16) T buf3[MaxLanes(d)];
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    buf0[i] = *unaligned++;
    buf1[i] = *unaligned++;
    buf2[i] = *unaligned++;
    buf3[i] = *unaligned++;
  }
  v0 = Load(d, buf0);
  v1 = Load(d, buf1);
  v2 = Load(d, buf2);
  v3 = Load(d, buf3);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void StoreInterleaved2(VFromD<D> v0, VFromD<D> v1, D d,
                               TFromD<D>* __restrict__ unaligned) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    *unaligned++ = v0.raw[i];
    *unaligned++ = v1.raw[i];
  }
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void StoreInterleaved3(VFromD<D> v0, VFromD<D> v1, VFromD<D> v2, D d,
                               TFromD<D>* __restrict__ unaligned) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    *unaligned++ = v0.raw[i];
    *unaligned++ = v1.raw[i];
    *unaligned++ = v2.raw[i];
  }
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void StoreInterleaved4(VFromD<D> v0, VFromD<D> v1, VFromD<D> v2,
                               VFromD<D> v3, D d,
                               TFromD<D>* __restrict__ unaligned) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    *unaligned++ = v0.raw[i];
    *unaligned++ = v1.raw[i];
    *unaligned++ = v2.raw[i];
    *unaligned++ = v3.raw[i];
  }
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void Stream(VFromD<D> v, D d, TFromD<D>* __restrict__ aligned) {
  Store(v, d, aligned);
}
template <class D, typename T = TFromD<D>, typename Offset>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void ScatterOffset(VFromD<D> v, D d, T* base,
                           Vec128<Offset, D::kPrivateLanes> offset) {
  static_assert(sizeof(T) == sizeof(Offset), "Index/lane size must match");
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    uint8_t* const base8 = reinterpret_cast<uint8_t*>(base) + offset.raw[i];
    CopyBytes<sizeof(T)>(&v.raw[i], base8);
  }
}
template <class D, typename T = TFromD<D>, typename Index>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void ScatterIndex(VFromD<D> v, D d, T* __restrict__ base,
                          Vec128<Index, D::kPrivateLanes> index) {
  static_assert(sizeof(T) == sizeof(Index), "Index/lane size must match");
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    base[index.raw[i]] = v.raw[i];
  }
}
template <class D, typename T = TFromD<D>, typename Offset>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> GatherOffset(D d, const T* base,
                               Vec128<Offset, D::kPrivateLanes> offset) {
  static_assert(sizeof(T) == sizeof(Offset), "Index/lane size must match");
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    const uint8_t* base8 =
        reinterpret_cast<const uint8_t*>(base) + offset.raw[i];
    CopyBytes<sizeof(T)>(base8, &v.raw[i]);
  }
  return v;
}
template <class D, typename T = TFromD<D>, typename Index>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> GatherIndex(D d, const T* __restrict__ base,
                              Vec128<Index, D::kPrivateLanes> index) {
  static_assert(sizeof(T) == sizeof(Index), "Index/lane size must match");
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    v.raw[i] = base[index.raw[i]];
  }
  return v;
}
template <class DTo, typename TFrom, hwy::EnableIf<!hwy::IsSpecialFloat<TFrom>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DTo> PromoteTo(DTo d, Vec128<TFrom, DTo::kPrivateLanes> from) {
  static_assert(sizeof(TFromD<DTo>) > sizeof(TFrom), "Not promoting");
  VFromD<DTo> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    ret.raw[i] = static_cast<TFromD<DTo>>(from.raw[i]);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, float>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> DemoteTo(D d, VFromD<Rebind<double, D>> from) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (std::isinf(from.raw[i]) ||
        std::fabs(from.raw[i]) > static_cast<double>(HighestValue<float>())) {
      ret.raw[i] = std::signbit(from.raw[i]) ? LowestValue<float>()
                                             : HighestValue<float>();
      continue;
    }
    ret.raw[i] = static_cast<float>(from.raw[i]);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, int32_t>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> DemoteTo(D d, VFromD<Rebind<double, D>> from) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (std::isinf(from.raw[i]) ||
        std::fabs(from.raw[i]) > static_cast<double>(HighestValue<int32_t>())) {
      ret.raw[i] = std::signbit(from.raw[i]) ? LowestValue<int32_t>()
                                             : HighestValue<int32_t>();
      continue;
    }
    ret.raw[i] = static_cast<int32_t>(from.raw[i]);
  }
  return ret;
}
template <class DTo, typename TFrom, size_t N, hwy::EnableIf<!hwy::IsFloat<TFrom>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DTo> DemoteTo(DTo , Vec128<TFrom, N> from) {
  using TTo = TFromD<DTo>;
  static_assert(sizeof(TTo) < sizeof(TFrom), "Not demoting");
  VFromD<DTo> ret;
  for (size_t i = 0; i < N; ++i) {
    from.raw[i] =
        ((((LimitsMin<TTo>()) > (from.raw[i]) ? (LimitsMin<TTo>()) : (from.raw[i]))) < (LimitsMax<TTo>()) ? (((LimitsMin<TTo>()) > (from.raw[i]) ? (LimitsMin<TTo>()) : (from.raw[i]))) : (LimitsMax<TTo>()));
    ret.raw[i] = static_cast<TTo>(from.raw[i]);
  }
  return ret;
}
template <class DBF16, hwy::EnableIf<IsSame<TFromD<DBF16>, bfloat16_t>()>* = nullptr, class VF32>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DBF16> ReorderDemote2To(DBF16 dbf16, VF32 a, VF32 b) {
  const Repartition<uint32_t, decltype(dbf16)> du32;
  const VFromD<decltype(du32)> b_in_lower = ShiftRight<16>(BitCast(du32, b));
  const VFromD<decltype(du32)> a_mask = Set(du32, 0xFFFF0000);
  return BitCast(dbf16, IfVecThenElse(a_mask, BitCast(du32, a), b_in_lower));
}
template <class DI16, hwy::EnableIf<IsSame<TFromD<DI16>, int16_t>()>* = nullptr, class VI32>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DI16> ReorderDemote2To(DI16 di16, VI32 a, VI32 b) {
  const RepartitionToWide<decltype(di16)> di32;
  const size_t N32 = Lanes(di32);
  const int16_t min = LimitsMin<int16_t>();
  const int16_t max = LimitsMax<int16_t>();
  VFromD<DI16> ret;
  for (size_t i = 0; i < N32; ++i) {
    ret.raw[i] = static_cast<int16_t>(((((min) > (a.raw[i]) ? (min) : (a.raw[i]))) < (max) ? (((min) > (a.raw[i]) ? (min) : (a.raw[i]))) : (max)));
  }
  for (size_t i = 0; i < N32; ++i) {
    ret.raw[N32 + i] =
        static_cast<int16_t>(((((min) > (b.raw[i]) ? (min) : (b.raw[i]))) < (max) ? (((min) > (b.raw[i]) ? (min) : (b.raw[i]))) : (max)));
  }
  return ret;
}
namespace detail {
inline __attribute__((always_inline)) void StoreU16ToF16(const uint16_t val,
                              hwy::float16_t* __restrict__ to) {
  CopySameSize(&val, to);
}
inline __attribute__((always_inline)) uint16_t U16FromF16(const hwy::float16_t* __restrict__ from) {
  uint16_t bits16;
  CopySameSize(from, &bits16);
  return bits16;
}
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, float>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> PromoteTo(D , Vec128<float16_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    const uint16_t bits16 = detail::U16FromF16(&v.raw[i]);
    const uint32_t sign = static_cast<uint32_t>(bits16 >> 15);
    const uint32_t biased_exp = (bits16 >> 10) & 0x1F;
    const uint32_t mantissa = bits16 & 0x3FF;
    if (biased_exp == 0) {
      const float subnormal =
          (1.0f / 16384) * (static_cast<float>(mantissa) * (1.0f / 1024));
      ret.raw[i] = sign ? -subnormal : subnormal;
      continue;
    }
    const uint32_t biased_exp32 = biased_exp + (127 - 15);
    const uint32_t mantissa32 = mantissa << (23 - 10);
    const uint32_t bits32 = (sign << 31) | (biased_exp32 << 23) | mantissa32;
    CopySameSize(&bits32, &ret.raw[i]);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, float>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> PromoteTo(D , Vec128<bfloat16_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = F32FromBF16(v.raw[i]);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, float16_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> DemoteTo(D , Vec128<float, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    uint32_t bits32;
    CopySameSize(&v.raw[i], &bits32);
    const uint32_t sign = bits32 >> 31;
    const uint32_t biased_exp32 = (bits32 >> 23) & 0xFF;
    const uint32_t mantissa32 = bits32 & 0x7FFFFF;
    const int32_t exp = ((static_cast<int32_t>(biased_exp32) - 127) < (15) ? (static_cast<int32_t>(biased_exp32) - 127) : (15));
    if (exp < -24) {
      ZeroBytes<sizeof(uint16_t)>(&ret.raw[i]);
      continue;
    }
    uint32_t biased_exp16, mantissa16;
    if (exp < -14) {
      biased_exp16 = 0;
      const uint32_t sub_exp = static_cast<uint32_t>(-14 - exp);
      do { } while (0);
      mantissa16 = static_cast<uint32_t>((1u << (10 - sub_exp)) +
                                         (mantissa32 >> (13 + sub_exp)));
    } else {
      biased_exp16 = static_cast<uint32_t>(exp + 15);
      do { } while (0);
      mantissa16 = mantissa32 >> 13;
    }
    do { } while (0);
    const uint32_t bits16 = (sign << 15) | (biased_exp16 << 10) | mantissa16;
    do { } while (0);
    const uint16_t narrowed = static_cast<uint16_t>(bits16);
    detail::StoreU16ToF16(narrowed, &ret.raw[i]);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, bfloat16_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> DemoteTo(D , Vec128<float, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = BF16FromF32(v.raw[i]);
  }
  return ret;
}
namespace detail {
template <typename TFrom, typename ToT, size_t N, int kPow2>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<ToT, N> ConvertTo(hwy::FloatTag ,
                                 Simd<ToT, N, kPow2> ,
                                 Vec128<TFrom, N> from) {
  static_assert(sizeof(ToT) == sizeof(TFrom), "Should have same size");
  Vec128<ToT, N> ret;
  for (size_t i = 0; i < N; ++i) {
    const double f = static_cast<double>(from.raw[i]);
    if (std::isinf(from.raw[i]) ||
        std::fabs(f) > static_cast<double>(LimitsMax<ToT>())) {
      ret.raw[i] =
          std::signbit(from.raw[i]) ? LimitsMin<ToT>() : LimitsMax<ToT>();
      continue;
    }
    ret.raw[i] = static_cast<ToT>(from.raw[i]);
  }
  return ret;
}
template <typename TFrom, typename ToT, size_t N, int kPow2>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<ToT, N> ConvertTo(hwy::NonFloatTag ,
                                 Simd<ToT, N, kPow2> ,
                                 Vec128<TFrom, N> from) {
  static_assert(sizeof(ToT) == sizeof(TFrom), "Should have same size");
  Vec128<ToT, N> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<ToT>(from.raw[i]);
  }
  return ret;
}
}
template <class DTo, typename TFrom, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DTo> ConvertTo(DTo d, Vec128<TFrom, N> from) {
  return detail::ConvertTo(hwy::IsFloatTag<TFrom>(), d, from);
}
template <size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<uint8_t, N> U8FromU32(Vec128<uint32_t, N> v) {
  return DemoteTo(Simd<uint8_t, N, 0>(), v);
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, uint8_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> TruncateTo(D , Vec128<uint64_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint8_t>(v.raw[i] & 0xFF);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, uint16_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> TruncateTo(D , Vec128<uint64_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint16_t>(v.raw[i] & 0xFFFF);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, uint32_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> TruncateTo(D , Vec128<uint64_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint32_t>(v.raw[i] & 0xFFFFFFFFu);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, uint8_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> TruncateTo(D , Vec128<uint32_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint8_t>(v.raw[i] & 0xFF);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, uint16_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> TruncateTo(D , Vec128<uint32_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint16_t>(v.raw[i] & 0xFFFF);
  }
  return ret;
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, uint8_t>()>* = nullptr, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> TruncateTo(D , Vec128<uint16_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint8_t>(v.raw[i] & 0xFF);
  }
  return ret;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N / 2> LowerHalf(Vec128<T, N> v) {
  Vec128<T, N / 2> ret;
  CopyBytes<N / 2 * sizeof(T)>(v.raw, ret.raw);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> LowerHalf(D , VFromD<Twice<D>> v) {
  return LowerHalf(v);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> UpperHalf(D d, VFromD<Twice<D>> v) {
  VFromD<D> ret;
  CopyBytes<d.MaxBytes()>(&v.raw[MaxLanes(d)], ret.raw);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ZeroExtendVector(D d, VFromD<Half<D>> v) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(v.raw, ret.raw);
  return ret;
}
template <class D, class VH = VFromD<Half<D>>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Combine(D d, VH hi_half, VH lo_half) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(lo_half.raw, &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(hi_half.raw, &ret.raw[MaxLanes(dh)]);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ConcatLowerLower(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(lo.raw, &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(hi.raw, &ret.raw[MaxLanes(dh)]);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ConcatUpperUpper(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(&lo.raw[MaxLanes(dh)], &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(&hi.raw[MaxLanes(dh)], &ret.raw[MaxLanes(dh)]);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ConcatLowerUpper(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(&lo.raw[MaxLanes(dh)], &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(hi.raw, &ret.raw[MaxLanes(dh)]);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ConcatUpperLower(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(lo.raw, &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(&hi.raw[MaxLanes(dh)], &ret.raw[MaxLanes(dh)]);
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ConcatEven(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[i] = lo.raw[2 * i];
  }
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[MaxLanes(dh) + i] = hi.raw[2 * i];
  }
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ConcatOdd(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[i] = lo.raw[2 * i + 1];
  }
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[MaxLanes(dh) + i] = hi.raw[2 * i + 1];
  }
  return ret;
}
template <int kBytes, class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> CombineShiftRightBytes(D d, VFromD<D> hi, VFromD<D> lo) {
  VFromD<D> ret;
  const uint8_t* __restrict__ lo8 =
      reinterpret_cast<const uint8_t * __restrict__>(lo.raw);
  uint8_t* __restrict__ ret8 =
      reinterpret_cast<uint8_t * __restrict__>(ret.raw);
  CopyBytes<d.MaxBytes() - kBytes>(lo8 + kBytes, ret8);
  CopyBytes<kBytes>(hi.raw, ret8 + d.MaxBytes() - kBytes);
  return ret;
}
template <int kBytes, class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ShiftLeftBytes(D d, VFromD<D> v) {
  static_assert(0 <= kBytes && kBytes <= 16, "Invalid kBytes");
  VFromD<D> ret;
  uint8_t* __restrict__ ret8 =
      reinterpret_cast<uint8_t * __restrict__>(ret.raw);
  ZeroBytes<kBytes>(ret8);
  CopyBytes<d.MaxBytes() - kBytes>(v.raw, ret8 + kBytes);
  return ret;
}
template <int kBytes, typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ShiftLeftBytes(Vec128<T, N> v) {
  return ShiftLeftBytes<kBytes>(DFromV<decltype(v)>(), v);
}
template <int kLanes, class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ShiftLeftLanes(D d, VFromD<D> v) {
  const Repartition<uint8_t, decltype(d)> d8;
  return BitCast(d, ShiftLeftBytes<kLanes * sizeof(T)>(BitCast(d8, v)));
}
template <int kLanes, typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> ShiftLeftLanes(Vec128<T, N> v) {
  return ShiftLeftLanes<kLanes>(DFromV<decltype(v)>(), v);
}
template <int kBytes, class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ShiftRightBytes(D d, VFromD<D> v) {
  static_assert(0 <= kBytes && kBytes <= 16, "Invalid kBytes");
  VFromD<D> ret;
  const uint8_t* __restrict__ v8 =
      reinterpret_cast<const uint8_t * __restrict__>(v.raw);
  uint8_t* __restrict__ ret8 =
      reinterpret_cast<uint8_t * __restrict__>(ret.raw);
  CopyBytes<d.MaxBytes() - kBytes>(v8 + kBytes, ret8);
  ZeroBytes<kBytes>(ret8 + d.MaxBytes() - kBytes);
  return ret;
}
template <int kLanes, class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ShiftRightLanes(D d, VFromD<D> v) {
  const Repartition<uint8_t, decltype(d)> d8;
  constexpr size_t kBytes = kLanes * sizeof(TFromD<D>);
  return BitCast(d, ShiftRightBytes<kBytes>(d8, BitCast(d8, v)));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) T GetLane(Vec128<T, N> v) {
  return v.raw[0];
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> InsertLane(Vec128<T, N> v, size_t i, T t) {
  v.raw[i] = t;
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) T ExtractLane(Vec128<T, N> v, size_t i) {
  return v.raw[i];
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> DupEven(Vec128<T, N> v) {
  for (size_t i = 0; i < N; i += 2) {
    v.raw[i + 1] = v.raw[i];
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> DupOdd(Vec128<T, N> v) {
  for (size_t i = 0; i < N; i += 2) {
    v.raw[i] = v.raw[i + 1];
  }
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> OddEven(Vec128<T, N> odd, Vec128<T, N> even) {
  for (size_t i = 0; i < N; i += 2) {
    odd.raw[i] = even.raw[i];
  }
  return odd;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> OddEvenBlocks(Vec128<T, N> , Vec128<T, N> even) {
  return even;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> SwapAdjacentBlocks(Vec128<T, N> v) {
  return v;
}
template <typename T, size_t N>
struct Indices128 {
  MakeSigned<T> raw[N];
};
template <class D, typename TI, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Indices128<TFromD<D>, N> IndicesFromVec(D d, Vec128<TI, N> vec) {
  static_assert(sizeof(TFromD<D>) == sizeof(TI), "Index/lane size must match");
  Indices128<TFromD<D>, N> ret;
  CopyBytes<d.MaxBytes()>(vec.raw, ret.raw);
  return ret;
}
template <class D, typename TI>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Indices128<TFromD<D>, D::kPrivateLanes> SetTableIndices(
    D d, const TI* idx) {
  return IndicesFromVec(d, LoadU(Rebind<TI, D>(), idx));
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> TableLookupLanes(Vec128<T, N> v, Indices128<T, N> idx) {
  Vec128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = v.raw[idx.raw[i]];
  }
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ReverseBlocks(D , VFromD<D> v) {
  return v;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Reverse(D d, VFromD<D> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    ret.raw[i] = v.raw[MaxLanes(d) - 1 - i];
  }
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Reverse2(D d, VFromD<D> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); i += 2) {
    ret.raw[i + 0] = v.raw[i + 1];
    ret.raw[i + 1] = v.raw[i + 0];
  }
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Reverse4(D d, VFromD<D> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); i += 4) {
    ret.raw[i + 0] = v.raw[i + 3];
    ret.raw[i + 1] = v.raw[i + 2];
    ret.raw[i + 2] = v.raw[i + 1];
    ret.raw[i + 3] = v.raw[i + 0];
  }
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> Reverse8(D d, VFromD<D> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); i += 8) {
    ret.raw[i + 0] = v.raw[i + 7];
    ret.raw[i + 1] = v.raw[i + 6];
    ret.raw[i + 2] = v.raw[i + 5];
    ret.raw[i + 3] = v.raw[i + 4];
    ret.raw[i + 4] = v.raw[i + 3];
    ret.raw[i + 5] = v.raw[i + 2];
    ret.raw[i + 6] = v.raw[i + 1];
    ret.raw[i + 7] = v.raw[i + 0];
  }
  return ret;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Shuffle2301(Vec128<T, N> v) {
  static_assert(sizeof(T) == 4, "Only for 32-bit");
  static_assert(N == 2 || N == 4, "Does not make sense for N=1");
  return Reverse2(DFromV<decltype(v)>(), v);
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T> Shuffle1032(Vec128<T> v) {
  static_assert(sizeof(T) == 4, "Only for 32-bit");
  Vec128<T> ret;
  ret.raw[3] = v.raw[1];
  ret.raw[2] = v.raw[0];
  ret.raw[1] = v.raw[3];
  ret.raw[0] = v.raw[2];
  return ret;
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T> Shuffle01(Vec128<T> v) {
  static_assert(sizeof(T) == 8, "Only for 64-bit");
  return Reverse2(DFromV<decltype(v)>(), v);
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T> Shuffle0321(Vec128<T> v) {
  Vec128<T> ret;
  ret.raw[3] = v.raw[0];
  ret.raw[2] = v.raw[3];
  ret.raw[1] = v.raw[2];
  ret.raw[0] = v.raw[1];
  return ret;
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T> Shuffle2103(Vec128<T> v) {
  Vec128<T> ret;
  ret.raw[3] = v.raw[2];
  ret.raw[2] = v.raw[1];
  ret.raw[1] = v.raw[0];
  ret.raw[0] = v.raw[3];
  return ret;
}
template <typename T>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T> Shuffle0123(Vec128<T> v) {
  return Reverse4(DFromV<decltype(v)>(), v);
}
template <int kLane, typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Broadcast(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = v.raw[kLane];
  }
  return v;
}
template <typename T, size_t N, typename TI, size_t NI>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<TI, NI> TableLookupBytes(Vec128<T, N> v,
                                        Vec128<TI, NI> indices) {
  const uint8_t* __restrict__ v_bytes =
      reinterpret_cast<const uint8_t * __restrict__>(v.raw);
  const uint8_t* __restrict__ idx_bytes =
      reinterpret_cast<const uint8_t*>(indices.raw);
  Vec128<TI, NI> ret;
  uint8_t* __restrict__ ret_bytes =
      reinterpret_cast<uint8_t * __restrict__>(ret.raw);
  for (size_t i = 0; i < NI * sizeof(TI); ++i) {
    const size_t idx = idx_bytes[i];
    ret_bytes[i] = idx < sizeof(T) * N ? v_bytes[idx] : 0;
  }
  return ret;
}
template <typename T, size_t N, typename TI, size_t NI>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<TI, NI> TableLookupBytesOr0(Vec128<T, N> v,
                                           Vec128<TI, NI> indices) {
  return TableLookupBytes(v, indices);
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> InterleaveLower(Vec128<T, N> a, Vec128<T, N> b) {
  Vec128<T, N> ret;
  for (size_t i = 0; i < N / 2; ++i) {
    ret.raw[2 * i + 0] = a.raw[i];
    ret.raw[2 * i + 1] = b.raw[i];
  }
  return ret;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V InterleaveLower(DFromV<V> , V a, V b) {
  return InterleaveLower(a, b);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> InterleaveUpper(D d, VFromD<D> a, VFromD<D> b) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[2 * i + 0] = a.raw[MaxLanes(dh) + i];
    ret.raw[2 * i + 1] = b.raw[MaxLanes(dh) + i];
  }
  return ret;
}
template <class V, class DW = RepartitionToWide<DFromV<V>>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DW> ZipLower(V a, V b) {
  return BitCast(DW(), InterleaveLower(a, b));
}
template <class V, class D = DFromV<V>, class DW = RepartitionToWide<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DW> ZipLower(DW dw, V a, V b) {
  return BitCast(dw, InterleaveLower(D(), a, b));
}
template <class V, class D = DFromV<V>, class DW = RepartitionToWide<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<DW> ZipUpper(DW dw, V a, V b) {
  return BitCast(dw, InterleaveUpper(D(), a, b));
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) bool AllFalse(D d, MFromD<D> mask) {
  typename MFromD<D>::Raw or_sum = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    or_sum |= mask.bits[i];
  }
  return or_sum == 0;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) bool AllTrue(D d, MFromD<D> mask) {
  constexpr uint64_t kAll = LimitsMax<typename MFromD<D>::Raw>();
  uint64_t and_sum = kAll;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    and_sum &= mask.bits[i];
  }
  return and_sum == kAll;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) MFromD<D> LoadMaskBits(D d, const uint8_t* __restrict__ bits) {
  MFromD<D> m;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    const size_t bit = size_t{1} << (i & 7);
    const size_t idx_byte = i >> 3;
    m.bits[i] = MFromD<D>::FromBool((bits[idx_byte] & bit) != 0);
  }
  return m;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t StoreMaskBits(D d, MFromD<D> mask, uint8_t* bits) {
  bits[0] = 0;
  if (MaxLanes(d) > 8) bits[1] = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    const size_t bit = size_t{1} << (i & 7);
    const size_t idx_byte = i >> 3;
    if (mask.bits[i]) {
      bits[idx_byte] = static_cast<uint8_t>(bits[idx_byte] | bit);
    }
  }
  return MaxLanes(d) > 8 ? 2 : 1;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CountTrue(D d, MFromD<D> mask) {
  size_t count = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    count += mask.bits[i] != 0;
  }
  return count;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t FindKnownFirstTrue(D d, MFromD<D> mask) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (mask.bits[i] != 0) return i;
  }
  do { } while (0);
  return 0;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) intptr_t FindFirstTrue(D d, MFromD<D> mask) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (mask.bits[i] != 0) return static_cast<intptr_t>(i);
  }
  return intptr_t{-1};
}
template <typename T>
struct CompressIsPartition {
  enum { value = (sizeof(T) != 1) };
};
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Compress(Vec128<T, N> v, Mask128<T, N> mask) {
  size_t count = 0;
  Vec128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    if (mask.bits[i]) {
      ret.raw[count++] = v.raw[i];
    }
  }
  for (size_t i = 0; i < N; ++i) {
    if (!mask.bits[i]) {
      ret.raw[count++] = v.raw[i];
    }
  }
  do { } while (0);
  return ret;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> Expand(Vec128<T, N> v, const Mask128<T, N> mask) {
  size_t in_pos = 0;
  Vec128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    if (mask.bits[i]) {
      ret.raw[i] = v.raw[in_pos++];
    } else {
      ret.raw[i] = T();
    }
  }
  return ret;
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> LoadExpand(MFromD<D> mask, D d,
                             const TFromD<D>* __restrict__ unaligned) {
  size_t in_pos = 0;
  VFromD<D> ret;
  for (size_t i = 0; i < Lanes(d); ++i) {
    if (mask.bits[i]) {
      ret.raw[i] = unaligned[in_pos++];
    } else {
      ret.raw[i] = TFromD<D>();
    }
  }
  return ret;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> CompressNot(Vec128<T, N> v, Mask128<T, N> mask) {
  size_t count = 0;
  Vec128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    if (!mask.bits[i]) {
      ret.raw[count++] = v.raw[i];
    }
  }
  for (size_t i = 0; i < N; ++i) {
    if (mask.bits[i]) {
      ret.raw[count++] = v.raw[i];
    }
  }
  do { } while (0);
  return ret;
}
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<uint64_t> CompressBlocksNot(Vec128<uint64_t> v,
                                           Mask128<uint64_t> ) {
  return v;
}
template <typename T, size_t N>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec128<T, N> CompressBits(Vec128<T, N> v,
                                  const uint8_t* __restrict__ bits) {
  return Compress(v, LoadMaskBits(Simd<T, N, 0>(), bits));
}
template <class D, hwy::EnableIf<sizeof(TFromD<D>) != (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CompressStore(VFromD<D> v, MFromD<D> mask, D d,
                             TFromD<D>* __restrict__ unaligned) {
  size_t count = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (mask.bits[i]) {
      unaligned[count++] = v.raw[i];
    }
  }
  return count;
}
template <class D, hwy::EnableIf<sizeof(TFromD<D>) != (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CompressBlendedStore(VFromD<D> v, MFromD<D> mask, D d,
                                    TFromD<D>* __restrict__ unaligned) {
  return CompressStore(v, mask, d, unaligned);
}
template <class D, hwy::EnableIf<sizeof(TFromD<D>) != (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CompressBitsStore(VFromD<D> v, const uint8_t* __restrict__ bits,
                                 D d, TFromD<D>* __restrict__ unaligned) {
  const MFromD<D> mask = LoadMaskBits(d, bits);
  StoreU(Compress(v, mask), d, unaligned);
  return CountTrue(d, mask);
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, float>()>* = nullptr, size_t N, class VBF16>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ReorderWidenMulAccumulate(D df32, VBF16 a, VBF16 b,
                                            const Vec128<float, N> sum0,
                                            Vec128<float, N>& sum1) {
  const Rebind<uint32_t, decltype(df32)> du32;
  using VU32 = VFromD<decltype(du32)>;
  const VU32 odd = Set(du32, 0xFFFF0000u);
  const VU32 ae = ShiftLeft<16>(BitCast(du32, a));
  const VU32 ao = And(BitCast(du32, a), odd);
  const VU32 be = ShiftLeft<16>(BitCast(du32, b));
  const VU32 bo = And(BitCast(du32, b), odd);
  sum1 = MulAdd(BitCast(df32, ao), BitCast(df32, bo), sum1);
  return MulAdd(BitCast(df32, ae), BitCast(df32, be), sum0);
}
template <class D, hwy::EnableIf<IsSame<TFromD<D>, int32_t>()>* = nullptr, size_t N, class VI16>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> ReorderWidenMulAccumulate(D d32, VI16 a, VI16 b,
                                            const Vec128<int32_t, N> sum0,
                                            Vec128<int32_t, N>& sum1) {
  using VI32 = VFromD<decltype(d32)>;
  const VI32 ae = ShiftRight<16>(ShiftLeft<16>(BitCast(d32, a)));
  const VI32 be = ShiftRight<16>(ShiftLeft<16>(BitCast(d32, b)));
  const VI32 ao = ShiftRight<16>(BitCast(d32, a));
  const VI32 bo = ShiftRight<16>(BitCast(d32, b));
  sum1 = Add(Mul(ao, bo), sum1);
  return Add(Mul(ae, be), sum0);
}
template <class VW>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VW RearrangeToOddPlusEven(VW sum0, VW sum1) {
  return Add(sum0, sum1);
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> SumOfLanes(D d, VFromD<D> v) {
  T sum = T{0};
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    sum += v.raw[i];
  }
  return Set(d, sum);
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> MinOfLanes(D d, VFromD<D> v) {
  T min = HighestValue<T>();
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    min = ((min) < (v.raw[i]) ? (min) : (v.raw[i]));
  }
  return Set(d, min);
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) VFromD<D> MaxOfLanes(D d, VFromD<D> v) {
  T max = LowestValue<T>();
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    max = ((max) > (v.raw[i]) ? (max) : (v.raw[i]));
  }
  return Set(d, max);
}
inline __attribute__((always_inline)) Vec128<uint64_t> MulEven(Vec128<uint64_t> a, Vec128<uint64_t> b) {
  alignas(16) uint64_t mul[2];
  mul[0] = Mul128(GetLane(a), GetLane(b), &mul[1]);
  return Load(Full128<uint64_t>(), mul);
}
inline __attribute__((always_inline)) Vec128<uint64_t> MulOdd(Vec128<uint64_t> a, Vec128<uint64_t> b) {
  alignas(16) uint64_t mul[2];
  const Half<Full128<uint64_t>> d2;
  mul[0] =
      Mul128(GetLane(UpperHalf(d2, a)), GetLane(UpperHalf(d2, b)), &mul[1]);
  return Load(Full128<uint64_t>(), mul);
}
}
}
static_assert(true, "For requiring trailing semicolon");
static_assert(true, "For requiring trailing semicolon");
namespace hwy {
namespace N_EMU128 {
template <class V>
using LaneType = decltype(GetLane(V()));
template <class D>
using Vec = decltype(Zero(D()));
template <class D>
using Mask = decltype(MaskFromVec(Zero(D())));
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V Clamp(const V v, const V lo, const V hi) {
  return Min(Max(lo, v), hi);
}
template <size_t kLanes, class D, class V = VFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V CombineShiftRightLanes(D d, const V hi, const V lo) {
  constexpr size_t kBytes = kLanes * sizeof(LaneType<V>);
  static_assert(kBytes < 16, "Shift count is per-block");
  return CombineShiftRightBytes<kBytes>(d, hi, lo);
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec<D> SignBit(D d) {
  const RebindToUnsigned<decltype(d)> du;
  return BitCast(d, Set(du, SignMask<TFromD<D>>()));
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec<D> NaN(D d) {
  const RebindToSigned<D> di;
  return BitCast(d, Set(di, LimitsMax<TFromD<decltype(di)>>()));
}
template <class D>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec<D> Inf(D d) {
  const RebindToUnsigned<D> du;
  using T = TFromD<D>;
  using TU = TFromD<decltype(du)>;
  const TU max_x2 = static_cast<TU>(MaxExponentTimes2<T>());
  return BitCast(d, Set(du, max_x2 >> 1));
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void SafeFillN(const size_t num, const T value, D d,
                       T* __restrict__ to) {
  (void)d;
  for (size_t i = 0; i < num; ++i) {
    to[i] = value;
  }
}
template <class D, typename T = TFromD<D>>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) void SafeCopyN(const size_t num, D d, const T* __restrict__ from,
                       T* __restrict__ to) {
  (void)d;
  for (size_t i = 0; i < num; ++i) {
    to[i] = from[i];
  }
}
template <class V, hwy::EnableIf<!hwy::IsFloat<TFromV<V> >() && !hwy::IsSpecialFloat<TFromV<V> >()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V AbsDiff(V a, V b) {
  return Sub(Max(a, b), Min(a, b));
}
template <class V, hwy::EnableIf<IsSame<TFromD<DFromV<V> >, uint8_t>()>* = nullptr,
          hwy::EnableIf<(DFromV<V>::kPrivateLanes * sizeof(TFromD<DFromV<V> >) > ((1LL << 61) == (1LL << 62) ? 0 : 4))>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) Vec<Repartition<uint64_t, DFromV<V>>> SumsOf8AbsDiff(V a, V b) {
  return SumsOf8(AbsDiff(a, b));
}
namespace detail {
template <class V>
inline __attribute__((always_inline)) V SubBytes(V state) {
  const DFromV<V> du;
  const auto mask = Set(du, uint8_t{0xF});
  {
    alignas(16) static constexpr uint8_t basisL[16] = {
        0x00, 0x70, 0x2A, 0x5A, 0x98, 0xE8, 0xB2, 0xC2,
        0x08, 0x78, 0x22, 0x52, 0x90, 0xE0, 0xBA, 0xCA};
    alignas(16) static constexpr uint8_t basisU[16] = {
        0x00, 0x4D, 0x7C, 0x31, 0x7D, 0x30, 0x01, 0x4C,
        0x81, 0xCC, 0xFD, 0xB0, 0xFC, 0xB1, 0x80, 0xCD};
    const auto sL = And(state, mask);
    const auto sU = ShiftRight<4>(state);
    const auto gf4L = TableLookupBytes(LoadDup128(du, basisL), sL);
    const auto gf4U = TableLookupBytes(LoadDup128(du, basisU), sU);
    state = Xor(gf4L, gf4U);
  }
  alignas(16) static constexpr uint8_t kZetaInv[16] = {
      0x80, 7, 11, 15, 6, 10, 4, 1, 9, 8, 5, 2, 12, 14, 13, 3};
  alignas(16) static constexpr uint8_t kInv[16] = {
      0x80, 1, 8, 13, 15, 6, 5, 14, 2, 12, 11, 10, 9, 3, 7, 4};
  const auto tbl = LoadDup128(du, kInv);
  const auto sL = And(state, mask);
  const auto sU = ShiftRight<4>(state);
  const auto sX = Xor(sU, sL);
  const auto invL = TableLookupBytes(LoadDup128(du, kZetaInv), sL);
  const auto invU = TableLookupBytes(tbl, sU);
  const auto invX = TableLookupBytes(tbl, sX);
  const auto outL = Xor(sX, TableLookupBytesOr0(tbl, Xor(invL, invU)));
  const auto outU = Xor(sU, TableLookupBytesOr0(tbl, Xor(invL, invX)));
  alignas(16) static constexpr uint8_t kAffineL[16] = {
      0x00, 0xC7, 0xBD, 0x6F, 0x17, 0x6D, 0xD2, 0xD0,
      0x78, 0xA8, 0x02, 0xC5, 0x7A, 0xBF, 0xAA, 0x15};
  alignas(16) static constexpr uint8_t kAffineU[16] = {
      0x00, 0x6A, 0xBB, 0x5F, 0xA5, 0x74, 0xE4, 0xCF,
      0xFA, 0x35, 0x2B, 0x41, 0xD1, 0x90, 0x1E, 0x8E};
  const auto affL = TableLookupBytesOr0(LoadDup128(du, kAffineL), outL);
  const auto affU = TableLookupBytesOr0(LoadDup128(du, kAffineU), outU);
  return Xor(Xor(affL, affU), Set(du, uint8_t{0x63}));
}
}
namespace detail {
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V ShiftRows(const V state) {
  const DFromV<V> du;
  alignas(16) static constexpr uint8_t kShiftRow[16] = {
      0, 5, 10, 15,
      4, 9, 14, 3,
      8, 13, 2, 7,
      12, 1, 6, 11};
  const auto shift_row = LoadDup128(du, kShiftRow);
  return TableLookupBytes(state, shift_row);
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V MixColumns(const V state) {
  const DFromV<V> du;
  alignas(16) static constexpr uint8_t k2301[16] = {
      2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13};
  alignas(16) static constexpr uint8_t k1230[16] = {
      1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12};
  const RebindToSigned<decltype(du)> di;
  const auto msb = Lt(BitCast(di, state), Zero(di));
  const auto overflow = BitCast(du, IfThenElseZero(msb, Set(di, int8_t{0x1B})));
  const auto d = Xor(Add(state, state), overflow);
  const auto s2301 = TableLookupBytes(state, LoadDup128(du, k2301));
  const auto d_s2301 = Xor(d, s2301);
  const auto t_s2301 = Xor(state, d_s2301);
  const auto t1230_s3012 = TableLookupBytes(t_s2301, LoadDup128(du, k1230));
  return Xor(d_s2301, t1230_s3012);
}
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V AESRound(V state, const V round_key) {
  state = detail::SubBytes(state);
  state = detail::ShiftRows(state);
  state = detail::MixColumns(state);
  state = Xor(state, round_key);
  return state;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V AESLastRound(V state, const V round_key) {
  state = detail::SubBytes(state);
  state = detail::ShiftRows(state);
  state = Xor(state, round_key);
  return state;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V CLMulLower(V a, V b) {
  const DFromV<V> d;
  static_assert(IsSame<TFromD<decltype(d)>, uint64_t>(), "V must be u64");
  const auto k1 = Set(d, 0x1111111111111111ULL);
  const auto k2 = Set(d, 0x2222222222222222ULL);
  const auto k4 = Set(d, 0x4444444444444444ULL);
  const auto k8 = Set(d, 0x8888888888888888ULL);
  const auto a0 = And(a, k1);
  const auto a1 = And(a, k2);
  const auto a2 = And(a, k4);
  const auto a3 = And(a, k8);
  const auto b0 = And(b, k1);
  const auto b1 = And(b, k2);
  const auto b2 = And(b, k4);
  const auto b3 = And(b, k8);
  auto m0 = Xor(MulEven(a0, b0), MulEven(a1, b3));
  auto m1 = Xor(MulEven(a0, b1), MulEven(a1, b0));
  auto m2 = Xor(MulEven(a0, b2), MulEven(a1, b1));
  auto m3 = Xor(MulEven(a0, b3), MulEven(a1, b2));
  m0 = Xor(m0, Xor(MulEven(a2, b2), MulEven(a3, b1)));
  m1 = Xor(m1, Xor(MulEven(a2, b3), MulEven(a3, b2)));
  m2 = Xor(m2, Xor(MulEven(a2, b0), MulEven(a3, b3)));
  m3 = Xor(m3, Xor(MulEven(a2, b1), MulEven(a3, b0)));
  return Or(Or(And(m0, k1), And(m1, k2)), Or(And(m2, k4), And(m3, k8)));
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V CLMulUpper(V a, V b) {
  const DFromV<V> d;
  static_assert(IsSame<TFromD<decltype(d)>, uint64_t>(), "V must be u64");
  const auto k1 = Set(d, 0x1111111111111111ULL);
  const auto k2 = Set(d, 0x2222222222222222ULL);
  const auto k4 = Set(d, 0x4444444444444444ULL);
  const auto k8 = Set(d, 0x8888888888888888ULL);
  const auto a0 = And(a, k1);
  const auto a1 = And(a, k2);
  const auto a2 = And(a, k4);
  const auto a3 = And(a, k8);
  const auto b0 = And(b, k1);
  const auto b1 = And(b, k2);
  const auto b2 = And(b, k4);
  const auto b3 = And(b, k8);
  auto m0 = Xor(MulOdd(a0, b0), MulOdd(a1, b3));
  auto m1 = Xor(MulOdd(a0, b1), MulOdd(a1, b0));
  auto m2 = Xor(MulOdd(a0, b2), MulOdd(a1, b1));
  auto m3 = Xor(MulOdd(a0, b3), MulOdd(a1, b2));
  m0 = Xor(m0, Xor(MulOdd(a2, b2), MulOdd(a3, b1)));
  m1 = Xor(m1, Xor(MulOdd(a2, b3), MulOdd(a3, b2)));
  m2 = Xor(m2, Xor(MulOdd(a2, b0), MulOdd(a3, b3)));
  m3 = Xor(m3, Xor(MulOdd(a2, b1), MulOdd(a3, b0)));
  return Or(Or(And(m0, k1), And(m1, k2)), Or(And(m2, k4), And(m3, k8)));
}
template <class V, class D = DFromV<V>, hwy::EnableIf<IsSame<TFromD<D>, uint8_t>()>* = nullptr,
          hwy::EnableIf<(D::kPrivateLanes * sizeof(TFromD<D>) > 8)>* = nullptr, void* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V PopulationCount(V v) {
  const D d;
  alignas(16) constexpr uint8_t kLookup[16] = {
      0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
  };
  const auto lo = And(v, Set(d, uint8_t{0xF}));
  const auto hi = ShiftRight<4>(v);
  const auto lookup = LoadDup128(d, kLookup);
  return Add(TableLookupBytes(lookup, hi), TableLookupBytes(lookup, lo));
}
template <class V, class D = DFromV<V>, hwy::EnableIf<IsSame<TFromD<D>, uint8_t>()>* = nullptr,
          hwy::EnableIf<D::kPrivateLanes * sizeof(TFromD<D>) <= 8>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V PopulationCount(V v) {
  const D d;
  const V k33 = Set(d, uint8_t{0x33});
  v = Sub(v, And(ShiftRight<1>(v), Set(d, uint8_t{0x55})));
  v = Add(And(ShiftRight<2>(v), k33), And(v, k33));
  return And(Add(v, ShiftRight<4>(v)), Set(d, uint8_t{0x0F}));
}
template <class V, class D = DFromV<V>, hwy::EnableIf<IsSame<TFromD<D>, uint16_t>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V PopulationCount(V v) {
  const D d;
  const Repartition<uint8_t, decltype(d)> d8;
  const auto vals = BitCast(d, PopulationCount(BitCast(d8, v)));
  return Add(ShiftRight<8>(vals), And(vals, Set(d, uint16_t{0xFF})));
}
template <class V, class D = DFromV<V>, hwy::EnableIf<IsSame<TFromD<D>, uint32_t>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V PopulationCount(V v) {
  const D d;
  Repartition<uint16_t, decltype(d)> d16;
  auto vals = BitCast(d, PopulationCount(BitCast(d16, v)));
  return Add(ShiftRight<16>(vals), And(vals, Set(d, uint32_t{0xFF})));
}
template <class V, class D = DFromV<V>, hwy::EnableIf<IsSame<TFromD<D>, uint64_t>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V PopulationCount(V v) {
  const D d;
  Repartition<uint32_t, decltype(d)> d32;
  auto vals = BitCast(d, PopulationCount(BitCast(d32, v)));
  return Add(ShiftRight<32>(vals), And(vals, Set(d, 0xFFULL)));
}
template <class V, hwy::EnableIf<DFromV<V>::kPrivateLanes * sizeof(TFromV<V>) == 8>* = nullptr, hwy::EnableIf<IsSame<TFromD<DFromV<V> >, double>()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V operator*(V x, V y) {
  return Set(DFromV<V>(), GetLane(x) * GetLane(y));
}
template <class V, hwy::EnableIf<sizeof(TFromV<V>) == (8)>* = nullptr, hwy::EnableIf<DFromV<V>::kPrivateLanes * sizeof(TFromV<V>) == 8>* = nullptr,
          hwy::EnableIf<!hwy::IsFloat<TFromV<V> >()>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V operator*(V x, V y) {
  const DFromV<V> d;
  using T = TFromD<decltype(d)>;
  using TU = MakeUnsigned<T>;
  const TU xu = static_cast<TU>(GetLane(x));
  const TU yu = static_cast<TU>(GetLane(y));
  return Set(d, static_cast<T>(xu * yu));
}
template <class V, class D64 = DFromV<V>, hwy::EnableIf<IsSame<TFromD<D64>, uint64_t>()>* = nullptr,
          hwy::EnableIf<(D64::kPrivateLanes * sizeof(TFromD<D64>) > 8)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V operator*(V x, V y) {
  RepartitionToNarrow<D64> d32;
  auto x32 = BitCast(d32, x);
  auto y32 = BitCast(d32, y);
  auto lolo = BitCast(d32, MulEven(x32, y32));
  auto lohi = BitCast(d32, MulEven(x32, BitCast(d32, ShiftRight<32>(y))));
  auto hilo = BitCast(d32, MulEven(BitCast(d32, ShiftRight<32>(x)), y32));
  auto hi = BitCast(d32, ShiftLeft<32>(BitCast(D64{}, lohi + hilo)));
  return BitCast(D64{}, lolo + hi);
}
template <class V, class DI64 = DFromV<V>, hwy::EnableIf<IsSame<TFromD<DI64>, int64_t>()>* = nullptr,
          hwy::EnableIf<(DI64::kPrivateLanes * sizeof(TFromD<DI64>) > 8)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V operator*(V x, V y) {
  RebindToUnsigned<DI64> du64;
  return BitCast(DI64{}, BitCast(du64, x) * BitCast(du64, y));
}
template <class V, class D, typename T, hwy::EnableIf<sizeof(T) == (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CompressBitsStore(V v, const uint8_t* __restrict__ bits, D d,
                                 T* unaligned) {
  alignas(16) T lanes[MaxLanes(d)];
  Store(v, d, lanes);
  const Simd<T, ((MaxLanes(d)) < (8) ? (MaxLanes(d)) : (8)), 0> d8;
  T* __restrict__ pos = unaligned;
  alignas(16) constexpr T table[2048] = {
      0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      1, 0, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      2, 0, 1, 3, 4, 5, 6, 7, 0, 2, 1, 3, 4, 5, 6, 7,
      1, 2, 0, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      3, 0, 1, 2, 4, 5, 6, 7, 0, 3, 1, 2, 4, 5, 6, 7,
      1, 3, 0, 2, 4, 5, 6, 7, 0, 1, 3, 2, 4, 5, 6, 7,
      2, 3, 0, 1, 4, 5, 6, 7, 0, 2, 3, 1, 4, 5, 6, 7,
      1, 2, 3, 0, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      4, 0, 1, 2, 3, 5, 6, 7, 0, 4, 1, 2, 3, 5, 6, 7,
      1, 4, 0, 2, 3, 5, 6, 7, 0, 1, 4, 2, 3, 5, 6, 7,
      2, 4, 0, 1, 3, 5, 6, 7, 0, 2, 4, 1, 3, 5, 6, 7,
      1, 2, 4, 0, 3, 5, 6, 7, 0, 1, 2, 4, 3, 5, 6, 7,
      3, 4, 0, 1, 2, 5, 6, 7, 0, 3, 4, 1, 2, 5, 6, 7,
      1, 3, 4, 0, 2, 5, 6, 7, 0, 1, 3, 4, 2, 5, 6, 7,
      2, 3, 4, 0, 1, 5, 6, 7, 0, 2, 3, 4, 1, 5, 6, 7,
      1, 2, 3, 4, 0, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      5, 0, 1, 2, 3, 4, 6, 7, 0, 5, 1, 2, 3, 4, 6, 7,
      1, 5, 0, 2, 3, 4, 6, 7, 0, 1, 5, 2, 3, 4, 6, 7,
      2, 5, 0, 1, 3, 4, 6, 7, 0, 2, 5, 1, 3, 4, 6, 7,
      1, 2, 5, 0, 3, 4, 6, 7, 0, 1, 2, 5, 3, 4, 6, 7,
      3, 5, 0, 1, 2, 4, 6, 7, 0, 3, 5, 1, 2, 4, 6, 7,
      1, 3, 5, 0, 2, 4, 6, 7, 0, 1, 3, 5, 2, 4, 6, 7,
      2, 3, 5, 0, 1, 4, 6, 7, 0, 2, 3, 5, 1, 4, 6, 7,
      1, 2, 3, 5, 0, 4, 6, 7, 0, 1, 2, 3, 5, 4, 6, 7,
      4, 5, 0, 1, 2, 3, 6, 7, 0, 4, 5, 1, 2, 3, 6, 7,
      1, 4, 5, 0, 2, 3, 6, 7, 0, 1, 4, 5, 2, 3, 6, 7,
      2, 4, 5, 0, 1, 3, 6, 7, 0, 2, 4, 5, 1, 3, 6, 7,
      1, 2, 4, 5, 0, 3, 6, 7, 0, 1, 2, 4, 5, 3, 6, 7,
      3, 4, 5, 0, 1, 2, 6, 7, 0, 3, 4, 5, 1, 2, 6, 7,
      1, 3, 4, 5, 0, 2, 6, 7, 0, 1, 3, 4, 5, 2, 6, 7,
      2, 3, 4, 5, 0, 1, 6, 7, 0, 2, 3, 4, 5, 1, 6, 7,
      1, 2, 3, 4, 5, 0, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      6, 0, 1, 2, 3, 4, 5, 7, 0, 6, 1, 2, 3, 4, 5, 7,
      1, 6, 0, 2, 3, 4, 5, 7, 0, 1, 6, 2, 3, 4, 5, 7,
      2, 6, 0, 1, 3, 4, 5, 7, 0, 2, 6, 1, 3, 4, 5, 7,
      1, 2, 6, 0, 3, 4, 5, 7, 0, 1, 2, 6, 3, 4, 5, 7,
      3, 6, 0, 1, 2, 4, 5, 7, 0, 3, 6, 1, 2, 4, 5, 7,
      1, 3, 6, 0, 2, 4, 5, 7, 0, 1, 3, 6, 2, 4, 5, 7,
      2, 3, 6, 0, 1, 4, 5, 7, 0, 2, 3, 6, 1, 4, 5, 7,
      1, 2, 3, 6, 0, 4, 5, 7, 0, 1, 2, 3, 6, 4, 5, 7,
      4, 6, 0, 1, 2, 3, 5, 7, 0, 4, 6, 1, 2, 3, 5, 7,
      1, 4, 6, 0, 2, 3, 5, 7, 0, 1, 4, 6, 2, 3, 5, 7,
      2, 4, 6, 0, 1, 3, 5, 7, 0, 2, 4, 6, 1, 3, 5, 7,
      1, 2, 4, 6, 0, 3, 5, 7, 0, 1, 2, 4, 6, 3, 5, 7,
      3, 4, 6, 0, 1, 2, 5, 7, 0, 3, 4, 6, 1, 2, 5, 7,
      1, 3, 4, 6, 0, 2, 5, 7, 0, 1, 3, 4, 6, 2, 5, 7,
      2, 3, 4, 6, 0, 1, 5, 7, 0, 2, 3, 4, 6, 1, 5, 7,
      1, 2, 3, 4, 6, 0, 5, 7, 0, 1, 2, 3, 4, 6, 5, 7,
      5, 6, 0, 1, 2, 3, 4, 7, 0, 5, 6, 1, 2, 3, 4, 7,
      1, 5, 6, 0, 2, 3, 4, 7, 0, 1, 5, 6, 2, 3, 4, 7,
      2, 5, 6, 0, 1, 3, 4, 7, 0, 2, 5, 6, 1, 3, 4, 7,
      1, 2, 5, 6, 0, 3, 4, 7, 0, 1, 2, 5, 6, 3, 4, 7,
      3, 5, 6, 0, 1, 2, 4, 7, 0, 3, 5, 6, 1, 2, 4, 7,
      1, 3, 5, 6, 0, 2, 4, 7, 0, 1, 3, 5, 6, 2, 4, 7,
      2, 3, 5, 6, 0, 1, 4, 7, 0, 2, 3, 5, 6, 1, 4, 7,
      1, 2, 3, 5, 6, 0, 4, 7, 0, 1, 2, 3, 5, 6, 4, 7,
      4, 5, 6, 0, 1, 2, 3, 7, 0, 4, 5, 6, 1, 2, 3, 7,
      1, 4, 5, 6, 0, 2, 3, 7, 0, 1, 4, 5, 6, 2, 3, 7,
      2, 4, 5, 6, 0, 1, 3, 7, 0, 2, 4, 5, 6, 1, 3, 7,
      1, 2, 4, 5, 6, 0, 3, 7, 0, 1, 2, 4, 5, 6, 3, 7,
      3, 4, 5, 6, 0, 1, 2, 7, 0, 3, 4, 5, 6, 1, 2, 7,
      1, 3, 4, 5, 6, 0, 2, 7, 0, 1, 3, 4, 5, 6, 2, 7,
      2, 3, 4, 5, 6, 0, 1, 7, 0, 2, 3, 4, 5, 6, 1, 7,
      1, 2, 3, 4, 5, 6, 0, 7, 0, 1, 2, 3, 4, 5, 6, 7,
      7, 0, 1, 2, 3, 4, 5, 6, 0, 7, 1, 2, 3, 4, 5, 6,
      1, 7, 0, 2, 3, 4, 5, 6, 0, 1, 7, 2, 3, 4, 5, 6,
      2, 7, 0, 1, 3, 4, 5, 6, 0, 2, 7, 1, 3, 4, 5, 6,
      1, 2, 7, 0, 3, 4, 5, 6, 0, 1, 2, 7, 3, 4, 5, 6,
      3, 7, 0, 1, 2, 4, 5, 6, 0, 3, 7, 1, 2, 4, 5, 6,
      1, 3, 7, 0, 2, 4, 5, 6, 0, 1, 3, 7, 2, 4, 5, 6,
      2, 3, 7, 0, 1, 4, 5, 6, 0, 2, 3, 7, 1, 4, 5, 6,
      1, 2, 3, 7, 0, 4, 5, 6, 0, 1, 2, 3, 7, 4, 5, 6,
      4, 7, 0, 1, 2, 3, 5, 6, 0, 4, 7, 1, 2, 3, 5, 6,
      1, 4, 7, 0, 2, 3, 5, 6, 0, 1, 4, 7, 2, 3, 5, 6,
      2, 4, 7, 0, 1, 3, 5, 6, 0, 2, 4, 7, 1, 3, 5, 6,
      1, 2, 4, 7, 0, 3, 5, 6, 0, 1, 2, 4, 7, 3, 5, 6,
      3, 4, 7, 0, 1, 2, 5, 6, 0, 3, 4, 7, 1, 2, 5, 6,
      1, 3, 4, 7, 0, 2, 5, 6, 0, 1, 3, 4, 7, 2, 5, 6,
      2, 3, 4, 7, 0, 1, 5, 6, 0, 2, 3, 4, 7, 1, 5, 6,
      1, 2, 3, 4, 7, 0, 5, 6, 0, 1, 2, 3, 4, 7, 5, 6,
      5, 7, 0, 1, 2, 3, 4, 6, 0, 5, 7, 1, 2, 3, 4, 6,
      1, 5, 7, 0, 2, 3, 4, 6, 0, 1, 5, 7, 2, 3, 4, 6,
      2, 5, 7, 0, 1, 3, 4, 6, 0, 2, 5, 7, 1, 3, 4, 6,
      1, 2, 5, 7, 0, 3, 4, 6, 0, 1, 2, 5, 7, 3, 4, 6,
      3, 5, 7, 0, 1, 2, 4, 6, 0, 3, 5, 7, 1, 2, 4, 6,
      1, 3, 5, 7, 0, 2, 4, 6, 0, 1, 3, 5, 7, 2, 4, 6,
      2, 3, 5, 7, 0, 1, 4, 6, 0, 2, 3, 5, 7, 1, 4, 6,
      1, 2, 3, 5, 7, 0, 4, 6, 0, 1, 2, 3, 5, 7, 4, 6,
      4, 5, 7, 0, 1, 2, 3, 6, 0, 4, 5, 7, 1, 2, 3, 6,
      1, 4, 5, 7, 0, 2, 3, 6, 0, 1, 4, 5, 7, 2, 3, 6,
      2, 4, 5, 7, 0, 1, 3, 6, 0, 2, 4, 5, 7, 1, 3, 6,
      1, 2, 4, 5, 7, 0, 3, 6, 0, 1, 2, 4, 5, 7, 3, 6,
      3, 4, 5, 7, 0, 1, 2, 6, 0, 3, 4, 5, 7, 1, 2, 6,
      1, 3, 4, 5, 7, 0, 2, 6, 0, 1, 3, 4, 5, 7, 2, 6,
      2, 3, 4, 5, 7, 0, 1, 6, 0, 2, 3, 4, 5, 7, 1, 6,
      1, 2, 3, 4, 5, 7, 0, 6, 0, 1, 2, 3, 4, 5, 7, 6,
      6, 7, 0, 1, 2, 3, 4, 5, 0, 6, 7, 1, 2, 3, 4, 5,
      1, 6, 7, 0, 2, 3, 4, 5, 0, 1, 6, 7, 2, 3, 4, 5,
      2, 6, 7, 0, 1, 3, 4, 5, 0, 2, 6, 7, 1, 3, 4, 5,
      1, 2, 6, 7, 0, 3, 4, 5, 0, 1, 2, 6, 7, 3, 4, 5,
      3, 6, 7, 0, 1, 2, 4, 5, 0, 3, 6, 7, 1, 2, 4, 5,
      1, 3, 6, 7, 0, 2, 4, 5, 0, 1, 3, 6, 7, 2, 4, 5,
      2, 3, 6, 7, 0, 1, 4, 5, 0, 2, 3, 6, 7, 1, 4, 5,
      1, 2, 3, 6, 7, 0, 4, 5, 0, 1, 2, 3, 6, 7, 4, 5,
      4, 6, 7, 0, 1, 2, 3, 5, 0, 4, 6, 7, 1, 2, 3, 5,
      1, 4, 6, 7, 0, 2, 3, 5, 0, 1, 4, 6, 7, 2, 3, 5,
      2, 4, 6, 7, 0, 1, 3, 5, 0, 2, 4, 6, 7, 1, 3, 5,
      1, 2, 4, 6, 7, 0, 3, 5, 0, 1, 2, 4, 6, 7, 3, 5,
      3, 4, 6, 7, 0, 1, 2, 5, 0, 3, 4, 6, 7, 1, 2, 5,
      1, 3, 4, 6, 7, 0, 2, 5, 0, 1, 3, 4, 6, 7, 2, 5,
      2, 3, 4, 6, 7, 0, 1, 5, 0, 2, 3, 4, 6, 7, 1, 5,
      1, 2, 3, 4, 6, 7, 0, 5, 0, 1, 2, 3, 4, 6, 7, 5,
      5, 6, 7, 0, 1, 2, 3, 4, 0, 5, 6, 7, 1, 2, 3, 4,
      1, 5, 6, 7, 0, 2, 3, 4, 0, 1, 5, 6, 7, 2, 3, 4,
      2, 5, 6, 7, 0, 1, 3, 4, 0, 2, 5, 6, 7, 1, 3, 4,
      1, 2, 5, 6, 7, 0, 3, 4, 0, 1, 2, 5, 6, 7, 3, 4,
      3, 5, 6, 7, 0, 1, 2, 4, 0, 3, 5, 6, 7, 1, 2, 4,
      1, 3, 5, 6, 7, 0, 2, 4, 0, 1, 3, 5, 6, 7, 2, 4,
      2, 3, 5, 6, 7, 0, 1, 4, 0, 2, 3, 5, 6, 7, 1, 4,
      1, 2, 3, 5, 6, 7, 0, 4, 0, 1, 2, 3, 5, 6, 7, 4,
      4, 5, 6, 7, 0, 1, 2, 3, 0, 4, 5, 6, 7, 1, 2, 3,
      1, 4, 5, 6, 7, 0, 2, 3, 0, 1, 4, 5, 6, 7, 2, 3,
      2, 4, 5, 6, 7, 0, 1, 3, 0, 2, 4, 5, 6, 7, 1, 3,
      1, 2, 4, 5, 6, 7, 0, 3, 0, 1, 2, 4, 5, 6, 7, 3,
      3, 4, 5, 6, 7, 0, 1, 2, 0, 3, 4, 5, 6, 7, 1, 2,
      1, 3, 4, 5, 6, 7, 0, 2, 0, 1, 3, 4, 5, 6, 7, 2,
      2, 3, 4, 5, 6, 7, 0, 1, 0, 2, 3, 4, 5, 6, 7, 1,
      1, 2, 3, 4, 5, 6, 7, 0, 0, 1, 2, 3, 4, 5, 6, 7};
  for (size_t i = 0; i < Lanes(d); i += 8) {
    const size_t bits8 = bits[i / 8];
    const auto indices = Load(d8, table + bits8 * 8);
    const auto compressed = TableLookupBytes(LoadU(d8, lanes + i), indices);
    StoreU(compressed, d8, pos);
    pos += PopCount(bits8);
  }
  return static_cast<size_t>(pos - unaligned);
}
template <class V, class M, class D, typename T, hwy::EnableIf<sizeof(T) == (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CompressStore(V v, M mask, D d, T* __restrict__ unaligned) {
  uint8_t bits[((size_t{8}) > (MaxLanes(d) / 8) ? (size_t{8}) : (MaxLanes(d) / 8))];
  (void)StoreMaskBits(d, mask, bits);
  return CompressBitsStore(v, bits, d, unaligned);
}
template <class V, class M, class D, typename T, hwy::EnableIf<sizeof(T) == (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) size_t CompressBlendedStore(V v, M mask, D d,
                                    T* __restrict__ unaligned) {
  alignas(16) T buf[MaxLanes(d)];
  const size_t bytes = CompressStore(v, mask, d, buf);
  BlendedStore(Load(d, buf), FirstN(d, bytes), d, unaligned);
  return bytes;
}
template <class V, class M, typename T = TFromV<V>, hwy::EnableIf<sizeof(T) == (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V Compress(V v, const M mask) {
  const DFromV<V> d;
  alignas(16) T lanes[MaxLanes(d)];
  (void)CompressStore(v, mask, d, lanes);
  return Load(d, lanes);
}
template <class V, typename T = TFromV<V>, hwy::EnableIf<sizeof(T) == (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V CompressBits(V v, const uint8_t* __restrict__ bits) {
  const DFromV<V> d;
  alignas(16) T lanes[MaxLanes(d)];
  (void)CompressBitsStore(v, bits, d, lanes);
  return Load(d, lanes);
}
template <class V, class M, typename T = TFromV<V>, hwy::EnableIf<sizeof(T) == (1)>* = nullptr>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V CompressNot(V v, M mask) {
  return Compress(v, Not(mask));
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V Add(V a, V b) {
  return a + b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V Sub(V a, V b) {
  return a - b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V Mul(V a, V b) {
  return a * b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) V Div(V a, V b) {
  return a / b;
}
template <class V>
V Shl(V a, V b) {
  return a << b;
}
template <class V>
V Shr(V a, V b) {
  return a >> b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) auto Eq(V a, V b) -> decltype(a == b) {
  return a == b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) auto Ne(V a, V b) -> decltype(a == b) {
  return a != b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) auto Lt(V a, V b) -> decltype(a == b) {
  return a < b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) auto Gt(V a, V b) -> decltype(a == b) {
  return a > b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) auto Ge(V a, V b) -> decltype(a == b) {
  return a >= b;
}
template <class V>
static inline __attribute__((always_inline)) __attribute__((flatten)) __attribute__((unused)) auto Le(V a, V b) -> decltype(a == b) {
  return a <= b;
}
}
}
static_assert(true, "For requiring trailing semicolon");
static_assert(true, "For requiring trailing semicolon");
namespace hwy {
namespace N_EMU128 {
template <class D, class V>
inline __attribute__((always_inline)) V Acos(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallAcos(const D d, VecArg<V> x) {
  return Acos(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Acosh(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallAcosh(const D d, VecArg<V> x) {
  return Acosh(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Asin(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallAsin(const D d, VecArg<V> x) {
  return Asin(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Asinh(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallAsinh(const D d, VecArg<V> x) {
  return Asinh(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Atan(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallAtan(const D d, VecArg<V> x) {
  return Atan(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Atanh(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallAtanh(const D d, VecArg<V> x) {
  return Atanh(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Cos(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallCos(const D d, VecArg<V> x) {
  return Cos(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Exp(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallExp(const D d, VecArg<V> x) {
  return Exp(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Expm1(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallExpm1(const D d, VecArg<V> x) {
  return Expm1(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallLog(const D d, VecArg<V> x) {
  return Log(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log10(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallLog10(const D d, VecArg<V> x) {
  return Log10(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log1p(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallLog1p(const D d, VecArg<V> x) {
  return Log1p(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log2(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallLog2(const D d, VecArg<V> x) {
  return Log2(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Sin(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallSin(const D d, VecArg<V> x) {
  return Sin(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Sinh(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallSinh(const D d, VecArg<V> x) {
  return Sinh(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Tanh(const D d, V x);
template <class D, class V>
__attribute__((noinline)) V CallTanh(const D d, VecArg<V> x) {
  return Tanh(d, x);
}
namespace impl {
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1) {
  return MulAdd(c1, x, c0);
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2) {
  T x2 = Mul(x, x);
  return MulAdd(x2, c2, MulAdd(c1, x, c0));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3) {
  T x2 = Mul(x, x);
  return MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  return MulAdd(x4, c4, MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  return MulAdd(x4, MulAdd(c5, x, c4),
                MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  return MulAdd(x4, MulAdd(x2, c6, MulAdd(c5, x, c4)),
                MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  return MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8, c8,
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8, MulAdd(c9, x, c8),
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8, MulAdd(x2, c10, MulAdd(c9, x, c8)),
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8, MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8)),
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(
      x8, MulAdd(x4, c12, MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
      MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
             MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12, T c13) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8,
                MulAdd(x4, MulAdd(c13, x, c12),
                       MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12, T c13, T c14) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8,
                MulAdd(x4, MulAdd(x2, c14, MulAdd(c13, x, c12)),
                       MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12, T c13, T c14, T c15) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  return MulAdd(x8,
                MulAdd(x4, MulAdd(x2, MulAdd(c15, x, c14), MulAdd(c13, x, c12)),
                       MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
                MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                       MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12, T c13, T c14, T c15, T c16) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  T x16 = Mul(x8, x8);
  return MulAdd(
      x16, c16,
      MulAdd(x8,
             MulAdd(x4, MulAdd(x2, MulAdd(c15, x, c14), MulAdd(c13, x, c12)),
                    MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
             MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                    MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12, T c13, T c14, T c15, T c16, T c17) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  T x16 = Mul(x8, x8);
  return MulAdd(
      x16, MulAdd(c17, x, c16),
      MulAdd(x8,
             MulAdd(x4, MulAdd(x2, MulAdd(c15, x, c14), MulAdd(c13, x, c12)),
                    MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
             MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                    MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)))));
}
template <class T>
inline __attribute__((always_inline)) __attribute__((unused)) T Estrin(T x, T c0, T c1, T c2, T c3, T c4, T c5,
                                     T c6, T c7, T c8, T c9, T c10, T c11,
                                     T c12, T c13, T c14, T c15, T c16, T c17,
                                     T c18) {
  T x2 = Mul(x, x);
  T x4 = Mul(x2, x2);
  T x8 = Mul(x4, x4);
  T x16 = Mul(x8, x8);
  return MulAdd(
      x16, MulAdd(x2, c18, MulAdd(c17, x, c16)),
      MulAdd(x8,
             MulAdd(x4, MulAdd(x2, MulAdd(c15, x, c14), MulAdd(c13, x, c12)),
                    MulAdd(x2, MulAdd(c11, x, c10), MulAdd(c9, x, c8))),
             MulAdd(x4, MulAdd(x2, MulAdd(c7, x, c6), MulAdd(c5, x, c4)),
                    MulAdd(x2, MulAdd(c3, x, c2), MulAdd(c1, x, c0)))));
}
template <class FloatOrDouble>
struct AsinImpl {};
template <class FloatOrDouble>
struct AtanImpl {};
template <class FloatOrDouble>
struct CosSinImpl {};
template <class FloatOrDouble>
struct ExpImpl {};
template <class FloatOrDouble>
struct LogImpl {};
template <>
struct AsinImpl<float> {
  template <class D, class V>
  inline __attribute__((always_inline)) V AsinPoly(D d, V x2, V ) {
    const auto k0 = Set(d, +0.1666677296f);
    const auto k1 = Set(d, +0.07495029271f);
    const auto k2 = Set(d, +0.04547423869f);
    const auto k3 = Set(d, +0.02424046025f);
    const auto k4 = Set(d, +0.04197454825f);
    return Estrin(x2, k0, k1, k2, k3, k4);
  }
};
template <>
struct AsinImpl<double> {
  template <class D, class V>
  inline __attribute__((always_inline)) V AsinPoly(D d, V x2, V ) {
    const auto k0 = Set(d, +0.1666666666666497543);
    const auto k1 = Set(d, +0.07500000000378581611);
    const auto k2 = Set(d, +0.04464285681377102438);
    const auto k3 = Set(d, +0.03038195928038132237);
    const auto k4 = Set(d, +0.02237176181932048341);
    const auto k5 = Set(d, +0.01735956991223614604);
    const auto k6 = Set(d, +0.01388715184501609218);
    const auto k7 = Set(d, +0.01215360525577377331);
    const auto k8 = Set(d, +0.006606077476277170610);
    const auto k9 = Set(d, +0.01929045477267910674);
    const auto k10 = Set(d, -0.01581918243329996643);
    const auto k11 = Set(d, +0.03161587650653934628);
    return Estrin(x2, k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11);
  }
};
template <>
struct AtanImpl<float> {
  template <class D, class V>
  inline __attribute__((always_inline)) V AtanPoly(D d, V x) {
    const auto k0 = Set(d, -0.333331018686294555664062f);
    const auto k1 = Set(d, +0.199926957488059997558594f);
    const auto k2 = Set(d, -0.142027363181114196777344f);
    const auto k3 = Set(d, +0.106347933411598205566406f);
    const auto k4 = Set(d, -0.0748900920152664184570312f);
    const auto k5 = Set(d, +0.0425049886107444763183594f);
    const auto k6 = Set(d, -0.0159569028764963150024414f);
    const auto k7 = Set(d, +0.00282363896258175373077393f);
    const auto y = Mul(x, x);
    return MulAdd(Estrin(y, k0, k1, k2, k3, k4, k5, k6, k7), Mul(y, x), x);
  }
};
template <>
struct AtanImpl<double> {
  template <class D, class V>
  inline __attribute__((always_inline)) V AtanPoly(D d, V x) {
    const auto k0 = Set(d, -0.333333333333311110369124);
    const auto k1 = Set(d, +0.199999999996591265594148);
    const auto k2 = Set(d, -0.14285714266771329383765);
    const auto k3 = Set(d, +0.111111105648261418443745);
    const auto k4 = Set(d, -0.090908995008245008229153);
    const auto k5 = Set(d, +0.0769219538311769618355029);
    const auto k6 = Set(d, -0.0666573579361080525984562);
    const auto k7 = Set(d, +0.0587666392926673580854313);
    const auto k8 = Set(d, -0.0523674852303482457616113);
    const auto k9 = Set(d, +0.0466667150077840625632675);
    const auto k10 = Set(d, -0.0407629191276836500001934);
    const auto k11 = Set(d, +0.0337852580001353069993897);
    const auto k12 = Set(d, -0.0254517624932312641616861);
    const auto k13 = Set(d, +0.016599329773529201970117);
    const auto k14 = Set(d, -0.00889896195887655491740809);
    const auto k15 = Set(d, +0.00370026744188713119232403);
    const auto k16 = Set(d, -0.00110611831486672482563471);
    const auto k17 = Set(d, +0.000209850076645816976906797);
    const auto k18 = Set(d, -1.88796008463073496563746e-5);
    const auto y = Mul(x, x);
    return MulAdd(Estrin(y, k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11,
                         k12, k13, k14, k15, k16, k17, k18),
                  Mul(y, x), x);
  }
};
template <>
struct CosSinImpl<float> {
  template <class D, class V>
  inline __attribute__((always_inline)) Vec<Rebind<int32_t, D>> ToInt32(D , V x) {
    return ConvertTo(Rebind<int32_t, D>(), x);
  }
  template <class D, class V>
  inline __attribute__((always_inline)) V Poly(D d, V x) {
    const auto k0 = Set(d, -1.66666597127914428710938e-1f);
    const auto k1 = Set(d, +8.33307858556509017944336e-3f);
    const auto k2 = Set(d, -1.981069071916863322258e-4f);
    const auto k3 = Set(d, +2.6083159809786593541503e-6f);
    const auto y = Mul(x, x);
    return MulAdd(Estrin(y, k0, k1, k2, k3), Mul(y, x), x);
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V CosReduce(D d, V x, VI32 q) {
    const V kHalfPiPart0f = Set(d, -0.5f * 3.140625f);
    const V kHalfPiPart1f = Set(d, -0.5f * 0.0009670257568359375f);
    const V kHalfPiPart2f = Set(d, -0.5f * 6.2771141529083251953e-7f);
    const V kHalfPiPart3f = Set(d, -0.5f * 1.2154201256553420762e-10f);
    const V qf = ConvertTo(d, q);
    x = MulAdd(qf, kHalfPiPart0f, x);
    x = MulAdd(qf, kHalfPiPart1f, x);
    x = MulAdd(qf, kHalfPiPart2f, x);
    x = MulAdd(qf, kHalfPiPart3f, x);
    return x;
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V SinReduce(D d, V x, VI32 q) {
    const V kPiPart0f = Set(d, -3.140625f);
    const V kPiPart1f = Set(d, -0.0009670257568359375f);
    const V kPiPart2f = Set(d, -6.2771141529083251953e-7f);
    const V kPiPart3f = Set(d, -1.2154201256553420762e-10f);
    const V qf = ConvertTo(d, q);
    x = MulAdd(qf, kPiPart0f, x);
    x = MulAdd(qf, kPiPart1f, x);
    x = MulAdd(qf, kPiPart2f, x);
    x = MulAdd(qf, kPiPart3f, x);
    return x;
  }
  template <class D, class VI32>
  inline __attribute__((always_inline)) Vec<Rebind<float, D>> CosSignFromQuadrant(D d, VI32 q) {
    const VI32 kTwo = Set(Rebind<int32_t, D>(), 2);
    return BitCast(d, ShiftLeft<30>(AndNot(q, kTwo)));
  }
  template <class D, class VI32>
  inline __attribute__((always_inline)) Vec<Rebind<float, D>> SinSignFromQuadrant(D d, VI32 q) {
    const VI32 kOne = Set(Rebind<int32_t, D>(), 1);
    return BitCast(d, ShiftLeft<31>(And(q, kOne)));
  }
};
template <>
struct CosSinImpl<double> {
  template <class D, class V>
  inline __attribute__((always_inline)) Vec<Rebind<int32_t, D>> ToInt32(D , V x) {
    return DemoteTo(Rebind<int32_t, D>(), x);
  }
  template <class D, class V>
  inline __attribute__((always_inline)) V Poly(D d, V x) {
    const auto k0 = Set(d, -0.166666666666666657414808);
    const auto k1 = Set(d, +0.00833333333333332974823815);
    const auto k2 = Set(d, -0.000198412698412696162806809);
    const auto k3 = Set(d, +2.75573192239198747630416e-6);
    const auto k4 = Set(d, -2.50521083763502045810755e-8);
    const auto k5 = Set(d, +1.60590430605664501629054e-10);
    const auto k6 = Set(d, -7.64712219118158833288484e-13);
    const auto k7 = Set(d, +2.81009972710863200091251e-15);
    const auto k8 = Set(d, -7.97255955009037868891952e-18);
    const auto y = Mul(x, x);
    return MulAdd(Estrin(y, k0, k1, k2, k3, k4, k5, k6, k7, k8), Mul(y, x), x);
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V CosReduce(D d, V x, VI32 q) {
    const V kHalfPiPart0d = Set(d, -0.5 * 3.1415926218032836914);
    const V kHalfPiPart1d = Set(d, -0.5 * 3.1786509424591713469e-8);
    const V kHalfPiPart2d = Set(d, -0.5 * 1.2246467864107188502e-16);
    const V kHalfPiPart3d = Set(d, -0.5 * 1.2736634327021899816e-24);
    const V qf = PromoteTo(d, q);
    x = MulAdd(qf, kHalfPiPart0d, x);
    x = MulAdd(qf, kHalfPiPart1d, x);
    x = MulAdd(qf, kHalfPiPart2d, x);
    x = MulAdd(qf, kHalfPiPart3d, x);
    return x;
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V SinReduce(D d, V x, VI32 q) {
    const V kPiPart0d = Set(d, -3.1415926218032836914);
    const V kPiPart1d = Set(d, -3.1786509424591713469e-8);
    const V kPiPart2d = Set(d, -1.2246467864107188502e-16);
    const V kPiPart3d = Set(d, -1.2736634327021899816e-24);
    const V qf = PromoteTo(d, q);
    x = MulAdd(qf, kPiPart0d, x);
    x = MulAdd(qf, kPiPart1d, x);
    x = MulAdd(qf, kPiPart2d, x);
    x = MulAdd(qf, kPiPart3d, x);
    return x;
  }
  template <class D, class VI32>
  inline __attribute__((always_inline)) Vec<Rebind<double, D>> CosSignFromQuadrant(D d, VI32 q) {
    const VI32 kTwo = Set(Rebind<int32_t, D>(), 2);
    return BitCast(
        d, ShiftLeft<62>(PromoteTo(Rebind<int64_t, D>(), AndNot(q, kTwo))));
  }
  template <class D, class VI32>
  inline __attribute__((always_inline)) Vec<Rebind<double, D>> SinSignFromQuadrant(D d, VI32 q) {
    const VI32 kOne = Set(Rebind<int32_t, D>(), 1);
    return BitCast(
        d, ShiftLeft<63>(PromoteTo(Rebind<int64_t, D>(), And(q, kOne))));
  }
};
template <>
struct ExpImpl<float> {
  template <class D, class V>
  inline __attribute__((always_inline)) Vec<Rebind<int32_t, D>> ToInt32(D , V x) {
    return ConvertTo(Rebind<int32_t, D>(), x);
  }
  template <class D, class V>
  inline __attribute__((always_inline)) V ExpPoly(D d, V x) {
    const auto k0 = Set(d, +0.5f);
    const auto k1 = Set(d, +0.166666671633720397949219f);
    const auto k2 = Set(d, +0.0416664853692054748535156f);
    const auto k3 = Set(d, +0.00833336077630519866943359f);
    const auto k4 = Set(d, +0.00139304355252534151077271f);
    const auto k5 = Set(d, +0.000198527617612853646278381f);
    return MulAdd(Estrin(x, k0, k1, k2, k3, k4, k5), Mul(x, x), x);
  }
  template <class D, class VI32>
  inline __attribute__((always_inline)) Vec<D> Pow2I(D d, VI32 x) {
    const Rebind<int32_t, D> di32;
    const VI32 kOffset = Set(di32, 0x7F);
    return BitCast(d, ShiftLeft<23>(Add(x, kOffset)));
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V LoadExpShortRange(D d, V x, VI32 e) {
    const VI32 y = ShiftRight<1>(e);
    return Mul(Mul(x, Pow2I(d, y)), Pow2I(d, Sub(e, y)));
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V ExpReduce(D d, V x, VI32 q) {
    const V kLn2Part0f = Set(d, -0.693145751953125f);
    const V kLn2Part1f = Set(d, -1.428606765330187045e-6f);
    const V qf = ConvertTo(d, q);
    x = MulAdd(qf, kLn2Part0f, x);
    x = MulAdd(qf, kLn2Part1f, x);
    return x;
  }
};
template <>
struct LogImpl<float> {
  template <class D, class V>
  inline __attribute__((always_inline)) Vec<Rebind<int32_t, D>> Log2p1NoSubnormal(D , V x) {
    const Rebind<int32_t, D> di32;
    const Rebind<uint32_t, D> du32;
    const auto kBias = Set(di32, 0x7F);
    return Sub(BitCast(di32, ShiftRight<23>(BitCast(du32, x))), kBias);
  }
  template <class D, class V>
  inline __attribute__((always_inline)) V LogPoly(D d, V x) {
    const V k0 = Set(d, 0.66666662693f);
    const V k1 = Set(d, 0.40000972152f);
    const V k2 = Set(d, 0.28498786688f);
    const V k3 = Set(d, 0.24279078841f);
    const V x2 = Mul(x, x);
    const V x4 = Mul(x2, x2);
    return MulAdd(MulAdd(k2, x4, k0), x2, Mul(MulAdd(k3, x4, k1), x4));
  }
};
template <>
struct ExpImpl<double> {
  template <class D, class V>
  inline __attribute__((always_inline)) Vec<Rebind<int32_t, D>> ToInt32(D , V x) {
    return DemoteTo(Rebind<int32_t, D>(), x);
  }
  template <class D, class V>
  inline __attribute__((always_inline)) V ExpPoly(D d, V x) {
    const auto k0 = Set(d, +0.5);
    const auto k1 = Set(d, +0.166666666666666851703837);
    const auto k2 = Set(d, +0.0416666666666665047591422);
    const auto k3 = Set(d, +0.00833333333331652721664984);
    const auto k4 = Set(d, +0.00138888888889774492207962);
    const auto k5 = Set(d, +0.000198412698960509205564975);
    const auto k6 = Set(d, +2.4801587159235472998791e-5);
    const auto k7 = Set(d, +2.75572362911928827629423e-6);
    const auto k8 = Set(d, +2.75573911234900471893338e-7);
    const auto k9 = Set(d, +2.51112930892876518610661e-8);
    const auto k10 = Set(d, +2.08860621107283687536341e-9);
    return MulAdd(Estrin(x, k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10),
                  Mul(x, x), x);
  }
  template <class D, class VI32>
  inline __attribute__((always_inline)) Vec<D> Pow2I(D d, VI32 x) {
    const Rebind<int32_t, D> di32;
    const Rebind<int64_t, D> di64;
    const VI32 kOffset = Set(di32, 0x3FF);
    return BitCast(d, ShiftLeft<52>(PromoteTo(di64, Add(x, kOffset))));
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V LoadExpShortRange(D d, V x, VI32 e) {
    const VI32 y = ShiftRight<1>(e);
    return Mul(Mul(x, Pow2I(d, y)), Pow2I(d, Sub(e, y)));
  }
  template <class D, class V, class VI32>
  inline __attribute__((always_inline)) V ExpReduce(D d, V x, VI32 q) {
    const V kLn2Part0d = Set(d, -0.6931471805596629565116018);
    const V kLn2Part1d = Set(d, -0.28235290563031577122588448175e-12);
    const V qf = PromoteTo(d, q);
    x = MulAdd(qf, kLn2Part0d, x);
    x = MulAdd(qf, kLn2Part1d, x);
    return x;
  }
};
template <>
struct LogImpl<double> {
  template <class D, class V>
  inline __attribute__((always_inline)) Vec<Rebind<int64_t, D>> Log2p1NoSubnormal(D , V x) {
    const Rebind<int64_t, D> di64;
    const Rebind<uint64_t, D> du64;
    return Sub(BitCast(di64, ShiftRight<52>(BitCast(du64, x))),
               Set(di64, 0x3FF));
  }
  template <class D, class V>
  inline __attribute__((always_inline)) V LogPoly(D d, V x) {
    const V k0 = Set(d, 0.6666666666666735130);
    const V k1 = Set(d, 0.3999999999940941908);
    const V k2 = Set(d, 0.2857142874366239149);
    const V k3 = Set(d, 0.2222219843214978396);
    const V k4 = Set(d, 0.1818357216161805012);
    const V k5 = Set(d, 0.1531383769920937332);
    const V k6 = Set(d, 0.1479819860511658591);
    const V x2 = Mul(x, x);
    const V x4 = Mul(x2, x2);
    return MulAdd(MulAdd(MulAdd(MulAdd(k6, x4, k4), x4, k2), x4, k0), x2,
                  (Mul(MulAdd(MulAdd(k5, x4, k3), x4, k1), x4)));
  }
};
template <class D, class V, bool kAllowSubnormals = true>
inline __attribute__((always_inline)) V Log(const D d, V x) {
  using T = TFromD<D>;
  impl::LogImpl<T> impl;
  constexpr bool kIsF32 = (sizeof(T) == 4);
  const V kLn2Hi = Set(d, kIsF32 ? static_cast<T>(0.69313812256f)
                                 : static_cast<T>(0.693147180369123816490));
  const V kLn2Lo = Set(d, kIsF32 ? static_cast<T>(9.0580006145e-6f)
                                 : static_cast<T>(1.90821492927058770002e-10));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kMinNormal = Set(d, kIsF32 ? static_cast<T>(1.175494351e-38f)
                                     : static_cast<T>(2.2250738585072014e-308));
  const V kScale = Set(d, kIsF32 ? static_cast<T>(3.355443200e+7f)
                                 : static_cast<T>(1.8014398509481984e+16));
  using TI = MakeSigned<T>;
  const Rebind<TI, D> di;
  using VI = decltype(Zero(di));
  const VI kLowerBits = Set(di, kIsF32 ? static_cast<TI>(0x00000000L)
                                       : static_cast<TI>(0xFFFFFFFFLL));
  const VI kMagic = Set(di, kIsF32 ? static_cast<TI>(0x3F3504F3L)
                                   : static_cast<TI>(0x3FE6A09E00000000LL));
  const VI kExpMask = Set(di, kIsF32 ? static_cast<TI>(0x3F800000L)
                                     : static_cast<TI>(0x3FF0000000000000LL));
  const VI kExpScale =
      Set(di, kIsF32 ? static_cast<TI>(-25) : static_cast<TI>(-54));
  const VI kManMask = Set(di, kIsF32 ? static_cast<TI>(0x7FFFFFL)
                                     : static_cast<TI>(0xFFFFF00000000LL));
  VI exp_bits;
  V exp;
  if (kAllowSubnormals == true) {
    const auto is_denormal = Lt(x, kMinNormal);
    x = IfThenElse(is_denormal, Mul(x, kScale), x);
    exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
    const VI exp_scale =
        BitCast(di, IfThenElseZero(is_denormal, BitCast(d, kExpScale)));
    exp = ConvertTo(
        d, Add(exp_scale, impl.Log2p1NoSubnormal(d, BitCast(d, exp_bits))));
  } else {
    exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
    exp = ConvertTo(d, impl.Log2p1NoSubnormal(d, BitCast(d, exp_bits)));
  }
  const V y = Or(And(x, BitCast(d, kLowerBits)),
                 BitCast(d, Add(And(exp_bits, kManMask), kMagic)));
  const V ym1 = Sub(y, kOne);
  const V z = Div(ym1, Add(y, kOne));
  return MulSub(
      exp, kLn2Hi,
      Sub(MulSub(z, Sub(ym1, impl.LogPoly(d, z)), Mul(exp, kLn2Lo)), ym1));
}
}
template <class D, class V>
inline __attribute__((always_inline)) V Acos(const D d, V x) {
  using T = TFromD<D>;
  const V kZero = Zero(d);
  const V kHalf = Set(d, static_cast<T>(+0.5));
  const V kPi = Set(d, static_cast<T>(+3.14159265358979323846264));
  const V kPiOverTwo = Set(d, static_cast<T>(+1.57079632679489661923132169));
  const V sign_x = And(SignBit(d), x);
  const V abs_x = Xor(x, sign_x);
  const auto mask = Lt(abs_x, kHalf);
  const V yy =
      IfThenElse(mask, Mul(abs_x, abs_x), NegMulAdd(abs_x, kHalf, kHalf));
  const V y = IfThenElse(mask, abs_x, Sqrt(yy));
  impl::AsinImpl<T> impl;
  const V t = Mul(impl.AsinPoly(d, yy, y), Mul(y, yy));
  const V t_plus_y = Add(t, y);
  const V z =
      IfThenElse(mask, Sub(kPiOverTwo, Add(Xor(y, sign_x), Xor(t, sign_x))),
                 Add(t_plus_y, t_plus_y));
  return IfThenElse(Or(mask, Ge(x, kZero)), z, Sub(kPi, z));
}
template <class D, class V>
inline __attribute__((always_inline)) V Acosh(const D d, V x) {
  using T = TFromD<D>;
  const V kLarge = Set(d, static_cast<T>(268435456.0));
  const V kLog2 = Set(d, static_cast<T>(0.693147180559945286227));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kTwo = Set(d, static_cast<T>(+2.0));
  const auto is_x_large = Gt(x, kLarge);
  const auto is_x_gt_2 = Gt(x, kTwo);
  const V x_minus_1 = Sub(x, kOne);
  const V y0 = MulSub(kTwo, x, Div(kOne, Add(Sqrt(MulSub(x, x, kOne)), x)));
  const V y1 =
      Add(Sqrt(MulAdd(x_minus_1, kTwo, Mul(x_minus_1, x_minus_1))), x_minus_1);
  const V y2 =
      IfThenElse(is_x_gt_2, IfThenElse(is_x_large, x, y0), Add(y1, kOne));
  const V z = impl::Log<D, V, false>(d, y2);
  const auto is_pole = Eq(y2, kOne);
  const auto divisor = Sub(IfThenZeroElse(is_pole, y2), kOne);
  return Add(IfThenElse(is_x_gt_2, z,
                        IfThenElse(is_pole, y1, Div(Mul(z, y1), divisor))),
             IfThenElseZero(is_x_large, kLog2));
}
template <class D, class V>
inline __attribute__((always_inline)) V Asin(const D d, V x) {
  using T = TFromD<D>;
  const V kHalf = Set(d, static_cast<T>(+0.5));
  const V kTwo = Set(d, static_cast<T>(+2.0));
  const V kPiOverTwo = Set(d, static_cast<T>(+1.57079632679489661923132169));
  const V sign_x = And(SignBit(d), x);
  const V abs_x = Xor(x, sign_x);
  const auto mask = Lt(abs_x, kHalf);
  const V yy =
      IfThenElse(mask, Mul(abs_x, abs_x), NegMulAdd(abs_x, kHalf, kHalf));
  const V y = IfThenElse(mask, abs_x, Sqrt(yy));
  impl::AsinImpl<T> impl;
  const V z0 = MulAdd(impl.AsinPoly(d, yy, y), Mul(yy, y), y);
  const V z1 = NegMulAdd(z0, kTwo, kPiOverTwo);
  return Or(IfThenElse(mask, z0, z1), sign_x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Asinh(const D d, V x) {
  using T = TFromD<D>;
  const V kSmall = Set(d, static_cast<T>(1.0 / 268435456.0));
  const V kLarge = Set(d, static_cast<T>(268435456.0));
  const V kLog2 = Set(d, static_cast<T>(0.693147180559945286227));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kTwo = Set(d, static_cast<T>(+2.0));
  const V sign_x = And(SignBit(d), x);
  const V abs_x = Xor(x, sign_x);
  const auto is_x_large = Gt(abs_x, kLarge);
  const auto is_x_lt_2 = Lt(abs_x, kTwo);
  const V x2 = Mul(x, x);
  const V sqrt_x2_plus_1 = Sqrt(Add(x2, kOne));
  const V y0 = MulAdd(abs_x, kTwo, Div(kOne, Add(sqrt_x2_plus_1, abs_x)));
  const V y1 = Add(Div(x2, Add(sqrt_x2_plus_1, kOne)), abs_x);
  const V y2 =
      IfThenElse(is_x_lt_2, Add(y1, kOne), IfThenElse(is_x_large, abs_x, y0));
  const V z = impl::Log<D, V, false>(d, y2);
  const auto is_pole = Eq(y2, kOne);
  const auto divisor = Sub(IfThenZeroElse(is_pole, y2), kOne);
  const auto large = IfThenElse(is_pole, y1, Div(Mul(z, y1), divisor));
  const V y = IfThenElse(Lt(abs_x, kSmall), x, large);
  return Or(Add(IfThenElse(is_x_lt_2, y, z), IfThenElseZero(is_x_large, kLog2)),
            sign_x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Atan(const D d, V x) {
  using T = TFromD<D>;
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kPiOverTwo = Set(d, static_cast<T>(+1.57079632679489661923132169));
  const V sign = And(SignBit(d), x);
  const V abs_x = Xor(x, sign);
  const auto mask = Gt(abs_x, kOne);
  impl::AtanImpl<T> impl;
  const auto divisor = IfThenElse(mask, abs_x, kOne);
  const V y = impl.AtanPoly(d, IfThenElse(mask, Div(kOne, divisor), abs_x));
  return Or(IfThenElse(mask, Sub(kPiOverTwo, y), y), sign);
}
template <class D, class V>
inline __attribute__((always_inline)) V Atanh(const D d, V x) {
  using T = TFromD<D>;
  const V kHalf = Set(d, static_cast<T>(+0.5));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V sign = And(SignBit(d), x);
  const V abs_x = Xor(x, sign);
  return Mul(Log1p(d, Div(Add(abs_x, abs_x), Sub(kOne, abs_x))),
             Xor(kHalf, sign));
}
template <class D, class V>
inline __attribute__((always_inline)) V Cos(const D d, V x) {
  using T = TFromD<D>;
  impl::CosSinImpl<T> impl;
  const V kOneOverPi = Set(d, static_cast<T>(0.31830988618379067153));
  const Rebind<int32_t, D> di32;
  using VI32 = decltype(Zero(di32));
  const VI32 kOne = Set(di32, 1);
  const V y = Abs(x);
  const VI32 q = Add(ShiftLeft<1>(impl.ToInt32(d, Mul(y, kOneOverPi))), kOne);
  return impl.Poly(
      d, Xor(impl.CosReduce(d, y, q), impl.CosSignFromQuadrant(d, q)));
}
template <class D, class V>
inline __attribute__((always_inline)) V Exp(const D d, V x) {
  using T = TFromD<D>;
  const V kHalf = Set(d, static_cast<T>(+0.5));
  const V kLowerBound =
      Set(d, static_cast<T>((sizeof(T) == 4 ? -104.0 : -1000.0)));
  const V kNegZero = Set(d, static_cast<T>(-0.0));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kOneOverLog2 = Set(d, static_cast<T>(+1.442695040888963407359924681));
  impl::ExpImpl<T> impl;
  const auto q =
      impl.ToInt32(d, MulAdd(x, kOneOverLog2, Or(kHalf, And(x, kNegZero))));
  const V y = impl.LoadExpShortRange(
      d, Add(impl.ExpPoly(d, impl.ExpReduce(d, x, q)), kOne), q);
  return IfThenElseZero(Ge(x, kLowerBound), y);
}
template <class D, class V>
inline __attribute__((always_inline)) V Expm1(const D d, V x) {
  using T = TFromD<D>;
  const V kHalf = Set(d, static_cast<T>(+0.5));
  const V kLowerBound =
      Set(d, static_cast<T>((sizeof(T) == 4 ? -104.0 : -1000.0)));
  const V kLn2Over2 = Set(d, static_cast<T>(+0.346573590279972654708616));
  const V kNegOne = Set(d, static_cast<T>(-1.0));
  const V kNegZero = Set(d, static_cast<T>(-0.0));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kOneOverLog2 = Set(d, static_cast<T>(+1.442695040888963407359924681));
  impl::ExpImpl<T> impl;
  const auto q =
      impl.ToInt32(d, MulAdd(x, kOneOverLog2, Or(kHalf, And(x, kNegZero))));
  const V y = impl.ExpPoly(d, impl.ExpReduce(d, x, q));
  const V z = IfThenElse(Lt(Abs(x), kLn2Over2), y,
                         Sub(impl.LoadExpShortRange(d, Add(y, kOne), q), kOne));
  return IfThenElse(Lt(x, kLowerBound), kNegOne, z);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log(const D d, V x) {
  return impl::Log<D, V, true>(d, x);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log10(const D d, V x) {
  using T = TFromD<D>;
  return Mul(Log(d, x), Set(d, static_cast<T>(0.4342944819032518276511)));
}
template <class D, class V>
inline __attribute__((always_inline)) V Log1p(const D d, V x) {
  using T = TFromD<D>;
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V y = Add(x, kOne);
  const auto is_pole = Eq(y, kOne);
  const auto divisor = Sub(IfThenZeroElse(is_pole, y), kOne);
  const auto non_pole =
      Mul(impl::Log<D, V, false>(d, y), Div(x, divisor));
  return IfThenElse(is_pole, x, non_pole);
}
template <class D, class V>
inline __attribute__((always_inline)) V Log2(const D d, V x) {
  using T = TFromD<D>;
  return Mul(Log(d, x), Set(d, static_cast<T>(1.44269504088896340735992)));
}
template <class D, class V>
inline __attribute__((always_inline)) V Sin(const D d, V x) {
  using T = TFromD<D>;
  impl::CosSinImpl<T> impl;
  const V kOneOverPi = Set(d, static_cast<T>(0.31830988618379067153));
  const V kHalf = Set(d, static_cast<T>(0.5));
  const Rebind<int32_t, D> di32;
  using VI32 = decltype(Zero(di32));
  const V abs_x = Abs(x);
  const V sign_x = Xor(abs_x, x);
  const VI32 q = impl.ToInt32(d, MulAdd(abs_x, kOneOverPi, kHalf));
  return impl.Poly(d, Xor(impl.SinReduce(d, abs_x, q),
                          Xor(impl.SinSignFromQuadrant(d, q), sign_x)));
}
template <class D, class V>
inline __attribute__((always_inline)) V Sinh(const D d, V x) {
  using T = TFromD<D>;
  const V kHalf = Set(d, static_cast<T>(+0.5));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kTwo = Set(d, static_cast<T>(+2.0));
  const V sign = And(SignBit(d), x);
  const V abs_x = Xor(x, sign);
  const V y = Expm1(d, abs_x);
  const V z = Mul(Div(Add(y, kTwo), Add(y, kOne)), Mul(y, kHalf));
  return Xor(z, sign);
}
template <class D, class V>
inline __attribute__((always_inline)) V Tanh(const D d, V x) {
  using T = TFromD<D>;
  const V kLimit = Set(d, static_cast<T>(18.714973875));
  const V kOne = Set(d, static_cast<T>(+1.0));
  const V kTwo = Set(d, static_cast<T>(+2.0));
  const V sign = And(SignBit(d), x);
  const V abs_x = Xor(x, sign);
  const V y = Expm1(d, Mul(abs_x, kTwo));
  const V z = IfThenElse(Gt(abs_x, kLimit), kOne, Div(y, Add(y, kTwo)));
  return Xor(z, sign);
}
}
}
static_assert(true, "For requiring trailing semicolon");
       
namespace std
{
  using ::int8_t;
  using ::int16_t;
  using ::int32_t;
  using ::int64_t;
  using ::int_fast8_t;
  using ::int_fast16_t;
  using ::int_fast32_t;
  using ::int_fast64_t;
  using ::int_least8_t;
  using ::int_least16_t;
  using ::int_least32_t;
  using ::int_least64_t;
  using ::intmax_t;
  using ::intptr_t;
  using ::uint8_t;
  using ::uint16_t;
  using ::uint32_t;
  using ::uint64_t;
  using ::uint_fast8_t;
  using ::uint_fast16_t;
  using ::uint_fast32_t;
  using ::uint_fast64_t;
  using ::uint_least8_t;
  using ::uint_least16_t;
  using ::uint_least32_t;
  using ::uint_least64_t;
  using ::uintmax_t;
  using ::uintptr_t;
}
extern "C" {
typedef struct
  {
    __extension__ long long int quot;
    __extension__ long long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) noexcept (true) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      noexcept (true) __attribute__ ((__const__));
extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) noexcept (true);
extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) noexcept (true);
extern intmax_t wcstoimax (const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     noexcept (true);
extern uintmax_t wcstoumax (const wchar_t *__restrict __nptr,
       wchar_t ** __restrict __endptr, int __base)
     noexcept (true);
}
       
extern "C" {
typedef __builtin_va_list __gnuc_va_list;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);
typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);
typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);
typedef int cookie_close_function_t (void *__cookie);
typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;
typedef __fpos64_t fpos64_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) noexcept (true);
extern int rename (const char *__old, const char *__new) noexcept (true);
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) noexcept (true);
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
        const char *__new, unsigned int __flags) noexcept (true);
extern int fclose (FILE *__stream);
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *tmpfile64 (void)
   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern char *tmpnam (char[20]) noexcept (true) ;
extern char *tmpnam_r (char __s[20]) noexcept (true) ;
extern char *tempnam (const char *__dir, const char *__pfx)
   noexcept (true) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern int fcloseall (void);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fopen64 (const char *__restrict __filename,
        const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen64 (const char *__restrict __filename,
   const char *__restrict __modes,
   FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) noexcept (true)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) noexcept (true)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  noexcept (true) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) noexcept (true)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) noexcept (true);
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) noexcept (true);
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) noexcept (true);
extern void setlinebuf (FILE *__stream) noexcept (true);
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) noexcept (true);
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) noexcept (true);
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     noexcept (true) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     noexcept (true) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     noexcept (true) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     noexcept (true) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     noexcept (true) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) noexcept (true);
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) noexcept (true) __asm__ ("" "__isoc99_sscanf");
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     noexcept (true) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) noexcept (true) __asm__ ("" "__isoc99_vsscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *gets (char *__s) __attribute__ ((__deprecated__));
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern int fputs_unlocked (const char *__restrict __s,
      FILE *__restrict __stream);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);
extern void clearerr (FILE *__stream) noexcept (true);
extern int feof (FILE *__stream) noexcept (true) ;
extern int ferror (FILE *__stream) noexcept (true) ;
extern void clearerr_unlocked (FILE *__stream) noexcept (true);
extern int feof_unlocked (FILE *__stream) noexcept (true) ;
extern int ferror_unlocked (FILE *__stream) noexcept (true) ;
extern void perror (const char *__s);
extern int fileno (FILE *__stream) noexcept (true) ;
extern int fileno_unlocked (FILE *__stream) noexcept (true) ;
extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;
extern char *ctermid (char *__s) noexcept (true)
  __attribute__ ((__access__ (__write_only__, 1)));
extern char *cuserid (char *__s)
  __attribute__ ((__access__ (__write_only__, 1)));
struct obstack;
extern int obstack_printf (struct obstack *__restrict __obstack,
      const char *__restrict __format, ...)
     noexcept (true) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       const char *__restrict __format,
       __gnuc_va_list __args)
     noexcept (true) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void flockfile (FILE *__stream) noexcept (true);
extern int ftrylockfile (FILE *__stream) noexcept (true) ;
extern void funlockfile (FILE *__stream) noexcept (true);
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
extern __inline __attribute__ ((__gnu_inline__)) int
vprintf (const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf (stdout, __fmt, __arg);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getchar (void)
{
  return getc (stdin);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar (int __c)
{
  return putc (__c, stdout);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) __ssize_t
getline (char **__lineptr, size_t *__n, FILE *__stream)
{
  return __getdelim (__lineptr, __n, '\n', __stream);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__leaf__)) feof_unlocked (FILE *__stream) noexcept (true)
{
  return (((__stream)->_flags & 0x0010) != 0);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__leaf__)) ferror_unlocked (FILE *__stream) noexcept (true)
{
  return (((__stream)->_flags & 0x0020) != 0);
}
}
namespace std
{
  using ::FILE;
  using ::fpos_t;
  using ::clearerr;
  using ::fclose;
  using ::feof;
  using ::ferror;
  using ::fflush;
  using ::fgetc;
  using ::fgetpos;
  using ::fgets;
  using ::fopen;
  using ::fprintf;
  using ::fputc;
  using ::fputs;
  using ::fread;
  using ::freopen;
  using ::fscanf;
  using ::fseek;
  using ::fsetpos;
  using ::ftell;
  using ::fwrite;
  using ::getc;
  using ::getchar;
  using ::gets;
  using ::perror;
  using ::printf;
  using ::putc;
  using ::putchar;
  using ::puts;
  using ::remove;
  using ::rename;
  using ::rewind;
  using ::scanf;
  using ::setbuf;
  using ::setvbuf;
  using ::sprintf;
  using ::sscanf;
  using ::tmpfile;
  using ::tmpnam;
  using ::ungetc;
  using ::vfprintf;
  using ::vprintf;
  using ::vsprintf;
}
namespace __gnu_cxx
{
  using ::snprintf;
  using ::vfscanf;
  using ::vscanf;
  using ::vsnprintf;
  using ::vsscanf;
}
namespace std
{
  using ::__gnu_cxx::snprintf;
  using ::__gnu_cxx::vfscanf;
  using ::__gnu_cxx::vscanf;
  using ::__gnu_cxx::vsnprintf;
  using ::__gnu_cxx::vsscanf;
}
namespace hwy {
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class D> void TestMath(D d, uint64_t start, uint64_t stop) {
  uint64_t kSamplesPerRange=4000 ;
  uint64_t step(stop / kSamplesPerRange);
  for (uint64_t value_bits = start; value_bits <= stop; value_bits += step) {
    double value = BitCast<double>(value_bits),
           actual = GetLane(CallLog1p(d, Set(d, value))),
           expected = log1p(value);
    fprintf(stderr, "%" "ll" "u" " - Log1p(%.17g) expected %.17g actual %.17g %a\n", value_bits, value,
            expected, actual, actual);
  }
}
}
int main(int , char *[]) {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  uint64_t start = 4318952042648305665;
  uint64_t stop = 4368493837572636672;
  hwy::TestMath(b2, start, stop);
}

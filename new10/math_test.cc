// Copyright 2020 Google LLC
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Main header required before using vector types.

// IWYU pragma: begin_exports
// Copyright 2020 Google LLC
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef HIGHWAY_HWY_BASE_H_
#define HIGHWAY_HWY_BASE_H_

// For SIMD module implementations and their callers, target-independent.

// IWYU pragma: begin_exports
#include <stddef.h>
#include <stdint.h>

// Wrapping this into a HWY_HAS_INCLUDE causes clang-format to fail.
#if __cplusplus >= 202100L && defined(__has_include)
#if __has_include(<stdfloat>)
#include <stdfloat>  // std::float16_t
#endif
#endif

#include "hwy/detect_compiler_arch.h"
#include "hwy/highway_export.h"

// "IWYU pragma: keep" does not work for these includes, so hide from the IDE.
#if !HWY_IDE

#if !defined(HWY_NO_LIBCXX)
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS  // before inttypes.h
#endif
#include <inttypes.h>
#endif

#if (HWY_ARCH_X86 && !defined(HWY_NO_LIBCXX)) || HWY_COMPILER_MSVC
#include <atomic>
#endif

#endif  // !HWY_IDE

// IWYU pragma: end_exports

#if HWY_COMPILER_MSVC
#include <string.h>  // memcpy
#endif

//------------------------------------------------------------------------------
// Compiler-specific definitions

#define HWY_STR_IMPL(macro) #macro
#define HWY_STR(macro) HWY_STR_IMPL(macro)

#if HWY_COMPILER_MSVC

#include <intrin.h>

#define HWY_RESTRICT __restrict
#define HWY_INLINE __forceinline
#define HWY_NOINLINE __declspec(noinline)
#define HWY_FLATTEN
#define HWY_NORETURN __declspec(noreturn)
#define HWY_LIKELY(expr) (expr)
#define HWY_UNLIKELY(expr) (expr)
#define HWY_PRAGMA(tokens) __pragma(tokens)
#define HWY_DIAGNOSTICS(tokens) HWY_PRAGMA(warning(tokens))
#define HWY_DIAGNOSTICS_OFF(msc, gcc) HWY_DIAGNOSTICS(msc)
#define HWY_MAYBE_UNUSED
#define HWY_HAS_ASSUME_ALIGNED 0
#if (_MSC_VER >= 1700)
#define HWY_MUST_USE_RESULT _Check_return_
#else
#define HWY_MUST_USE_RESULT
#endif

#else

#define HWY_RESTRICT __restrict__
// force inlining without optimization enabled creates very inefficient code
// that can cause compiler timeout
#ifdef __OPTIMIZE__
#define HWY_INLINE inline __attribute__((always_inline))
#else
#define HWY_INLINE inline
#endif
#define HWY_NOINLINE __attribute__((noinline))
#define HWY_FLATTEN __attribute__((flatten))
#define HWY_NORETURN __attribute__((noreturn))
#define HWY_LIKELY(expr) __builtin_expect(!!(expr), 1)
#define HWY_UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#define HWY_PRAGMA(tokens) _Pragma(#tokens)
#define HWY_DIAGNOSTICS(tokens) HWY_PRAGMA(GCC diagnostic tokens)
#define HWY_DIAGNOSTICS_OFF(msc, gcc) HWY_DIAGNOSTICS(gcc)
// Encountered "attribute list cannot appear here" when using the C++17
// [[maybe_unused]], so only use the old style attribute for now.
#define HWY_MAYBE_UNUSED __attribute__((unused))
#define HWY_MUST_USE_RESULT __attribute__((warn_unused_result))

#endif  // !HWY_COMPILER_MSVC

//------------------------------------------------------------------------------
// Builtin/attributes (no more #include after this point due to namespace!)

namespace hwy {

// Enables error-checking of format strings.
#if HWY_HAS_ATTRIBUTE(__format__)
#define HWY_FORMAT(idx_fmt, idx_arg) \
  __attribute__((__format__(__printf__, idx_fmt, idx_arg)))
#else
#define HWY_FORMAT(idx_fmt, idx_arg)
#endif

// Returns a void* pointer which the compiler then assumes is N-byte aligned.
// Example: float* HWY_RESTRICT aligned = (float*)HWY_ASSUME_ALIGNED(in, 32);
//
// The assignment semantics are required by GCC/Clang. ICC provides an in-place
// __assume_aligned, whereas MSVC's __assume appears unsuitable.
#if HWY_HAS_BUILTIN(__builtin_assume_aligned)
#define HWY_ASSUME_ALIGNED(ptr, align) __builtin_assume_aligned((ptr), (align))
#else
#define HWY_ASSUME_ALIGNED(ptr, align) (ptr) /* not supported */
#endif

// Clang and GCC require attributes on each function into which SIMD intrinsics
// are inlined. Support both per-function annotation (HWY_ATTR) for lambdas and
// automatic annotation via pragmas.
#if HWY_COMPILER_ICC
// As of ICC 2021.{1-9} the pragma is neither implemented nor required.
#define HWY_PUSH_ATTRIBUTES(targets_str)
#define HWY_POP_ATTRIBUTES
#elif HWY_COMPILER_CLANG
#define HWY_PUSH_ATTRIBUTES(targets_str)                                \
  HWY_PRAGMA(clang attribute push(__attribute__((target(targets_str))), \
                                  apply_to = function))
#define HWY_POP_ATTRIBUTES HWY_PRAGMA(clang attribute pop)
#elif HWY_COMPILER_GCC_ACTUAL
#define HWY_PUSH_ATTRIBUTES(targets_str) \
  HWY_PRAGMA(GCC push_options) HWY_PRAGMA(GCC target targets_str)
#define HWY_POP_ATTRIBUTES HWY_PRAGMA(GCC pop_options)
#else
#define HWY_PUSH_ATTRIBUTES(targets_str)
#define HWY_POP_ATTRIBUTES
#endif

//------------------------------------------------------------------------------
// Macros

#define HWY_API static HWY_INLINE HWY_FLATTEN HWY_MAYBE_UNUSED

#define HWY_CONCAT_IMPL(a, b) a##b
#define HWY_CONCAT(a, b) HWY_CONCAT_IMPL(a, b)

#define HWY_MIN(a, b) ((a) < (b) ? (a) : (b))
#define HWY_MAX(a, b) ((a) > (b) ? (a) : (b))

#if HWY_COMPILER_GCC_ACTUAL
// nielskm: GCC does not support '#pragma GCC unroll' without the factor.
#define HWY_UNROLL(factor) HWY_PRAGMA(GCC unroll factor)
#define HWY_DEFAULT_UNROLL HWY_UNROLL(4)
#elif HWY_COMPILER_CLANG || HWY_COMPILER_ICC || HWY_COMPILER_ICX
#define HWY_UNROLL(factor) HWY_PRAGMA(unroll factor)
#define HWY_DEFAULT_UNROLL HWY_UNROLL()
#else
#define HWY_UNROLL(factor)
#define HWY_DEFAULT_UNROLL
#endif

// Tell a compiler that the expression always evaluates to true.
// The expression should be free from any side effects.
// Some older compilers may have trouble with complex expressions, therefore
// it is advisable to split multiple conditions into separate assume statements,
// and manually check the generated code.
// OK but could fail:
//   HWY_ASSUME(x == 2 && y == 3);
// Better:
//   HWY_ASSUME(x == 2);
//   HWY_ASSUME(y == 3);
#if HWY_HAS_CPP_ATTRIBUTE(assume)
#define HWY_ASSUME(expr) [[assume(expr)]]
#elif HWY_COMPILER_MSVC || HWY_COMPILER_ICC
#define HWY_ASSUME(expr) __assume(expr)
// __builtin_assume() was added in clang 3.6.
#elif HWY_COMPILER_CLANG && HWY_HAS_BUILTIN(__builtin_assume)
#define HWY_ASSUME(expr) __builtin_assume(expr)
// __builtin_unreachable() was added in GCC 4.5, but __has_builtin() was added
// later, so check for the compiler version directly.
#elif HWY_COMPILER_GCC_ACTUAL >= 405
#define HWY_ASSUME(expr) \
  ((expr) ? static_cast<void>(0) : __builtin_unreachable())
#else
#define HWY_ASSUME(expr) static_cast<void>(0)
#endif

// Compile-time fence to prevent undesirable code reordering. On Clang x86, the
// typical asm volatile("" : : : "memory") has no effect, whereas atomic fence
// does, without generating code.
#if HWY_ARCH_X86 && !defined(HWY_NO_LIBCXX)
#define HWY_FENCE std::atomic_thread_fence(std::memory_order_acq_rel)
#else
// TODO(janwas): investigate alternatives. On Arm, the above generates barriers.
#define HWY_FENCE
#endif

// 4 instances of a given literal value, useful as input to LoadDup128.
#define HWY_REP4(literal) literal, literal, literal, literal

HWY_DLLEXPORT HWY_NORETURN void HWY_FORMAT(3, 4)
    Abort(const char* file, int line, const char* format, ...);

#define HWY_ABORT(format, ...) \
  ::hwy::Abort(__FILE__, __LINE__, format, ##__VA_ARGS__)

// Always enabled.
#define HWY_ASSERT(condition)             \
  do {                                    \
    if (!(condition)) {                   \
      HWY_ABORT("Assert %s", #condition); \
    }                                     \
  } while (0)

#if HWY_HAS_FEATURE(memory_sanitizer) || defined(MEMORY_SANITIZER)
#define HWY_IS_MSAN 1
#else
#define HWY_IS_MSAN 0
#endif

#if HWY_HAS_FEATURE(address_sanitizer) || defined(ADDRESS_SANITIZER)
#define HWY_IS_ASAN 1
#else
#define HWY_IS_ASAN 0
#endif

#if HWY_HAS_FEATURE(thread_sanitizer) || defined(THREAD_SANITIZER)
#define HWY_IS_TSAN 1
#else
#define HWY_IS_TSAN 0
#endif

// MSAN may cause lengthy build times or false positives e.g. in AVX3 DemoteTo.
// You can disable MSAN by adding this attribute to the function that fails.
#if HWY_IS_MSAN
#define HWY_ATTR_NO_MSAN __attribute__((no_sanitize_memory))
#else
#define HWY_ATTR_NO_MSAN
#endif

// For enabling HWY_DASSERT and shortening tests in slower debug builds
#if !defined(HWY_IS_DEBUG_BUILD)
// Clang does not define NDEBUG, but it and GCC define __OPTIMIZE__, and recent
// MSVC defines NDEBUG (if not, could instead check _DEBUG).
#if (!defined(__OPTIMIZE__) && !defined(NDEBUG)) || HWY_IS_ASAN || \
    HWY_IS_MSAN || HWY_IS_TSAN || defined(__clang_analyzer__)
#define HWY_IS_DEBUG_BUILD 1
#else
#define HWY_IS_DEBUG_BUILD 0
#endif
#endif  // HWY_IS_DEBUG_BUILD

#if HWY_IS_DEBUG_BUILD
#define HWY_DASSERT(condition) HWY_ASSERT(condition)
#else
#define HWY_DASSERT(condition) \
  do {                         \
  } while (0)
#endif

//------------------------------------------------------------------------------
// CopyBytes / ZeroBytes

#if HWY_COMPILER_MSVC
#pragma intrinsic(memcpy)
#pragma intrinsic(memset)
#endif

// The source/destination must not overlap/alias.
template <size_t kBytes, typename From, typename To>
HWY_API void CopyBytes(const From* from, To* to) {
#if HWY_COMPILER_MSVC
  memcpy(to, from, kBytes);
#else
  __builtin_memcpy(to, from,
                   kBytes);
#endif
}

HWY_API void CopyBytes(const void* HWY_RESTRICT from, void* HWY_RESTRICT to,
                       size_t num_of_bytes_to_copy) {
#if HWY_COMPILER_MSVC
  memcpy(to, from, num_of_bytes_to_copy);
#else
  __builtin_memcpy(to, from, num_of_bytes_to_copy);
#endif
}

// Same as CopyBytes, but for same-sized objects; avoids a size argument.
template <typename From, typename To>
HWY_API void CopySameSize(const From* HWY_RESTRICT from, To* HWY_RESTRICT to) {
  static_assert(sizeof(From) == sizeof(To), "");
  CopyBytes<sizeof(From)>(from, to);
}

template <size_t kBytes, typename To>
HWY_API void ZeroBytes(To* to) {
#if HWY_COMPILER_MSVC
  memset(to, 0, kBytes);
#else
  __builtin_memset(to, 0, kBytes);
#endif
}

HWY_API void ZeroBytes(void* to, size_t num_bytes) {
#if HWY_COMPILER_MSVC
  memset(to, 0, num_bytes);
#else
  __builtin_memset(to, 0, num_bytes);
#endif
}

//------------------------------------------------------------------------------
// kMaxVectorSize (undocumented, pending removal)

#if HWY_ARCH_X86
static constexpr HWY_MAYBE_UNUSED size_t kMaxVectorSize = 64;  // AVX-512
#elif HWY_ARCH_RVV && defined(__riscv_v_intrinsic) && \
    __riscv_v_intrinsic >= 11000
// Not actually an upper bound on the size.
static constexpr HWY_MAYBE_UNUSED size_t kMaxVectorSize = 4096;
#else
static constexpr HWY_MAYBE_UNUSED size_t kMaxVectorSize = 16;
#endif

//------------------------------------------------------------------------------
// Alignment

// Potentially useful for LoadDup128 and capped vectors. In other cases, arrays
// should be allocated dynamically via aligned_allocator.h because Lanes() may
// exceed the stack size.
#if HWY_ARCH_X86
#define HWY_ALIGN_MAX alignas(64)
#elif HWY_ARCH_RVV && defined(__riscv_v_intrinsic) && \
    __riscv_v_intrinsic >= 11000
#define HWY_ALIGN_MAX alignas(8)  // only elements need be aligned
#else
#define HWY_ALIGN_MAX alignas(16)
#endif

//------------------------------------------------------------------------------
// Lane types

#pragma pack(push, 1)

// float16_t load/store/conversion intrinsics are always supported on Armv8 and
// VFPv4 (except with MSVC). On Armv7 Clang requires __ARM_FP & 2; GCC requires
// -mfp16-format=ieee.
#if (HWY_ARCH_ARM_A64 && !HWY_COMPILER_MSVC) ||                    \
    (HWY_COMPILER_CLANG && defined(__ARM_FP) && (__ARM_FP & 2)) || \
    (HWY_COMPILER_GCC_ACTUAL && defined(__ARM_FP16_FORMAT_IEEE))
#define HWY_NEON_HAVE_FLOAT16C 1
#else
#define HWY_NEON_HAVE_FLOAT16C 0
#endif

// C11 extension ISO/IEC TS 18661-3:2015 but not supported on all targets.
// Required if HWY_HAVE_FLOAT16, i.e. RVV with zvfh or AVX3_SPR (with
// sufficiently new compiler supporting avx512fp16). Do not use on clang-cl,
// which is missing __extendhfsf2.
#if ((HWY_ARCH_RVV && defined(__riscv_zvfh) && HWY_COMPILER_CLANG) || \
     (HWY_ARCH_X86 && defined(__SSE2__) &&                            \
      ((HWY_COMPILER_CLANG >= 1600 && !HWY_COMPILER_CLANGCL) ||       \
       HWY_COMPILER_GCC_ACTUAL >= 1200)))
#define HWY_HAVE_C11_FLOAT16 1
#else
#define HWY_HAVE_C11_FLOAT16 0
#endif

// If 1, both __bf16 and a limited set of *_bf16 SVE intrinsics are available:
// create/get/set/dup, ld/st, sel, rev, trn, uzp, zip.
#if HWY_ARCH_ARM_A64 && defined(__ARM_FEATURE_SVE_BF16)
#define HWY_SVE_HAVE_BFLOAT16 1
#else
#define HWY_SVE_HAVE_BFLOAT16 0
#endif

// Match [u]int##_t naming scheme so rvv-inl.h macros can obtain the type name
// by concatenating base type and bits. We use a wrapper class instead of a
// typedef to the native type to ensure that the same symbols, e.g. for VQSort,
// are generated regardless of F16 support; see #1684.
struct float16_t {
#if HWY_NEON_HAVE_FLOAT16C  // ACLE's __fp16
  using Raw = __fp16;
#elif HWY_HAVE_C11_FLOAT16                                    // C11 _Float16
  using Raw = _Float16;
#elif __cplusplus > 202002L && defined(__STDCPP_FLOAT16_T__)  // C++23
  using Raw = std::float16_t;
#else
#define HWY_EMULATE_FLOAT16
  using Raw = uint16_t;
  Raw bits;
#endif  // float16_t

// When backed by a native type, ensure the wrapper behaves like the native
// type by forwarding all operators. Unfortunately it seems difficult to reuse
// this code in a base class, so we repeat it in bfloat16_t.
#ifndef HWY_EMULATE_FLOAT16
  Raw raw;

  float16_t() noexcept = default;
  template <typename T>
  constexpr float16_t(T arg) noexcept : raw(static_cast<Raw>(arg)) {}
  float16_t& operator=(Raw arg) noexcept {
    raw = arg;
    return *this;
  }
  constexpr float16_t(const float16_t&) noexcept = default;
  float16_t& operator=(const float16_t&) noexcept = default;
  constexpr operator Raw() const noexcept { return raw; }

  template <typename T>
  float16_t& operator+=(T rhs) noexcept {
    raw = static_cast<Raw>(raw + rhs);
    return *this;
  }

  template <typename T>
  float16_t& operator-=(T rhs) noexcept {
    raw = static_cast<Raw>(raw - rhs);
    return *this;
  }

  template <typename T>
  float16_t& operator*=(T rhs) noexcept {
    raw = static_cast<Raw>(raw * rhs);
    return *this;
  }

  template <typename T>
  float16_t& operator/=(T rhs) noexcept {
    raw = static_cast<Raw>(raw / rhs);
    return *this;
  }

  // pre-decrement operator (--x)
  float16_t& operator--() noexcept {
    raw = static_cast<Raw>(raw - Raw{1});
    return *this;
  }

  // post-decrement operator (x--)
  float16_t operator--(int) noexcept {
    float16_t result = *this;
    raw = static_cast<Raw>(raw - Raw{1});
    return result;
  }

  // pre-increment operator (++x)
  float16_t& operator++() noexcept {
    raw = static_cast<Raw>(raw + Raw{1});
    return *this;
  }

  // post-increment operator (x++)
  float16_t operator++(int) noexcept {
    float16_t result = *this;
    raw = static_cast<Raw>(raw + Raw{1});
    return result;
  }

  constexpr float16_t operator-() const noexcept {
    return float16_t(static_cast<Raw>(-raw));
  }
  constexpr float16_t operator+() const noexcept { return *this; }
#endif  // HWY_EMULATE_FLOAT16
};

#ifndef HWY_EMULATE_FLOAT16
constexpr inline bool operator==(float16_t lhs, float16_t rhs) noexcept {
  return lhs.raw == rhs.raw;
}
constexpr inline bool operator!=(float16_t lhs, float16_t rhs) noexcept {
  return lhs.raw != rhs.raw;
}
constexpr inline bool operator<(float16_t lhs, float16_t rhs) noexcept {
  return lhs.raw < rhs.raw;
}
constexpr inline bool operator<=(float16_t lhs, float16_t rhs) noexcept {
  return lhs.raw <= rhs.raw;
}
constexpr inline bool operator>(float16_t lhs, float16_t rhs) noexcept {
  return lhs.raw > rhs.raw;
}
constexpr inline bool operator>=(float16_t lhs, float16_t rhs) noexcept {
  return lhs.raw >= rhs.raw;
}
#endif  // HWY_EMULATE_FLOAT16

struct bfloat16_t {
#if HWY_SVE_HAVE_BFLOAT16
  using Raw = __bf16;
#elif __cplusplus >= 202100L && defined(__STDCPP_BFLOAT16_T__)  // C++23
  using Raw = std::bfloat16_t;
#else
#define HWY_EMULATE_BFLOAT16
  using Raw = uint16_t;
  Raw bits;
#endif

#ifndef HWY_EMULATE_BFLOAT16
  Raw raw;

  bfloat16_t() noexcept = default;
  template <typename T>
  constexpr bfloat16_t(T arg) noexcept : raw(static_cast<Raw>(arg)) {}
  bfloat16_t& operator=(Raw arg) noexcept {
    raw = arg;
    return *this;
  }
  constexpr bfloat16_t(const bfloat16_t&) noexcept = default;
  bfloat16_t& operator=(const bfloat16_t&) noexcept = default;
  constexpr operator Raw() const noexcept { return raw; }

  template <typename T>
  bfloat16_t& operator+=(T rhs) noexcept {
    raw = static_cast<Raw>(raw + rhs);
    return *this;
  }

  template <typename T>
  bfloat16_t& operator-=(T rhs) noexcept {
    raw = static_cast<Raw>(raw - rhs);
    return *this;
  }

  template <typename T>
  bfloat16_t& operator*=(T rhs) noexcept {
    raw = static_cast<Raw>(raw * rhs);
    return *this;
  }

  template <typename T>
  bfloat16_t& operator/=(T rhs) noexcept {
    raw = static_cast<Raw>(raw / rhs);
    return *this;
  }

  // pre-decrement operator (--x)
  bfloat16_t& operator--() noexcept {
    raw = static_cast<Raw>(raw - Raw{1});
    return *this;
  }

  // post-decrement operator (x--)
  bfloat16_t operator--(int) noexcept {
    bfloat16_t result = *this;
    raw = static_cast<Raw>(raw - Raw{1});
    return result;
  }

  // pre-increment operator (++x)
  bfloat16_t& operator++() noexcept {
    raw = static_cast<Raw>(raw + Raw{1});
    return *this;
  }

  // post-increment operator (x++)
  bfloat16_t operator++(int) noexcept {
    bfloat16_t result = *this;
    raw = static_cast<Raw>(raw + Raw{1});
    return result;
  }

  constexpr bfloat16_t operator-() const noexcept {
    return bfloat16_t(static_cast<Raw>(-raw));
  }
  constexpr bfloat16_t operator+() const noexcept { return *this; }
#endif  // HWY_EMULATE_BFLOAT16
};

#ifndef HWY_EMULATE_BFLOAT16
constexpr inline bool operator==(bfloat16_t lhs, bfloat16_t rhs) noexcept {
  return lhs.raw == rhs.raw;
}
constexpr inline bool operator!=(bfloat16_t lhs, bfloat16_t rhs) noexcept {
  return lhs.raw != rhs.raw;
}
constexpr inline bool operator<(bfloat16_t lhs, bfloat16_t rhs) noexcept {
  return lhs.raw < rhs.raw;
}
constexpr inline bool operator<=(bfloat16_t lhs, bfloat16_t rhs) noexcept {
  return lhs.raw <= rhs.raw;
}
constexpr inline bool operator>(bfloat16_t lhs, bfloat16_t rhs) noexcept {
  return lhs.raw > rhs.raw;
}
constexpr inline bool operator>=(bfloat16_t lhs, bfloat16_t rhs) noexcept {
  return lhs.raw >= rhs.raw;
}
#endif  // HWY_EMULATE_BFLOAT16

#pragma pack(pop)

HWY_API float F32FromF16(float16_t f16) {
#ifdef HWY_EMULATE_FLOAT16
  uint16_t bits16;
  CopySameSize(&f16, &bits16);
  const uint32_t sign = static_cast<uint32_t>(bits16 >> 15);
  const uint32_t biased_exp = (bits16 >> 10) & 0x1F;
  const uint32_t mantissa = bits16 & 0x3FF;

  // Subnormal or zero
  if (biased_exp == 0) {
    const float subnormal =
        (1.0f / 16384) * (static_cast<float>(mantissa) * (1.0f / 1024));
    return sign ? -subnormal : subnormal;
  }

  // Normalized: convert the representation directly (faster than ldexp/tables).
  const uint32_t biased_exp32 = biased_exp + (127 - 15);
  const uint32_t mantissa32 = mantissa << (23 - 10);
  const uint32_t bits32 = (sign << 31) | (biased_exp32 << 23) | mantissa32;

  float result;
  CopySameSize(&bits32, &result);
  return result;
#else
  return static_cast<float>(f16);
#endif
}

HWY_API float16_t F16FromF32(float f32) {
#ifdef HWY_EMULATE_FLOAT16
  uint32_t bits32;
  CopySameSize(&f32, &bits32);
  const uint32_t sign = bits32 >> 31;
  const uint32_t biased_exp32 = (bits32 >> 23) & 0xFF;
  const uint32_t mantissa32 = bits32 & 0x7FFFFF;

  const int32_t exp = HWY_MIN(static_cast<int32_t>(biased_exp32) - 127, 15);

  // Tiny or zero => zero.
  float16_t out;
  if (exp < -24) {
    // restore original sign
    const uint16_t bits = static_cast<uint16_t>(sign << 15);
    CopySameSize(&bits, &out);
    return out;
  }

  uint32_t biased_exp16, mantissa16;

  // exp = [-24, -15] => subnormal
  if (exp < -14) {
    biased_exp16 = 0;
    const uint32_t sub_exp = static_cast<uint32_t>(-14 - exp);
    HWY_DASSERT(1 <= sub_exp && sub_exp < 11);
    mantissa16 = static_cast<uint32_t>((1u << (10 - sub_exp)) +
                                       (mantissa32 >> (13 + sub_exp)));
  } else {
    // exp = [-14, 15]
    biased_exp16 = static_cast<uint32_t>(exp + 15);
    HWY_DASSERT(1 <= biased_exp16 && biased_exp16 < 31);
    mantissa16 = mantissa32 >> 13;
  }

  HWY_DASSERT(mantissa16 < 1024);
  const uint32_t bits16 = (sign << 15) | (biased_exp16 << 10) | mantissa16;
  HWY_DASSERT(bits16 < 0x10000);
  const uint16_t narrowed = static_cast<uint16_t>(bits16);  // big-endian safe
  CopySameSize(&narrowed, &out);
  return out;
#else
  return float16_t(static_cast<float16_t::Raw>(f32));
#endif
}

HWY_API float F32FromBF16(bfloat16_t bf) {
  uint16_t bits16;
  CopyBytes<2>(&bf, &bits16);
  uint32_t bits = bits16;
  bits <<= 16;
  float f;
  CopySameSize(&bits, &f);
  return f;
}

HWY_API float F32FromF16Mem(const void* ptr) {
  float16_t f16;
  CopyBytes<2>(ptr, &f16);
  return F32FromF16(f16);
}

HWY_API float F32FromBF16Mem(const void* ptr) {
  bfloat16_t bf;
  CopyBytes<2>(ptr, &bf);
  return F32FromBF16(bf);
}

HWY_API bfloat16_t BF16FromF32(float f) {
  uint32_t bits;
  CopySameSize(&f, &bits);
  const uint16_t bits16 = static_cast<uint16_t>(bits >> 16);
  bfloat16_t bf;
  CopySameSize(&bits16, &bf);
  return bf;
}

using float32_t = float;
using float64_t = double;

#pragma pack(push, 1)

// Aligned 128-bit type. Cannot use __int128 because clang doesn't yet align it:
// https://reviews.llvm.org/D86310
struct alignas(16) uint128_t {
  uint64_t lo;  // little-endian layout
  uint64_t hi;
};

// 64 bit key plus 64 bit value. Faster than using uint128_t when only the key
// field is to be compared (Lt128Upper instead of Lt128).
struct alignas(16) K64V64 {
  uint64_t value;  // little-endian layout
  uint64_t key;
};

// 32 bit key plus 32 bit value. Allows vqsort recursions to terminate earlier
// than when considering both to be a 64-bit key.
struct alignas(8) K32V32 {
  uint32_t value;  // little-endian layout
  uint32_t key;
};

#pragma pack(pop)

#ifdef HWY_EMULATE_FLOAT16

static inline HWY_MAYBE_UNUSED bool operator<(const float16_t& a,
                                              const float16_t& b) {
  return F32FromF16(a) < F32FromF16(b);
}
// Required for std::greater.
static inline HWY_MAYBE_UNUSED bool operator>(const float16_t& a,
                                              const float16_t& b) {
  return F32FromF16(a) > F32FromF16(b);
}
static inline HWY_MAYBE_UNUSED bool operator==(const float16_t& a,
                                               const float16_t& b) {
  return F32FromF16(a) == F32FromF16(b);
}

#endif  // HWY_EMULATE_FLOAT16

static inline HWY_MAYBE_UNUSED bool operator<(const uint128_t& a,
                                              const uint128_t& b) {
  return (a.hi == b.hi) ? a.lo < b.lo : a.hi < b.hi;
}
// Required for std::greater.
static inline HWY_MAYBE_UNUSED bool operator>(const uint128_t& a,
                                              const uint128_t& b) {
  return b < a;
}
static inline HWY_MAYBE_UNUSED bool operator==(const uint128_t& a,
                                               const uint128_t& b) {
  return a.lo == b.lo && a.hi == b.hi;
}

static inline HWY_MAYBE_UNUSED bool operator<(const K64V64& a,
                                              const K64V64& b) {
  return a.key < b.key;
}
// Required for std::greater.
static inline HWY_MAYBE_UNUSED bool operator>(const K64V64& a,
                                              const K64V64& b) {
  return b < a;
}
static inline HWY_MAYBE_UNUSED bool operator==(const K64V64& a,
                                               const K64V64& b) {
  return a.key == b.key;
}

static inline HWY_MAYBE_UNUSED bool operator<(const K32V32& a,
                                              const K32V32& b) {
  return a.key < b.key;
}
// Required for std::greater.
static inline HWY_MAYBE_UNUSED bool operator>(const K32V32& a,
                                              const K32V32& b) {
  return b < a;
}
static inline HWY_MAYBE_UNUSED bool operator==(const K32V32& a,
                                               const K32V32& b) {
  return a.key == b.key;
}

//------------------------------------------------------------------------------
// Controlling overload resolution (SFINAE)

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
HWY_API constexpr bool IsSame() {
  return IsSameT<T, U>::value;
}

template <bool Condition, typename Then, typename Else>
struct IfT {
  using type = Then;
};

template <class Then, class Else>
struct IfT<false, Then, Else> {
  using type = Else;
};

template <bool Condition, typename Then, typename Else>
using If = typename IfT<Condition, Then, Else>::type;

// Insert into template/function arguments to enable this overload only for
// vectors of exactly, at most (LE), or more than (GT) this many bytes.
//
// As an example, checking for a total size of 16 bytes will match both
// Simd<uint8_t, 16, 0> and Simd<uint8_t, 8, 1>.
#define HWY_IF_V_SIZE(T, kN, bytes) \
  hwy::EnableIf<kN * sizeof(T) == bytes>* = nullptr
#define HWY_IF_V_SIZE_LE(T, kN, bytes) \
  hwy::EnableIf<kN * sizeof(T) <= bytes>* = nullptr
#define HWY_IF_V_SIZE_GT(T, kN, bytes) \
  hwy::EnableIf<(kN * sizeof(T) > bytes)>* = nullptr

#define HWY_IF_LANES(kN, lanes) hwy::EnableIf<(kN == lanes)>* = nullptr
#define HWY_IF_LANES_LE(kN, lanes) hwy::EnableIf<(kN <= lanes)>* = nullptr
#define HWY_IF_LANES_GT(kN, lanes) hwy::EnableIf<(kN > lanes)>* = nullptr

#define HWY_IF_UNSIGNED(T) hwy::EnableIf<!IsSigned<T>()>* = nullptr
#define HWY_IF_SIGNED(T)                                                   \
  hwy::EnableIf<IsSigned<T>() && !IsFloat<T>() && !IsSpecialFloat<T>()>* = \
      nullptr
#define HWY_IF_FLOAT(T) hwy::EnableIf<hwy::IsFloat<T>()>* = nullptr
#define HWY_IF_NOT_FLOAT(T) hwy::EnableIf<!hwy::IsFloat<T>()>* = nullptr
#define HWY_IF_FLOAT3264(T) hwy::EnableIf<hwy::IsFloat3264<T>()>* = nullptr
#define HWY_IF_NOT_FLOAT3264(T) hwy::EnableIf<!hwy::IsFloat3264<T>()>* = nullptr
#define HWY_IF_SPECIAL_FLOAT(T) \
  hwy::EnableIf<hwy::IsSpecialFloat<T>()>* = nullptr
#define HWY_IF_NOT_SPECIAL_FLOAT(T) \
  hwy::EnableIf<!hwy::IsSpecialFloat<T>()>* = nullptr
#define HWY_IF_FLOAT_OR_SPECIAL(T) \
  hwy::EnableIf<hwy::IsFloat<T>() || hwy::IsSpecialFloat<T>()>* = nullptr
#define HWY_IF_NOT_FLOAT_NOR_SPECIAL(T) \
  hwy::EnableIf<!hwy::IsFloat<T>() && !hwy::IsSpecialFloat<T>()>* = nullptr

#define HWY_IF_T_SIZE(T, bytes) hwy::EnableIf<sizeof(T) == (bytes)>* = nullptr
#define HWY_IF_NOT_T_SIZE(T, bytes) \
  hwy::EnableIf<sizeof(T) != (bytes)>* = nullptr
// bit_array = 0x102 means 1 or 8 bytes. There is no NONE_OF because it sounds
// too similar. If you want the opposite of this (2 or 4 bytes), ask for those
// bits explicitly (0x14) instead of attempting to 'negate' 0x102.
#define HWY_IF_T_SIZE_ONE_OF(T, bit_array) \
  hwy::EnableIf<((size_t{1} << sizeof(T)) & (bit_array)) != 0>* = nullptr

// Use instead of HWY_IF_T_SIZE to avoid ambiguity with float16_t/float/double
// overloads.
#define HWY_IF_UI16(T) \
  hwy::EnableIf<IsSame<T, uint16_t>() || IsSame<T, int16_t>()>* = nullptr
#define HWY_IF_UI32(T) \
  hwy::EnableIf<IsSame<T, uint32_t>() || IsSame<T, int32_t>()>* = nullptr
#define HWY_IF_UI64(T) \
  hwy::EnableIf<IsSame<T, uint64_t>() || IsSame<T, int64_t>()>* = nullptr
#define HWY_IF_BF16(T) hwy::EnableIf<IsSame<T, hwy::bfloat16_t>()>* = nullptr
#define HWY_IF_F16(T) hwy::EnableIf<IsSame<T, hwy::float16_t>()>* = nullptr

#define HWY_IF_LANES_PER_BLOCK(T, N, LANES) \
  hwy::EnableIf<HWY_MIN(sizeof(T) * N, 16) / sizeof(T) == (LANES)>* = nullptr

// Empty struct used as a size tag type.
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
struct RemoveRefT<T&&> {
  using type = T;
};

template <class T>
using RemoveRef = typename RemoveRefT<T>::type;

//------------------------------------------------------------------------------
// Type relations

namespace detail {

template <typename T>
struct Relations;
template <>
struct Relations<uint8_t> {
  using Unsigned = uint8_t;
  using Signed = int8_t;
  using Wide = uint16_t;
  enum { is_signed = 0, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<int8_t> {
  using Unsigned = uint8_t;
  using Signed = int8_t;
  using Wide = int16_t;
  enum { is_signed = 1, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<uint16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Float = float16_t;
  using Wide = uint32_t;
  using Narrow = uint8_t;
  enum { is_signed = 0, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<int16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Float = float16_t;
  using Wide = int32_t;
  using Narrow = int8_t;
  enum { is_signed = 1, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<uint32_t> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
  using Wide = uint64_t;
  using Narrow = uint16_t;
  enum { is_signed = 0, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<int32_t> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
  using Wide = int64_t;
  using Narrow = int16_t;
  enum { is_signed = 1, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<uint64_t> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
  using Wide = uint128_t;
  using Narrow = uint32_t;
  enum { is_signed = 0, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<int64_t> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
  using Narrow = int32_t;
  enum { is_signed = 1, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<uint128_t> {
  using Unsigned = uint128_t;
  using Narrow = uint64_t;
  enum { is_signed = 0, is_float = 0, is_bf16 = 0 };
};
template <>
struct Relations<float16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Float = float16_t;
  using Wide = float;
  enum { is_signed = 1, is_float = 1, is_bf16 = 0 };
};
template <>
struct Relations<bfloat16_t> {
  using Unsigned = uint16_t;
  using Signed = int16_t;
  using Wide = float;
  enum { is_signed = 1, is_float = 1, is_bf16 = 1 };
};
template <>
struct Relations<float> {
  using Unsigned = uint32_t;
  using Signed = int32_t;
  using Float = float;
  using Wide = double;
  using Narrow = float16_t;
  enum { is_signed = 1, is_float = 1, is_bf16 = 0 };
};
template <>
struct Relations<double> {
  using Unsigned = uint64_t;
  using Signed = int64_t;
  using Float = double;
  using Narrow = float;
  enum { is_signed = 1, is_float = 1, is_bf16 = 0 };
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
  using Float = float16_t;
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

}  // namespace detail

// Aliases for types of a different category, but the same size.
template <typename T>
using MakeUnsigned = typename detail::Relations<T>::Unsigned;
template <typename T>
using MakeSigned = typename detail::Relations<T>::Signed;
template <typename T>
using MakeFloat = typename detail::Relations<T>::Float;

// Aliases for types of the same category, but different size.
template <typename T>
using MakeWide = typename detail::Relations<T>::Wide;
template <typename T>
using MakeNarrow = typename detail::Relations<T>::Narrow;

// Obtain type from its size [bytes].
template <size_t N>
using UnsignedFromSize = typename detail::TypeFromSize<N>::Unsigned;
template <size_t N>
using SignedFromSize = typename detail::TypeFromSize<N>::Signed;
template <size_t N>
using FloatFromSize = typename detail::TypeFromSize<N>::Float;

// Avoid confusion with SizeTag where the parameter is a lane size.
using UnsignedTag = SizeTag<0>;
using SignedTag = SizeTag<0x100>;  // integer
using FloatTag = SizeTag<0x200>;
using SpecialTag = SizeTag<0x300>;

template <typename T, class R = detail::Relations<T>>
constexpr auto TypeTag()
    -> hwy::SizeTag<((R::is_signed + R::is_float + R::is_bf16) << 8)> {
  return hwy::SizeTag<((R::is_signed + R::is_float + R::is_bf16) << 8)>();
}

// For when we only want to distinguish FloatTag from everything else.
using NonFloatTag = SizeTag<0x400>;

template <typename T, class R = detail::Relations<T>>
constexpr auto IsFloatTag() -> hwy::SizeTag<(R::is_float ? 0x200 : 0x400)> {
  return hwy::SizeTag<(R::is_float ? 0x200 : 0x400)>();
}

//------------------------------------------------------------------------------
// Type traits

template <typename T>
HWY_API constexpr bool IsFloat3264() {
  return IsSame<T, float>() || IsSame<T, double>();
}

template <typename T>
HWY_API constexpr bool IsFloat() {
  // Cannot use T(1.25) != T(1) for float16_t, which can only be converted to or
  // from a float, not compared. Include float16_t in case HWY_HAVE_FLOAT16=1.
  return IsSame<T, float16_t>() || IsFloat3264<T>();
}

// These types are often special-cased and not supported in all ops.
template <typename T>
HWY_API constexpr bool IsSpecialFloat() {
  return IsSame<T, float16_t>() || IsSame<T, bfloat16_t>();
}

template <typename T>
HWY_API constexpr bool IsSigned() {
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

// Largest/smallest representable integer values.
template <typename T>
HWY_API constexpr T LimitsMax() {
  static_assert(!IsFloat<T>(), "Only for integer types");
  using TU = MakeUnsigned<T>;
  return static_cast<T>(IsSigned<T>() ? (static_cast<TU>(~0ull) >> 1)
                                      : static_cast<TU>(~0ull));
}
template <typename T>
HWY_API constexpr T LimitsMin() {
  static_assert(!IsFloat<T>(), "Only for integer types");
  return IsSigned<T>() ? T(-1) - LimitsMax<T>() : T(0);
}

// Largest/smallest representable value (integer or float). This naming avoids
// confusion with numeric_limits<float>::min() (the smallest positive value).
// Cannot be constexpr because we use CopySameSize for [b]float16_t.
template <typename T>
HWY_API T LowestValue() {
  return LimitsMin<T>();
}
template <>
HWY_INLINE bfloat16_t LowestValue<bfloat16_t>() {
  const uint16_t kBits = 0xFF7F;  // -1.1111111 x 2^127
  bfloat16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float16_t LowestValue<float16_t>() {
  const uint16_t kBits = 0xFBFF;  // -1.1111111111 x 2^15
  float16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float LowestValue<float>() {
  return -3.402823466e+38F;
}
template <>
HWY_INLINE double LowestValue<double>() {
  return -1.7976931348623158e+308;
}

template <typename T>
HWY_API T HighestValue() {
  return LimitsMax<T>();
}
template <>
HWY_INLINE bfloat16_t HighestValue<bfloat16_t>() {
  const uint16_t kBits = 0x7F7F;  // 1.1111111 x 2^127
  bfloat16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float16_t HighestValue<float16_t>() {
  const uint16_t kBits = 0x7BFF;  // 1.1111111111 x 2^15
  float16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float HighestValue<float>() {
  return 3.402823466e+38F;
}
template <>
HWY_INLINE double HighestValue<double>() {
  return 1.7976931348623158e+308;
}

// Difference between 1.0 and the next representable value. Equal to
// 1 / (1ULL << MantissaBits<T>()), but hard-coding ensures precision.
template <typename T>
HWY_API T Epsilon() {
  return 1;
}
template <>
HWY_INLINE bfloat16_t Epsilon<bfloat16_t>() {
  const uint16_t kBits = 0x3C00;  // 0.0078125
  bfloat16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float16_t Epsilon<float16_t>() {
  const uint16_t kBits = 0x1400;  // 0.0009765625
  float16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float Epsilon<float>() {
  return 1.192092896e-7f;
}
template <>
HWY_INLINE double Epsilon<double>() {
  return 2.2204460492503131e-16;
}

// Returns width in bits of the mantissa field in IEEE binary16/32/64.
template <typename T>
constexpr int MantissaBits() {
  static_assert(sizeof(T) == 0, "Only instantiate the specializations");
  return 0;
}
template <>
constexpr int MantissaBits<bfloat16_t>() {
  return 7;
}
template <>
constexpr int MantissaBits<float16_t>() {
  return 10;
}
template <>
constexpr int MantissaBits<float>() {
  return 23;
}
template <>
constexpr int MantissaBits<double>() {
  return 52;
}

// Returns the (left-shifted by one bit) IEEE binary16/32/64 representation with
// the largest possible (biased) exponent field. Used by IsInf.
template <typename T>
constexpr MakeSigned<T> MaxExponentTimes2() {
  return -(MakeSigned<T>{1} << (MantissaBits<T>() + 1));
}

// Returns bitmask of the sign bit in IEEE binary16/32/64.
template <typename T>
constexpr MakeUnsigned<T> SignMask() {
  return MakeUnsigned<T>{1} << (sizeof(T) * 8 - 1);
}

// Returns bitmask of the exponent field in IEEE binary16/32/64.
template <typename T>
constexpr MakeUnsigned<T> ExponentMask() {
  return (~(MakeUnsigned<T>{1} << MantissaBits<T>()) + 1) & ~SignMask<T>();
}

// Returns bitmask of the mantissa field in IEEE binary16/32/64.
template <typename T>
constexpr MakeUnsigned<T> MantissaMask() {
  return (MakeUnsigned<T>{1} << MantissaBits<T>()) - 1;
}

// Returns 1 << mantissa_bits as a floating-point number. All integers whose
// absolute value are less than this can be represented exactly.
template <typename T>
HWY_INLINE T MantissaEnd() {
  static_assert(sizeof(T) == 0, "Only instantiate the specializations");
  return 0;
}
template <>
HWY_INLINE bfloat16_t MantissaEnd<bfloat16_t>() {
  const uint16_t kBits = 0x4300;  // 1.0 x 2^7
  bfloat16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float16_t MantissaEnd<float16_t>() {
  const uint16_t kBits = 0x6400;  // 1.0 x 2^10
  float16_t ret;
  CopySameSize(&kBits, &ret);
  return ret;
}
template <>
HWY_INLINE float MantissaEnd<float>() {
  return 8388608.0f;  // 1 << 23
}
template <>
HWY_INLINE double MantissaEnd<double>() {
  // floating point literal with p52 requires C++17.
  return 4503599627370496.0;  // 1 << 52
}

// Returns width in bits of the exponent field in IEEE binary16/32/64.
template <typename T>
constexpr int ExponentBits() {
  // Exponent := remaining bits after deducting sign and mantissa.
  return 8 * sizeof(T) - 1 - MantissaBits<T>();
}

// Returns largest value of the biased exponent field in IEEE binary16/32/64,
// right-shifted so that the LSB is bit zero. Example: 0xFF for float.
// This is expressed as a signed integer for more efficient comparison.
template <typename T>
constexpr MakeSigned<T> MaxExponentField() {
  return (MakeSigned<T>{1} << ExponentBits<T>()) - 1;
}

//------------------------------------------------------------------------------
// Helper functions

template <typename T1, typename T2>
constexpr inline T1 DivCeil(T1 a, T2 b) {
  return (a + b - 1) / b;
}

// Works for any `align`; if a power of two, compiler emits ADD+AND.
constexpr inline size_t RoundUpTo(size_t what, size_t align) {
  return DivCeil(what, align) * align;
}

// Undefined results for x == 0.
HWY_API size_t Num0BitsBelowLS1Bit_Nonzero32(const uint32_t x) {
#if HWY_COMPILER_MSVC
  unsigned long index;  // NOLINT
  _BitScanForward(&index, x);
  return index;
#else   // HWY_COMPILER_MSVC
  return static_cast<size_t>(__builtin_ctz(x));
#endif  // HWY_COMPILER_MSVC
}

HWY_API size_t Num0BitsBelowLS1Bit_Nonzero64(const uint64_t x) {
#if HWY_COMPILER_MSVC
#if HWY_ARCH_X86_64
  unsigned long index;  // NOLINT
  _BitScanForward64(&index, x);
  return index;
#else   // HWY_ARCH_X86_64
  // _BitScanForward64 not available
  uint32_t lsb = static_cast<uint32_t>(x & 0xFFFFFFFF);
  unsigned long index;  // NOLINT
  if (lsb == 0) {
    uint32_t msb = static_cast<uint32_t>(x >> 32u);
    _BitScanForward(&index, msb);
    return 32 + index;
  } else {
    _BitScanForward(&index, lsb);
    return index;
  }
#endif  // HWY_ARCH_X86_64
#else   // HWY_COMPILER_MSVC
  return static_cast<size_t>(__builtin_ctzll(x));
#endif  // HWY_COMPILER_MSVC
}

// Undefined results for x == 0.
HWY_API size_t Num0BitsAboveMS1Bit_Nonzero32(const uint32_t x) {
#if HWY_COMPILER_MSVC
  unsigned long index;  // NOLINT
  _BitScanReverse(&index, x);
  return 31 - index;
#else   // HWY_COMPILER_MSVC
  return static_cast<size_t>(__builtin_clz(x));
#endif  // HWY_COMPILER_MSVC
}

HWY_API size_t Num0BitsAboveMS1Bit_Nonzero64(const uint64_t x) {
#if HWY_COMPILER_MSVC
#if HWY_ARCH_X86_64
  unsigned long index;  // NOLINT
  _BitScanReverse64(&index, x);
  return 63 - index;
#else   // HWY_ARCH_X86_64
  // _BitScanReverse64 not available
  const uint32_t msb = static_cast<uint32_t>(x >> 32u);
  unsigned long index;  // NOLINT
  if (msb == 0) {
    const uint32_t lsb = static_cast<uint32_t>(x & 0xFFFFFFFF);
    _BitScanReverse(&index, lsb);
    return 63 - index;
  } else {
    _BitScanReverse(&index, msb);
    return 31 - index;
  }
#endif  // HWY_ARCH_X86_64
#else   // HWY_COMPILER_MSVC
  return static_cast<size_t>(__builtin_clzll(x));
#endif  // HWY_COMPILER_MSVC
}

HWY_API size_t PopCount(uint64_t x) {
#if HWY_COMPILER_GCC  // includes clang
  return static_cast<size_t>(__builtin_popcountll(x));
  // This instruction has a separate feature flag, but is often called from
  // non-SIMD code, so we don't want to require dynamic dispatch. It was first
  // supported by Intel in Nehalem (SSE4.2), but MSVC only predefines a macro
  // for AVX, so check for that.
#elif HWY_COMPILER_MSVC && HWY_ARCH_X86_64 && defined(__AVX__)
  return _mm_popcnt_u64(x);
#elif HWY_COMPILER_MSVC && HWY_ARCH_X86_32 && defined(__AVX__)
  return _mm_popcnt_u32(static_cast<uint32_t>(x & 0xFFFFFFFFu)) +
         _mm_popcnt_u32(static_cast<uint32_t>(x >> 32));
#else
  x -= ((x >> 1) & 0x5555555555555555ULL);
  x = (((x >> 2) & 0x3333333333333333ULL) + (x & 0x3333333333333333ULL));
  x = (((x >> 4) + x) & 0x0F0F0F0F0F0F0F0FULL);
  x += (x >> 8);
  x += (x >> 16);
  x += (x >> 32);
  return static_cast<size_t>(x & 0x7Fu);
#endif
}

// Skip HWY_API due to GCC "function not considered for inlining". Previously
// such errors were caused by underlying type mismatches, but it's not clear
// what is still mismatched despite all the casts.
template <typename TI>
/*HWY_API*/ constexpr size_t FloorLog2(TI x) {
  return x == TI{1}
             ? 0
             : static_cast<size_t>(FloorLog2(static_cast<TI>(x >> 1)) + 1);
}

template <typename TI>
/*HWY_API*/ constexpr size_t CeilLog2(TI x) {
  return x == TI{1}
             ? 0
             : static_cast<size_t>(FloorLog2(static_cast<TI>(x - 1)) + 1);
}

template <typename T>
HWY_INLINE constexpr T AddWithWraparound(hwy::FloatTag /*tag*/, T t, size_t n) {
  return t + static_cast<T>(n);
}

template <typename T>
HWY_INLINE constexpr T AddWithWraparound(hwy::NonFloatTag /*tag*/, T t,
                                         size_t n) {
  using TU = MakeUnsigned<T>;
  return static_cast<T>(
      static_cast<TU>(static_cast<TU>(t) + static_cast<TU>(n)) &
      hwy::LimitsMax<TU>());
}

#if HWY_COMPILER_MSVC && HWY_ARCH_X86_64
#pragma intrinsic(_umul128)
#endif

// 64 x 64 = 128 bit multiplication
HWY_API uint64_t Mul128(uint64_t a, uint64_t b, uint64_t* HWY_RESTRICT upper) {
#if defined(__SIZEOF_INT128__)
  __uint128_t product = (__uint128_t)a * (__uint128_t)b;
  *upper = (uint64_t)(product >> 64);
  return (uint64_t)(product & 0xFFFFFFFFFFFFFFFFULL);
#elif HWY_COMPILER_MSVC && HWY_ARCH_X86_64
  return _umul128(a, b, upper);
#else
  constexpr uint64_t kLo32 = 0xFFFFFFFFU;
  const uint64_t lo_lo = (a & kLo32) * (b & kLo32);
  const uint64_t hi_lo = (a >> 32) * (b & kLo32);
  const uint64_t lo_hi = (a & kLo32) * (b >> 32);
  const uint64_t hi_hi = (a >> 32) * (b >> 32);
  const uint64_t t = (lo_lo >> 32) + (hi_lo & kLo32) + lo_hi;
  *upper = (hi_lo >> 32) + (t >> 32) + hi_hi;
  return (t << 32) | (lo_lo & kLo32);
#endif
}

// Prevents the compiler from eliding the computations that led to "output".
template <class T>
HWY_API void PreventElision(T&& output) {
#if HWY_COMPILER_MSVC
  // MSVC does not support inline assembly anymore (and never supported GCC's
  // RTL constraints). Self-assignment with #pragma optimize("off") might be
  // expected to prevent elision, but it does not with MSVC 2015. Type-punning
  // with volatile pointers generates inefficient code on MSVC 2017.
  static std::atomic<RemoveRef<T>> dummy;
  dummy.store(output, std::memory_order_relaxed);
#else
  // Works by indicating to the compiler that "output" is being read and
  // modified. The +r constraint avoids unnecessary writes to memory, but only
  // works for built-in types (typically FuncOutput).
  asm volatile("" : "+r"(output) : : "memory");
#endif
}

}  // namespace hwy

#endif  // HIGHWAY_HWY_BASE_H_
#include "hwy/detect_compiler_arch.h"
#include "hwy/highway_export.h"
#include "hwy/targets.h"
// IWYU pragma: end_exports

// This include guard is checked by foreach_target, so avoid the usual _H_
// suffix to prevent copybara from renaming it. NOTE: ops/*-inl.h are included
// after/outside this include guard.
#ifndef HWY_HIGHWAY_INCLUDED
#define HWY_HIGHWAY_INCLUDED

namespace hwy {

// API version (https://semver.org/); keep in sync with CMakeLists.txt.
#define HWY_MAJOR 1
#define HWY_MINOR 0
#define HWY_PATCH 7

//------------------------------------------------------------------------------
// Shorthand for tags (defined in shared-inl.h) used to select overloads.
// Note that ScalableTag<T> is preferred over HWY_FULL, and CappedTag<T, N> over
// HWY_CAPPED(T, N).

// HWY_FULL(T[,LMUL=1]) is a native vector/group. LMUL is the number of
// registers in the group, and is ignored on targets that do not support groups.
#define HWY_FULL1(T) hwy::HWY_NAMESPACE::ScalableTag<T>
#define HWY_FULL2(T, LMUL) \
  hwy::HWY_NAMESPACE::ScalableTag<T, hwy::CeilLog2(HWY_MAX(0, LMUL))>
#define HWY_3TH_ARG(arg1, arg2, arg3, ...) arg3
// Workaround for MSVC grouping __VA_ARGS__ into a single argument
#define HWY_FULL_RECOMPOSER(args_with_paren) HWY_3TH_ARG args_with_paren
// Trailing comma avoids -pedantic false alarm
#define HWY_CHOOSE_FULL(...) \
  HWY_FULL_RECOMPOSER((__VA_ARGS__, HWY_FULL2, HWY_FULL1, ))
#define HWY_FULL(...) HWY_CHOOSE_FULL(__VA_ARGS__())(__VA_ARGS__)

// Vector of up to MAX_N lanes. It's better to use full vectors where possible.
#define HWY_CAPPED(T, MAX_N) hwy::HWY_NAMESPACE::CappedTag<T, MAX_N>

//------------------------------------------------------------------------------
// Export user functions for static/dynamic dispatch

// Evaluates to 0 inside a translation unit if it is generating anything but the
// static target (the last one if multiple targets are enabled). Used to prevent
// redefinitions of HWY_EXPORT. Unless foreach_target.h is included, we only
// compile once anyway, so this is 1 unless it is or has been included.
#ifndef HWY_ONCE
#define HWY_ONCE 1
#endif

// HWY_STATIC_DISPATCH(FUNC_NAME) is the namespace-qualified FUNC_NAME for
// HWY_STATIC_TARGET (the only defined namespace unless HWY_TARGET_INCLUDE is
// defined), and can be used to deduce the return type of Choose*.
#if HWY_STATIC_TARGET == HWY_SCALAR
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SCALAR::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_EMU128
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_EMU128::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_RVV
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_RVV::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_WASM_EMU256
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_WASM_EMU256::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_WASM
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_WASM::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_NEON_WITHOUT_AES
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_NEON_WITHOUT_AES::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_NEON
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_NEON::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SVE
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SVE::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SVE2
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SVE2::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SVE_256
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SVE_256::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SVE2_128
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SVE2_128::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_PPC8
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_PPC8::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_PPC9
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_PPC9::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_PPC10
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_PPC10::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SSE2
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SSE2::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SSSE3
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SSSE3::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_SSE4
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_SSE4::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_AVX2
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_AVX2::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_AVX3
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_AVX3::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_AVX3_DL
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_AVX3_DL::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_AVX3_ZEN4
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_AVX3_ZEN4::FUNC_NAME
#elif HWY_STATIC_TARGET == HWY_AVX3_SPR
#define HWY_STATIC_DISPATCH(FUNC_NAME) N_AVX3_SPR::FUNC_NAME
#endif

// HWY_CHOOSE_*(FUNC_NAME) expands to the function pointer for that target or
// nullptr is that target was not compiled.
#if HWY_TARGETS & HWY_EMU128
#define HWY_CHOOSE_FALLBACK(FUNC_NAME) &N_EMU128::FUNC_NAME
#elif HWY_TARGETS & HWY_SCALAR
#define HWY_CHOOSE_FALLBACK(FUNC_NAME) &N_SCALAR::FUNC_NAME
#else
// When HWY_SCALAR/HWY_EMU128 are not present and other targets were disabled at
// runtime, fall back to the baseline with HWY_STATIC_DISPATCH().
#define HWY_CHOOSE_FALLBACK(FUNC_NAME) &HWY_STATIC_DISPATCH(FUNC_NAME)
#endif

#if HWY_TARGETS & HWY_WASM_EMU256
#define HWY_CHOOSE_WASM_EMU256(FUNC_NAME) &N_WASM_EMU256::FUNC_NAME
#else
#define HWY_CHOOSE_WASM_EMU256(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_WASM
#define HWY_CHOOSE_WASM(FUNC_NAME) &N_WASM::FUNC_NAME
#else
#define HWY_CHOOSE_WASM(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_RVV
#define HWY_CHOOSE_RVV(FUNC_NAME) &N_RVV::FUNC_NAME
#else
#define HWY_CHOOSE_RVV(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_NEON_WITHOUT_AES
#define HWY_CHOOSE_NEON_WITHOUT_AES(FUNC_NAME) &N_NEON_WITHOUT_AES::FUNC_NAME
#else
#define HWY_CHOOSE_NEON_WITHOUT_AES(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_NEON
#define HWY_CHOOSE_NEON(FUNC_NAME) &N_NEON::FUNC_NAME
#else
#define HWY_CHOOSE_NEON(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SVE
#define HWY_CHOOSE_SVE(FUNC_NAME) &N_SVE::FUNC_NAME
#else
#define HWY_CHOOSE_SVE(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SVE2
#define HWY_CHOOSE_SVE2(FUNC_NAME) &N_SVE2::FUNC_NAME
#else
#define HWY_CHOOSE_SVE2(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SVE_256
#define HWY_CHOOSE_SVE_256(FUNC_NAME) &N_SVE_256::FUNC_NAME
#else
#define HWY_CHOOSE_SVE_256(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SVE2_128
#define HWY_CHOOSE_SVE2_128(FUNC_NAME) &N_SVE2_128::FUNC_NAME
#else
#define HWY_CHOOSE_SVE2_128(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_PPC8
#define HWY_CHOOSE_PPC8(FUNC_NAME) &N_PPC8::FUNC_NAME
#else
#define HWY_CHOOSE_PPC8(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_PPC9
#define HWY_CHOOSE_PPC9(FUNC_NAME) &N_PPC9::FUNC_NAME
#else
#define HWY_CHOOSE_PPC9(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_PPC10
#define HWY_CHOOSE_PPC10(FUNC_NAME) &N_PPC10::FUNC_NAME
#else
#define HWY_CHOOSE_PPC10(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SSE2
#define HWY_CHOOSE_SSE2(FUNC_NAME) &N_SSE2::FUNC_NAME
#else
#define HWY_CHOOSE_SSE2(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SSSE3
#define HWY_CHOOSE_SSSE3(FUNC_NAME) &N_SSSE3::FUNC_NAME
#else
#define HWY_CHOOSE_SSSE3(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_SSE4
#define HWY_CHOOSE_SSE4(FUNC_NAME) &N_SSE4::FUNC_NAME
#else
#define HWY_CHOOSE_SSE4(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_AVX2
#define HWY_CHOOSE_AVX2(FUNC_NAME) &N_AVX2::FUNC_NAME
#else
#define HWY_CHOOSE_AVX2(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_AVX3
#define HWY_CHOOSE_AVX3(FUNC_NAME) &N_AVX3::FUNC_NAME
#else
#define HWY_CHOOSE_AVX3(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_AVX3_DL
#define HWY_CHOOSE_AVX3_DL(FUNC_NAME) &N_AVX3_DL::FUNC_NAME
#else
#define HWY_CHOOSE_AVX3_DL(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_AVX3_ZEN4
#define HWY_CHOOSE_AVX3_ZEN4(FUNC_NAME) &N_AVX3_ZEN4::FUNC_NAME
#else
#define HWY_CHOOSE_AVX3_ZEN4(FUNC_NAME) nullptr
#endif

#if HWY_TARGETS & HWY_AVX3_SPR
#define HWY_CHOOSE_AVX3_SPR(FUNC_NAME) &N_AVX3_SPR::FUNC_NAME
#else
#define HWY_CHOOSE_AVX3_SPR(FUNC_NAME) nullptr
#endif

// MSVC 2017 workaround: the non-type template parameter to ChooseAndCall
// apparently cannot be an array. Use a function pointer instead, which has the
// disadvantage that we call the static (not best) target on the first call to
// any HWY_DYNAMIC_DISPATCH.
#if HWY_COMPILER_MSVC && HWY_COMPILER_MSVC < 1915
#define HWY_DISPATCH_WORKAROUND 1
#else
#define HWY_DISPATCH_WORKAROUND 0
#endif

// Provides a static member function which is what is called during the first
// HWY_DYNAMIC_DISPATCH, where GetIndex is still zero, and instantiations of
// this function are the first entry in the tables created by HWY_EXPORT.
template <typename RetType, typename... Args>
struct FunctionCache {
 public:
  typedef RetType(FunctionType)(Args...);

#if HWY_DISPATCH_WORKAROUND
  template <FunctionType* const func>
  static RetType ChooseAndCall(Args... args) {
    ChosenTarget& chosen_target = GetChosenTarget();
    chosen_target.Update(SupportedTargets());
    return (*func)(args...);
  }
#else
  // A template function that when instantiated has the same signature as the
  // function being called. This function initializes the bit array of targets
  // supported by the current CPU and then calls the appropriate entry within
  // the HWY_EXPORT table. Subsequent calls via HWY_DYNAMIC_DISPATCH to any
  // exported functions, even those defined by different translation units,
  // will dispatch directly to the best available target.
  template <FunctionType* const table[]>
  static RetType ChooseAndCall(Args... args) {
    ChosenTarget& chosen_target = GetChosenTarget();
    chosen_target.Update(SupportedTargets());
    return (table[chosen_target.GetIndex()])(args...);
  }
#endif  // HWY_DISPATCH_WORKAROUND
};

// Used to deduce the template parameters RetType and Args from a function.
template <typename RetType, typename... Args>
FunctionCache<RetType, Args...> DeduceFunctionCache(RetType (*)(Args...)) {
  return FunctionCache<RetType, Args...>();
}

#define HWY_DISPATCH_TABLE(FUNC_NAME) \
  HWY_CONCAT(FUNC_NAME, HighwayDispatchTable)

// HWY_EXPORT(FUNC_NAME); expands to a static array that is used by
// HWY_DYNAMIC_DISPATCH() to call the appropriate function at runtime. This
// static array must be defined at the same namespace level as the function
// it is exporting.
// After being exported, it can be called from other parts of the same source
// file using HWY_DYNAMIC_DISPATCH(), in particular from a function wrapper
// like in the following example:
//
//   #include "hwy/highway.h"
//   HWY_BEFORE_NAMESPACE();
//   namespace skeleton {
//   namespace HWY_NAMESPACE {
//
//   void MyFunction(int a, char b, const char* c) { ... }
//
//   // NOLINTNEXTLINE(google-readability-namespace-comments)
//   }  // namespace HWY_NAMESPACE
//   }  // namespace skeleton
//   HWY_AFTER_NAMESPACE();
//
//   namespace skeleton {
//   HWY_EXPORT(MyFunction);  // Defines the dispatch table in this scope.
//
//   void MyFunction(int a, char b, const char* c) {
//     return HWY_DYNAMIC_DISPATCH(MyFunction)(a, b, c);
//   }
//   }  // namespace skeleton
//

#if HWY_IDE || ((HWY_TARGETS & (HWY_TARGETS - 1)) == 0)

// Simplified version for IDE or the dynamic dispatch case with only one target.
// This case still uses a table, although of a single element, to provide the
// same compile error conditions as with the dynamic dispatch case when multiple
// targets are being compiled.
#define HWY_EXPORT(FUNC_NAME)                                             \
  HWY_MAYBE_UNUSED static decltype(&HWY_STATIC_DISPATCH(FUNC_NAME)) const \
  HWY_DISPATCH_TABLE(FUNC_NAME)[1] = {&HWY_STATIC_DISPATCH(FUNC_NAME)}
#define HWY_DYNAMIC_DISPATCH(FUNC_NAME) HWY_STATIC_DISPATCH(FUNC_NAME)
#define HWY_DYNAMIC_POINTER(FUNC_NAME) &HWY_STATIC_DISPATCH(FUNC_NAME)

#else

// Simplified version for MSVC 2017: function pointer instead of table.
#if HWY_DISPATCH_WORKAROUND

#define HWY_EXPORT(FUNC_NAME)                                                \
  static decltype(&HWY_STATIC_DISPATCH(FUNC_NAME)) const HWY_DISPATCH_TABLE( \
      FUNC_NAME)[HWY_MAX_DYNAMIC_TARGETS + 2] = {                            \
      /* The first entry in the table initializes the global cache and       \
       * calls the function from HWY_STATIC_TARGET. */                       \
      &decltype(hwy::DeduceFunctionCache(&HWY_STATIC_DISPATCH(               \
          FUNC_NAME)))::ChooseAndCall<&HWY_STATIC_DISPATCH(FUNC_NAME)>,      \
      HWY_CHOOSE_TARGET_LIST(FUNC_NAME),                                     \
      HWY_CHOOSE_FALLBACK(FUNC_NAME),                                        \
  }

#else

// Dynamic dispatch case with one entry per dynamic target plus the fallback
// target and the initialization wrapper.
#define HWY_EXPORT(FUNC_NAME)                                                \
  static decltype(&HWY_STATIC_DISPATCH(FUNC_NAME)) const HWY_DISPATCH_TABLE( \
      FUNC_NAME)[HWY_MAX_DYNAMIC_TARGETS + 2] = {                            \
      /* The first entry in the table initializes the global cache and       \
       * calls the appropriate function. */                                  \
      &decltype(hwy::DeduceFunctionCache(&HWY_STATIC_DISPATCH(               \
          FUNC_NAME)))::ChooseAndCall<HWY_DISPATCH_TABLE(FUNC_NAME)>,        \
      HWY_CHOOSE_TARGET_LIST(FUNC_NAME),                                     \
      HWY_CHOOSE_FALLBACK(FUNC_NAME),                                        \
  }

#endif  // HWY_DISPATCH_WORKAROUND

#define HWY_DYNAMIC_DISPATCH(FUNC_NAME) \
  (*(HWY_DISPATCH_TABLE(FUNC_NAME)[hwy::GetChosenTarget().GetIndex()]))
#define HWY_DYNAMIC_POINTER(FUNC_NAME) \
  (HWY_DISPATCH_TABLE(FUNC_NAME)[hwy::GetChosenTarget().GetIndex()])

#endif  // HWY_IDE || ((HWY_TARGETS & (HWY_TARGETS - 1)) == 0)

// DEPRECATED names; please use HWY_HAVE_* instead.
#define HWY_CAP_INTEGER64 HWY_HAVE_INTEGER64
#define HWY_CAP_FLOAT16 HWY_HAVE_FLOAT16
#define HWY_CAP_FLOAT64 HWY_HAVE_FLOAT64

}  // namespace hwy

#endif  // HWY_HIGHWAY_INCLUDED

//------------------------------------------------------------------------------

// NOTE: the following definitions and ops/*.h depend on HWY_TARGET, so we want
// to include them once per target, which is ensured by the toggle check.
// Because ops/*.h are included under it, they do not need their own guard.
#if defined(HWY_HIGHWAY_PER_TARGET) == defined(HWY_TARGET_TOGGLE)
#ifdef HWY_HIGHWAY_PER_TARGET
#undef HWY_HIGHWAY_PER_TARGET
#else
#define HWY_HIGHWAY_PER_TARGET
#endif

// These define ops inside namespace hwy::HWY_NAMESPACE.
#if HWY_TARGET == HWY_SSE2 || HWY_TARGET == HWY_SSSE3 || HWY_TARGET == HWY_SSE4
#include "hwy/ops/x86_128-inl.h"
#elif HWY_TARGET == HWY_AVX2
#include "hwy/ops/x86_256-inl.h"
#elif HWY_TARGET == HWY_AVX3 || HWY_TARGET == HWY_AVX3_DL || \
    HWY_TARGET == HWY_AVX3_ZEN4 || HWY_TARGET == HWY_AVX3_SPR
#include "hwy/ops/x86_512-inl.h"
#elif HWY_TARGET == HWY_PPC8 || HWY_TARGET == HWY_PPC9 || \
    HWY_TARGET == HWY_PPC10
#include "hwy/ops/ppc_vsx-inl.h"
#elif HWY_TARGET == HWY_NEON || HWY_TARGET == HWY_NEON_WITHOUT_AES
#include "hwy/ops/arm_neon-inl.h"
#elif HWY_TARGET == HWY_SVE || HWY_TARGET == HWY_SVE2 || \
    HWY_TARGET == HWY_SVE_256 || HWY_TARGET == HWY_SVE2_128
#include "hwy/ops/arm_sve-inl.h"
#elif HWY_TARGET == HWY_WASM_EMU256
#include "hwy/ops/wasm_256-inl.h"
#elif HWY_TARGET == HWY_WASM
#include "hwy/ops/wasm_128-inl.h"
#elif HWY_TARGET == HWY_RVV
#include "hwy/ops/rvv-inl.h"
#elif HWY_TARGET == HWY_EMU128

// Copyright 2022 Google LLC
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Single-element vectors and operations.
// External include guard in highway.h - see comment there.

#include <cmath>  // std::abs, std::isnan

#include "hwy/ops/shared-inl.h"

HWY_BEFORE_NAMESPACE();
namespace hwy {
namespace HWY_NAMESPACE {

template <typename T>
using Full128 = Simd<T, 16 / sizeof(T), 0>;

// (Wrapper class required for overloading comparison operators.)
template <typename T, size_t N = 16 / sizeof(T)>
struct Vec128 {
  using PrivateT = T;                     // only for DFromV
  static constexpr size_t kPrivateN = N;  // only for DFromV

  HWY_INLINE Vec128() = default;
  Vec128(const Vec128&) = default;
  Vec128& operator=(const Vec128&) = default;

  HWY_INLINE Vec128& operator*=(const Vec128 other) {
    return *this = (*this * other);
  }
  HWY_INLINE Vec128& operator/=(const Vec128 other) {
    return *this = (*this / other);
  }
  HWY_INLINE Vec128& operator+=(const Vec128 other) {
    return *this = (*this + other);
  }
  HWY_INLINE Vec128& operator-=(const Vec128 other) {
    return *this = (*this - other);
  }
  HWY_INLINE Vec128& operator&=(const Vec128 other) {
    return *this = (*this & other);
  }
  HWY_INLINE Vec128& operator|=(const Vec128 other) {
    return *this = (*this | other);
  }
  HWY_INLINE Vec128& operator^=(const Vec128 other) {
    return *this = (*this ^ other);
  }

  // Behave like wasm128 (vectors can always hold 128 bits). generic_ops-inl.h
  // relies on this for LoadInterleaved*. CAVEAT: this method of padding
  // prevents using range for, especially in SumOfLanes, where it would be
  // incorrect. Moving padding to another field would require handling the case
  // where N = 16 / sizeof(T) (i.e. there is no padding), which is also awkward.
  T raw[16 / sizeof(T)] /*= {}*/;
};

// 0 or FF..FF, same size as Vec128.
template <typename T, size_t N = 16 / sizeof(T)>
struct Mask128 {
  using Raw = hwy::MakeUnsigned<T>;
  static HWY_INLINE Raw FromBool(bool b) {
    return b ? static_cast<Raw>(~Raw{0}) : 0;
  }

  // Must match the size of Vec128.
  Raw bits[16 / sizeof(T)] /*= {}*/;
};

template <class V>
using DFromV = Simd<typename V::PrivateT, V::kPrivateN, 0>;

template <class V>
using TFromV = typename V::PrivateT;

// ------------------------------ Zero

// Use HWY_MAX_LANES_D here because VFromD is defined in terms of Zero.
template <class D, HWY_IF_V_SIZE_LE_D(D, 16)>
HWY_API Vec128<TFromD<D>, HWY_MAX_LANES_D(D)> Zero(D /* tag */) {
  Vec128<TFromD<D>, HWY_MAX_LANES_D(D)> v;  // zero-initialized
  return v;
}

template <class D>
using VFromD = decltype(Zero(D()));

// ------------------------------ Tuple (VFromD)
#include "hwy/ops/tuple-inl.h"

// ------------------------------ BitCast

template <class D, class VFrom>
HWY_API VFromD<D> BitCast(D /* tag */, VFrom v) {
  VFromD<D> to;
  CopySameSize(&v, &to);
  return to;
}

// ------------------------------ ResizeBitCast

template <class D, class VFrom>
HWY_API VFromD<D> ResizeBitCast(D d, VFrom v) {
  using DFrom = DFromV<VFrom>;
  using TFrom = TFromD<DFrom>;
  using TTo = TFromD<D>;

  constexpr size_t kFromByteLen = sizeof(TFrom) * HWY_MAX_LANES_D(DFrom);
  constexpr size_t kToByteLen = sizeof(TTo) * HWY_MAX_LANES_D(D);
  constexpr size_t kCopyByteLen = HWY_MIN(kFromByteLen, kToByteLen);

  VFromD<D> to = Zero(d);
  CopyBytes<kCopyByteLen>(&v, &to);
  return to;
}

namespace detail {

// ResizeBitCast on the HWY_EMU128 target has zero-extending semantics if
// VFromD<DTo> is a larger vector than FromV
template <class FromSizeTag, class ToSizeTag, class DTo, class DFrom>
HWY_INLINE VFromD<DTo> ZeroExtendResizeBitCast(FromSizeTag /* from_size_tag */,
                                               ToSizeTag /* to_size_tag */,
                                               DTo d_to, DFrom /* d_from */,
                                               VFromD<DFrom> v) {
  return ResizeBitCast(d_to, v);
}

}  // namespace detail

// ------------------------------ Set
template <class D, typename T2>
HWY_API VFromD<D> Set(D d, const T2 t) {
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    v.raw[i] = static_cast<TFromD<D>>(t);
  }
  return v;
}

// ------------------------------ Undefined
template <class D>
HWY_API VFromD<D> Undefined(D d) {
  return Zero(d);
}

// ------------------------------ Iota

template <class D, typename T = TFromD<D>, typename T2>
HWY_API VFromD<D> Iota(D d, T2 first) {
  VFromD<D> v;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    v.raw[i] =
        AddWithWraparound(hwy::IsFloatTag<T>(), static_cast<T>(first), i);
  }
  return v;
}

// ================================================== LOGICAL

// ------------------------------ Not
template <typename T, size_t N>
HWY_API Vec128<T, N> Not(Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  const RebindToUnsigned<decltype(d)> du;
  using TU = TFromD<decltype(du)>;
  VFromD<decltype(du)> vu = BitCast(du, v);
  for (size_t i = 0; i < N; ++i) {
    vu.raw[i] = static_cast<TU>(~vu.raw[i]);
  }
  return BitCast(d, vu);
}

// ------------------------------ And
template <typename T, size_t N>
HWY_API Vec128<T, N> And(Vec128<T, N> a, Vec128<T, N> b) {
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
HWY_API Vec128<T, N> operator&(Vec128<T, N> a, Vec128<T, N> b) {
  return And(a, b);
}

// ------------------------------ AndNot
template <typename T, size_t N>
HWY_API Vec128<T, N> AndNot(Vec128<T, N> a, Vec128<T, N> b) {
  return And(Not(a), b);
}

// ------------------------------ Or
template <typename T, size_t N>
HWY_API Vec128<T, N> Or(Vec128<T, N> a, Vec128<T, N> b) {
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
HWY_API Vec128<T, N> operator|(Vec128<T, N> a, Vec128<T, N> b) {
  return Or(a, b);
}

// ------------------------------ Xor
template <typename T, size_t N>
HWY_API Vec128<T, N> Xor(Vec128<T, N> a, Vec128<T, N> b) {
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
HWY_API Vec128<T, N> operator^(Vec128<T, N> a, Vec128<T, N> b) {
  return Xor(a, b);
}

// ------------------------------ Xor3
template <typename T, size_t N>
HWY_API Vec128<T, N> Xor3(Vec128<T, N> x1, Vec128<T, N> x2, Vec128<T, N> x3) {
  return Xor(x1, Xor(x2, x3));
}

// ------------------------------ Or3
template <typename T, size_t N>
HWY_API Vec128<T, N> Or3(Vec128<T, N> o1, Vec128<T, N> o2, Vec128<T, N> o3) {
  return Or(o1, Or(o2, o3));
}

// ------------------------------ OrAnd
template <typename T, size_t N>
HWY_API Vec128<T, N> OrAnd(Vec128<T, N> o, Vec128<T, N> a1, Vec128<T, N> a2) {
  return Or(o, And(a1, a2));
}

// ------------------------------ IfVecThenElse
template <typename T, size_t N>
HWY_API Vec128<T, N> IfVecThenElse(Vec128<T, N> mask, Vec128<T, N> yes,
                                   Vec128<T, N> no) {
  return Or(And(mask, yes), AndNot(mask, no));
}

// ------------------------------ CopySign
template <typename T, size_t N>
HWY_API Vec128<T, N> CopySign(Vec128<T, N> magn, Vec128<T, N> sign) {
  static_assert(IsFloat<T>(), "Only makes sense for floating-point");
  const DFromV<decltype(magn)> d;
  return BitwiseIfThenElse(SignBit(d), sign, magn);
}

// ------------------------------ CopySignToAbs
template <typename T, size_t N>
HWY_API Vec128<T, N> CopySignToAbs(Vec128<T, N> abs, Vec128<T, N> sign) {
  static_assert(IsFloat<T>(), "Only makes sense for floating-point");
  const DFromV<decltype(abs)> d;
  return OrAnd(abs, SignBit(d), sign);
}

// ------------------------------ BroadcastSignBit
template <typename T, size_t N>
HWY_API Vec128<T, N> BroadcastSignBit(Vec128<T, N> v) {
  // This is used inside ShiftRight, so we cannot implement in terms of it.
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = v.raw[i] < 0 ? T(-1) : T(0);
  }
  return v;
}

// ------------------------------ Mask

// v must be 0 or FF..FF.
template <typename T, size_t N>
HWY_API Mask128<T, N> MaskFromVec(Vec128<T, N> v) {
  Mask128<T, N> mask;
  CopySameSize(&v, &mask);
  return mask;
}

template <class D>
using MFromD = decltype(MaskFromVec(VFromD<D>()));

template <class DTo, class MFrom>
HWY_API MFromD<DTo> RebindMask(DTo /* tag */, MFrom mask) {
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
VFromD<D> VecFromMask(D /* tag */, MFromD<D> mask) {
  return VecFromMask(mask);
}

template <class D>
HWY_API MFromD<D> FirstN(D d, size_t n) {
  MFromD<D> m;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    m.bits[i] = MFromD<D>::FromBool(i < n);
  }
  return m;
}

// Returns mask ? yes : no.
template <typename T, size_t N>
HWY_API Vec128<T, N> IfThenElse(Mask128<T, N> mask, Vec128<T, N> yes,
                                Vec128<T, N> no) {
  return IfVecThenElse(VecFromMask(mask), yes, no);
}

template <typename T, size_t N>
HWY_API Vec128<T, N> IfThenElseZero(Mask128<T, N> mask, Vec128<T, N> yes) {
  const DFromV<decltype(yes)> d;
  return IfVecThenElse(VecFromMask(mask), yes, Zero(d));
}

template <typename T, size_t N>
HWY_API Vec128<T, N> IfThenZeroElse(Mask128<T, N> mask, Vec128<T, N> no) {
  const DFromV<decltype(no)> d;
  return IfVecThenElse(VecFromMask(mask), Zero(d), no);
}

template <typename T, size_t N>
HWY_API Vec128<T, N> IfNegativeThenElse(Vec128<T, N> v, Vec128<T, N> yes,
                                        Vec128<T, N> no) {
  const DFromV<decltype(v)> d;
  const RebindToSigned<decltype(d)> di;
  const auto vi = BitCast(di, v);

  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = vi.raw[i] < 0 ? yes.raw[i] : no.raw[i];
  }
  return v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> ZeroIfNegative(Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return IfNegativeThenElse(v, Zero(d), v);
}

// ------------------------------ Mask logical

template <typename T, size_t N>
HWY_API Mask128<T, N> Not(Mask128<T, N> m) {
  return MaskFromVec(Not(VecFromMask(Simd<T, N, 0>(), m)));
}

template <typename T, size_t N>
HWY_API Mask128<T, N> And(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(And(VecFromMask(d, a), VecFromMask(d, b)));
}

template <typename T, size_t N>
HWY_API Mask128<T, N> AndNot(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(AndNot(VecFromMask(d, a), VecFromMask(d, b)));
}

template <typename T, size_t N>
HWY_API Mask128<T, N> Or(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(Or(VecFromMask(d, a), VecFromMask(d, b)));
}

template <typename T, size_t N>
HWY_API Mask128<T, N> Xor(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(Xor(VecFromMask(d, a), VecFromMask(d, b)));
}

template <typename T, size_t N>
HWY_API Mask128<T, N> ExclusiveNeither(Mask128<T, N> a, Mask128<T, N> b) {
  const Simd<T, N, 0> d;
  return MaskFromVec(AndNot(VecFromMask(d, a), Not(VecFromMask(d, b))));
}

// ================================================== SHIFTS

// ------------------------------ ShiftLeft/ShiftRight (BroadcastSignBit)

template <int kBits, typename T, size_t N>
HWY_API Vec128<T, N> ShiftLeft(Vec128<T, N> v) {
  static_assert(0 <= kBits && kBits < sizeof(T) * 8, "Invalid shift");
  using TU = hwy::MakeUnsigned<T>;
  for (size_t i = 0; i < N; ++i) {
    const TU raw_u = static_cast<TU>(v.raw[i]);
    const auto shifted = raw_u << kBits;  // separate line to avoid MSVC warning
    v.raw[i] = static_cast<T>(shifted);
  }
  return v;
}

template <int kBits, typename T, size_t N>
HWY_API Vec128<T, N> ShiftRight(Vec128<T, N> v) {
  static_assert(0 <= kBits && kBits < sizeof(T) * 8, "Invalid shift");
#if __cplusplus >= 202002L
  // Signed right shift is now guaranteed to be arithmetic (rounding toward
  // negative infinity, i.e. shifting in the sign bit).
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = static_cast<T>(v.raw[i] >> kBits);
  }
#else
  if (IsSigned<T>()) {
    // Emulate arithmetic shift using only logical (unsigned) shifts, because
    // signed shifts are still implementation-defined.
    using TU = hwy::MakeUnsigned<T>;
    for (size_t i = 0; i < N; ++i) {
      const TU shifted = static_cast<TU>(static_cast<TU>(v.raw[i]) >> kBits);
      const TU sign = v.raw[i] < 0 ? static_cast<TU>(~TU{0}) : 0;
      const size_t sign_shift =
          static_cast<size_t>(static_cast<int>(sizeof(TU)) * 8 - 1 - kBits);
      const TU upper = static_cast<TU>(sign << sign_shift);
      v.raw[i] = static_cast<T>(shifted | upper);
    }
  } else {  // T is unsigned
    for (size_t i = 0; i < N; ++i) {
      v.raw[i] = static_cast<T>(v.raw[i] >> kBits);
    }
  }
#endif
  return v;
}

// ------------------------------ RotateRight (ShiftRight)
template <int kBits, typename T, size_t N>
HWY_API Vec128<T, N> RotateRight(const Vec128<T, N> v) {
  constexpr size_t kSizeInBits = sizeof(T) * 8;
  static_assert(0 <= kBits && kBits < kSizeInBits, "Invalid shift count");
  if (kBits == 0) return v;
  return Or(ShiftRight<kBits>(v),
            ShiftLeft<HWY_MIN(kSizeInBits - 1, kSizeInBits - kBits)>(v));
}

// ------------------------------ ShiftLeftSame

template <typename T, size_t N>
HWY_API Vec128<T, N> ShiftLeftSame(Vec128<T, N> v, int bits) {
  for (size_t i = 0; i < N; ++i) {
    const auto shifted = static_cast<hwy::MakeUnsigned<T>>(v.raw[i]) << bits;
    v.raw[i] = static_cast<T>(shifted);
  }
  return v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> ShiftRightSame(Vec128<T, N> v, int bits) {
#if __cplusplus >= 202002L
  // Signed right shift is now guaranteed to be arithmetic (rounding toward
  // negative infinity, i.e. shifting in the sign bit).
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = static_cast<T>(v.raw[i] >> bits);
  }
#else
  if (IsSigned<T>()) {
    // Emulate arithmetic shift using only logical (unsigned) shifts, because
    // signed shifts are still implementation-defined.
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
      v.raw[i] = static_cast<T>(v.raw[i] >> bits);  // unsigned, logical shift
    }
  }
#endif
  return v;
}

// ------------------------------ Shl

template <typename T, size_t N>
HWY_API Vec128<T, N> operator<<(Vec128<T, N> v, Vec128<T, N> bits) {
  for (size_t i = 0; i < N; ++i) {
    const auto shifted = static_cast<hwy::MakeUnsigned<T>>(v.raw[i])
                         << bits.raw[i];
    v.raw[i] = static_cast<T>(shifted);
  }
  return v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> operator>>(Vec128<T, N> v, Vec128<T, N> bits) {
#if __cplusplus >= 202002L
  // Signed right shift is now guaranteed to be arithmetic (rounding toward
  // negative infinity, i.e. shifting in the sign bit).
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = static_cast<T>(v.raw[i] >> bits.raw[i]);
  }
#else
  if (IsSigned<T>()) {
    // Emulate arithmetic shift using only logical (unsigned) shifts, because
    // signed shifts are still implementation-defined.
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
  } else {  // T is unsigned
    for (size_t i = 0; i < N; ++i) {
      v.raw[i] = static_cast<T>(v.raw[i] >> bits.raw[i]);
    }
  }
#endif
  return v;
}

// ================================================== ARITHMETIC

// Tag dispatch instead of SFINAE for MSVC 2017 compatibility
namespace detail {

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Add(hwy::NonFloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    const uint64_t a64 = static_cast<uint64_t>(a.raw[i]);
    const uint64_t b64 = static_cast<uint64_t>(b.raw[i]);
    a.raw[i] = static_cast<T>((a64 + b64) & static_cast<uint64_t>(~T(0)));
  }
  return a;
}
template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Sub(hwy::NonFloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    const uint64_t a64 = static_cast<uint64_t>(a.raw[i]);
    const uint64_t b64 = static_cast<uint64_t>(b.raw[i]);
    a.raw[i] = static_cast<T>((a64 - b64) & static_cast<uint64_t>(~T(0)));
  }
  return a;
}

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Add(hwy::FloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] += b.raw[i];
  }
  return a;
}

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Sub(hwy::FloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] -= b.raw[i];
  }
  return a;
}

}  // namespace detail

template <typename T, size_t N>
HWY_API Vec128<T, N> operator-(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Sub(hwy::IsFloatTag<T>(), a, b);
}
template <typename T, size_t N>
HWY_API Vec128<T, N> operator+(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Add(hwy::IsFloatTag<T>(), a, b);
}

// ------------------------------ SumsOf8

template <size_t N>
HWY_API Vec128<uint64_t, (N + 7) / 8> SumsOf8(Vec128<uint8_t, N> v) {
  Vec128<uint64_t, (N + 7) / 8> sums;
  for (size_t i = 0; i < N; ++i) {
    sums.raw[i / 8] += v.raw[i];
  }
  return sums;
}

// ------------------------------ SaturatedAdd
template <typename T, size_t N, HWY_IF_T_SIZE_ONE_OF(T, (1 << 1) | (1 << 2)),
          HWY_IF_NOT_FLOAT_NOR_SPECIAL(T)>
HWY_API Vec128<T, N> SaturatedAdd(Vec128<T, N> a, Vec128<T, N> b) {
  using TW = MakeSigned<MakeWide<T>>;
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(HWY_MIN(
        HWY_MAX(hwy::LowestValue<T>(), static_cast<TW>(a.raw[i]) + b.raw[i]),
        hwy::HighestValue<T>()));
  }
  return a;
}

// ------------------------------ SaturatedSub
template <typename T, size_t N, HWY_IF_T_SIZE_ONE_OF(T, (1 << 1) | (1 << 2)),
          HWY_IF_NOT_FLOAT_NOR_SPECIAL(T)>
HWY_API Vec128<T, N> SaturatedSub(Vec128<T, N> a, Vec128<T, N> b) {
  using TW = MakeSigned<MakeWide<T>>;
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(HWY_MIN(
        HWY_MAX(hwy::LowestValue<T>(), static_cast<TW>(a.raw[i]) - b.raw[i]),
        hwy::HighestValue<T>()));
  }
  return a;
}

// ------------------------------ AverageRound
template <typename T, size_t N>
HWY_API Vec128<T, N> AverageRound(Vec128<T, N> a, Vec128<T, N> b) {
  static_assert(!IsSigned<T>(), "Only for unsigned");
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>((a.raw[i] + b.raw[i] + 1) / 2);
  }
  return a;
}

// ------------------------------ Abs

// Tag dispatch instead of SFINAE for MSVC 2017 compatibility
namespace detail {

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Abs(SignedTag /*tag*/, Vec128<T, N> a) {
  for (size_t i = 0; i < N; ++i) {
    const T s = a.raw[i];
    const T min = hwy::LimitsMin<T>();
    a.raw[i] = static_cast<T>((s >= 0 || s == min) ? a.raw[i] : -s);
  }
  return a;
}

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Abs(hwy::FloatTag /*tag*/, Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = std::abs(v.raw[i]);
  }
  return v;
}

}  // namespace detail

template <typename T, size_t N>
HWY_API Vec128<T, N> Abs(Vec128<T, N> a) {
  return detail::Abs(hwy::TypeTag<T>(), a);
}

// ------------------------------ Min/Max

// Tag dispatch instead of SFINAE for MSVC 2017 compatibility
namespace detail {

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Min(hwy::NonFloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = HWY_MIN(a.raw[i], b.raw[i]);
  }
  return a;
}
template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Max(hwy::NonFloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = HWY_MAX(a.raw[i], b.raw[i]);
  }
  return a;
}

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Min(hwy::FloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    if (std::isnan(a.raw[i])) {
      a.raw[i] = b.raw[i];
    } else if (std::isnan(b.raw[i])) {
      // no change
    } else {
      a.raw[i] = HWY_MIN(a.raw[i], b.raw[i]);
    }
  }
  return a;
}
template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Max(hwy::FloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    if (std::isnan(a.raw[i])) {
      a.raw[i] = b.raw[i];
    } else if (std::isnan(b.raw[i])) {
      // no change
    } else {
      a.raw[i] = HWY_MAX(a.raw[i], b.raw[i]);
    }
  }
  return a;
}

}  // namespace detail

template <typename T, size_t N>
HWY_API Vec128<T, N> Min(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Min(hwy::IsFloatTag<T>(), a, b);
}

template <typename T, size_t N>
HWY_API Vec128<T, N> Max(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Max(hwy::IsFloatTag<T>(), a, b);
}

// ------------------------------ Neg

// Tag dispatch instead of SFINAE for MSVC 2017 compatibility
namespace detail {

template <typename T, size_t N>
HWY_API Vec128<T, N> Neg(hwy::NonFloatTag /*tag*/, Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return Zero(d) - v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> Neg(hwy::FloatTag /*tag*/, Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return Xor(v, SignBit(d));
}

template <typename T, size_t N>
HWY_API Vec128<T, N> Neg(hwy::SpecialTag /*tag*/, Vec128<T, N> v) {
  const DFromV<decltype(v)> d;
  return Xor(v, SignBit(d));
}

}  // namespace detail

template <typename T, size_t N>
HWY_API Vec128<T, N> Neg(Vec128<T, N> v) {
  return detail::Neg(hwy::IsFloatTag<T>(), v);
}

// ------------------------------ Mul/Div

// Tag dispatch instead of SFINAE for MSVC 2017 compatibility
namespace detail {

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Mul(hwy::FloatTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] *= b.raw[i];
  }
  return a;
}

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Mul(SignedTag /*tag*/, Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(static_cast<uint64_t>(a.raw[i]) *
                              static_cast<uint64_t>(b.raw[i]));
  }
  return a;
}

template <typename T, size_t N>
HWY_INLINE Vec128<T, N> Mul(UnsignedTag /*tag*/, Vec128<T, N> a,
                            Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<T>(static_cast<uint64_t>(a.raw[i]) *
                              static_cast<uint64_t>(b.raw[i]));
  }
  return a;
}

}  // namespace detail

// Per-target flags to prevent generic_ops-inl.h defining 8/64-bit operator*.
#ifdef HWY_NATIVE_MUL_8
#undef HWY_NATIVE_MUL_8
#else
#define HWY_NATIVE_MUL_8
#endif
#ifdef HWY_NATIVE_MUL_64
#undef HWY_NATIVE_MUL_64
#else
#define HWY_NATIVE_MUL_64
#endif

template <typename T, size_t N>
HWY_API Vec128<T, N> operator*(Vec128<T, N> a, Vec128<T, N> b) {
  return detail::Mul(hwy::TypeTag<T>(), a, b);
}

template <typename T, size_t N>
HWY_API Vec128<T, N> operator/(Vec128<T, N> a, Vec128<T, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = (b.raw[i] == T{0}) ? 0 : a.raw[i] / b.raw[i];
  }
  return a;
}

// Returns the upper 16 bits of a * b in each lane.
template <size_t N>
HWY_API Vec128<int16_t, N> MulHigh(Vec128<int16_t, N> a, Vec128<int16_t, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<int16_t>((int32_t{a.raw[i]} * b.raw[i]) >> 16);
  }
  return a;
}
template <size_t N>
HWY_API Vec128<uint16_t, N> MulHigh(Vec128<uint16_t, N> a,
                                    Vec128<uint16_t, N> b) {
  for (size_t i = 0; i < N; ++i) {
    // Cast to uint32_t first to prevent overflow. Otherwise the result of
    // uint16_t * uint16_t is in "int" which may overflow. In practice the
    // result is the same but this way it is also defined.
    a.raw[i] = static_cast<uint16_t>(
        (static_cast<uint32_t>(a.raw[i]) * static_cast<uint32_t>(b.raw[i])) >>
        16);
  }
  return a;
}

template <size_t N>
HWY_API Vec128<int16_t, N> MulFixedPoint15(Vec128<int16_t, N> a,
                                           Vec128<int16_t, N> b) {
  for (size_t i = 0; i < N; ++i) {
    a.raw[i] = static_cast<int16_t>((a.raw[i] * b.raw[i] + 16384) >> 15);
  }
  return a;
}

// Multiplies even lanes (0, 2, ..) and returns the double-wide result.
template <class T, size_t N,
          HWY_IF_T_SIZE_ONE_OF(T, (1 << 1) | (1 << 2) | (1 << 4)),
          HWY_IF_NOT_FLOAT_NOR_SPECIAL(T)>
HWY_API Vec128<MakeWide<T>, (N + 1) / 2> MulEven(Vec128<T, N> a,
                                                 Vec128<T, N> b) {
  using TW = MakeWide<T>;
  Vec128<TW, (N + 1) / 2> mul;
  for (size_t i = 0; i < N; i += 2) {
    const TW a_wide = a.raw[i];
    mul.raw[i / 2] = static_cast<TW>(a_wide * b.raw[i]);
  }
  return mul;
}

// Multiplies odd lanes (1, 3, ..) and returns the double-wide result.
template <class T, size_t N,
          HWY_IF_T_SIZE_ONE_OF(T, (1 << 1) | (1 << 2) | (1 << 4)),
          HWY_IF_NOT_FLOAT_NOR_SPECIAL(T)>
HWY_API Vec128<MakeWide<T>, (N + 1) / 2> MulOdd(Vec128<T, N> a,
                                                Vec128<T, N> b) {
  using TW = MakeWide<T>;
  Vec128<TW, (N + 1) / 2> mul;
  for (size_t i = 0; i < N; i += 2) {
    const TW a_wide = a.raw[i + 1];
    mul.raw[i / 2] = static_cast<TW>(a_wide * b.raw[i + 1]);
  }
  return mul;
}

template <size_t N>
HWY_API Vec128<float, N> ApproximateReciprocal(Vec128<float, N> v) {
  for (size_t i = 0; i < N; ++i) {
    // Zero inputs are allowed, but callers are responsible for replacing the
    // return value with something else (typically using IfThenElse). This check
    // avoids a ubsan error. The result is arbitrary.
    v.raw[i] = (std::abs(v.raw[i]) == 0.0f) ? 0.0f : 1.0f / v.raw[i];
  }
  return v;
}

// generic_ops takes care of integer T.
template <typename T, size_t N, HWY_IF_FLOAT(T)>
HWY_API Vec128<T, N> AbsDiff(Vec128<T, N> a, Vec128<T, N> b) {
  return Abs(a - b);
}

// ------------------------------ Floating-point multiply-add variants

template <typename T, size_t N>
HWY_API Vec128<T, N> MulAdd(Vec128<T, N> mul, Vec128<T, N> x,
                            Vec128<T, N> add) {
  return mul * x + add;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> NegMulAdd(Vec128<T, N> mul, Vec128<T, N> x,
                               Vec128<T, N> add) {
  return add - mul * x;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> MulSub(Vec128<T, N> mul, Vec128<T, N> x,
                            Vec128<T, N> sub) {
  return mul * x - sub;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> NegMulSub(Vec128<T, N> mul, Vec128<T, N> x,
                               Vec128<T, N> sub) {
  return Neg(mul) * x - sub;
}

// ------------------------------ Floating-point square root

template <size_t N>
HWY_API Vec128<float, N> ApproximateReciprocalSqrt(Vec128<float, N> v) {
  for (size_t i = 0; i < N; ++i) {
    const float half = v.raw[i] * 0.5f;
    uint32_t bits;
    CopySameSize(&v.raw[i], &bits);
    // Initial guess based on log2(f)
    bits = 0x5F3759DF - (bits >> 1);
    CopySameSize(&bits, &v.raw[i]);
    // One Newton-Raphson iteration
    v.raw[i] = v.raw[i] * (1.5f - (half * v.raw[i] * v.raw[i]));
  }
  return v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> Sqrt(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = std::sqrt(v.raw[i]);
  }
  return v;
}

// ------------------------------ Floating-point rounding

template <typename T, size_t N>
HWY_API Vec128<T, N> Round(Vec128<T, N> v) {
  using TI = MakeSigned<T>;
  const Vec128<T, N> a = Abs(v);
  for (size_t i = 0; i < N; ++i) {
    if (!(a.raw[i] < MantissaEnd<T>())) {  // Huge or NaN
      continue;
    }
    const T bias = v.raw[i] < T(0.0) ? T(-0.5) : T(0.5);
    const TI rounded = static_cast<TI>(v.raw[i] + bias);
    if (rounded == 0) {
      v.raw[i] = v.raw[i] < 0 ? T{-0} : T{0};
      continue;
    }
    const T rounded_f = static_cast<T>(rounded);
    // Round to even
    if ((rounded & 1) && std::abs(rounded_f - v.raw[i]) == T(0.5)) {
      v.raw[i] = static_cast<T>(rounded - (v.raw[i] < T(0) ? -1 : 1));
      continue;
    }
    v.raw[i] = rounded_f;
  }
  return v;
}

// Round-to-nearest even.
template <size_t N>
HWY_API Vec128<int32_t, N> NearestInt(Vec128<float, N> v) {
  using T = float;
  using TI = int32_t;

  const Vec128<float, N> abs = Abs(v);
  Vec128<int32_t, N> ret;
  for (size_t i = 0; i < N; ++i) {
    const bool signbit = std::signbit(v.raw[i]);

    if (!(abs.raw[i] < MantissaEnd<T>())) {  // Huge or NaN
      // Check if too large to cast or NaN
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
    // Round to even
    if ((rounded & 1) && std::abs(rounded_f - v.raw[i]) == T(0.5)) {
      ret.raw[i] = rounded - (signbit ? -1 : 1);
      continue;
    }
    ret.raw[i] = rounded;
  }
  return ret;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> Trunc(Vec128<T, N> v) {
  using TI = MakeSigned<T>;
  const Vec128<T, N> abs = Abs(v);
  for (size_t i = 0; i < N; ++i) {
    if (!(abs.raw[i] <= MantissaEnd<T>())) {  // Huge or NaN
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

// Toward +infinity, aka ceiling
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
    // Already an integer.
    if (exponent >= kMantissaBits) continue;
    // |v| <= 1 => 0 or 1.
    if (exponent < 0) {
      v.raw[i] = positive ? Float{1} : Float{-0.0};
      continue;
    }

    const Bits mantissa_mask = kMantissaMask >> exponent;
    // Already an integer
    if ((bits & mantissa_mask) == 0) continue;

    // Clear fractional bits and round up
    if (positive) bits += (kMantissaMask + 1) >> exponent;
    bits &= ~mantissa_mask;

    CopySameSize(&bits, &v.raw[i]);
  }
  return v;
}

// Toward -infinity, aka floor
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
    // Already an integer.
    if (exponent >= kMantissaBits) continue;
    // |v| <= 1 => -1 or 0.
    if (exponent < 0) {
      v.raw[i] = negative ? Float(-1.0) : Float(0.0);
      continue;
    }

    const Bits mantissa_mask = kMantissaMask >> exponent;
    // Already an integer
    if ((bits & mantissa_mask) == 0) continue;

    // Clear fractional bits and round down
    if (negative) bits += (kMantissaMask + 1) >> exponent;
    bits &= ~mantissa_mask;

    CopySameSize(&bits, &v.raw[i]);
  }
  return v;
}

// ------------------------------ Floating-point classification

template <typename T, size_t N>
HWY_API Mask128<T, N> IsNaN(Vec128<T, N> v) {
  Mask128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    // std::isnan returns false for 0x7F..FF in clang AVX3 builds, so DIY.
    MakeUnsigned<T> bits;
    CopySameSize(&v.raw[i], &bits);
    bits += bits;
    bits >>= 1;  // clear sign bit
    // NaN if all exponent bits are set and the mantissa is not zero.
    ret.bits[i] = Mask128<T, N>::FromBool(bits > ExponentMask<T>());
  }
  return ret;
}

template <typename T, size_t N>
HWY_API Mask128<T, N> IsInf(Vec128<T, N> v) {
  static_assert(IsFloat<T>(), "Only for float");
  const DFromV<decltype(v)> d;
  const RebindToSigned<decltype(d)> di;
  const VFromD<decltype(di)> vi = BitCast(di, v);
  // 'Shift left' to clear the sign bit, check for exponent=max and mantissa=0.
  return RebindMask(d, Eq(Add(vi, vi), Set(di, hwy::MaxExponentTimes2<T>())));
}

// Returns whether normal/subnormal/zero.
template <typename T, size_t N>
HWY_API Mask128<T, N> IsFinite(Vec128<T, N> v) {
  static_assert(IsFloat<T>(), "Only for float");
  const DFromV<decltype(v)> d;
  const RebindToUnsigned<decltype(d)> du;
  const RebindToSigned<decltype(d)> di;  // cheaper than unsigned comparison
  using VI = VFromD<decltype(di)>;
  using VU = VFromD<decltype(du)>;
  const VU vu = BitCast(du, v);
  // 'Shift left' to clear the sign bit, then right so we can compare with the
  // max exponent (cannot compare with MaxExponentTimes2 directly because it is
  // negative and non-negative floats would be greater).
  const VI exp =
      BitCast(di, ShiftRight<hwy::MantissaBits<T>() + 1>(Add(vu, vu)));
  return RebindMask(d, Lt(exp, Set(di, hwy::MaxExponentField<T>())));
}

// ================================================== COMPARE

template <typename T, size_t N>
HWY_API Mask128<T, N> operator==(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] == b.raw[i]);
  }
  return m;
}

template <typename T, size_t N>
HWY_API Mask128<T, N> operator!=(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] != b.raw[i]);
  }
  return m;
}

template <typename T, size_t N>
HWY_API Mask128<T, N> TestBit(Vec128<T, N> v, Vec128<T, N> bit) {
  static_assert(!hwy::IsFloat<T>(), "Only integer vectors supported");
  return (v & bit) == bit;
}

template <typename T, size_t N>
HWY_API Mask128<T, N> operator<(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] < b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
HWY_API Mask128<T, N> operator>(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] > b.raw[i]);
  }
  return m;
}

template <typename T, size_t N>
HWY_API Mask128<T, N> operator<=(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] <= b.raw[i]);
  }
  return m;
}
template <typename T, size_t N>
HWY_API Mask128<T, N> operator>=(Vec128<T, N> a, Vec128<T, N> b) {
  Mask128<T, N> m;
  for (size_t i = 0; i < N; ++i) {
    m.bits[i] = Mask128<T, N>::FromBool(a.raw[i] >= b.raw[i]);
  }
  return m;
}

// ------------------------------ Lt128

// Only makes sense for full vectors of u64.
template <class D>
HWY_API MFromD<D> Lt128(D /* tag */, Vec128<uint64_t> a, Vec128<uint64_t> b) {
  const bool lt =
      (a.raw[1] < b.raw[1]) || (a.raw[1] == b.raw[1] && a.raw[0] < b.raw[0]);
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(lt);
  return ret;
}

template <class D>
HWY_API MFromD<D> Lt128Upper(D /* tag */, Vec128<uint64_t> a,
                             Vec128<uint64_t> b) {
  const bool lt = a.raw[1] < b.raw[1];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(lt);
  return ret;
}

// ------------------------------ Eq128

// Only makes sense for full vectors of u64.
template <class D>
HWY_API MFromD<D> Eq128(D /* tag */, Vec128<uint64_t> a, Vec128<uint64_t> b) {
  const bool eq = a.raw[1] == b.raw[1] && a.raw[0] == b.raw[0];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(eq);
  return ret;
}

template <class D>
HWY_API Mask128<uint64_t> Ne128(D /* tag */, Vec128<uint64_t> a,
                                Vec128<uint64_t> b) {
  const bool ne = a.raw[1] != b.raw[1] || a.raw[0] != b.raw[0];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(ne);
  return ret;
}

template <class D>
HWY_API MFromD<D> Eq128Upper(D /* tag */, Vec128<uint64_t> a,
                             Vec128<uint64_t> b) {
  const bool eq = a.raw[1] == b.raw[1];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(eq);
  return ret;
}

template <class D>
HWY_API MFromD<D> Ne128Upper(D /* tag */, Vec128<uint64_t> a,
                             Vec128<uint64_t> b) {
  const bool ne = a.raw[1] != b.raw[1];
  Mask128<uint64_t> ret;
  ret.bits[0] = ret.bits[1] = Mask128<uint64_t>::FromBool(ne);
  return ret;
}

// ------------------------------ Min128, Max128 (Lt128)

template <class D>
HWY_API VFromD<D> Min128(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128(d, a, b), a, b);
}

template <class D>
HWY_API VFromD<D> Max128(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128(d, b, a), a, b);
}

template <class D>
HWY_API VFromD<D> Min128Upper(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128Upper(d, a, b), a, b);
}

template <class D>
HWY_API VFromD<D> Max128Upper(D d, VFromD<D> a, VFromD<D> b) {
  return IfThenElse(Lt128Upper(d, b, a), a, b);
}

// ================================================== MEMORY

// ------------------------------ Load

template <class D>
HWY_API VFromD<D> Load(D d, const TFromD<D>* HWY_RESTRICT aligned) {
  VFromD<D> v;
  CopyBytes<d.MaxBytes()>(aligned, v.raw);  // copy from array
  return v;
}

template <class D>
HWY_API VFromD<D> MaskedLoad(MFromD<D> m, D d,
                             const TFromD<D>* HWY_RESTRICT p) {
  return IfThenElseZero(m, LoadU(d, p));
}

template <class D>
HWY_API VFromD<D> MaskedLoadOr(VFromD<D> v, MFromD<D> m, D d,
                               const TFromD<D>* HWY_RESTRICT p) {
  return IfThenElse(m, LoadU(d, p), v);
}

template <class D>
HWY_API VFromD<D> LoadU(D d, const TFromD<D>* HWY_RESTRICT p) {
  return Load(d, p);
}

// In some use cases, "load single lane" is sufficient; otherwise avoid this.
template <class D>
HWY_API VFromD<D> LoadDup128(D d, const TFromD<D>* HWY_RESTRICT aligned) {
  return Load(d, aligned);
}

#ifdef HWY_NATIVE_LOAD_N
#undef HWY_NATIVE_LOAD_N
#else
#define HWY_NATIVE_LOAD_N
#endif

template <class D>
HWY_API VFromD<D> LoadN(D d, const TFromD<D>* HWY_RESTRICT p,
                        size_t max_lanes_to_load) {
  VFromD<D> v = Zero(d);
  const size_t N = Lanes(d);
  const size_t num_of_lanes_to_load = HWY_MIN(max_lanes_to_load, N);
  CopyBytes(p, v.raw, num_of_lanes_to_load * sizeof(TFromD<D>));
  return v;
}

template <class D>
HWY_API VFromD<D> LoadNOr(VFromD<D> no, D d, const TFromD<D>* HWY_RESTRICT p,
                          size_t max_lanes_to_load) {
  VFromD<D> v = no;
  const size_t N = Lanes(d);
  const size_t num_of_lanes_to_load = HWY_MIN(max_lanes_to_load, N);
  CopyBytes(p, v.raw, num_of_lanes_to_load * sizeof(TFromD<D>));
  return v;
}

// ------------------------------ Store

template <class D>
HWY_API void Store(VFromD<D> v, D d, TFromD<D>* HWY_RESTRICT aligned) {
  CopyBytes<d.MaxBytes()>(v.raw, aligned);  // copy to array
}

template <class D>
HWY_API void StoreU(VFromD<D> v, D d, TFromD<D>* HWY_RESTRICT p) {
  Store(v, d, p);
}

template <class D>
HWY_API void BlendedStore(VFromD<D> v, MFromD<D> m, D d,
                          TFromD<D>* HWY_RESTRICT p) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (m.bits[i]) p[i] = v.raw[i];
  }
}

#ifdef HWY_NATIVE_STORE_N
#undef HWY_NATIVE_STORE_N
#else
#define HWY_NATIVE_STORE_N
#endif

template <class D>
HWY_API void StoreN(VFromD<D> v, D d, TFromD<D>* HWY_RESTRICT p,
                    size_t max_lanes_to_store) {
  const size_t N = Lanes(d);
  const size_t num_of_lanes_to_store = HWY_MIN(max_lanes_to_store, N);
  CopyBytes(v.raw, p, num_of_lanes_to_store * sizeof(TFromD<D>));
}

// ------------------------------ LoadInterleaved2/3/4

// Per-target flag to prevent generic_ops-inl.h from defining LoadInterleaved2.
// We implement those here because scalar code is likely faster than emulation
// via shuffles.
#ifdef HWY_NATIVE_LOAD_STORE_INTERLEAVED
#undef HWY_NATIVE_LOAD_STORE_INTERLEAVED
#else
#define HWY_NATIVE_LOAD_STORE_INTERLEAVED
#endif

template <class D, typename T = TFromD<D>>
HWY_API void LoadInterleaved2(D d, const T* HWY_RESTRICT unaligned,
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
HWY_API void LoadInterleaved3(D d, const T* HWY_RESTRICT unaligned,
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
HWY_API void LoadInterleaved4(D d, const T* HWY_RESTRICT unaligned,
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

// ------------------------------ StoreInterleaved2/3/4

template <class D>
HWY_API void StoreInterleaved2(VFromD<D> v0, VFromD<D> v1, D d,
                               TFromD<D>* HWY_RESTRICT unaligned) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    *unaligned++ = v0.raw[i];
    *unaligned++ = v1.raw[i];
  }
}

template <class D>
HWY_API void StoreInterleaved3(VFromD<D> v0, VFromD<D> v1, VFromD<D> v2, D d,
                               TFromD<D>* HWY_RESTRICT unaligned) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    *unaligned++ = v0.raw[i];
    *unaligned++ = v1.raw[i];
    *unaligned++ = v2.raw[i];
  }
}

template <class D>
HWY_API void StoreInterleaved4(VFromD<D> v0, VFromD<D> v1, VFromD<D> v2,
                               VFromD<D> v3, D d,
                               TFromD<D>* HWY_RESTRICT unaligned) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    *unaligned++ = v0.raw[i];
    *unaligned++ = v1.raw[i];
    *unaligned++ = v2.raw[i];
    *unaligned++ = v3.raw[i];
  }
}

// ------------------------------ Stream
template <class D>
HWY_API void Stream(VFromD<D> v, D d, TFromD<D>* HWY_RESTRICT aligned) {
  Store(v, d, aligned);
}

// ------------------------------ Scatter in generic_ops-inl.h
// ------------------------------ Gather in generic_ops-inl.h

// ================================================== CONVERT

// ConvertTo and DemoteTo with floating-point input and integer output truncate
// (rounding toward zero).

namespace detail {

template <class ToT, class FromT>
HWY_INLINE ToT CastValueForF2IConv(hwy::UnsignedTag /* to_type_tag */,
                                   FromT val) {
  // Prevent ubsan errors when converting float to narrower integer

  // If LimitsMax<ToT>() can be exactly represented in FromT,
  // kSmallestOutOfToTRangePosVal is equal to LimitsMax<ToT>().

  // Otherwise, if LimitsMax<ToT>() cannot be exactly represented in FromT,
  // kSmallestOutOfToTRangePosVal is equal to LimitsMax<ToT>() + 1, which can
  // be exactly represented in FromT.
  constexpr FromT kSmallestOutOfToTRangePosVal =
      (sizeof(ToT) * 8 <= static_cast<size_t>(MantissaBits<FromT>()) + 1)
          ? static_cast<FromT>(LimitsMax<ToT>())
          : static_cast<FromT>(
                static_cast<FromT>(ToT{1} << (sizeof(ToT) * 8 - 1)) * FromT(2));

  if (std::signbit(val)) {
    return ToT{0};
  } else if (std::isinf(val) || val >= kSmallestOutOfToTRangePosVal) {
    return LimitsMax<ToT>();
  } else {
    return static_cast<ToT>(val);
  }
}

template <class ToT, class FromT>
HWY_INLINE ToT CastValueForF2IConv(hwy::SignedTag /* to_type_tag */,
                                   FromT val) {
  // Prevent ubsan errors when converting float to narrower integer

  // If LimitsMax<ToT>() can be exactly represented in FromT,
  // kSmallestOutOfToTRangePosVal is equal to LimitsMax<ToT>().

  // Otherwise, if LimitsMax<ToT>() cannot be exactly represented in FromT,
  // kSmallestOutOfToTRangePosVal is equal to -LimitsMin<ToT>(), which can
  // be exactly represented in FromT.
  constexpr FromT kSmallestOutOfToTRangePosVal =
      (sizeof(ToT) * 8 <= static_cast<size_t>(MantissaBits<FromT>()) + 2)
          ? static_cast<FromT>(LimitsMax<ToT>())
          : static_cast<FromT>(-static_cast<FromT>(LimitsMin<ToT>()));

  if (std::isinf(val) || std::fabs(val) >= kSmallestOutOfToTRangePosVal) {
    return std::signbit(val) ? LimitsMin<ToT>() : LimitsMax<ToT>();
  } else {
    return static_cast<ToT>(val);
  }
}

template <class ToT, class ToTypeTag, class FromT>
HWY_INLINE ToT CastValueForPromoteTo(ToTypeTag /* to_type_tag */, FromT val) {
  return static_cast<ToT>(val);
}

template <class ToT>
HWY_INLINE ToT CastValueForPromoteTo(hwy::SignedTag to_type_tag, float val) {
  return CastValueForF2IConv<ToT>(to_type_tag, val);
}

template <class ToT>
HWY_INLINE ToT CastValueForPromoteTo(hwy::UnsignedTag to_type_tag, float val) {
  return CastValueForF2IConv<ToT>(to_type_tag, val);
}

}  // namespace detail

template <class DTo, typename TFrom, HWY_IF_NOT_SPECIAL_FLOAT(TFrom)>
HWY_API VFromD<DTo> PromoteTo(DTo d, Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  static_assert(sizeof(TFromD<DTo>) > sizeof(TFrom), "Not promoting");
  VFromD<DTo> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    // For bits Y > X, floatX->floatY and intX->intY are always representable.
    ret.raw[i] = detail::CastValueForPromoteTo<TFromD<DTo>>(
        hwy::TypeTag<TFromD<DTo>>(), from.raw[i]);
  }
  return ret;
}

// MSVC 19.10 cannot deduce the argument type if HWY_IF_FLOAT(TFrom) is here,
// so we overload for TFrom=double and ToT={float,int32_t}.
template <class D, HWY_IF_F32_D(D)>
HWY_API VFromD<D> DemoteTo(D d, VFromD<Rebind<double, D>> from) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    // Prevent ubsan errors when converting float to narrower integer/float
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
template <class D, HWY_IF_UI32_D(D)>
HWY_API VFromD<D> DemoteTo(D d, VFromD<Rebind<double, D>> from) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    // Prevent ubsan errors when converting double to narrower integer/int32_t
    ret.raw[i] = detail::CastValueForF2IConv<TFromD<D>>(
        hwy::TypeTag<TFromD<D>>(), from.raw[i]);
  }
  return ret;
}

template <class DTo, typename TFrom, size_t N, HWY_IF_SIGNED(TFrom),
          HWY_IF_NOT_FLOAT_NOR_SPECIAL(TFromD<DTo>)>
HWY_API VFromD<DTo> DemoteTo(DTo /* tag */, Vec128<TFrom, N> from) {
  using TTo = TFromD<DTo>;
  static_assert(sizeof(TTo) < sizeof(TFrom), "Not demoting");

  VFromD<DTo> ret;
  for (size_t i = 0; i < N; ++i) {
    // Int to int: choose closest value in ToT to `from` (avoids UB)
    from.raw[i] =
        HWY_MIN(HWY_MAX(LimitsMin<TTo>(), from.raw[i]), LimitsMax<TTo>());
    ret.raw[i] = static_cast<TTo>(from.raw[i]);
  }
  return ret;
}

template <class DTo, typename TFrom, size_t N, HWY_IF_UNSIGNED(TFrom),
          HWY_IF_UNSIGNED_D(DTo)>
HWY_API VFromD<DTo> DemoteTo(DTo /* tag */, Vec128<TFrom, N> from) {
  using TTo = TFromD<DTo>;
  static_assert(sizeof(TTo) < sizeof(TFrom), "Not demoting");

  VFromD<DTo> ret;
  for (size_t i = 0; i < N; ++i) {
    // Int to int: choose closest value in ToT to `from` (avoids UB)
    from.raw[i] = HWY_MIN(from.raw[i], LimitsMax<TTo>());
    ret.raw[i] = static_cast<TTo>(from.raw[i]);
  }
  return ret;
}

template <class DTo, typename TFrom, size_t N, HWY_IF_UI64(TFrom),
          HWY_IF_F32_D(DTo)>
HWY_API VFromD<DTo> DemoteTo(DTo /* tag */, Vec128<TFrom, N> from) {
  using TTo = TFromD<DTo>;
  static_assert(sizeof(TTo) < sizeof(TFrom), "Not demoting");

  VFromD<DTo> ret;
  for (size_t i = 0; i < N; ++i) {
    // int64_t/uint64_t to float: okay to cast to float as an int64_t/uint64_t
    // value is always within the range of a float
    ret.raw[i] = static_cast<TTo>(from.raw[i]);
  }
  return ret;
}

template <class DBF16, HWY_IF_BF16_D(DBF16), class VF32>
HWY_API VFromD<DBF16> ReorderDemote2To(DBF16 dbf16, VF32 a, VF32 b) {
  const Repartition<uint32_t, decltype(dbf16)> du32;
  const VFromD<decltype(du32)> b_in_lower = ShiftRight<16>(BitCast(du32, b));
  // Avoid OddEven - we want the upper half of `a` even on big-endian systems.
  const VFromD<decltype(du32)> a_mask = Set(du32, 0xFFFF0000);
  return BitCast(dbf16, IfVecThenElse(a_mask, BitCast(du32, a), b_in_lower));
}

template <class DN, HWY_IF_NOT_FLOAT_NOR_SPECIAL(TFromD<DN>), class V,
          HWY_IF_SIGNED_V(V), HWY_IF_T_SIZE_V(V, sizeof(TFromD<DN>) * 2),
          HWY_IF_LANES_D(DN, HWY_MAX_LANES_D(DFromV<V>) * 2)>
HWY_API VFromD<DN> ReorderDemote2To(DN dn, V a, V b) {
  const RepartitionToWide<decltype(dn)> dw;
  const size_t NW = Lanes(dw);
  using TN = TFromD<DN>;
  const TN min = LimitsMin<TN>();
  const TN max = LimitsMax<TN>();
  VFromD<DN> ret;
  for (size_t i = 0; i < NW; ++i) {
    ret.raw[i] = static_cast<TN>(HWY_MIN(HWY_MAX(min, a.raw[i]), max));
  }
  for (size_t i = 0; i < NW; ++i) {
    ret.raw[NW + i] = static_cast<TN>(HWY_MIN(HWY_MAX(min, b.raw[i]), max));
  }
  return ret;
}

template <class DN, HWY_IF_UNSIGNED_D(DN), class V, HWY_IF_UNSIGNED_V(V),
          HWY_IF_T_SIZE_V(V, sizeof(TFromD<DN>) * 2),
          HWY_IF_LANES_D(DN, HWY_MAX_LANES_D(DFromV<V>) * 2)>
HWY_API VFromD<DN> ReorderDemote2To(DN dn, V a, V b) {
  const RepartitionToWide<decltype(dn)> dw;
  const size_t NW = Lanes(dw);
  using TN = TFromD<DN>;
  const TN max = LimitsMax<TN>();
  VFromD<DN> ret;
  for (size_t i = 0; i < NW; ++i) {
    ret.raw[i] = static_cast<TN>(HWY_MIN(a.raw[i], max));
  }
  for (size_t i = 0; i < NW; ++i) {
    ret.raw[NW + i] = static_cast<TN>(HWY_MIN(b.raw[i], max));
  }
  return ret;
}

template <class DN, HWY_IF_NOT_FLOAT_NOR_SPECIAL(TFromD<DN>), class V,
          HWY_IF_NOT_FLOAT_NOR_SPECIAL_V(V),
          HWY_IF_T_SIZE_V(V, sizeof(TFromD<DN>) * 2),
          HWY_IF_LANES_D(DN, HWY_MAX_LANES_D(DFromV<V>) * 2)>
HWY_API VFromD<DN> OrderedDemote2To(DN dn, V a, V b) {
  return ReorderDemote2To(dn, a, b);
}

template <class DN, HWY_IF_BF16_D(DN), class V, HWY_IF_F32_D(DFromV<V>),
          HWY_IF_LANES_D(DN, HWY_MAX_LANES_D(DFromV<V>) * 2)>
HWY_API VFromD<DN> OrderedDemote2To(DN dn, V a, V b) {
  const RebindToUnsigned<DFromV<decltype(a)>> du32;
  const size_t NW = Lanes(du32);
  VFromD<Repartition<uint16_t, DN>> ret;

  const auto a_bits = BitCast(du32, a);
  const auto b_bits = BitCast(du32, b);

  for (size_t i = 0; i < NW; ++i) {
    ret.raw[i] = static_cast<uint16_t>(a_bits.raw[i] >> 16);
  }
  for (size_t i = 0; i < NW; ++i) {
    ret.raw[NW + i] = static_cast<uint16_t>(b_bits.raw[i] >> 16);
  }
  return BitCast(dn, ret);
}

namespace detail {

HWY_INLINE void StoreU16ToF16(const uint16_t val,
                              hwy::float16_t* HWY_RESTRICT to) {
  CopySameSize(&val, to);
}

HWY_INLINE uint16_t U16FromF16(const hwy::float16_t* HWY_RESTRICT from) {
  uint16_t bits16;
  CopySameSize(from, &bits16);
  return bits16;
}

}  // namespace detail

template <class D, HWY_IF_F32_D(D), size_t N>
HWY_API VFromD<D> PromoteTo(D /* tag */, Vec128<bfloat16_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = F32FromBF16(v.raw[i]);
  }
  return ret;
}

template <class D, HWY_IF_BF16_D(D), size_t N>
HWY_API VFromD<D> DemoteTo(D /* tag */, Vec128<float, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = BF16FromF32(v.raw[i]);
  }
  return ret;
}

// Tag dispatch instead of SFINAE for MSVC 2017 compatibility
namespace detail {

template <typename TFrom, typename DTo>
HWY_API VFromD<DTo> ConvertTo(hwy::FloatTag /*tag*/, DTo /*tag*/,
                              Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  using ToT = TFromD<DTo>;
  static_assert(sizeof(ToT) == sizeof(TFrom), "Should have same size");
  VFromD<DTo> ret;
  constexpr size_t N = HWY_MAX_LANES_D(DTo);

  for (size_t i = 0; i < N; ++i) {
    // float## -> int##: return closest representable value
    ret.raw[i] = CastValueForF2IConv<ToT>(hwy::TypeTag<ToT>(), from.raw[i]);
  }
  return ret;
}

template <typename TFrom, typename DTo>
HWY_API VFromD<DTo> ConvertTo(hwy::NonFloatTag /*tag*/, DTo /* tag */,
                              Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  using ToT = TFromD<DTo>;
  static_assert(sizeof(ToT) == sizeof(TFrom), "Should have same size");
  VFromD<DTo> ret;
  constexpr size_t N = HWY_MAX_LANES_D(DTo);
  for (size_t i = 0; i < N; ++i) {
    // int## -> float##: no check needed
    ret.raw[i] = static_cast<ToT>(from.raw[i]);
  }
  return ret;
}

}  // namespace detail

template <class DTo, typename TFrom>
HWY_API VFromD<DTo> ConvertTo(DTo d, Vec128<TFrom, HWY_MAX_LANES_D(DTo)> from) {
  return detail::ConvertTo(hwy::IsFloatTag<TFrom>(), d, from);
}

template <size_t N>
HWY_API Vec128<uint8_t, N> U8FromU32(Vec128<uint32_t, N> v) {
  return DemoteTo(Simd<uint8_t, N, 0>(), v);
}

// ------------------------------ Truncations

template <class D, HWY_IF_U8_D(D), size_t N>
HWY_API VFromD<D> TruncateTo(D /* tag */, Vec128<uint64_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint8_t>(v.raw[i] & 0xFF);
  }
  return ret;
}

template <class D, HWY_IF_U16_D(D), size_t N>
HWY_API VFromD<D> TruncateTo(D /* tag */, Vec128<uint64_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint16_t>(v.raw[i] & 0xFFFF);
  }
  return ret;
}

template <class D, HWY_IF_U32_D(D), size_t N>
HWY_API VFromD<D> TruncateTo(D /* tag */, Vec128<uint64_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint32_t>(v.raw[i] & 0xFFFFFFFFu);
  }
  return ret;
}

template <class D, HWY_IF_U8_D(D), size_t N>
HWY_API VFromD<D> TruncateTo(D /* tag */, Vec128<uint32_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint8_t>(v.raw[i] & 0xFF);
  }
  return ret;
}

template <class D, HWY_IF_U16_D(D), size_t N>
HWY_API VFromD<D> TruncateTo(D /* tag */, Vec128<uint32_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint16_t>(v.raw[i] & 0xFFFF);
  }
  return ret;
}

template <class D, HWY_IF_U8_D(D), size_t N>
HWY_API VFromD<D> TruncateTo(D /* tag */, Vec128<uint16_t, N> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = static_cast<uint8_t>(v.raw[i] & 0xFF);
  }
  return ret;
}

#ifdef HWY_NATIVE_ORDERED_TRUNCATE_2_TO
#undef HWY_NATIVE_ORDERED_TRUNCATE_2_TO
#else
#define HWY_NATIVE_ORDERED_TRUNCATE_2_TO
#endif

template <class DN, HWY_IF_UNSIGNED_D(DN), class V, HWY_IF_UNSIGNED_V(V),
          HWY_IF_T_SIZE_V(V, sizeof(TFromD<DN>) * 2),
          HWY_IF_LANES_D(DN, HWY_MAX_LANES_D(DFromV<V>) * 2)>
HWY_API VFromD<DN> OrderedTruncate2To(DN dn, V a, V b) {
  const RepartitionToWide<decltype(dn)> dw;
  const size_t NW = Lanes(dw);
  using TW = TFromD<decltype(dw)>;
  using TN = TFromD<decltype(dn)>;
  VFromD<DN> ret;
  constexpr TW max_val{LimitsMax<TN>()};

  for (size_t i = 0; i < NW; ++i) {
    ret.raw[i] = static_cast<TN>(a.raw[i] & max_val);
  }
  for (size_t i = 0; i < NW; ++i) {
    ret.raw[NW + i] = static_cast<TN>(b.raw[i] & max_val);
  }
  return ret;
}

// ================================================== COMBINE

template <typename T, size_t N>
HWY_API Vec128<T, N / 2> LowerHalf(Vec128<T, N> v) {
  Vec128<T, N / 2> ret;
  CopyBytes<N / 2 * sizeof(T)>(v.raw, ret.raw);
  return ret;
}

template <class D>
HWY_API VFromD<D> LowerHalf(D /* tag */, VFromD<Twice<D>> v) {
  return LowerHalf(v);
}

template <class D>
HWY_API VFromD<D> UpperHalf(D d, VFromD<Twice<D>> v) {
  VFromD<D> ret;
  CopyBytes<d.MaxBytes()>(&v.raw[MaxLanes(d)], ret.raw);
  return ret;
}

template <class D>
HWY_API VFromD<D> ZeroExtendVector(D d, VFromD<Half<D>> v) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;  // zero-initialized
  CopyBytes<dh.MaxBytes()>(v.raw, ret.raw);
  return ret;
}

template <class D, class VH = VFromD<Half<D>>>
HWY_API VFromD<D> Combine(D d, VH hi_half, VH lo_half) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(lo_half.raw, &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(hi_half.raw, &ret.raw[MaxLanes(dh)]);
  return ret;
}

template <class D>
HWY_API VFromD<D> ConcatLowerLower(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(lo.raw, &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(hi.raw, &ret.raw[MaxLanes(dh)]);
  return ret;
}

template <class D>
HWY_API VFromD<D> ConcatUpperUpper(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(&lo.raw[MaxLanes(dh)], &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(&hi.raw[MaxLanes(dh)], &ret.raw[MaxLanes(dh)]);
  return ret;
}

template <class D>
HWY_API VFromD<D> ConcatLowerUpper(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(&lo.raw[MaxLanes(dh)], &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(hi.raw, &ret.raw[MaxLanes(dh)]);
  return ret;
}

template <class D>
HWY_API VFromD<D> ConcatUpperLower(D d, VFromD<D> hi, VFromD<D> lo) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  CopyBytes<dh.MaxBytes()>(lo.raw, &ret.raw[0]);
  CopyBytes<dh.MaxBytes()>(&hi.raw[MaxLanes(dh)], &ret.raw[MaxLanes(dh)]);
  return ret;
}

template <class D>
HWY_API VFromD<D> ConcatEven(D d, VFromD<D> hi, VFromD<D> lo) {
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
HWY_API VFromD<D> ConcatOdd(D d, VFromD<D> hi, VFromD<D> lo) {
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

// ------------------------------ CombineShiftRightBytes
template <int kBytes, class D>
HWY_API VFromD<D> CombineShiftRightBytes(D d, VFromD<D> hi, VFromD<D> lo) {
  VFromD<D> ret;
  const uint8_t* HWY_RESTRICT lo8 =
      reinterpret_cast<const uint8_t * HWY_RESTRICT>(lo.raw);
  uint8_t* HWY_RESTRICT ret8 =
      reinterpret_cast<uint8_t * HWY_RESTRICT>(ret.raw);
  CopyBytes<d.MaxBytes() - kBytes>(lo8 + kBytes, ret8);
  CopyBytes<kBytes>(hi.raw, ret8 + d.MaxBytes() - kBytes);
  return ret;
}

// ------------------------------ ShiftLeftBytes

template <int kBytes, class D>
HWY_API VFromD<D> ShiftLeftBytes(D d, VFromD<D> v) {
  static_assert(0 <= kBytes && kBytes <= 16, "Invalid kBytes");
  VFromD<D> ret;
  uint8_t* HWY_RESTRICT ret8 =
      reinterpret_cast<uint8_t * HWY_RESTRICT>(ret.raw);
  ZeroBytes<kBytes>(ret8);
  CopyBytes<d.MaxBytes() - kBytes>(v.raw, ret8 + kBytes);
  return ret;
}

template <int kBytes, typename T, size_t N>
HWY_API Vec128<T, N> ShiftLeftBytes(Vec128<T, N> v) {
  return ShiftLeftBytes<kBytes>(DFromV<decltype(v)>(), v);
}

// ------------------------------ ShiftLeftLanes

template <int kLanes, class D, typename T = TFromD<D>>
HWY_API VFromD<D> ShiftLeftLanes(D d, VFromD<D> v) {
  const Repartition<uint8_t, decltype(d)> d8;
  return BitCast(d, ShiftLeftBytes<kLanes * sizeof(T)>(BitCast(d8, v)));
}

template <int kLanes, typename T, size_t N>
HWY_API Vec128<T, N> ShiftLeftLanes(Vec128<T, N> v) {
  return ShiftLeftLanes<kLanes>(DFromV<decltype(v)>(), v);
}

// ------------------------------ ShiftRightBytes
template <int kBytes, class D>
HWY_API VFromD<D> ShiftRightBytes(D d, VFromD<D> v) {
  static_assert(0 <= kBytes && kBytes <= 16, "Invalid kBytes");
  VFromD<D> ret;
  const uint8_t* HWY_RESTRICT v8 =
      reinterpret_cast<const uint8_t * HWY_RESTRICT>(v.raw);
  uint8_t* HWY_RESTRICT ret8 =
      reinterpret_cast<uint8_t * HWY_RESTRICT>(ret.raw);
  CopyBytes<d.MaxBytes() - kBytes>(v8 + kBytes, ret8);
  ZeroBytes<kBytes>(ret8 + d.MaxBytes() - kBytes);
  return ret;
}

// ------------------------------ ShiftRightLanes
template <int kLanes, class D>
HWY_API VFromD<D> ShiftRightLanes(D d, VFromD<D> v) {
  const Repartition<uint8_t, decltype(d)> d8;
  constexpr size_t kBytes = kLanes * sizeof(TFromD<D>);
  return BitCast(d, ShiftRightBytes<kBytes>(d8, BitCast(d8, v)));
}

// ================================================== SWIZZLE

template <typename T, size_t N>
HWY_API T GetLane(Vec128<T, N> v) {
  return v.raw[0];
}

template <typename T, size_t N>
HWY_API Vec128<T, N> InsertLane(Vec128<T, N> v, size_t i, T t) {
  v.raw[i] = t;
  return v;
}

template <typename T, size_t N>
HWY_API T ExtractLane(Vec128<T, N> v, size_t i) {
  return v.raw[i];
}

template <typename T, size_t N>
HWY_API Vec128<T, N> DupEven(Vec128<T, N> v) {
  for (size_t i = 0; i < N; i += 2) {
    v.raw[i + 1] = v.raw[i];
  }
  return v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> DupOdd(Vec128<T, N> v) {
  for (size_t i = 0; i < N; i += 2) {
    v.raw[i] = v.raw[i + 1];
  }
  return v;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> OddEven(Vec128<T, N> odd, Vec128<T, N> even) {
  for (size_t i = 0; i < N; i += 2) {
    odd.raw[i] = even.raw[i];
  }
  return odd;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> OddEvenBlocks(Vec128<T, N> /* odd */, Vec128<T, N> even) {
  return even;
}

// ------------------------------ SwapAdjacentBlocks
template <typename T, size_t N>
HWY_API Vec128<T, N> SwapAdjacentBlocks(Vec128<T, N> v) {
  return v;
}

// ------------------------------ TableLookupLanes

// Returned by SetTableIndices for use by TableLookupLanes.
template <typename T, size_t N>
struct Indices128 {
  MakeSigned<T> raw[N];
};

template <class D, typename TI, size_t N>
HWY_API Indices128<TFromD<D>, N> IndicesFromVec(D d, Vec128<TI, N> vec) {
  static_assert(sizeof(TFromD<D>) == sizeof(TI), "Index/lane size must match");
  Indices128<TFromD<D>, N> ret;
  CopyBytes<d.MaxBytes()>(vec.raw, ret.raw);
  return ret;
}

template <class D, typename TI>
HWY_API Indices128<TFromD<D>, HWY_MAX_LANES_D(D)> SetTableIndices(
    D d, const TI* idx) {
  return IndicesFromVec(d, LoadU(Rebind<TI, D>(), idx));
}

template <typename T, size_t N>
HWY_API Vec128<T, N> TableLookupLanes(Vec128<T, N> v, Indices128<T, N> idx) {
  Vec128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    ret.raw[i] = v.raw[idx.raw[i]];
  }
  return ret;
}

template <typename T, size_t N>
HWY_API Vec128<T, N> TwoTablesLookupLanes(Vec128<T, N> a, Vec128<T, N> b,
                                          Indices128<T, N> idx) {
  using TI = MakeSigned<T>;
  Vec128<T, N> ret;
  constexpr TI kVecLaneIdxMask = static_cast<TI>(N - 1);
  for (size_t i = 0; i < N; ++i) {
    const auto src_idx = idx.raw[i];
    const auto masked_src_lane_idx = src_idx & kVecLaneIdxMask;
    ret.raw[i] = (src_idx < static_cast<TI>(N)) ? a.raw[masked_src_lane_idx]
                                                : b.raw[masked_src_lane_idx];
  }
  return ret;
}

// ------------------------------ ReverseBlocks
template <class D>
HWY_API VFromD<D> ReverseBlocks(D /* tag */, VFromD<D> v) {
  return v;  // Single block: no change
}

// ------------------------------ Reverse

template <class D>
HWY_API VFromD<D> Reverse(D d, VFromD<D> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    ret.raw[i] = v.raw[MaxLanes(d) - 1 - i];
  }
  return ret;
}

// Per-target flag to prevent generic_ops-inl.h defining 8-bit Reverse2/4/8.
#ifdef HWY_NATIVE_REVERSE2_8
#undef HWY_NATIVE_REVERSE2_8
#else
#define HWY_NATIVE_REVERSE2_8
#endif

template <class D>
HWY_API VFromD<D> Reverse2(D d, VFromD<D> v) {
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(d); i += 2) {
    ret.raw[i + 0] = v.raw[i + 1];
    ret.raw[i + 1] = v.raw[i + 0];
  }
  return ret;
}

template <class D>
HWY_API VFromD<D> Reverse4(D d, VFromD<D> v) {
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
HWY_API VFromD<D> Reverse8(D d, VFromD<D> v) {
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

// ------------------------------ SlideUpLanes

template <class D>
HWY_API VFromD<D> SlideUpLanes(D d, VFromD<D> v, size_t amt) {
  VFromD<D> ret = Zero(d);
  constexpr size_t N = HWY_MAX_LANES_D(D);
  const size_t clamped_amt = HWY_MIN(amt, N);
  CopyBytes(v.raw, ret.raw + clamped_amt,
            (N - clamped_amt) * sizeof(TFromD<D>));
  return ret;
}

// ------------------------------ SlideDownLanes

template <class D>
HWY_API VFromD<D> SlideDownLanes(D d, VFromD<D> v, size_t amt) {
  VFromD<D> ret = Zero(d);
  constexpr size_t N = HWY_MAX_LANES_D(D);
  const size_t clamped_amt = HWY_MIN(amt, N);
  CopyBytes(v.raw + clamped_amt, ret.raw,
            (N - clamped_amt) * sizeof(TFromD<D>));
  return ret;
}

// ================================================== BLOCKWISE

// ------------------------------ Shuffle*

// Swap 32-bit halves in 64-bit halves.
template <typename T, size_t N>
HWY_API Vec128<T, N> Shuffle2301(Vec128<T, N> v) {
  static_assert(sizeof(T) == 4, "Only for 32-bit");
  static_assert(N == 2 || N == 4, "Does not make sense for N=1");
  return Reverse2(DFromV<decltype(v)>(), v);
}

// Swap 64-bit halves
template <typename T>
HWY_API Vec128<T> Shuffle1032(Vec128<T> v) {
  static_assert(sizeof(T) == 4, "Only for 32-bit");
  Vec128<T> ret;
  ret.raw[3] = v.raw[1];
  ret.raw[2] = v.raw[0];
  ret.raw[1] = v.raw[3];
  ret.raw[0] = v.raw[2];
  return ret;
}
template <typename T>
HWY_API Vec128<T> Shuffle01(Vec128<T> v) {
  static_assert(sizeof(T) == 8, "Only for 64-bit");
  return Reverse2(DFromV<decltype(v)>(), v);
}

// Rotate right 32 bits
template <typename T>
HWY_API Vec128<T> Shuffle0321(Vec128<T> v) {
  Vec128<T> ret;
  ret.raw[3] = v.raw[0];
  ret.raw[2] = v.raw[3];
  ret.raw[1] = v.raw[2];
  ret.raw[0] = v.raw[1];
  return ret;
}

// Rotate left 32 bits
template <typename T>
HWY_API Vec128<T> Shuffle2103(Vec128<T> v) {
  Vec128<T> ret;
  ret.raw[3] = v.raw[2];
  ret.raw[2] = v.raw[1];
  ret.raw[1] = v.raw[0];
  ret.raw[0] = v.raw[3];
  return ret;
}

template <typename T>
HWY_API Vec128<T> Shuffle0123(Vec128<T> v) {
  return Reverse4(DFromV<decltype(v)>(), v);
}

// ------------------------------ Broadcast
template <int kLane, typename T, size_t N>
HWY_API Vec128<T, N> Broadcast(Vec128<T, N> v) {
  for (size_t i = 0; i < N; ++i) {
    v.raw[i] = v.raw[kLane];
  }
  return v;
}

// ------------------------------ TableLookupBytes, TableLookupBytesOr0

template <typename T, size_t N, typename TI, size_t NI>
HWY_API Vec128<TI, NI> TableLookupBytes(Vec128<T, N> v,
                                        Vec128<TI, NI> indices) {
  const uint8_t* HWY_RESTRICT v_bytes =
      reinterpret_cast<const uint8_t * HWY_RESTRICT>(v.raw);
  const uint8_t* HWY_RESTRICT idx_bytes =
      reinterpret_cast<const uint8_t*>(indices.raw);
  Vec128<TI, NI> ret;
  uint8_t* HWY_RESTRICT ret_bytes =
      reinterpret_cast<uint8_t * HWY_RESTRICT>(ret.raw);
  for (size_t i = 0; i < NI * sizeof(TI); ++i) {
    const size_t idx = idx_bytes[i];
    // Avoid out of bounds reads.
    ret_bytes[i] = idx < sizeof(T) * N ? v_bytes[idx] : 0;
  }
  return ret;
}

template <typename T, size_t N, typename TI, size_t NI>
HWY_API Vec128<TI, NI> TableLookupBytesOr0(Vec128<T, N> v,
                                           Vec128<TI, NI> indices) {
  // Same as TableLookupBytes, which already returns 0 if out of bounds.
  return TableLookupBytes(v, indices);
}

// ------------------------------ InterleaveLower/InterleaveUpper

template <typename T, size_t N>
HWY_API Vec128<T, N> InterleaveLower(Vec128<T, N> a, Vec128<T, N> b) {
  Vec128<T, N> ret;
  for (size_t i = 0; i < N / 2; ++i) {
    ret.raw[2 * i + 0] = a.raw[i];
    ret.raw[2 * i + 1] = b.raw[i];
  }
  return ret;
}

// Additional overload for the optional tag.
template <class V>
HWY_API V InterleaveLower(DFromV<V> /* tag */, V a, V b) {
  return InterleaveLower(a, b);
}

template <class D>
HWY_API VFromD<D> InterleaveUpper(D d, VFromD<D> a, VFromD<D> b) {
  const Half<decltype(d)> dh;
  VFromD<D> ret;
  for (size_t i = 0; i < MaxLanes(dh); ++i) {
    ret.raw[2 * i + 0] = a.raw[MaxLanes(dh) + i];
    ret.raw[2 * i + 1] = b.raw[MaxLanes(dh) + i];
  }
  return ret;
}

// ------------------------------ ZipLower/ZipUpper (InterleaveLower)

// Same as Interleave*, except that the return lanes are double-width integers;
// this is necessary because the single-lane scalar cannot return two values.
template <class V, class DW = RepartitionToWide<DFromV<V>>>
HWY_API VFromD<DW> ZipLower(V a, V b) {
  return BitCast(DW(), InterleaveLower(a, b));
}
template <class V, class D = DFromV<V>, class DW = RepartitionToWide<D>>
HWY_API VFromD<DW> ZipLower(DW dw, V a, V b) {
  return BitCast(dw, InterleaveLower(D(), a, b));
}

template <class V, class D = DFromV<V>, class DW = RepartitionToWide<D>>
HWY_API VFromD<DW> ZipUpper(DW dw, V a, V b) {
  return BitCast(dw, InterleaveUpper(D(), a, b));
}

// ================================================== MASK

template <class D>
HWY_API bool AllFalse(D d, MFromD<D> mask) {
  typename MFromD<D>::Raw or_sum = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    or_sum |= mask.bits[i];
  }
  return or_sum == 0;
}

template <class D>
HWY_API bool AllTrue(D d, MFromD<D> mask) {
  constexpr uint64_t kAll = LimitsMax<typename MFromD<D>::Raw>();
  uint64_t and_sum = kAll;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    and_sum &= mask.bits[i];
  }
  return and_sum == kAll;
}

// `p` points to at least 8 readable bytes, not all of which need be valid.
template <class D>
HWY_API MFromD<D> LoadMaskBits(D d, const uint8_t* HWY_RESTRICT bits) {
  MFromD<D> m;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    const size_t bit = size_t{1} << (i & 7);
    const size_t idx_byte = i >> 3;
    m.bits[i] = MFromD<D>::FromBool((bits[idx_byte] & bit) != 0);
  }
  return m;
}

// `p` points to at least 8 writable bytes.
template <class D>
HWY_API size_t StoreMaskBits(D d, MFromD<D> mask, uint8_t* bits) {
  bits[0] = 0;
  if (MaxLanes(d) > 8) bits[1] = 0;  // MaxLanes(d) <= 16, so max two bytes
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
HWY_API size_t CountTrue(D d, MFromD<D> mask) {
  size_t count = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    count += mask.bits[i] != 0;
  }
  return count;
}

template <class D>
HWY_API size_t FindKnownFirstTrue(D d, MFromD<D> mask) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (mask.bits[i] != 0) return i;
  }
  HWY_DASSERT(false);
  return 0;
}

template <class D>
HWY_API intptr_t FindFirstTrue(D d, MFromD<D> mask) {
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (mask.bits[i] != 0) return static_cast<intptr_t>(i);
  }
  return intptr_t{-1};
}

template <class D>
HWY_API size_t FindKnownLastTrue(D d, MFromD<D> mask) {
  for (intptr_t i = static_cast<intptr_t>(MaxLanes(d) - 1); i >= 0; i--) {
    if (mask.bits[i] != 0) return static_cast<size_t>(i);
  }
  HWY_DASSERT(false);
  return 0;
}

template <class D>
HWY_API intptr_t FindLastTrue(D d, MFromD<D> mask) {
  for (intptr_t i = static_cast<intptr_t>(MaxLanes(d) - 1); i >= 0; i--) {
    if (mask.bits[i] != 0) return i;
  }
  return intptr_t{-1};
}

// ------------------------------ Compress

template <typename T>
struct CompressIsPartition {
  enum { value = (sizeof(T) != 1) };
};

template <typename T, size_t N>
HWY_API Vec128<T, N> Compress(Vec128<T, N> v, Mask128<T, N> mask) {
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
  HWY_DASSERT(count == N);
  return ret;
}

// ------------------------------ Expand

// Could also just allow generic_ops-inl.h to implement these, but use our
// simple implementation below to ensure the test is correct.
#ifdef HWY_NATIVE_EXPAND
#undef HWY_NATIVE_EXPAND
#else
#define HWY_NATIVE_EXPAND
#endif

template <typename T, size_t N>
HWY_API Vec128<T, N> Expand(Vec128<T, N> v, const Mask128<T, N> mask) {
  size_t in_pos = 0;
  Vec128<T, N> ret;
  for (size_t i = 0; i < N; ++i) {
    if (mask.bits[i]) {
      ret.raw[i] = v.raw[in_pos++];
    } else {
      ret.raw[i] = T();  // zero, also works for float16_t
    }
  }
  return ret;
}

// ------------------------------ LoadExpand

template <class D>
HWY_API VFromD<D> LoadExpand(MFromD<D> mask, D d,
                             const TFromD<D>* HWY_RESTRICT unaligned) {
  size_t in_pos = 0;
  VFromD<D> ret;
  for (size_t i = 0; i < Lanes(d); ++i) {
    if (mask.bits[i]) {
      ret.raw[i] = unaligned[in_pos++];
    } else {
      ret.raw[i] = TFromD<D>();  // zero, also works for float16_t
    }
  }
  return ret;
}

// ------------------------------ CompressNot
template <typename T, size_t N>
HWY_API Vec128<T, N> CompressNot(Vec128<T, N> v, Mask128<T, N> mask) {
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
  HWY_DASSERT(count == N);
  return ret;
}

// ------------------------------ CompressBlocksNot
HWY_API Vec128<uint64_t> CompressBlocksNot(Vec128<uint64_t> v,
                                           Mask128<uint64_t> /* m */) {
  return v;
}

// ------------------------------ CompressBits
template <typename T, size_t N>
HWY_API Vec128<T, N> CompressBits(Vec128<T, N> v,
                                  const uint8_t* HWY_RESTRICT bits) {
  return Compress(v, LoadMaskBits(Simd<T, N, 0>(), bits));
}

// ------------------------------ CompressStore

// generic_ops-inl defines the 8-bit versions.
template <class D, HWY_IF_NOT_T_SIZE_D(D, 1)>
HWY_API size_t CompressStore(VFromD<D> v, MFromD<D> mask, D d,
                             TFromD<D>* HWY_RESTRICT unaligned) {
  size_t count = 0;
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    if (mask.bits[i]) {
      unaligned[count++] = v.raw[i];
    }
  }
  return count;
}

// ------------------------------ CompressBlendedStore
template <class D, HWY_IF_NOT_T_SIZE_D(D, 1)>
HWY_API size_t CompressBlendedStore(VFromD<D> v, MFromD<D> mask, D d,
                                    TFromD<D>* HWY_RESTRICT unaligned) {
  return CompressStore(v, mask, d, unaligned);
}

// ------------------------------ CompressBitsStore
template <class D, HWY_IF_NOT_T_SIZE_D(D, 1)>
HWY_API size_t CompressBitsStore(VFromD<D> v, const uint8_t* HWY_RESTRICT bits,
                                 D d, TFromD<D>* HWY_RESTRICT unaligned) {
  const MFromD<D> mask = LoadMaskBits(d, bits);
  StoreU(Compress(v, mask), d, unaligned);
  return CountTrue(d, mask);
}

// ------------------------------ Additional mask logical operations
template <class T>
HWY_API Mask128<T, 1> SetAtOrAfterFirst(Mask128<T, 1> mask) {
  return mask;
}

template <class T, size_t N, HWY_IF_LANES_GT(N, 1)>
HWY_API Mask128<T, N> SetAtOrAfterFirst(Mask128<T, N> mask) {
  using TU = hwy::MakeUnsigned<T>;

  Mask128<T, N> result;
  TU result_lane_mask{0};
  for (size_t i = 0; i < N; i++) {
    result_lane_mask = static_cast<TU>(result_lane_mask | mask.bits[i]);
    result.bits[i] = result_lane_mask;
  }
  return result;
}

template <class T, size_t N>
HWY_API Mask128<T, N> SetBeforeFirst(Mask128<T, N> mask) {
  return Not(SetAtOrAfterFirst(mask));
}

template <class T, size_t N>
HWY_API Mask128<T, N> SetOnlyFirst(Mask128<T, N> mask) {
  using TU = hwy::MakeUnsigned<T>;
  using TI = hwy::MakeSigned<T>;

  Mask128<T, N> result;
  TU result_lane_mask = static_cast<TU>(~TU{0});
  for (size_t i = 0; i < N; i++) {
    const auto curr_lane_mask_bits = mask.bits[i];
    result.bits[i] = static_cast<TU>(curr_lane_mask_bits & result_lane_mask);
    result_lane_mask =
        static_cast<TU>(result_lane_mask &
                        static_cast<TU>(-static_cast<TI>(mask.bits[i] == 0)));
  }
  return result;
}

template <class T, size_t N>
HWY_API Mask128<T, N> SetAtOrBeforeFirst(Mask128<T, N> mask) {
  using TU = hwy::MakeUnsigned<T>;
  using TI = hwy::MakeSigned<T>;

  Mask128<T, N> result;
  TU result_lane_mask = static_cast<TU>(~TU{0});
  for (size_t i = 0; i < N; i++) {
    result.bits[i] = result_lane_mask;
    result_lane_mask =
        static_cast<TU>(result_lane_mask &
                        static_cast<TU>(-static_cast<TI>(mask.bits[i] == 0)));
  }
  return result;
}

// ------------------------------ WidenMulPairwiseAdd

template <class D, HWY_IF_F32_D(D), class VBF16>
HWY_API VFromD<D> WidenMulPairwiseAdd(D df32, VBF16 a, VBF16 b) {
  const Rebind<uint32_t, decltype(df32)> du32;
  using VU32 = VFromD<decltype(du32)>;
  const VU32 odd = Set(du32, 0xFFFF0000u);  // bfloat16 is the upper half of f32
  // Avoid ZipLower/Upper so this also works on big-endian systems.
  const VU32 ae = ShiftLeft<16>(BitCast(du32, a));
  const VU32 ao = And(BitCast(du32, a), odd);
  const VU32 be = ShiftLeft<16>(BitCast(du32, b));
  const VU32 bo = And(BitCast(du32, b), odd);
  return Mul(BitCast(df32, ae), BitCast(df32, be)) +
         Mul(BitCast(df32, ao), BitCast(df32, bo));
}

template <class D, HWY_IF_I32_D(D), class VI16>
HWY_API VFromD<D> WidenMulPairwiseAdd(D d32, VI16 a, VI16 b) {
  using VI32 = VFromD<decltype(d32)>;
  // Manual sign extension requires two shifts for even lanes.
  const VI32 ae = ShiftRight<16>(ShiftLeft<16>(BitCast(d32, a)));
  const VI32 be = ShiftRight<16>(ShiftLeft<16>(BitCast(d32, b)));
  const VI32 ao = ShiftRight<16>(BitCast(d32, a));
  const VI32 bo = ShiftRight<16>(BitCast(d32, b));
  return Add(Mul(ae, be), Mul(ao, bo));
}

template <class D, HWY_IF_U32_D(D), class VU16>
HWY_API VFromD<D> WidenMulPairwiseAdd(D du32, VU16 a, VU16 b) {
  const auto lo16_mask = Set(du32, 0x0000FFFFu);

  const auto a0 = And(BitCast(du32, a), lo16_mask);
  const auto b0 = And(BitCast(du32, b), lo16_mask);

  const auto a1 = ShiftRight<16>(BitCast(du32, a));
  const auto b1 = ShiftRight<16>(BitCast(du32, b));

  return Add(Mul(a0, b0), Mul(a1, b1));
}

// ------------------------------ ReorderWidenMulAccumulate (MulAdd, ZipLower)

template <class D, HWY_IF_F32_D(D), size_t N, class VBF16>
HWY_API VFromD<D> ReorderWidenMulAccumulate(D df32, VBF16 a, VBF16 b,
                                            const Vec128<float, N> sum0,
                                            Vec128<float, N>& sum1) {
  const Rebind<uint32_t, decltype(df32)> du32;
  using VU32 = VFromD<decltype(du32)>;
  const VU32 odd = Set(du32, 0xFFFF0000u);  // bfloat16 is the upper half of f32
  // Avoid ZipLower/Upper so this also works on big-endian systems.
  const VU32 ae = ShiftLeft<16>(BitCast(du32, a));
  const VU32 ao = And(BitCast(du32, a), odd);
  const VU32 be = ShiftLeft<16>(BitCast(du32, b));
  const VU32 bo = And(BitCast(du32, b), odd);
  sum1 = MulAdd(BitCast(df32, ao), BitCast(df32, bo), sum1);
  return MulAdd(BitCast(df32, ae), BitCast(df32, be), sum0);
}

template <class D, HWY_IF_I32_D(D), size_t N, class VI16>
HWY_API VFromD<D> ReorderWidenMulAccumulate(D d32, VI16 a, VI16 b,
                                            const Vec128<int32_t, N> sum0,
                                            Vec128<int32_t, N>& sum1) {
  using VI32 = VFromD<decltype(d32)>;
  // Manual sign extension requires two shifts for even lanes.
  const VI32 ae = ShiftRight<16>(ShiftLeft<16>(BitCast(d32, a)));
  const VI32 be = ShiftRight<16>(ShiftLeft<16>(BitCast(d32, b)));
  const VI32 ao = ShiftRight<16>(BitCast(d32, a));
  const VI32 bo = ShiftRight<16>(BitCast(d32, b));
  sum1 = Add(Mul(ao, bo), sum1);
  return Add(Mul(ae, be), sum0);
}

template <class D, HWY_IF_U32_D(D), size_t N, class VU16>
HWY_API VFromD<D> ReorderWidenMulAccumulate(D du32, VU16 a, VU16 b,
                                            const Vec128<uint32_t, N> sum0,
                                            Vec128<uint32_t, N>& sum1) {
  using VU32 = VFromD<decltype(du32)>;
  const VU32 lo16_mask = Set(du32, uint32_t{0x0000FFFFu});
  const VU32 ae = And(BitCast(du32, a), lo16_mask);
  const VU32 be = And(BitCast(du32, b), lo16_mask);
  const VU32 ao = ShiftRight<16>(BitCast(du32, a));
  const VU32 bo = ShiftRight<16>(BitCast(du32, b));
  sum1 = Add(Mul(ao, bo), sum1);
  return Add(Mul(ae, be), sum0);
}

// ------------------------------ RearrangeToOddPlusEven
template <class VW>
HWY_API VW RearrangeToOddPlusEven(VW sum0, VW sum1) {
  return Add(sum0, sum1);
}

// ================================================== REDUCTIONS

template <class D, typename T = TFromD<D>>
HWY_API VFromD<D> SumOfLanes(D d, VFromD<D> v) {
  T sum = T{0};
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    sum += v.raw[i];
  }
  return Set(d, sum);
}
template <class D, typename T = TFromD<D>>
HWY_API T ReduceSum(D d, VFromD<D> v) {
  T sum = T{0};
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    sum += v.raw[i];
  }
  return sum;
}
template <class D, typename T = TFromD<D>>
HWY_API VFromD<D> MinOfLanes(D d, VFromD<D> v) {
  T min = HighestValue<T>();
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    min = HWY_MIN(min, v.raw[i]);
  }
  return Set(d, min);
}
template <class D, typename T = TFromD<D>>
HWY_API VFromD<D> MaxOfLanes(D d, VFromD<D> v) {
  T max = LowestValue<T>();
  for (size_t i = 0; i < MaxLanes(d); ++i) {
    max = HWY_MAX(max, v.raw[i]);
  }
  return Set(d, max);
}

// ================================================== OPS WITH DEPENDENCIES

// ------------------------------ MulEven/Odd 64x64 (UpperHalf)

HWY_INLINE Vec128<uint64_t> MulEven(Vec128<uint64_t> a, Vec128<uint64_t> b) {
  alignas(16) uint64_t mul[2];
  mul[0] = Mul128(GetLane(a), GetLane(b), &mul[1]);
  return Load(Full128<uint64_t>(), mul);
}

HWY_INLINE Vec128<uint64_t> MulOdd(Vec128<uint64_t> a, Vec128<uint64_t> b) {
  alignas(16) uint64_t mul[2];
  const Half<Full128<uint64_t>> d2;
  mul[0] =
      Mul128(GetLane(UpperHalf(d2, a)), GetLane(UpperHalf(d2, b)), &mul[1]);
  return Load(Full128<uint64_t>(), mul);
}

// NOLINTNEXTLINE(google-readability-namespace-comments)
}  // namespace HWY_NAMESPACE
}  // namespace hwy
HWY_AFTER_NAMESPACE();

#elif HWY_TARGET == HWY_SCALAR
#include "hwy/ops/scalar-inl.h"
#else
#pragma message("HWY_TARGET does not match any known target")
#endif  // HWY_TARGET

#include "hwy/ops/generic_ops-inl.h"

#endif  // HWY_HIGHWAY_PER_TARGET
#include <cstdio>
#include <inttypes.h>
#include <cassert>
#include <cfenv>
namespace hwy {
namespace HWY_NAMESPACE {
template <class D, class V> V CallLog1p(D d, V x) { return Log1p(d, x); }
namespace impl {
template <class> struct LogImpl {
  template <class D, class V>
  Vec<Rebind<int64_t, D>> Log2p1NoSubnormal(D, V x) {
    Rebind<int64_t, D> di64;
    Rebind<uint64_t, D> du64;
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
template <class D, class V, bool> HWY_INLINE V Log(D d, V x) {
  using T = TFromD<D>;
  LogImpl<T> impl;
  V kLn2Hi = Set(d, 0.693147180369123816490);
  V kLn2Lo = Set(d, 1.90821492927058770002e-10);
  V kOne = Set(d, 1.0);
  using TI = MakeSigned<T>;
  Rebind<TI, D> di;
  using VI = decltype(Zero(di));
  VI kLowerBits = Set(di, 4294967295);
  VI kMagic = Set(di, 4604544269498187776);
  VI kExpMask = Set(di, 4607182418800017408);
  VI kManMask = Set(di, 4503595332403200);
  VI exp_bits = Add(BitCast(di, x), Sub(kExpMask, kMagic));
  V exp = ConvertTo(d, impl.Log2p1NoSubnormal(d, exp_bits));
  V y = Or(And(x, BitCast(d, kLowerBits)),
           BitCast(d, Add(And(exp_bits, kManMask), kMagic)));
  V ym1 = Sub(y, kOne);
  V z = Div(ym1, Add(y, kOne));
  return MulSub(
      exp, kLn2Hi,
      Sub(MulSub(z, Sub(ym1, impl.LogPoly(d, z)), Mul(exp, kLn2Lo)), ym1));
}
} // namespace impl
template <class D, class V> V Log1p(D d, V x) {
  using T = TFromD<D>;
  V kOne = Set(d, T(1.0));
  const V y = Add(x, kOne);
  volatile auto dbg8 = y; (void)dbg8;
#if HIDESYMPTOM
  fprintf(stdout, "%.17g\n", y.raw[0] );
#endif
  auto is_pole = Eq(y, kOne);
  //volatile auto dbg7 = is_pole; (void)dbg7;
//  fprintf(stdout, "%" PRIu64 "\n", is_pole.bits[0] );
#if 1
  auto divisor = Sub(IfThenZeroElse(is_pole, y), kOne);
#else
  volatile auto dbg7 = is_pole;
  auto tmp1 = IfThenZeroElse(is_pole, y);
  volatile auto dbg4 = tmp1;
  volatile auto dbg5 = kOne;
  auto divisor = Sub(tmp1, kOne);
  volatile auto dbg6 = divisor;
  (void)dbg4;
  (void)dbg5;
  (void)dbg6;
  (void)dbg7;
#endif
#if 1
  auto non_pole = Mul(impl::Log<D, V, false>(d, y), Div(x, divisor));
#else
  volatile auto dbg3 = y;
  volatile auto dbg0 = divisor;
  auto tmp1 = impl::Log<D, V, false>(d, y);
  auto tmp2 = Div(x, divisor);
  volatile auto dbg1 = tmp1;
  volatile auto dbg2 = tmp2;
  (void)dbg0;
  (void)dbg1;
  (void)dbg2;
  (void)dbg3;
  auto non_pole = Mul( tmp1, tmp2);
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
  //uint64_t kSamplesPerRange = 4000, start = 4318952042648305665 , stop = 9218868437227405311;
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
#else
    (void)actual;
    (void)expected;
    assert( actual >= 0.0 );
#endif
  }
}
} // namespace hwy
int main() {
//  feenableexcept(FE_INVALID | FE_DIVBYZERO );
//  feenableexcept( FE_INVALID );
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::TestMath(b2);
}

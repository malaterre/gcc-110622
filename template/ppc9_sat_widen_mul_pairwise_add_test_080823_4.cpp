#include <stddef.h>

#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

#pragma push_macro("vector")
#pragma push_macro("pixel")
#pragma push_macro("bool")

#undef vector
#undef pixel
#undef bool

#include <altivec.h>

#pragma pop_macro("vector")
#pragma pop_macro("pixel")
#pragma pop_macro("bool")

struct StdFreeDeleter {
  template <class T>
  void operator()(T* ptr) const noexcept {
    if (ptr)
      std::free(const_cast<void*>(static_cast<const volatile void*>(ptr)));
  }
};

template <class T>
std::unique_ptr<T[], StdFreeDeleter> AllocateVectorAlignedArray() {
  constexpr size_t kAllocLen = 16 / sizeof(T);
  static_assert(kAllocLen > 0, "kAllocLen > 0 must be true");

  T* ptr = reinterpret_cast<T*>(std::aligned_alloc(16, kAllocLen));
  return std::unique_ptr<T[], StdFreeDeleter>(ptr);
}

static inline __attribute__((__always_inline__)) __vector signed char Neg(
    __vector signed char v) {
  return vec_sub(vec_splats(static_cast<signed char>(0)), v);
}

static inline __attribute__((__always_inline__)) __vector unsigned char
AltivecU8Iota0() {
  constexpr __vector unsigned char kU8Iota0 = {0, 1, 2,  3,  4,  5,  6,  7,
                                               8, 9, 10, 11, 12, 13, 14, 15};
  return kU8Iota0;
}

static inline __attribute__((__always_inline__)) __vector signed char
AltivecI8Iota0() {
  return reinterpret_cast<__vector signed char>(AltivecU8Iota0());
}

static inline __vector signed short SatWidenMulPairwiseAdd(
    __vector unsigned char a, __vector signed char b) {
  const __vector unsigned short vu16_k8 =
      vec_splats(static_cast<unsigned short>(8));

  const auto a0 = vec_and(reinterpret_cast<__vector signed short>(a),
                          vec_splats(static_cast<short>(0x00FF)));
  const auto b0 =
      vec_sra(reinterpret_cast<__vector signed short>(vec_sl(
                  reinterpret_cast<__vector unsigned short>(b), vu16_k8)),
              vu16_k8);

  const auto a1 = reinterpret_cast<__vector signed short>(
      vec_sr(reinterpret_cast<__vector unsigned short>(a), vu16_k8));
  const auto b1 = vec_sra(reinterpret_cast<__vector signed short>(b), vu16_k8);

  return vec_adds(vec_mul(a0, b0), vec_mul(a1, b1));
}

template <class T>
static inline void PrintArrayElements(const T* ptr, size_t len) {
  std::cout << '{';
  for (size_t i = 0; i < len; i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    std::cout << ptr[i];
  }
  std::cout << '}';
}

static inline __attribute__((__noinline__, __noipa__)) void
VerifyVectorElementsEqual(const short* expected, const short* actual) {
  for (size_t i = 0; i < 8; i++) {
    if (expected[i] != actual[i]) {
      std::cout << "Actual vector not equal to expected vector\n";
      std::cout << "Expected: ";
      PrintArrayElements(expected, 8);
      std::cout << "\nActual:   ";
      PrintArrayElements(actual, 8);
      std::cout << '\n';
      std::cout.flush();
      std::cerr.flush();
      std::abort();
    }
  }
}

static inline __attribute__((__always_inline__)) void DoAssertVectorsEqual(
    __vector signed short expected, __vector signed short actual) {
  auto expected_lanes = AllocateVectorAlignedArray<short>();
  auto actual_lanes = AllocateVectorAlignedArray<short>();
  if (!expected_lanes || !actual_lanes) {
    std::cout << "Failed to allocate arrays\n";
    std::cout.flush();
    std::cerr.flush();
    std::abort();
  }

  *reinterpret_cast<__vector signed short*>(expected_lanes.get()) = expected;
  *reinterpret_cast<__vector signed short*>(actual_lanes.get()) = actual;
  VerifyVectorElementsEqual(expected_lanes.get(), actual_lanes.get());
}

__attribute__((__noinline__)) void TestSatWidenMulPairwiseAdd() {
  using VN = __vector signed char;
  using VN_U = __vector unsigned char;
  using TN = signed char;
  using TN_U = unsigned char;
  using TW = signed short;

  const VN nf0 = reinterpret_cast<VN>(vec_splats(0));

  const auto vn_signed_min = vec_splats(std::numeric_limits<TN>::min());
  const auto vn_signed_max = vec_splats(std::numeric_limits<TN>::max());
  const auto vn_unsigned_max = vec_splats(std::numeric_limits<TN_U>::max());
  const auto vw_signed_min = vec_splats(std::numeric_limits<TW>::min());

  const auto vn_iota_zero_repl =
      vec_splats(static_cast<TN>(std::numeric_limits<TN>::max() - 16));

  auto vn_a =
      vec_and(vec_add(AltivecI8Iota0(), vec_splats(TN{1})), vn_signed_max);
  vn_a = vec_or(vn_a, vec_and(vec_cmpeq(vn_a, nf0), vn_iota_zero_repl));

  auto vn_b = vec_add(vec_and(vn_a, vec_splats(TN{63})), vec_splats(TN{20}));
  const auto vn_neg_b = Neg(vn_b);
  DoAssertVectorsEqual(
      vw_signed_min,
      SatWidenMulPairwiseAdd(
          vec_mergeh(reinterpret_cast<VN_U>(vn_b), vn_unsigned_max),
          vec_mergeh(vn_neg_b, vn_signed_min)));
}

int main() {
  TestSatWidenMulPairwiseAdd();
  std::cout << "Test completed successfully\n";
  return 0;
}

#include "hwy/contrib/math/math-inl.h"
#include <float.h>
#include <iostream>
namespace hwy {
namespace N_EMU128 {
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class T, class D>
void TestMath(T fx1(T), Vec<D> fxN(D, VecArg<Vec<D>>), D d, T min, T max) {
  using UintT = MakeUnsigned<T>;
  UintT min_bits(min);
  UintT max_bits;
  CopyBytes<sizeof max_bits>(&max, &max_bits);
  UintT ranges[][2]{{min_bits, max_bits}};
  UintT kSamplesPerRange(4000);
  int range_index = 0;
  UintT start = ranges[range_index][0];
  UintT stop = ranges[range_index][1];
  UintT step(stop / kSamplesPerRange);
  for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
    T value = BitCast<T>(value_bits), actual = GetLane(fxN(d, Set(d, value))),
      expected = fx1(value);
    fprintf(stderr, "Log1p(%.17g) expected %.17g actual %.17g \n", value,
            expected, actual);
  }
}
#define DEFINE_MATH_TEST(F64x1, F64xN, F64_MIN, F64_MAX)                       \
  struct TestLog1p {                                                           \
    template <class T, class D> void operator()(T, D d) {                      \
      TestMath(F64x1, F64xN, d, F64_MIN, F64_MAX);                             \
    }                                                                          \
  }
DEFINE_MATH_TEST(log1p, CallLog1p, 0.0, DBL_MAX);
} // namespace N_EMU128
} // namespace hwy
double main_b1;
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::N_EMU128::TestLog1p testLog1p;
  testLog1p(main_b1, b2);
}

#include "hwy/contrib/math/math-inl.h"
#include <float.h>
#include <iostream>
char TypeName_string100[1];
namespace hwy {
template <typename T> std::string TypeName(T) { return TypeName_string100; }
namespace HWY_NAMESPACE {
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class T, class D>
void TestMath(const char *name, T fx1(T), Vec<D> fxN(D, VecArg<Vec<D>>), D d,
              T min, T max ) {
  using UintT = MakeUnsigned<T>;
  UintT min_bits(min);
  UintT max_bits = BitCast<UintT>(max);
  UintT ranges[][2]{{min_bits, max_bits}};
  UintT kSamplesPerRange(4000);
  int range_index = 0;
  UintT start = ranges[range_index][0];
  UintT stop = ranges[range_index][1];
  UintT step(stop / kSamplesPerRange);
  for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
    T value = BitCast<T> HWY_MIN(value_bits, stop);
    T actual = GetLane(fxN(d, Set(d, value)));
    T expected = fx1(value);
    fprintf(stderr, "%s: %s(%.17g) expected %.17g actual %.17g \n",
            TypeName(T()).c_str(), name, value, expected, actual);
  }
}
#define DEFINE_MATH_TEST(NAME, F64x1, F64xN, F64_MIN, F64_MAX )      \
  struct Test##NAME {                                                          \
    template <class T, class D> void operator()(T, D d) {                      \
      TestMath(HWY_STR(NAME), F64x1, F64xN, d, F64_MIN, F64_MAX );   \
    }                                                                          \
  }
DEFINE_MATH_TEST(Log1p, log1p, CallLog1p, 0.0, DBL_MAX );
} // namespace HWY_NAMESPACE
} // namespace hwy
double main_b1;
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::N_EMU128::TestLog1p testLog1p;
  testLog1p(main_b1, b2);
}

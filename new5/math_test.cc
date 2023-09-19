#include "hwy/contrib/math/math-inl.h"
#include <float.h>
#include <iostream>
namespace hwy {
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
struct TestLog1p {
  template <class T, class D> void operator()(T, D d) {
    T min = 0.0, max = DBL_MAX;
    using UintT = MakeUnsigned<T>;
    UintT min_bits(min);
    UintT max_bits;
    CopyBytes<sizeof max_bits>(&max, &max_bits);
    UintT ranges[]{min_bits, max_bits};
    UintT kSamplesPerRange(4000);
    UintT start = 0;
    UintT stop = ranges[1];
    UintT step(stop / kSamplesPerRange);
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      T value = BitCast<T>(value_bits),
        actual = GetLane(CallLog1p(d, Set(d, value))), expected(value);
      fprintf(stderr, "Log1p(%.17g) expected %.17g actual %.17g \n", value,
              expected, actual);
    }
  }
};
} // namespace hwy
double main_b1;
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::TestLog1p testLog1p;
  testLog1p(main_b1, b2);
}

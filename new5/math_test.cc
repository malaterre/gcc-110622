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
void TestMath(T fx1(T), Vec<D> fxN(D, VecArg<Vec<D>>), D d ) {
//  using UintT = MakeUnsigned<T>;
//  UintT min_bits(min);
//  UintT max_bits;
//  CopyBytes<sizeof max_bits>(&max, &max_bits);
//  UintT ranges[]{min_bits, max_bits};
  uint64_t kSamplesPerRange(4000);
  uint64_t start = 0;
  uint64_t stop; // = ranges[1];
  stop = 0x7fefffffffffffff;
  uint64_t step(stop / kSamplesPerRange);
  for (uint64_t value_bits = start; value_bits <= stop; value_bits += step) {
    T value = BitCast<T>(value_bits), actual = GetLane(fxN(d, Set(d, value))),
      expected = fx1(value);
    fprintf(stderr, "Log1p(%.17g) expected %.17g actual %.17g \n", value,
            expected, actual);
  }
}
} // namespace N_EMU128
} // namespace hwy
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::N_EMU128::TestMath<double>(log1p, hwy::N_EMU128::CallLog1p, b2 );
}

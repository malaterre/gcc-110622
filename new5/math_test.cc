#include "hwy/contrib/math/math-inl.h"
#include <iostream>
#include <inttypes.h>

namespace hwy {
template <class Out, class In> Out BitCast(In in) {
  Out out;
  CopyBytes<sizeof(out)>(&in, &out);
  return out;
}
template <class D> void TestMath(D d) {
  uint64_t kSamplesPerRange=4000 , start = 0, stop = 9218868437227405311;
  uint64_t step(stop / kSamplesPerRange);
  for (uint64_t value_bits = start; value_bits <= stop; value_bits += step) {
    double value = BitCast<double>(value_bits),
           actual = GetLane(CallLog1p(d, Set(d, value))),
           expected = log1p(value);
    fprintf(stderr, "%" PRIu64 " - Log1p(%.17g) expected %.17g actual %.17g %a\n", value_bits, value,
            expected, actual, actual);
  }
}
} // namespace hwy
int main() {
  hwy::N_EMU128::Simd<double, 1, 0> b2;
  hwy::TestMath(b2);
}

#include "hwy/contrib/math/math-inl.h"
#include "hwy/tests/test_util-inl.h"

namespace hwy {
namespace N_EMU128 {
template <class b, class c> b al(c e) {
  b f;
  CopyBytes<sizeof(f)>(&e, &f);
  return f;
}
template <class g, class h>
void am(std::string i, g an(g), Vec<h> j(h, VecArg<Vec<h>>), h d, g k, g l,
        uint64_t m) {
  (void)i;
  using n = MakeUnsigned<g>;
  n o(k), p = al<n>(l), s(4000);
  n q[][2]{{o, p}};
  uint64_t r = 0;
  for (int ao = 0; ao < 1; ++ao) {
    n ap = q[ao][0], aq = q[ao][1], ar(s);
    for (n as = ap; as <= aq; as += ar) {
      g t = al<g> ((as) < (aq) ? (as) : (aq));
      VFromD<h> u = Set(d, t);
      g aa = GetLane(j(d, u));
      g ab = an(t);
      auto ac = hwy::detail::ComputeUlpDelta(aa, ab);
      r = ((r) > (ac) ? (r) : (ac));
    }
  }
  do { if (!(r <= m)) { ::hwy::Abort("math_test.cc", 29, "Assert %s","r <= m"); } } while (0);
}
struct xLog1p { template <class g, class h> void operator()(g, h d) { am("", log1p, CallLog1p, d, 0.0f, 1e37f, 3); } }; void MyAllLog1p() { ForFloatTypes(ForPartialVectors<xLog1p>()); }
}
}
int main() { hwy::N_EMU128::MyAllLog1p(); }


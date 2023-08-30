#include "hwy/contrib/math/math-inl.h"
#include "hwy/tests/test_util-inl.h"
namespace hwy {
namespace HWY_NAMESPACE {
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
  n q[][2]{o, p};
  uint64_t r = 0;
  for (int ao = 0; ao < 1; ++ao) {
    n ap = q[ao][0], aq = q[ao][1], ar(s);
    for (n as = ap; as <= aq; as += ar) {
      g t = al<g> HWY_MIN(as, aq);
      VFromD<h> u = Set(d, t);
      g aa = GetLane(j(d, u));
      g ab = an(t);
      auto ac = hwy::detail::ComputeUlpDelta(aa, ab);
      r = HWY_MAX(r, ac);
    }
  }
  HWY_ASSERT(r <= m);
}
#define v(w)                                                                   \
  void MyAll##w() { ForFloatTypes(ForPartialVectors<x##w>()); }
#define y(w, z, ad, ae, af, ag, ah, ai, aj, ak, a)                             \
  struct x##w {                                                                \
    template <class g, class h> void operator()(g, h d) {                      \
      am(HWY_STR(), z, ad, d, ae, af, ag);                                     \
    }                                                                          \
  };                                                                           \
  v(w)
y(Log1p, log1p, CallLog1p, 0.0f, 1e37f, 3, , , , , )
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() { hwy::N_EMU128::MyAllLog1p(); }

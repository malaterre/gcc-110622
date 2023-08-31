#include "hwy/contrib/math/math-inl.h"
#include "hwy/tests/test_util-inl.h"
namespace hwy {
namespace N_EMU128 {
template <class a, class b> a al(b c) {
  a f;
  CopyBytes<sizeof(f)>(&c, &f);
  return f;
}
template <class e, class h>
void am(e an(e), Vec<h> g(h, VecArg<Vec<h>>), h d, e k, e i, uint64_t j) {
  using l = MakeUnsigned<e>;
  l m(k), n = al<l>(i), s(4000);
  l o[][2]{{m, n}};
  uint64_t p = 0;
  for (int ao = 0; ao < 1; ++ao) {
    l ap = o[ao][0], aq = o[ao][1], ar(s);
    for (l as = ap; as <= aq; as += ar) {
      e q = al<e>(as), ab = an(q);
      VFromD<h> r = Set(d, q);
      e aa = GetLane(g(d, r));
      auto ac = hwy::detail::ComputeUlpDelta(aa, ab);
      p = p ?: ac;
    }
  }
  if (!(p <= j))
    Abort("", 9, "r <= m");
}
struct t {
  template <class e, class h> void operator()(e, h d) {
    am(log1p, CallLog1p, d, 0.0f, 1e37f, 3);
  }
};
void u() { ForFloatTypes(ForPartialVectors<t>()); }
} // namespace N_EMU128
} // namespace hwy
int main() { hwy::N_EMU128::u(); }

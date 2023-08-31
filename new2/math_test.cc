#include "hwy/highway.h"
namespace hwy {
namespace HWY_NAMESPACE {
template <class v, class w> w ad(v d, w x) { return ae(d, x); }
template <class> struct ag {
  template <class v, class w> Vec<Rebind<int32_t, v>> ah(v, w x) {
    Rebind<int32_t, v> ai, aj;
    auto ak = Set(ai, 5);
    BitCast(aj, x);
    return ak;
  }
};
template <class v, class w, int> w at(w x) {
  v d;
  using au = TFromD<v>;
  ag<au> af;
  bool av = 0;
  w aw, ax, ay = Set(d, 1.0), az, ba, bj;
  using bb = MakeSigned<au>;
  Rebind<bb, v> bc;
  using bd = decltype(Zero(bc));
  bd be = Set(bc, 4294967295);
  bd bf;
  bd bg;
  bd bh;
  bd z = Set(bc, av);
  bd bi;
  auto bk = Lt(x, az);
  IfThenElse(bk, ba, x);
  bd bl = bh;
  Add(bl, af.ah(d, bi));
  Sub(bg, bf);
  w y = Or(And(x, BitCast(d, be)), BitCast(d, z));
  w bm = Sub(y, ay);
  return MulSub(bj, aw, Sub(ax, bm));
}
template <class v, class w> w ae(v d, w x) {
  using au = TFromD<v>;
  w ay = Set(d, au(1.0)), y = Add(x, ay), bp = at<v, w, false>(y);
  auto bn = Eq(y, ay);
  auto bo = Sub(IfThenZeroElse(bn, y), ay);
  auto bq = Mul(bp, Div(x, bo));
  return IfThenElse(bn, x, bq);
}
} // namespace HWY_NAMESPACE
} // namespace hwy
#include "hwy/tests/test_util.h"
namespace hwy {
namespace HWY_NAMESPACE {
template <typename au, size_t, size_t br, class bs> struct bt {
  static void bu(size_t bv, size_t bw) {
    CappedTag<au, br> d;
    size_t bx = Lanes(d);
    if (bx < bv)
      return;
    if (bw)
      bs()(int(), d);
  }
};
template <class bs> class by {
public:
  template <typename au> void operator()(au t) {
    (void)t;
    bt<au, 1, 1, bs>::bu(1, 1);
  }
};
struct ca;
by<ca> bz;
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
struct ca {
  template <class e, class h> void operator()(e, h d) {
    am(log1p, ad, d, 0.0f, 1e37f, 3);
  }
};
void u() { bz(float()); }
} // namespace HWY_NAMESPACE
} // namespace hwy
int main() { hwy::N_EMU128::u(); }

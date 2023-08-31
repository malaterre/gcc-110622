#include "hwy/ops/emu128-inl.h"
template <class bi> using bj = decltype(Zero(bi()));
template <class bk> bk bl(bk a, bk b) { return a + b; }
template <class bk> bk bm(bk a, bk b) { return a - b; }
template <class bk> bk bg(bk a, bk b) { return a * b; }
template <class bk> bk bo(bk a, bk b) { return a / b; }
template <class bk> auto bp(bk a, bk b) { return a == b; }
int af, ah;
namespace hwy {
template <typename ai> int aj(ai ak, ai actual) {
  CopySameSize(&ak, &af);
  CopySameSize(&actual, &ah);
  int aw = ah - HWY_MIN(af, ah);
  return aw;
}
namespace N_EMU128 {
template <class v, class w> w ad(v d, w x) { return ae(d, x); }
template <class v, class w> w ae(v d, w x) {
  using ag = TFromD<v>;
  w ay = Set(d, ag(1.0)), y = bl(x, ay), at(y);
  auto au = bp(y, ay);
  auto av = bm(IfThenZeroElse(au, y), ay);
  auto ax = bg(at, bo(x, av));
  return IfThenElse(au, x, ax);
}
template <typename ag, size_t, size_t az, class ba> struct bb {
  static void bc(size_t bd, size_t be) {
    CappedTag<ag, az> d;
    size_t bf = Lanes(d);
    if (bf < bd)
      return;
    if (be)
      ba()(int(), d);
  }
};
template <class ba> class z {
public:
  template <typename ag> void operator()(ag t) {
    (void)t;
    bb<ag, 1, 1, ba>::bc(1, 1);
  }
};
struct bn;
z<bn> bh;
template <class a, class b> a al(b c) {
  a f;
  CopyBytes<sizeof(f)>(&c, &f);
  return f;
}
template <class e, class h>
void am(e an(e), bj<h> g(h, VecArg<bj<h>>), h d, e k, e i, uint64_t j) {
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
      auto ac = aj(aa, ab);
      p = p ?: ac;
    }
  }
  if (!(p <= j))
    Abort("", 9, "r <= m");
}
struct bn {
  template <class e, class h> void operator()(e, h d) {
    am(log1p, ad, d, 0.0f, 1e37f, 3);
  }
};
void u() { bh(float()); }
} // namespace N_EMU128
} // namespace hwy
int main() { hwy::N_EMU128::u(); }

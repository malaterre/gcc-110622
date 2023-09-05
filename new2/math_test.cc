#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void az(aj c, an p2) {
  __builtin_memcpy(p2, c, ai);
}
template <typename aj, typename an> void ba(aj *c, an p2) {
  az<sizeof(aj)>(c, p2);
}
template <typename bb> struct e {
  using bc = bb;
  template <typename bd> using be = e<bd>;
};
template <class bc, class bf> using be = typename bf::template be<bc>;
template <typename bn> struct bo {
  using bq = bn;
  bn br[sizeof(bn)];
};
struct g {
  static int m_fn1(bool c) { return c ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class bv> bo<typename bv::bc> bw(bv) {
  bo<typename bv::bc> u;
  return u;
}
template <class bv> using bx = decltype(bw(bv()));
template <class bv, class by> bx<bv> bz(bv, by p2) {
  bx<bv> ca;
  ba(&p2, &ca);
  return ca;
}
template <class bv, typename cb> bx<bv> cc(bv c, cb p2) {
  (void)c;
  bx<bv> u;
  u.br[0] = p2;
  return u;
}
bo<float> cd(bo<float> c, bo<float> p2) {
  e<float> d;
  be<uint32_t, e<float>> ce;
  auto au = bz(ce, c), bu = bz(ce, p2);
  au.br[0] &= bu.br[0];
  return bz(d, au);
}
bo<float> cf(bo<float> c, bo<float> p2) {
  e<float> d;
  be<uint32_t, e<float>> ce;
  auto au = bz(ce, c), bu = bz(ce, p2);
  au.br[0] |= bu.br[0];
  return bz(d, au);
}
bo<float> cg(bo<float> c, bo<float> p2, bo<float> p3) {
  bo ch = cd(c, p2);
  return cf(ch, p3);
}
bo<float> ci(g c) {
  bo<float> u;
  ba(&c, &u);
  return u;
}
bo<float> cj(g c, bo<float> p2, bo<float> p3) {
  bo ck = ci(c);
  return cg(ck, p2, p3);
}
bo<float> cl;
bo<float> cr(bo<float> c) {
  e<float> d;
  bo t = bw(d);
  return cg(cl, t, c);
}
bo<float> cm(bo<float> c, bo<float> p2) {
  c.br[0] += p2.br[0];
  return c;
}
bo<float> cn(bo<float> c, bo<float> p2) {
  c.br[0] -= p2.br[0];
  return c;
}
bo<float> operator-(bo<float> c, bo<float> p2) { return cn(c, p2); }
bo<float> operator+(bo<float> c, bo<float> p2) { return cm(c, p2); }
bo<float> co(bo<float> c, bo<float> p2) {
  c.br[0] = p2.br[0];
  return c;
}
bo<float> operator*(bo<float> c, bo<float> p2) { return co(c, p2); }
g operator==(bo<float> c, bo<float> p2) {
  g m;
  m.bits[0] = g::m_fn1(c.br[0] == p2.br[0]);
  return m;
}
template <class bi> using bj = decltype(bw(bi()));
bo<float> bl(bo<float> c, bo<float> p2) { return c + p2; }
bo<float> bm(bo<float> c, bo<float> p2) { return c - p2; }
bo<float> bg(bo<float> c, bo<float> p2) { return c * p2; }
auto bp(bo<float> c, bo<float> p2) { return c == p2; }
int af, ah;
template <class u, class w> w ad(u c, w p2) {
  using ag = typename u::bc;
  w ay = cc(c, ag(1.0)), x = bl(p2, ay), at;
  auto au = bp(x, ay);
  bo cp = cr(x);
  auto av = bm(cp, ay);
  auto ax = bg(at, av);
  return cj(au, p2, ax);
}
template <class a, class b> a al(b c) {
  a f;
  az<sizeof(f)>(&c, &f);
  return f;
}
void am(bj<e<float>> c(e<float>, bj<e<float>>), e<float> p2) {
  float k = 0.0f, i = 1e37f;
  uint64_t j = 2;
  using l = uint32_t;
  l m(k);
  l n = al<l>(i);
  l s(4000);
  l o[][2]{{m, n}};
  uint64_t p = 0;
  for (int ao = 0; ao < 1; ++ao) {
    l ap = m;
    l aq = o[ao][1];
    l ar(s);
    for (l as = ap; as <= aq; as += ar) {
      float q = al<float>(as), ab(q);
      bx<e<float>> r = cc(p2, q), cq = c(p2, r);
      float aa = cq.br[0];
      float ak = aa, actual = ab;
      ba(&ak, &af);
      ba(&actual, &ah);
      int aw = ah - ae(af, ah);
      auto ac = aw;
      p = p ?: ac;
    }
  }
  if (!(p <= j))
    abort();
}
int main() {
  e<float> d;
  am(ad, d);
}

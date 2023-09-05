#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void az(aj c, an g) {
  __builtin_memcpy(g, c, ai);
}
template <typename aj, typename an> void ba(aj *c, an g) {
  az<sizeof(aj)>(c, g);
}
template <typename bb> struct e {
  using bc = bb;
  template <typename bd> using be = e<bd>;
};
template <class bc, class bf> using be = typename bf::template be<bc>;
template <typename bh> struct bi {
  bh bj[sizeof(bh)];
};
struct A {
  static int m_fn1(bool c) { return c ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class bk> bi<typename bk::bc> bn(bk) {
  bi<typename bk::bc> u;
  return u;
}
template <class bk> using bo = decltype(bn(bk()));
template <class bk, class bq> bo<bk> br(bk, bq g) {
  bo<bk> bs;
  ba(&g, &bs);
  return bs;
}
template <class bk, typename bt> bo<bk> bv(bk c, bt g) {
  (void)c;
  bo<bk> u;
  u.bj[0] = g;
  return u;
}
bi<float> bw(bi<float> c, bi<float> g) {
  e<float> d;
  be<uint32_t, e<float>> bx;
  auto au = br(bx, c), bu = br(bx, g);
  au.bj[0] &= bu.bj[0];
  return br(d, au);
}
bi<float> by(bi<float> c, bi<float> g) {
  e<float> d;
  be<uint32_t, e<float>> bx;
  auto au = br(bx, c), bu = br(bx, g);
  au.bj[0] |= bu.bj[0];
  return br(d, au);
}
bi<float> bz(bi<float> c, bi<float> g, bi<float> z) {
  bi ca = bw(c, g);
  return by(ca, z);
}
bi<float> cb(A c) {
  bi<float> u;
  ba(&c, &u);
  return u;
}
bi<float> cc(A c, bi<float> g, bi<float> z) {
  bi cd = cb(c);
  return bz(cd, g, z);
}
bi<float> cf(bi<float> c) {
  e<float> d;
  bi t = bn(d);
  return bz(c, t, c);
}
bi<float> cg(bi<float> c, bi<float> g) {
  c.bj[0] += g.bj[0];
  return c;
}
bi<float> ch(bi<float> c, bi<float> g) {
  c.bj[0] -= g.bj[0];
  return c;
}
bi<float> operator-(bi<float> c, bi<float> g) { return ch(c, g); }
bi<float> operator+(bi<float> c, bi<float> g) { return cg(c, g); }
bi<float> ci(bi<float> c, bi<float> g) {
  c.bj[0] = g.bj[0];
  return c;
}
bi<float> operator*(bi<float> c, bi<float> g) { return ci(c, g); }
A operator==(bi<float> c, bi<float> g) {
  A m;
  m.bits[0] = A::m_fn1(c.bj[0] == g.bj[0]);
  return m;
}
bi<float> bl(bi<float> c, bi<float> g) { return c + g; }
bi<float> bm(bi<float> c, bi<float> g) { return c - g; }
bi<float> bg(bi<float> c, bi<float> g) { return c * g; }
auto bp(bi<float> c, bi<float> g) { return c == g; }
int af, ah;
template <class u, class w> w ad(u c, w g) {
  using ag = typename u::bc;
  w ay = bv(c, ag(1.0)), v = bl(g, ay), at;
  auto au = bp(v, ay);
  bi cj = cf(v);
  auto av = bm(cj, ay);
  auto ax = bg(at, av);
  return cc(au, g, ax);
}
template <class a, class b> a al(b c) {
  a f;
  az<sizeof(f)>(&c, &f);
  return f;
}
void am(bo<e<float>> c(e<float>, bo<e<float>>), e<float> g) {
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
      bo<e<float>> r = bv(g, q), ck = c(g, r);
      float aa = ck.bj[0];
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

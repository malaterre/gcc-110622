#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void az(aj c, an p2) {
  __builtin_memcpy(p2, c, ai);
}
template <typename aj, typename an> void bc(aj *c, an p2) {
  az<sizeof(aj)>(c, p2);
}
template <typename bd> struct e {
  using be = bd;
  template <typename bf> using bh = e<bf>;
};
template <class bk> using bn = typename bk::be;
template <class be, class bk> using bh = typename bk::template bh<be>;
template <class bk> using bo = bh<uint32_t, bk>;
template <typename bq> struct br {
  using bs = bq;
  bq bt[sizeof(bq)];
};
struct g {
  static int m_fn1(bool c) { return c ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class bw> using bx = e<typename bw::bs>;
template <class by> br<bn<by>> bz(by) {
  br<bn<by>> u;
  return u;
}
template <class by> using ca = decltype(bz(by()));
template <class by, class cb> ca<by> cc(by, cb p2) {
  ca<by> cd;
  bc(&p2, &cd);
  return cd;
}
template <class by, typename ce> ca<by> cf(by c, ce p2) {
  (void)c;
  ca<by> u;
  u.bt[0] = p2;
  return u;
}
br<float> cg(br<float> c, br<float> p2) {
  bx<decltype(c)> d;
  bo<decltype(d)> ch;
  auto au = cc(ch, c), bu = cc(ch, p2);
  for (size_t i = 0; i < 1; ++i)
    au.bt[i] &= bu.bt[i];
  return cc(d, au);
}
br<float> ci(br<float> c, br<float> p2) {
  bx<decltype(c)> d;
  bo<decltype(d)> ch;
  auto au = cc(ch, c), bu = cc(ch, p2);
  for (size_t i = 0; i < 1; ++i)
    au.bt[i] |= bu.bt[i];
  return cc(d, au);
}
br<float> cj(br<float> c, br<float> p2, br<float> p3) {
  br cm = cg(c, p2);
  return ci(cm, p3);
}
br<float> cn(g c) {
  br<float> u;
  bc(&c, &u);
  return u;
}
br<float> cs(g c, br<float> p2, br<float> p3) {
  br cp = cn(c);
  return cj(cp, p2, p3);
}
br<float> z, cq = z;
br<float> cr(br<float> c) {
  bx<decltype(c)> d;
  br t = bz(d);
  return cj(cq, t, c);
}
br<float> ct(br<float> c, br<float> p2) {
  for (size_t i = 0; i < 1; ++i)
    c.bt[i] += p2.bt[i];
  return c;
}
br<float> cu(br<float> c, br<float> p2) {
  for (size_t i = 0; i < 1; ++i)
    c.bt[i] -= p2.bt[i];
  return c;
}
br<float> operator-(br<float> c, br<float> p2) { return cu(c, p2); }
br<float> operator+(br<float> c, br<float> p2) { return ct(c, p2); }
br<float> cv(br<float> c, br<float> p2) {
  for (size_t i = 0; i < 1; ++i)
    c.bt[i] = p2.bt[i];
  return c;
}
br<float> operator*(br<float> c, br<float> p2) { return cv(c, p2); }
g operator==(br<float> c, br<float> p2) {
  g m;
  for (size_t i = 0; i < 1; ++i)
    m.bits[i] = g::m_fn1(c.bt[i] == p2.bt[i]);
  return m;
}
float cw(br<float> c) { return c.bt[0]; }
template <class bi> using bj = decltype(bz(bi()));
br<float> bl(br<float> c, br<float> p2) { return c + p2; }
br<float> bm(br<float> c, br<float> p2) { return c - p2; }
br<float> bg(br<float> c, br<float> p2) { return c * p2; }
auto bp(br<float> c, br<float> p2) { return c == p2; }
int af, ah, cy;
template <class u, class w> w ad(u c, w p2) {
  using ag = bn<u>;
  w ay = cf(c, ag(1.0)), x = bl(p2, ay), at;
  auto au = bp(x, ay);
  br cx = cr(x);
  auto av = bm(cx, ay);
  auto ax = bg(at, av);
  return cs(au, p2, ax);
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
      ca<e<float>> r = cf(p2, q), cz = c(p2, r);
      float aa = cw(cz);
      {
        float ak = aa, actual = ab;
        bc(&ak, &af);
        bc(&actual, &ah);
        int aw = ah - ae(af, ah);
        cy = aw;
      }
      auto ac = cy;
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

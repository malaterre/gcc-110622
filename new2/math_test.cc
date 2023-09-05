#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void ao(aj c, an g) {
  __builtin_memcpy(g, c, ai);
}
template <typename aj, typename an> void az(aj *c, an g) {
  ao<sizeof(aj)>(c, g);
}
template <typename ba> struct e {
  using bb = ba;
  template <typename bc> using bd = e<bc>;
};
template <class bb, class be> using bd = typename be::template bd<bb>;
template <typename bf> struct bh {
  bf bi[sizeof(bf)];
};
struct i {
  static int m_fn1(bool c) { return c ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class bj> bh<typename bj::bb> bk(bj) {
  bh<typename bj::bb> k;
  return k;
}
template <class bj> using bn = decltype(bk(bj()));
template <class bj, class bo> bn<bj> br(bj, bo g) {
  bn<bj> bq;
  az(&g, &bq);
  return bq;
}
template <class bj, typename bt> bn<bj> bs(bj, bt g) {
  bn<bj> k;
  k.bi[0] = g;
  return k;
}
bh<float> bw(bh<float> c, bh<float> g) {
  e<float> d;
  bd<uint32_t, e<float>> bv;
  auto au = br(bv, c), bu = br(bv, g);
  au.bi[0] &= bu.bi[0];
  return br(d, au);
}
bh<float> by(bh<float> c, bh<float> g) {
  e<float> d;
  bd<uint32_t, e<float>> bv;
  auto au = br(bv, c), bu = br(bv, g);
  au.bi[0] |= bu.bi[0];
  return br(d, au);
}
bh<float> bx(bh<float> c, bh<float> g, bh<float> n) {
  bh ca = bw(c, g);
  return by(ca, n);
}
bh<float> bz(i c) {
  bh<float> k;
  az(&c, &k);
  return k;
}
bh<float> cc(i c, bh<float> g, bh<float> n) {
  bh cb = bz(c);
  return bx(cb, g, n);
}
bh<float> cf(bh<float> c) {
  e<float> d;
  bh o = bk(d);
  return bx(c, o, c);
}
bh<float> cd(bh<float> c, bh<float> g) {
  c.bi[0] += g.bi[0];
  return c;
}
bh<float> ce(bh<float> c, bh<float> g) {
  c.bi[0] -= g.bi[0];
  return c;
}
bh<float> operator-(bh<float> c, bh<float> g) { return ce(c, g); }
bh<float> operator+(bh<float> c, bh<float> g) { return cd(c, g); }
bh<float> cg(bh<float> c, bh<float> g) {
  c.bi[0] = g.bi[0];
  return c;
}
bh<float> operator*(bh<float> c, bh<float> g) { return cg(c, g); }
i operator==(bh<float> c, bh<float> g) {
  i m;
  m.bits[0] = i::m_fn1(c.bi[0] == g.bi[0]);
  return m;
}
bh<float> bl(bh<float> c, bh<float> g) { return c + g; }
bh<float> bm(bh<float> c, bh<float> g) { return c - g; }
bh<float> bg(bh<float> c, bh<float> g) { return c * g; }
auto bp(bh<float> c, bh<float> g) { return c == g; }
int af, ah;
template <class k, class s> s ad(k c, s g) {
  using ag = typename k::bb;
  s ay = bs(c, ag(1.0)), u = bl(g, ay), at;
  auto au = bp(u, ay);
  bh ch = cf(u);
  auto av = bm(ch, ay);
  auto ax = bg(at, av);
  return cc(au, g, ax);
}
template <class a, class b> a al(b c) {
  a f;
  ao<sizeof(f)>(&c, &f);
  return f;
}
void am(bn<e<float>> c(e<float>, bn<e<float>>), e<float> g) {
  uint64_t j = 2;
  using l = uint32_t;
  uint64_t p;
  l as = 528484000;
  float q = al<float>(as), ab(q);
  bn<e<float>> r = bs(g, q), ci = c(g, r);
  float aa = ci.bi[0];
  float ak = aa, actual = ab;
  az(&ak, &af);
  az(&actual, &ah);
  int aw = ah - ae(af, ah);
  p = aw;
  if (!(p <= j))
    abort();
}
int main() {
  e<float> d;
  am(ad, d);
}

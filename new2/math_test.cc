#include <stdio.h>
#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void ao(aj c, an p2) {
  __builtin_memcpy(p2, c, ai);
}
template <typename aj, typename an> void az(aj *c, an p2) {
  ao<sizeof(aj)>(c, p2);
}
template <typename ba> struct e {
  using bb = ba;
};
template <typename bf> struct bh {
  bf bi[sizeof(bf)];
};
struct g {
  static int m_fn1(bool c) { return c ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class bj> bh<typename bj::bb> bk(bj) {
  bh<typename bj::bb> i;
  return i;
}
template <class bj> using bn = decltype(bk(bj()));
template <class bj, class bo> bn<bj> br(bj, bo p2) {
  bn<bj> bq;
  az(&p2, &bq);
  return bq;
}
bh<float> bs(float c) {
  bh<float> i;
  i.bi[0] = c;
  return i;
}
bh<float> bw(bh<float> c, bh<float> p2) {
  e<float> d;
  e<uint32_t> bv;
  auto au = br(bv, c), bu = br(bv, p2);
  au.bi[0] &= bu.bi[0];
  return br(d, au);
}
bh<float> by(bh<float> c, bh<float> p2) {
  e<float> d;
  e<uint32_t> bv;
  auto au = br(bv, c), bu = br(bv, p2);
  au.bi[0] |= bu.bi[0];
  return br(d, au);
}
bh<float> bx(bh<float> c, bh<float> p2, bh<float> k) {
  bh ca = bw(c, p2);
  return by(ca, k);
}
bh<float> bz(g c) {
  bh<float> i{};
  printf("bz0: %d %g\n", c.bits[0], i.bi[0]);
  az(&c, &i);
  printf("bz1: %d %g\n", c.bits[0], i.bi[0]);
  return i;
}
bh<float> cc(g c, bh<float> p2, bh<float> k) {
  printf("cc0: %d\n", c.bits[0]);
  bh cb = bz(c);
  printf("cc1: %g\n", cb.bi[0]);
  return bx(cb, p2, k);
}
bh<float> cf(bh<float> c) {
  e<float> d;
  bh o = bk(d);
  return bx(c, o, c);
}
bh<float> cd(bh<float> c, bh<float> p2) {
  c.bi[0] += p2.bi[0];
  return c;
}
bh<float> ce(bh<float> c, bh<float> p2) {
  c.bi[0] -= p2.bi[0];
  return c;
}
bh<float> operator-(bh<float> c, bh<float> p2) { return ce(c, p2); }
bh<float> operator+(bh<float> c, bh<float> p2) { return cd(c, p2); }
bh<float> cg(bh<float> c, bh<float> p2) {
  c.bi[0] = p2.bi[0];
  return c;
}
bh<float> operator*(bh<float> c, bh<float> p2) { return cg(c, p2); }
g operator==(bh<float> c, bh<float> p2) {
  g m;
  m.bits[0] = g::m_fn1(c.bi[0] == p2.bi[0]);
  return m;
}
bh<float> bl(bh<float> c, bh<float> p2) { return c + p2; }
bh<float> bm(bh<float> c, bh<float> p2) { return c - p2; }
bh<float> bg(bh<float> c, bh<float> p2) { return c * p2; }
auto bp(bh<float> c, bh<float> p2) { return c == p2; }
int af, ah;
template <class i, class n> n ad(i, n p2) {
  using ag = typename i::bb;
  n ay = bs(ag(1.0)), u = bl(p2, ay), at;
//  printf("au0: %g %g \n", u.bi[0], ay.bi[0]);
  auto au = bp(u, ay);
  printf("au1: %d \n", au.bits[0]);
  bh ch = cf(u);
  auto av = bm(ch, ay);
  auto ax = bg(at, av);
  printf("ad1: %g %g\n", av.bi[0], ax.bi[0]);
  return cc(au, p2, ax);
}
template <class a, class b> a al(b c) {
  a f;
  ao<sizeof(f)>(&c, &f);
  return f;
}
void am(bh<float> c(e<float>, bh<float>) ) {
 e<float> p2 ;
  uint32_t as = 528484000;
  float q = al<float>(as), ab(q);
  bh r = bs(q), ci = c(p2, r);
  printf("0: %g\n", r.bi[0]);
  float ak = ci.bi[0];
  printf("1: %g %d %d\n", ak, af, ah);
  az(&ak, &af);
  printf("2: %g %d %d\n", ak, af, ah);
  az(&ab, &ah);
  printf("3: %g %d %d\n", ak, af, ah);
  int aw = ah - ae(af, ah);
  uint64_t  p = aw;
  if (!(p <= 2))
    abort();
}
int main() {
  am(ad );
}

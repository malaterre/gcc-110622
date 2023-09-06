#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void ao(aj c, an p2) {
  __builtin_memcpy(p2, c, ai);
}
template <typename aj, typename an> void az(aj *c, an p2) {
  ao<sizeof(aj)>(c, p2);
}
template <typename> struct e {};
template <typename bf> struct bh {
  bf bi[sizeof(bf)];
};
int m_fn1(bool c) { return c ? ~int{} : 0; }
struct g {
  int bits[sizeof(int)];
};
bh<float> bk(e<float>) {
  bh<float> i;
  return i;
}
template <typename T1, typename T2> bh<T1> br(e<T1>, T2 p2) {
  bh<T1> bq;
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
  bh<float> ca = bw(c, p2);
  return by(ca, k);
}
bh<float> bz(g c) {
  bh<float> i;
  az(&c, &i);
  return i;
}
bh<float> cc(g c, bh<float> p2, bh<float> k) {
  bh<float> cb = bz(c);
  return bx(cb, p2, k);
}
bh<float> cf(bh<float> c) {
  e<float> d;
  bh<float> o = bk(d);
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
  m.bits[0] = m_fn1(c.bi[0] == p2.bi[0]);
  return m;
}
bh<float> bl(bh<float> c, bh<float> p2) { return c + p2; }
bh<float> bm(bh<float> c, bh<float> p2) { return c - p2; }
bh<float> bg(bh<float> c, bh<float> p2) { return c * p2; }
g bp(bh<float> c, bh<float> p2) { return c == p2; }
bh<float> ad_ay = bs(1.0);
bh<float> ad(e<float>, bh<float> p2) {
  bh<float> u = bl(p2, ad_ay), at;
  auto au = bp(u, ad_ay);
  bh<float> ch = cf(u);
  auto av = bm(ch, ad_ay);
  auto ax = bg(at, av);
  return cc(au, p2, ax);
}
template <class a, class b> a al(b c) {
  a f;
  ao<sizeof(f)>(&c, &f);
  return f;
}
int main_af;
int main() {
  int ah, as = 528484000;
  e<float> p2;
  float q = al<float>(as), ab(q);
  bh<float> r = bs(q), ci = ad(p2, r);
  float ak = ci.bi[0];
  az(&ak, &main_af);
  az(&ab, &ah);
  int aw = ah - ae(main_af, ah);
  uint64_t p = aw;
  if (!(p <= 2))
    abort();
}

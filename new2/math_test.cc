#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t ai, typename aj, typename an> void ao(aj c, an p2) {
  __builtin_memcpy(p2, c, ai);
}
template <typename aj, typename an> void az(aj *c, an p2) {
  ao<sizeof(aj)>(c, p2);
}
struct e {};
template <typename bf> struct bh {
  bf bi[sizeof(bf)];
};
int m_fn1(bool c) { return c ? ~int{} : 0; }
struct g {
  int bits[sizeof(int)];
};
template <typename T1, typename T2> bh<T1> br(T2 p2) {
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
  auto au = br<uint32_t>(c), bu = br<uint32_t>(p2);
  au.bi[0] &= bu.bi[0];
  return br<float>(au);
}
bh<float> by(bh<float> c, bh<float> p2) {
  auto au = br<uint32_t>(c), bu = br<uint32_t>(p2);
  au.bi[0] |= bu.bi[0];
  return br<float>(au);
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
  bh<float> o;
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
bh<float> cg(bh<float> c, bh<float> p2) {
  c.bi[0] = p2.bi[0];
  return c;
}
bh<float> plus(bh<float> c, bh<float> p2) { return cd(c, p2); }
bh<float> minus(bh<float> c, bh<float> p2) { return ce(c, p2); }
bh<float> mult(bh<float> c, bh<float> p2) { return cg(c, p2); }
g equal(bh<float> c, bh<float> p2) {
  g m;
  m.bits[0] = m_fn1(c.bi[0] == p2.bi[0]);
  return m;
}
bh<float> ad_ay = bs(1.0);
bh<float> ad(e, bh<float> p2) {
  bh<float> u = plus(p2, ad_ay), at;
  auto au = equal(u, ad_ay);
  bh<float> ch = cf(u);
  auto av = minus(ch, ad_ay);
  auto ax = mult(at, av);
  return cc(au, p2, ax);
}
float al_f;
float al(int c) {
  ao<sizeof(al_f)>(&c, &al_f);
  return al_f;
}
int main_af;
float main_q = al(528484000);
float main_ab = main_q;
bh<float> main_r = bs(main_q);
int main() {
  int ah;
  e p2;
  bh<float> ci = ad(p2, main_r);
  float ak = ci.bi[0];
  az(&ak, &main_af);
  az(&main_ab, &ah);
  int aw = ah - ae(main_af, ah);
  uint64_t p = aw;
  if (!(p <= 2))
    abort();
}

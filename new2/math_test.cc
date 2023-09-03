#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t az, typename ba, typename bb> void bc(ba bd, bb be) {
  __builtin_memcpy(be, static_cast<void *>(bd), az);
}
template <typename ba, typename bb> void bf(ba *bd, bb be) {
  bc<sizeof(ba)>(bd, be);
}
template <typename bh> struct y {
  using bn = bh;
  template <typename bo> using bv = y<bo>;
};
template <class by> using de = typename by::bn;
template <class bn, class by> using bv = typename by::template bv<bn>;
template <class by> using cz = bv<uint32_t, by>;
template <typename bq > struct bs {
  using bt = bq;
  bq bw[sizeof(bq)]{};
};
template <typename bq, size_t = sizeof(bq)> struct bx {
  static int z(bool b) { return b ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class ca> using cb = y<typename ca::bt>;
template <class bz> bs<de<bz>> cc(bz) {
  bs<de<bz>> u;
  return u;
}
template <class bz> using cd = decltype(cc(bz()));
template <class bz, class ce> cd<bz> cf(bz, ce u) {
  cd<bz> cg;
  bf(&u, &cg);
  return cg;
}
template <class bz, typename ch> cd<bz> ci(bz d, ch t) {
  (void)d;
  cd<bz> u;
  u.bw[0] = t;
  return u;
}
template <typename bq > bs<bq > cj(bs<bq> a, bs<bq> b) {
  cb<decltype(a)> d;
  cz<decltype(d)> ck;
  auto au = cf(ck, a), bu = cf(ck, b);
  for (size_t i = 0; i < 1; ++i)
    au.bw[i] &= bu.bw[i];
  return cf(d, au);
}
template <typename bq > bs<bq> cl(bs<bq> a, bs<bq> b) {
  cb<decltype(a)> d;
  cz<decltype(d)> ck;
  auto au = cf(ck, a), bu = cf(ck, b);
  for (size_t i = 0; i < 1; ++i)
    au.bw[i] |= bu.bw[i];
  return cf(d, au);
}
template <typename bq >
bs<bq> cn(bs<bq> cm, bs<bq> cr, bs<bq> co) {
  bs cq = cj(cm, cr);
  return cl(cq, co);
}
template <typename bq > bs<bq> cp(bx<bq> cm) {
  bs<bq> u;
  bf(&cm, &u);
  return u;
}
template <typename bq >
bs<bq> cs(bx<bq> cm, bs<bq> cr, bs<bq> co) {
  bs da = cp(cm);
  return cn(da, cr, co);
}
template <typename bq > bs<bq> cu(bx<bq> cm, bs<bq> co) {
  cb<decltype(co)> d;
  bs ct = cp(cm);
  return cn(ct, cc(d), co);
}
template <typename bq > bs<bq> cw(bs<bq> a, bs<bq> b) {
  for (size_t i = 0; i < 1; ++i)
    a.bw[i] += b.bw[i];
  return a;
}
template <typename bq > bs<bq> cv(bs<bq> a, bs<bq> b) {
  for (size_t i = 0; i < 1; ++i)
    a.bw[i] -= b.bw[i];
  return a;
}
template <typename bq >
bs<bq> operator-(bs<bq> a, bs<bq> b) {
  return cv(a, b);
}
template <typename bq >
bs<bq> operator+(bs<bq> a, bs<bq> b) {
  return cw(a, b);
}
template <typename bq > bs<bq> cx(bs<bq> a, bs<bq> b) {
  for (size_t i = 0; i < 1; ++i)
    a.bw[i] = b.bw[i];
  return a;
}
template <typename bq >
bs<bq> operator*(bs<bq> a, bs<bq> b) {
  return cx(a, b);
}
template <typename bq>
bx<bq> operator==(bs<bq> a, bs<bq> b) {
  bx<bq> m;
  for (size_t i = 0; i < 1; ++i)
    m.bits[i] = bx<int>::z(a.bw[i] == b.bw[i]);
  return m;
}
template <typename bq > bq cy(bs<bq> u) { return u.bw[0]; }
template <class bi> using bj = decltype(cc(bi()));
template <class bk> bk bl(bk a, bk b) { return a + b; }
template <class bk> bk bm(bk a, bk b) { return a - b; }
template <class bk> bk bg(bk a, bk b) { return a * b; }
template <class bk> auto bp(bk a, bk b) { return a == b; }
int af, ah;
template <typename ai> int aj(ai ak, ai actual) {
  bf(&ak, &af);
  bf(&actual, &ah);
  int aw = ah - ae(af, ah);
  return aw;
}
template <class u, class w> w ad(u d, w v) {
  using ag = de<u>;
  w ay = ci(d, ag(1.0)), x = bl(v, ay), at;
  auto au = bp(x, ay);
  auto av = bm(cu(au, x), ay);
  auto ax = bg(at, av);
  return cs(au, v, ax);
}
template <class a, class b> a al(b c) {
  a f;
  bc<sizeof(f)>(&c, &f);
  return f;
}
template < class h>
void am( bj<h> g(h, bj<h>), h d ) {
float k = 0.0f;  float i = 1e37f;  uint64_t j = 2;
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
      float q = al<float>(as), ab = log1p(q);
      cd<h> r = ci(d, q);
      float aa = cy(g(d, r));
      auto ac = aj(aa, ab);
      p = p ?: ac;
    }
  }
  if (!(p <= j))
    abort();
}
int main() {
    y<float> d;
    //am( ad, d, 0.0f, 1e37f, 2);
    am( ad, d) ;
}

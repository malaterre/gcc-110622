#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <size_t az, typename ba, typename bh> void bn(ba bo, bh by) {
  __builtin_memcpy(by, static_cast<void *>(bo), az);
}
template <typename ba, typename bh> void cz(ba *bo, bh by) {
  bn<sizeof(ba)>(bo, by);
}
template <typename db> struct z {
  using dc = db;
  template <typename dd> using de = z<dd>;
};
template <class di> using dj = typename di::dc;
template <class dc, class di> using de = typename di::template de<dc>;
template <class di> using dl = de<uint32_t, di>;
template <typename bq, size_t> struct bs {
  using bt = bq;
  bq bw[sizeof(bq)]{};
};
template <typename bq, size_t = sizeof(bq)> struct bx {
  static int bv(bool b) { return b ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class ca> using cb = z<typename ca::bt>;
template <class bz> bs<dj<bz>, 1> cc(bz) {
  bs<dj<bz>, 1> u;
  return u;
}
template <class bz> using cd = decltype(cc(bz()));
template <class bz, class ce> cd<bz> cf(bz, ce u) {
  cd<bz> cg;
  cz(&u, &cg);
  return cg;
}
template <class bz, typename ch> cd<bz> ci(bz d, ch t) {
  (void)d;
  cd<bz> u;
    u.bw[0] = t;
  return u;
}
template <typename bq, size_t br> bs<bq, br> cj(bs<bq, br> a, bs<bq, br> b) {
  cb<decltype(a)> d;
  dl<decltype(d)> ck;
  auto au = cf(ck, a), bu = cf(ck, b);
  for (size_t i = 0; i < br; ++i)
    au.bw[i] &= bu.bw[i];
  return cf(d, au);
}
template <typename bq, size_t br> bs<bq, br> cl(bs<bq, br> a, bs<bq, br> b) {
  cb<decltype(a)> d;
  dl<decltype(d)> ck;
  auto au = cf(ck, a), bu = cf(ck, b);
  for (size_t i = 0; i < br; ++i)
    au.bw[i] |= bu.bw[i];
  return cf(d, au);
}
template <typename bq, size_t br>
bs<bq, br> cn(bs<bq, br> cm, bs<bq, br> cr, bs<bq, br> co) {
  bs cq = cj(cm, cr);
  return cl(cq, co);
}
template <typename bq, size_t br> bs<bq, br> cp(bx<bq, br> cm) {
  bs<bq, br> u;
  cz(&cm, &u);
  return u;
}
template <typename bq, size_t br>
bs<bq, br> cs(bx<bq, br> cm, bs<bq, br> cr, bs<bq, br> co) {
  bs da = cp(cm);
  return cn(da, cr, co);
}
template <typename bq, size_t br> bs<bq, br> cu(bx<bq, br> cm, bs<bq, br> co) {
  cb<decltype(co)> d;
  bs ct = cp(cm);
  return cn(ct, cc(d), co);
}
template <typename bq, size_t br> bs<bq, br> cw(bs<bq, br> a, bs<bq, br> b) {
  for (size_t i = 0; i < br; ++i)
    a.bw[i] += b.bw[i];
  return a;
}
template <typename bq, size_t br> bs<bq, br> cv(bs<bq, br> a, bs<bq, br> b) {
  for (size_t i = 0; i < br; ++i)
    a.bw[i] -= b.bw[i];
  return a;
}
template <typename bq, size_t br>
bs<bq, br> operator-(bs<bq, br> a, bs<bq, br> b) {
  return cv(a, b);
}
template <typename bq, size_t br>
bs<bq, br> operator+(bs<bq, br> a, bs<bq, br> b) {
  return cw(a, b);
}
template <typename bq, size_t br> bs<bq, br> cx(bs<bq, br> a, bs<bq, br> b) {
  for (size_t i = 0; i < br; ++i)
    a.bw[i] = b.bw[i];
  return a;
}
template <typename bq, size_t br>
bs<bq, br> operator*(bs<bq, br> a, bs<bq, br> b) {
  return cx(a, b);
}
template <typename bq, size_t br>
bx<bq, br> operator==(bs<bq, br> a, bs<bq, br> b) {
  bx<bq, br> m;
  for (size_t i = 0; i < br; ++i)
    m.bits[i] = bx<int>::bv(a.bw[i] == b.bw[i]);
  return m;
}
template <typename bq, size_t br> bq cy(bs<bq, br> u) { return u.bw[0]; }
template <class bi> using bj = decltype(cc(bi()));
template <class bk> bk bl(bk a, bk b) { return a + b; }
template <class bk> bk bm(bk a, bk b) { return a - b; }
template <class bk> bk bg(bk a, bk b) { return a * b; }
template <class bk> auto bp(bk a, bk b) { return a == b; }
int af, ah;
template <typename ai> int aj(ai ak, ai actual) {
  cz(&ak, &af);
  cz(&actual, &ah);
  int aw = ah - ae(af, ah);
  return aw;
}
template <class u, class w> w ad(u d, w v) {
  using ag = dj<u>;
  w ay = ci(d, ag(1.0)), x = bl(v, ay), at;
  auto au = bp(x, ay);
  auto av = bm(cu(au, x), ay);
  auto ax = bg(at, av);
  return cs(au, v, ax);
}
template <class h> void y(h d) { am(log1p, ad, d, 0.0f, 1e37f, 3); }
template <size_t> struct bb {
  static void bc(size_t bd, size_t be) {
 z<float>
     d;
    size_t bf = 1;
    if (bf < bd)
      return;
    if (be)
      y(d);
  }
};
template <class a, class b> a al(b c) {
  a f;
  bn<sizeof(f)>(&c, &f);
  return f;
}
template <class e, class h>
void am(e an(e), bj<h> g(h, bj<h>), h d, e k, e i, uint64_t j) {
  using l = uint32_t;
  l m(k), n = al<l>(i), s(4000);
  l o[][2]{{m, n}};
  uint64_t p = 0;
  for (int ao = 0; ao < 1; ++ao) {
    l ap = m, aq = o[ao][1], ar(s);
    for (l as = ap; as <= aq; as += ar) {
      e q = al<e>(as), ab = an(q);
      cd<h> r = ci(d, q);
      e aa = cy(g(d, r));
      auto ac = aj(aa, ab);
      p = p ?: ac;
    }
  }
  if (!(p <= j))
    abort();
}
int main() { bb<1>::bc(1, 1); }

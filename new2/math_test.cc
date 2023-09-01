#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
using bo = uint32_t;
template <size_t cz, typename db, typename dc> void ec(db dg, dc dh) {
  __builtin_memcpy(dh, static_cast<void *>(dg), cz);
}
template <typename db, typename dc> void dl(db *dg, dc dh) {
  ec<sizeof(db)>(dg, dh);
}
template <typename de, size_t, int> struct di {
  using dj = de;
  static constexpr size_t dm = 1;
  static constexpr int dk() { return 0; }
  static constexpr size_t ds() { return 0; }
  template <typename dt> using dn = di<dt, ds(), dk()>;
};
namespace dd {
template <typename dj > struct dv {
  using dw = di<dj, 6, 3>;
};
template <typename dj, int du> struct dy {
  static constexpr size_t df = 0;
  using dw = typename dv<dj >::dw;
};
} // namespace dd
template <typename dj, size_t dx, int du = 0>
using ea = typename dd::dy<dj, du>::dw;
template <class dz> using eb = typename dz::dj;
template <class dz> size_t dp(dz) { return dz::dm; }
template <class dz> size_t dq(dz) { return dz::dm; }
template <class dj, class dz> using dn = typename dz::template dn<dj>;
template <class dz> using dr = dn<bo, dz>;
template <typename bq, size_t br> struct bs {
  using bt = bq;
  static constexpr size_t bn = br;
  bq bw[sizeof(bq)]{};
};
template <typename bq, size_t = sizeof(bq)> struct bx {
  static int bv(bool b) { return b ? ~int{} : 0; }
  int bits[sizeof(int)];
};
template <class ca> using cb = di<typename ca::bt, ca::bn, 0>;
template <class bz> bs<eb<bz>, bz::dm> cc(bz) {
  bs<eb<bz>, bz::dm> u;
  return u;
}
template <class bz> using cd = decltype(cc(bz()));
template <class bz, class ce> cd<bz> cf(bz, ce u) {
  cd<bz> cg;
  dl(&u, &cg);
  return cg;
}
template <class bz, typename ch> cd<bz> ci(bz d, ch t) {
  cd<bz> u;
  for (size_t i = 0; i < dp(d); ++i)
    u.bw[i] = t;
  return u;
}
template <typename bq, size_t br> bs<bq, br> cj(bs<bq, br> a, bs<bq, br> b) {
  cb<decltype(a)> d;
  dr<decltype(d)> ck;
  auto au = cf(ck, a), bu = cf(ck, b);
  for (size_t i = 0; i < br; ++i)
    au.bw[i] &= bu.bw[i];
  return cf(d, au);
}
template <typename bq, size_t br> bs<bq, br> cl(bs<bq, br> a, bs<bq, br> b) {
  cb<decltype(a)> d;
  dr<decltype(d)> ck;
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
  dl(&cm, &u);
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
  dl(&ak, &af);
  dl(&actual, &ah);
  int aw = ah - ae(af, ah);
  return aw;
}
template <class u, class w> w ad(u d, w v) {
  using ag = eb<u>;
  w ay = ci(d, ag(1.0)), x = bl(v, ay), at;
  auto au = bp(x, ay);
  auto av = bm(cu(au, x), ay);
  auto ax = bg(at, av);
  return cs(au, v, ax);
}
template <typename ag, size_t az, class ba> struct bb {
  static void bc(size_t bd, size_t be) {
    ea<ag, az> d;
    size_t bf = dq(d);
    if (bf < bd)
      return;
    if (be)
      ba()(int(), d);
  }
};
template <class ba> class y {
public:
  template <typename ag> void operator()(ag t) {
    (void)t;
    bb<ag, 1, ba>::bc(1, 1);
  }
};
struct z {
  template <class e, class h> void operator()(e, h d) {
    am(log1p, ad, d, 0.0f, 1e37f, 3);
  }
};
y<z> bh;
template <class a, class b> a al(b c) {
  a f;
  ec<sizeof(f)>(&c, &f);
  return f;
}
template <class e, class h>
void am(e an(e), bj<h> g(h, bj<h>), h d, e k, e i, uint64_t j) {
  using l = bo;
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
int main() { bh(float()); }

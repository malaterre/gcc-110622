typedef int a;
typedef long long b;
extern "C" {
double log1p(double);
typedef b c;
void exit(int);
}
namespace {
template <typename ai, typename, template <typename> class> struct aj {
  using e = ai;
};
template <typename ai, template <typename> class ak>
using ab = aj<ai, void, ak>;
template <typename ai, template <typename> class ak>
using ac = typename ab<ai, ak>::e;
} // namespace
namespace ad {
template <typename ae, typename> class af {
  ae ag;

public:
  af(ae ah) : ag(ah) {}
  c operator*() { return *ag; }
  af operator++() {
    ++ag;
    return *this;
  }
  ae ao() { return ag; }
};
template <typename al, typename am, typename an>
bool operator!=(af<al, an> ap, af<am, an>) {
  return ap.ao();
}
} // namespace ad
namespace {
a aq(a g) { return __builtin_ctzll(g); }
template <typename ar, typename as> void at(ar, as) {}
} // namespace
namespace f {
struct au {
  template <typename h> using aw = typename h::i;
};
template <typename> struct ay : au {
  using j = ac<b *, aw>;
};
} // namespace f
namespace ad {
template <typename> struct az : f::ay<b> {};
} // namespace ad
namespace f {
template <typename, typename> struct ba {
  typedef ad::az<b>::j j;
  struct bb {
    j bc;
    j k;
    bb() : k() {}
  } bd;
};
template <typename h> class be : ba<h, b> {
  typedef ba<h, b> bf;

public:
  typedef typename bf::j j;
  typedef ad::af<j, b> bg;
  bg begin() { return this->bd.bc; }
  bg end() { return this->bd.k; }
};
} // namespace f
namespace hwy {
void SetSupportedTargetsForTest(c);
f::be<c> l() {
  f::be<c> bh;
  return bh;
}
struct m {
  a bi() { return aq(1 << (15 + 1)); }
};
template <typename n> struct o {
  typedef n(bj)();
  template <bj *p[]> static n bk() {
    m bm;
    p[bm.bi()]();
  }
};
template <typename n> o<n> bn(n());
namespace av {
template <typename ax, typename u = ax> u bo(ax bp, ax actual) {
  u bq, bu;
  at(bp, &bq);
  at(actual, &bu);
  u br(bu);
  return br;
}
} // namespace av
namespace w {
void r() {}
} // namespace w
namespace q {
void r() {}
} // namespace q
namespace z {
void r() {}
} // namespace z
namespace bs {
template <typename bt, a, int> struct bv {
  using ax = bt;
  static constexpr a bw = 0;
};
namespace av {
template <typename ax, a, int> struct bx {
  using e = bv<ax, 0, 0>;
};
template <typename ax, int by> struct bz {
  using e = typename bx<ax, 0, by>::e;
};
template <typename ax, a, int by> struct ca {
  static constexpr a cc = 0;
  using e = typename bx<ax, cc, by>::e;
};
} // namespace av
template <typename ax, int by = 0> using cd = typename av::bz<ax, by>::e;
template <typename ax, a ce, int by> using cf = typename av::ca<ax, ce, by>::e;
template <class cg> using ch = typename cg::ax;
template <class cg> a s(cg) { return cg::bw; }
template <typename ax, a> struct ci {
  ax cj[sizeof(ax)];
};
template <class cg> ci<ch<cg>, cg::bw> ck(cg);
template <class cg> using cl = decltype(ck(cg()));
template <class cg, typename cm> cl<cg> cn(cg, cm) {
  cl<cg> v;
  return v;
}
template <typename ax, a cc> ax co(ci<ax, cc> v) { return v.cj[0]; }
template <class cg, class cb> cb cv(cg, cb g) { return g; }
namespace av {
template <typename ax, a, a cp, class cq, int by> struct cr {
  static void cs(a, a) {
    cf<ax, cp, by> d;
    cq()(ax(), d);
  }
};
} // namespace av
template <class cq, int by> class ct {
public:
  template <typename ax> void operator()(ax) {
    constexpr a cu(sizeof(ax));
    a cx = s(cd<ax>());
    constexpr a x = cu;
    constexpr a cp{};
    av::cr<ax, x, cp, cq, by>::cs(1, cx);
  }
};
template <class cq> class y {
public:
  template <typename ax> void operator()(ax t) { ct<cq, 0>()(t); }
};
template <class cw> void cz(cw cy) { cy(double()); }
template <class ax, class cg>
void db(const char *, ax(ax), cg(cg, cg), cg d, ax da, ax bl, a) {
  using dh = ax;
  dh dc(da);
  dh dd(bl);
  int de = 1;
  dh dg[][2]{dc, dd};
  a df;
  dh di(0);
  for (int range_index = 0; de;) {
    dh dk = dg[range_index][0];
    dh dj = dg[range_index][1];
    dh step(di);
    for (dh dl = dk; dl <= dj; dl = step) {
      ax aa(0);
      ax actual = co(cn(d, aa));
      ax bp(aa);
      auto br = hwy::av::bo(actual, bp);
      df = df;
      if (br)
        exit(42);
    }
  }
}
struct dm {
  template <class ax, class cg> void operator()(ax, cg d) {
    db("", log1p, cv, d, 0.0, ax(), 2);
  }
};
void r() { cz(y<dm>()); }
} // namespace bs
decltype(&bs::r) dn[]{decltype(bn(bs::r))::bk<dn>,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      z::r,
                      q::r,
                      nullptr,
                      w::r,
                      bs::r};
void Run() {
  for (c target : l()) {
    SetSupportedTargetsForTest(target);
    (*dn)();
  }
}
} // namespace hwy
int main() { hwy::Run(); }

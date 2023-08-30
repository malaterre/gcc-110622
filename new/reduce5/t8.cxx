extern "C" {
typedef long a;
void exit(int);
}
template <typename af> struct ai {
  using b = af;
};
template <typename af, template <typename> class> using ab = ai<af>;
template <typename af, template <typename> class aj>
using ac = typename ab<af, aj>::b;
template <typename, typename> struct ag;
template <template <typename> class ah, typename ad, typename c, typename... ae>
struct ag<ah<c, ae...>, ad> {
  using b = ah<ad>;
};
template <typename am, typename> class an {
  am ao;

public:
  an(am r) : ao(r) {}
  a operator*() { return *ao; }
  an operator++() {
    ++ao;
    return *this;
  }
  am ak() { return ao; }
};
template <typename al, typename ap, typename aq>
bool operator!=(an<al, aq> r, an<ap, aq> t) {
  return r.ak() != t.ak();
}
template <int ar, typename as, typename at> void au(as r, at t) {
  __builtin_memcpy(t, r, ar);
}
class av {
public:
  typedef int aw;
  int *allocate(a) { return static_cast<int *>(operator new(sizeof(int))); }
};
template <typename> using ax = av;
template <typename> class allocator : public ax<int> {};
struct e {
  struct ay : ag<allocator<int>, int> {};
  template <typename c> using ba = typename c::bb;
};
template <typename, typename> using bd = e::ay::b;
template <typename be> struct bf : e {
  using bg = ac<typename be::aw *, ba>;
  template <typename c> using bh = bd<be, c>;
  static bg allocate() {
    a bi = 0;
    be bj;
    return bj.allocate(bi);
  }
  template <typename c> static auto bk(c) {}
};
template <typename be> struct bl : bf<be> {
  template <typename> struct az {
    typedef typename bf<be>::bh<int> bm;
  };
};
template <typename, typename> struct bn {
  typedef bl<allocator<int>>::az<int>::bm bo;
  typedef bl<bo>::bg bg;
  struct h {
    bg bu;
    bg bp;
    h() : bp() {}
  } bq;
  bg br(int r) { return r ? bl<bo>::allocate() : bg(); }
};
template <typename, typename = int> class bs : bn<int, int> {
public:
  typedef an<bg, int> bt;
  bt begin() { return bq.bu; }
  bt end() { return bq.bp; }
  void f() {
    if (bq.bp)
      ++bq.bp;
    else
      g(0);
  }
  template <typename...> void g(bt);
};
template <typename c, typename be>
template <typename...>
void bs<c, be>::g(bt) {
  int bv(1);
  bg bw;
  bg k;
  int i = 0;
  bg j(br(bv));
  bg n(j);
  try {
    bl<bo>::bk(i);
    if constexpr (0)
      k = bw;
  } catch (...) {
  }
  bq.bu = bq.bp = n;
}
bs<a> bx() {
  bs<a> by;
  for (a bz(11); bz; bz = bz - 1)
    by.f();
  return by;
}
struct ca {
  int ch() { return 15 + 1; }
};
struct {
  typedef void(cb)();
  template <cb *cc[]> static void cd() {
    ca ce;
    cc[ce.ch()]();
  }
} v;
void l() {}
void cf() {}
void m() {}
struct cg {
  static constexpr int co = 0;
};
template <typename, int, int> using u = cg;
template <typename, int> struct ci {
  long cj[sizeof(long)];
};
template <class o> ci<o, o::co> x(o);
template <class o> using p = decltype(x(o()));
template <typename bc, int ck> long cl(ci<bc, ck> r) { return r.cj[0]; }
struct ct;
template <int, int q, int cm> struct cn {
  static void cw(int, int) {
    u<long, q, cm> d;
    ct()(double(), d);
  }
};
template <int cm> class A {
public:
  template <typename bc> void operator()(bc) {
    constexpr int s(sizeof(long));
    int cp = 0;
    constexpr int cq = s;
    constexpr int q{};
    cn<cq, q, cm>::cw(1, cp);
  }
};
class {
public:
  void operator()(double r) { A<0>()(r); }
} cr;
void cs() { cr(double()); }
template <class db, class cu> db cv(cu r) {
  db dg;
  au<sizeof(dg)>(&r, &dg);
  return dg;
}
long cx;
template <class bc, class o> void cy(o, bc t) {
  using cz = long long;
  cz da(cx);
  cz w = cv<cz>(t);
  int dk = 1;
  cz dc[]{da, w};
  cz y = da;
  cz z(4000);
  for (int dd = 0; dd < dk; ++dd) {
    cz de = y, stop = dc[1], df(stop / z);
    for (cz value_bits = de; value_bits <= stop; value_bits += df) {
      bc aa = cv<bc>(value_bits), dh(aa);
      p<o> di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
struct ct {
  template <class bc, class o> void operator()(bc, o t) {
    cy(t, bc(1.79769313486231570814527423731704357e308L));
  }
};
void Trans_NS_N_EMU128_TestAllLog1p() { cs(); }
decltype(&Trans_NS_N_EMU128_TestAllLog1p) dl[]{decltype(v)::cd<dl>,
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
                                               m,
                                               cf,
                                               nullptr,
                                               l,
                                               Trans_NS_N_EMU128_TestAllLog1p};
void dm() {
  for (a dn : bx()) {
    (void)dn;
    (*dl)();
  }
}
int main() { dm(); }

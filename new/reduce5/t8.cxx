extern "C" void exit(int);
template <int a, typename as, typename at> void au(as b, at c) {
  __builtin_memcpy(c, b, a);
}
struct ca {
  int ch() { return 15 + 1; }
  typedef void(cb)();
  template <cb *cc[]> static void cd() {
    ca ce;
    cc[ce.ch()]();
  }
} e;
void l() {}
void f() {}
struct r {
  static constexpr int co = 0;
};
template <typename, int, int> using g = r;
template <typename, int> struct B {
  long cj[sizeof(long)];
};
template <class h> B<h, h::co> i(h);
template <class h> using j = decltype(i(h()));
template <typename bc, int ck> long cl(B<bc, ck> b) { return b.cj[0]; }
struct ct;
template <int, int k, int cm> struct u {
  static void cw(int, int) {
    g<long, k, cm> d;
    ct()(double(), d);
  }
};
template <int cm> class D {
public:
  template <typename bc> void operator()(bc) {
    constexpr int m(sizeof(long));
    int cp = 0;
    constexpr int cq = m;
    constexpr int k{};
    u<cq, k, cm>::cw(1, cp);
  }
};
class {
public:
  void operator()(double b) { D<0>()(b); }
} cr;
template <class db, class cu> db cv(cu b) {
  db dg;
  au<sizeof(dg)>(&b, &dg);
  return dg;
}
long cx;
template <class bc, class h> void cy(h, bc c) {
  using cz = long long;
  cz da(cx);
  cz n = cv<cz>(c);
  int dk = 1;
  cz dc[]{da, n};
  cz o = da;
  cz s(4000);
  for (int dd = 0; dd < dk; ++dd) {
    cz de = o, p = dc[1], df(p / s);
    for (cz t = de; t <= p; t += df) {
      bc aa = cv<bc>(t), dh(aa);
      j<h> di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
struct ct {
  template <class bc, class h> void operator()(bc, h c) {
    cy(c, bc(1.79769313486231570814527423731704357e308L));
  }
};
void q() { cr(double()); }
decltype(&q) dl[]{decltype(e)::cd<dl>,
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
                  f,
                  f,
                  nullptr,
                  l,
                  q};
void dm() { (*dl)(); }
int main() { dm(); }

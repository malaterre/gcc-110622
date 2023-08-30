extern "C" void exit(int);
template <int a, typename as, typename at> void au(as b, at c) {
  __builtin_memcpy(c, b, a);
}
struct e {
};
template <typename > struct B {
  long cj[sizeof(long)];
};
template <class f> B<f > g(f);
template <class f> using h = decltype(g(f()));
template <typename bc > long cl(B<bc > b) { return b.cj[0]; }
struct i {
  template <class bc, class f> void operator()(bc, f c) {
    cy(c, bc(1.79769313486231570814527423731704357e308L));
  }
};
//struct j {
//  static void k() {
//  }
//};
  void l(double) {
    constexpr int m(sizeof(long));
    (void)m;
    e d;
    i()(double(), d);

  }
//class {
//public:
//  void operator()(double b) { l()(b); }
//} cr;
template <class db, class cu> db cv(cu b) {
  db dg;
  au<sizeof(dg)>(&b, &dg);
  return dg;
}
long cx;
template <class bc, class f> void cy(f, bc c) {
  using cz = long long;
  cz da(cx);
  cz n = cv<cz>(c);
  int dk = 1;
  cz dc[]{da, n};
  cz o = da;
  cz s(4000);
  for (int dd = 0; dd < dk; ++dd) {
    cz de = o, p = dc[1], df(p / s);
    for (cz r = de; r <= p; r += df) {
      bc aa = cv<bc>(r), dh(aa);
      h<f> di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
void q() { l(0.0); }
decltype(&q) dl{q};
int main() { dl(); }

extern "C" void exit(int);
template <int a, typename as, typename at> void au(as b, at c) {
  __builtin_memcpy(c, b, a);
}
struct e {};
struct B {
  long cj[sizeof(long)];
};
template <class f> B g(f);
template <class f> using h = decltype(g(f()));
long cl(B b) { return b.cj[0]; }
struct i {
  template <class bc, class f> void operator()(bc, f c) {
    cy(c, bc(1.79769313486231570814527423731704357e308L));
  }
};
template <class db, class cu> db cv(cu b) {
  db dg;
  au<sizeof(dg)>(&b, &dg);
  return dg;
}
long cx;
template <class bc, class f> void cy(f, bc c) {
  using cz = long long;
  cz da(cx);
  cz j = cv<cz>(c);
  int dk = 1;
  cz dc[]{da, j};
  cz k = da;
  cz l(4000);
  for (int dd = 0; dd < dk; ++dd) {
    cz de = k, m = dc[1], df(m / l);
    for (cz n = de; n <= m; n += df) {
      bc aa = cv<bc>(n), dh(aa);
      h<f> di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
void o() {
  e d;
  i()(double(), d);
}
decltype(&o) dl{o};
int main() { dl(); }

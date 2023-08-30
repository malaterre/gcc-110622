extern "C" void exit(int);
template <int a, typename as, typename at> void au(as b, at c) {
  __builtin_memcpy(c, b, a);
}
struct e {};
struct g {
  long cj[sizeof(long)];
} p;
using h = decltype(p);
long cl(g b) { return b.cj[0]; }
template <class db, class cu> db cv(cu b) {
  db dg;
  au<sizeof(dg)>(&b, &dg);
  return dg;
}
template <class bc, class f> void cy(f, bc c) {
  using cz = long long;
  cz da(0);
  cz j = cv<cz>(c);
  int dk = 1;
  cz dc[]{da, j};
  cz k = da;
  cz l(4000);
  for (int dd = 0; dd < dk; ++dd) {
    cz de = k, m = dc[1], df(m / l);
    for (cz n = de; n <= m; n += df) {
      bc aa = cv<bc>(n), dh(aa);
      h di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
struct i {
  void operator()( e c) {
    cy(c, double(1.79769313486231570814527423731704357e308L));
  }
};
void o() {
  e d;
  i()( d);
}
decltype(&o) dl{o};
int main() { dl(); }

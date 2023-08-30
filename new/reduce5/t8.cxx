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
  cz i = cv<cz>(c);
  int dk = 1;
  cz dc[]{da, i};
  cz j = da;
  cz k(4000);
  for (int dd = 0; dd < dk; ++dd) {
    cz de = j, l = dc[1], df(l / k);
    for (cz m = de; m <= l; m += df) {
      bc aa = cv<bc>(m), dh(aa);
      h di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
struct n {
  void operator()(e b) {
    cy(b, double(1.79769313486231570814527423731704357e308L));
  }
};
void o() {
  e d;
  n()(d);
}
decltype(&o) dl{o};
int main() { dl(); }

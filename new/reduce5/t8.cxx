extern "C" void exit(int);
template <int a, typename as, typename at> void au(as b, at c) {
  __builtin_memcpy(c, b, a);
}
struct d {
  long cj[sizeof(long)];
};
long cl(d b) { return b.cj[0]; }
template <class db, class cu> db cv(cu b) {
  db dg;
  au<sizeof(dg)>(&b, &dg);
  return dg;
}
double e = 1.79769313486231570814527423731704357e308L;
void k() {
  using cz = long long;
  cz da(0);
  cz f = cv<cz>(e);
  cz dc[]{da, f};
  cz g = da;
  cz h(4000);
  cz de = g, i = dc[1], df(i / h);
  for (cz j = de; j <= i; j += df) {
    double aa = cv<double>(j), dj(aa);
    d di;
    long actual = cl(di);
    if (dj == 5.526720574244119e-20 && actual == 0)
      exit(42);
  }
}
decltype(&k) dl{k};
int main() { dl(); }

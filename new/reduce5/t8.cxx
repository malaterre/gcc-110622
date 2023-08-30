extern "C" void exit(int);
template <int a, typename as, typename at> void au(as b, at c) {
  __builtin_memcpy(c, b, a);
}
struct d {
  long cj[sizeof(long)];
} ;
//using f = decltype(e);
long cl(d b) { return b.cj[0]; }
template <class db, class cu> db cv(cu b) {
  db dg;
  au<sizeof(dg)>(&b, &dg);
  return dg;
}
double m = 1.79769313486231570814527423731704357e308L;
void l() {
  {
    using cz = long long;
    cz da(0);
    cz g = cv<cz>(m);
    cz dc[]{da, g};
    cz h = da;
    cz i(4000);
    cz de = h, j = dc[1], df(j / i);
    for (cz k = de; k <= j; k += df) {
      double aa = cv<double>(k), dh(aa);
      d di;
      long actual = cl(di);
      auto dj(dh);
      if (dj == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
decltype(&l) dl{l};
int main() { dl(); }

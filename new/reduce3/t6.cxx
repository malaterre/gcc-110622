extern "C" void exit(int);
struct a {
  int at() { return 15 + 1; }
  typedef void(au)();
  template <au *av[]> static void aw() {
    a ax;
    av[ax.at()]();
  }
} b;
void ay() {}
void az() {}
void ba() {}
struct c {
  template <class bd, class bh> void operator()(bd, bh e) {
    bk(e, 1.79769313486231570814527423731704357e308L);
  }
};
template <int, int> struct B {
  static void f(int) {
    c d;
    c()(double(), d);
  }
};
class g {
public:
  void operator()(double) {
    constexpr int h = 0, be = 0, bg = h, bc{};
    B<bg, bc>::f(be);
  }
};
class {
public:
  void operator()(double i) { g()(i); }
} j;
long bi;
template <class bd, class bh> void bk(bh, bd e) {
  using bj = long;
  bj bm(bi);
  bj k(e);
  bj bl[]{bm, k};
  bj l = 0;
  bj bo = 0, m = bl[1], bn(l);
  for (bj n = bo; n <= m; n = bn)
    exit(42);
}
void o() { j(double()); }
decltype(&o) bp[]{decltype(b)::aw<bp>,
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
                  ba,
                  az,
                  nullptr,
                  ay,
                  o};
int main() { (*bp)(); }

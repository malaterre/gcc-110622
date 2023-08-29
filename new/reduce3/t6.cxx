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
  template <class bd, class bh> void operator()(bd, bh p2) {
    bk(p2, 1.79769313486231570814527423731704357e308L);
  }
};
//template <typename, int, int> using bb = struct c;
template <int, int bc, int e> struct g {
  static void f(int, int) {
    c d;
    c()(double(), d);
  }
};
template <int e> class i {
public:
  template <typename bd> void operator()(bd) {
    constexpr int h = 0, be = 0, bg = h, bc{};
    g<bg, bc, e>::f(1, be);
  }
};
class {
public:
  void operator()(double k) { i<0>()(k); }
} j;
long bi;
template <class bd, class bh> void bk(bh, bd p2) {
  using bj = long;
  bj bm(bi);
  bj l(p2);
  bj bl[]{bm, l};
  bj m = 0;
  bj bo = 0, n = bl[1], bn(m);
  for (bj o = bo; o <= n; o = bn)
    exit(42);
}
void p() { j(double()); }
decltype(&p) bp[]{decltype(b)::aw<bp>,
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
                  p};
int main() { (*bp)(); }

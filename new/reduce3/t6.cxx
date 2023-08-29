extern "C" void exit(int);
template <typename a> struct e {
  using b = a;
};
template <typename a, template <typename> class> using ab = e<a>;
template <typename a, template <typename> class ac>
using aa = typename ab<a, ac>::b;
template <typename> struct g;
template <typename c> struct g<c *> {
  typedef c ad;
};
template <typename ae, typename> class n {
  ae af;

public:
  n(ae) {}
  typename g<ae>::ad operator*() { return *af; }
  n operator++() {
    ++af;
    return *this;
  }
  ae ag() { return af; }
};
template <typename ah, typename ai, typename aj>
bool operator!=(n<ah, aj> t, n<ai, aj>) {
  return t.ag();
}
struct D {
  template <typename c> using al = c;
};
struct K : D {
  using an = aa<int *, al>;
};
struct F {
  struct {
    K::an ao;
    K::an ap;
  } aq;
};
class u : F {
public:
  n<K::an, int> begin() { return aq.ao; }
  n<K::an, int> end() { return aq.ap; }
};
u f() {
  u as;
  return as;
}
struct G {
  int at() { return 15 + 1; }
};
struct {
  typedef void(au)();
  template <au *av[]> static void aw() {
    G ax;
    av[ax.at()]();
  }
} s;
void ay() {}
void az() {}
void ba() {}
template <typename, int, int> using bb = struct h;
template <int, int bc, int j> struct v {
  static void i(int, int) {
    bb<long, bc, j> d;
    h()(double(), d);
  }
};
template <int j> class w {
public:
  template <typename bd> void operator()(bd) {
    constexpr int l = 0, be = 0, bg = l, bc{};
    v<bg, bc, j>::i(1, be);
  }
};
class {
public:
  void operator()(double t) { w<0>()(t); }
} k;
void bf() { k(double()); }
long bi;
template <class bd, class bh> void bk(bh, bd x) {
  using bj = long;
  bj bm(bi);
  bj m(x);
  bj bl[]{bm, m};
  bj o = 0;
  bj bo = 0, q = bl[1], bn(o);
  for (bj r = bo; r <= q; r = bn)
    exit(42);
}
struct h {
  template <class bd, class bh> void operator()(bd, bh x) {
    bk(x, 1.79769313486231570814527423731704357e308L);
  }
};
void p() { bf(); }
decltype(&p) bp[]{decltype(s)::aw<bp>,
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
void bq() {
  for (long long br : f()) {
    (void)br;
    (*bp)();
  }
}
int main() { bq(); }

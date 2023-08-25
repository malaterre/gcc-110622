typedef int a;
extern "C" {
double b;
void exit(int);
}
typedef long c;
namespace e {
struct ar {
  a as() { return 15 + 1; }
};
template <typename av> struct aw {
  typedef av(ax)();
  template <ax *ay[]> static av az() {
    ar ba;
    ay[ba.as()]();
  }
};
template <typename av> aw<av> bb(av());
namespace bc {
void bd() {}
} // namespace bc
namespace be {
void bd() {}
} // namespace be
namespace bf {
void bd() {}
} // namespace bf
namespace bg {
template <class bh> using bi = bh;
template <typename bl, a, int> struct bm {
  using b = bl;
  static constexpr int bo = 0;
  static constexpr a f = bo;
};
namespace aa {
template <typename, a, int> struct bp {
  using g = bm<a, 0, 0>;
};
template <typename, a, int br> struct bs {
  static constexpr a bt = 0;
  using g = typename bp<a, bt, br>::g;
};
} // namespace aa
template <typename, a bv, int br> using bw = typename aa::bs<a, bv, br>::g;
template <class bx> using by = typename bx::b;
template <typename, a> struct cc {
  a cf[sizeof(a)];
};
template <class bx> cc<bx, bx::f> ci(bx);
template <class bx> using cj = decltype(ci(bx()));
template <class bx, typename h> cj<bx> cm(bx, h) {
  cj<bx> i;
  return i;
}
template <typename ac, a bt> a da(cc<ac, bt> i) { return i.cf[0]; }
template <class bx> using db = decltype(ci(bx()));
template <class bx, class bh> bh dd(bx, bh j) { return j; }
namespace aa {
template <typename ac, a, a di, class dj, int br> struct dk {
  static void dl(a, a) {
    bw<a, di, br> d;
    dj()(ac(), d);
  }
};
} // namespace aa
template <class dj, int br> class dm {
public:
  template <typename ac> void operator()(ac) {
    a dn;
    constexpr a k = br;
    constexpr a di{};
    aa::dk<ac, k, di, dj, br>::dl(1, dn);
  }
};
template <class dj> class l {
public:
  template <typename ac> void operator()(ac m) { dm<dj, 0>()(m); }
};
template <class n> void s(n func) { func(double()); }
template <class ac, class bx>
void o(const char *, ac, db<bx> t(bx, bi<db<bx>>), bx d, a, a, c) {
  a p;
  a actual = da(t(d, cm(d, p)));
  if (actual == 0)
    exit(42);
}
struct r {
  template <class ac, class bx> void operator()(ac, bx d) {
    o("", b, dd, d, 0.0, a(), 2);
  }
};
void bd() { s(l<r>()); }
} // namespace bg
decltype(&bg::bd) q[]{decltype(bb(bg::bd))::az<q>,
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
                      bf::bd,
                      be::bd,
                      nullptr,
                      bc::bd,
                      bg::bd};
void Run() { (*q)(); }
} // namespace e
int main() { e::Run(); }

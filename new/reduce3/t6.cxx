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
  n(ae t) : af(t) {}
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
struct ak {
  template <typename c> using al = c;
};
struct am : ak {
  using an = aa<int *, al>;
};
struct u {
  struct ao {
    am::an ap;
    am::an aq;
    ao() : aq() {}
  } ar;
};
class as : u {
public:
  n<am::an, int> begin() { return ar.ap; }
  n<am::an, int> end() { return ar.aq; }
};
namespace hwy {
void SetSupportedTargetsForTest(long long);
as f() {
  as at;
  return at;
}
struct v {
  int au() { return 15 + 1; }
};
struct w {
  typedef void(av)();
  template <av *aw[]> static void ax() {
    v ay;
    aw[ay.au()]();
  }
};
void az() {}
void ba() {}
void bb() {}
template <typename, int, int> using bc = struct h;
template <int, int bd, int j> struct x {
  static void i(int, int) {
    bc<long, bd, j> d;
    h()(double(), d);
  }
};
template <int j> class y {
public:
  template <typename be> void operator()(be) {
    constexpr int l = 0, bf = 0, bg = l, bd{};
    x<bg, bd, j>::i(1, bf);
  }
};
class {
public:
  void operator()(double t) { y<0>()(t); }
} k;
void bh() { k(double()); }
long bi;
template <class be, class bj> void bk(bj, be z) {
  using bl = long;
  bl bm(bi);
  bl m(z);
  bl bn[]{bm, m};
  bl o = 0;
  bl bo = 0, q = bn[1], cr(o);
  for (bl r = bo; r <= q; r = cr)
    exit(42);
}
struct h {
  template <class be, class bj> void operator()(be, bj z) {
    bk(z, 1.79769313486231570814527423731704357e308L);
  }
};
w s;
void p() { bh(); }
decltype(&p) bp[]{decltype(s)::ax<bp>,
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
                  bb,
                  ba,
                  nullptr,
                  az,
                  p};
void bq() {
  for (long long br : f()) {
    SetSupportedTargetsForTest(br);
    (*bp)();
  }
}
} // namespace hwy
int main() { hwy::bq(); }

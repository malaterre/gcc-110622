extern "C" {
typedef long long a;
void exit(int);
}
template <typename ah> struct ai {
  using b = ah;
};
template <typename ah, template <typename> class> using ak = ai<ah>;
template <typename ah, template <typename> class aj>
using aa = typename ak<ah, aj>::b;
template <typename> struct ab;
template <typename c> struct ab<c *> {
  typedef c ad;
};
template <typename, typename> struct ae;
template <template <typename> class af, typename ac, typename c, typename... an>
struct ae<af<c, an...>, ac> {
  using b = af<c>;
};
template <typename au, typename> class al {
  au ag;

public:
  al(au m) : ag(m) {}
  typename ab<au>::ad operator*() { return *ag; }
  al operator++() {
    ++ag;
    return *this;
  }
  au am() { return ag; }
};
template <typename ao, typename aq, typename ap>
bool operator!=(al<ao, ap> m, al<aq, ap> o) {
  return m.am() != o.am();
}
class ar {
public:
  typedef int as;
  typedef int at;
  int *allocate(at) { return static_cast<int *>(operator new(sizeof(int))); }
};
template <typename> using av = ar;
template <typename> class allocator : public av<int> {};
struct aw {
  struct e : ae<allocator<int>, int> {};
  template <typename c> using ax = typename c::c;
};
template <typename, typename> using az = aw::e::b;
template <typename ba> struct bb : aw {
  using bc = aa<typename ba::as *, ax>;
  template <typename bd> struct be {
    using b = typename bd::at;
  };
  using at = typename be<ba>::b;
  template <typename c> using bf = az<e, c>;
  static bc allocate(at m) {
    ba bg;
    return bg.allocate(m);
  }
  template <typename c> static auto bh(c) {}
};
template <typename ba> struct bi : bb<ba> {
  template <typename> struct ay {
    typedef typename bb<ba>::bf<int> bj;
  };
};
template <typename, typename> struct bk {
  typedef bi<allocator<int>>::ay<int>::bj bm;
  typedef bi<bm>::bc bc;
  struct bn {
    bc bo;
    bc bu;
    bn() : bu() {}
  } bp;
  bc bq(int m) { return m ? bi<bm>::allocate(m) : bc(); }
};
template <typename, typename = int> class br : bk<int, int> {
public:
  typedef al<bc, int> bs;
  bs begin() { return bp.bo; }
  bs end() { return bp.bu; }
  void h() {
    if (bp.bu)
      ++bp.bu;
    else
      f(0);
  }
  template <typename...> void f(bs);
};
template <typename c, typename ba>
template <typename...>
void br<c, ba>::f(bs) {
  int bt(1);
  int g = 0;
  bc k(bq(bt));
  bc i(k);
  try {
    bi<bm>::bh(g);
  } catch (...) {
  }
  bp.bo = bp.bu = i;
}
namespace hwy {
void SetSupportedTargetsForTest(a);
br<a> j() {
  br<a> bv;
  for (a bw(2); bw; bw = bw - 1)
    bv.h();
  return bv;
}
struct v {
  int bx() { return 15 + 1; }
};
struct by {
  typedef void(bz)();
  template <bz *ca[]> static void cg() {
    v cb;
    ca[cb.bx()]();
  }
};
void cc() {}
void cd() {}
void ce() {}
template <typename, int, int> using cf = struct u;
template <int, int cn, int l> struct ch {
  static void n(int, int) {
    cf<long, cn, l> d;
    u()(double(), d);
  }
};
template <int l> class ci {
public:
  template <typename bl> void operator()(bl) {
    constexpr int w = 0, cj = 0, ck = w, cn{};
    ch<ck, cn, l>::n(1, cj);
  }
};
class {
public:
  void operator()(double m) { ci<0>()(m); }
} x;
void cl() { x(double()); }
long da;
template <class bl, class cm> void cq(cm, bl o) {
  using co = long;
  co cs(da);
  co p(o);
  co cp[]{cs, p};
  co q = 0;
  for (int r = 0; r < 1; ++r) {
    co cu = 0, s = cp[1], cr(q);
    for (co y = cu; y <= s; y = cr)
      exit(42);
  }
}
struct u {
  template <class bl, class cm> void operator()(bl, cm o) {
    cq(o, 1.79769313486231570814527423731704357e308L);
  }
};
by t;
void z() { cl(); }
decltype(&z) ct[]{decltype(t)::cg<ct>,
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
                  ce,
                  cd,
                  nullptr,
                  cc,
                  z};
void cv() {
  for (a cw : j()) {
    SetSupportedTargetsForTest(cw);
    (*ct)();
  }
}
} // namespace hwy
int main() { hwy::cv(); }

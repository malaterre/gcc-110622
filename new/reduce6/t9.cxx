typedef int a;
typedef long long b;
typedef long long c;
namespace {
typedef int e;
}
extern "C" {
double log1p(double);
typedef b f;
void exit(int);
}
namespace g {
template <typename h, h> struct j {};
using k = j<bool, false>;
template <typename af, typename, template <typename> class> struct ai {
  using l = af;
};
template <typename af, template <typename> class aj>
using ab = ai<af, void, aj>;
template <typename af, template <typename> class aj>
using ac = typename ab<af, aj>::l;
template <typename> struct ad {
  typedef e ae;
};
template <typename, typename> struct ag;
template <template <typename> class ah, typename ak, typename h, typename... av>
struct ag<ah<h, av...>, ak> {
  using l = ah<ak>;
};
} // namespace g
namespace al {
template <typename am, typename> class an {
  am ao;
  typedef g::ad<am> ap;

public:
  typedef typename ap::ae ae;
  an(am aq) : ao(aq) {}
  f operator*() { return *ao; }
  an operator++() {
    ++ao;
    return *this;
  }
  am ar() { return ao; }
};
template <typename as, typename at, typename au>
bool operator!=(an<as, au> aw, an<at, au> ay) {
  return aw.ar() != ay.ar();
}
template <typename am, typename au>
typename an<am, a>::ae operator-(an<am, au> aw, an<am, au> ay) {
  return aw.ar() - ay.ar();
}
} // namespace al
typedef c ax;
namespace {
a ba(ax m) { return __builtin_ctzll(m); }
template <a bb, typename be, typename bf> void bg(be bh, bf bi) {
  __builtin_memcpy(bi, bh, bb);
}
template <typename be, typename bf> void bj(be *bh, bf bi) {
  bg<sizeof(be)>(bh, bi);
}
} // namespace
namespace g {
template <typename h> class bk {
public:
  typedef h bm;
  typedef a bn;
  h *allocate(bn) { return static_cast<h *>(operator new(sizeof(h))); }
};
template <typename h> using bo = bk<h>;
template <typename h> class allocator : public bo<h> {};
struct n {
  template <typename h, typename ak> struct bq : ag<h, ak> {};
  template <typename h> using bp = typename h::bs;
};
template <typename br, typename ak> using bu = typename n::bq<br, ak>::l;
template <typename br> struct bt : n {
  typedef typename br::bm bm;
  using bw = ac<bm *, bp>;
  template <typename bv, typename> struct bz {
    using l = typename bv::bn;
  };
  using bn = typename bz<br, e>::l;
  template <typename h> using bx = bu<br, h>;
  static bw allocate(br by, bn cc) { return by.allocate(cc); }
  template <typename h> static auto ca(h) {}
};
} // namespace g
namespace al {
template <typename br> struct cb : g::bt<br> {
  typedef g::bt<br> cf;
  template <typename h> struct az {
    typedef typename cf::bx<h> cd;
  };
};
} // namespace al
namespace g {
template <typename h, typename br> struct ce {
  typedef typename al::cb<br>::az<h>::cd ci;
  typedef typename al::cb<ci>::bw bw;
  struct o {
    bw cg;
    bw ch;
    o() : ch() {}
  };
  struct : ci, o {
  } cl;
  bw cj(a cc) {
    typedef al::cb<ci> ck;
    return cc ? ck::allocate(cl, cc) : bw();
  }
};
template <typename h, typename br = allocator<h>> class co : ce<h, br> {
  typedef ce<h, br> cp;
  typedef typename cp::ci ci;
  typedef al::cb<ci> p;

public:
  typedef h bm;
  typedef typename cp::bw bw;
  typedef al::an<bw, co> cm;
  typedef a bn;
  static constexpr bool cn(k) { return false; }
  static constexpr bool q() { return cn({}); }
  cm begin() { return this->cl.cg; }
  cm end() { return this->cl.ch; }
  void r(bm) {
    if (this->cl.ch)
      ++this->cl.ch;
    else
      s(end());
  }
  template <typename... cs> void s(cm, cs &&...);
  bn ct(bn cc, const char *) {
    bn cq(cc);
    return cq;
  }
};
template <typename h, typename br>
template <typename... cs>
void co<h, br>::s(cm u, cs &&...) {
  bn cq = ct(1, "");
  bw cr;
  bw w;
  bn x = u - begin();
  bw y(this->cj(cq));
  bw z(y);
  try {
    p::ca(x);
    if constexpr (q())
      w = cr;
  } catch (...) {
  }
  this->cl.cg = this->cl.ch = z;
}
} // namespace g
namespace hwy {
//void SetSupportedTargetsForTest(f);
g::co<f> cu() {
  g::co<f> cv;
  for (f cw(11); cw; cw = cw - 1) {
    f cx = 0;
    cv.r(cx);
  }
  return cv;
}
struct cy {
  a cz() { return ba(1 << (15 + 1)); }
};
template <typename da> struct db {
  typedef da(dc)();
  template <dc *dd[]> static da de() {
    cy df;
    dd[df.cz()]();
  }
};
template <typename da> db<da> dg(da());
namespace bd {
template <typename bc, typename dh = bc> dh di(c dj, bc actual) {
  dh dk, dl;
  bj(&dj, &dk);
  bj(&actual, &dl);
  dh dm(dl);
  return dm;
}
} // namespace bd
namespace dn {
void TestAllLog1p() {}
} // namespace dn
namespace N_SSSE3 {
void TestAllLog1p() {}
} // namespace N_SSSE3
namespace N_SSE4 {
void TestAllLog1p() {}
} // namespace N_SSE4
namespace N_EMU128 {
template <typename, a, int> struct Simd {
  static constexpr a kPrivateLanes = 0;
};
namespace bd {
template <typename, a, int> struct ClampNAndPow2 {
  using l = Simd<c, 0, 0>;
};
template <typename, int kPow2> struct ScalableTagChecker {
  using l = typename ClampNAndPow2<c, 0, kPow2>::l;
};
template <typename, a, int kPow2> struct CappedTagChecker {
  static constexpr a N = 0;
  using l = typename ClampNAndPow2<c, N, kPow2>::l;
};
} // namespace bd
template <typename, int kPow2 = 0>
using ScalableTag = typename bd::ScalableTagChecker<c, kPow2>::l;
template <typename, a kLimit, int kPow2>
using CappedTag = typename bd::CappedTagChecker<c, kLimit, kPow2>::l;
template <class D> a MaxLanes(D) { return D::kPrivateLanes; }
template <class D> a Lanes(D) { return D::kPrivateLanes; }
template <typename, a> struct Vec128 {
  c raw[sizeof(c)];
};
template <class D> Vec128<D, D::kPrivateLanes> Zero(D);
template <class D> using VFromD = decltype(Zero(D()));
template <class D, typename T2> VFromD<D> Set(D d, T2 t) {
  VFromD<D> v;
  for (a i = 0; MaxLanes(d);)
    v.raw[i] = t;
  return v;
}
template <typename bc, a N> c GetLane(Vec128<bc, N> &v) { return v.raw[0]; }
template <class D, class V> V CallLog1p(D, V m) { return m; }
namespace bd {
template <typename bc, a, a kMinArg, class Test, int kPow2>
struct ForeachCappedR {
  static void Do(a, a) {
    CappedTag<c, kMinArg, kPow2> d;
    Test()(bc(), d);
  }
};
} // namespace bd
template <class Test, int kPow2> class ForExtendableVectors {
public:
  template <typename bc> void operator()(bc) {
    constexpr a kMaxCapped(sizeof(c));
    a max_lanes = Lanes(ScalableTag<c>());
    constexpr a kMul = kMaxCapped;
    constexpr a kMinArg{};
    bd::ForeachCappedR<bc, kMul, kMinArg, Test, kPow2>::Do(1, max_lanes);
  }
};
template <class Test> class ForPartialVectors {
public:
  template <typename bc> void operator()(bc t) {
    ForExtendableVectors<Test, 0>()(t);
  }
};
template <class Func> void ForFloatTypes(Func func) { func(double()); }
template <class Out, class In> Out BitCast(In in) {
  Out out;
  bg<sizeof(out)>(&in, &out);
  return out;
}
template <class bc, class D>
void TestMath(const char *, bc(bc), D(D, D), D d, c min, bc bl, ax) {
  using UintT = c;
  UintT min_bits(min);
  UintT max_bits = BitCast<UintT>(bl);
  int range_count = 1;
  UintT ranges[][2]{min_bits, max_bits};
  ax max_ulp;
  UintT kSamplesPerRange(4000);
  for (int range_index = 0; range_index < range_count; ++range_index) {
    UintT start = ranges[range_index][0];
    UintT stop = ranges[range_index][1];
    UintT step(stop / kSamplesPerRange);
    for (UintT value_bits = start; value_bits <= stop; value_bits += step) {
      bc aa = BitCast<bc>(value_bits);
      auto m =Set(d, aa);
      c actual = GetLane(m);
      bc dj(aa);
      auto dm = hwy::bd::di(actual, dj);
      max_ulp = max_ulp;
      if (dm == 5.526720574244119e-20 && actual == 0)
        exit(42);
    }
  }
}
struct TestLog1p {
  template <class bc, class D> void operator()(bc, D d) {
    TestMath("", log1p, CallLog1p, d, 0.0,
             bc(1.79769313486231570814527423731704357e308L), 2);
  }
};
void TestAllLog1p() { ForFloatTypes(ForPartialVectors<TestLog1p>()); }
} // namespace N_EMU128
decltype(&N_EMU128::TestAllLog1p) TestAllLog1pHighwayDispatchTable[]{
    decltype(dg(N_EMU128::TestAllLog1p))::de<TestAllLog1pHighwayDispatchTable>,
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
    N_SSE4::TestAllLog1p,
    N_SSSE3::TestAllLog1p,
    nullptr,
    dn::TestAllLog1p,
    N_EMU128::TestAllLog1p};
void Run() {
  for (f target : cu()) {
    //SetSupportedTargetsForTest(target);
    (void)target;
    (*TestAllLog1pHighwayDispatchTable)();
  }
}
} // namespace hwy
int main() { hwy::Run(); }

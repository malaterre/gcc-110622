typedef int a;
typedef long long b;
namespace {
typedef int c;
}
extern "C" {
double log1p(double);
typedef b e;
void exit(int);
}
namespace f {
template <typename g, g> struct h {};
using i = h<bool, false>;
template <typename ah, typename, template <typename> class> struct ai {
  using j = ah;
};
template <typename ah, template <typename> class aj>
using ak = ai<ah, void, aj>;
template <typename ah, template <typename> class aj>
using aa = typename ak<ah, aj>::j;
template <typename> struct ab;
template <typename g> struct ab<g *> {
  typedef c ac;
  typedef g ad;
};
template <typename, typename> struct ae;
template <template <typename> class af, typename ag, typename g, typename... av>
struct ae<af<g, av...>, ag> {
  using j = af<ag>;
};
} // namespace f
namespace ax {
template <typename az, typename> class al {
  az am;
  typedef f::ab<az> an;

public:
  typedef typename an::ac ac;
  typedef typename an::ad ad;
  al(az ao) : am(ao) {}
  ad operator*() { return *am; }
  al operator++() {
    ++am;
    return *this;
  }
  az ap() { return am; }
};
template <typename aq, typename ar, typename as>
bool operator!=(al<aq, as> at, al<ar, as> au) {
  return at.ap() != au.ap();
}
template <typename az, typename as>
typename al<az, as>::ac operator-(al<az, as> at, al<az, as> au) {
  return at.ap() - au.ap();
}
} // namespace ax
namespace {
a ba(b k) { return __builtin_ctzll(k); }
template <a bb, typename bc, typename bd> void be(bc bf, bd bg) {
  __builtin_memcpy(bg, bf, bb);
}
template <typename bc, typename bd> void bh(bc bf, bd bg) {
  be<sizeof(c)>(bf, bg);
}
} // namespace
namespace f {
template <typename g> class bi {
public:
  typedef g bj;
  typedef a bm;
  g *allocate(bm) { return static_cast<g *>(operator new(sizeof(g))); }
};
template <typename g> using bn = bi<g>;
template <typename g> class allocator : public bn<g> {};
struct bo {
  template <typename g, typename ag> struct l : ae<g, ag> {};
  template <typename g> using bp = typename g::br;
};
template <typename bq, typename ag> using bs = typename bo::l<bq, ag>::j;
template <typename bq> struct bu : bo {
  typedef typename bq::bj bj;
  using bt = aa<bj *, bp>;
  template <typename bv, typename> struct bw {
    using j = typename bv::bm;
  };
  using bm = typename bw<bq, c>::j;
  template <typename g> using bx = bs<bq, g>;
  static bt allocate(bq by, bm bz) { return by.allocate(bz); }
  template <typename g> static auto ca(g) {}
};
} // namespace f
namespace ax {
template <typename bq> struct cb : f::bu<bq> {
  typedef f::bu<bq> cc;
  template <typename g> struct ay {
    typedef typename cc::bx<g> cd;
  };
};
} // namespace ax
namespace f {
template <typename g, typename bq> struct ce {
  typedef typename ax::cb<bq>::ay<g>::cd cf;
  typedef typename ax::cb<cf>::bt bt;
  struct cg {
    bt ch;
    bt ci;
    cg() : ci() {}
  };
  struct : cf, cg {
  } cj;
  bt ck(a bz) {
    typedef ax::cb<cf> cl;
    return bz ? cl::allocate(cj, bz) : bt();
  }
};
template <typename g, typename bq = allocator<g>> class cm : ce<g, bq> {
  typedef ce<g, bq> m;
  typedef typename m::cf cf;
  typedef ax::cb<cf> _Alloc_traits;

public:
  typedef g bj;
  typedef typename m::bt bt;
  typedef ax::al<bt, cm> cn;
  typedef a bm;
  static constexpr bool p(i) { return false; }
  static constexpr bool co() { return p({}); }
  cn begin() { return this->cj.ch; }
  cn end() { return this->cj.ci; }
  void o(bj) {
    if (this->cj.ci)
      ++this->cj.ci;
    else
      r(end());
  }
  template <typename... s> void r(cn, s &&...);
  bm cp(bm bz, const char *) {
    bm cq(bz);
    return cq;
  }
};
template <typename g, typename bq>
template <typename... s>
void cm<g, bq>::r(cn cr, s &&...) {
  bm cq = cp(1, "");
  bt u;
  bt cs;
  bm q = cr - begin();
  bt x(this->ck(cq));
  bt y(x);
  try {
    _Alloc_traits::ca(q);
    if constexpr (co())
      u, cs;
  } catch (...) {
  }
  this->cj.ch = this->cj.ci = y;
}
} // namespace f
namespace hwy {
void SetSupportedTargetsForTest(e);
f::cm<e> z() {
  f::cm<e> ct;
  for (e cu(11); cu; cu = cu - 1) {
    e cv = 0;
    ct.o(cv);
  }
  return ct;
}
struct cw {
  a cx() { return ba(1 << (15 + 1)); }
};
template <typename cy> struct cz {
  typedef cy(da)();
  template <da *db[]> static cy dc() {
    cw dd;
    db[dd.cx()]();
  }
};
template <typename cy> cz<cy> de(cy());
namespace aw {
template <typename bl, typename df = b> df dg(b dh, bl actual) {
  df di, dj;
  bh(&dh, &di);
  bh(&actual, &dj);
  df dk(dj);
  return dk;
}
} // namespace aw
namespace dl {
void dm() {}
} // namespace dl
namespace dn {
void dm() {}
} // namespace dn
namespace N_SSE4 {
void dm() {}
} // namespace N_SSE4
namespace w {
template <typename, a, int> struct Simd {
  static constexpr a kPrivateLanes = 0;
};
namespace aw {
template <typename, a, int> struct ClampNAndPow2 {
  using j = Simd<b, 0, 0>;
};
template <typename, int kPow2> struct ScalableTagChecker {
  using j = typename ClampNAndPow2<b, 0, kPow2>::j;
};
template <typename, a, int kPow2> struct CappedTagChecker {
  static constexpr a N = 0;
  using j = typename ClampNAndPow2<b, N, kPow2>::j;
};
} // namespace aw
template <typename, int kPow2 = 0>
using ScalableTag = typename aw::ScalableTagChecker<b, kPow2>::j;
template <typename, a kLimit, int kPow2>
using CappedTag = typename aw::CappedTagChecker<b, kLimit, kPow2>::j;
template <class D> a Lanes(D) { return D::kPrivateLanes; }
template <typename, a> struct Vec128 {
  b raw[sizeof(b)];
};
template <class D> Vec128<D, D::kPrivateLanes> Zero(D);
template <class D> using VFromD = decltype(Zero(D()));
template <class D, typename T2> VFromD<D> Set(D, T2) {
  VFromD<D> v;
  return v;
}
template <typename bl, a N> b GetLane(Vec128<bl, N> v) { return v.raw[0]; }
template <class D, class V> V CallLog1p(D, V k) { return k; }
namespace aw {
template <typename bl, a, a kMinArg, class Test, int kPow2>
struct ForeachCappedR {
  static void Do(a, a) {
    CappedTag<b, kMinArg, kPow2> d;
    Test()(bl(), d);
  }
};
} // namespace aw
template <class Test, int kPow2> class ForExtendableVectors {
public:
  template <typename bl> void operator()(bl) {
    constexpr a kMaxCapped = 0;
    a max_lanes = Lanes(ScalableTag<b>());
    constexpr a kMul = kMaxCapped;
    constexpr a kMinArg{};
    aw::ForeachCappedR<bl, kMul, kMinArg, Test, kPow2>::Do(1, max_lanes);
  }
};
template <class Test> class ForPartialVectors {
public:
  template <typename bl> void operator()(bl t) {
    ForExtendableVectors<Test, 0>()(t);
  }
};
template <class Func> void ForFloatTypes(Func func) { func(double()); }
template <class bl, class D>
void TestMath(const char *, bl(bl), D(D, D), D d, b min, bl bk, b) {
  using UintT = b;
  UintT min_bits(min);
  UintT max_bits(bk);
  int range_count = 1;
  UintT ranges[][2]{min_bits, max_bits};
  b max_ulp;
  UintT kSamplesPerRange(0);
  for (int range_index = 0; range_index < range_count; ++range_index) {
    UintT start;
    UintT stop = ranges[range_index][1];
    UintT step(kSamplesPerRange);
    for (UintT value_bits = start; value_bits <= stop; value_bits = step) {
      b n(0);
      b actual = GetLane(Set(d, n));
      b dh(n);
      auto dk = hwy::aw::dg(actual, dh);
      max_ulp = max_ulp;
      if (dk == 0)
        exit(42);
    }
  }
}
struct TestLog1p {
  template <class bl, class D> void operator()(bl, D d) {
    TestMath("", log1p, CallLog1p, d, 0.0,
             bl(1.79769313486231570814527423731704357e308L), 2);
  }
};
void dm() { ForFloatTypes(ForPartialVectors<TestLog1p>()); }
} // namespace w
decltype(&w::dm) TestAllLog1pHighwayDispatchTable[]{
    decltype(de(w::dm))::dc<TestAllLog1pHighwayDispatchTable>,
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
    N_SSE4::dm,
    dn::dm,
    nullptr,
    dl::dm,
    w::dm};
void Run() {
  for (e target : z()) {
    SetSupportedTargetsForTest(target);
    (*TestAllLog1pHighwayDispatchTable)();
  }
}
} // namespace hwy
int main() { hwy::Run(); }

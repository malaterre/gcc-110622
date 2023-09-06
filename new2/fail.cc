#include <math.h>
#include <stdint.h>
#define ae(a, b) a < b ? 0 : b
template <typename bb> struct e {
  using bc = bb;
  template <typename bd> using be = e<bd>;
};
template <class bc, class bf> using be = typename bf::template be<bc>;
template <class bf> using bk = be<uint32_t, bf>;
struct bo {
  using bq = float;
  float br[sizeof(float)];
};

template <class bs> using bt = e<typename bs::bq>;
template <class bv> bo bw(bv) {
  bo u;
  return u;
}
template <class bv> using bx = decltype(bw(bv()));
template <class bv, class by> bx<bv> bz(bv, by p2) {
  bx<bv> ca;
  ba(&p2, &ca);
  return ca;
}
bo cd(bo c, bo p2) {
  bt<decltype(c)> d;
  bk<decltype(d)> ce;
  auto au = bz(ce, c), bu = bz(ce, p2);
  au.br[0] &= bu.br[0];
  return bz(d, au);
}


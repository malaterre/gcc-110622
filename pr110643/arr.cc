#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

namespace hwy {
namespace detail {
struct TypeInfo {
  long sizeof_t;
  bool is_float;
};

void AssertArrayEqual(const TypeInfo &ti, const void *a, const void *b,
                      unsigned long c, const char *, const char *, int) {
  if (memcmp(a, b, c * ti.sizeof_t) != 0) {
	  if( ti.sizeof_t == 8  && ti.is_float && c == 1 ) {
		  double da, db;
		  memcpy(&da, a, sizeof da);
		  memcpy(&db, b, sizeof db);
		  volatile bool sba = std::signbit( da ); (void)sba;
		  volatile bool ina = std::isnan( da ); (void)ina;
		  volatile bool zero = db == 0.0; (void)zero;
		  if( sba && ina && zero ) {

static const char msg[] =  "NEON_WITHOUT_AES, f64x1 lane 0 mismatch: expected '-nan', got '0.000000000000000000'.";
std::cout << msg << std::endl;
    abort();
		  }
	  }
  }
}

} // namespace detail
} // namespace hwy

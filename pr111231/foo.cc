#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace hwy {
namespace detail {
struct TypeInfo {
  size_t sizeof_t;
  bool is_float;
};

void AssertArrayEqual2(const TypeInfo &ti, const void *a, const void *b,
                       size_t c, const char *, const char *, int) {
  if (memcmp(a, b, c * ti.sizeof_t) != 0) {
	  std::cerr << "lane" << "mismatch" << std::endl;
    abort();
  }
}

} // namespace detail
} // namespace hwy

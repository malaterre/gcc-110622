#include <atomic>
namespace hwy {
struct bfloat16_t {};
} // namespace hwy
void bla(uint16_t *);
hwy::bfloat16_t *__restrict foo_aligned;
void foo() { bla(reinterpret_cast<uint16_t *>(foo_aligned)); }

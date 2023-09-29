#include <cstdint>
namespace n {
#pragma pack(push, 1)
struct bfloat16_t {
  uint16_t bits;
};
#pragma pop(push, 1)
} // namespace n
void bla(uint16_t *) {}
void foo(n::bfloat16_t *__restrict aligned) {
  bla(reinterpret_cast<uint16_t *>(aligned));
}

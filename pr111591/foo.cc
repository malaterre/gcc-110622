#include <cstdlib>
#include <cstring>
#include <memory>
namespace hwy {
using AllocPtr = void *(void *, size_t);
using FreePtr = void (*)(void *, void *);

void *AllocateAlignedBytes(size_t s, AllocPtr, void *) {
  void *memptr = NULL;
  int ret = posix_memalign(&memptr, 64, s);
  if (ret != 0)
    abort();
  return memptr;
}
void FreeAlignedBytes(const void *p, FreePtr, void *) { free((void *)p); }

} // namespace hwy

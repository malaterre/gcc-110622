#include <stdlib.h>
#include <stdint.h>

size_t f(uint16_t *keyc, size_t len)
{
    size_t hash = len;
    len = len / 2;

    for (size_t i = 0; i < len; ++i)
        hash += keyc[i];
    return hash;
}

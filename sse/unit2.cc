#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>

size_t f(uint16_t *keyc, size_t len);

struct mystruct {
    uint8_t padding;
    uint16_t contents[100];
} __attribute__ ((packed));

int main(void)
{
    struct mystruct s;
    size_t len;

    srand(time(NULL));
    scanf("%zu", &len);

    char *initializer = (char *)s.contents;
    for (size_t i = 0; i < len; i++)
       initializer[i] = rand();

    printf("out %zu\n", f(s.contents, len));
}

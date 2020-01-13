#include "libmx.h"

void *mx_memset(void *b, int c, size_t len)  {
    unsigned char *buf = (unsigned char *)b;

    for (size_t i = 0; i < len; i++)
        buf[i] = c;
    return b;
}

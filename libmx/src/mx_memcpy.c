#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *dst1 = (char *)dst;
    char *src1 = (char *)src;

    for (unsigned int i = 0; i < n; i++)
        dst1[i] = src1[i];
    return dst;
}


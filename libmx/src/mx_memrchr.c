#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *str = (unsigned char *)s;

    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == c)
            return (char *)str + i;
    }
    return NULL;
}

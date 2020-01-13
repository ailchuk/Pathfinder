#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *str = (unsigned char *)s;
    unsigned char ch = (unsigned char)c;
    
    if (!n)
        return NULL;
    while (n--) {
        if (*str == ch)
            return ((char *)str);
        str++;
    }
    return NULL;
}


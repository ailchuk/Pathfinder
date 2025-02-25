#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *str1 = (unsigned char *)s1;
    unsigned char *str2 = (unsigned char *)s2;

    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);   
    }
    return 0;
}


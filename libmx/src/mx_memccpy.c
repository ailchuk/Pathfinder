#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	unsigned char *dest = (unsigned char *)dst;
	unsigned char *source = (unsigned char *)src;

	for (size_t i = 0; i < n; dest++, source++, i++) {
		*dest = *source;
		if (*source == (unsigned char)c)
			return (dest + 1);
	}
	return 0;
}

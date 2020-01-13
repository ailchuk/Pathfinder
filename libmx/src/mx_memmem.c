#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const char *cur;
    const char *last;
	const char *str1 = big;
	const char *str2 = little;

	if (little_len == 0)
		return (void *)str1;
	if (big_len < little_len)
		return NULL;
	if (little_len == 1)
		return mx_memchr(big, *str2, big_len);
	last = str1 + big_len - little_len;
	for (cur = str1; cur <= last; cur++)
		if (cur[0] == str2[0] && mx_memcmp(cur, str2, little_len) == 0)
			return (void *)cur;
	return NULL;
}

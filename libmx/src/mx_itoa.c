#include "libmx.h"

static int i_len(int n) {
    int i = 0;

    if (n < 0) {
        n *= -1;
        i++;
    }
    if (n > 0) {
        for(;n / 10 != 0; i++)
            n /= 10;
    }
    return i + 1;
}

char *mx_itoa(int number) {
    long long int n = number;
    size_t len = i_len(n);
    char *str = mx_strnew(len);
    
    if (!str)
        return 0;
    str[len] = '\0';
    if (number == -2147483648)
        return mx_strdup("-2147483648");
    if (n == 0)
        str[0] = 48;
    if (n < 0) {
        str[0] = '-';
        n *= -1;
    }
    while (n > 0) {
        str[--len] = (n % 10) + 48;
        n /= 10;
    }
    return str;
}

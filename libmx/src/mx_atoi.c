#include "libmx.h"

int mx_atoi(const char *str) {
    int i = -1;
    int res = 0;

    while (str[++i]) {
        if (mx_isdigit(str[i]))
            res = res * 10 + str[i] - '0';
        if (!mx_isdigit(str[i]))
            return res;
    }
    return res;
}

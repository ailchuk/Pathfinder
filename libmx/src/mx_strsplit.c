#include "libmx.h"

static int get_word_length(const char *s, char c);

char **mx_strsplit(const char *s, char c) {
    int len = 0;
    int i = 0;
    char **arr = NULL;

    if (!s)
        return NULL;
    arr = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            len = get_word_length(s, c);
            arr[i] = mx_strndup(s, len);
            s += len;
            i++;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    return arr;
}

static int get_word_length(const char *s, char c) {
    int len = 0;
    char *copy = (char *)s;

    while ((*copy != c) && (*copy != '\0')) {
        len++;
        copy++;
    }
    return len;
}

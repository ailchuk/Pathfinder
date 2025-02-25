#include "pathfinder.h"

static void print_invalid(int nline) {
    char *index = NULL;

    nline++;
    index = mx_itoa(nline);
    mx_printerr("error: line ");
    mx_printerr(index);
    mx_printerr(" is not valid\n");
    exit(EXIT_FAILURE);
}

void mx_check_empty_line(char **lines, char *file) {
    char *fl = file;
    char **ln = lines;
    int i = 0;
    int len = 0;

    if (*fl == '\n')
        print_invalid(0);
    while(*fl) {
        if (*fl == '\n' && *(fl+1) == '\n')
            while(ln[i]) {
                len = mx_strlen(ln[i]);
                if (mx_strncmp(fl-len, ln[i], mx_strlen(ln[i])) == 0)
                    print_invalid(i+1);
                i++;
            }
        fl++;
    }
}

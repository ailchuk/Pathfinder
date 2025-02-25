#include "pathfinder.h"

static void print_invalid(int nline) {
    char *index = NULL;

    nline++;
    index = mx_itoa(nline);
    mx_printerr("error: line ");
    mx_printerr(index);
    mx_printerr(" is not valid\n");
    exit(1);
}

static void checkLnSec(char **lines, int n, int i) {
    int copy_i = i;

    while(mx_isalpha(lines[n][copy_i]))
            copy_i++;
    if (copy_i - i == 0 || lines[n][copy_i] != ',')
        print_invalid(n);
    copy_i++;
    i = copy_i;
    while(mx_isdigit(lines[n][copy_i]))
        copy_i++;
    if (copy_i - i == 0 || lines[n][copy_i] != '\0')
        print_invalid(n);
}

static void checkline(char **lines, int nline) {
    int i = 0;
    int copy_i = 0;

    for (int n = 1; n <= nline; n++) {
        i = 0;
        copy_i = 0;
        while(mx_isalpha(lines[n][i]))
            i++;
        if (i == 0 || lines[n][i] != '-')
            print_invalid(n);
        i++;
        checkLnSec(lines, n, i);
    }
}

static void parserr(char *file) {
    char **lines = mx_strsplit(file, '\n');
    int nline = 0;
    int at = 0;

    while (lines[nline])
        nline++;
    if (lines[0][0] == '0') {
        mx_printerr("error: line 1 is not valid\n");
        exit(1);
    }
    while (lines[0][at]) {
        if (!mx_isdigit(lines[0][at])) {
            mx_printerr("error: line 1 is not valid\n");
            exit(1);
        }
        at++;
    }
    checkline(lines, nline-1);
    mx_check_empty_line(lines, file);
    mx_del_strarr(&lines);
}

void mx_errors(int argc, char *file, char **argv) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    if (mx_get_file_length(argv[1]) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    if (!file) {
         mx_printerr("error: file ");
         mx_printerr(argv[1]);
         mx_printerr(" does not exist\n");
         exit(1);
    }
    parserr(file);
}

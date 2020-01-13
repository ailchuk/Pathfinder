#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int num = 0;

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++) {
            if (mx_strcmp(arr[i], arr[j]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                num++;
            }
        }
    return num;
}

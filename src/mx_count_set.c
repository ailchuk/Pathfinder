#include "pathfinder.h"

static void errInvNum(char *nIslands, int count) {
	if (count == 0 || count != mx_atoi(nIslands) || count == 1) {
		mx_printerr("error: invalid number of islands\n");
		exit(EXIT_FAILURE);
	}
}

void mx_count_set(char **arr, char *nIslands, int *count) {
	int j = 0;

	if(arr && *arr) {
		if (arr[0])
			(*count)++;
		for (int i = 1; arr[i] != NULL; i++) {
			if (mx_isdigit(arr[i][0]))
				i++;
			if (arr[i] == NULL)
				break;
			for (j = i - 1; j >= 0; j--) {
				if (mx_strcmp(arr[i], arr[j]) == 0)
					break;
				if (j == 0)
					(*count)++;
			}
		}
	}
	errInvNum(nIslands, *count);
}

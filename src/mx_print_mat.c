#include "pathfinder.h"

void mx_print_mat(int **mat, char **set) {
	int i = 0;
	int k = 0;
	int j = 0;

	while(set[i])
		i++;
	while(k < i) {
		j = 0;
		while(j < i) {
			mx_printint(mat[k][j]);
			mx_printchar(' ');
			j++;
		}
		mx_printchar('\n');
		k++;
	}
}

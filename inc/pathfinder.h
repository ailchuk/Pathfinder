#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_path {
	int bondIsl;
	int bondDist;
	int index;
	struct s_path *nextBond;
	struct s_path *nextPath;
}       t_path;

typedef struct s_island {
	int currentIsl;
	int distTo;
	struct s_path *path;
	struct s_island *next;
}		t_island;

typedef struct s_char {
	char *p;
	char *r;
	char *d;
	int s;
}		t_char;

typedef struct s_int {
	int size;
	int root;
}		t_int;

typedef struct s_md {
	int isl1;
	int isl2;
	int mat;
}		t_md;

typedef struct s_li{
	t_island *un;
	t_island *v;
	t_island *cur;
	t_island *sh;
}		t_li;

void mx_count_set(char **arr, char *nIslands, int *count);
t_li *mx_create_l();
t_island *mx_create_island(int isl, int dist);
void mx_pI(t_island **island, t_path **path, int isl, int dist);
void mx_pop_front_island(t_island **head);
void mx_pop_middle_island(t_island **unvisited, int index);
int mx_addIndexPathes(t_path **path);
void mx_sortPath(t_path **disp, int sizeP);
void mx_join(char **res, char *s2);
void mx_printOutput(t_island **visited, int root, int size, char **set);
void mx_delMat(int ***matrix, char **set);
t_path *mx_create_path(int isl, int dist);
void mx_delPath(t_path **head);
t_path *mx_addPath(t_path **previous, int isl, int dist);
void mx_pushPath(t_path **path, t_path **previous, int isl, int dist);
t_path *mx_copyPath(t_path **data);
int mx_uniquePath(t_path **new, t_path **current);
void mx_check_empty_line(char **lines, char *file);
void mx_errors(int argc, char *file, char **argv);
void mx_parse(char *fd, int ***matrix, char ***set);
void mx_create_arrarr(char **lines, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *nIslands);
int **mx_create_matrix(char **set, char ***arrarr);
void mx_print_mat(int **mat, char **set);
void mx_algo(int **matrix, char **set);
t_island *mx_shortest(t_island **unvisited);

#endif

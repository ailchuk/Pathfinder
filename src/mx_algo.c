#include "pathfinder.h"

static void st(t_island **un, t_island **cur, t_island **v, t_int *in) {
	*un = NULL;
	*v = NULL;

	for (int i = 0; i < in->size; i++)
		mx_pI(&(*un), NULL, i, 0);
	*cur = *un;
	while((*cur)->currentIsl != in->root)
		*cur = (*cur)->next;
	(*cur)->path = mx_create_path(in->root, 0);
	mx_pI(&(*v), &(*cur)->path, (*cur)->currentIsl, (*cur)->distTo);
	mx_pop_middle_island(&(*un), in->root);
	*cur = *v;
}

static void md(t_island **un, t_island **cur, int **mat, t_md **m) {
	t_island *h = *un;

	while (h != NULL) {
		(*m)->isl1 = (*cur)->currentIsl;
		(*m)->isl2 = h->currentIsl;
		(*m)->mat = mat[(*m)->isl1][(*m)->isl2];
		if ((*m)->mat != 0 && h->distTo == 0) {
			h->distTo = (*cur)->distTo + (*m)->mat;
			h->path = mx_addPath(&(*cur)->path, (*m)->isl2, (*m)->mat);
		} else if ((*m)->mat != 0) {
			if ((*cur)->distTo + (*m)->mat == h->distTo)
				mx_pushPath(&h->path, &(*cur)->path, (*m)->isl2, (*m)->mat);
			if ((*cur)->distTo + (*m)->mat < h->distTo) {
				h->distTo = (*cur)->distTo + (*m)->mat;
				mx_delPath(&h->path);
				h->path = mx_addPath(&(*cur)->path, (*m)->isl2, (*m)->mat);
			}
		}
		h = h->next;
	}
}

static void lt(t_li **l, int **matrix, char **set) {
	(*l)->sh = mx_shortest(&(*l)->un);
	mx_pI(&(*l)->v, &(*l)->sh->path, (*l)->sh->currentIsl, (*l)->sh->distTo);
	mx_pop_middle_island(&(*l)->un, (*l)->sh->currentIsl);
	(*l)->cur = (*l)->cur->next;
	if ((*l)->cur->path == NULL) {
		mx_delMat(&matrix, set);
		mx_printerr("error: two islands has not a path between them\n");
		exit(EXIT_FAILURE);
	}
}

static void deixtra(int **matrix, char **set, t_int *in) {
	t_li *l = mx_create_l();
	t_md *m = NULL;

	st(&l->un, &l->cur, &l->v, in);
	while (l->un && l->un != NULL) {
		m = malloc(sizeof(t_md));
		md(&l->un, &l->cur, matrix, &m);
		free(m);
		m = NULL;
		lt(&l, matrix, set);
	}
	mx_printOutput(&l->v, in->root+1, in->size, set);
	while (l->v != NULL) {
		mx_delPath(&l->v->path);
		mx_pop_front_island(&l->v);
	}
	free(l);
	l = NULL;
}

void mx_algo(int **matrix, char **set) {
	int size = 0;
	int i = 0;
	t_int *in = malloc(sizeof(t_int));

	while (set[size])
		size++;
	in->size = size;
	while (i < size - 1) {
	 	in->root = i;
		deixtra(matrix, set, in);
		i++;
	 }
	 free(in);
	 in = NULL;
}

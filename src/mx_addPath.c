#include "pathfinder.h"

static void addLink(t_path **cur, t_path **new) {
	t_path *current = *cur;

	while(current->nextBond) {
		current->nextPath = *new;
		current = current->nextBond;
	}
	current->nextPath = *new;
}

static t_path *addOnePath(t_path **previous, int isl, int dist) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	if (!last)
		return res = mx_create_path(isl, dist);
	res = mx_create_path(last->bondIsl, last->bondDist);
	new = res;
	last = last->nextBond;
	while (last) {
		new->nextBond = mx_create_path(last->bondIsl, last->bondDist);
		last = last->nextBond;
		new = new->nextBond;
	}
	new->nextBond = mx_create_path(isl, dist);
	return res;
}

t_path *mx_addPath(t_path **previous, int isl, int dist) {
	t_path *cur = NULL;
	t_path *res = NULL;
	t_path *new = NULL;
	t_path *fast = NULL;

	if (*previous)
		cur = *previous;
	res = addOnePath(&cur, isl, dist);
	fast = res;
	if (cur)
		cur = cur->nextPath;
	while (cur) {
		new = addOnePath(&cur, isl, dist);
		addLink(&fast, &new);
		fast = fast->nextPath;
		cur = cur->nextPath;
	}
	return res;
}

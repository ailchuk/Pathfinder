#include "pathfinder.h"

static void addLink(t_path **cur, t_path **new) {
	t_path *current = *cur;

	while(current->nextBond) {
		current->nextPath = *new;
		current = current->nextBond;
	}
	current->nextPath = *new;
}

static t_path *addOne(t_path **previous) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	res = mx_create_path(last->bondIsl, last->bondDist);
	new = res;
	last = last->nextBond;
	while (last) {
		new->nextBond = mx_create_path(last->bondIsl, last->bondDist);
		last = last->nextBond;
		new = new->nextBond;
	}
	return res;
}

t_path *mx_copyPath(t_path **data) {
	t_path *cur = NULL;
	t_path *res = NULL;
	t_path *new = NULL;
	t_path *fast = NULL;

	if (*data)
		cur = *data;
	res = addOne(&cur);
	fast = res;
	cur = cur->nextPath;
	while (cur) {
		new = addOne(&cur);
		addLink(&fast, &new);
		fast = fast->nextPath;
		cur = cur->nextPath;
	}
	return res;
}

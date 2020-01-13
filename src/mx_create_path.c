#include "pathfinder.h"

t_path *mx_create_path(int isl, int dist) {
	t_path *node = (t_path *)malloc(1 * sizeof(t_path));

	node->bondIsl = isl;
	node->bondDist = dist;
	node->nextBond = NULL;
	node->nextPath = NULL;
	return node;
}

#include "pathfinder.h"

static void compare(t_path **newOne, t_path **curOne, int *flag) {
	if (*newOne && *curOne) {
		if ((*newOne)->bondIsl != (*curOne)->bondIsl)
			*flag = 1;
		if ((*newOne)->bondDist != (*curOne)->bondDist)
			*flag = 1;
	}
	if (!(*newOne) || !(*curOne))
		*flag = 1;
}

static void step(t_path **oldOne, t_path **path, t_path **new) {
	*path = *new;
	*oldOne = (*oldOne)->nextPath;
}

int mx_uniquePath(t_path **new, t_path **current) {
	int flag = -1;
	t_path *path = *new;
	t_path *oldOne = *current;

	while (oldOne) {
		if (oldOne->nextBond == NULL || !path) {
			compare(&path, &oldOne, &flag);
			step(&oldOne, &path, &(*new));
			if (flag == -1)
				return -1;
			if (oldOne)
				flag = -1;
			continue;
		}
		compare(&path, &oldOne, &flag);
		path = path->nextBond;
		oldOne = oldOne->nextBond;
	}
	return flag;
}

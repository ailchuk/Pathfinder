#include "pathfinder.h"

static void addLink(t_path **cur, t_path **new) {
	t_path *current = *cur;

	while(current->nextBond) {
		current->nextPath = *new;
		current = current->nextBond;
	}
	current->nextPath = *new;
}

static int cmp(t_path *bond, t_path *fast) {
	while (bond && fast) {
		if (bond->bondIsl > fast->bondIsl)
			return 1;
		if (bond->bondIsl < fast->bondIsl)
			return 0;
		bond = bond->nextBond;
		fast = fast->nextBond;
	}
	if (bond && !fast)
		return 1;
	return 0;
}

static void swpD(t_path **disp, t_path **bond, t_path **fast) {
	t_path *temp = (*fast)->nextPath;
	t_path *cur = *disp;

	while(cur->nextPath != *fast)
		cur = cur->nextPath;
	addLink(&cur, &(*bond));
	cur = *disp;
	if (*disp == *bond)
		*disp = *fast;
	else {
		while(cur && cur->nextPath != *bond)
			cur = cur->nextPath;
		addLink(&cur, &(*fast));
	}
	addLink(&(*fast), &(*bond)->nextPath);
	addLink(&(*bond), &temp);
}

static void swp(t_path **disp, t_path **bond, t_path **fast) {
	t_path *temp = (*fast)->nextPath;
	t_path *cur = *disp;

	if ((*bond)->nextPath == *fast) {
			addLink(&(*fast), &(*bond));
			addLink(&(*bond), &temp);
		if (*disp == *bond)
			*disp = *fast;
		else {
			while(cur && cur->nextPath != *bond)
				cur = cur->nextPath;
			addLink(&cur, &(*fast));
		}
	}
	else 
		swpD(&(*disp), &(*bond), &(*fast));
}

void mx_sortPath(t_path **disp, int sizeP) {
	t_path *bond = *disp;
	t_path *fast = (*disp)->nextPath;

	for(int i = 0; i < sizeP; i++) {
		bond = *disp;
		fast = bond->nextPath;
		for (; bond->index != i; bond = bond->nextPath)
			fast = bond->nextPath;
		while(fast) {
			if (cmp(bond, fast) == 1) {
				swp(&(*disp), &bond, &fast);
				for (bond = *disp; bond->index != i; bond = bond->nextPath)
					fast = bond->nextPath;
			}
			else
				fast = fast->nextPath;
		}
	}
}

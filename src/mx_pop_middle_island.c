#include "pathfinder.h"

static void popOne (t_island **temp, t_island **leftOne) {
	(*leftOne)->next = (*temp)->next;
	mx_delPath(&(*temp)->path);
	free(*temp);
	*temp = NULL;
}

void mx_pop_middle_island(t_island **unvisited, int index) {
	t_island *temp = NULL;
	t_island *leftOne = NULL;

	if (!unvisited || !(*unvisited))
		return;
	if ((*unvisited)->currentIsl == index) {
		mx_delPath(&((*unvisited)->path));
		mx_pop_front_island(&(*unvisited));
	}
	else {
		temp = *unvisited;
		leftOne = temp;
		while (temp != NULL && temp->currentIsl != index) {
			leftOne = temp;
			temp = temp->next;
		}
		if (temp && temp->currentIsl == index) {
			popOne(&temp, &leftOne);
		}
	}
}

#include "pathfinder.h"

t_island *mx_shortest(t_island **unvisited) {
	t_island *head = NULL;
	t_island *shortest = NULL;

	if (unvisited || *unvisited) {
		head = *unvisited;
		shortest = *unvisited;
		while(head) {
			if (head->distTo != 0)
			if (shortest->distTo > head->distTo || !shortest->distTo)
				shortest = head;
			head = head->next;
		}
	}
	return shortest;
}

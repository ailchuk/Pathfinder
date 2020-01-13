#include "pathfinder.h"

static void pop_allBond(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head))
        return;
    while ((*head)->nextBond) {
        p = (*head)->nextBond;
        free(*head);
        *head = p;
    }
    if (!(*head)->nextBond && !(*head)->nextPath) {
        free(*head);
        *head = NULL;
        return;
    }
}

static void pop_nextPath(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head))
        return;
    if ((*head)->nextPath == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        p = (*head)->nextPath;
        free(*head);
        *head = p;
    }
}

void mx_delPath(t_path **head) {
	if (!head || !(*head))
        return;
    while(*head) {
        pop_allBond(&(*head));
    	pop_nextPath(&(*head));
    }
}

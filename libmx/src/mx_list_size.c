#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *node = list;
    int size = 0;

	while (node && node != NULL) {
            size++;
	    node = node->next;
	}
    return size;
}

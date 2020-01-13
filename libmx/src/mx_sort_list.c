#include "libmx.h"

static void swap(void **l1, void **l2) {
    void *tmp = *l1;
    *l1 = *l2;
    *l2 = tmp;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    t_list *head = NULL, *store = list, *tmp = list;

    while(list) {
        head = store;
        while(head) {
            if(head->next && cmp(head->data,head->next->data))
                swap(&head->data, &head->next->data);
            head = head->next;
        }
        list = list->next;
    }
    return tmp;
}

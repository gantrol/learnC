#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include "dbg.h"
#include "list_algos.h"

void swap(ListNode *a, ListNode *b) {
    void *tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}

int List_bubble_sort(List *list, List_compare lcmp) {
    if (list->count == 0) {
        return 0;
    }
    LIST_FOREACH(list, first, next, c) {
        LIST_FOREACH(list, first, next, cur) {
            if (cur->next  && lcmp(cur->value, cur->next->value) > 0) {
                swap(cur, cur->next);
            }
        }
    }
    return 0;
}

List *List_merge(List *s_left, List *s_right, List_compare lcmp) {
    List *result = List_create();

    while (List_count(s_left) > 0 || List_count(s_right) > 0) {
        if (List_count(s_left) > 0 && List_count(s_right) > 0) {
            if (lcmp(s_left->first->value, s_right->first->value) <= 0) {
                List_push(result, List_shift(s_left));
            } else {
                List_push(result, List_shift(s_right));
            }
        } else if (List_count(s_left) > 0) {
            List_push(result, List_shift(s_left));
        } else {
            List_push(result, List_shift(s_right));
        }
    }

    return result;
}


List *List_merge_sort(List *list, List_compare lcmp) {
    if (List_count(list) < 2) {
        return list;
    }
    List *result = NULL;

    List *left = List_create();
    List *right = List_create();
    int mid = List_count(list) / 2;
    LIST_FOREACH(list, first, next, cur) {
        if (mid > 0) {
            List_push(left, cur->value);
        } else {
            List_push(right, cur->value);
        }
        mid--;
    }

    List *sorted_left = List_merge_sort(left, lcmp);
    List *sorted_right = List_merge_sort(right, lcmp);

    if (sorted_left != left)  // why?
        free(left);
    if (sorted_right != right)
        free(right);

    result = List_merge(sorted_left, sorted_right, lcmp);

    List_destroy(sorted_left);
    List_destroy(sorted_right);

    return result;
}


#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        if (cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_clear(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }
}

void List_clear_destroy(List *list)
{
    List_clear(list);
    List_destroy(list);
}

void List_push(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        // list->last = list->last->next;
        list->last = node;
    }

    list->count++;
error:
    return;
}

void *List_pop(List *list)
{
    void *result = NULL;
    ListNode *last = list->last;
    check(last, "last can't be NULL");

    if (list->count == 1) {
        check(list->first == list->last, "length of list == 1, but list->first != list->last")
        list->first = NULL;
        list->last = NULL;
    } else {
        list->last = last->prev;
        check(list->last != NULL, "Invalid list whose last is NULL.");
        list->last->next = NULL;
        last->prev = NULL;
    }
    list->count--;
    result = last->value;
    free(last);
    return result;
error:
    return NULL;
}

void List_unshift(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void *List_shift(List *list)
{
    void *result = NULL;
    ListNode *first = list->first;
    check(first, "first can't be NULL");
    if (list->count == 1) {
        check(list->first == list->last, "length of list == 1, but list->first != list->last")
        list->first = NULL;
        list->last = NULL;
    } else {
        list->first = first->next;
        check(list->first != NULL, "Invalid list whose first is NULL.");
        list->first->prev = NULL;
    }
    list->count--;
    result = first->value;
    free(first);
    return result;

error:
    return NULL;  //  ???
}

void *List_remove(List *list, ListNode *node)
{
    void *result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "node can't be NULL");

    if (node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if (node == list->first) {
        List_shift(list);
    } else if (node == list->last) {
        List_pop(list);
    } else {
        ListNode *before = node->prev;
        ListNode *after = node->next;
        before->next = after;
        after->prev = before;
    }
    list->count--;
    result = node->value;  //???
    free(node);
error:
    return result;
}
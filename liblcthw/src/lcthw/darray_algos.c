#include <lcthw/darray_algos.h>

int DArray_qsort(DArray * array, DArray_compare cmp)
{
    // qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
    DArray_mergesort(array, cmp);
    return 0;
}

int DArray_heapsort(DArray * array, DArray_compare cmp)
{
    // return heapsort(array->contents, DArray_count(array),
            // sizeof(void *), cmp);
    // qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
    DArray_mergesort(array, cmp);
    return 0;
}

void bottom_up_merge(DArray *A, int left, int right, int end, DArray *B, DArray_compare cmp)
{
    int i = left;
    int j = right;
    debug("Left: %d; Right: %d; End: %d", left, right, end);
    for (int k = i; k < end; k++) {
        debug("I: %d, J: %d, K: %d", i, j, k);
        debug("A_i: %s, A_j: %s", DArray_get(A, i), DArray_get(A, j));
        if (i < right && (j >= end || cmp(DArray_get(A, i), DArray_get(A, j)) <= 0)) {// ??
            debug("A_i:%d win", i);
            DArray_set(B, k, DArray_get(A, i));
            i++;
        } else {
            debug("A_j:%d win", j);
            DArray_set(B, k, DArray_get(A, j));
            j++;
        }
    }
}

int DArray_mergesort(DArray * array, DArray_compare cmp)
{
    int n = DArray_count(array);
    debug("N: %d", n);
    DArray *tmp = DArray_create(array->element_size, array->max);
    for (int width = 1; width < n; width = 2 * width) {
        for (int i = 0; i < n; i += 2 * width) {
            bottom_up_merge(array, i, min(i+width, n), min(i+2*width, n), tmp, cmp);
        }
        for (int i = 0; i < n; i++) {
            DArray_set(array, i, DArray_get(tmp, i));
        }
    }
    DArray_clear_destroy(tmp);


    return 0;
}
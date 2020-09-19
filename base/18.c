#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

typedef int (*compare_cb)(int a, int b);
typedef int *(*sort_cb)(int *numbers, int count, compare_cb cmp);

int *bubble_sort(int *numbers, int count, compare_cb cmp) {
    int *result = malloc(count * sizeof(int));
    memcpy(result, numbers, count * sizeof(int));
    if (!result) { die("Memory Error!"); }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (cmp(result[i], result[j])) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    return result;
}

int *insert_sort(int *numbers, int count, compare_cb cmp) {
    int *result = malloc(count * sizeof(int));
    memcpy(result, numbers, count * sizeof(int));
    if (!result) { die("Memory Error"); }


    for (int i = 0; i < count; i++) {
        int min = i;
        for (int j = i + 1; j < count; j++) {
            if (cmp(result[min], result[j])) {
                min = j;
            }
        }
        int temp = result[i];
        result[i] = result[min];
        result[min] = temp;
    }

    return result;
}

int ascend(int a, int b) {
    return a >= b;
}

void ascend1(int a, int b) {
    printf("a > b");
}

int descend(int a, int b) {
    return a <= b;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b % 2;
    }
}

/** 
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int *result = bubble_sort(numbers, count, cmp);

    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

}

void dump(compare_cb cmp) {

    unsigned char *data = (unsigned char *)cmp;
    check(data, "Data %p:%s is null, stop!!!", data, data);
    

    for(int i = 0; i < 25; i++) {
        printf("%02x ", data[i]);
    }

    printf("\n");
error:
    printf("\n");
}

void sorting(int *numbers, int count, sort_cb sort, compare_cb cmp) {
    int *result = sort(numbers, count, cmp);

    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ./18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }
    // test_sorting(numbers, count, NULL);
    // test_sorting(numbers, count, ascend1);
    // test_sorting(numbers, count, ascend);
    // test_sorting(numbers, count, descend);
    // test_sorting(numbers, count, strange_order);
    sorting(numbers, count, insert_sort, ascend);
    sorting(numbers, count, insert_sort, descend);
    sorting(numbers, count, insert_sort, strange_order);

    dump(NULL);
    dump(ascend);

    sorting(numbers, count, bubble_sort, ascend);
    sorting(numbers, count, bubble_sort, descend);
    sorting(numbers, count, bubble_sort, strange_order);

    free(numbers);

    return 0;
}
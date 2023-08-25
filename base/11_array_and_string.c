/**
 * String in C was stored as a char array, terminated with a null char('\0').
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    // request 4 numbers space
    int count = 4;
    int *numbers = malloc(count * sizeof(int));
    numbers[0] = 1;
    // request 4 chars space
    char *name = malloc(count * sizeof(char));
    name[0] = 'a';

    assert(numbers[0] == 1);
    assert(numbers[1] == 0);
    assert(numbers[2] == 0);
    assert(numbers[3] == 0);
    assert(name[0] == 'a');
    assert(name[1] == '\0');
    assert(name[2] == '\0');
    assert(name[3] == '\0');

    numbers[0] = 0;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    name[0] = 'b';
    name[1] = 'c';
    name[2] = 'd';
    name[3] = '\0';
    assert(numbers[0] == 0);
    assert(numbers[1] == 2);
    assert(numbers[2] == 3);
    assert(numbers[3] == 4);
    assert(name[0] == 'b');
    assert(name[1] == 'c');
    assert(name[2] == 'd');
    assert(name[3] == '\0');

}
/**
 * String in C was stored as a char array, terminated with a null char('\0').
 */
#include <stdio.h>
#include <assert.h>

int main() {
    // request 4 numbers space
    int numbers[4] = {1};
    // request 4 chars space
    char name[4] = {'a'};

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
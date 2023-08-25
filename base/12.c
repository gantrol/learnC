#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = { 10, 12, 13, 14, 20 };
    char name[] = "Gantrol";
    char full_name[] = {
            'G', 'a', 'n', 't', 'r', 'o', 'l',
            ' ', 'Q', '.', ' ',
            'H', 'w', 'a', 'n', 'g', '\0'
    };

    // WARNING: IF %ld wrong, then change it into %u (use unsigned ints instead)
    //
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n",
           sizeof(areas) / sizeof(int));
    printf("areas[1] is %d, areas[2] is %d\n", areas[1], areas[2]);

    printf("The size of the char: %ld\n", sizeof(char));
    printf("The size of the name (char[]): %ld\n", sizeof(name));
    printf("The number of char: %ld\n", sizeof(name) / sizeof(char));

    printf("The size of the full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n",
           sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
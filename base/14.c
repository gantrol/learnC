#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

// forward declarations
void print_letters(char arg[], int length);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++) {
        char *arg = argv[i];
        print_letters(arg, strlen(arg));
    }
}

void print_letters(char arg[], int length)
{
    int i = 0;
    for (i = 0; i < length; i++) {
        char ch = arg[i];
        if (isalnum((int) ch) || iswblank((int) ch)) {
            // if (isalpha((int)ch) || isblank((int)ch)) {
            printf("'%c' == '%d'", ch, ch);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}

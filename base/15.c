#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int count = 5;
    int ages[] = {31, 29, 25, 28, 28};
    char *names[] = {
            "蠢狗君", "大明",
            "小黄", "小明", "小红"
    };

    // safely get the size of ages
    int i;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s活了 %d 年。\n", names[i], ages[i]);
    }

    printf("---\n");

    // second way using pointers
    for (i = 0; i < count; i++) {
        printf("%s活了 %d 年。\n",
                names[i], ages[i]);
    }

    printf("---\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", names[i], ages[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    // try rewriting the loops so that they start at the end of the arrays and go to the beginning.
    for (i = count - 1;
         i >= 0; i--) {
        printf("%s lived %d years so far.\n", names[i], ages[i]);
    }

    return 0;
}

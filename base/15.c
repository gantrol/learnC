#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {31, 29, 25, 28, 28};
    char *names[] = {
            "蠢狗君", "大明",
            "小黄", "小明", "小红"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int); // TODO: why?
    int i;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s活了 %d 年。\n", names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names; // TODO: why not []?

    // second way using pointers
    for (i = 0; i < count; i++) {
        printf("%s活了 %d 年。\n",
               *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    // ry rewriting the loops so that they start at the end of the arrays and go to the beginning.
    for (cur_name = (names + count - 1), cur_age = (ages + count - 1);
         (cur_age - ages) >= 0; cur_name--, cur_age--) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}

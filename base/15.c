#include <stdio.h>

void print_array_pointer(int count, int ages[], char * names[])
{
    int i;
    for (i = 0; i < count; i++) {
        printf("%s活了 %d 年。\n", names[i], ages[i]);
    }
    printf("---\n");
}

void print_array_pointer_2(int count, int * cur_age, char ** cur_name)
{
    int i;
    for (i = 0; i < count; i++) {
        printf("%s活了 %d 年。\n",
               *(cur_name + i), *(cur_age + i));
    }
    printf("---\n");
}

void print_array_pointer_3(int count, int * cur_age, char **cur_name)
{
    int i;
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }
    printf("---\n");
}

void print_array_pointer_4(int count, int ages[], char * names[])
{
    int *cur_age = ages;
    char **cur_name = names;
    while ((cur_age - ages) < count) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
        cur_age++;
        cur_name++;
    }
    printf("---\n");
}

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
    print_array_pointer(count, ages, names);


    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names; // TODO: why not []?

    // second way using pointers
    print_array_pointer_2(count, cur_age, cur_name);

    // third way, pointers are just arrays
    print_array_pointer_3(count, cur_age, cur_name);

    // fourth way with pointers in a stupid complex way
    print_array_pointer_4(count, cur_age, cur_name);

    for (cur_name = names, cur_age = ages, i = 0; i < count; i++) {
        printf("地址 %p 活了 %d 年\n", *(cur_name + i), *(cur_age + i));
    }
    return 0;
}

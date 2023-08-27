#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    if (who != NULL) {
        free(who->name); // 漏了
        free(who);
    }
}

void Person_print(struct Person *who)
{
    if (who != NULL) {
        printf("Name: %s\n", who->name);
        printf("\tAge: %d\n", who->age);
        printf("\tWeight: %d\n", who->weight);
        printf("\tHeight: %d\n", who->height);
        printf("\tAt memory: %p\n", who);
    }
}

int main(int argc, char** argv)
{
    struct Person *dog = Person_create("蠢狗君", 31, 70, 173);
    struct Person *ming = Person_create("ming", 26, 65, 180);

    Person_print(dog);
    Person_print(ming);

    dog->age += 20;
    dog->height += 1;
    dog->weight += 5;
    Person_print(dog);

    ming->age += 10;
    ming->height += 5;
    ming->weight += 20;
    Person_print(ming);

    Person_destroy(dog);
    Person_destroy(ming);

    return 0;

}
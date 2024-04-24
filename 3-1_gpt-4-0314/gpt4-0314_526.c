#include <stdio.h>
#include <string.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main()
{
    char name[] = "John Doe";
    person p1 = {25, 'm'};
    memcpy(p1.name, name, sizeof(name));

    printf("Name: %s, Age: %d, Sex: %c\n", p1.name, p1.age, p1.sex);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main()
{
    char name[] = "John Doe";
    person *p1 = malloc(sizeof(person) + sizeof(name));
    p1->age = 25;
    p1->sex = 'm';
    memcpy(p1->name, name, sizeof(name));

    printf("Name: %s, Age: %d, Sex: %c\n", p1->name, p1->age, p1->sex);

    free(p1);
    return 0;
}

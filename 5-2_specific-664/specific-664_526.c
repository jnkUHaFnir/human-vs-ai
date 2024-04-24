#include <stdio.h>

typedef struct _person {
    int age;
    char sex;
    char name[]; // flexible array member
} person;

#define PERSON_SIZE 20 // Define a maximum size for the name array

int main() {
    struct {
        person p;
        char name_buffer[PERSON_SIZE]; // Buffer to hold the name data
    } p1 = {{25, 'M'}, "John Doe"};

    // Accessing and printing the values
    printf("Age: %d\n", p1.p.age);
    printf("Sex: %c\n", p1.p.sex);
    printf("Name: %s\n", p1.p.name);

    return 0;
}

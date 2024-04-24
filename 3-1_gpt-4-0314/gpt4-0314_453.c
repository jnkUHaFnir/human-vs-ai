#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char surname[50];
    char UUN[10];
    char department[50];
    char gender;
    int age;
} student_t;

int main(void) {
    int i, len;
    student_t student_t[6];

    student_t[0].name = "John";
    student_t[0].surname = "Bishop";
    // ...
    strcpy(student_t[0].name, "John");
    strcpy(student_t[0].surname, "Bishop");
    strcpy(student_t[0].UUN, "s1234");
    strcpy(student_t[0].department, "Inf");
    student_t[0].gender = 'm';
    student_t[0].age = 18;

    // ...

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf(" %s", student_t[i].name);
        printf("Enter your surname: ");
        scanf(" %s", student_t[i].surname);
        printf("Enter your UUN: ");
        // ...
        scanf(" %s", student_t[i].UUN);
        printf("Enter your department: ");
        scanf(" %s", student_t[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student_t[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student_t[i].age);
    }

    return EXIT_SUCCESS;
}

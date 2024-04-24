#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *surname;
    char *UUN;
    char *department;
    char gender;
    int age;
} student_t;

int main(void) {
    int i;
    student_t student[6];

    student[0].name = strdup("John");
    student[0].surname = strdup("Bishop");
    student[0].UUN = strdup("s1234");
    student[0].department = strdup("Inf");
    student[0].gender = 'm';
    student[0].age = 18;

    student[1].name = strdup("Lady");
    student[1].surname = strdup("Cook");
    student[1].UUN = strdup("s2345");
    student[1].department = strdup("Eng");
    student[1].gender = 'f';
    student[1].age = 21;

    student[2].name = strdup("James");
    student[2].surname = strdup("Jackson");
    student[2].UUN = strdup("s3456");
    student[2].department = strdup("Eng");
    student[2].gender = 'm';
    student[2].age = 17;

    for (i = 3; i < 6; i++) {
        student[i].name = malloc(100);  // Allocate memory for the string members
        student[i].surname = malloc(100);
        student[i].UUN = malloc(20);   // UUN seems to have max length of 20
        student[i].department = malloc(100);

        printf("Enter your name: ");
        scanf(" %99s", student[i].name);  // Read input and limit the length
        printf("Enter your surname: ");
        scanf(" %99s", student[i].surname);  
        printf("Enter your UUN: ");
        scanf(" %19s", student[i].UUN);  
        printf("Enter your department: ");
        scanf(" %99s", student[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender);
        printf("Enter your age: ");
        scanf("%d", &student[i].age);
    }

    // Free dynamically allocated memory
    for (i = 0; i < 6; i++) {
        free(student[i].name);
        free(student[i].surname);
        free(student[i].UUN);
        free(student[i].department);
    }

    return EXIT_SUCCESS;
}

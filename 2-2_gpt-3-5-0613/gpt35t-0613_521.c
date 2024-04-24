#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* surname;
    char* UUN;
    char* department;
    char gender;
    int age;
} student_t;

int main(void) {
    int i;
    student_t students[6];

    // Initialize the existing students
    students[0].name = strdup("John");
    students[0].surname = strdup("Bishop");
    students[0].UUN = strdup("s1234");
    students[0].department = strdup("Inf");
    students[0].gender = 'm';
    students[0].age = 18;

    students[1].name = strdup("Lady");
    students[1].surname = strdup("Cook");
    students[1].UUN = strdup("s2345");
    students[1].department = strdup("Eng");
    students[1].gender = 'f';
    students[1].age = 21;

    students[2].name = strdup("James");
    students[2].surname = strdup("Jackson");
    students[2].UUN = strdup("s3456");
    students[2].department = strdup("Eng");
    students[2].gender = 'm';
    students[2].age = 17;

    // Collect input for new students
    for (i = 3; i < 6; i++) {
        char input[100];

        printf("Enter your name: ");
        scanf(" %99s", input);
        students[i].name = strdup(input);

        printf("Enter your surname: ");
        scanf(" %99s", input);
        students[i].surname = strdup(input);

        printf("Enter your UUN: ");
        scanf(" %99s", input);
        students[i].UUN = strdup(input);

        printf("Enter your department: ");
        scanf(" %99s", input);
        students[i].department = strdup(input);

        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);

        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // Print all students
    for (i = 0; i < 6; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Surname: %s\n", students[i].surname);
        printf("UUN: %s\n", students[i].UUN);
        printf("Department: %s\n", students[i].department);
        printf("Gender: %c\n", students[i].gender);
        printf("Age: %d\n", students[i].age);
        printf("------------------\n");
    }

    // Free the memory allocated for strings
    for (i = 0; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return 0;
}

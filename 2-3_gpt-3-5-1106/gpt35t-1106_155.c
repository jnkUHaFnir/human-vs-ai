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
    student_t students[6];

    students[0].name = strdup("John");
    students[0].surname = strdup("Bishop");
    students[0].UUN = strdup("s1234");
    students[0].department = strdup("Inf");
    students[0].gender = 'm';
    students[0].age = 18;

    // Similar initializations for students[1] and students[2]

    for (i = 3; i < 6; i++) {
        students[i].name = malloc(50 * sizeof(char)); // Allocate memory for name
        printf("Enter your name: ");
        scanf("%s", students[i].name);

        students[i].surname = malloc(50 * sizeof(char)); // Allocate memory for surname
        printf("Enter your surname: ");
        scanf("%s", students[i].surname);

        students[i].UUN = malloc(10 * sizeof(char)); // Allocate memory for UUN
        printf("Enter your UUN: ");
        scanf("%s", students[i].UUN);

        students[i].department = malloc(50 * sizeof(char)); // Allocate memory for department
        printf("Enter your department: ");
        scanf("%s", students[i].department);

        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // Your code for processing the student data goes here

    // It's important to free the memory allocated using malloc and strdup
    for (i = 0; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

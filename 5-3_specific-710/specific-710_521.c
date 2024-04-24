#include <stdio.h>
#include <stdlib.h>

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

    for (i = 0; i < 3; i++) {
        students[i].name = strdup("John");
        students[i].surname = strdup("Bishop");
        students[i].UUN = strdup("s1234");
        students[i].department = strdup("Inf");
        students[i].gender = 'm';
        students[i].age = 18;
    }

    for (i = 3; i < 6; i++) {
        students[i].name = malloc(sizeof(char) * 100);
        printf("Enter your name: ");
        scanf(" %99s", students[i].name);

        students[i].surname = malloc(sizeof(char) * 100);
        printf("Enter your surname: ");
        scanf(" %99s", students[i].surname);

        students[i].UUN = malloc(sizeof(char) * 100);
        printf("Enter your UUN: ");
        scanf(" %99s", students[i].UUN);

        students[i].department = malloc(sizeof(char) * 100);
        printf("Enter your department: ");
        scanf(" %99s", students[i].department);

        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &students[i].age);
    }

    // Free dynamically allocated memory
    for (i = 0; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

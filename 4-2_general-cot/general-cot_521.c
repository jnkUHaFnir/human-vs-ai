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

    for (i = 0; i < 6; i++) {
        students[i].name = (char *)malloc(50 * sizeof(char)); // Allocate memory for name
        students[i].surname = (char *)malloc(50 * sizeof(char)); // Allocate memory for surname
        students[i].UUN = (char *)malloc(10 * sizeof(char)); // Allocate memory for UUN
        students[i].department = (char *)malloc(50 * sizeof(char)); // Allocate memory for department

        printf("Enter your name: ");
        scanf(" %49s", students[i].name);
        printf("Enter your surname: ");
        scanf(" %49s", students[i].surname);
        printf("Enter your UUN: ");
        scanf(" %9s", students[i].UUN);
        printf("Enter your department: ");
        scanf(" %49s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &students[i].age);
    }

    // Free allocated memory
    for (i = 0; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

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
    student_t student_t[6];

    for (i = 0; i < 6; i++) {
        student_t[i].name = malloc(256); // Allocate memory for name
        student_t[i].surname = malloc(256); // Allocate memory for surname
        student_t[i].UUN = malloc(256); // Allocate memory for UUN
        student_t[i].department = malloc(256); // Allocate memory for department

        if (student_t[i].name == NULL || student_t[i].surname == NULL || student_t[i].UUN == NULL || student_t[i].department == NULL) {
            // Handle allocation failure
            printf("Memory allocation failed!\n");
            return EXIT_FAILURE;
        }

        printf("Enter your name: ");
        scanf(" %s", student_t[i].name);
        printf("Enter your surname: ");
        scanf(" %s", student_t[i].surname);
        printf("Enter your UUN: ");
        scanf(" %s", student_t[i].UUN);
        printf("Enter your department: ");
        scanf(" %s", student_t[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student_t[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student_t[i].age);
    }

    // Free allocated memory
    for (i = 0; i < 6; i++) {
        free(student_t[i].name);
        free(student_t[i].surname);
        free(student_t[i].UUN);
        free(student_t[i].department);
    }

    return EXIT_SUCCESS;
}

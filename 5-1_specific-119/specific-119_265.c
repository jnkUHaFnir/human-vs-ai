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
        student_t[i].name = malloc(50 * sizeof(char)); // Allocate memory for name
        student_t[i].surname = malloc(50 * sizeof(char)); // Allocate memory for surname
        student_t[i].UUN = malloc(10 * sizeof(char)); // Allocate memory for UUN

        printf("Enter your name: ");
        scanf(" %49s", student_t[i].name); // Limit input size to avoid buffer overflow

        printf("Enter your surname: ");
        scanf(" %49s", student_t[i].surname); // Limit input size to avoid buffer overflow

        printf("Enter your UUN: ");
        scanf(" %9s", student_t[i].UUN); // Limit input size to avoid buffer overflow

        // Additional input for department, gender, and age can be added here

        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < 6; i++) {
        free(student_t[i].name);
        free(student_t[i].surname);
        free(student_t[i].UUN);
    }

    return EXIT_SUCCESS;
}

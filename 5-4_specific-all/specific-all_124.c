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

    for (i = 0; i < 3; i++) {
        student_t[i].name = NULL;
        student_t[i].surname = NULL;
        student_t[i].UUN = NULL;
        
        // Assigning statically allocated values for the first three students
        student_t[i].department = "Inf";
        student_t[i].gender = 'm';
        student_t[i].age = 18 + i;
    }

    for (i = 3; i < 6; i++) {
        student_t[i].name = malloc(50 * sizeof(char)); // Allocating memory for name
        student_t[i].surname = malloc(50 * sizeof(char)); // Allocating memory for surname
        student_t[i].UUN = malloc(10 * sizeof(char)); // Allocating memory for UUN
        
        printf("Enter your name: ");
        scanf(" %49s", student_t[i].name); // Allowing up to 49 characters to avoid buffer overflow
        printf("Enter your surname: ");
        scanf(" %49s", student_t[i].surname);
        printf("Enter your UUN: ");
        scanf(" %9s", student_t[i].UUN);
        
        student_t[i].department = malloc(50 * sizeof(char)); // Allocating memory for department
        printf("Enter your department: ");
        scanf(" %49s", student_t[i].department);
        
        printf("Enter your gender: ");
        scanf(" %c", &student_t[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student_t[i].age);
    }

    // Free dynamically allocated memory
    for (i = 3; i < 6; i++) {
        free(student_t[i].name);
        free(student_t[i].surname);
        free(student_t[i].UUN);
        free(student_t[i].department);
    }

    return EXIT_SUCCESS;
}

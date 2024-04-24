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
    student_t student_data[6];

    // Initialize the first three students
    student_data[0].name = "John";
    student_data[0].surname = "Bishop";
    student_data[0].UUN = "s1234";
    student_data[0].department = "Inf";
    student_data[0].gender = 'm';
    student_data[0].age = 18;

    student_data[1].name = "Lady";
    student_data[1].surname = "Cook";
    student_data[1].UUN = "s2345";
    student_data[1].department = "Eng";
    student_data[1].gender = 'f';
    student_data[1].age = 21;

    student_data[2].name = "James";
    student_data[2].surname = "Jackson";
    student_data[2].UUN = "s3456";
    student_data[2].department = "Eng";
    student_data[2].gender = 'm';
    student_data[2].age = 17;

    // Input data for the remaining students
    for (i = 3; i < 6; i++) {
        student_data[i].name = malloc(100); // Allocate memory for name
        student_data[i].surname = malloc(100); // Allocate memory for surname
        student_data[i].UUN = malloc(100); // Allocate memory for UUN
        student_data[i].department = malloc(100); // Allocate memory for department

        printf("Enter your name: ");
        scanf(" %99s", student_data[i].name);
        printf("Enter your surname: ");
        scanf(" %99s", student_data[i].surname);
        printf("Enter your UUN: ");
        scanf(" %99s", student_data[i].UUN);
        printf("Enter your department: ");
        scanf(" %99s", student_data[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student_data[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student_data[i].age);
    }

    // Free dynamically allocated memory
    for (i = 3; i < 6; i++) {
        free(student_data[i].name);
        free(student_data[i].surname);
        free(student_data[i].UUN);
        free(student_data[i].department);
    }

    return EXIT_SUCCESS;
}

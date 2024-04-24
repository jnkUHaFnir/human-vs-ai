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

    // Initializing the first 3 students
    student_t[0].name = "John";
    student_t[0].surname = "Bishop";
    student_t[0].UUN = "s1234";
    student_t[0].department = "Inf";
    student_t[0].gender = 'm';
    student_t[0].age = 18;

    student_t[1].name = "Lady";
    student_t[1].surname = "Cook";
    student_t[1].UUN = "s2345";
    student_t[1].department = "Eng";
    student_t[1].gender = 'f';
    student_t[1].age = 21;

    student_t[2].name = "James";
    student_t[2].surname = "Jackson";
    student_t[2].UUN = "s3456";
    student_t[2].department = "Eng";
    student_t[2].gender = 'm';
    student_t[2].age = 17;

    // Dynamically allocate memory for the strings
    for (i = 3; i < 6; i++) {
        student_t[i].name = malloc(100); // Allocating memory for 100 characters
        student_t[i].surname = malloc(100);
        student_t[i].UUN = malloc(100);
        student_t[i].department = malloc(100);

        printf("Enter your name: ");
        scanf(" %99s", student_t[i].name); // Limiting input to 99 characters to prevent buffer overflow
        printf("Enter your surname: ");
        scanf(" %99s", student_t[i].surname);
        printf("Enter your UUN: ");
        scanf(" %99s", student_t[i].UUN);
        printf("Enter your department: ");
        scanf(" %99s", student_t[i].department);
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
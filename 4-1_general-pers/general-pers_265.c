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

    // Initialize the static data
    student[0].name = "John";
    student[0].surname = "Bishop";
    student[0].UUN = "s1234";
    student[0].department = "Inf";
    student[0].gender = 'm';
    student[0].age = 18;

    student[1].name = "Lady";
    student[1].surname = "Cook";
    student[1].UUN = "s2345";
    student[1].department = "Eng";
    student[1].gender = 'f';
    student[1].age = 21;

    student[2].name = "James";
    student[2].surname = "Jackson";
    student[2].UUN = "s3456";
    student[2].department = "Eng";
    student[2].gender = 'm';
    student[2].age = 17;

    for (i = 3; i < 6; i++) {
        student[i].name = (char *)malloc(100 * sizeof(char)); // Allocating memory for name
        printf("Enter your name: ");
        scanf(" %99s", student[i].name);

        student[i].surname = (char *)malloc(100 * sizeof(char)); // Allocating memory for surname
        printf("Enter your surname: ");
        scanf(" %99s", student[i].surname);

        student[i].UUN = (char *)malloc(100 * sizeof(char)); // Allocating memory for UUN
        printf("Enter your UUN: ");
        scanf(" %99s", student[i].UUN);

        student[i].department = (char *)malloc(100 * sizeof(char)); // Allocating memory for department
        printf("Enter your department: ");
        scanf(" %99s", student[i].department);

        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student[i].age);
    }

    // Clean up - free allocated memory
    for (i = 3; i < 6; i++) {
        free(student[i].name);
        free(student[i].surname);
        free(student[i].UUN);
        free(student[i].department);
    }

    return EXIT_SUCCESS;
}

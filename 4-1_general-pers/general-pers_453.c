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
        students[i].name = "John";
        students[i].surname = "Bishop";
        students[i].UUN = "s1234";
        students[i].department = "Inf";
        students[i].gender = 'm';
        students[i].age = 18;
    }

    for (i = 3; i < 6; i++) {
        students[i].name = malloc(100 * sizeof(char));  // Allocate memory for name
        students[i].surname = malloc(100 * sizeof(char));  // Allocate memory for surname
        students[i].UUN = malloc(10 * sizeof(char));  // Allocate memory for UUN
        students[i].department = malloc(100 * sizeof(char));  // Allocate memory for department

        printf("Enter your name: ");
        scanf("%99s", students[i].name);  // Limit input to prevent buffer overflow
        printf("Enter your surname: ");
        scanf("%99s", students[i].surname);  // Limit input to prevent buffer overflow
        printf("Enter your UUN: ");
        scanf("%9s", students[i].UUN);  // Limit input to prevent buffer overflow
        printf("Enter your department: ");
        scanf("%99s", students[i].department);  // Limit input to prevent buffer overflow
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // Free dynamically allocated memory
    for (i = 3; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

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

    for(i = 0; i < 3; i++) {
        students[i].name = malloc(50 * sizeof(char)); // Allocate memory for name
        students[i].surname = malloc(50 * sizeof(char)); // Allocate memory for surname
        students[i].UUN = malloc(10 * sizeof(char)); // Allocate memory for UUN
        students[i].department = malloc(50 * sizeof(char)); // Allocate memory for department

        // Fill in the details for the first 3 students
        if(i == 0) {
            strcpy(students[i].name, "John");
            strcpy(students[i].surname, "Bishop");
            strcpy(students[i].UUN, "s1234");
            strcpy(students[i].department, "Inf");
            students[i].gender = 'm';
            students[i].age = 18;
        } else if(i == 1) {
            strcpy(students[i].name, "Lady");
            strcpy(students[i].surname, "Cook");
            strcpy(students[i].UUN, "s2345");
            strcpy(students[i].department, "Eng");
            students[i].gender = 'f';
            students[i].age = 21;
        } else if(i == 2) {
            strcpy(students[i].name, "James");
            strcpy(students[i].surname, "Jackson");
            strcpy(students[i].UUN, "s3456");
            strcpy(students[i].department, "Eng");
            students[i].gender = 'm';
            students[i].age = 17;
        }
    }

    // Input details for students 3 to 5
    for(i = 3; i < 6; i++) {
        students[i].name = malloc(50 * sizeof(char)); // Allocate memory for name
        students[i].surname = malloc(50 * sizeof(char)); // Allocate memory for surname
        students[i].UUN = malloc(10 * sizeof(char)); // Allocate memory for UUN
        students[i].department = malloc(50 * sizeof(char)); // Allocate memory for department

        printf("Enter your name: ");
        scanf("%s", students[i].name);
        printf("Enter your surname: ");
        scanf("%s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // Free allocated memory
    for(i = 0; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

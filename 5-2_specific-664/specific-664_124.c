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

#define MAX_STUDENTS 6

int main(void) {
    int i;
    student_t students[MAX_STUDENTS];

    for (i = 0; i < MAX_STUDENTS - 3; i++) {
        students[i].name = "John";
        students[i].surname = "Bishop";
        students[i].UUN = "s1234";
        students[i].department = "Inf";
        students[i].gender = 'm';
        students[i].age = 18;
    }

    for (i = MAX_STUDENTS - 3; i < MAX_STUDENTS; i++) {
        students[i].name = malloc(100 * sizeof(char));
        students[i].surname = malloc(100 * sizeof(char));
        students[i].UUN = malloc(100 * sizeof(char));
        students[i].department = malloc(100 * sizeof(char));

        printf("Enter your name: ");
        scanf(" %99s", students[i].name);
        printf("Enter your surname: ");
        scanf(" %99s", students[i].surname);
        printf("Enter your UUN: ");
        scanf(" %99s", students[i].UUN);
        printf("Enter your department: ");
        scanf(" %99s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &students[i].age);
    }

    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d: %s %s, UUN: %s, Department: %s, Gender: %c, Age: %d\n",
               i, students[i].name, students[i].surname, students[i].UUN, students[i].department,
               students[i].gender, students[i].age);

        // Free memory for dynamically allocated strings
        if (i >= MAX_STUDENTS - 3) { 
            free(students[i].name);
            free(students[i].surname);
            free(students[i].UUN);
            free(students[i].department);
        }
    }

    return EXIT_SUCCESS;
}

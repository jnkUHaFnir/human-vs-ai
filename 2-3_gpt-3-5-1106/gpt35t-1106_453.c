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

    students[0].name = "John";
    students[0].surname = "Bishop";
    students[0].UUN = "s1234";
    students[0].department = "Inf";
    students[0].gender = 'm';
    students[0].age = 18;

    // ... (similarly for students 1 and 2)

    for (i = 3; i < 6; i++) {
        students[i].name = (char *)malloc(50 * sizeof(char)); // allocate memory for the name
        printf("Enter your name: ");
        scanf(" %s", students[i].name);

        students[i].surname = (char *)malloc(50 * sizeof(char)); // allocate memory for the surname
        printf("Enter your surname: ");
        scanf(" %s", students[i].surname);

        students[i].UUN = (char *)malloc(50 * sizeof(char)); // allocate memory for the UUN
        printf("Enter your UUN: ");
        scanf(" %s", students[i].UUN);

        printf("Enter your department: ");
        // ... (similarly for department, gender, and age)

        free(students[i].name); // free the allocated memory when you're done using it
        free(students[i].surname);
        free(students[i].UUN);
    }

    return EXIT_SUCCESS;
}

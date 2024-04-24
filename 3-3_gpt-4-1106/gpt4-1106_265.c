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
    // Allocate memory size for a reasonably long string for each field
    int stringSize = 100;
    student_t students[6]; // Change variable name to avoid confusion

    students[0].name = "John";
    students[0].surname = "Bishop";
    students[0].UUN = "s1234";
    students[0].department = "Inf";
    students[0].gender = 'm';
    students[0].age = 18;

    students[1].name = "Lady";
    students[1].surname = "Cook";
    students[1].UUN = "s2345";
    students[1].department = "Eng";
    students[1].gender = 'f';
    students[1].age = 21;

    students[2].name = "James";
    students[2].surname = "Jackson";
    students[2].UUN = "s3456";
    students[2].department = "Eng";
    students[2].gender = 'm';
    students[2].age = 17;

    for (i = 3; i < 6; i++) {
        students[i].name = malloc(stringSize * sizeof(char)); // Allocate memory
        students[i].surname = malloc(stringSize * sizeof(char));
        students[i].UUN = malloc(stringSize * sizeof(char));
        students[i].department = malloc(stringSize * sizeof(char));

        printf("Enter your name: ");
        scanf("%99s", students[i].name); // Use 99 to leave room for null terminator
        printf("Enter your surname: ");
        scanf("%99s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%99s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%99s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender); // Space before %c to skip whitespace
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // Free allocated memory when done (to avoid memory leaks)
    for (i = 3; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

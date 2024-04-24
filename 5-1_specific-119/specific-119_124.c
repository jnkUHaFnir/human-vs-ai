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
    int i, len;
    student_t students[6];

    // Static initialization of structs
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

    // Dynamic memory allocation for user input
    for (i = 3; i < 6; i++) {
        students[i].name = malloc(50 * sizeof(char));
        students[i].surname = malloc(50 * sizeof(char));
        students[i].UUN = malloc(50 * sizeof(char));

        printf("Enter your name: ");
        scanf("%s", students[i].name);
        printf("Enter your surname: ");
        scanf("%s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%s", students[i].UUN);
        
        // Include the code to read department, gender, and age here
        
        // Free dynamically allocated memory after use
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
    }

    return EXIT_SUCCESS;
}

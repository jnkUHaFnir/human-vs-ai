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
        students[i].name = malloc(50); // Allocate memory for name
        students[i].surname = malloc(50); // Allocate memory for surname
        students[i].UUN = malloc(10); // Allocate memory for UUN

        if (students[i].name == NULL || students[i].surname == NULL || students[i].UUN == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        // Assign values for the first 3 students
        switch(i) {
            case 0:
                students[i].name = "John";
                students[i].surname = "Bishop";
                students[i].UUN = "s1234";
                students[i].department = "Inf";
                students[i].gender = 'm';
                students[i].age = 18;
                break;
            case 1:
                students[i].name = "Lady";
                students[i].surname = "Cook";
                students[i].UUN = "s2345";
                students[i].department = "Eng";
                students[i].gender = 'f';
                students[i].age = 21;
                break;
            case 2:
                students[i].name = "James";
                students[i].surname = "Jackson";
                students[i].UUN = "s3456";
                students[i].department = "Eng";
                students[i].gender = 'm';
                students[i].age = 17;
                break;
        }
    }

    for (i = 3; i < 6; i++) {
        students[i].name = malloc(50); // Allocate memory for name
        students[i].surname = malloc(50); // Allocate memory for surname
        students[i].UUN = malloc(10); // Allocate memory for UUN

        if (students[i].name == NULL || students[i].surname == NULL || students[i].UUN == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter your name: ");
        scanf("%s", students[i].name);
        printf("Enter your surname: ");
        scanf("%s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%s", students[i].department); // Assuming department is a string
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // Free allocated memory
    for (i = 0; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
    }

    return EXIT_SUCCESS;
}

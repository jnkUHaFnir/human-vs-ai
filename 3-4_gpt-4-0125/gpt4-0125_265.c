#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 100
int main(void) {
    int i;
    student_t student[6]; // Naming fixed to avoid confusion with the struct name

    // Static initialization for the first three students
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
        student[i].name = malloc(MAX_STRING_LENGTH);
        student[i].surname = malloc(MAX_STRING_LENGTH);
        student[i].UUN = malloc(MAX_STRING_LENGTH);
        student[i].department = malloc(MAX_STRING_LENGTH);
        
        if (!student[i].name || !student[i].surname || !student[i].UUN || !student[i].department) {
            fprintf(stderr, "Memory allocation failed\n");
            return EXIT_FAILURE;
        }

        printf("Enter your name: ");
        scanf("%99s", student[i].name);
        printf("Enter your surname: ");
        scanf("%99s", student[i].surname);
        printf("Enter your UUN: ");
        scanf("%99s", student[i].UUN);
        printf("Enter your department: ");
        scanf("%99s", student[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender); // Space before %c to consume any leftover newline in input buffer
        printf("Enter your age: ");
        scanf("%d", &student[i].age);
    }

    // Remember to free the allocated memory at the end!
    for (i = 3; i < 6; i++) {
        free(student[i].name);
        free(student[i].surname);
        free(student[i].UUN);
        free(student[i].department);
    }

    return EXIT_SUCCESS;
}

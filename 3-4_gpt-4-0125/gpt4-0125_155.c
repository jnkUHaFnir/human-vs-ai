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

int main(void)  {
    int i;
    student_t student[6]; // It's better to not name your variable exactly like your type

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
        student[i].name = malloc(50); // Allocate memory for name
        student[i].surname = malloc(50); // Allocate memory for surname
        student[i].UUN = malloc(10); // Allocate memory for UUN
        student[i].department = malloc(50); // Allocate memory for department
        if (!student[i].name || !student[i].surname || !student[i].UUN || !student[i].department) {
            // If any malloc call failed, report an error and exit
            printf("Failed to allocate memory.\n");
            return EXIT_FAILURE;
        }

        printf("Enter your name: ");
        scanf("%49s", student[i].name); // Use width specifier to prevent buffer overflow
        printf("Enter your surname: ");
        scanf("%49s", student[i].surname);
        printf("Enter your UUN: ");
        scanf("%9s", student[i].UUN);
        printf("Enter your department: ");
        scanf("%49s", student[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender); // Notice the space before %c to consume any newline left in the input buffer
        printf("Enter your age: ");
        scanf("%d", &student[i].age);
    }

    // Remember to free allocated memory to avoid memory leaks
    for (i = 3; i < 6; i++) {
        free(student[i].name);
        free(student[i].surname);
        free(student[i].UUN);
        free(student[i].department);
    }

    return EXIT_SUCCESS;
}

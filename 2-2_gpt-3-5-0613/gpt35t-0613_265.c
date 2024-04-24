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
    student_t student_t[6];

    student_t[0].name = "John";
    student_t[0].surname = "Bishop";
    student_t[0].UUN = "s1234";
    student_t[0].department = "Inf";
    student_t[0].gender = 'm';
    student_t[0].age = 18;

    student_t[1].name = "Lady";
    student_t[1].surname = "Cook";
    student_t[1].UUN = "s2345";
    student_t[1].department = "Eng";
    student_t[1].gender = 'f';
    student_t[1].age = 21;

    student_t[2].name = "James";
    student_t[2].surname = "Jackson";
    student_t[2].UUN = "s3456";
    student_t[2].department = "Eng";
    student_t[2].gender = 'm';
    student_t[2].age = 17;

    for (i = 3; i < 6; i++) {
        student_t[i].name = malloc(sizeof(char) * 50); // Allocate memory for name
        student_t[i].surname = malloc(sizeof(char) * 50); // Allocate memory for surname
        student_t[i].UUN = malloc(sizeof(char) * 50); // Allocate memory for UUN
        student_t[i].department = malloc(sizeof(char) * 50); // Allocate memory for department

        printf("Enter your name: ");
        scanf(" %49s", student_t[i].name); // Use %49s to prevent buffer overflow
        printf("Enter your surname: ");
        scanf(" %49s", student_t[i].surname);
        printf("Enter your UUN: ");
        scanf(" %49s", student_t[i].UUN);
        printf("Enter your department: ");
        scanf(" %49s", student_t[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student_t[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student_t[i].age);
    }

    for (i = 3; i < 6; i++) {
        printf("%s %s %s %s %c %d\n", student_t[i].name, student_t[i].surname, student_t[i].UUN, student_t[i].department, student_t[i].gender, student_t[i].age);
    }

    for (i = 3; i < 6; i++) {
        free(student_t[i].name); // Free allocated memory for name
        free(student_t[i].surname); // Free allocated memory for surname
        free(student_t[i].UUN); // Free allocated memory for UUN
        free(student_t[i].department); // Free allocated memory for department
    }

    return EXIT_SUCCESS;
}

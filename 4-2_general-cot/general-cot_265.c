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
    student_t student[6];

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
        student[i].name = malloc(100 * sizeof(char)); // Assuming max length of name is 100 characters
        student[i].surname = malloc(100 * sizeof(char)); // Assuming max length of surname is 100 characters
        student[i].UUN = malloc(10 * sizeof(char)); // Assuming UUN is no more than 10 characters
        
        printf("Enter your name: ");
        scanf("%s", student[i].name);
        printf("Enter your surname: ");
        scanf("%s", student[i].surname);
        printf("Enter your UUN: ");
        scanf("%s", student[i].UUN);
        printf("Enter your department: ");
        scanf("%s", student[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender);
        printf("Enter your age: ");
        scanf("%d", &student[i].age);
    }

    // Free memory for dynamically allocated fields
    for (i = 3; i < 6; i++) {
        free(student[i].name);
        free(student[i].surname);
        free(student[i].UUN);
    }

    return EXIT_SUCCESS;
}

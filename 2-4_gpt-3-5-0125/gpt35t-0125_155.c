#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        student[i].name = malloc(50*sizeof(char));
        printf("Enter your name: ");
        scanf("%s", student[i].name);

        student[i].surname = malloc(50*sizeof(char));
        printf("Enter your surname: ");
        scanf("%s", student[i].surname);

        student[i].UUN = malloc(50*sizeof(char));
        printf("Enter your UUN: ");
        scanf("%s", student[i].UUN);

        student[i].department = malloc(50*sizeof(char));
        printf("Enter your department: ");
        scanf("%s", student[i].department);

        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender);

        printf("Enter your age: ");
        scanf(" %d", &student[i].age);
    }

    for (i = 0; i < 6; i++) {
        printf("Student %d\n", i+1);
        printf("Name: %s\n", student[i].name);
        printf("Surname: %s\n", student[i].surname);
        printf("UUN: %s\n", student[i].UUN);
        printf("Department: %s\n", student[i].department);
        printf("Gender: %c\n", student[i].gender);
        printf("Age: %d\n", student[i].age);
    }

    for (i = 3; i < 6; i++) {
        free(student[i].name);
        free(student[i].surname);
        free(student[i].UUN);
        free(student[i].department);
    }

    return EXIT_SUCCESS;
}

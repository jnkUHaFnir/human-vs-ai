#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char surname[50];
    char UUN[50];
    char department[50];
    char gender;
    int age;
} student_t;

int main(void) {
    int i;
    student_t student[6];

    strcpy(student[0].name, "John");
    strcpy(student[0].surname, "Bishop");
    strcpy(student[0].UUN, "s1234");
    strcpy(student[0].department, "Inf");
    student[0].gender = 'm';
    student[0].age = 18;

    strcpy(student[1].name, "Lady");
    strcpy(student[1].surname, "Cook");
    strcpy(student[1].UUN, "s2345");
    strcpy(student[1].department, "Eng");
    student[1].gender = 'f';
    student[1].age = 21;

    strcpy(student[2].name, "James");
    strcpy(student[2].surname, "Jackson");
    strcpy(student[2].UUN, "s3456");
    strcpy(student[2].department, "Eng");
    student[2].gender = 'm';
    student[2].age = 17;

    for (i = 3; i < 6; i++) {
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

    return EXIT_SUCCESS;
}

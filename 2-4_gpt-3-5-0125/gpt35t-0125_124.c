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
    student_t students[6];

    for (i = 0; i < 3; i++) {
        students[i].name = (char *)malloc(50 * sizeof(char));
        students[i].surname = (char *)malloc(50 * sizeof(char));
        students[i].UUN = (char *)malloc(10 * sizeof(char));
        students[i].department = (char *)malloc(10 * sizeof(char));

        printf("Enter your name: ");
        scanf("%s", students[i].name);
        printf("Enter your surname: ");
        scanf("%s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    for (i = 0; i < 3; i++) {
        printf("Student %d\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Surname: %s\n", students[i].surname);
        printf("UUN: %s\n", students[i].UUN);
        printf("Department: %s\n", students[i].department);
        printf("Gender: %c\n", students[i].gender);
        printf("Age: %d\n", students[i].age);
    }

    for (i = 0; i < 3; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

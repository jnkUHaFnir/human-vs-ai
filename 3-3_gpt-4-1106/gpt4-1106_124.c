#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    student_t students[6];

    strcpy(students[0].name, "John");
    strcpy(students[0].surname, "Bishop");
    strcpy(students[0].UUN, "s1234");
    strcpy(students[0].department, "Inf");
    students[0].gender = 'm';
    students[0].age = 18;

    strcpy(students[1].name, "Lady");
    strcpy(students[1].surname, "Cook");
    strcpy(students[1].UUN, "s2345");
    strcpy(students[1].department, "Eng");
    students[1].gender = 'f';
    students[1].age = 21;

    strcpy(students[2].name, "James");
    strcpy(students[2].surname, "Jackson");
    strcpy(students[2].UUN, "s3456");
    strcpy(students[2].department, "Eng");
    students[2].gender = 'm';
    students[2].age = 17;

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf("%49s", students[i].name);  // Limit input to 49 chars (leaving room for terminating null)
        printf("Enter your surname: ");
        scanf("%49s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%49s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%49s", students[i].department);
        printf("Enter your gender: ");
        // Consume any left-over characters in the input buffer (e.g. newlines)
        while (getchar() != '\n');
        scanf("%c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    return EXIT_SUCCESS;
}

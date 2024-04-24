#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];      // changed from a pointer to an array of chars
    char surname[100];   // changed from a pointer to an array of chars
    char UUN[100];       // changed from a pointer to an array of chars
    char department[100]; // changed from a pointer to an array of chars
    char gender;
    int age;
} student_t;


int main(void)  {
    int i;
    student_t students[6];

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

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf("%99s", students[i].name);
        printf("Enter your surname: ");
        scanf("%99s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%99s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%99s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &students[i].age);
    }
    
    return EXIT_SUCCESS;
}

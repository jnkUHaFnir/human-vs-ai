#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char surname[20];
    char UUN[10];
    char department[20];
    char gender;
    int age;
} student_t;

int main(void) {
    int i;
    student_t students[6];

    // Your initialization code here

    for (i = 3; i < 6; i++) {
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

    return EXIT_SUCCESS;
}

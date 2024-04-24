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

    // ... (initializing the first 3 students)

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf(" %19s", students[i].name);  // limit input to 19 characters to avoid buffer overflow
        printf("Enter your surname: ");
        scanf(" %19s", students[i].surname);
        printf("Enter your UUN: ");
        scanf(" %9s", students[i].UUN);  // limit input to 9 characters to avoid buffer overflow
        printf("Enter your department: ");
        scanf(" %19s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &students[i].age);
    }

    return EXIT_SUCCESS;
}

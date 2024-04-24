#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char surname[50];
    char UUN[10];
    char department[50];
    char gender;
    int age;
} student_t;

int main(void) {
    int i;

    student_t student_t[6];

    // Assign initial values to the first 3 students
    student_t[0] = (student_t){"John", "Bishop", "s1234", "Inf", 'm', 18};
    student_t[1] = (student_t){"Lady", "Cook", "s2345", "Eng", 'f', 21};
    student_t[2] = (student_t){"James", "Jackson", "s3456", "Eng", 'm', 17};

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf("%49s", student_t[i].name);
        printf("Enter your surname: ");
        scanf("%49s", student_t[i].surname);
        printf("Enter your UUN: ");
        scanf("%9s", student_t[i].UUN);
        printf("Enter your department: ");
        scanf("%49s", student_t[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student_t[i].gender);
        printf("Enter your age: ");
        scanf("%d", &student_t[i].age);
    }

    return EXIT_SUCCESS;
}

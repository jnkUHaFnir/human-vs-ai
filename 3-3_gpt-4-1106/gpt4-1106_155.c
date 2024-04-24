#define MAX_NAME_LEN 50
#define MAX_SURNAME_LEN 50
#define MAX_UUN_LEN 20
#define MAX_DEPARTMENT_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char surname[MAX_SURNAME_LEN];
    char UUN[MAX_UUN_LEN];
    char department[MAX_DEPARTMENT_LEN];
    char gender;
    int age;
} student_t;
for (i = 3; i < 6; i++) {
    printf("Enter your name: ");
    scanf(" %49s", student_t[i].name);
    printf("Enter your surname: ");
    scanf(" %49s", student_t[i].surname);
    printf("Enter your UUN: ");
    scanf(" %19s", student_t[i].UUN);
    printf("Enter your department: ");
    scanf(" %49s", student_t[i].department);
    printf("Enter your gender: ");
    scanf(" %c", &student_t[i].gender);
    printf("Enter your age: ");
    scanf(" %d", &student_t[i].age);
}
#include <stdio.h>
#include <stdlib.h>

// ... (rest of your code)
scanf(" %c%*c", &student_t[i].gender);  // %*c will consume the extra newline character

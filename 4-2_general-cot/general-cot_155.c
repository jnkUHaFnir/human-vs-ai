#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50]; // Allocate memory for the strings
    char surname[50];
    char UUN[10];
    char department[50];
    char gender;
    int age;
} student_t;

int main(void) {
    int i;
    student_t student_arr[6];

    // Pre-filled student data
    strcpy(student_arr[0].name, "John");
    strcpy(student_arr[0].surname, "Bishop");
    strcpy(student_arr[0].UUN, "s1234");
    strcpy(student_arr[0].department, "Inf");
    student_arr[0].gender = 'm';
    student_arr[0].age = 18;

    strcpy(student_arr[1].name, "Lady");
    strcpy(student_arr[1].surname, "Cook");
    strcpy(student_arr[1].UUN, "s2345");
    strcpy(student_arr[1].department, "Eng");
    student_arr[1].gender = 'f';
    student_arr[1].age = 21;

    strcpy(student_arr[2].name, "James");
    strcpy(student_arr[2].surname, "Jackson");
    strcpy(student_arr[2].UUN, "s3456");
    strcpy(student_arr[2].department, "Eng");
    student_arr[2].gender = 'm';
    student_arr[2].age = 17;

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf(" %49s", student_arr[i].name);  // Limit input to prevent buffer overflow
        printf("Enter your surname: ");
        scanf(" %49s", student_arr[i].surname);
        printf("Enter your UUN: ");
        scanf(" %9s", student_arr[i].UUN);
        printf("Enter your department: ");
        scanf(" %49s", student_arr[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student_arr[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student_arr[i].age);
    }

    return EXIT_SUCCESS;
}

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
    student_t students[6];

    students[0].name = "John";
    students[0].surname = "Bishop";
    students[0].UUN = "s1234";
    students[0].department = "Inf";
    students[0].gender = 'm';
    students[0].age = 18;

    // ... Initialize the other students here ...

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf("%49s", students[i].name); // Limit input to prevent buffer overflow
        printf("Enter your surname: ");
        scanf("%49s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%49s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%49s", students[i].department);
        printf("Enter your gender: ");
        // Consume the newline left in input buffer from previous scanf
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    return EXIT_SUCCESS;
}
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

int main(void) {
    int i;
    student_t students[6];

    // ... Initialize static students here ...

    for (i = 3; i < 6; i++) {
        students[i].name = malloc(50);
        students[i].surname = malloc(50);
        students[i].UUN = malloc(50);
        students[i].department = malloc(50);

        // Check if malloc was successful
        if (!students[i].name || !students[i].surname || !students[i].UUN || !students[i].department) {
            // Handle memory allocation failure (e.g., print error and exit)
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter your name: ");
        scanf("%49s", students[i].name);
        printf("Enter your surname: ");
        scanf("%49s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%49s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%49s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // ... After using the students array, free the allocated memory

    for (i = 3; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

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

// The rest of your code would remain mostly unchanged.
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
    student_t students[6] = {
        {"John", "Bishop", "s1234", "Inf", 'm', 18},
        {"Lady", "Cook", "s2345", "Eng", 'f', 21},
        {"James", "Jackson", "s3456", "Eng", 'm', 17},
        {NULL, NULL, NULL, NULL, 0, 0},
        {NULL, NULL, NULL, NULL, 0, 0},
        {NULL, NULL, NULL, NULL, 0, 0}
    };

    char buffer[100]; // Assuming none of the inputs will be longer than 99 characters.

    for (int i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf(" %99s", buffer);
        students[i].name = strdup(buffer);

        printf("Enter your surname: ");
        scanf(" %99s", buffer);
        students[i].surname = strdup(buffer);

        printf("Enter your UUN: ");
        scanf(" %99s", buffer);
        students[i].UUN = strdup(buffer);

        printf("Enter your department: ");
        scanf(" %99s", buffer);
        students[i].department = strdup(buffer);

        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender); // Watch out for '\n' char left in the input stream.

        printf("Enter your age: ");
        scanf(" %d", &students[i].age);
    }

    // Don't forget to free dynamically allocated memory to avoid memory leaks.
    for (int i = 3; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

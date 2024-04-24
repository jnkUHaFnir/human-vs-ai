#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50]; // Assuming max length of name is 50 characters
    char surname[50]; // Assuming max length of surname is 50 characters
    char UUN[10]; // Assuming max length of UUN is 10 characters
    char department[10]; // Assuming max length of department is 10 characters
    char gender;
    int age;
} student_t;

int main(void) {
    int i;

    // Initialize struct array
    student_t students[6] = {
        {"John", "Bishop", "s1234", "Inf", 'm', 18},
        {"Lady", "Cook", "s2345", "Eng", 'f', 21},
        {"James", "Jackson", "s3456", "Eng", 'm', 17}
    };

    for(i = 3; i < 6; i++) {
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

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];  // Using arrays instead of char pointers
    char surname[50];
    char UUN[20];
    char department[50];
    char gender;
    int age;
} student_t;

int main(void)  {
    int i;
    student_t student[6]; // Changed variable name to avoid confusion with type name

    student[0].name = "John"; // These will now cause compilation errors
    //...
    // You should use strcpy to assign strings to arrays:
    strcpy(student[0].name, "John");
    strcpy(student[0].surname, "Bishop");
    strcpy(student[0].UUN, "s1234");
    strcpy(student[0].department, "Inf");
    student[0].gender = 'm';
    student[0].age = 18;
    
    // Similar corrections for other predefined students...

    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf(" %49s", student[i].name); // Note '%49s' to prevent buffer overflow
        printf("Enter your surname: ");
        scanf(" %49s", student[i].surname);
        printf("Enter your UUN: ");
        scanf(" %19s", student[i].UUN);
        printf("Enter your department: ");
        scanf(" %49s", student[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &student[i].gender);
        printf("Enter your age: ");
        scanf(" %d", &student[i].age);
    }

    return EXIT_SUCCESS;
}

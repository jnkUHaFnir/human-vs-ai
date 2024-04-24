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
    const int MAX_NAME_LEN = 50; // Define a max length for names and other strings
    student_t students[6]; // Renamed to avoid type/name conflict

    // Assigning static strings is fine for the fixed entries, no need for dynamic memory
    students[0].name = "John";
    students[0].surname = "Bishop";
    students[0].UUN = "s1234";
    students[0].department = "Inf";
    students[0].gender = 'm';
    students[0].age = 18;

    // (Similarly for students[1] and students[2], which you have correctly set)

    // Now, for reading in user input, allocate memory
    for (i = 3; i < 6; i++) {
        students[i].name = malloc(MAX_NAME_LEN);
        students[i].surname = malloc(MAX_NAME_LEN);
        students[i].UUN = malloc(MAX_NAME_LEN);
        students[i].department = malloc(MAX_NAME_LEN);

        if (!students[i].name || !students[i].surname || !students[i].UUN || !students[i].department) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE); // It's good practice to handle failed memory allocations
        }

        printf("Enter your name: ");
        scanf("%49s", students[i].name); // Use the limit to prevent buffer overflows
        printf("Enter your surname: ");
        scanf("%49s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%49s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%49s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender); // Notice the space before %c to skip any whitespace
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }

    // ... (Your remaining code, if any)

    // Don't forget to free the allocated memory at the end of your program:
    for (i = 3; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

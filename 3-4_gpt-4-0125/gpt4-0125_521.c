#include <stdio.h>
#include <stdlib.h>

// Your structure definition and the initialization for the first three students remains the same...

for (i = 3; i < 6; i++) {
    // Allocate memory for each string. Let's say max length is 99 + 1 for '\0' terminator
    student_t[i].name = (char *)malloc(100 * sizeof(char));
    student_t[i].surname = (char *)malloc(100 * sizeof(char));
    student_t[i].UUN = (char *)malloc(100 * sizeof(char));
    student_t[i].department = (char *)malloc(100 * sizeof(char));
    
    if (!student_t[i].name || !student_t[i].surname || !student_t[i].UUN || !student_t[i].department) {
        // If any allocation failed, exit to avoid undefined behavior
        printf("Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    printf("Enter your name: ");
    scanf("%99s", student_t[i].name);
    printf("Enter your surname: ");
    scanf("%99s", student_t[i].surname);
    printf("Enter your UUN: ");
    scanf("%99s", student_t[i].UUN);
    printf("Enter your department: ");
    scanf("%99s", student_t[i].department);
    printf("Enter your gender: ");
    scanf(" %c", &student_t[i].gender); // Space before %c to consume any leftover newline
    printf("Enter your age: ");
    scanf("%d", &student_t[i].age);
}

// Don't forget to free the allocated memory once you're done using it.
for (i = 3; i < 6; i++) {
    free(student_t[i].name);
    free(student_t[i].surname);
    free(student_t[i].UUN);
    free(student_t[i].department);
}

return EXIT_SUCCESS;

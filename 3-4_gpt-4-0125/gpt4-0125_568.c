#include <stdio.h>

int main() {
    FILE *student;
    char brst[255];
    int line_count = 0;

    // Open the file for reading
    student = fopen("student.txt", "r");
    if (student == NULL) {
        printf("Error opening file\n");
        return 1; // return with error
    }

    // Read and print lines from file, and count them
    while (fgets(brst, sizeof(brst), student) != NULL) {
        printf("%s", brst); // brst contains the newline character from the file, so no \n required
        line_count++;
    }

    // Print the number of lines
    printf("Number of lines: %d\n", line_count);

    // Close the file
    fclose(student);

    return 0;
}

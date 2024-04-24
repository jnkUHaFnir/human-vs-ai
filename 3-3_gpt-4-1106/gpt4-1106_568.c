#include <stdio.h>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[]) {
    FILE *student;
    char buffer[255];
    int lineCount = 0;

    student = fopen("student.txt", "r");

    // Check if file opened successfully
    if (student == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Loop while not at end of file
    while (fgets(buffer, sizeof(buffer), student)) {
        printf("%s", buffer); // Print the line
        lineCount++; // Increment the line count
    }

    // Close the file
    fclose(student);

    // Print the line count
    printf("\nNumber of lines: %d\n", lineCount);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;     // Pointer to the buffer, initialize to NULL
    size_t len = 0;        // Size of the buffer, initialize to 0
    ssize_t read;          // Number of characters read (including the newline, but excluding the null terminator)

    printf("Enter a line:\n");

    // Read the line
    read = getline(&line, &len, stdin);

    // Check for errors
    if (read == -1) {
        perror("getline");
        // Clean up and exit if getline failed
        free(line);
        exit(EXIT_FAILURE);
    }

    // Output the line that was read
    printf("You entered: %s", line);

    // Free the buffer allocated by getline
    free(line);

    return 0;
}
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH]; // Buffer for the line

    printf("Enter a line:\n");

    // Read the line
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Output the line that was read
    printf("You entered: %s", line);

    return 0;
}

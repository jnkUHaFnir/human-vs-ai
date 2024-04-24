#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* line = NULL;   // Pointer to hold the line
    size_t bufsize = 0;  // Variable to hold the allocated size of the buffer
    ssize_t len;         // Variable to hold the length of the line
    FILE* fp = stdin;    // Pointer to file

    // Read line by line until EOF is reached
    while ((len = getline(&line, &bufsize, fp)) != -1) {
        // Process the line as needed
        printf("Line: %s", line);
    }

    // Free the dynamically allocated memory
    free(line);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* line = malloc(10 * sizeof(char));  // Allocate initial memory for 10 characters
    size_t bufsize = 10;                     // Initial allocated size of the buffer
    ssize_t len;                             // Length of the line
    FILE* fp = stdin;                        // Pointer to file

    // Read line by line until EOF is reached
    while ((len = getline(&line, &bufsize, fp)) != -1) {
        // Process the line as needed
        printf("Line: %s", line);

        // Check if more memory is needed and reallocate if necessary
        if (len == bufsize - 1 && line[len - 1] != '\n') {
            bufsize *= 2;
            line = realloc(line, bufsize * sizeof(char));
        }
    }

    // Free the dynamically allocated memory
    free(line);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 1024 // Initial size for the buffer

char *readLine(FILE *file) {
    int size = INITIAL_SIZE;
    int index = 0;
    char *buffer = (char *)malloc(size * sizeof(char));

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    while (1) {
        char *result = fgets(buffer + index, size - index, file);

        if (result == NULL) {
            if (feof(file)) {
                break; // End of file reached
            } else {
                fprintf(stderr, "Error reading from file\n");
                exit(1);
            }
        }

        index += strlen(buffer + index);

        if (buffer[index - 1] == '\n') {
            break; // End of line reached
        }

        // Reallocate memory if needed
        if (index >= size - 1) {
            size *= 2;
            buffer = (char *)realloc(buffer, size);

            if (buffer == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(1);
            }
        }
    }

    return buffer;
}

int main() {
    // Example reading from stdin
    printf("Enter a line of text (Ctrl+D/Ctrl+Z to end):\n");
    char *line = readLine(stdin);
    printf("You entered: %s\n", line);

    free(line);

    // Example reading from a file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while (!feof(file)) {
        char *line = readLine(file);
        printf("Line from file: %s\n", line);
        free(line);
    }

    fclose(file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 100

char* readLine(FILE* file) {
    char* buffer = (char*)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t bufferSize = INITIAL_BUFFER_SIZE;
    size_t position = 0;
    int c;

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = fgetc(file);

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            break;
        }

        buffer[position] = (char)c;
        position++;

        // If buffer size is not enough, resize the buffer
        if (position >= bufferSize - 1) {
            bufferSize *= 2;
            buffer = (char*)realloc(buffer, bufferSize * sizeof(char));
            if (buffer == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return buffer;
}

int main() {
    char* line;

    // Reading from a file
    FILE* file = fopen("input.txt", "r");
    if (file) {
        line = readLine(file);
        fclose(file);
        printf("File Input: %s\n", line);
        free(line);
    } else {
        fprintf(stderr, "Failed to open file\n");
    }

    // Reading from stdin
    printf("Enter a line: ");
    line = readLine(stdin);
    printf("Stdin Input: %s\n", line);
    free(line);

    return 0;
}

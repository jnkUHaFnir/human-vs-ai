#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 64

char *read_line(FILE *file) {
    int buffer_size = INITIAL_BUFFER_SIZE;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    int position = 0;
    int c;

    while (1) {
        c = fgetc(file);

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            break;
        }

        buffer[position] = (char)c;
        position++;

        if (position >= buffer_size) {
            buffer_size *= 2;
            buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
            if (buffer == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                exit(1);
            }
        }
    }

    return buffer;
}

int main() {
    char *line;

    // Example: Read from stdin
    printf("Enter a line of text:\n");
    line = read_line(stdin);
    printf("You entered: %s\n", line);
    free(line);

    // Example: Read from a file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    line = read_line(file);
    printf("Line from file: %s\n", line);
    free(line);
    fclose(file);

    return 0;
}

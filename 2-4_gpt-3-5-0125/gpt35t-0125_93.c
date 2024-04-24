#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 128

char* read_input_line(FILE* stream) {
    char* buffer = (char*) malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    size_t buffer_size = INITIAL_BUFFER_SIZE;
    size_t input_length = 0;
    int c;

    while ((c = fgetc(stream)) != EOF && c != '\n') {
        buffer[input_length++] = c;

        if (input_length == buffer_size - 1) {
            buffer_size *= 2;
            buffer = (char*) realloc(buffer, buffer_size * sizeof(char));
            if (buffer == NULL) {
                fprintf(stderr, "Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    buffer[input_length] = '\0';

    return buffer;
}

int main() {
    // Example of reading input line by line from stdin
    char* input_line = read_input_line(stdin);
    printf("Input line: %s\n", input_line);
    
    free(input_line);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define GROWTH_FACTOR 2

char *read_line(FILE *fp) {
    int capacity = INITIAL_SIZE;
    int length = 0;
    char* line = (char*)malloc(capacity * sizeof(char));
    
    if (line == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(fp)) != '\n' && c != EOF) {
        line[length++] = c;

        if (length >= capacity) {
            capacity *= GROWTH_FACTOR;
            line = (char*)realloc(line, capacity * sizeof(char));
            if (line == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    line[length] = '\0'; // Null-terminate the string
    return line;
}

int main() {
    char *input_line;
    
    // Reading from stdin
    printf("Enter a line of text:\n");
    input_line = read_line(stdin);
    printf("You entered: %s\n", input_line);
    
    free(input_line); // Free dynamically allocated memory

    return 0;
}

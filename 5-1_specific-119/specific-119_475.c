#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    int buff_len = 0;
    int i = 0;
    
    int capacity = 10; // Initial capacity
    
    buffer = malloc(capacity * sizeof(char));

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // or handle the error according to your requirements
    }

    int ch;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = (char)ch;
        ++i;

        if (i >= capacity - 1) {
            capacity *= 2; // Double the capacity

            char *temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(1); // or handle the error according to your requirements
            }

            buffer = temp;
        }
    }

    buffer[i] = '\0'; // Null-terminate the string

    return buffer;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1; // indicate failure
    }

    char *line = readline(fp);
    printf("Read line: %s\n", line);

    free(line);
    fclose(fp);

    return 0;
}

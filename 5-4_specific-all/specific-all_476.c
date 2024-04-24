#include <stdlib.h>
#include <stdio.h>

#define INITIAL_BUFFER_SIZE 64

char *readline(FILE *fp) {
    char *buffer = malloc(INITIAL_BUFFER_SIZE);
    int buff_len = INITIAL_BUFFER_SIZE;
    int i = 0;
    char ch;

    if (!buffer) {
        return NULL; // Handle memory allocation failure
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = ch;
        ++i;

        if (i == buff_len - 1) {
            buff_len *= 2;
            buffer = realloc(buffer, buff_len);

            if (!buffer) {
                return NULL; // Handle memory reallocation failure
            }
        }
    }

    buffer[i] = '\0'; // Null-terminate the string
    return buffer;
}

int main() {
    // Example of how to use the readline function
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = readline(file);
    if (line == NULL) {
        perror("Error reading line");
        fclose(file);
        return 1;
    }

    printf("Read line: %s\n", line);

    free(line);
    fclose(file);

    return 0;
}

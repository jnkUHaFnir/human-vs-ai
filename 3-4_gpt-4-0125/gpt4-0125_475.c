#include <stdlib.h>
#include <stdio.h>

char *readline(FILE *fp) {
    char ch;
    int i = 0;
    int buff_size = 10; // Start with an initial size

    char *buffer = malloc(buff_size * sizeof(char));
    if (buffer == NULL) {
        return NULL; // Allocation failed
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        // Check if we need to expand the buffer
        if (i >= buff_size - 1) { // Leave space for the null terminator
            // Increase the buffer size
            buff_size *= 2; // Doubling the buffer size for efficiency
            char *temp = realloc(buffer, buff_size * sizeof(char));
            if (temp == NULL) {
                free(buffer);
                return NULL; // Reallocation failed
            }
            buffer = temp;
        }

        // Place the character into the buffer
        buffer[i++] = ch;
    }

    // Handling cases like when a file doesn't end with a newline
    if (i == 0 && ch == EOF) {
        free(buffer);
        return NULL; // Nothing was read
    }

    // Null terminate the string
    buffer[i] = '\0';

    // Optionally, shrink the buffer to the exact size needed
    char *shrunkBuffer = realloc(buffer, i + 1); // +1 for null terminator
    if (shrunkBuffer != NULL) {
        buffer = shrunkBuffer;
    }

    return buffer;
}

int main() {
    FILE *fp = fopen("yourfile.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char *line;
    while ((line = readline(fp)) != NULL) {
        printf("%s\n", line);
        free(line); // Don't forget to free the memory!
    }

    fclose(fp);
    return 0;
}

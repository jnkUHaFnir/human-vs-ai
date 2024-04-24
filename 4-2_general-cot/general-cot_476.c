#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128  // Initial buffer size

char *readline(FILE *fp) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int i = 0;
    int buff_len = BUFFER_SIZE;

    int ch;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = (char)ch;
        ++i;

        if (i >= buff_len - 1) {  // Check if buffer is full
            buff_len += BUFFER_SIZE;
            buffer = (char *)realloc(buffer, buff_len);
            if (buffer == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(1);
            }
        }
    }

    buffer[i] = '\0'; // Null-terminate the string

    return buffer;
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return 1;
    }

    char *line = readline(file);
    printf("Read line: %s\n", line);

    free(line);
    fclose(file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char ch;
    int i = 0;
    int buff_len = 10; // Initial buffer length
    char *buffer = malloc(buff_len * sizeof(char)); // Allocate initial buffer

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = ch;
        ++i;

        if (i == buff_len - 1) {
            buff_len *= 2; // Double the buffer size
            char *temp = realloc(buffer, buff_len * sizeof(char));
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
    }

    buffer[i] = '\0'; // Null-terminate the string
    return buffer;
}

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "File open failed\n");
        return 1;
    }

    char *line = readline(fp);

    if (line != NULL) {
        printf("Read line: %s\n", line);
        free(line); // Free the allocated memory
    }

    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    int buff_len = 0;
    int i = 0;
    char ch;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        if (i >= buff_len - 1) {
            buff_len = (buff_len == 0) ? 1 : buff_len * 2;
            buffer = realloc(buffer, buff_len);
            if (buffer == NULL) {
                // Handle memory allocation failure
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
        }
        buffer[i] = ch;
        ++i;
    }

    if (i > 0) {
        buffer[i] = '\0'; // Null-terminate the string
    } else {
        free(buffer);
        buffer = NULL;
    }

    return buffer;
}

int main() {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *line = readline(fp);
    if (line != NULL) {
        printf("Read line: %s\n", line);
        free(line);
    }

    fclose(fp);
    return 0;
}

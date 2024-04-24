#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char ch;
    int i = 0, buff_len = 1;  // Start with space for '\0'

    char *buffer = malloc(buff_len);
    if (buffer == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = ch;
        ++i;
        if (i == buff_len - 1) {
            buff_len *= 2;  // Double buffer size if needed
            char *temp = realloc(buffer, buff_len);
            if (temp == NULL) {
                // Handle memory allocation failure
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
    }

    buffer[i] = '\0';  // Null-terminate the string

    return buffer;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *line = readline(fp);
    if (line == NULL) {
        fprintf(stderr, "Error reading line\n");
        fclose(fp);
        return 1;
    }

    printf("Read line: %s\n", line);

    free(line);
    fclose(fp);

    return 0;
}

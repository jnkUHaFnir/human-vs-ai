#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char ch;
    int i = 0, buff_len = 1; // Starting with 1 for the null terminator
    char *buffer = malloc(buff_len);

    if (buffer == NULL) {
        return NULL; // Handle memory allocation failure
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = ch;
        ++i;
        ++buff_len;
        char *temp = realloc(buffer, buff_len);
        if (temp == NULL) {
            free(buffer);
            return NULL; // Handle memory reallocation failure
        }
        buffer = temp;
    }

    buffer[i] = '\0'; // Null-terminate the string

    return buffer;
}

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = readline(fp);
    if (line == NULL) {
        perror("Error reading line");
    } else {
        printf("Read line: %s\n", line);
        free(line); // Free allocated memory
    }

    fclose(fp);
    return 0;
}

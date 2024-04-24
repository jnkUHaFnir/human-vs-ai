#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    size_t buff_len = 0;

    // Allocate initial memory for buffer
    buffer = malloc(1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    buffer[0] = '\0'; // Initialize with null terminator

    while (fgets(buffer + buff_len, 1, fp) != NULL) {
        if (buffer[buff_len] == '\n') {
            break; // Stop reading at newline character
        }
        
        ++buff_len;
        buffer = realloc(buffer, buff_len + 2); // Allocate 1 more for the next character and another for the null terminator
        if (buffer == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
    }

    return buffer;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "File open failed\n");
        return 1;
    }

    char *line = readline(fp);
    printf("Read line: %s\n", line);

    free(line);
    fclose(fp);

    return 0;
}

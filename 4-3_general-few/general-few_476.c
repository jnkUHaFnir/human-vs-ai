#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    int buff_len = 0;
    char ch;
    
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer = realloc(buffer, buff_len + 1); // Reallocate memory for each character
        
        if (buffer == NULL) {
            // Error handling for allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        
        buffer[buff_len] = ch;
        buff_len++;
    }
    
    // Add null terminator to indicate end of string
    buffer = realloc(buffer, buff_len + 1);
    buffer[buff_len] = '\0';

    return buffer;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *line = readline(fp);
    printf("Read line: %s\n", line);

    free(line);
    fclose(fp);

    return 0;
}

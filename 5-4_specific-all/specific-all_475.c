#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    char ch;
    int i = 0, buff_len = 0;
    
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer = realloc(buffer, (buff_len + 1) * sizeof(char));

        if (buffer == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        buffer[i] = ch;
        ++i;
        ++buff_len;
    }

    // Add null terminator
    buffer = realloc(buffer, (buff_len + 1) * sizeof(char));
    if (buffer == NULL) {
        // Handle allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    buffer[buff_len] = '\0';

    return buffer;
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = readline(file);
    if (line != NULL) {
        printf("Read line: %s\n", line);
        free(line);
    }

    fclose(file);
    return 0;
}

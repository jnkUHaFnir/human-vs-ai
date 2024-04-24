#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 128

char *readline(FILE *fp) {
    char *buffer = malloc(INITIAL_BUFFER_SIZE);
    if (buffer == NULL) {
        // Handle allocation failure
        return NULL;
    }

    int i = 0;
    int buff_len = INITIAL_BUFFER_SIZE;
    char ch;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = ch;
        ++i;

        if (i == buff_len - 1) { // Resize buffer if needed
            buff_len *= 2;
            char *temp = realloc(buffer, buff_len);
            if (temp == NULL) {
                // Handle allocation failure
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
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *line = readline(fp);
    printf("%s\n", line);

    free(line);
    fclose(fp);
    return 0;
}

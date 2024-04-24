#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 100
#define BUFFER_CHUNK_SIZE 50

char *readline(FILE *fp) {
    char *buffer = malloc(INITIAL_BUFFER_SIZE);
    if (buffer == NULL) {
        return NULL;
    }

    int i = 0;
    int buff_len = INITIAL_BUFFER_SIZE;
    char ch;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        if (i >= buff_len - 1) {
            buff_len += BUFFER_CHUNK_SIZE;
            char *temp = realloc(buffer, buff_len);
            if (temp == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        buffer[i] = ch;
        ++i;
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
    printf("Read line: %s\n", line);
    
    fclose(fp);
    free(line);

    return 0;
}

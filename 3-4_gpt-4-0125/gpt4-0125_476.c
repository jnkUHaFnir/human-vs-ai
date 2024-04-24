#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    int bufferSize = 0;
    int capacity = 0;
    char ch;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        // Increase buffer size
        if (bufferSize + 1 >= capacity) {
            int newCapacity = capacity + 1024; // Allocate in chunks
            char *newBuffer = realloc(buffer, newCapacity);
            if (newBuffer == NULL) {
                // Allocation failed, cleanup and exit
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
            capacity = newCapacity;
        }

        // Add character to buffer
        buffer[bufferSize++] = ch;
    }

    if (bufferSize == 0 && ch == EOF) {
        // End of file and no characters read
        return NULL;
    }

    // Null-terminate the string
    char *finalBuffer = realloc(buffer, bufferSize + 1);
    if (finalBuffer == NULL) {
        free(buffer);
        return NULL;
    }
    finalBuffer[bufferSize] = '\0';
    return finalBuffer;
}

int main() {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char *line;
    while ((line = readline(fp)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    fclose(fp);
    return 0;
}

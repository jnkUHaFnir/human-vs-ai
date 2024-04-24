#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

char *readLine(FILE *file) {
    char *line = NULL;
    char *tmp = NULL;
    size_t size = 0;
    size_t len = 0;

    do {
        if (len + BUFFER_SIZE + 1 > size) {
            size += BUFFER_SIZE;
            tmp = realloc(line, size);
            if (!tmp) {
                fprintf(stderr, "Memory allocation failed\n");
                free(line);
                return NULL;
            }
            line = tmp;
        }

        if (!fgets(line + len, size - len, file)) {
            break;
        }

        len += strlen(line + len);
    } while (line[len - 1] != '\n' && !feof(file));

    return line;
}

int main() {
    char *line = readLine(stdin);
    if (line) {
        printf("Input line: %s\n", line);
        free(line);
    }

    return 0;
}

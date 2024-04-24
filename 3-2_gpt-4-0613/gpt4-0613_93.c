#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024  // Maximum line size

char *readLine(FILE *file) {
    char *line = malloc(MAX_LINE_SIZE), *tmp;
    if (!fgets(line, MAX_LINE_SIZE, file)) {
        free(line);
        return NULL;
    }
    size_t len = strlen(line);
    if ((len > 0) && (line[len - 1] == '\n')) {
        line[len - 1] = '\0';
    }

    tmp = realloc(line, len);
    if(tmp) {
        line = tmp;
    }

    return line;
}

int main(void) {
    FILE *file = fopen("yourfile.txt", "r");
    if (file) {
        char *line;
        while ((line = readLine(file)) != NULL) {
            printf("%s\n", line);
            free(line);
        }
        fclose(file);
    }
    return 0;
}

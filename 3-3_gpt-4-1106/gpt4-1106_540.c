#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_dashed_line(int length) {
    char *line = malloc(length + 1); // +1 for the null terminator
    if (line) {
        memset(line, '-', length);
        line[length] = '\0';
    }
    return line;
}

int main() {
    int length = 10;
    char *dashedLine = create_dashed_line(length);
    if (dashedLine) {
        printf("%s\n", dashedLine);
        free(dashedLine);
    }
    return 0;
}
#define DASHED_LINE "----------"

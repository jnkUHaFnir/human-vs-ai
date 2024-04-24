#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* read_line(FILE* fin) {
    // Assume read_line function is implemented elsewhere
}

int main() {
    FILE* fin = fopen("file1.txt", "r");

    char* url = NULL;
    char* line;

    if (fin) {
        while ((line = read_line(fin)) != NULL) {
            if ((url = strstr(line, "url=")) != NULL) {
                fprintf(stdout, "%s \n", url);
                // Making a copy of the data
                url = strdup(url);
            }
            free(line);
        }
        fclose(fin);
    }

    printf("line is: %s\n", url);

    return 0;
}

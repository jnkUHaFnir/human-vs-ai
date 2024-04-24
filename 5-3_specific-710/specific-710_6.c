#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_line(FILE *fin) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fin)) != -1) {
        // Remove newline character if present
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        return line;
    }

    free(line); // Free allocated memory in case of failure
    return NULL;
}

int main() {
    FILE *fin = fopen("file1.txt", "r");

    char* url;
    if ( fin ) {
        while ( char *line = read_line(fin) ) {
            if ( (url = strstr(line, "url=")) != NULL ) {
                fprintf(stdout, "%s \n", url);

                // Allocate memory for url and copy the data
                url = strdup(url);

                // Process data

                free(url); // Free allocated memory after processing
            }
            free(line);
        }
    }

    fclose(fin);
    return 0;
}

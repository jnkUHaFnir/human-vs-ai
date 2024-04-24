#include <stdio.h>
#include <stdlib.h>

int main() {
    // Reading from stdin
    printf("Reading from stdin:\n");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("Line length: %zu\n", read);
        printf("Content: %s", line);
    }

    free(line);

    // Reading from a file
    printf("Reading from a file:\n");
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        exit(EXIT_FAILURE);
    }

    line = NULL;
    len = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        printf("Line length: %zu\n", read);
        printf("Content: %s", line);
    }

    fclose(file);
    free(line);
    exit(EXIT_SUCCESS);
}

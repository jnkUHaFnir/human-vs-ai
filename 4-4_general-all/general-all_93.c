#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read lines from stdin until EOF is encountered
    while ((read = getline(&line, &len, stdin)) != -1) {
        // Print the line read (including spaces)
        printf("Line read: %s", line);
    }

    // Free the allocated memory
    free(line);

    return 0;
}

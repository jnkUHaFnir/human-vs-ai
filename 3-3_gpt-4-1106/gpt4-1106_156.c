#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024  // Define your buffer size (including space for the null-terminator)

int main() {
    char buf[BUFFER_SIZE];

    while (fgets(buf, BUFFER_SIZE, stdin)) {
        // Remove newline character if present
        buf[strcspn(buf, "\n")] = 0;

        // Process the input
        // ...

        // If you want to read the next line, continue the loop
    }
    return 0;
}
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf = NULL;
    size_t buf_size = 0;
    ssize_t line_size;

    while ((line_size = getline(&buf, &buf_size, stdin)) != -1) {
        // Remove newline character if present
        if (line_size > 0 && buf[line_size - 1] == '\n') {
            buf[line_size - 1] = '\0';
            --line_size;
        }

        // Process the input
        // ...

        // It's not necessary to clear the buffer since getline will handle it on the next iteration.
    }

    // Don't forget to free the memory allocated by getline
    free(buf);
    return 0;
}

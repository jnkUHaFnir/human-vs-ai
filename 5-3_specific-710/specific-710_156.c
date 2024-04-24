#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 100

int main() {
    char *buf = (char *)malloc(INITIAL_BUF_SIZE * sizeof(char));
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    char tmp[INITIAL_BUF_SIZE]; // Temporary buffer for input

    while (1) {
        printf("Enter a string: ");
        if (fgets(tmp, sizeof(tmp), stdin) == NULL) {
            break; // Error or EOF
        }

        size_t len = strlen(tmp);
        if (tmp[len - 1] == '\n') {
            // Remove newline character if present
            tmp[len - 1] = '\0';
        } else {
            // Input too long to fit in tmp buffer, discard extra characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }

        // Reallocate buf if needed
        size_t new_len = strlen(buf) + strlen(tmp) + 1; // +1 for null terminator
        if (new_len > strlen(buf) + INITIAL_BUF_SIZE) {
            char *new_buf = (char *)realloc(buf, new_len * sizeof(char));
            if (new_buf == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(buf);
                return 1;
            }
            buf = new_buf;
        }

        strcat(buf, tmp); // Concatenate input to buf

        if (tmp[len - 1] == '\0') { // Check if the input ended with a null terminator
            break;
        }
    }

    printf("Input: %s\n", buf);

    free(buf);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char *buf = NULL;
    char input[MAX_INPUT_SIZE];

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character at the end of input
        input[strcspn(input, "\n")] = 0;

        // Allocate memory for buf dynamically based on input length
        buf = malloc(strlen(input) + 1);
        if (buf == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        // Copy input to buf
        strcpy(buf, input);

        // Use buf for processing
        printf("Input: %s\n", buf);

        // Free memory when no longer needed
        free(buf);
        buf = NULL;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *inputBuffer = NULL;
    size_t bufferSize = 0;
    ssize_t charactersRead;

    // Read input line by line
    while ((charactersRead = getline(&inputBuffer, &bufferSize, stdin)) != -1) {
        // Process the input line
        printf("Input line: %s", inputBuffer);
    }

    // Free the memory allocated for the input buffer
    free(inputBuffer);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *inputBuffer = NULL;
    size_t bufferSize = 0;
    ssize_t charactersRead;

    // Read input line by line
    while ((charactersRead = getline(&inputBuffer, &bufferSize, file)) != -1) {
        // Process the input line
        printf("Input line: %s", inputBuffer);
    }

    // Free the memory allocated for the input buffer
    free(inputBuffer);
    fclose(file);
    return 0;
}

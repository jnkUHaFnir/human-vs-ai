#include <stdio.h>
#include <stdlib.h>

int read_string(char** output) {
    int counter = 0;
    int buffer_size = 1; // Initial size of buffer
    *output = (char*)malloc(buffer_size * sizeof(char));

    if (*output == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    char input;
    while ((input = getchar()) != '\n') {
        (*output)[counter] = input;
        counter++;

        // Resize the buffer if needed
        if (counter >= buffer_size) {
            buffer_size *= 2;
            char* temp = (char*)realloc(*output, buffer_size * sizeof(char));
            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(*output);
                return -1;
            }
            *output = temp;
        }
    }

    (*output)[counter] = '\0'; // Add null terminator at the end
    return counter;
}

int main() {
    char* input;
    int length = read_string(&input);

    if (length >= 0) {
        printf("Input string: %s\n", input);
        printf("Length of string: %d\n", length);
    }

    free(input); // Free dynamically allocated memory
    return 0;
}

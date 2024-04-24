#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char *input = NULL;
    size_t input_length = 0;

    printf("Enter a string: ");
    if (scanf("%zu", &input_length) != 1) {
        printf("Invalid input length\n");
        return 1;
    }

    // Allocate memory for the input buffer
    input = (char *)malloc(input_length + 1); // +1 for null terminator

    if (input == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string (max %zu characters): ", input_length);
    if (gets_s(input, input_length) != NULL) {
        printf("Input: %s\n", input);
    } else {
        printf("Error reading input\n");
    }

    // Free dynamically allocated memory
    free(input);

    return 0;
}

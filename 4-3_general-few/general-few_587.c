#include <stdio.h>
#include <stdlib.h>

int parseHexToInt(const char *input, size_t offset) {
    // Check input string and offset bounds
    if (input == NULL || offset >= strlen(input) - 3) {
        fprintf(stderr, "Invalid input or offset\n");
        exit(EXIT_FAILURE);
    }

    int result = 0;
    char hex[5];
    // Copy the 4 hex characters to a separate string
    strncpy(hex, input + offset, 4);
    hex[4] = '\0';

    // Convert hex string to integer
    sscanf(hex, "%x", &result);

    return result;
}

int main() {
    const char *input = "foo10a4bar";
    size_t offset = 3;

    int result = parseHexToInt(input, offset);
    printf("%d\n", result);

    return 0;
}
``` 

This code snippet defines a function `parseHexToInt` that takes the input string and the offset as parameters, extracts the 4 hex characters at the given offset, and converts them to an integer. It performs bounds checking to ensure safe operation and signals an error if the input is invalid.

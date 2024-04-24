#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Example input
    char input[] = "ABCDEFGH";
    int input_len = strlen(input);

    // Calculate output length and allocate memory for output string
    // Note: +1 for the null terminator
    int output_len = (2 * input_len) - 1;
    char* output = (char*)malloc(output_len + 1);

    if (!output) {
        // Allocation failed
        return 1;
    }

    // Loop to fill the output string
    for (int i = 0, j = 0; i < input_len; i+=2, j+=3) {
        output[j] = input[i];       // Copy character from input
        if (i+1 < input_len) {
            output[j+1] = input[i+1];   // Copy next character from input
        }
        if (j + 2 < output_len) {    // Check if a space should be added (not after the last character pair)
            output[j+2] = ' ';      // Insert space
        }
    }
    output[output_len] = '\0'; // Null-terminate the output string

    printf("Output: %s\n", output);

    // Free the allocated memory
    free(output);

    return 0;
}

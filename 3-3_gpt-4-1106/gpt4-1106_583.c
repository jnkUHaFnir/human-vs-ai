#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[] = "ABCDEFGH"; // Original input
    int input_len = strlen(input);
    int output_len = input_len + (input_len / 2) - 1; // Calculate the new length with spaces
    char *output = (char *)malloc(sizeof(char) * (output_len + 1)); // Allocate memory for output (+1 for null terminator)

    int input_index = 0;
    int output_index = 0;

    while (input_index < input_len) {
        // Copy two characters from input to output
        output[output_index++] = input[input_index++];
        output[output_index++] = input[input_index++];
        
        // If we are not at the end, add a space
        if (input_index < input_len) {
            output[output_index++] = ' ';
        }
    }

    // Add the null terminator at the end of the string
    output[output_index] = '\0';

    printf("%s\n", output); // Output the result

    // Free the allocated memory for the output array
    free(output);

    return 0;
}

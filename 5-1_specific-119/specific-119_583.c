#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "ABCDEFGHIJKL"; // Original input
    int input_len = strlen(input);
    int output_len = (2 * input_len) - 1;

    char output[output_len]; // New array to store modified string
    int j = 0;

    for (int i = 0; i < input_len - 1; i += 2) {
        output[j++] = input[i];
        output[j++] = input[i + 1];
        if (i != input_len - 2) {
            output[j++] = ' ';
        }
    }

    output[output_len] = '\0'; // Null-terminate the output string

    printf("Original input: %s\n", input);
    printf("Modified output: %s\n", output);

    return 0;
}

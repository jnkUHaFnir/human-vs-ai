#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[] = "ABCDEFGHIJKL";
    int input_len = strlen(input);
    int output_len = 2 * input_len - 1;
    char *output = malloc((output_len + 1) * sizeof(char)); // +1 for null-terminator

    int j = 0;
    for (int i = 0; i < input_len; i++) {
        output[j++] = input[i];
        if (i % 2 == 1 && i < input_len - 1) {
            output[j++] = ' ';
        }
    }
    output[j] = '\0'; // adding null-terminator

    printf("Input: \"%s\"\n", input);
    printf("Output: \"%s\"\n", output);

    free(output); // don't forget to free the allocated memory

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[] = "ABCDEFGHI";
    int input_len = strlen(input);
    int output_len = (2 * input_len) - 1;
    char *output = (char*)malloc(output_len + 1); // Allocate memory for output array

    int j = 0;
    for (int i = 0; i < input_len; i += 2) {
        output[j++] = input[i];
        output[j++] = input[i + 1];
        if (i < input_len - 2) {
            output[j++] = ' ';
        }
    }
    output[output_len] = '\0';

    printf("%s\n", output);

    free(output); // Free allocated memory

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "ABCDEFGHI";
    int input_len = strlen(input);
    int output_len = (2*input_len) - 1;
    char output[output_len + 1]; // +1 for the null terminator

    int j = 0;
    for (int i = 0; i < input_len; i++) {
        output[j++] = input[i];
        if (i < input_len - 1) {
            output[j++] = ' ';
        }
    }
    output[output_len] = '\0'; // null terminate the string

    printf("Output: %s\n", output);

    return 0;
}

#include <stdio.h>

void deldigit(char *input, char *output) {
    while (*input) {
        if (!(*input >= '0' && *input <= '9')) {
            *output = *input;
            output++;
        }
        input++;
    }
    *output = '\0'; // Null-terminate the output string
}

int main() {
    char str[100];
    char result[100];

    printf("Insert word: ");
    scanf("%99[^\n]", str); // Read up to 99 characters without whitespace

    deldigit(str, result);

    printf("Result: %s\n", result);

    return 0;
}

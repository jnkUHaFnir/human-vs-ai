#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    char reverse[100];

    printf("Enter a number\n");
    fgets(input, 100, stdin);

    // Remove newline character from the end of the input if present
    size_t numLen = strlen(input);
    if (numLen > 0 && input[numLen - 1] == '\n') {
        input[numLen - 1] = '\0';
        numLen--; // Adjust the length after removing the newline
    }

    printf("The number is: %s\n", input);
    printf("Length of string is: %zu\n", numLen); // Use %zu for size_t

    for (size_t i = 0; i < numLen; i++) {
        reverse[i] = input[numLen - 1 - i];
    }
    reverse[numLen] = '\0'; // Terminate the reverse string outside the loop

    printf("The reverse number is: %s\n", reverse);
    printf("The original number is: %s\n", input);

    int result = strcmp(input, reverse);
    printf("Result of strcmp gives us: %d\n", result);

    if (result == 0) {
        printf("These numbers are palindromes\n");
    } else {
        printf("These numbers are not palindromes\n");
    }

    return 0;
}

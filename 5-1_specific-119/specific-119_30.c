#include <stdio.h>

#define MAX_INPUT_LENGTH 1000 // Maximum length of input line

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    printf("You entered: %s", input);

    return 0;
}

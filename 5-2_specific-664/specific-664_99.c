#include <stdio.h>
#include <string.h>

void processSingleCharInput(char c) {
    // Process the single character input
    printf("You entered: %c\n", c);
}

void processMultipleCharInput(const char *input) {
    // Process the case when multiple characters are entered
    printf("Multiple characters entered: %s\n", input);
}

int main() {
    char input[2]; // Allow for a single character and null terminator

    printf("Enter a single character: ");
    fgets(input, 2, stdin);

    // Remove trailing newline character if present
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 1) {
        processSingleCharInput(input[0]);
    } else {
        processMultipleCharInput(input);
    }

    return 0;
}

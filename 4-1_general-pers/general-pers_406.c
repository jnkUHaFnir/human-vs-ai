#include <stdio.h>

#define MAX_INPUT_LENGTH 50

int main() {
    char userInput[MAX_INPUT_LENGTH];

    printf("Enter a string (max %d characters): ", MAX_INPUT_LENGTH - 1);
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        // Remove the trailing newline character if present
        size_t len = strlen(userInput);
        if (len > 0 && userInput[len-1] == '\n') {
            userInput[len-1] = '\0';
        }

        // Handle the user input here
        printf("You entered: %s\n", userInput);
    } else {
        // Handle fgets error or EOF condition
        printf("Error reading input.\n");
    }

    return 0;
}

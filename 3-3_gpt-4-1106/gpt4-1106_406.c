#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of the input, plus one for the null terminator
#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    errno_t err;

    // Prompt the user to enter a string
    printf("Enter a string up to %d characters: ", MAX_INPUT_LENGTH - 1);

    // Use gets_s to get the input
    err = gets_s(input, sizeof(input));

    if (err != 0) {
        // Handle error when input is too long or another error occurs
        if (input[0] == '\0') {
            // If the first character is a null terminator, the input was too long
            printf("Input was too long, please try again.\n");
        } else {
            // Other error occurred
            printf("An error occurred while reading input.\n");
        }
        // Handle the error gracefully here. For instance, you may want to give the
        // user another chance to enter the input or exit the program with an error message.

    } else {
        // Input was successfully read into the buffer
        printf("You entered: %s\n", input);
    }

    return 0;
}

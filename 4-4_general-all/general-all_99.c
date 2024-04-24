#include <stdio.h>
#include <stdlib.h>

void handleSingleCharInput(char input) {
    // Function to process single character input
    printf("You entered: %c\n", input);
}

void handleMultiCharInput() {
    // Function to handle multiple characters input
    printf("You entered more than one character. Please enter only a single character.\n");
    // Clear input buffer by reading and discarding extra characters
    while(getchar() != '\n');
}

int main() {
    char input;

    printf("Enter a single character: ");
    // Read a single character
    scanf("%c", &input);

    // Check if there are extra characters in the input buffer
    if(getchar() != '\n') {
        handleMultiCharInput();
    } else {
        handleSingleCharInput(input);
    }

    return 0;
}

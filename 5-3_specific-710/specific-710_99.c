#include <stdio.h>

void handleSingleCharInput() {
    char c;
    printf("Enter a single character: ");
    
    // Read a single character
    c = getchar();
    
    // Check if there are more characters in the input buffer
    if (getchar() != '\n') {
        // Clear the input buffer
        while (getchar() != '\n');
        
        // Call the function that should run for multiple inputs
        handleMultipleCharInput();
    } else {
        // Process the single character input
        printf("You entered: %c\n", c);
        // Continue with the rest of your program
    }
}

void handleMultipleCharInput() {
    printf("You entered more than one character. Handling multiple characters...\n");
    // Add your logic here for handling multiple characters
}

int main() {
    handleSingleCharInput();
    return 0;
}

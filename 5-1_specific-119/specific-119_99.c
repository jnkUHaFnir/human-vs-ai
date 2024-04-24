#include <stdio.h>
#include <string.h>

void handleSingleCharInput() {
    char input[2]; // We will read a maximum of 2 characters (1 char + '\0')

    printf("Enter a character: ");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (strlen(input) > 2 || input[1] != '\n') {
            printf("Multiple characters entered! Handling multiple characters...\n");
            // Call the function to handle multiple character input
        } else {
            char ch = input[0];
            printf("You entered: %c\n", ch);
            // Continue with your single character logic here
        }
    }
}

void handleMultipleCharInput() {
    printf("Handling multiple characters...\n");
    // Add your code to handle multiple character input here
}

int main() {
    handleSingleCharInput();

    return 0;
}

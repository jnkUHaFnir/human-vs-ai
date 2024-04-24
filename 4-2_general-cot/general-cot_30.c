#include <stdio.h>

int main() {
    char input[256]; // Define a buffer to store the input

    printf("Enter a line of text:\n");
    
    // Read a line of text from stdin
    if(fgets(input, sizeof(input), stdin) != NULL) {
        // Display the input
        printf("You entered: %s\n", input);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}

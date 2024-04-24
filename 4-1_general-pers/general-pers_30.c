#include <stdio.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    
    printf("Enter a line of text: ");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Check for buffer overflow scenario by looking for the newline character
        if (strchr(input, '\n') == NULL) {
            // Clear input buffer if overflow has occurred
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        
        printf("You entered: %s\n", input);
    } else {
        printf("Error reading input.\n");
    }
    
    return 0;
}

#include <stdio.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter a string (up to %d characters): ", MAX_INPUT_LENGTH - 1);
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        for (int i = 0; i < MAX_INPUT_LENGTH; i++) {
            if (input[i] == '\n') {
                input[i] = '\0';
                break;
            }
        }
        
        printf("You entered: %s\n", input);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}

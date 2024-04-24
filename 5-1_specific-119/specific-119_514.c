#include <stdio.h>

int main() {
    int x;
    char prevInput = ' ';
    char input = ' ';
    
    while (1) {
        prevInput = input;
        if (scanf(" %c", &input) == 1) { // Read a character (ignoring leading whitespace)
            if (input == ' ' && prevInput == ' ') {
                // Two consecutive whitespaces detected
                printf("Two consecutive whitespaces found!\n");
                // Do something different with the next set of data here
            } else if (input == ' ') {
                // Single whitespace found
                printf("Single whitespace found\n");
                // Do something specific when a single whitespace is encountered
            } else {
                // Character other than whitespace found
                printf("Non-whitespace character found\n");
                // Handle non-whitespace character if needed
            }
        } else {
            break; // Exit loop if input is not a character
        }
    }

    return 0;
}

#include <stdio.h>

int main() {
    char x[50]; // Adjust size as needed
    char termChar;

    // Attempt to read up to 49 characters or until a ':' is encountered
    while (scanf("%49[^:]", x) == 1) {
        // Check if the next character is actually ':'
        if (scanf("%c", &termChar) == 1 && termChar == ':') {
            // Add ':' to the end of the read string
            int len = strlen(x);
            if (len < sizeof(x) - 1) {
                x[len] = ':';
                x[len + 1] = '\0';
            }
            printf("Read string: %s\n", x);
            // Handle the read data before moving to the next iteration
            // ...
        } else {
            // Handle the case where ':' was not the terminating character, if necessary
            break; // Exit if no ':' is found or end of input
        }
    }

    return 0;
}

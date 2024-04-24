#include <stdio.h>

#define MAX_LENGTH 50

int main() {
    char buffer[MAX_LENGTH];

    printf("Enter a string (up to %d characters): ", MAX_LENGTH - 1);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Handle the input string here
        printf("You entered: %s", buffer);
    } else {
        // Handle input error or end of file
        printf("Error reading input.\n");
    }

    return 0;
}

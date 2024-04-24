#include <stdio.h>

int main() {
    char buffer[1024]; // Define a buffer to store the input line
    printf("Enter a line of text:\n");

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // fgets has successfully read the input line
        printf("You entered: %s\n", buffer);
    } else {
        // Error handling if fgets fails
        printf("Error reading input\n");
    }

    return 0;
}

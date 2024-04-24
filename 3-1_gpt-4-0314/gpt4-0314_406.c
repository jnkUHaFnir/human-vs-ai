#include <stdio.h>
#include <string.h>

int main() {
    const size_t MAX_LENGTH = 50;
    char input[MAX_LENGTH + 1]; // One extra for the null terminator

    fputs("Please enter a string: ", stdout);
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin)) {
        // Strip the newline character if it's present
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        } else {
            // Remove extra characters left in the buffer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        printf("You entered: %s\n", input);
    } else {
        printf("Error occurred while reading input.\n");
    }

    return 0;
}

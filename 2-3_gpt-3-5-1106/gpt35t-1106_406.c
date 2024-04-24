#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // specify the maximum length of the input string

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // use fgets() to get the input

    // remove the trailing newline character from the input
    input[strcspn(input, "\n")] = 0;

    if(strlen(input) >= 100) {
        printf("Error: Input string is too long\n");
        // handle the error gracefully, for example, by asking the user to re-enter a valid input
    } else {
        // process the input string
        printf("You entered: %s\n", input);
    }

    return 0;
}

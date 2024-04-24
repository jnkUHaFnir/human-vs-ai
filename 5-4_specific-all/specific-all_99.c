#include <stdio.h>
#include <string.h>

void singleCharInput() {
    char input[2]; // Including space for null terminator

    printf("Enter a single character: ");
    if (fgets(input, sizeof(input), stdin)) {
        if (strlen(input) == 2 && input[1] == '\n') {
            // Valid single character input
            char singleChar = input[0];
            printf("You entered: %c\n", singleChar);
            // Continue with your program logic here
        } else {
            printf("Error: Please enter only a single character.\n");
            // Handle this case, maybe ask user to input again
        }
    } else {
        printf("Error reading input.\n");
    }
}

void multipleCharInput() {
    printf("Too many characters entered. This function will handle it.\n");
    // Code to handle multiple character input
}

int main() {
    char input[100]; // Just for this example

    singleCharInput(); // Call the function for single character input

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int prev_space = 0; // Indicates if the last character was a space (0 for no, 1 for yes)
    int ch; // To store the current character
    int num; // To store the current number
    int current_sum = 0; // Example variable to do something with a group of numbers (sum in this case)
    int space_count = 0; // Counter for consecutive spaces

    while ((ch = getc(stdin)) != EOF) {
        if (isspace(ch)) { // Check if the current character is a space
            space_count++; // Increment consecutive space counter
            if (space_count == 2) {
                printf("Group sum: %d\n", current_sum); // Example action when a new group is detected
                current_sum = 0; // Reset sum for the new group
            }
        } else if (isdigit(ch)) { // Check if it's a digit
            ungetc(ch, stdin); // Push the digit back to be read by scanf
            if (scanf("%d", &num) == 1) {
                current_sum += num; // Example operation with the number
            }
            space_count = 0; // Reset space counter as we encountered a non-space character
        }
    }

    // Handle the final group if any
    if (current_sum > 0) {
        printf("Group sum: %d\n", current_sum);
    }

    return 0;
}

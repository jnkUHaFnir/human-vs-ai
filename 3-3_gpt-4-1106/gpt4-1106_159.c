#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void) {
    long input; // Use a larger type to store the input
    char buffer[50]; // Buffer to store string representation of input

    printf("Enter an integer: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Error reading input!\n");
        return 1;
    }
    
    // Convert to a long to check the value is within int range
    char *endptr; // For detecting non-numeric input
    input = strtol(buffer, &endptr, 10); // Base 10 for decimal

    if (*endptr != '\n' && *endptr != '\0') {
        printf("Invalid input. Please enter numeric values only.\n");
    } else if (input < INT_MIN || input > INT_MAX) {
        printf("The entered number is out of the range of int. Please enter a value between %d and %d.\n", INT_MIN, INT_MAX);
    } else {
        int valid_int = (int)input; // Safe to cast now
        printf("You entered the valid int value: %d\n", valid_int);
    }

    return 0;
}

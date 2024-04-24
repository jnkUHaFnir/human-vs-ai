#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char input[20]; // Assuming the input will not exceed 20 characters

    // Get user input
    printf("Enter an integer: ");
    fgets(input, sizeof(input), stdin);

    // Convert input to a long integer
    char *endptr;
    long num = strtol(input, &endptr, 10);

    // Check if conversion was successful
    if (endptr == input) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Check if the number fits within the range of an int
    if (num > INT_MAX || num < INT_MIN) {
        printf("Input value exceeds the range of an int. Please enter a smaller integer.\n");
    } else {
        int result = (int)num; // Safely cast to int
        printf("Input value is within the range of an int: %d\n", result);
        // Use 'result' as needed in the program
    }

    return 0;
}

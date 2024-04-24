#include <stdio.h>
#include <limits.h>
int main() {
    char input[20]; // Buffer to hold user input string.
    long long value; // To hold the converted value which has a wider range than int.

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin); // Read input as string to prevent overflow.
    sscanf(input, "%lld", &value); // Attempt to convert string to long long.

    // Check if the number is within the range of an int.
    if (value < INT_MIN || value > INT_MAX) {
        printf("The number you entered is out of range. Please enter a number between %d and %d.\n", INT_MIN, INT_MAX);
    } else {
        printf("You entered: %lld, which is within the int range.\n", value);
    }

    return 0;
}

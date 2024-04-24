#include <stdio.h>
#include <stdlib.h>

// Function to print the array as a base-10 number
void printArrayAsBase10(unsigned char *n, size_t size) {
    // Temporary array to hold base-10 representation (digits).
    char *digits = malloc(size * 3); // Each byte can have a max of 3 decimal digits.
    if (!digits) {
        printf("Memory allocation failed\n");
        return;
    }

    int digitCount = 0; // Count of digits in the base-10 representation
    int i, j;

    for (i = 0; i < size; ++i) {
        int carry = n[i];
        for (j = 0; j < digitCount || carry != 0; ++j) {
            if (j < digitCount) {
                carry += digits[j] * 256; // Multiply by base
            }
            if (j >= digitCount) {
                // Ensure space for another digit
                digits[digitCount++] = carry % 10;
            } else {
                digits[j] = carry % 10;
            }
            carry /= 10; // Carry is the division result
        }
    }

    // Print the digits in reverse order
    for (i = digitCount - 1; i >= 0; --i) {
        printf("%d", digits[i]);
    }
    printf("\n");

    free(digits); // Don't forget to free the allocated memory
}

// Example usage
int main() {
    unsigned char n[3] = {1, 2, 3}; // Your example {1, 2, 3} would print "197121"
    printArrayAsBase10(n, 3);

    return 0;
}

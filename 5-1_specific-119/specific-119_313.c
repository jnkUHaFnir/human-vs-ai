#include <stdio.h>

// Function to convert the unsigned char array to a base 10 number
void printBase10(unsigned char *array, int size) {
    // Initialize a result array to store the final number
    int result[100] = {0}; // Assuming max 100 digits for simplicity

    // Iterating over the array from the end to the beginning
    for (int i = size - 1; i >= 0; i--) {
        int carry = 0;
        // Multiply each digit in the result array by 256 and add the current digit
        for (int j = 0; j < 100; j++) {
            int product = result[j] * 256 + array[i] + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
    }

    // Find the most significant digit position
    int mostSignificantDigit = 99;
    while (mostSignificantDigit > 0 && result[mostSignificantDigit] == 0) {
        mostSignificantDigit--;
    }

    // Print the number
    printf("Number in base 10: ");
    for (int i = mostSignificantDigit; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printBase10(n, 3);

    return 0;
}

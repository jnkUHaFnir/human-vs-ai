#include <stdio.h>

// Function to convert an array of unsigned chars to a decimal number
unsigned long long arrayToDecimal(unsigned char *array, int size) {
    unsigned long long result = 0;
    unsigned long long base = 1;

    for (int i = size - 1; i >= 0; i--) {
        result += array[i] * base;
        base *= 256; // Base is raised to 256 for each byte position
    }

    return result;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    // Get the decimal representation of the number
    unsigned long long decimalNumber = arrayToDecimal(n, 3);

    // Print the decimal number
    printf("%llu\n", decimalNumber);

    return 0;
}

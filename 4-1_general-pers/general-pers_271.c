#include <stdio.h>
#include <stdlib.h>

void printLargeNumber(unsigned char arr[], size_t size) {
    // Initialize variables for the result in base 10
    unsigned long long result = 0;
    unsigned long long base = 1; // Represents the base 10 multiplier

    // Iterate over the array elements from least significant to most significant
    for (int i = size - 1; i >= 0; i--) {
        // Add the current array element multiplied by the appropriate power of 256 to the result
        result += arr[i] * base;
        base *= 256;
    }

    // Print the result as a decimal number
    printf("%llu\n", result);
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    printLargeNumber(n, sizeof(n) / sizeof(n[0]));

    return 0;
}

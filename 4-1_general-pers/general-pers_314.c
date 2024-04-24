#include <stdio.h>
#include <stdint.h>

// Function to convert an array of unsigned chars representing a number in base 256 to base 10.
void printBase10(unsigned char* array, int size) {
    // Initialize variables for calculations
    uint64_t base10 = 0;
    uint64_t multiplier = 1;

    // Calculate the base 10 value
    for (int i = 0; i < size; i++) {
        base10 += ((uint64_t)array[i]) * multiplier;
        multiplier *= 256;
    }

    // Print the base10 value
    printf("%llu\n", base10);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printBase10(n, 3);

    return 0;
}

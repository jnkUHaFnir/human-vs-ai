#include <stdio.h>

void convertToBase10(unsigned char *array, int size) {
    // Initialize variables for base 10 representation
    unsigned long long base10 = 0;
    unsigned long long multiplier = 1;

    // Convert from base 256 to base 10
    for (int i = size - 1; i >= 0; i--) {
        base10 += (unsigned long long)array[i] * multiplier;
        multiplier *= 256;
    }

    // Print the number in base 10
    printf("%llu\n", base10);
}

int main() {
    // Define the unsigned char array
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    // Print the number in base 10
    convertToBase10(n, 3);

    return 0;
}

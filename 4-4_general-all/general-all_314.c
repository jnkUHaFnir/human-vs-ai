#include <stdio.h>

void printBase10(unsigned char *arr, int size) {
    // Initialize variables for base 10 number and multiplier
    unsigned long long base10 = 0;
    unsigned long long multiplier = 1;

    // Calculate base 10 value by iterating through the array
    for (int i = size - 1; i >= 0; i--) {
        base10 += arr[i] * multiplier;
        multiplier *= 256; // 256 for base 256 conversion
    }

    // Print the base 10 number
    printf("%llu\n", base10);
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    printBase10(n, 3); // Print base 10 representation of the array

    return 0;
}

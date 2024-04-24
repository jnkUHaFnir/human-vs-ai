#include <stdio.h>

void printBase10(unsigned char* arr, int size) {
    // Initialize variables for base 10 conversion
    unsigned long long base10 = 0;
    unsigned long long base = 1;

    // Perform base 256 to base 10 conversion
    for (int i = size - 1; i >= 0; i--) {
        base10 += arr[i] * base;
        base *= 256;
    }

    // Print the base 10 number
    printf("%llu\n", base10);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    int size = sizeof(n) / sizeof(n[0]);

    // Print in base 10
    printBase10(n, size);

    return 0;
}

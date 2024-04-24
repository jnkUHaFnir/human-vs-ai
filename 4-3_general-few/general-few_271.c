#include <stdio.h>

void printBigNumber(unsigned char n[], int size) {
    unsigned long long result = 0;

    // Calculate the decimal value of the big number
    for (int i = size - 1; i >= 0; i--) {
        result = result * 256 + n[i];
    }

    // Print the decimal value
    printf("%llu\n", result);
}

int main() {
    // Initialize the array with your values
    unsigned char n[3] = {1, 2, 3};
    int size = sizeof(n) / sizeof(n[0]);

    // Print the big number in base 10
    printBigNumber(n, size);

    return 0;
}

#include <stdio.h>

// Function to convert an array of unsigned chars to a decimal number
unsigned long long convertToDecimal(unsigned char arr[], int size) {
    unsigned long long result = 0;
    unsigned long long base = 1;

    for(int i = 0; i < size; i++) {
        result += arr[i] * base;
        base *= 256;
    }

    return result;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    int size = sizeof(n) / sizeof(n[0]);

    unsigned long long decimalNumber = convertToDecimal(n, size);

    printf("%llu\n", decimalNumber);

    return 0;
}

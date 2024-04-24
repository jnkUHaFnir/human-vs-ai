#include <stdio.h>

void printNumber(unsigned char *arr, size_t size) {
    // Initialize variables
    unsigned long long result = 0;
    unsigned long long base = 1;

    // Convert from base 256 to base 10
    for (int i = size - 1; i >= 0; i--) {
        result += arr[i] * base;
        base *= 256;
    }

    // Print the number in base 10
    printf("%llu\n", result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printNumber(n, sizeof(n)/sizeof(n[0]));

    return 0;
}

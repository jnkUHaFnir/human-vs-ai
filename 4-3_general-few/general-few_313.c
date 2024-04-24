#include <stdio.h>

void printLargeNumber(unsigned char n[], int size) {
    unsigned long long result = 0;
    unsigned long long base = 1;

    for (int i = size - 1; i >= 0; i--) {
        result += (unsigned long long)n[i] * base;
        base *= 256; // Move to the next 256 base
    }

    printf("%llu\n", result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printLargeNumber(n, 3);

    return 0;
}

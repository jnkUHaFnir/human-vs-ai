#include <stdio.h>

unsigned long long convertToBase10(unsigned char *arr, int size) {
    unsigned long long base10Val = 0;
    unsigned long long powerOf256 = 1;

    for (int i = 0; i < size; i++) {
        base10Val += arr[i] * powerOf256;
        powerOf256 *= 256;
    }

    return base10Val;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned long long decimalValue = convertToBase10(n, 3);

    printf("%llu\n", decimalValue);

    return 0;
}

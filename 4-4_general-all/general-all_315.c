#include <stdio.h>

void printArrayAsDecimal(unsigned char arr[], int size) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    // Convert the unsigned char array to a decimal number
    for (int i = size - 1; i >= 0; i--) {
        decimal += arr[i] * base;
        base *= 256;
    }

    // Print the decimal number
    printf("%llu\n", decimal);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printArrayAsDecimal(n, 3);

    return 0;
}

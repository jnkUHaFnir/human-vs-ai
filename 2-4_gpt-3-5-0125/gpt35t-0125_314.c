#include <stdio.h>

unsigned long long convertToDecimal(unsigned char *arr, int size) {
    unsigned long long result = 0;
    int power = 1;

    for (int i = size - 1; i >= 0; i--) {
        result += arr[i] * power;
        power *= 256;
    }

    return result;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned long long decimalNumber = convertToDecimal(n, 3);

    printf("%llu\n", decimalNumber);

    return 0;
}

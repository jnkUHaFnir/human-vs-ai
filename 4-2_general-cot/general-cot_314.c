#include <stdio.h>

unsigned long long convertToBase10(unsigned char *array, int size) {
    unsigned long long result = 0;

    for (int i = size - 1; i >= 0; i--) {
        result = result * 256 + array[i];
    }

    return result;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned long long base10Number = convertToBase10(n, 3);
    printf("%llu\n", base10Number);

    return 0;
}

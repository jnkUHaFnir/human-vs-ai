#include <stdio.h>

void multiply(unsigned char result[], unsigned char num, unsigned char size) {
    unsigned char carry = 0;
    for (int i = 0; i < size; i++) {
        unsigned int temp = (unsigned int)result[i] * 256 + carry;
        result[i] = (unsigned char)(temp % 10);
        carry = (unsigned char)(temp / 10);
    }
}

void arrayToBase10(unsigned char n[], unsigned char size) {
    unsigned char result[size];
    for (int i = 0; i < size; i++) {
        result[i] = 0;
    }

    result[0] = n[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        multiply(result, 256, size);
        result[0] += n[i];
    }

    for (int i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    arrayToBase10(n, 3);

    return 0;
}

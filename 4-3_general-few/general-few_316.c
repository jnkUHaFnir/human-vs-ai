#include <stdio.h>

void printBase10(unsigned char n[], int size) {
    unsigned long long base10 = 0;
    unsigned long long factor = 1;

    for (int i = 0; i < size; i++) {
        base10 += (unsigned long long)n[i] * factor;
        factor *= 256;
    }

    printf("%llu\n", base10);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printBase10(n, 3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void arrayToBase10(unsigned char* arr, size_t size) {
    unsigned long long base10 = 0;
    unsigned long long multiplier = 1;

    for (int i = size - 1; i >= 0; i--) {
        base10 += arr[i] * multiplier;
        multiplier *= 256;
    }

    printf("%llu\n", base10);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    arrayToBase10(n, sizeof(n)/sizeof(n[0]));

    return 0;
}

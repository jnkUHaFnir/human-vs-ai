#include <stdio.h>

void printLargeNumber(unsigned char* array, int size) {
    unsigned char base = 1;
    unsigned char digit;
    int i, j;
    long long result = 0;

    for (i = size - 1; i >= 0; i--) {
        digit = array[i];
        for (j = 0; j < i; j++) {
            base *= 256;
        }
        result += digit * base;
        base = 1; // Reset base for next iteration
    }

    printf("%lld\n", result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printLargeNumber(n, 3);
    
    return 0;
}

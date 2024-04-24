#include <stdio.h>

void printBinary(unsigned int n) {
    if (n > 1) {
        printBinary(n >> 1);
    }
    putchar((n & 1) ? '1' : '0');
}

int main() {
    unsigned int a = 5;
    printf("Binary representation of a = ");
    printBinary(a);
    printf("\n");
    return 0;
}

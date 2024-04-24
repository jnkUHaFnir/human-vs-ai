#include <stdio.h>

void printBinary(int num) {
    if (num) {
        printBinary(num >> 1);  // Recursively shift bits to the right
        putchar('0' + (num & 1));  // Print the rightmost bit
    }
}

int main() {
    int a = 5;
    printf("binary representation of a = ");
    printBinary(a);
    printf("\n");
    return 0;
}

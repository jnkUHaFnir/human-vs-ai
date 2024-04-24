#include<stdio.h>

void printBinary(unsigned int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    unsigned int a = 5;
    printf("Binary representation of a = ");
    printBinary(a);
    printf("\n");

    return 0;
}

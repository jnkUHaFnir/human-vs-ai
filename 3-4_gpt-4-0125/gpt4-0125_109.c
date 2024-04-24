#include <stdio.h>

void printBinary(unsigned int val) {
    for (int i = sizeof(val) * 8 - 1; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

int main() {
    char a = 5;
    printf("binary representation of a = ");
    printBinary(a);
    printf("\n");
    return 0;
}

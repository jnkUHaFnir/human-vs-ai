#include <stdio.h>

void print_binary(int num) {
    unsigned int mask = 1 << (sizeof(num) * 8 - 1);

    for (; mask; mask >>= 1) {
        printf("%c", num & mask ? '1' : '0');
    }
}

int main() {
    int a = 5;
    printf("Binary representation of a = ");
    print_binary(a);
    printf("\n");

    return 0;
}

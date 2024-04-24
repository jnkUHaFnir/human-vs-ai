#include <stdio.h>
#include <stdlib.h>

char *int_to_binary(int n) {
    if (n == 0) {
        return "0";
    }

    int bits = sizeof(n) * 8; // Assuming integer is 32 bits
    char *binary = (char *)malloc(bits + 1);
    binary[bits] = '\0';

    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }

    return binary;
}

int main() {
    int a = 5;
    char *binary = int_to_binary(a);
    printf("binary representation of a = %s\n", binary);

    free(binary);
    return 0;
}

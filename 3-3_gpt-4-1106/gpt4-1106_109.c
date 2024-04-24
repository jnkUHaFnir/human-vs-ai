#include <stdio.h>

void print_binary(unsigned int n) {
    unsigned int num_bits = sizeof(n) * 8;
    for (int i = num_bits - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
    }
}

int main() {
    char a = 5;
    printf("binary representation of a = ");
    print_binary(a);
    printf("\n");

    return 0;
}
void print_binary(unsigned int n, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
    }
}

int main() {
    char a = 5;
    printf("binary representation of a = ");
    print_binary(a, 8); // print 8 bits for a char
    printf("\n");

    return 0;
}

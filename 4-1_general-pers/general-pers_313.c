#include <stdio.h>
#include <gmp.h>

void printUnsignedCharArrayAsDecimal(unsigned char *arr, size_t size) {
    mpz_t decimal;
    mpz_init(decimal);

    for (size_t i = 0; i < size; i++) {
        mpz_mul_ui(decimal, decimal, 256);
        mpz_add_ui(decimal, decimal, arr[i]);
    }

    gmp_printf("%Zd\n", decimal);

    mpz_clear(decimal);
}

int main() {
    unsigned char n[3] = {1, 2, 3}; // Array of size 3 for demonstration
    size_t size = 3;

    printUnsignedCharArrayAsDecimal(n, size);

    return 0;
}

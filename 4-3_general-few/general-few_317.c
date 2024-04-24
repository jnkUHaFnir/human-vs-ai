#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    mpz_t base10;
    mpz_init(base10);

    mpz_import(base10, 3, 1, sizeof(n[0]), 0, 0, n);
    gmp_printf("%Zd\n", base10);

    mpz_clear(base10);

    return 0;
}

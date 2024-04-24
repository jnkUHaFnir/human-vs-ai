#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    mpz_t result;
    mpz_init(result);

    for (int i = 0; i < 3; i++) {
        mpz_mul_ui(result, result, 256);  // Multiply result by 256
        mpz_add_ui(result, result, n[i]); // Add the current element of the array
    }

    gmp_printf("%Zd\n", result);

    mpz_clear(result);

    return 0;
}

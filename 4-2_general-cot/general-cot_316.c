#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    
    mpz_t base256_num;
    mpz_init(base256_num);

    // Convert base256 number to base 10 using GMP
    for (int i = 2; i >= 0; i--) {
        mpz_mul_ui(base256_num, base256_num, 256);
        mpz_add_ui(base256_num, base256_num, n[i]);
    }

    // Print the number in base 10
    gmp_printf("Number in base 10: %Zd\n", base256_num);

    mpz_clear(base256_num);
    
    return 0;
}

#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    mpz_t base256_num;
    
    // Initialize a GMP integer
    mpz_init(base256_num);
    
    // Convert the array of unsigned chars into a GMP integer
    for (int i = 0; i < 3; i++) {
        mpz_mul_ui(base256_num, base256_num, 256); // Multiply by 256
        mpz_add_ui(base256_num, base256_num, n[i]); // Add the current element
    }
    
    // Print the GMP integer in base 10
    gmp_printf("Base 10 representation: %Zd\n", base256_num);
    
    // Clean up
    mpz_clear(base256_num);
    
    return 0;
}

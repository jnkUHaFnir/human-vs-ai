#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    mpz_t result;
    mpz_init(result);

    // Initialize a counter variable for the power
    mpz_t power;
    mpz_init(power);
    mpz_set_ui(power, 0);

    for (int i = 0; i < 3; i++) {
        mpz_t base;
        mpz_init(base);
        mpz_set_ui(base, 256);
        
        // Calculate n[i] * 256^i
        mpz_t term;
        mpz_init(term);
        mpz_ui_pow_ui(term, (unsigned int)n[i], i);
        
        // Multiply term by the current power of 256
        mpz_mul(term, term, power);

        // Add the term to the result
        mpz_add(result, result, term);

        // Update the power for the next iteration
        mpz_mul(power, power, base);

        mpz_clear(base);
        mpz_clear(term);
    }

    // Output the result in base 10
    gmp_printf("Result in base 10: %Zd\n", result);

    // Clean up
    mpz_clear(result);
    mpz_clear(power);

    return 0;
}

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    
    mpz_t num;
    mpz_init(num);

    int i;
    for (i = 0; i < 3; i++) {
        mpz_mul_ui(num, num, 256); // Multiply the existing number by 256
        mpz_add_ui(num, num, n[i]); // Add the current byte to the number
    }

    char* num_str = mpz_get_str(NULL, 10, num);
    printf("Number in base 10: %s\n", num_str);

    free(num_str);
    mpz_clear(num);

    return 0;
}

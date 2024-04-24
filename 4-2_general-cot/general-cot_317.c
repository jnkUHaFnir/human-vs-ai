#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3];  // Declare your unsigned char array
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    mpz_t bigNum;   // Declare a GMP big integer variable
    mpz_init(bigNum); // Initialize the big integer

    // Convert the array elements into a big integer
    mpz_import(bigNum, sizeof(n)/sizeof(n[0]), 1, 1, 0, 0, n);

    // Print the big integer in base 10
    gmp_printf("The number in base 10 is: %Zd\n", bigNum);

    // Clean up
    mpz_clear(bigNum);

    return 0;
}

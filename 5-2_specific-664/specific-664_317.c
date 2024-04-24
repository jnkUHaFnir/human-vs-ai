#include <stdio.h>
#include <gmp.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    
    mpz_t num;
    mpz_init(num); // Initialize the multiple precision integer
    
    for(int i = 0; i < 3; i++) {
        mpz_mul_ui(num, num, 256); // Multiply the current result by 256
        mpz_add_ui(num, num, n[i]); // Add the current value in the array
    }
    
    char *num_str = mpz_get_str(NULL, 10, num); // Convert the multiple precision integer to a base 10 string
    printf("%s\n", num_str); // Print the result in base 10
    
    mpz_clear(num); // Free the multiple precision integer
    free(num_str); // Free the allocated string
    
    return 0;
}
gcc -o main main.c -lgmp

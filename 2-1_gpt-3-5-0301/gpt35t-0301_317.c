#include <stdio.h>
#include <gmp.h>

int main()
{
    unsigned char n[3] = {1, 2, 3};
    mpz_t num;
    mpz_init(num); // initialize to zero
    
    for(int i = 2; i >= 0; i--) // iterate backwards through array
    {
        mpz_mul_ui(num, num, 256); // multiply by 256 for next digit
        mpz_add_ui(num, num, n[i]); // add current digit
    }
    
    char* str = mpz_get_str(NULL, 10, num); // convert to base 10 string
    printf("%s\n", str); // print result
    
    return 0;
}
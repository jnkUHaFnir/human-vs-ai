#include <gmp.h>

unsigned char n[3] = { 1, 2, 3 };
mpz_t number;

mpz_init(number);
mpz_import(number, 3, 1, sizeof(n[0]), 0, 0, n); // import from array of unsigned chars
char* str_number = mpz_get_str(NULL, 10, number); // convert to string in base 10
printf("%s\n", str_number); // print out
free(str_number);
mpz_clear(number);
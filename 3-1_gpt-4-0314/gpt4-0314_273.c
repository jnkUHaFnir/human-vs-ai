#include <stdio.h>

int main() {
    char line[] = "+6.590472E-01";
    char sign, exp_sign;
    int whole, fraction, exponent;

    sscanf(line, "%c%1d.%6dE%c%2d", &sign, &whole, &fraction, &exp_sign, &exponent);

    printf("Sign: %c\n", sign);
    printf("Whole: %d\n", whole);
    printf("Fraction: %d\n", fraction);
    printf("Exponent Sign: %c\n", exp_sign);
    printf("Exponent: %d\n", exponent);

    return 0;
}
Sign: +
Whole: 6
Fraction: 590472
Exponent Sign: -
Exponent: 1

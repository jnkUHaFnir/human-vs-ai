#include <stdio.h>

int main() {
    char sign;
    int mantissa_whole;
    int mantissa_decimal;
    int exponent;

    char line[30] = "+6.590472E-01;+2.771043E+07;+";
    sscanf(line, "%c%d.%dE%d;", &sign, &mantissa_whole, &mantissa_decimal, &exponent);

    printf("Sign: %c\n", sign);
    printf("Mantissa whole: %d\n", mantissa_whole);
    printf("Mantissa decimal: %d\n", mantissa_decimal);
    printf("Exponent: %d\n", exponent);

    return 0;
}

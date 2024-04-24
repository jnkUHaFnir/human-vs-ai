#include <stdio.h>

int main()
{
    char line[] = "+6.590472E-01;+2.771043E+07;+";

    // Replace the semicolons with spaces to make it easier to read with fscanf
    for (int i = 0; line[i]; i++) {
        if (line[i] == ';') {
            line[i] = ' ';
        }
    }

    char sign, expSign;
    int integerPart, fractionalPart, exponent;
    sscanf(line, "%c%d.%dE%c%d", &sign, &integerPart, &fractionalPart, &expSign, &exponent);

    printf("Sign: %c\n", sign);
    printf("IntegerPart: %d\n", integerPart);
    printf("FractionalPart: %d\n", fractionalPart);
    printf("E-sign: %c\n", expSign);
    printf("Exponent: %d\n", exponent);

    return 0;
}
Sign: +
IntegerPart: 6
FractionalPart: 590472
E-sign: -
Exponent: 1

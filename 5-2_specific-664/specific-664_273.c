#include <stdio.h>

int main() {
    char line[30];
    char sign, exponent_sign;
    int int_part;
    unsigned int frac_part;
    int exponent;

    // Assuming 'line' contains the string "+6.590472E-01"

    if (sscanf(line, "%c%d.%uE%c%d", &sign, &int_part, &frac_part, &exponent_sign, &exponent) == 5) {
        // Printing the extracted information
        printf("Sign: %c\n", sign);
        printf("Integer part: %d\n", int_part);
        printf("Fraction part: %u\n", frac_part);
        printf("Exponent: %c%d\n", exponent_sign, exponent);
    } else {
        printf("Invalid format.\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    char line[30];
    char sign, before_dot, exponent_sign;
    int between_dot_and_exponent;

    // Assuming 'line' contains the line you provided
    sscanf(line, "%c%1d.%6dE%c%2d;", &sign, &before_dot, &between_dot_and_exponent, &exponent_sign, &ignored);

    // Convert before_dot to a character
    before_dot += '0';

    printf("Sign: %c\n", sign);
    printf("Before the dot: %c\n", before_dot);
    printf("Between the dot and the exponent: %d\n", between_dot_and_exponent);
    printf("Exponent sign: %c\n", exponent_sign);

    return 0;
}

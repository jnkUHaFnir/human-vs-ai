#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int before_dot, fraction;
    int exponent;

    // Assuming 'line' contains the input string "+6.590472E-01"
    sscanf(line, "%c%d.%dE%d", &sign, &before_dot, &fraction, &exponent);

    // Output the extracted values
    printf("Sign: %c\n", sign);
    printf("Before Dot: %d\n", before_dot);
    printf("Fraction: %d\n", fraction);
    printf("Exponent: %d\n", exponent);

    return 0;
}

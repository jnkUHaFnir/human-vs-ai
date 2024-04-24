#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int before_dot;
    int between_dot_and_exp;
    int exponent;

    // Assuming 'line' contains the number "+6.590472E-01"
    sscanf(line, "%c%d.%dE%d", &sign, &before_dot, &between_dot_and_exp, &exponent);

    // Output the extracted information
    printf("Sign: %c\n", sign);
    printf("Number before the dot: %d\n", before_dot);
    printf("Numbers between the dot and the exponent: %d\n", between_dot_and_exp);
    printf("Exponent: %d\n", exponent);

    return 0;
}

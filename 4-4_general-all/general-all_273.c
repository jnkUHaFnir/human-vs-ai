#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int before_dot;
    int between_dot_and_exp;
    char exp_sign;
    int exponent;

    // Assuming line contains the input string
    sscanf(line, "%c%d.%6d%c%d", &sign, &before_dot, &between_dot_and_exp, &exp_sign, &exponent);

    // Output the extracted information
    printf("Sign: %c\n", sign);
    printf("Digits before the dot: %d\n", before_dot);
    printf("Digits between the dot and exponent: %d\n", between_dot_and_exp);
    printf("Exponent sign: %c\n", exp_sign);
    printf("Exponent: %d\n", exponent);

    return 0;
}

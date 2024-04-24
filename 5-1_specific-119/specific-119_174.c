#include <stdio.h>

int main() {
    char sign;
    int before_dot;
    int between_dot_and_exp;
    int exponent;

    char number[20]; // Assuming the maximum length of the number

    // Assuming the number is stored in a variable called 'number' after splitting
    sscanf(number, "%c%d.%dE%d", &sign, &before_dot, &between_dot_and_exp, &exponent);

    printf("Sign: %c\n", sign);
    printf("Before dot: %d\n", before_dot);
    printf("Between dot and exponent: %d\n", between_dot_and_exp);
    printf("Exponent: %d\n", exponent);

    return 0;
}

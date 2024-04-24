#include <stdio.h>

int main() {
    char sign;
    int mantissa_before_dot;
    int mantissa_after_dot;
    int exponent;

    char input[] = "+6.590472E-01";
    
    sscanf(input, "%c%d.%dE%d", &sign, &mantissa_before_dot, &mantissa_after_dot, &exponent);

    printf("Sign: %c\n", sign);
    printf("Mantissa before dot: %d\n", mantissa_before_dot);
    printf("Mantissa after dot: %d\n", mantissa_after_dot);
    printf("Exponent: %d\n", exponent);

    return 0;
}

#include <stdio.h>

int main() {
    char sign;
    int beforeDot;
    int betweenDotAndExp;
    int exponent;

    char num[30] = "+6.590472E-01";
    sscanf(num, "%c%1d.%6dE%3d", &sign, &beforeDot, &betweenDotAndExp, &exponent);

    // Output the extracted information
    printf("Sign: %c\n", sign);
    printf("Before Dot: %d\n", beforeDot);
    printf("Between Dot and Exp: %d\n", betweenDotAndExp);
    printf("Exponent: %d\n", exponent);

    return 0;
}

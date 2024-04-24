#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int integerPart;
    int decimalPart;
    int exponent;

    // Assuming line contains the column "+6.590472E-01"
    sscanf(line, "%c%d.%dE%d", &sign, &integerPart, &decimalPart, &exponent);

    printf("Sign: %c\n", sign);
    printf("Integer part: %d\n", integerPart);
    printf("Decimal part: %d\n", decimalPart);
    printf("Exponent: %d\n", exponent);

    return 0;
}

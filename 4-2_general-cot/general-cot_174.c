#include <stdio.h>

int main() {
    char sign;
    int integerPart, decimalPart, exponent;

    FILE *file = fopen("yourfile.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Assuming char line[30] contains the line "+6.590472E-01;+2.771043E+07;+"
    char line[30] = "+6.590472E-01;+2.771043E+07;+";

    sscanf(line, "%c%d.%dE%d", &sign, &integerPart, &decimalPart, &exponent);

    printf("Sign: %c\n", sign);
    printf("Integer part: %d\n", integerPart);
    printf("Decimal part: %d\n", decimalPart);
    printf("Exponent: %d\n", exponent);

    fclose(file);

    return 0;
}

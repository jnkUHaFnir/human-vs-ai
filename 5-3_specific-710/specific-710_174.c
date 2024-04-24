#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char sign;
    int before_dot;
    int between_dot_and_exp;
    int exponent;

    // Assuming each line has the format: +x.yyyyyyE+zz;
    while (fscanf(file, "%c%d.%dE%d;", &sign, &before_dot, &between_dot_and_exp, &exponent) == 4) {
        // Process the extracted values
        printf("Sign: %c\n", sign);
        printf("Before dot: %d\n", before_dot);
        printf("Between dot and exponent: %d\n", between_dot_and_exp);
        printf("Exponent: %d\n", exponent);
    }

    fclose(file);
    return 0;
}

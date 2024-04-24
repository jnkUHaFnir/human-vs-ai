#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int before_dot;
    int after_dot;
    int exponent;

    // Assuming 'line' contains the string to be parsed

    // Using the precise format pattern for the given input format
    sscanf(line, "%c%d.%dE%d;", &sign, &before_dot, &after_dot, &exponent);

    // Output the extracted values
    printf("Sign: %c\n", sign);
    printf("Number before dot: %d\n", before_dot);
    printf("Numbers after dot: %d\n", after_dot);
    printf("Exponent: %d\n", exponent);

    return 0;
}

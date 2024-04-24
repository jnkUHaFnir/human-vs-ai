#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int before_dot;
    int after_dot;
    int exponent;

    // Assuming 'line' contains the string "+6.590472E-01" to parse
    if (sscanf(line, "%c%1d.%6dE%3d", &sign, &before_dot, &after_dot, &exponent) == 4) {
        // Process the parsed values
        printf("Sign: %c\n", sign);
        printf("Before dot: %d\n", before_dot);
        printf("After dot: %d\n", after_dot);
        printf("Exponent: %d\n", exponent);
    } else {
        printf("Error parsing the line.\n");
    }

    return 0;
}

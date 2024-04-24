#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int before_dot, after_dot, exponent;

    // Assuming you have the line stored in 'line'
    sscanf(line, "%c%d.%dE%d;", &sign, &before_dot, &after_dot, &exponent);

    printf("Sign: %c\n", sign);
    printf("Before dot: %d\n", before_dot);
    printf("After dot: %d\n", after_dot);
    printf("Exponent: %d\n", exponent);

    return 0;
}

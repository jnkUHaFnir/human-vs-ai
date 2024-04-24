#include <stdio.h>

int main() {
    char sign;
    int beforeDot;
    int afterDot;
    int exponent;

    char line[30];
    // Assuming line contains the string "+6.590472E-01"
    // For demonstration, you can replace this with your file reading logic

    sscanf(line, "%c%d.%dE%d", &sign, &beforeDot, &afterDot, &exponent);

    printf("Sign: %c\n", sign);
    printf("Before Dot: %d\n", beforeDot);
    printf("After Dot: %d\n", afterDot);
    printf("Exponent: %d\n", exponent);

    return 0;
}

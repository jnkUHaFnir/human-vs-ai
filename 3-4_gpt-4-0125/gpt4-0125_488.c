#include <stdio.h>

int main() {
    char floatStr[] = "+6.590472E-01";
    char sign;
    int beforeDot;
    int afterDot;
    int exponent;
    
    // Parse the string manually. Assumes `floatStr` has the format "+X.YYYYYYE+ZZ"
    // %c captures the sign
    // %d captures the number before the dot
    // %d captures the numbers between the dot and the 'E'
    // %d captures the exponent
    int ret = sscanf(floatStr, "%c%d.%dE%d", &sign, &beforeDot, &afterDot, &exponent);
    
    if (ret == 4) { // Successfully parsed all parts
        printf("Sign: %c\n", sign);
        printf("Before dot: %d\n", beforeDot);
        printf("After dot: %d\n", afterDot);
        printf("Exponent: %d\n", exponent);
    } else {
        printf("Parsing Error\n");
    }

    return 0;
}

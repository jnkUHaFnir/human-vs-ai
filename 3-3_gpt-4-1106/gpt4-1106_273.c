#include <stdio.h>

int main() {
    char line[30] = "+6.590472E-01;+2.771043E+07;+";
    char sign;
    int integer_part;
    char fractional_part[7]; // +1 for null-terminator
    int exponent;
    
    // Assuming we're reading from the string, for file use fscanf(file, ...)
    // This assumes there's always 6 digits between the dot and 'E'
    // %+c captures the '+' or '-' sign
    // %1d captures the single digit before the dot
    // %6c captures the six characters between the dot and the 'E'
    // %d captures the integer exponent part
    sscanf(line, "%c%1d.%6cE%d", &sign, &integer_part, fractional_part, &exponent);
    fractional_part[6] = '\0'; // Null-terminate the string
    
    // Now you can work with the sign, integer_part, fractional_part, and exponent separately
    printf("Sign: %c\n", sign);
    printf("Integer part: %d\n", integer_part);
    printf("Fractional part: %s\n", fractional_part);
    printf("Exponent: %d\n", exponent);
    
    return 0;
}

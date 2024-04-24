#include <stdio.h>
#include <string.h>

int main() {
    // Example input
    const char *input = "+6.590472E-01";
    
    // Variables to store components
    char sign = '+';
    int integerPart = 0;
    int decimalPart = 0;
    int exponent = 0;
    
    // Read the sign
    if (input[0] == '-') {
        sign = '-';
    }
    
    // Parse the integer part
    sscanf(input, "%c%d", &sign, &integerPart);
    
    // Find the position of the 'E' or 'e' to split the mantissa and the exponent
    char *ePos = strchr(input, 'E') ? strchr(input, 'E') : strchr(input, 'e');
    
    if (ePos) {
        // Copy the decimal part into a temporary buffer
        size_t decimalLength = ePos - input - 2; // -2 to avoid the sign and integer part
        char decimalBuffer[10]; // Adjust the size as necessary
        strncpy(decimalBuffer, input + 2, decimalLength); // +2 to skip the sign and integer part
        decimalBuffer[decimalLength] = '\0'; // Null-terminate the string
        
        // Parse the decimal part
        sscanf(decimalBuffer, "%d", &decimalPart);
        
        // Parse the exponent
        sscanf(ePos, "E%d", &exponent);
    }
    
    // Output
    printf("Sign: %c\n", sign);
    printf("Integer part: %d\n", integerPart);
    printf("Decimal part: %d\n", decimalPart);
    printf("Exponent: %d\n", exponent);
    
    return 0;
}
sscanf(ePos + 1, "%d", &exponent); // +1 to skip 'E' or 'e'

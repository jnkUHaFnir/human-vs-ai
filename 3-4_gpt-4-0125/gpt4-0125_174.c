char line[] = "+6.590472E-01";
char sign;
int integerPart;
int exponent;
char fractionalStr[7]; // Enough to hold the fractional part, assuming fixed size here for simplicity.

// First, grab the sign and the entire number.
// Then, we'll decompose the number further.
float number;
sscanf(line, "%c%fE%d", &sign, &number, &exponent);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parseScientificNotation(const char* sn, char* sign, int* integerPart, char* fractionalPart, int* exponent) {
    const char* ePointer = strchr(sn, 'E'); // Find the 'E' to separate the base from the exponent.
    
    if (ePointer != NULL) {
        *sign = *sn; // First character is the sign.
        sscanf(sn+1, "%d.%[0-9]E%d", integerPart, fractionalPart, exponent);
    }
}

int main() {
    char line[] = "+6.590472E-01";
    char sign;
    int integerPart;
    char fractionalPart[10] = {0}; // Be sure this is big enough or handle dynamically.
    int exponent;

    parseScientificNotation(line, &sign, &integerPart, fractionalPart, &exponent);

    printf("Sign: %c\nInteger Part: %d\nFractional Part: %s\nExponent: %d\n", sign, integerPart, fractionalPart, exponent);

    return 0;
}

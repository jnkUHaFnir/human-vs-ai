#include <stdio.h>
#include <string.h>

void printLargeNumber(unsigned char *n, size_t size) {
    char result[256] = {0}; // Array to hold the decimal representation, adjust the size accordingly.
    int i, j, k;
    unsigned char remainder;
    
    do {
        remainder = 0;
        // Go through each byte
        for (i = 0; i < size; i++) {
            unsigned int value = (unsigned int)remainder * 256 + n[i];
            remainder = value % 10;
            n[i] = value / 10;
        }
        // Prepend the result with the new digit
        memmove(result + 1, result, strlen(result) + 1);
        result[0] = remainder + '0'; // Convert digit to character
        // Check if the unsigned char array is all zeroes
        for (k = 0, j = 0; j < size && !n[j]; j++);
    } while (j < size); // Keep going until all bytes are zero
    
    printf("%s\n", result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    printLargeNumber(n, sizeof(n)/sizeof(n[0]));
    
    return 0;
}

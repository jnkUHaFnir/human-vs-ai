#include <stdio.h>

// Function to print an unsigned char array as a base 10 number.
void printBase10(unsigned char *arr, size_t len) {
    // Output array for decimal digits, 3 decimal digits per base-256 digit is conservative.
    char output[3 * len + 1]; // Plus one for the terminating null byte.
    size_t out_len = 0;

    // Process the input number until it's zero.
    int nonzero;
    do {
        int remainder = 0;
        nonzero = 0;
        // Divide the number by 10, from the highest significant byte to the least.
        for (size_t i = 0; i < len; ++i) {
            int digit = (remainder << 8) + arr[i];
            arr[i] = digit / 10;
            remainder = digit % 10;
            if (arr[i] != 0) {
                nonzero = 1;
            }
        }
        // Store the remainder as the next digit in the output in reverse order.
        output[out_len++] = remainder + '0';
    } while (nonzero);

    // The digits are in reverse order, so we print them from the end to the beginning.
    for (size_t i = out_len; i > 0; --i) {
        putchar(output[i - 1]);
    }
}

int main(void) {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printBase10(n, sizeof(n));
    
    return 0;
}

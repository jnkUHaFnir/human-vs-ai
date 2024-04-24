#include <stdio.h>

void printBigNumberInBase10(unsigned char *bytes, size_t length) {
    // Allocate a string to hold the base-10 representation; for simplicity, allocate more than needed.
    char base10[256] = {0}; // Adjust size as needed, or dynamically compute the necessary size.
    int i, j, temp, carry;

    for (i = length - 1; i >= 0; --i) { // Process bytes from most significant to least significant.
        carry = bytes[i];
        for (j = 0; j < 256 && carry; ++j) { // Process each digit in the base-10 string.
            temp = (base10[j] - '0') * 256 + carry; // Multiply the current digit by 256 and add the carry from byte processing.
            base10[j] = (temp % 10) + '0'; // Calculate the new digit.
            carry = temp / 10; // Calculate the new carry.
        }
    }

    // Find the starting point of the number to skip leading zeros.
    for (i = 255; i >= 0 && base10[i] == 0; --i);

    // If all digits are zero, print 0.
    if (i == -1) {
        printf("0\n");
        return;
    }

    // Print the digits from the first non-zero till the end.
    for (; i >= 0; --i) {
        putchar(base10[i] ? base10[i] : '0');
    }
    putchar('\n');
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    printBigNumberInBase10(n, 3);
    return 0;
}

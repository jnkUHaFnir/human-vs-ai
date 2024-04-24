#include <stdio.h>
#include <string.h>

#define SIZE 256  // Max number of decimal digits

void printBase10(unsigned char *bytes, size_t numBytes) {
    unsigned char temp[SIZE] = {0};
    char output[SIZE] = {0};  // Buffer for the decimal representation
    int i, j, k, quotient, remainder;

    // Copy the input bytes into a temporary array
    for (i = 0; i < numBytes; ++i) {
        temp[i] = bytes[i];
    }

    for (i = 0; i < SIZE - 1; ++i) {
        remainder = 0;
        for (j = (int)numBytes - 1; j >= 0; --j) {
            // Simulate division of temp by 10
            quotient = (remainder * 256 + temp[j]) / 10;
            remainder = (remainder * 256 + temp[j]) % 10;
            temp[j] = quotient;  // Store the quotient back in place
        }
        output[i] = remainder + '0';  // Convert to ASCII and store in output
        // Early termination check: if all bytes are zero, we're done
        for (k = 0; k < numBytes; ++k) {
            if (temp[k] != 0) {
                break;
            }
        }
        if (k == numBytes) {
            break;  // All bytes are zero; we're done
        }
    }

    // Print in reverse order to get the correct representation
    int start = 0;
    while (output[start] == '0') {  // Skip any leading zeros
        start++;
    }
    if (start == i && i > 0) {  // Manage all zeros case
        start--;
    }
    for (j = i - 1; j >= start; --j) {
        putchar(output[j]);
    }
}

int main() {
    unsigned char n[3] = {3, 2, 1};  // Array is in big-endian order
    printBase10(n, 3);
    return 0;
}

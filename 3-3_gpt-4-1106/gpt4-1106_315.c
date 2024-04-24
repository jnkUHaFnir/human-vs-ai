#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 256

void printLargeNumber(unsigned char *n, size_t length) {
    // Allocate a string assuming each byte contributes up to 3 decimal digits
    char *buffer = calloc(length * 3 + 1, sizeof(char));
    if (!buffer) {
        perror("calloc failed");
        return;
    }
    buffer[0] = '0'; // Start with "0" as the string representation

    for (size_t i = 0; i < length; ++i) {
        int carry = n[i];
        for (char *p = buffer; *p != '\0' || carry; ++p) {
            if (*p == '\0') {
                *p = '0';
            }
            int newVal = (*p - '0') * BASE + carry;
            *p = (newVal % 10) + '0';
            carry = newVal / 10;
        }
    }

    // Find the length of the result
    size_t resultLen = strlen(buffer);

    // Remove leading zeros
    size_t startIndex = 0;
    while (startIndex < resultLen - 1 && buffer[startIndex] == '0') {
        startIndex++;
    }

    // Print the result
    printf("%s\n", &buffer[startIndex]);

    // Free the buffer when done
    free(buffer);
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    printLargeNumber(n, sizeof(n));
    return 0;
}

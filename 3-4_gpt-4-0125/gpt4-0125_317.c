#include <stdio.h>
#include <string.h>

// Function to multiply a very large number represented as a string by an integer
void multiplyBy256(char* num, int length) {
    int carry = 0;
    for (int i = 0; i < length; i++) {
        int digit = (num[i] - '0') * 256 + carry;
        num[i] = digit % 10 + '0';
        carry = digit / 10;
    }
    while (carry > 0) {
        num[length++] = (carry % 10) + '0';
        carry /= 10;
    }
    num[length] = '\0';
}

// Function to add an unsigned char to the very large number represented as a string
void addUnsignedChar(char* num, unsigned char value) {
    int carry = value;
    for (int i = 0; carry > 0; i++) {
        int digit = (num[i] - '0') + carry;
        num[i] = (digit % 10) + '0';
        carry = digit / 10;
    }
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    char result[1024] = {'0', '\0'}; // Result initialized to 0

    for (int i = sizeof(n)/sizeof(n[0]) - 1; i >= 0; i--) {
        multiplyBy256(result, strlen(result)); // Multiply current result by 256
        addUnsignedChar(result, n[i]); // Add the current byte to the result
        // Since our add and multiply operations work in reverse (for simplicity), we reverse the string each time
        strrev(result);
    }

    // The string 'result' now contains the number in base 10, but in reverse
    printf("Number in base 10: ");
    for (int i = strlen(result) - 1; i >= 0; i--) {
        putchar(result[i]);
    }

    return 0;
}

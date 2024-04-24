#include <stdio.h>
#include <string.h>

void printLargeNumberInBase10(unsigned char *n, size_t len) {
    char result[1024] = {0}; // Large enough buffer for result
    int resultLen = 0;

    // Assume the input number is little-endian for simplicity
    unsigned long long num = 0;
    for (int i = len - 1; i >= 0; i--) {
        num = (num << 8) + n[i];
    }

    // Convert to base 10
    do {
        int digit = num % 10;
        result[resultLen++] = '0' + digit;
        num /= 10;
    } while (num != 0);

    // Print in reverse order
    for(int i = resultLen - 1; i >= 0; i--) {
        putchar(result[i]);
    }
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    printLargeNumberInBase10(n, 3);
    return 0;
}

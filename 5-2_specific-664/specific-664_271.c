#include <stdio.h>
#include <string.h>

void printLargeNumber(unsigned char* array, size_t size) {
    // Allocate memory to store the result (maximum size needed is 3 * size)
    char result[3 * size + 1]; // +1 for null terminator
    size_t resultIndex = 0;
    size_t i;

    // Initialize result array with null terminator
    result[resultIndex] = '\0';

    // Perform base conversion
    for (i = size; i > 0; i--) {
        unsigned int carry = 0;
        for (size_t j = 0; j < strlen(result); j++) {
            unsigned int tmp = (result[j] - '0') * 256 + carry;
            result[j] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        while (carry > 0) {
            result[resultIndex++] = carry % 10 + '0';
            carry /= 10;
        }
    }

    // Print the result in reversed order
    for (int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printLargeNumber(n, 3);

    return 0;
}

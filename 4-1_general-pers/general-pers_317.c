#include <stdio.h>

#define ARRAY_SIZE 3 // Change this to 100 for a 100-byte array

void multiply(unsigned char *result, int factor) {
    int carry = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int num = result[i] * factor + carry;
        result[i] = num % 10; // Store the digit in base 10
        carry = num / 10;
    }
}

void printNumberInBase10(unsigned char *arr) {
    unsigned char result[ARRAY_SIZE] = {0};

    for (int i = 0; i < ARRAY_SIZE; i++) {
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);
        multiply(result, 256);

        multiply(result, 16);

        multiply(result, 2);

        multiply(result, 1);

        multiply(result, 1);
    }

    // Print the result
    int leadingZeros = ARRAY_SIZE - 1;
    while (result[leadingZeros] == 0 && leadingZeros > 0) {
        leadingZeros--;
    }

    for (int i = leadingZeros; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[ARRAY_SIZE] = {1, 2, 3}; // Initialize your array here
    printNumberInBase10(n);

    return 0;
}

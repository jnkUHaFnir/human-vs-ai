#include <stdio.h>

// Function to multiply a number represented as an array of digits by an integer
void multiply_and_add(unsigned char* result, int result_len, int mult, unsigned char add) {
    int carry = 0;
    for (int i = 0; i < result_len; i++) {
        int prod = result[i] * mult + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned char result[100] = {0}; // You might need to increase the size depending on your input size
    int result_len = sizeof(result) / sizeof(result[0]);
    result[0] = 1;

    for (int i = 0; i < 3; i++) {
        // result = result * 256 + n[i]
        multiply_and_add(result, result_len, 256, n[i]);
    }

    // Print the result in reverse order
    int first_non_zero = result_len - 1;
    while (result[first_non_zero] == 0) {
        first_non_zero--;
    }

    for (int i = first_non_zero; i >= 0; i--) {
        printf("%d", result[i]);
    }

    printf("\n");
    return 0;
}

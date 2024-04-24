#include <stdio.h>

void printDecimal(unsigned char n[], int size) {
    // Initialize an array to store the result (maximum size required is 3 * (current array size) + 1 for carry overflow)
    int result[size * 3 + 1];
    int resultSize = 1;
    result[0] = 0;

    // Iterate through the array from right to left
    for (int i = size - 1; i >= 0; i--) {
        // Multiply the current result by 256
        for (int j = 0; j < resultSize; j++) {
            result[j] *= 256;
        }
        
        // Add the current byte value and propagate any carry
        for (int j = 0; j < resultSize || result[j] > 0; j++) {
            result[j] += n[i];
            if (result[j] > 9) { // Perform carry operation if required
                result[j + 1] += result[j] / 10;
                result[j] %= 10;
            }
            if (result[j] > 0 && j == resultSize) { // Update result size if necessary
                resultSize++;
            }
        }
    }

    // Print the final result
    printf("Decimal representation: ");
    for (int i = resultSize - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    int size = sizeof(n) / sizeof(n[0]);
    
    printDecimal(n, size);

    return 0;
}

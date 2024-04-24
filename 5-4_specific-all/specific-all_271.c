#include <stdio.h>

// Function to print a number represented by an array of unsigned chars in base 10
void printNumberInBase10(unsigned char arr[], int size) {
    // Initialize variables
    int base = 256;
    int result[400]; // Assuming the maximum possible output length
    int i, j;
    
    // Initialize result array with 0
    for (i = 0; i < 400; i++) {
        result[i] = 0;
    }
    
    // Iterate through each byte in the array
    for (i = size - 1; i >= 0; i--) {
        int carry = 0;
        
        // Multiply each digit in result by 256 and add the current byte
        for (j = 0; j < 400; j++) {
            int product = result[j] * base + arr[i] + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
    }
    
    // Find the most significant digit in the result
    int msd = 399;
    while (msd > 0 && result[msd] == 0)
        msd--;
    
    // Print the number in base 10
    for (i = msd; i >= 0; i--) {
        printf("%d", result[i]);
    }
    
    printf("\n");
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    printNumberInBase10(n, 3);  // Output: 197
    return 0;
}

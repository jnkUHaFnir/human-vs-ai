#include <stdio.h>

void printLargeNumber(unsigned char* arr, size_t size) {
    // Initialize result array with 0
    unsigned char result[250] = {0};
    
    // Iterate over each digit in the input array
    for (size_t i = 0; i < size; i++) {
        unsigned char carry = 0;
        
        // Multiply each digit in the result array by 256 and add the current digit from input array
        for (size_t j = 0; j < 250; j++) {
            unsigned short product = result[j] * 256 + arr[i] + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
    }
    
    // Find the position of the most significant digit in the result
    size_t msdPos = 249;
    while (msdPos > 0 && result[msdPos] == 0) {
        msdPos--;
    }
    
    // Print the result in reverse order
    printf("Result: ");
    for (size_t i = msdPos + 1; i > 0; i--) {
        printf("%d", result[i - 1]);
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

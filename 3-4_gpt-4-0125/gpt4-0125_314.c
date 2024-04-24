#include <stdio.h>

void multiplyBy256(unsigned int *arr, int length) {
    unsigned long carry = 0;
    for (int i = 0; i < length; i++) {
        unsigned long temp = arr[i] * 256UL + carry;
        arr[i] = temp % 10;
        carry = temp / 10;
    }
}

void addValue(unsigned int *arr, unsigned char value, int length) {
    arr[0] += value; 
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] >= 10) {
            arr[i+1] += arr[i] / 10;
            arr[i] %= 10;
        } else {
            break;
        }
    }
}

void printArray(unsigned int *arr, int length) {
    int startIndex = length - 1;
    while (startIndex > 0 && arr[startIndex] == 0) startIndex--;
    
    for (int i = startIndex; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[100] = {0}; // Your big number representation in base 256
    // Example setup for a smaller number
    n[97] = 1;
    n[98] = 2;
    n[99] = 3;
    
    unsigned int result[300] = {0}; // Adjust size according to needs
    
    for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++) {
        multiplyBy256(result, sizeof(result) / sizeof(result[0]));
        addValue(result, n[i], sizeof(result) / sizeof(result[0]));
    }
    
    printArray(result, sizeof(result) / sizeof(result[0]));
    
    return 0;
}

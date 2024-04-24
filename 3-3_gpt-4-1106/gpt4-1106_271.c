#include <stdio.h>

// Utility function to divide the number by 10 and return the remainder
int divideBy10(unsigned char* number, int size) {
    int remainder = 0;
    for (int i = size - 1; i >= 0; --i) {
        int value = (remainder << 8) + number[i];
        number[i] = value / 10;
        remainder = value % 10;
    }
    return remainder;
}

// Function to print an unsigned char array as a base 10 number
void printLargeNumberBase10(unsigned char* number, int size) {
    // Copy the original number so we don't modify it
    unsigned char *temp = (unsigned char*)malloc(size);
    for (int i = 0; i < size; i++) {
        temp[i] = number[i];
    }

    // Check if the number is zero
    int isZero = 1;
    for (int i = 0; i < size; i++) {
        if (temp[i] != 0) {
            isZero = 0;
            break;
        }
    }
    if (isZero) {
        printf("0");
        free(temp);
        return;
    }

    // Buffer to store digits in reverse order
    char digits[256 * size]; // Enough to store decimal digits of the byte array
    int digitIndex = 0;

    // Keep dividing by 10 and storing remainder until the number is zero
    while (1) {
        int isZero = 1;
        for (int i = 0; i < size; i++) {
            if (temp[i] != 0) {
                isZero = 0;
                break;
            }
        }
        if (isZero) break;

        digits[digitIndex++] = divideBy10(temp, size) + '0'; // Convert to ASCII and store
    }

    // Print the digits in reverse order
    for (int i = digitIndex - 1; i >= 0; --i) {
        putchar(digits[i]);
    }

    free(temp);
}

int main() {
    unsigned char n[3];
    n[0] = 3;
    n[1] = 2;
    n[2] = 1;
  
    printLargeNumberBase10(n, sizeof(n));
    printf("\n");

    return 0;
}

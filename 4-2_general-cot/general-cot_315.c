#include <stdio.h>
#include <string.h>

// Function to convert an array of unsigned chars to a decimal string
void arrayToDecimalString(unsigned char* arr, int size, char* output) {
    // Initialize a buffer to store the decimal string
    char buffer[size * 4 + 1]; // Each byte can be up to 3 digits in decimal, +1 for null terminator
    int i, j = 0;

    // Loop through each byte and convert it to decimal
    for (i = size - 1; i >= 0; i--) {
        j += sprintf(&buffer[j], "%03d", arr[i]); // Assuming each byte will be represented by up to 3 decimal digits
    }

    buffer[j] = '\0'; // Add null terminator

    // Reverse the buffer to get the correct order
    for (i = 0; i < j; i++) {
        output[i] = buffer[j-1-i];
    }
    output[j] = '\0'; // Add null terminator to the output string
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    char decimalString[3 * 4 + 1]; // Maximum 3 characters per byte

    arrayToDecimalString(n, 3, decimalString);

    // Print the decimal string
    printf("%s\n", decimalString);

    return 0;
}

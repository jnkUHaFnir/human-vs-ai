#include <stdio.h>
#include <string.h>

void doubleToString(double value, char* output, int maxLength) {
    // Use snprintf to format the double value into scientific notation with fixed number of digits
    snprintf(output, maxLength, "%.15e", value);
    
    // Remove trailing zeros and adjust the string length if necessary
    int length = strlen(output);
    while (length > 0 && output[length - 1] == '0') {
        output[length - 1] = '\0';
        length--;
    }
    
    // Check if the last character is a decimal point, remove it if necessary
    if (output[length - 1] == '.') {
        output[length - 1] = '\0';
        length--;
    }
    
    // Check if the string is longer than the maximum length
    if (length >= maxLength) {
        // Truncate the string to fit within the maximum length
        output[maxLength - 1] = '\0';
    }
}

int main() {
    double value = 3.14159265358979323846;
    char output[17]; // Limited to 16 bytes (+1 for null terminator)
    
    doubleToString(value, output, sizeof(output));
    
    printf("%s\n", output);
    
    return 0;
}

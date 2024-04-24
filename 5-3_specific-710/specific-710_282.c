#include <stdio.h>

void double_to_decimal_string(double value, char* buffer, size_t buffer_size) {
    // Format the double value with scientific notation and write it to a buffer
    snprintf(buffer, buffer_size, "%.15e", value);

    // Adjust the buffer to limit the number of significant digits to 16
    size_t length = strlen(buffer);
    char* exponent = strchr(buffer, 'e');
    
    // Check if scientific notation is used and the position of the exponent in the buffer
    if (exponent != NULL) {
        int decimals = 16 - (length - (exponent - buffer));
        
        // Adjust decimals to adhere to 16 significant digits limit
        if (decimals > 0) {
            snprintf(buffer, buffer_size, "%.*e", decimals, value);
        }
    }
}

int main() {
    char output[17]; // 16 characters for the string + 1 for null terminator
    double input = 1234567890.123456789;

    double_to_decimal_string(input, output, sizeof(output));
    printf("Converted value: %s\n", output);

    return 0;
}

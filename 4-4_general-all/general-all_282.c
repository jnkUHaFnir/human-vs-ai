#include <stdio.h>
#include <string.h>

void doubleToLimitedString(double value, char* output, size_t maxLength) {
    snprintf(output, maxLength, "%.15e", value); // Format with 15 significant digits

    // Remove trailing zeros and decimal point
    size_t len = strlen(output);
    while (len > 0 && (output[len - 1] == '0' || output[len - 1] == '.')) {
        output[--len] = '\0';
    }

    if (len >= maxLength) {
        // Truncate if the output exceeds maxLength
        output[maxLength - 1] = '\0';
    }
}

int main() {
    double num = 123456789.987654321; // Example double value
    char str[17]; // 16 bytes maximum + 1 for null terminator

    doubleToLimitedString(num, str, sizeof(str));
    printf("Converted string: %s\n", str);

    return 0;
}

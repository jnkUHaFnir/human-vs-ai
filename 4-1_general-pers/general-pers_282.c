#include <stdio.h>

void doubleToDecimalString(double value, char* buffer, int bufferSize) {
    int written = snprintf(buffer, bufferSize, "%.16e", value);

    // Check if the buffer was large enough to hold the formatted string
    if (written >= bufferSize) {
        // Buffer was not large enough, now use an alternate method or truncate
        snprintf(buffer, bufferSize, "NaN"); // For example, handle overflow with a default value
    }
}

int main() {
    double value = 3.141592653589793;
    char buffer[17]; // 16 bytes for the decimal string + 1 for null terminator

    doubleToDecimalString(value, buffer, sizeof(buffer));
    
    printf("Decimal String: %s\n", buffer);

    return 0;
}

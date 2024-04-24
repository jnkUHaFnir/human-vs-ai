#include <stdio.h>

// Helper function to format the double value within the limits
void formatLimitedDecimalString(char* buffer, size_t bufferSize, double value) {
    snprintf(buffer, bufferSize, "%.15e", value); // Limiting to 15 significant digits
    char* dotPos = strchr(buffer, '.');
    
    if (dotPos != NULL) {
        size_t maxLength = (dotPos - buffer) + 15; // Max length including decimal point
        if (strlen(buffer) > maxLength) {
            buffer[maxLength] = '\0'; // Truncate after 15 digits if necessary
        }
    }
}

int main() {
    double value = 123.456789012345; // Example double value
    char buffer[17]; // 16 bytes for Decimal String with 1 byte for null terminator
    
    formatLimitedDecimalString(buffer, sizeof(buffer), value);
    
    printf("Formatted Limited Decimal String: %s\n", buffer);
    
    return 0;
}

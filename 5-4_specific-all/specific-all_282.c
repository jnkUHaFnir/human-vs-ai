#include <stdio.h>

void convertDoubleToString(double value, char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "%.14g", value); // Using 14 here to leave room for padding
    buffer[bufferSize - 1] = '\0'; // Null-terminate the string
}

int main() {
    double myDouble = 12345.6789123456;
    char output[17]; // 16 bytes for the value and 1 byte for null terminator

    convertDoubleToString(myDouble, output, sizeof(output));

    printf("Converted double value: %s\n", output);

    return 0;
}

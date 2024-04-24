#include <stdio.h>

void doubleToStringLimited(double value, char* output) {
    sprintf(output, "%.15e", value); // Format the double with 15 significant digits
    int len = strlen(output);
    while (len > 1 && (output[len-1] == '0' || output[len-1] == '.')) {
        output[--len] = '\0'; // Remove trailing '0's and '.' if any
    }
}

int main() {
    double value = 1234567890.1234567;
    char str[17]; // 16 bytes for value + 1 byte for null terminator

    doubleToStringLimited(value, str);
    printf("Result: %s\n", str);
    
    return 0;
}

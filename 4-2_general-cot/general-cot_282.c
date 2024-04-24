#include <stdio.h>

void double_to_str(double d, char *str, size_t maxLength) {
    // Writing the double with necessary precision
    int len = snprintf(str, maxLength, "%.15e", d);

    // Truncating the string if it exceeds the maximum length
    if (len >= maxLength) {
        str[maxLength - 1] = '\0';
    }
}

double str_to_double(const char *str) {
    double d;
    sscanf(str, "%le", &d);
    return d;
}

int main() {
    double originalValue = 123456.789012345;
    char str[17]; // 16 bytes plus null terminator

    // Conversion from double to limited size string
    double_to_str(originalValue, str, sizeof(str));

    // Printing the limited size string
    printf("Limited size string: %s\n", str);

    // Conversion from limited size string back to double
    double restoredValue = str_to_double(str);

    // Printing the restored double value
    printf("Restored double value: %.15e\n", restoredValue);

    return 0;
}

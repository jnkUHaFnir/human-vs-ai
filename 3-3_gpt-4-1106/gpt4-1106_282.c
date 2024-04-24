#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> // for DBL_DIG

#define MAX_STR_SIZE 16

int format_double_to_dicom_string(double value, char *buffer, size_t buffer_size) {
    // Start with 9 significant digits for '%g'
    int length = snprintf(buffer, buffer_size, "%.9g", value);
    
    if (length < 0 || length >= buffer_size) {
        // Not enough space, revert to scientific notation with reduced precision
        // Adapting precision based on the buffer_size - 7 accounts for '-','e','+/-','3 \0'
        int prec = buffer_size - 7; // e.g., for '-1.23e-123\0' we require 7 extra characters
        if (prec < 1) return -1; // Not enough space even for the smallest scientific notation
        length = snprintf(buffer, buffer_size, "%.*e", prec, value);
        
        // Check if snprintf failed or if the buffer wasn't large enough
        if (length < 0 || length >= buffer_size) {
            return -1;
        }
    }

    // Add memory for null-terminator if it's missing (snprintf does not count it)
    if (length == buffer_size - 1) {
        return -1;
    }
    
    return 0;
}

int main() {
    double values[] = {
        0.123456789, 
        123456789.0, 
        1.234567e+200, 
        1.234567e-200, 
        123.456, 
        -12345.6789, 
        DBL_MAX, 
        DBL_MIN,
    };
    char buffer[MAX_STR_SIZE];
    int size = sizeof(values) / sizeof(double);

    for(int i = 0; i < size; ++i) {
        if (format_double_to_dicom_string(values[i], buffer, sizeof(buffer)) != 0) {
            printf("Failed to format '%.17g'\n", values[i]);
            continue;
        }
        printf("'%g' -> '%s'\n", values[i], buffer);
    }

    return 0;
}

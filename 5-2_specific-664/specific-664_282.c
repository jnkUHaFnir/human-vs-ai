#include <stdio.h>
#include <stdlib.h>

// Function to convert a double to a string with limited size while maintaining precision
char* double_to_limited_decimal_string(double d, int precision) {
    char* str = (char*)malloc(17); // allocate 17 characters (16 significant digits + null terminator)
    if (str == NULL) {
        return NULL; // memory allocation failed
    }

    snprintf(str, 17, "%.*e", precision - 1, d); // format the double with specified precision

    return str;
}

int main() {
    double num = 1234.56789;
    
    // Convert the double to a limited size string with precision 16
    char* str = double_to_limited_decimal_string(num, 16);
    
    if (str != NULL) {
        printf("Limited size string with precision 16: %s\n", str);
        free(str); // free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

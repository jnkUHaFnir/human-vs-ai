#include <stdio.h>
#include <ctype.h>

int hexStringToInt(const char *input, size_t offset) {
    if (input == NULL || offset < 0 || offset > strlen(input) - 4) {
        return -1; // Invalid input or offset out of bounds
    }

    // Initialize the result
    int result = 0;

    // Iterate through the four characters starting from the given offset
    for (int i = 0; i < 4; i++) {
        char c = toupper(input[offset + i]); // Convert to uppercase for case insensitivity
        if (!isxdigit(c)) {
            return -1; // Non-hex character detected
        }
        
        int hexValue = isdigit(c) ? c - '0' : c - 'A' + 10; // Convert hex char to decimal
        result = (result << 4) | hexValue; // Shift and add the hex value
    }

    return result;
}

int main() {
    const char *input = "foo10a4bar";
    size_t offset = 3;
    
    int result = hexStringToInt(input, offset);
    
    if (result == -1) {
        printf("Invalid input or offset\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

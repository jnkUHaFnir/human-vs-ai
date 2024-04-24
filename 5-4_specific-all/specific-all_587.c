#include <stdio.h>
#include <ctype.h>

int hexCharToInt(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10;
    }
}

int parseHexToInt(const char *input, int offset) {
    int result = 0;
    
    for (int i = 0; i < 4; i++) {
        char hexChar = input[offset + i];
        
        if (!isxdigit(hexChar)) {
            // Invalid hex character detected
            return -1;
        }
        
        result = (result << 4) | hexCharToInt(hexChar);
    }
    
    return result;
}

int main() {
    const char *input = "foo10a4bar";
    int offset = 3;
    
    int result = parseHexToInt(input, offset);
    
    if (result != -1) {
        printf("Result: %d\n", result);
    } else {
        printf("Invalid input detected.\n");
    }
    
    return 0;
}

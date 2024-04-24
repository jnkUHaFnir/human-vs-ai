#include <stdio.h>
#include <ctype.h>

int hexCharsToInt(const char* str, int offset) {
    int result = 0;
    
    for (int i = offset; i < offset + 4; i++) {
        char c = tolower(str[i]);
        if (!isxdigit(c)) {
            // Invalid input detected
            return -1;
        }
        
        result = (result << 4) | (isdigit(c) ? c - '0' : c - 'a' + 10);
    }
    
    return result;
}

int main() {
    const char* input = "foo10a4bar";
    int offset = 3;
    
    int result = hexCharsToInt(input, offset);
    
    if (result == -1) {
        printf("Invalid input detected.\n");
    } else {
        printf("Result: %d\n", result);
    }
    
    return 0;
}

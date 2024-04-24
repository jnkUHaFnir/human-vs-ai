#include <stdio.h>

int parseHexToInt(const char* str, int offset) {
    int value = 0;
    
    for (int i = offset; i < offset + 4; i++) {
        char ch = str[i];
        int hexDigit;
        
        if (ch >= '0' && ch <= '9') {
            hexDigit = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            hexDigit = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            hexDigit = ch - 'a' + 10;
        } else {
            printf("Invalid input at offset %d\n", offset);
            return -1;
        }
        
        value = (value << 4) | hexDigit;
    }
    
    return value;
}

int main() {
    const char* str = "foo10a4bar";
    int offset = 3;
    
    int hexValue = parseHexToInt(str, offset);
    printf("%d\n", hexValue);
    
    return 0;
}

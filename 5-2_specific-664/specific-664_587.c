#include <stdio.h>
#include <ctype.h>

int hexToInt(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10;
    }
}

int parseHexAtOffset(const char *input, int offset) {
    int result = 0;
    for (int i = offset; i < offset + 4; i++) {
        char c = input[i];
        if (!isxdigit(c)) {
            return -1; // Invalid input detected
        }
        result = result * 16 + hexToInt(c);
    }
    return result;
}

int main() {
    const char *input = "foo10a4bar";
    int offset = 3;
    int parsedValue = parseHexAtOffset(input, offset);
    
    if (parsedValue == -1) {
        printf("Invalid input detected.\n");
    } else {
        printf("Parsed value: %d\n", parsedValue);
    }
    
    return 0;
}

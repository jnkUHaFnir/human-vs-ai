#include <stdio.h>
#include <ctype.h>

int hexCharToInt(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'F') return 10 + c - 'A';
    if(c >= 'a' && c <= 'f') return 10 + c - 'a';
    return -1; // Invalid hex character
}

int parseHexSubstring(const char *str, size_t offset, unsigned int *outValue) {
    if (!str || offset + 4 > strlen(str)) return -1; // Invalid input or position offset
    
    *outValue = 0;
    for (int i = 0; i < 4; ++i) {
        int val = hexCharToInt(str[offset + i]);
        if (val < 0) return -1; // Invalid hex character detected

        *outValue = (*outValue << 4) | val;
    }
    return 0; // Success
}

int main() {
    const char* example = "foo10a4bar";
    unsigned int value;
    int status = parseHexSubstring(example, 3, &value);
    
    if (status == 0) {
        printf("Parsed value: %u\n", value);
    } else {
        printf("Error parsing\n");
    }
    
    return 0;
}

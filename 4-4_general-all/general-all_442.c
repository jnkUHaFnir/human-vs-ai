#include <stdio.h>

void processTokens(const char* data, int length) {
    const char* start = data + 8; // Start from byte 8
    const char* end = start; // Initialize end pointer
    
    while (end < data + length) {
        if (*end == '\0') { // Found the NUL char
            // Print the string
            printf("Token: %.*s\n", (int)(end - start), start);
            
            start = end + 1; // Move start pointer to next character
        }
        end++;
    }
    
    // Print the last token if there is no trailing NUL char at the end
    if (start < end) {
        printf("Token: %.*s\n", (int)(end - start), start);
    }
}

int main() {
    char data[] = {0, 0, 0, 0, 0, 0, 0, 0, 'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'};
    int length = sizeof(data) / sizeof(data[0]);
    
    processTokens(data, length);
    
    return 0;
}

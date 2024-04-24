#include <stdio.h>

void process_tokens(const char *buffer, size_t length) {
    const char *end = buffer + length; // Pointer to the end of the buffer
    const char *start = buffer + 8;   // Start processing from byte 8
    const char *current;

    while (start < end) {
        current = start; // Pointer to the beginning of the current token
        // Find the next NUL character
        while (start < end && *start) {
            start++;
        }
        // At this point, 'start' is either at end of buffer or pointing at a NUL character
        printf("Token: %.*s\n", (int)(start - current), current);
        // Move past the NUL character to the start of the next token
        start++;
    }
}

int main() {
    const char buffer[] = {
        0x00, 0x00, 0x00, 0x01, // 32-bit int
        0x00, 0x00, 0x00, 0x02, // 32-bit int
        'f', 'o', 'o',  '\0',   // Token
        'b', 'a', 'r',  '\0',   // Token
        'b', 'a', 'z',  '\0',   // Token
        '\0'                    // Final NUL (empty string)
    };
    size_t length = sizeof(buffer);

    process_tokens(buffer, length);

    return 0;
}

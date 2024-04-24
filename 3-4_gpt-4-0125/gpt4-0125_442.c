#include <stdio.h>

void processBuffer(char *buffer, size_t bufferSize) {
    // Assuming the first 8 bytes are not part of the string data
    char *current = buffer + 8;
    char *end = buffer + bufferSize;
    
    while (current < end) {
        printf("%s\n", current);
        
        // Advance `current` to the end of the current string, plus one character
        // for the null terminator. This positions `current` at the start of the
        // next string, ready for the next iteration.
        while (current < end && *current) {
            current++;
        }
        
        // Skip the null terminator to get to the start of the next string
        // Check to ensure we don't go past the end of the buffer
        if (current < end) {
            current++;
        }
    }
}

int main() {
    // Example buffer with two 32-bit integers followed by strings separated by NUL.
    // For demonstration, the content is hardcoded here.
    // Normally, this would come from a network recv command.
    // Note: '\0' is used for string termination and as a separator.
    char buffer[] = {0,0,0,1, 0,0,0,2, 'H','e','l','l','o','\0','W','o','r','l','d','\0','T','e','s','t','\0'};
    size_t bufferSize = sizeof(buffer) / sizeof(buffer[0]);

    processBuffer(buffer, bufferSize);

    return 0;
}

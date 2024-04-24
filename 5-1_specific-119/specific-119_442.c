#include <stdio.h>

int main() {
    char buffer[100]; // Assuming a buffer size of 100
    // Assume buffer has been filled with received data
    int buffer_length = 100; // Actual length of the char array
    
    int offset = 8; // Start from byte 8
    while (offset < buffer_length) {
        int string_length = 0;
        
        // Calculate the length of the current string until the next '\0'
        for (int i = offset; i < buffer_length; i++) {
            if (buffer[i] == '\0') {
                break;
            }
            string_length++;
        }
        
        // Process the token (e.g., print it)
        printf("Token: %.*s\n", string_length, &buffer[offset]);
        
        // Move the offset to the start of the next string for the next iteration
        offset += string_length + 1; // Add 1 to skip over the '\0' character
    }
    
    return 0;
}

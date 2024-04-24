#include <stdio.h>

// Function to convert an integer to a binary string
const char* int_to_binary(int n) {
    static char binary[9]; // 8 bits + NULL terminator
    
    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = ((n >> i) & 1) ? '1' : '0';
    }
    binary[8] = '\0'; // Null-terminate the string
    
    return binary;
}

int main() {
    char a = 5;
    
    // Use the function to get the binary representation of 'a' and print it
    printf("Binary representation of a = %s\n", int_to_binary(a));

    return 0;
}

#include <stdio.h>

// Function to convert an integer to binary string
const char *int_to_bin(int n) {
    static char bin_str[9]; // 8 bits for binary + 1 for null terminator
    int i;
    for (i = 7; i >= 0; i--) {
        bin_str[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    bin_str[8] = '\0'; // Null terminator
    return bin_str;
}

int main() {
    char a = 5;
    printf("Binary representation of a = %s\n", int_to_bin(a));
    return 0;
}

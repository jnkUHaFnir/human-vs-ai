#include <stdio.h>

// Converts an integer value to a formatted string such as "*RV200#".
// The `prefix` is "*RV" or "*FV", and `buf` is the output buffer.
void formatString(char *buf, size_t buf_size, const char *prefix, int value) {
    // Use snprintf to directly create the string in the buffer
    // Including the integer formatting and the suffix '#'.
    snprintf(buf, buf_size, "%s%03d#", prefix, value);
}

int main() {
    char result1[10];
    char result2[10];

    // Assuming these functions return the integer values you want to format:
    unsigned short BUF = GetWord(0); // Replace 0 with the actual memory address or allocation
    unsigned short BUF1 = GetWord(0); // Same as above

    formatString(result1, sizeof(result1), "*FV", BUF);
    formatString(result2, sizeof(result2), "*RV", BUF1);

    // Display String result1 and result2
    printf("%s\n", result1); // Should print *FV200# (if BUF is 200)
    printf("%s\n", result2); // Should print *RV200# (if BUF1 is 200)

    return 0;
}

// Dummy implementation to emulate behavior of GetWord (remove or replace with the actual function)
unsigned short GetWord(int address) {
    // Replace this with the actual code that reads the word from memory.
    return 200;
}

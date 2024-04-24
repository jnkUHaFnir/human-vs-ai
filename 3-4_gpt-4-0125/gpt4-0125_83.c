#include <stdio.h>

// Simulated function signature for demonstration purposes
unsigned short GetWord(const char* address, int offset) {
    // Assuming this function returns the desired value from the memory
    // For demonstration, return a fixed value (e.g., 200)
    return 200;
}

int main() {
    unsigned short BUF = GetWord("@FrontVIB@", 0);
    unsigned short BUF1 = GetWord("@RearVIB@", 0);

    // Instead of the pre-defined arrays for parts of the final string,
    // directly use the snprintf to format the entire string

    // Allocate enough space for the strings including the value and terminators
    char stringFV[10];
    char stringRV[10];

    // Format the strings directly, without needing a separate function
    snprintf(stringFV, sizeof(stringFV), "*FV%03u#", BUF);
    snprintf(stringRV, sizeof(stringRV), "*RV%03u#", BUF1);

    // Display the constructed strings
    printf("StringFV: %s\n", stringFV);
    printf("StringRV: %s\n", stringRV);

    return 0;
}

#include <stdio.h>

// Mock GetWord function definition for demonstration
// In practice, replace with the actual function definition
unsigned short GetWord(char* addressAlias, int addressOffset) {
    // Implementation that fetches from memory. Here's a dummy return for demonstration.
    return 200; // Example: Always returns 200 for demonstration
}

int main() {
    // Assuming 200 is just an example and actual value comes from memory
    unsigned short BUF = GetWord("@FrontVIB@", 0);
    unsigned short BUF1 = GetWord("@RearVIB@", 0);
    
    char String4H1[20]; // Increase buffer size to avoid overflow
    char String4H3[20]; // Increase buffer size to avoid overflow
    
    // Use snprintf directly to achieve the desired output
    // Demonstrates a simpler and more direct approach
    snprintf(String4H1, sizeof(String4H1), "*FV%03u#", BUF);
    snprintf(String4H3, sizeof(String4H3), "*RV%03u#", BUF1);
    
    // Display the results
    printf("%s\n%s\n", String4H1, String4H3);

    return 0;
}

#include <stdio.h>
#include <stdint.h>

int main() {
    // Input MAC address string
    const char* macStr = "00:0d:3f:cd:02:5f";

    // Array to hold the parsed MAC address bytes
    uint8_t macArray[6];

    // Parse the string into the array using sscanf
    // The %hhx format specifier is used for reading hexadecimal numbers into unsigned char (or uint8_t)
    int parsedItems = sscanf(macStr, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", 
                             &macArray[0], &macArray[1], &macArray[2], 
                             &macArray[3], &macArray[4], &macArray[5]);

    // Check if all items were parsed successfully
    if(parsedItems == 6) {
        printf("MAC address parsed successfully:\n");
        for(int i = 0; i < 6; i++) {
            // Print each byte in hexadecimal format
            printf("%02x", macArray[i]);
            if(i < 5) printf(":"); // Print colon separator for all but the last byte
        }
        printf("\n");
    } else {
        printf("Error: Could not parse MAC address correctly.\n");
    }

    return 0;
}

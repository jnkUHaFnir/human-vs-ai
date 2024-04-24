#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAC_ADDRESS_LENGTH 17  // Length of a MAC address string including ':' characters

void macStringToIntArray(const char *macStr, uint8_t *intArray) {
    if (strlen(macStr) != MAC_ADDRESS_LENGTH - 1) {
        // Handle invalid MAC address string length
        printf("Invalid MAC address format\n");
        return;
    }

    char *token;
    char *saveptr;
    int index = 0;
    int value;

    token = strtok(strdup(macStr), ":");
    while (token != NULL) {
        value = (int)strtol(token, NULL, 16);
        if (value < 0 || value > 255) {
            // Handle invalid hex value
            printf("Invalid hex value in MAC address\n");
            return;
        }

        intArray[index++] = (uint8_t)value;
        token = strtok(NULL, ":");
    }

    if (index != 6) {
        // Handle incomplete MAC address
        printf("Incomplete MAC address\n");
        return;
    }
}

int main() {
    const char *macAddress = "00:0d:3f:cd:02:5f";
    uint8_t intArray[6];

    macStringToIntArray(macAddress, intArray);

    // Print the converted integer array
    for (int i = 0; i < 6; i++) {
        printf("intArray[%d] = 0x%02X\n", i, intArray[i]);
    }

    return 0;
}

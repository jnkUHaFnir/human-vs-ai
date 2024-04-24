#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void stringToMacArray(const char *macAddress, uint8_t *array) {
    int i;
    char *token = strtok((char *)macAddress, ":");
    for (i = 0; token != NULL; i++) {
        array[i] = (uint8_t)strtol(token, NULL, 16);
        token = strtok(NULL, ":");
    }
}

int main() {
    const char *macAddressString = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    stringToMacArray(macAddressString, array);

    // Print the array to verify the conversion
    for (int i = 0; i < 6; i++) {
        printf("0x%02x ", array[i]);
    }
    printf("\n");

    return 0;
}

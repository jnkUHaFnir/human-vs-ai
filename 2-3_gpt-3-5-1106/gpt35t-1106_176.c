#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {
    char macAddressString[] = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    char *token = strtok(macAddressString, ":");
    int i = 0;

    while (token != NULL) {
        array[i++] = (uint8_t)strtol(token, NULL, 16);
        token = strtok(NULL, ":");
    }

    printf("MAC address in integer array: {0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x}\n", 
           array[0], array[1], array[2], array[3], array[4], array[5]);

    return 0;
}

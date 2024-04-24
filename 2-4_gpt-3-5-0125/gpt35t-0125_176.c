#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void macAddressStringToIntArray(char *macAddressString, uint8_t *macAddressIntArray) {
    char *token = strtok(macAddressString, ":");
    int i = 0;
    while(token) {
        macAddressIntArray[i++] = (uint8_t)strtol(token, NULL, 16);
        token = strtok(NULL, ":");
    }
}

int main() {
    char macAddressString[] = "00:0d:3f:cd:02:5f";
    uint8_t macAddressIntArray[6];

    macAddressStringToIntArray(macAddressString, macAddressIntArray);

    printf("MAC Address Array: {");
    for(int i = 0; i < 6; i++) {
        printf("0x%02x", macAddressIntArray[i]);
        if(i < 5) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}

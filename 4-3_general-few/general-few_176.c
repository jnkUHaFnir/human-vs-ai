#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {
    char *mac_address = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    char *token = strtok(mac_address, ":");
    int i = 0;
    while (token != NULL) {
        array[i] = (uint8_t)strtol(token, NULL, 16);
        token = strtok(NULL, ":");
        i++;
    }

    // Print the converted array
    for (i = 0; i < 6; i++) {
        printf("0x%02x ", array[i]);
    }
    printf("\n");

    return 0;
}

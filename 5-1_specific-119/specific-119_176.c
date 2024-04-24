#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char mac_address[] = "00:0d:3f:cd:02:5f";
    uint8_t array[6];
    int i = 0;

    char *token = strtok(mac_address, ":");
    while (token != NULL) {
        array[i++] = (uint8_t)strtol(token, NULL, 16);
        token = strtok(NULL, ":");
    }
    
    // Print the converted array
    printf("Converted array: {");
    for (i = 0; i < 6; i++) {
        printf("0x%02x", array[i]);
        if (i < 5) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}

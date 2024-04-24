#include <stdio.h>
#include <stdint.h>
#include <string.h>

void macStringToIntArray(const char *mac_str, uint8_t *array) {
    int i;
    for (i = 0; i < 6; i++) {
        sscanf(mac_str + 3*i, "%2hhx", &array[i]);  // Parse 2 characters as hexadecimal
    }
}

int main() {
    const char *mac_str = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    macStringToIntArray(mac_str, array);

    // Print the array for verification
    printf("Converted array: ");
    for (int i = 0; i < 6; i++) {
        printf("0x%02x ", array[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdint.h>

int main() {
    const char *mac_address = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    sscanf(mac_address, "%2hhx:%2hhx:%2hhx:%2hhx:%2hhx:%2hhx",
           &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);

    // Print the converted array values
    for (int i = 0; i < 6; i++) {
        printf("array[%d] = 0x%02x\n", i, array[i]);
    }

    return 0;
}

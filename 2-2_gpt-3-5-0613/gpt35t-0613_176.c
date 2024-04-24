#include <stdio.h>
#include <stdint.h>

int main() {
    const char* macAddress = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    sscanf(macAddress, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
        &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);

    printf("Converted: ");
    for (int i = 0; i < 6; i++) {
        printf("%02x ", array[i]);
    }
    printf("\n");

    return 0;
}
Converted: 00 0d 3f cd 02 5f

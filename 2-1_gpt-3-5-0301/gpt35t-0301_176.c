#include <stdio.h>
#include <stdint.h>

int main() {
    char mac_str[] = "00:0d:3f:cd:02:5f";
    uint8_t mac_array[6];
    int n = sscanf(mac_str, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
                   &mac_array[0], &mac_array[1], &mac_array[2],
                   &mac_array[3], &mac_array[4], &mac_array[5]);
    if (n != 6) {
        printf("Error: invalid MAC address\n");
        return 1;
    }
    // test output
    for (int i = 0; i < 6; i++) {
        printf("%02x ", mac_array[i]);
    }
    printf("\n");
    return 0;
}

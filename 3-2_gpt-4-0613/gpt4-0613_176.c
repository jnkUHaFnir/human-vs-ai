#include <stdio.h>

int main() {
    const char* mac_address = "00:0d:3f:cd:02:5f";
    unsigned int array[6];

    sscanf(mac_address, "%02x:%02x:%02x:%02x:%02x:%02x", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);

    for (int i = 0; i < 6; i++) {
        printf("array[%d] = 0x%02x\n", i, array[i]);
    }

    return 0;
}
array[0] = 0x00
array[1] = 0x0d
array[2] = 0x3f
array[3] = 0xcd
array[4] = 0x02
array[5] = 0x5f

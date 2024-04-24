#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void mac_str_to_array(const char* mac_str, uint8_t* array) {
    char *ptr = (char *)mac_str;
    int i = 0;
    
    while (*ptr && i < 6) {
        array[i] = (uint8_t)strtol(ptr, &ptr, 16);
        ptr++; // skip ':'
        i++;
    }
}

int main() {
    const char mac_str[] = "00:0d:3f:cd:02:5f";
    uint8_t array[6];

    mac_str_to_array(mac_str, array);

    // Print the converted array for verification
    for (int i = 0; i < 6; i++) {
        printf("array[%d] = %#04x\n", i, array[i]);
    }

    return 0;
}

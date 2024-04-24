#include <stdio.h>
#include <stdint.h>

void mac_string_to_array(const char* mac_str, uint8_t array[6]) {
    // Make sure the input string is of the correct length
    if (strlen(mac_str) != 17) {
        // Handle error, maybe return an error code or exit
        return;
    }

    // Use sscanf to parse the string and convert to integers
    sscanf(mac_str, "%2hhx:%2hhx:%2hhx:%2hhx:%2hhx:%2hhx",
            &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
}

int main() {
    const char* mac_address = "00:0d:3f:cd:02:5f";
    uint8_t mac_array[6];

    mac_string_to_array(mac_address, mac_array);

    // Print the converted array
    printf("Converted MAC address array: { ");
    for (int i = 0; i < 6; i++) {
        printf("0x%02x ", mac_array[i]);
    }
    printf("}\n");

    return 0;
}

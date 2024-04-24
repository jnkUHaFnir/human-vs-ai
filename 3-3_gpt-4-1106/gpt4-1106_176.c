#include <stdio.h>
#include <stdint.h>

int mac_string_to_array(const char *mac_str, uint8_t *mac_array) {
    // Ensure we have a valid input
    if (mac_str == NULL || mac_array == NULL) {
        return -1;
    }

    // Try to convert the MAC address string to bytes
    int bytes_read = sscanf(mac_str, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
                            &mac_array[0], &mac_array[1], &mac_array[2],
                            &mac_array[3], &mac_array[4], &mac_array[5]);

    // Check if all 6 bytes were successfully read
    if (bytes_read == 6) {
        return 0; // success
    }

    // If all 6 bytes weren't read, return an error
    return -1;
}

int main() {
    const char *mac_address = "00:0d:3f:cd:02:5f";
    uint8_t mac_array[6];

    // Convert the MAC address string to an array
    if (mac_string_to_array(mac_address, mac_array) == 0) {
        // Conversion was successful, print the result
        printf("The MAC address array is: ");
        for (int i = 0; i < 6; i++) {
            printf("0x%02x", mac_array[i]);
            if (i < 5) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        // Conversion failed
        fprintf(stderr, "Error converting MAC address string to array.\n");
        return 1;
    }

    return 0;
}

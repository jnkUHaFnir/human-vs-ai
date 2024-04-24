#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    char* endptr;
    long val = strtol(str, &endptr, 10);  // Using strtol to handle negative numbers

    if (*endptr != '\0' || val < 0 || val > UINT16_MAX) {
        return false; // Conversion failed or out of range
    }

    *res = (uint16_t)val;
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        return 1;
    }

    uint16_t port;
    if (!str_to_uint16(argv[1], &port)) {
        fprintf(stderr, "Invalid port number\n");
        return 1;
    }

    printf("Port number: %" PRIu16 "\n", port);

    return 0;
}

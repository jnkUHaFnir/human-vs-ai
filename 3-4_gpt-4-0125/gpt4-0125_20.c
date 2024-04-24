#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 * Ensures that the input is within the valid range for uint16_t.
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    long val;
    char* endPtr;

    errno = 0; // To distinguish success/failure after call
    val = strtol(str, &endPtr, 10);

    // Check for conversion errors (no digits found, or not a null-terminated string after number)
    if (endPtr == str || *endPtr != '\0')
        return false;

    // Check for valid range for uint16_t and overflow/underflow
    if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (val > UINT16_MAX) || (val < 0))
        return false;

    *res = (uint16_t)val;
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    uint16_t port;
    if (str_to_uint16(argv[1], &port)) {
        printf("Converted port: %u\n", port);
    } else {
        fprintf(stderr, "Failed to convert '%s' to uint16_t\n", argv[1]);
        return 1;
    }

    return 0;
}

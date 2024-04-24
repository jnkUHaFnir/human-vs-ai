#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    char *endptr;
    long conv = strtol(str, &endptr, 10);

    // Check for conversion errors
    if ((errno == ERANGE && (conv == LONG_MAX || conv == LONG_MIN)) ||
        (errno != 0 && conv == 0)) {
        return false; // Conversion error
    }

    // Check for out of range values
    if (conv < 0 || conv > UINT16_MAX || *endptr != '\0') {
        return false; // Out of range value or unconverted characters
    }

    *res = (uint16_t)conv;
    return true;
}

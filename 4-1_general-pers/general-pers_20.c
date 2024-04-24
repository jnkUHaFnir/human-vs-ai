#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/*
 * Converts a string to an unsigned integer and stores the result in "res".
 * Returns true if conversion is successful, false otherwise.
 */
bool str_to_uint(const char* str, uintmax_t* res) {
    if (str == NULL || *str == '\0') {
        return false; // Empty string
    }

    char* endptr;
    errno = 0;
    uintmax_t result = strtoumax(str, &endptr, 10);

    if (errno == ERANGE || result > UINTMAX_MAX) {
        return false; // Overflow
    }

    if (*endptr != '\0') {
        return false; // Not a valid integer
    }

    *res = result;
    return true;
}

/*
 * Converts a string to a uint16_t and stores the result in "res".
 * Returns true if conversion is successful and within the uint16_t range, false otherwise.
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    uintmax_t uint;
    if (!str_to_uint(str, &uint)) {
        return false;
    }

    if (uint > UINT16_MAX) {
        return false; // Exceeds uint16_t range
    }

    *res = (uint16_t)uint;
    return true;
}

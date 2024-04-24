#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 *
 * Returns true on success, false on failure.
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    char* endptr;
    long val = strtol(str, &endptr, 10);

    // Check for errors during conversion
    if ((errno == ERANGE) || (val < 0) || (val > UINT16_MAX) || (*endptr != '\0')) {
        return false;
    }

    *res = (uint16_t)val;
    return true;
}

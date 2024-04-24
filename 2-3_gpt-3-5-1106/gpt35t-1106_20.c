#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

// Converts a string to an uint16_t and stores the result in "res".
bool str_to_uint16(const char* str, uint16_t* res) {
    char* endptr;
    errno = 0;
    unsigned long val = strtoul(str, &endptr, 10);

    if (errno != 0 || *endptr != '\0' || val > UINT16_MAX) {
        return false; // Error: invalid input or overflow
    }

    *res = (uint16_t)val;
    return true;
}

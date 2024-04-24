#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    char* endptr;
    errno = 0;
    uintmax_t result = strtoumax(str, &endptr, 10);
    
    if (errno == ERANGE || result > UINT16_MAX || *endptr != '\0' || result > INT_MAX) {
        return false;
    }

    *res = (uint16_t) result;
    return true;
}

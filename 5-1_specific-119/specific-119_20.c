#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    if (str == NULL) {
        return false;
    }

    char* endptr;
    errno = 0;
    unsigned long val = strtoul(str, &endptr, 10);

    if (val > UINT16_MAX || *endptr != '\0' || (errno == ERANGE && val == ULONG_MAX)) {
        return false;
    }

    *res = (uint16_t)val;
    return true;
}

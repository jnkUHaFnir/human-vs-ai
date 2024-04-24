#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Converts a string to an uint16_t and stores the result in "res".
 */
bool str_to_uint16(const char* str, uint16_t* res) {
    if (str[0] == '-')
        return false;
    char* first_wrong_character;
    errno = 0; // Set errno to 0 before calling strtoul

    unsigned long uint = strtoul(str, &first_wrong_character, 10);

    if ((*str != '\0') && (*first_wrong_character != '\0'))
        return false; // Not everything has been converted
    if ((uint == 0) && (str == first_wrong_character))
        return false; // Nothing to convert
    if ((uint == ULONG_MAX) && (errno == ERANGE))
        return false; // Overflow
    if (uint > UINT16_MAX)
        return false;

    *res = (uint16_t)uint;
    return true;
}

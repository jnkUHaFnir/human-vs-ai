#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool str_to_uint16(const char* str, uint16_t* res) {
    unsigned long temp;
    if (sscanf(str, "%lu", &temp) != 1) {
        return false; // Failed to read an integer
    }

    if (temp > UINT16_MAX) {
        return false; // Value exceeds UINT16_MAX
    }

    *res = (uint16_t)temp;
    return true;
}

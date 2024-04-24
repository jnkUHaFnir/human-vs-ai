#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

bool str_to_uint16(const char* str, uint16_t* res) {
    char* end_ptr;
    unsigned long int value = strtoul(str, &end_ptr, 10);

    if (*end_ptr != '\0' || value > UINT16_MAX) {
        return false;
    }

    *res = (uint16_t)value;
    return true;
}

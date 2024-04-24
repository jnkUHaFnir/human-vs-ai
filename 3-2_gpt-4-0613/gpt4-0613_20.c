#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

bool str_to_uint16(const char* str, uint16_t* res) {
    if (str[0] == '-')
        return false;
    char *end;
    errno = 0;
    unsigned long val = strtoul(str, &end, 10);
    if (errno == ERANGE || *end != '\0' || val > 65535)
        return false;
    *res = (uint16_t)val;
    return true;
}


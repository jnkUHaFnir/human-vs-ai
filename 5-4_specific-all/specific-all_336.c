#include <stdint.h>

uint32_t getIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;

    // Handle invalid input
    if (p == NULL) {
        return 0;
    }

    while (*p) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        } else if (*p >= '0' && *p <= '9') {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        } else {
            // Handle invalid character in input
            return 0;
        }
        p++;
    }

    // Handle last part of the IP address
    dwIP = (dwIP << 8) | dwIP_Part;

    return dwIP;
}

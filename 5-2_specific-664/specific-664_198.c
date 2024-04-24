#include <stdint.h>

uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0;
    uint32_t dwIP_Part = 0;

    // Input validation - assuming valid IPv4 format without error checking
    if (p == NULL) {
        return 0; // Return an invalid IP address
    }

    while (*p) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        } else {
            dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (*p - '0'); // Equivalent to dwIP_Part * 10 + (*p - '0')
        }
        p++;
    }

    dwIP = (dwIP << 8) | dwIP_Part; // Combine the last part of the IP address

    return dwIP;
}

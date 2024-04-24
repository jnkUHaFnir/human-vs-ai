#include <stdint.h>

uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0, dwIP_Part = 0;

    while (*p != '\0') {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        } else {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        }
        p++;
    }
    
    // Handle the last octet of the IP address
    dwIP = (dwIP << 8) | dwIP_Part;

    return dwIP;
}

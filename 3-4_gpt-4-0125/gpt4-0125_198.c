#include <stdint.h>

uint32_t GetIPOptimized(const char *p) {
    uint32_t dwIP = 0, dwIP_Part = 0;

    for (int i = 0; i < 4; ++i) { // We know there are exactly 3 dots in a valid IPv4 address.
        while (*p != '.' && *p != '\0') {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
            ++p;
        }
        dwIP = (dwIP << 8) | dwIP_Part;
        dwIP_Part = 0;
        
        if (*p != '\0') ++p; // Skip the dot, but if it's the end, do not advance to prevent overrun.
    }

    return dwIP;
}

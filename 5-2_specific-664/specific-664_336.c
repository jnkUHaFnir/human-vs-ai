#include <stdint.h>

uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0;
    while (*p != '.') {
        dwIP = (dwIP * 10) + (*p - '0');
        ++p;
    }
    dwIP = (dwIP << 8);

    dwIP += (uint32_t)(p[1]-'0') << 16;
    dwIP += (uint32_t)(p[2]-'0') << 24;

    return dwIP;
}

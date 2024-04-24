#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0;
    while (*p != '.') {
        dwIP = dwIP * 10 + (*p - '0');
        ++p;
    }
    ++p;
    dwIP <<= 8;
    
    while (*p != '.') {
        dwIP = dwIP + (*p - '0');
        ++p;
    }
    ++p;
    dwIP <<= 8;
    
    while (*p != '.') {
        dwIP = dwIP + (*p - '0');
        ++p;
    }
    ++p;

    dwIP <<= 8;
    dwIP = dwIP + atoi(p);

    return dwIP;
}

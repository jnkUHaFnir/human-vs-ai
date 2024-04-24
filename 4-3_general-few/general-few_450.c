#include <stdint.h>

uint32_t GetIP(const char* p) {
    uint32_t dwIP = 0;
    int part = 0;

    while (*p) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | part;
            part = 0;
        } else {
            part = part * 10 + (*p - '0');
        }
        p++;
    }

    dwIP = (dwIP << 8) | part; // Handle the last part of the IP address
    return dwIP;
}

#include <stdint.h>

uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0;
    
    while(*p) {
        char c = *p;
        if (c == '.') {
            dwIP = (dwIP << 8);
        } else {
            dwIP = dwIP * 10 + (c - '0');
        }
        p++;
    }
    
    return dwIP;
}

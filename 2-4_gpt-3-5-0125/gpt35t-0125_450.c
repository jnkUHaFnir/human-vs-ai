#include <stdint.h>

uint32_t GetIP(const char* p) {
    uint32_t dwIP = 0, dwIP_Part = 0;

    // Check for end of string
    if (*p == 0)
        return 0;

    while (true) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            p++;
        } else if (*p == 0) {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        } else {
            dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (*p - '0'); // faster than * 10
            p++;
        }
    }
    return dwIP;
}

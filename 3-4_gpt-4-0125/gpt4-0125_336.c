#include <stdint.h>

uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0, dwIP_Part = 0;

    while (true) {
        char c = *p;
        if (c == '\0') {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        } else if (c == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        } else {
            dwIP_Part = ((dwIP_Part << 3) + (dwIP_Part << 1)) + (c - '0');
        }
        p++;
    }

    return dwIP;
}

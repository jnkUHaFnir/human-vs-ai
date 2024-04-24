#include <stdint.h>

uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0, dwIP_Part = 0;
    while (true) {
        if (p[0] == 0) {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        if (p[0] == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            p++;
        }
        dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (p[0] - '0'); // optimized for multiplication by 10
        p++;
    }
    return dwIP;
}
#include <stdint.h>

uint32_t GetIP(const char *p) {
    static const int digit_values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    uint32_t dwIP = 0, dwIP_Part = 0;
    while (true) {
        if (p[0] == 0) {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        if (p[0] == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            p++;
        }
        dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + digit_values[p[0] - '0'];
        p++;
    }
    return dwIP;
}

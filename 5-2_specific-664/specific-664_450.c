#include <stdio.h>

#define IS_DIGIT(c) ((c >= '0') && (c <= '9'))

UINT32 GetIP(const char *p) {
    UINT32 dwIP = 0, dwIP_Part = 0;
    
    while (*p) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        } else if (IS_DIGIT(*p)) {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        } else {
            // Handle invalid characters if needed
            // For example, return an error code or value
        }
        p++;
    }
    
    // Left shift by 8 bits for the last part
    dwIP = (dwIP << 8) | dwIP_Part;
    
    return dwIP;
}

int main() {
    const char *ip = "192.168.1.1";
    UINT32 result = GetIP(ip);
    printf("IP address as UINT32: %u\n", result);
    return 0;
}

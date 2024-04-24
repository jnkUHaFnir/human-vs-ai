#include <stdint.h>

// Function to convert a string representation of an IPv4 address to a UINT32 value
uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0, dwIP_Part = 0;

    // Loop through the input string
    while (*p) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        } else if (*p >= '0' && *p <= '9') {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        } else {
            // Handle invalid input, for example, non-numeric characters
            return 0;
        }
        
        p++;
    }

    // Handle the last part of the IP address
    if (*p == '\0') {
        dwIP = (dwIP << 8) | dwIP_Part;
    }

    return dwIP;
}

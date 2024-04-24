#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;
    
    // Input validation
    if (p == NULL) {
        return 0; // Or handle the error as necessary
    }

    while (*p != '\0')
    {
        // Ensure that the character is a valid digit or a dot
        if ((*p < '0' || *p > '9') && *p != '.') {
            return 0; // Or handle the error as necessary
        }

        // Skip dots
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;                     
            dwIP_Part = 0;
            p++;
            continue;
        }

        // Calculate the IP part
        dwIP_Part = dwIP_Part * 10 + (*p - '0');
        p++;
    }

    // Handle the last IP part
    dwIP = (dwIP << 8) | dwIP_Part;

    return dwIP;
}

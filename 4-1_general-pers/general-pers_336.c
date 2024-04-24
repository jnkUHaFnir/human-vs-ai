#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;
    int partCount = 0;
    
    while (*p)
    {
        if (*p < '0' || *p > '9')
        {
            // Invalid character in input
            return 0;
        }

        dwIP_Part = dwIP_Part * 10 + (*p - '0');

        if (dwIP_Part > 255)
        {
            // Invalid IPv4 part
            return 0;
        }

        if (*(p + 1) == '.' || *(p + 1) == '\0')
        {
            // Check if current part is too large or if there are too many parts
            if (partCount >= 4 || dwIP > 0xFFFFFF)
            {
                // Invalid IPv4 address format
                return 0;
            }

            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            partCount++;
        }
        
        p++;
    }
    
    // Check if we have exactly 4 parts
    if (partCount != 4)
    {
        // Invalid IPv4 address format
        return 0;
    }

    return dwIP;
}

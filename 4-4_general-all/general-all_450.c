#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0;
    uint32_t dwIP_Part = 0;
    
    // Pre-calculate the values for '0' to '9' to avoid repeated calculations
    static const uint32_t digitValues[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    while (true)
    {
        char c = *p;
        
        if (c == 0)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        else if (c == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            p++;
            continue;
        }
        
        dwIP_Part = dwIP_Part * 10 + digitValues[c - '0'];

        p++;
    }

    return dwIP;
}

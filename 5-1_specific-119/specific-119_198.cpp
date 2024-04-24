#include <stdint.h>

uint32_t GetIP(const char *p)
{
    if (p == NULL) {
        return 0; // Input validation: Return 0 for invalid input
    }

    uint32_t dwIP = 0;
    uint32_t dwIP_Part = 0;

    while (*p)
    {
        if (*p == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        }
        else if (*p >= '0' && *p <= '9')
        {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        }
        else
        {
            return 0; // Input validation: Return 0 for invalid input
        }

        p++;
    }

    if (dwIP_Part < 0 || dwIP_Part > 255)
    {
        return 0; // Input validation: Return 0 for invalid input
    }

    dwIP = (dwIP << 8) | dwIP_Part;

    return dwIP;
}

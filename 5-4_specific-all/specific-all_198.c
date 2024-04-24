#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0;

    // Read the first part of the IP address
    dwIP = (*p++ - '0');
    while (*p != '.' && *p != '\0')
    {
        dwIP = (dwIP * 10) + (*p++ - '0');
    }

    // Read the remaining parts of the IP address
    for (int i = 0; i < 3; ++i)
    {
        while (*p != '.' && *p != '\0')
        {
            dwIP = (dwIP << 8) + (*p++ - '0');
        }
        if (*p == '.') p++;
    }

    return dwIP;
}

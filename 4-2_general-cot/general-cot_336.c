#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0;
    int shift = 24; // Start with the most significant byte

    while (*p)
    {
        if (*p == '.')
        {
            shift -= 8;
        }
        else
        {
            dwIP |= (*p - '0') << shift;
            shift -= 1;
        }
        p++;
    }
    return dwIP;
}

#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;
    
    for (; *p != '\0'; ++p)
    {
        char c = *p;
        
        if (c == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        }
        else
        {
            dwIP_Part = (dwIP_Part * 10) + (c - '0');
        }
    }
    
    dwIP = (dwIP << 8) | dwIP_Part;
    
    return dwIP;
}

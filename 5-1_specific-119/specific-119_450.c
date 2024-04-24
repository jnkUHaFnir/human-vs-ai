#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;
    
    while (true)
    {
        if (p[0] == 0)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        
        if (p[0] == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            p++;
        }
        
        dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (p[0] - '0'); // Faster way to convert char to int (dwIP_Part * 10 + (p[0] - '0'))
        p++;
    }
    
    return dwIP;
}

#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0;
    int shift = 24; // start with the most significant byte
    
    while (true)
    {
        if (p[0] == 0)
        {
            break;
        }
        
        if (p[0] == '.') 
        {       
            shift -= 8; // move to the next byte
            p++;
            continue;
        }
        
        dwIP |= (p[0] - '0') << shift; // add the current digit to the IP address
        p++;
    }
    
    return dwIP;
}

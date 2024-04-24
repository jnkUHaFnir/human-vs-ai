#include <stdint.h>

uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;
    
    while (*p != '\0')
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
            // handle invalid input or unexpected characters
            return 0; // or any other appropriate action
        }
        
        p++;
    }
    
    // Adding the last part after the loop ends
    dwIP = (dwIP << 8) | dwIP_Part;
    
    return dwIP;
}

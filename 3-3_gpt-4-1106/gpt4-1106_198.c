#include <stdint.h>

typedef uint32_t UINT32;

UINT32 GetIP(const char *p)
{
    register UINT32 dwIP = 0, dwIP_Part = 0;
    while (true)
    {
        UINT32 val = *p;
        if(val == 0)
        {
            return (dwIP << 8) | dwIP_Part;
        }
        else if(val == '.') 
        {       
            dwIP = (dwIP << 8) | dwIP_Part;                     
            dwIP_Part = 0;
        }
        else
        {
            dwIP_Part = (dwIP_Part * 10) + (val - '0');
        }
        p++;
    }
}

int main() {
    const char* ip = "192.168.1.1";
    UINT32 ip_val = GetIP(ip);
    return 0;
}

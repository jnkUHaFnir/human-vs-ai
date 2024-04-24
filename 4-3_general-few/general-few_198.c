#define CHAR_TO_INT(c) ((c) - '0')

UINT32 GetIP(const char *p)
{
    if (p == NULL) {
        return 0;
    }

    UINT32 dwIP = 0, dwIP_Part = 0;

    while(true)
    {
        char c = *p;
        if(c == '.' || c == '\0') 
        {
            dwIP = (dwIP << 8) | dwIP_Part;                     
            dwIP_Part = 0;
            if (c == '\0') {
                break;
            }
        } else {
            dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + CHAR_TO_INT(c);
        }
        p++;
    }

    return dwIP;
}

UINT32 GetIP(const char *p)
{
    UINT32 dwIP=0,dwIP_Part=0;
    for (int i = 0; i < 3; i++)
    {
        do {
            dwIP_Part = (dwIP_Part*10)+(p[0]-'0');
            p++;
        } while(*p != '.');
        dwIP = (dwIP << 8) | dwIP_Part;
        dwIP_Part = 0;
        p++;
    }
    while (*p != 0) {
        dwIP_Part = (dwIP_Part*10)+(p[0]-'0');
        p++;
    }
    dwIP = (dwIP << 8) | dwIP_Part;
    return dwIP;
}
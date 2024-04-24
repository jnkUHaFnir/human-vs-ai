UINT32 GetIP(const char *p)
{
    UINT32 dwIP=0, dwIP_Part=0;
    while(true)
    {
        if(!*p)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        if(*p == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        }
        else
        {
            dwIP_Part = dwIP_Part * 10 + (*p - '0');
        }
        p++;
    }
    return dwIP;
}

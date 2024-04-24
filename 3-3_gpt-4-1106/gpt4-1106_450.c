UINT32 GetIP(const char *p)
{
    UINT32 dwIP = 0, dwIP_Part = 0;
    while (true) 
    {
        dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        ++p;
        
        dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        ++p;

        dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        ++p;

        if (*p == '.' || *p == 0)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            if (*p == 0) break;
            ++p;
        }
    }
    
    return dwIP;
}

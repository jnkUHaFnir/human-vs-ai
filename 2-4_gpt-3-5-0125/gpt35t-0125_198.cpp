UINT32 GetIP(const char *p)
{
    UINT32 dwIP=0,dwIP_Part=0;
    while(true)
    {
        if(p[0] == 0)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        if(p[0]=='.') 
        {       
            dwIP = (dwIP << 8) | dwIP_Part;                     
            dwIP_Part = 0;
            p++;
        }
        dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (p[0]-'0'); // Equivalent to dwIP_Part = dwIP_Part*10
        p++;
    }
    return dwIP;
}

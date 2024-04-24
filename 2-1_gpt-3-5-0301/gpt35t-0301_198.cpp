UINT32 GetIP(const char *p)
{
    UINT32 dwIP=0,dwIP_Part=0;
    const int digitTable[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
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
        dwIP_Part = (dwIP_Part * 10) + digitTable[p[0] - '0'];
        p++;
    }
    return dwIP;
}
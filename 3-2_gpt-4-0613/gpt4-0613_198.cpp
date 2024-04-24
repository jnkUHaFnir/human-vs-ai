UINT32 GetIP(const char *p)
{
    UINT32 dwIP=0, dwIP_Part=0;
    char c;

    while(true)
    {
        c = *p++;       

        if(c == '.' || c == 0)
        {       
            dwIP = (dwIP << 8) | dwIP_Part;                     
            dwIP_Part = 0;

            if (c == 0) break;
        } else {
            dwIP_Part = (dwIP_Part*10) + (c - '0');
        }
    }
    return dwIP;
}

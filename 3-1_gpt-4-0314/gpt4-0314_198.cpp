uint32_t GetIP(const char *p)
{
    uint32_t dwIP = 0, dwIP_Part = 0;
    char ch;
    while((ch = *p++) != 0)
    {
        if(ch == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        }
        else
        {
            dwIP_Part = (dwIP_Part * 10) + (ch - '0');
        }
    }
    return (dwIP << 8) | dwIP_Part;
}

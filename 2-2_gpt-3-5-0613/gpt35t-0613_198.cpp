UINT32 GetIP(const char* p)
{
    UINT32 dwIP = 0, dwIP_Part = 0;

    for (; *p != 0; ++p)
    {
        if (*p == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
        }
        else
        {
            dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (*p - '0');
        }
    }

    return (dwIP << 8) | dwIP_Part;
}

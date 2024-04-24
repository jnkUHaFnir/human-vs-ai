inline UINT32 GetIP(const char *p)
{
    UINT32 dwIP = 0, dwIP_Part = 0;

    while (true)
    {
        char c = *p;

        if (c == 0)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }

        if (c == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            p++;
            continue;
        }

        dwIP_Part = (dwIP_Part << 3) + (dwIP_Part << 1) + (c & 0xF);
        p++;
    }

    return dwIP;
}

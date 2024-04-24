UINT32 GetIP(const char* p)
{
    UINT32 dwIP = 0, dwIP_Part = 0;
    
    while (*p != 0 && *p != '.')
    {
        dwIP_Part = dwIP_Part * 10 + (*p - '0');
        ++p;
    }
    
    dwIP = (dwIP << 8) | dwIP_Part;
    
    if (*p == '.') 
    {
        ++p;
        // Second part
        while (*p != 0 && *p != '.')
        {
            dwIP_Part = dwIP_Part * 10 + (*p - '0');
            ++p;
        }

        dwIP = (dwIP << 8) | dwIP_Part;

        if (*p == '.')
        {
            ++p;
            // Third part
            while (*p != 0 && *p != '.')
            {
                dwIP_Part = dwIP_Part * 10 + (*p - '0');
                ++p;
            }

            dwIP = (dwIP << 8) | dwIP_Part;

            if (*p == '.')
            {
                ++p;
                // Fourth part
                while (*p != 0)
                {
                    dwIP_Part = dwIP_Part * 10 + (*p - '0');
                    ++p;
                }

                dwIP = (dwIP << 8) | dwIP_Part;
            }
        }
    }

    return dwIP;
}

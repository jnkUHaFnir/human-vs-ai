UINT32 GetIP(const char* p)
{
    constexpr int kAsciiDigitToValue[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    UINT32 dwIP = 0, dwIP_Part = 0;
    while (true)
    {
        if (*p == 0)
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        if (*p == '.')
        {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            ++p;
        }
        dwIP_Part = (dwIP_Part * 10) + kAsciiDigitToValue[*p - '0'];
        ++p;
    }
    return dwIP;
}

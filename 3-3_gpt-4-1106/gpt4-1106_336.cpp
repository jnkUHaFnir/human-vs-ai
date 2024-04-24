uint32_t GetIP(const char *p) {
    uint32_t dwIP = 0, dwIP_Part = 0;
    const char *start = p;

    while (*p) {
        if (*p == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            start = ++p;
        } else {
            dwIP_Part = dwIP_Part * 10 + (*p - '0');
            ++p;
        }
    }
    
    return (dwIP << 8) | dwIP_Part;
}

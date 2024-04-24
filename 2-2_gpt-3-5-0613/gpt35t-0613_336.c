UINT32 GetIP(const char *p) {
    UINT32 dwIP = 0, dwIP_Part = 0;
    int i = 0;
    
    while (true) {
        if (p[i] == 0) {
            dwIP = (dwIP << 8) | dwIP_Part;
            break;
        }
        
        if (p[i] == '.') {
            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            i++;
        }
        
        // Unroll the loop to process 4 characters at a time
        UINT32 ip_part4 = (p[i] - '0') * 1000 + (p[i+1] - '0') * 100 + (p[i+2] - '0') * 10 + (p[i+3] - '0');
        dwIP_Part = (dwIP_Part * 10000) + ip_part4;

        i += 4;
    }

    return dwIP;
}
    #define HEXLEN 4
    
    long extract_hex(const char *src, size_t offset)
    {
        char hex[HEXLEN + 1] = { 0 };
        char *end;
        long val;
    
        if (strlen(src) < offset)
            return -1;
    
        src += offset;
    
        if (strlen(src) < HEXLEN)
            return -1;
    
        memcpy(hex, src, HEXLEN);
        val = strtol(hex, &end, 16);
    
        if (*end != '\0')
            return -1;
    
        return val;
    }
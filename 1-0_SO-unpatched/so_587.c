    #define HEXLEN 4
    
    long extract_hex(const char *src, size_t offset)
    {
        char hex[HEXLEN + 1] = { 0 };
        long val;
    
        if (strlen(src) < offset + HEXLEN)
            return -1;
    
        memcpy(hex, src + offset, HEXLEN);
        if (strspn(hex, "0123456789AaBbCcDdEeFf") < HEXLEN)
            return -1;
            
        errno = 0;
        val = strtol(hex, &end, 16);
    
        /* Out of range - can't occur unless HEXLEN > 7 */
        if (errno)
            return -1;
    
        return val;
    }
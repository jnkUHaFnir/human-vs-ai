    #define HEXLEN 4
    
    long extract_hex(const char *src, size_t offset)
    {
        char hex[HEXLEN + 1] = { 0 };
        long val;
    
        if (strlen(src) < offset)
            return -1;
    
        src += offset;
    
        if (strspn(src, "0123456789AaBbCcDdEeFf") < HEXLEN)
            return -1;
    
        memcpy(hex, src, HEXLEN);
        
        errno = 0;
        val = strtol(hex, &end, 16);
    
        /* Out of range - can't occur unless HEXLEN > 7 */
        if (errno)
            return -1;
    
        return val;
    }
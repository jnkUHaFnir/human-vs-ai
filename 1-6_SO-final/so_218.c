    unsigned char* src = NULL;
    unsigned char* tmp = realloc(src, (src ? strlen(src) : 0) + strlen(tmp) + 1); 
    if (tmp)
    {
        src = tmp;
    }
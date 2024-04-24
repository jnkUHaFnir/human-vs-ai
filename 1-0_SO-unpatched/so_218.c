    unsigned char tmp[length + 1];
    memcpy(tmp, parameterArray[i].valueU8, length);
    tmp[length] = 0;
    unsigned char* src = NULL;
    unsigned char* src_tmp = realloc(src, (src ? strlen(src) : 0) + strlen(tmp) + 1);
    if (src_tmp)
    {
        if (!src) *src_tmp = 0; /* Ensure null character present before strcat(). */
        src = src_tmp;
        strcat(src, tmp);
    }
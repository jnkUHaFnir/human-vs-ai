    char *tmp = {0};
    
    tmp = ReSizeBuffer(buf, newSize);
    if(!tmp)
    {
       free(buf);
       return NULL;
    }
    else
    {
        buf = tmp;
        ///use new buf
        ...
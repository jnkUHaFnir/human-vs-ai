    char *tmp = {0};
    
    tmp = ReSizeBuffer(&buf, newSize); //see implementation below
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
    char *tmp = {0};
    
    tmp = ReSizeBuffer(&buf, newSize); //see implementation below
    if(!tmp)
    {
       free(buf);
       return NULL;
    }
    buf = tmp;
    ///use new buf
    ...
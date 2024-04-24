    char * ReSizeBuffer(char **str, unsigned int size)
    {
        char *tmp={0};
    
        if(!(*str)) return NULL;
    
        if(size == 0)
        {
            free(*str);
            return NULL;
        }
    
        tmp = (char *)realloc((char *)(*str), size);
        if(!tmp)
        {
            free(*str);
            return NULL;
        }
        *str = tmp;
    
        return *str;
    }
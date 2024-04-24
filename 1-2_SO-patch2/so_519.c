    int sgetline(int fd, char ** out) 
    { 
        int buf_size = 128; 
        int bytesloaded = 0; 
        int ret;
        char buf; 
        char * buffer = malloc(buf_size); 
        char * newbuf; 
     
        if (NULL == buffer)
            return -1;
     
        do
        {
            ret = read(fd, &buf, 1);
            if (ret < 1)
            {
                free(buffer);
                return -1;
            }
    
            buffer[bytesloaded] = buf; 
            bytesloaded++; 
     
            if (buf == '\n') 
                break;
    
            if (bytesloaded >= buf_size) 
            { 
                buf_size += 128; 
                newbuf = realloc(buffer, buf_size); 
     
                if (NULL == newbuf) 
                { 
                    free(buffer);
                    return -1;
                } 
    
                buffer = newbuf; 
            } 
        } 
     
        if ((bytesloaded) && (buffer[bytesloaded-1] == '\r'))
            bytesloaded--;
    
        *out = buffer; 
        return bytesloaded; 
    }
.
    int sockfd = socket( ... );         
    //....         
    char* tbuf;         
    int ret;
    do
    {
        ret = sgetline(sockfd, &tbuf);
        if (ret < 0)
            break;
    
        if (ret == 0)
           printf("End of Headers detected.\n");         
    
        free(tbuf);
    }
    while (true);
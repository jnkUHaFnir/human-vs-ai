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
            // read a single byte
            ret = read(fd, &buf, 1);
            if (ret < 1)
            {
                // error or disconnect
                free(buffer);
                return -1;
            }
    
            buffer[bytesloaded] = buf; 
            bytesloaded++; 
     
            // has end of line been reached?
            if (buf == '\n') 
                break; // yes
    
            // is more memory needed?
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
     
        // if the line was terminated by "\r\n", ignore the
        // "\r". the "\n" is not in the buffer
        if ((bytesloaded) && (buffer[bytesloaded-1] == '\r'))
            bytesloaded--;
    
        *out = buffer; // complete line
        return bytesloaded; // number of bytes in the line, not counting the line break
    }
.
    int sockfd = socket( ... );         
    //....         
    char* tbuf;         
    int ret;
    // keep reading until end of headers is detected.
    // headers are terminated by a 0-length line
    do
    {
        // read a single line
        ret = sgetline(sockfd, &tbuf);
        if (ret < 0)
            break; // error/disconnect
    
        // is it a 0-length line?
        if (ret == 0)
        {
           printf("End of Headers detected.\n");         
           free(tbuf);
           break;
        }
        // tbuf contains a header line, use as needed...
        free(tbuf);
    }
    while (true);
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
            buffer[bytesloaded] = buf; 
            ++bytesloaded; 
        } 
        while (true);
        // if the line was terminated by "\r\n", ignore the
        // "\r". the "\n" is not in the buffer
        if ((bytesloaded) && (buffer[bytesloaded-1] == '\r'))
            bytesloaded--;
    
        // is more memory needed?
        if (bytesloaded >= buf_size) 
        { 
            ++buf_size; 
            newbuf = realloc(buffer, buf_size); 
     
            if (NULL == newbuf) 
            { 
                free(buffer);
                return -1;
            } 
    
            buffer = newbuf; 
        } 
        // add a null terminator
        buffer[bytesloaded] = '\0';
        *out = buffer; // complete line
        return bytesloaded; // number of bytes in the line, not counting the line break and null terminator
    }
    void parse_http_headers(int s, FILE * fp)
    {
       int      isnheader;
       size_t   readed;
       size_t   len;
       size_t   offset;
       size_t   pos;
       char     buffer[512];
       char   * eol; // end of line
       char   * bol; // beginning of line
    
       isnheader = 0;
       len       = 0;
    
       // read next chunk from socket
       while((readed = recv(s, &buffer[len], (511-len), 0)) > 0)
       {
          // process headers
          if (isnheader == 0)
          {
             // calculate combined length of unprocessed data and new data
             len += readed;
    
             // NULL terminate buffer for string functions
             buffer[len] = '\0';
    
             // checks if the header break happened to be the first line of the
             // buffer 
             if (!(strncmp(buffer, "\r\n", 2)))
             {
                if (len > 2)
                   fwrite(buffer, 1, (len-2), fp);
                continue;
             };
    
             // process each line in buffer looking for header break
             bol = buffer;
             while((eol = strstr(bol, "\r\n")) != NULL)
             {
                // update bol based upon the value of eol
                bol = eol + 2;
    
                // test if end of headers has been reached
                if (!(strncmp(bol, "\r\n", 2)))
                {
                   // note that end of headers has been reached
                   isnheader = 1;
    
                   // update the value of bol to reflect the beginning of the line
                   // immediately after the headers
                   bol += 2;
    
                   // calculate the amount of data remaining in the buffer
                   len = len - (bol - buffer);
    
                   // write remaining data to FILE stream
                   if (len > 0)
                      fwrite(bol, 1, len, fp);
    
                   // reset length of left over data to zero and continue processing
                   // non-header information
                   len = 0;
                   continue;
                };
             };
    
             // shift data remaining in buffer to beginning of buffer
             offset = len - (bol - buffer);
             for(pos = 0; pos < offset; pos++)
                buffer[pos] = buffer[offset + pos];
    
             // save amount of unprocessed data remaining in buffer
             len = offset;
          };
    
          // write rest of data to FILE stream
          fwrite(buffer, 1, readed, fp);
       };
    
       return;
    }
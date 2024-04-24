if(buf[0] == '\n' && size > 1 && buffer[bytesloaded-1] == '\r')
{
    buffer[bytesloaded-1] = '\0'; // replace '\r' with '\0'
    *out = buffer; 
    return bytesloaded-1; // -1 because '\r' is not considered part of the line
}
buf[1] = '\0';
while(read(fd, buf, 1) > 0)
{
    buf[1] = '\0'; // Null terminating for safety

    buffer[bytesloaded] = buf[0]; // append char to buffer
    bytesloaded++;

    if(bytesloaded >= size) // time to reallocate?
    {
        size = size + buf_size;
        newbuf = realloc(buffer, size);

        if(NULL != newbuf)
        {
            buffer = newbuf;
        }
        else 
        {
            printf("sgetline() allocation failed!\n");
            exit(1);
        }
    }

    if(buf[0] == '\n' && bytesloaded > 1 && buffer[bytesloaded-2] == '\r')
    {
        buffer[bytesloaded-2] = '\0';   // replace '\r' with '\0'
         *out = buffer;
         return bytesloaded-2;   // -2 because '\r' is not considered part of the line
    }
}
if(strcmp(tbuf,"\r\n") == 0)
{
   printf("End of Headers detected.\n");
}

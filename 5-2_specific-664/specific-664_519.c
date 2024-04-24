int sgetline(int fd, char **out)
{
    int buf_size = 128;
    int bytesloaded = 0;
    char buf[2];
    char *buffer = malloc(buf_size);
    char *newbuf;
    int size = buf_size;

    assert(NULL != buffer);

    while (read(fd, buf, 1) > 0)
    {
        if (bytesloaded + 1 >= size)
        {
            size += buf_size;
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

        buffer[bytesloaded] = buf[0];
        bytesloaded++;
        buffer[bytesloaded] = '\0'; // Null-terminate the buffer

        if (buf[0] == '\n')
        {
            *out = buffer; 
            return bytesloaded;
        }
    }

    *out = buffer;
    return bytesloaded;
}

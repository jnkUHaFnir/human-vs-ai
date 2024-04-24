char *read_input(const char *file)
{
    int         fd;
    ssize_t     read_stat;
    size_t      i = 0;
    size_t      size = 4096;  // Initial buffer size
    char        *buffer;
   
    buffer = malloc(size);
    if (!buffer)
        return NULL;
  
    if ((fd = open(file, O_RDONLY)) == -1)
    {
        free(buffer);
        return NULL;
    }
    
    while ((read_stat = read(fd, buffer + i, 1)) == 1)
    {
        i++;
        if (i >= size)
        {
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (!new_buffer)
            {
                free(buffer);
                close(fd);
                return NULL;
            }
            buffer = new_buffer;
        }
    }

    if (read_stat == -1)
    {
        free(buffer);
        close(fd);
        return NULL;
    }

    buffer[i] = '\0';
    
    if (close(fd) == -1)
    {
        free(buffer);
        return NULL;
    }
  
    return buffer;
}
while ((read_stat = read(fd, buffer + i, size - i - 1)) > 0)

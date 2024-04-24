char *read_input(const char *file)
{
    int fd;
    int read_stat;
    int i = 0;
    int max_size = 1000; // Initial size of the buffer
    char *tmp = (char*)malloc(max_size * sizeof(char));

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        printf("Error");
        return NULL;
    }

    char buffer[1];

    while ((read_stat = read(fd, buffer, 1)))
    {
        if (i >= max_size) // If the buffer is full, reallocate more memory
        {
            max_size *= 2; // Double the size
            tmp = (char*)realloc(tmp, max_size * sizeof(char));
        }
        tmp[i++] = buffer[0];
    }
    tmp[i] = '\0';

    if (close(fd) == -1)
    {
        printf("Error");
        free(tmp); // Free the allocated memory before returning NULL
        return NULL;
    }

    return tmp;
}

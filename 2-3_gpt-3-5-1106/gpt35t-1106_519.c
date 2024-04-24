int sgetline(int fd, char **out)
{
    int buf_size = 128;
    int bytesloaded = 0;
    char buf[2];
    char *buffer = malloc(buf_size);
    int size = buf_size;

    assert(NULL != buffer);

    while (read(fd, buf, 1) > 0)
    {
        if (bytesloaded >= size - 1)
        {
            size += buf_size;
            buffer = realloc(buffer, size);
            assert(NULL != buffer);
        }

        if (buf[0] == '\n')
        {
            buffer[bytesloaded] = '\0'; // Terminate the buffer
            *out = buffer;
            return bytesloaded;
        }

        buffer[bytesloaded++] = buf[0];
    }

    *out = buffer;
    return bytesloaded;
}
int sockfd = socket( ... );
//....
char* tbuf = NULL;
int n;
while ((n = sgetline(sockfd, &tbuf)) > 0)
{
    if (strcmp(tbuf, "\r\n") == 0)
    {
        // We've reached the end of headers
        printf("End of Headers detected.\n");
        break;
    }
    free(tbuf); // Free the buffer after each use
    tbuf = NULL;
}

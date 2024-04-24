#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int sgetline(int fd, char **out)
{
    int buf_size = 128;
    int bytesloaded = 0;
    char buf;
    char *buffer = malloc(buf_size);
    int size = buf_size;

    if (buffer == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    while (read(fd, &buf, 1) > 0)
    {
        buffer[bytesloaded] = buf;
        bytesloaded++;

        if (bytesloaded >= size - 1)
        {
            size += buf_size;
            char *newbuf = realloc(buffer, size);
            if (newbuf == NULL)
            {
                printf("Memory reallocation failed!\n");
                exit(1);
            }
            buffer = newbuf;
        }

        if (buf == '\n')
        {
            buffer[bytesloaded] = '\0';
            *out = buffer;
            return bytesloaded;
        }
    }

    *out = buffer;
    return bytesloaded;
}

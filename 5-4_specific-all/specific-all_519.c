#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int sgetline(int fd, char **out)
{
    int buf_size = 128;
    int bytesloaded = 0;
    int size = buf_size;
    char *buffer = malloc(size);
    char *newbuf;

    assert(NULL != buffer);

    *out = buffer;

    char c;
    while (read(fd, &c, 1) > 0)
    {
        if (bytesloaded >= size - 1) // if buffer about to overflow
        {
            size += buf_size;
            newbuf = realloc(buffer, size);

            if (NULL != newbuf)
            {
                buffer = newbuf;
                *out = buffer;
            }
            else
            {
                printf("sgetline() allocation failed!\n");
                exit(1);
            }
        }

        if (c == '\n')
        {
            buffer[bytesloaded] = '\0';
            return bytesloaded;
        }

        buffer[bytesloaded] = c;
        bytesloaded++;
    }

    buffer[bytesloaded] = '\0'; // null terminate the string
    return bytesloaded;
}

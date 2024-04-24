#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

char* sgetline(int fd)
{
    int buf_size = 128;
    int bytesloaded = 0;
    char* buffer = malloc(buf_size);
    char* newbuf;
    
    assert(buffer != NULL);

    while(read(fd, buffer + bytesloaded, 1) > 0)
    {
        bytesloaded++;

        if(bytesloaded >= buf_size)
        {
            buf_size += 128;
            newbuf = realloc(buffer, buf_size);

            if(newbuf != NULL)
            {
                buffer = newbuf;
            }
            else 
            {
                printf("sgetline() allocation failed!\n");
                exit(1);
            }
        }
        
        if(buffer[bytesloaded - 1] == '\n')
        {
            buffer[bytesloaded] = '\0';
            return buffer;
        }
    }

    return buffer;
}

int main()
{
    int sockfd = socket(...);
    //....

    char* tbuf;
    while((tbuf = sgetline(sockfd)) != NULL)
    {
        if(strcmp(tbuf, "\r\n") == 0)
        {
           printf("End of Headers detected.\n");
           free(tbuf);
           break;
        }

        printf("%s", tbuf);
        free(tbuf);
    }

    return 0;
}

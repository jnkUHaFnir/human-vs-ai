#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sgetline(int fd, char **out) {
    int buf_size = 128;
    int bytesloaded = 0;
    char *buffer = malloc(buf_size);
    int size = buf_size;
    int index = 0;

    if (NULL == buffer) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    while (1) {
        char buf;
        int bytesRead = read(fd, &buf, 1);

        if (bytesRead <= 0) {
            break; // End of file or error
        }

        buffer[index++] = buf;

        bytesloaded++;
        size--;

        if (buf == '\n') {
            break;
        }

        if (size == 0) {
            size += buf_size;
            char *newbuf = realloc(buffer, size);

            if (NULL == newbuf) {
                printf("Memory reallocation failed!\n");
                free(buffer);
                exit(1);
            }

            buffer = newbuf;
        }
    }

    *out = buffer;
    return bytesloaded;
}
int sockfd = socket(...);
// ...
char* tbuf;
while (sgetline(sockfd, &tbuf) > 0) {
    if (memcmp(tbuf, "\r\n\r\n", 4) == 0) {
       printf("End of Headers detected.\n");
    }
    free(tbuf); // Free allocated memory
}
``` 

By making these changes, you will ensure that the function properly reads binary data from the socket buffer and detects the end of the headers correctly.

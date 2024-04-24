#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int sgetline(int fd, char **out) {
    int buf_size = 128;
    int bytesloaded = 0;
    char buf[2];
    char *buffer = malloc(buf_size);
    char *newbuf;
    int size = buf_size;

    assert(NULL != buffer);

    buffer[0] = '\0'; // Initialize buffer

    while (read(fd, buf, 1) > 0) {
        buf[1] = '\0';
        strcat(buffer, buf);
        bytesloaded += 1;

        if (buf[0] == '\n') {
            *out = buffer;
            return bytesloaded;
        }

        if (bytesloaded >= size - 1) {  // check for buffer overflow
            size = size + buf_size;
            newbuf = realloc(buffer, size);

            if (NULL != newbuf) {
                buffer = newbuf;
            } else {
                printf("sgetline() reallocation failed!\n");
                free(buffer); // free allocated memory before exit
                exit(1);
            }
        }
    }

    *out = buffer;
    return bytesloaded;
}

int main() {
    // Test your function
    int sockfd = socket(...);
    char* tbuf;
    
    while (sgetline(sockfd, &tbuf) > 0) {
        if (strcmp(tbuf, "\r\n") == 0) {
            printf("End of Headers detected.\n");
            break; // assuming you want to stop after detecting "\r\n"
        }
    }

    // Free allocated memory
    free(tbuf);

    return 0;
}

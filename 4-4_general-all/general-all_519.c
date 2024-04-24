#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int sgetline(int fd, char **out) {
    int buf_size = 128;
    int bytesloaded = 0;
    char buf;
    char *buffer = malloc(buf_size);
    int size = buf_size;

    if (buffer == NULL) {
        printf("Allocation failed!\n");
        exit(1);
    }

    int index = 0;
    while (read(fd, &buf, 1) > 0) {
        buffer[index++] = buf;
        bytesloaded++;

        if (buf == '\n') {
            buffer[index] = '\0';
            *out = buffer;
            return bytesloaded;
        }

        if (index >= size - 1) {
            size += buf_size;
            char *newbuf = realloc(buffer, size);
            if (newbuf == NULL) {
                printf("Reallocation failed!\n");
                free(buffer);
                exit(1);
            }
            buffer = newbuf;
        }
    }

    *out = buffer;
    return bytesloaded;
}

int main() {
    int sockfd = socket(...);

    char* tbuf;
    int endOfHeaders = 0;

    while (sgetline(sockfd, &tbuf) > 0) {
        if (strcmp(tbuf, "\r\n") == 0) {
            endOfHeaders = 1;
        } else {
            endOfHeaders = 0;
        }

        if (endOfHeaders && strcmp(tbuf, "\r\n") == 0) {
            printf("End of Headers detected.\n");
            break;
        }
    }

    // Free memory allocated for tbuf
    free(tbuf);

    return 0;
}

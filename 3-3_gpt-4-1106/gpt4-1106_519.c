#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int sgetline(int fd, char **out) {
    // Start with a small buffer size for demonstration; it's not efficient.
    int buf_size = 128;
    int bytesloaded = 0;
    char buf[2] = {0};
    char *buffer = malloc(buf_size);
    char *newbuf;

    if (buffer == NULL) {
        perror("malloc failed");
        return -1;
    }

    *buffer = '\0';  // Null-terminate the buffer initially.

    while (read(fd, buf, 1) == 1) {
        buf[1] = '\0';  // Null-terminate the string.
        if (bytesloaded >= buf_size - 1) {
            // Increase buffer size to accommodate larger lines.
            buf_size *= 2;
            newbuf = realloc(buffer, buf_size);
            if (newbuf == NULL) {
                perror("realloc failed");
                free(buffer);
                return -1;
            }
            buffer = newbuf;
        }

        // Append the read character to the buffer.
        buffer[bytesloaded] = buf[0];
        buffer[bytesloaded + 1] = '\0';
        bytesloaded++;

        // Check for the newline character indicating the end of a line.
        if (buf[0] == '\n') {
            break;
        }

    }

    if (bytesloaded == 0 && buffer[0] == '\0') {
        // End of file or no data read; signal this to the caller.
        free(buffer);
        *out = NULL;
        return 0;
    }

    *out = buffer;
    return bytesloaded;
}

int main() {
    // Emulate `socket()` somehow by getting a file descriptor for reading.
    int sockfd = /* Your socket setup code here */;

    char *tbuf = NULL;
    while (sgetline(sockfd, &tbuf) > 0) {
        // You should compare the result with CRLF also because some servers may use just LF.
        if (strcmp(tbuf, "\r\n") == 0 || strcmp(tbuf, "\n") == 0) {
            printf("End of Headers detected.\n");
        }
        free(tbuf);  // Don't forget to free the memory once you're done with it.
        tbuf = NULL;
    }

    return 0;
}

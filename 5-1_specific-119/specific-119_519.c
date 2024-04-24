#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int sgetline(int fd, char **out) {
    char *buffer = NULL;
    char buf;
    int bytesloaded = 0;
    int size = 0;
    
    while (read(fd, &buf, 1) > 0) {
        if (bytesloaded >= size) {
            size += 128;
            char *newbuf = realloc(buffer, size);
            if (newbuf == NULL) {
                printf("sgetline() allocation failed!\n");
                exit(1);
            }
            buffer = newbuf;
        }
        
        buffer[bytesloaded++] = buf;
        
        if (buf == '\n') {
            buffer[bytesloaded] = '\0';
            *out = buffer;
            return bytesloaded;
        }
    }
    
    if (bytesloaded > 0) {
        buffer[bytesloaded] = '\0';
        *out = buffer;
        return bytesloaded;
    } else {
        free(buffer);
        return -1; // Indicates no more data to read
    }
}

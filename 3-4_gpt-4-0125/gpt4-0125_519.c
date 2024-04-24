#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int sgetline(int fd, char **out) {
    int buf_size = 128;
    int bytesLoaded = 0;
    char *buffer = malloc(buf_size); // Allocate initial buffer size.
    
    assert(buffer != NULL); // Verify memory allocation succeeded.
    buffer[0] = '\0'; // Initialize as an empty string.
    
    char ch; // To store each character read.
    while (read(fd, &ch, 1) == 1) { // Read one byte at a time.
        if (bytesLoaded >= buf_size - 1) { // Check if buffer needs expansion.
            buf_size *= 2; // Double the buffer size.
            char *newbuf = realloc(buffer, buf_size);
            if (!newbuf) {
                printf("sgetline() allocation failed!\n");
                exit(1);
            }
            buffer = newbuf;
        }
        
        buffer[bytesLoaded++] = ch; // Store the character.
        buffer[bytesLoaded] = '\0'; // Null-terminate the string.

        if (ch == '\n') { // Check if this is the end of a line.
            break;
        }
    }
    
    *out = buffer; // Assign the output buffer.
    return bytesLoaded; // Return the number of characters read.
}

int main() {
    // Your sample usage
    int sockfd = ...; // Initialize socket here.

    char *tbuf = NULL;
    while (sgetline(sockfd, &tbuf) > 0) {
        if (strcmp(tbuf, "\r\n") == 0) {
            printf("End of Headers detected.\n");
            break; // Exiting after detecting end of headers.
        }
        free(tbuf); // Free the allocated buffer after use.
        tbuf = NULL; // Reset pointer to avoid dangling reference.
    }
    if (tbuf != NULL) free(tbuf); // Clean up if loop exits without freeing the last allocation.

    return 0;
}

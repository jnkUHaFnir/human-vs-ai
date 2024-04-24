#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFF_SIZE 1024

int main() {
    char buffer[MAX_BUFF_SIZE];
    int readed, isnheader = 0;
    FILE *fp = fopen("file.pdf", "wb");
    
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *endHeaders = NULL;
    size_t remaining = 0;
    
    while ((readed = recv(sock, buffer + remaining, MAX_BUFF_SIZE - remaining, 0)) > 0) {
        size_t totalRead = readed + remaining;
        buffer[totalRead] = '\0';

        if (!isnheader) {
            endHeaders = strstr(buffer, "\r\n\r\n");
            if (endHeaders != NULL) {
                isnheader = 1;
                size_t headerLength = endHeaders - buffer + 4; // Include the '\r\n\r\n'
                
                fwrite(endHeaders + 4, 1, totalRead - headerLength, fp);
            }
        } else {
            fwrite(buffer, 1, totalRead, fp);
        }

        remaining = totalRead - (endHeaders != NULL ? headerLength : 0);

        if (endHeaders != NULL) {
            memmove(buffer, endHeaders + 4, remaining);
        }
    }

    fclose(fp);
    
    return 0;
}

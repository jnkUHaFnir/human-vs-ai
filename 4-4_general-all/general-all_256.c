#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

int main() {
    // Assume sock, fp, and buffer are properly defined and initialized

    char buffer[128];
    int isnheader = 0;
    ssize_t readed;

    while ((readed = recv(sock, buffer, sizeof(buffer), 0)) > 0) {

        // Search for the end of headers by looking for an empty line
        char *endOfHeaders = strstr(buffer, "\r\n\r\n");
        if (endOfHeaders != NULL) {
            isnheader = 1;

            // Calculate the position of the beginning of the body content
            size_t bodyStart = endOfHeaders - buffer + 4;

            // Write the first part of the body content
            fwrite(buffer + bodyStart, 1, readed - bodyStart, fp);
        }

        // If we have passed the headers, write the entire buffer
        if (isnheader) {
            fwrite(buffer, 1, readed, fp);
        }
    }

    return 0;
}

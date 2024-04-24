#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

#define BUFFER_SIZE 256

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Modify this for your needs
    FILE *fp = fopen("output.pdf", "wb");
    char buffer[BUFFER_SIZE];
    ssize_t readed;
    int isnheader = 0;
    size_t header_len = 0;

    // Extra buffer for storing the remaining data after the headers
    char *extra_buf = NULL;
    size_t extra_len;

    while ((readed = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        if (!isnheader && (extra_buf = strstr(buffer, "\r\n\r\n")) != NULL) {
            isnheader = 1;

            // Calculate the length of header data
            header_len = (extra_buf + 4) - buffer;

            // Calculate the remaining data length after the headers
            extra_len = readed - header_len;

            // Write the remaining data after the headers
            if (extra_len > 0) {
                fwrite(extra_buf + 4, 1, extra_len, fp);
            }
        } else {
            if (isnheader) {
                // If headers are already passed, just write the received data
                fwrite(buffer, 1, readed, fp);
            } else {
                // You may also want to process the headers here
            }
        }
    }

    fclose(fp);
    close(sock);
    return 0;
}

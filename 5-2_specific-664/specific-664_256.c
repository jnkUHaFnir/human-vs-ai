#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main() {
    int sock; // Assume socket is created and connected
    
    FILE *fp = fopen("output.pdf", "wb"); // Open the output file in binary write mode
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t readed;
    int isnheader = 0;
    int header_end_index = -1;

    while ((readed = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        if (isnheader == 0) {
            // Look for the end of HTTP headers
            char *headers_end = strstr(buffer, "\r\n\r\n");
            if (headers_end != NULL) {
                isnheader = 1;
                header_end_index = headers_end - buffer + 4; // 4 is the length of "\r\n\r\n"
                fwrite(headers_end + 4, 1, readed - (header_end_index), fp); // Write the first part of the binary data
            }
        } else {
            // Write the binary data to the file
            fwrite(buffer, 1, readed, fp);
        }
    }

    if (readed < 0) {
        perror("Error in receiving data");
    }

    fclose(fp); // Close the file

    return 0;
}

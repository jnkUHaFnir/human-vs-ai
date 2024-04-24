#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 128

// Assuming fp is a valid FILE pointer for writing to the output file

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int readed;
    int isnheader = 0;
    int contentLength = -1; // Initialize to -1, indicating Content-Length not yet received
    int totalReaded = 0;

    while ((readed = recv(sock, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        if (!isnheader) {
            // Locate the end of headers
            char* endOfHeaders = strstr(buffer, "\r\n\r\n");
            if (endOfHeaders != NULL) {
                isnheader = 1;
                // Determine Content-Length
                char* contentLengthHeader = strstr(buffer, "Content-Length: ");
                if (contentLengthHeader != NULL) {
                    sscanf(contentLengthHeader + 16, "%d", &contentLength);
                }
                
                // Calculate the amount of data left in this buffer after the headers
                int leftAfterHeaders = readed - (endOfHeaders - buffer) - 4;
                if (leftAfterHeaders > 0) {
                    fwrite(endOfHeaders + 4, 1, leftAfterHeaders, fp);
                    totalReaded += leftAfterHeaders;
                }
            }
        } else if (contentLength > 0) { // Check if Content-Length is received
            if (totalReaded + readed < contentLength) {
                fwrite(buffer, 1, readed, fp);
                totalReaded += readed;
            } else {
                // Write only the necessary amount of data to complete the file
                fwrite(buffer, 1, contentLength - totalReaded, fp);
                break;
            }
        }
    }

    fclose(fp);

    return 0;
}

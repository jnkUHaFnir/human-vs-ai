#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sock; // Assume socket is properly initialized and connected
    FILE* fp; // Assume file pointer is properly initialized and opened in binary write mode

    char buffer[128];
    ssize_t readed;
    int isnheader = 0;
    char* endHeaders = "\r\n\r\n";

    while ((readed = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        if (!isnheader) {
            char* endPtr = strstr(buffer, endHeaders);
            if (endPtr != NULL) {
                isnheader = 1;
                size_t bytesToWrite = readed - (endPtr - buffer) - strlen(endHeaders);
                if (bytesToWrite > 0) {
                    fwrite(endPtr + strlen(endHeaders), 1, bytesToWrite, fp);
                }
            }
        } else {
            fwrite(buffer, 1, readed, fp);
        }
    }

    return 0;
}

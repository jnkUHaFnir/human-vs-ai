#include <stdio.h>
#include <string.h>

#define MAX_BUF_SIZE 128

int main() {
    // Assume sock, fp are properly initialized and open
    char buffer[MAX_BUF_SIZE];
    int readed;
    int isnheader = 0;
    
    while ((readed = recv(sock, buffer, MAX_BUF_SIZE, 0)) > 0) {
        if (!isnheader) {
            // Check for an empty line to signal end of headers
            if (strncmp(buffer, "\r\n", 2) == 0 || strncmp(buffer, "\n", 1) == 0) {
                isnheader = 1;
            }
        }

        if (isnheader) {
            fwrite(buffer, 1, readed, fp);
        }
    }

    return 0;
}

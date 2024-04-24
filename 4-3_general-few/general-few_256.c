#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    // Assume sock, buffer, fp are already initialized

    int isnheader = 0;
    char buffer[128];
    ssize_t readed;

    while ((readed = recv(sock, buffer, 128, 0)) > 0) {
        int i;
        for (i = 0; i < readed; i++) {
            if (isnheader == 0 && i + 3 < readed && 
                buffer[i] == '\r' && buffer[i + 1] == '\n' &&
                buffer[i + 2] == '\r' && buffer[i + 3] == '\n') {
                // Found end of headers
                isnheader = 1;
                i += 3; // Skip the "\r\n\r\n"
            }
            if (isnheader) {
                fwrite(&buffer[i], 1, readed - i, fp);
                break; // Exit the loop as we copied the binary data
            }
        }
    }

    return 0;
}

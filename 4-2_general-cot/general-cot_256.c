#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF_SIZE 128

int main() {
    FILE *fp = fopen("output.pdf", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int sock; // Assume the socket is already created and connected
    char buffer[MAX_BUF_SIZE];
    size_t readed;
    bool inHeader = true;

    while ((readed = recv(sock, buffer, MAX_BUF_SIZE, 0)) > 0) {
        for (size_t i = 0; i < readed; i++) {
            if (inHeader) { 
                if (i >= 3 && buffer[i] == '\n' && buffer[i - 1] == '\r' && buffer[i - 2] == '\n' && buffer[i - 3] == '\r') {
                    inHeader = false;
                    fwrite(buffer + i + 1, 1, readed - i - 1, fp); // Write the data after the headers
                    break;
                }
            } else {
                fwrite(buffer + i, 1, readed - i, fp); // Write the binary data
                break;
            }
        }
    }

    fclose(fp);
    return 0;
}

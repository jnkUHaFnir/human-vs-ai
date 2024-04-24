#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int send_all(int sockfd, const char *buf, int len) {
    ssize_t n;

    while (len > 0) {
        n = send(sockfd, buf, len, 0);
        if (n < 0)
            return -1;
        buf += n;
        len -= n;
    }

    return 0;
}

int recv_all(int sockfd, char *buf, int len) {
    ssize_t n;

    while (len > 0) {
        n = recv(sockfd, buf, len, 0);
        if (n <= 0)
            return n;
        buf += n;
        len -= n;
    }

    return 1;
}

int recv_txt_file(int sockfd, int len, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int total = 0;
    ssize_t received_bytes;

    while ((received_bytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        total += received_bytes;
        fwrite(buffer, 1, received_bytes, fp);
    }

    if (received_bytes < 0) {
        perror("Receiving");
    }

    fclose(fp);
    close(sockfd);

    printf("Received total bytes: %d\n", total);
    return 0;
}

int main() {
    // Server setup code remains the same as before
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int send_txt_file(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t read_bytes;

    while ((read_bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        if (send(sockfd, buffer, read_bytes, 0) != read_bytes) {
            perror("Sending");
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    // Client setup code remains the same as before
}

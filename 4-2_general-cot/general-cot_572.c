int send_all(int sockfd, const char *buf, size_t len) {
    ssize_t n;
    size_t total = 0;

    while (total < len) {
        n = send(sockfd, buf + total, len - total, 0);
        if (n < 0) {
            return -1; // send failed
        }
        total += n;
    }

    return 0; // success
}

int recv_all(int sockfd, char *buf, size_t len) {
    ssize_t n;
    size_t total = 0;

    while (total < len) {
        n = recv(sockfd, buf + total, len - total, 0);
        if (n <= 0) {
            return n; // recv failed or connection closed
        }
        total += n;
    }

    return 1; // success
}
int send_txt_file(int sockfd, int len, const char *filename) {
    FILE *fp = fopen(filename, "r");
    int b;
    char buffer[BUFFER_SIZE];

    if (fp == NULL) {
        perror("Error while opening file");
        return 0;
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        if (send_all(sockfd, buffer, b) < 0) {
            perror("Error while sending file");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

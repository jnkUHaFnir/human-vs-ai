int recv_txt_file(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    int total = 0;
    char buffer[BUFFER_SIZE];

    if (fp == NULL) {
        perror("File opening failed");
        return -1;
    }

    ssize_t n;
    while((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n, fp);
        total += n;
    }

    if (n < 0) {
        perror("Recv Error");
    }

    printf("Received bytes: %d\n", total);
    fclose(fp);

    return n >= 0 ? 0 : -1;
}
memset(buffer, 0, BUFFER_SIZE);  // Use instead of memset(buffer, BUFFER_SIZE, '\0');

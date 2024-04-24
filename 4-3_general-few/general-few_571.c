int recv_txt_file(int sockfd, int len, const char *filename) {
    FILE* fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    if (fp != NULL) {
        while ((b = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            total += b;
            fwrite(buffer, 1, b, fp);
        }

        if (b < 0) {
            perror("Receiving");
        }

        printf("Received total bytes: %d\n", total);

        fclose(fp);
    } else {
        perror("File");
    }

    close(sockfd);

    return 1;
}

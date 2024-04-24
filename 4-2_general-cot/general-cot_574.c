int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int total = 0, bytes_received;
    char buffer[BUFFER_SIZE];

    while ((bytes_received = recv_all(sockfd, buffer, BUFFER_SIZE)) > 0) {
        total += bytes_received;
        fwrite(buffer, 1, bytes_received, fp);
    }

    if (bytes_received < 0) {
        perror("Error receiving file");
    }

    fclose(fp);
    close(sockfd);

    return total;
}
int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int bytes_read;
    char buffer[BUFFER_SIZE];

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        if (send_all(sockfd, buffer, bytes_read) < 0) {
            perror("Error sending file");
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return 1;
}

int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error while opening file");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char buffer[BUFFER_SIZE];
    size_t bytes_read, total_sent = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        ssize_t bytes_sent = send_all(sockfd, buffer, bytes_read);
        if (bytes_sent < 0) {
            perror("Error while sending file content");
            fclose(fp);
            return 0;
        }
        total_sent += bytes_sent;
    }

    fclose(fp);
    printf("Total bytes sent: %ld\n", total_sent);
    
    return 1;
}
int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error while opening file for writing");
        return -1;
    }

    int total_received = 0, bytes_received;
    char buffer[BUFFER_SIZE];

    while ((bytes_received = recv_all(sockfd, buffer, len)) > 0) {
        total_received += bytes_received;
        fwrite(buffer, 1, bytes_received, fp);
    }

    if (bytes_received < 0) {
        perror("Error while receiving file content");
    }

    printf("Total bytes received: %d\n", total_received);
    
    fclose(fp);
    
    return total_received;
}

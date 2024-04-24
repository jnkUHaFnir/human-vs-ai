int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, bytes_received;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("Error opening file");
        close(sockfd);
        return 0;
    }

    while ((bytes_received = recv_all(sockfd, buffer, len)) > 0)
    {
        total += bytes_received;
        fwrite(buffer, 1, bytes_received, fp);
    }

    if (bytes_received < 0)
    {
        perror("Receiving");
    }

    printf("Received bytes: %d\n", total);

    fclose(fp);
    close(sockfd);

    return 1;
}
int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int bytes_read;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, bytes_read) < 0)
        {
            perror("Error sending file");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int recv_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, fp);
    }

    if (bytes_received < 0)
    {
        perror("Receiving");
    }

    fclose(fp);
    close(sockfd);
    return 1;
}
int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send(sockfd, buffer, bytes_read, 0) < 0)
        {
            perror("Sending");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

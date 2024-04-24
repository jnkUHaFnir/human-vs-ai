int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int b;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, b) < 0)
        {
            perror("Error while sending file data");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}
int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Error while opening file for writing");
        close(sockfd);
        return -1;
    }

    int total = 0, received;
    char buffer[BUFFER_SIZE];

    while ((received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0)
    {
        total += received;
        if (fwrite(buffer, 1, received, fp) != received)
        {
            perror("Error writing to file");
            fclose(fp);
            close(sockfd);
            return -1;
        }
    }

    if (received < 0)
    {
        perror("Error receiving file data");
        fclose(fp);
        close(sockfd);
        return -1;
    }

    printf("Received total bytes: %d\n", total);

    fclose(fp);
    close(sockfd);

    return 1;
}

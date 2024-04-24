int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
        }

        printf("Received bytes: %d\n", total);
        if (b < 0)
            perror("Receiving");

        fclose(fp);
    }
    else
    {
        perror("File");
    }
    close(sockfd);
}
int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int b;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, b) < 0)
        {
            perror("Error sending file content");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

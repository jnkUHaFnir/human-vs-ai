int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, bytes_read) < 0)
        {
            perror("Error sending file content");
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
        perror("Error opening file for writing");
        return 0;
    }

    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    while ((b = recv_all(sockfd, buffer, len)) > 0)
    {
        total += b;
        fwrite(buffer, 1, b, fp);
    }

    printf("Received bytes: %d\n", total);
    
    if (b < 0)
    {
        perror("Receiving error");
    }

    fclose(fp);
    return 1;
}

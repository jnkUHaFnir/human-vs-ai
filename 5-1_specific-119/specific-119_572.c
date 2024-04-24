int send_txt_file(int sockfd, int len, const char *filename)
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
        send_all(sockfd, buffer, b);  // Change BUFFER_SIZE to b
        memset(buffer, '\0', BUFFER_SIZE);
    }

    fclose(fp);
    return 1;
}
int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, len)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
        }

        printf("Received bytes: %d\n", total);
        if (b == 0)
        {
            printf("File uploaded successfully.\n");
        }
        else if (b < 0)
        {
            perror("Receiving error");
        }

        fclose(fp);
    }
    else
    {
        perror("File opening error");
    }
    close(sockfd);
}

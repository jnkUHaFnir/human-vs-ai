int recv_txt_file(int sockfd, long int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while ((b = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);

            if (total >= len) {
                break;  // Exit loop when all data received
            }
        }

        printf("Received bytes: %d\n", total);

        if (b < 0) {
            perror("Receiving");
        }

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
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send(sockfd, buffer, b, 0) < 0)
        {
            perror("Failed to send file data");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

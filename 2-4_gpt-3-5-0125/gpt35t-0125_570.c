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

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0){
        if (send_all(sockfd, buffer, b) < 0) {
            perror("Error while sending file");
            fclose(fp);
            return 0;
        }
        memset(buffer, '\0', BUFFER_SIZE);
    }

    fclose(fp);
    return 1;
}
int recv_txt_file(int sockfd, int len, const char *filename, int file_size)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while (total < file_size && (b = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
            memset(buffer, '\0', BUFFER_SIZE);
        }

        printf("Received byte: %d\n", total);
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
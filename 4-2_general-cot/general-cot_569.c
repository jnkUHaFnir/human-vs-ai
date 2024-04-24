int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, BUFFER_SIZE)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
        }

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

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0){
        send_all(sockfd, buffer, b);
    }

    fclose(fp);
    return 1;
}

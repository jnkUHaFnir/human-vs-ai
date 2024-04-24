int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("File");
        close(sockfd);
        return 0;
    }

    while (1)
    {
        memset(buffer, '\0', sizeof(buffer));
        ssize_t n = recv_all(sockfd, buffer, len);
        if (n <= 0)
            break;
        fwrite(buffer, 1, n, fp);
        total += n;
    }

    if (n < 0)
        perror("Receiving");

    fclose(fp);
    close(sockfd);
    printf("Received byte: %d\n", total);
    return 1;
}

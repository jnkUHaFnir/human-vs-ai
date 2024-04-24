int recv_all(int sockfd, char *buf, int len)
{
    ssize_t n = 0;
    ssize_t total = 0;

    while (total < len)
    {
        n = recv(sockfd, buf + total, len - total, 0);
        if (n <= 0)
            return n;
        
        total += n;
    }

    return total;
}

int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int b;
    char buffer[BUFFER_SIZE];
    int total = 0;

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, len)) > 0)
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

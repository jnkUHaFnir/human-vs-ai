int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, len)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
            memset(buffer, 0, BUFFER_SIZE); // Clear the buffer for the next read
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

int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while (1)
        {
            b = recv_all(sockfd, buffer, len);
            if (b <= 0)
                break;

            total += b;
            fwrite(buffer, 1, b, fp);
        }

        if (b < 0)
            perror("Receiving");

        printf("Received bytes: %d\n", total);

        fclose(fp);
    }
    else
    {
        perror("File");
    }
    close(sockfd);
}

int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while (total < len)
        {
            b = recv_all(sockfd, buffer, BUFFER_SIZE);
            if (b <= 0)
                break;
            total += b;
            fwrite(buffer, 1, b, fp);
        }

        printf("Received byte: %d\n",total);
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

int recv_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, BUFFER_SIZE)) != 1)
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
memset(fname, 0, sizeof(fname));

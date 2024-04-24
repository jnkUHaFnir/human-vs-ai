int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        do {
            b = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (b < 0) {
                perror("Error while receiving file");
                break;
            }
            fwrite(buffer, 1, b, fp);
            total += b;
        } while (b > 0);

        printf("Received bytes: %d\n", total);

        fclose(fp);
    }
    else
    {
        perror("Error while creating file");
    }
    close(sockfd);
}
int send_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int b;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
        {
            if (send_all(sockfd, buffer, b) < 0)
            {
                perror("Error while sending file");
                break;
            }
        }

        fclose(fp);
        return 1;
    }
    else
    {
        perror("Error while opening file");
        return 0;
    }
}

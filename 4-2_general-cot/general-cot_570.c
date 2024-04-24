// Adjust the loop and file writing logic in recv_txt_file function
int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while ((b = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
            memset(buffer, '\0', BUFFER_SIZE);
        }

        if (b < 0)
            perror("Receiving");

        printf("Received total bytes: %d\n", total);

        fclose(fp);
    }
    else
    {
        perror("File");
    }
    close(sockfd);
}
// Modify the send_txt_file function to send actual bytes read from the file
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

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, b) < 0) {
            perror("Sending failed");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

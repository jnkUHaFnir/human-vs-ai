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
            memset(buffer, 0, BUFFER_SIZE); // Clear the buffer for the next read
        }

        if (b < 0)
            perror("Receiving");

        printf("Received byte: %d\n", total);

        fclose(fp);

        // Notify the client that the file upload is completed
        char msg[] = "FILE_UPLOADED";
        send_all(sockfd, msg, sizeof(msg));
    }
    else
    {
        perror("File");
    }
    // close(sockfd); // Close the socket after all communication is complete
}
int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int b;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, b) < 0)
        {
            perror("Sending file content");
            break;
        }
    }

    fclose(fp);

    return 1;
}

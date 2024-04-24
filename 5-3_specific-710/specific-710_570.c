int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
        {
            fwrite(buffer, 1, b, fp);
            total += b;
        }

        printf("Received bytes: %d\n", total);

        if (b < 0)
            perror("Receiving");
        
        fclose(fp);

        // Send acknowledgment to the client
        const char *ack = "FILE_UPLOADED";
        send_all(sockfd, ack, strlen(ack));
    }
    else
    {
        perror("File");
    }

    close(sockfd);
}

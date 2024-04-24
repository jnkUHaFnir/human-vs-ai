int recv_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("File opening error");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = 0;
    int total_received = 0;

    while((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, fp);
        total_received += bytes_received;

        // If a signal to end transmission is received, break
        if (bytes_received < BUFFER_SIZE)
        {
            break; // Assuming the end of file content
        }
    }

    if (bytes_received < 0)
    {
        perror("Receiving error");
    }

    printf("Total bytes received: %d\n", total_received);
    fclose(fp);
    return bytes_received < 0 ? -1 : 0;
}
int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("File opening error");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0)
    {
        if (send_all(sockfd, buffer, bytes_read) == -1)
        {
            perror("Send error");
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return 0;
}

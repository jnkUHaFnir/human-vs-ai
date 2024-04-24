int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while (total < len) // Continue reading until total reaches the length of the file
        {
            b = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (b <= 0) {
                if (b < 0) perror("Error while receiving file");
                break;
            }
            total += b;
            fwrite(buffer, 1, b, fp);
            memset(buffer, '\0', BUFFER_SIZE);
        }

        printf("Received byte: %d\n", total);

        fclose(fp);
    }
    else
    {
        perror("Error while opening file");
    }
    close(sockfd);
}
if (strcmp(buffer, "SENDFILE_TXT\n") == 0) // No need for extra parentheses
{
    printf("-------FROM CLIENT: %s-------\n", buffer);
    memset(buffer, '\0', BUFFER_SIZE);
    strcpy(buffer, "OK\n"); // Add a newline character here
    if (send_all(client_fd, buffer, BUFFER_SIZE) < 0)
    {
        perror("Client write failed");
        break;
    }
    // ... rest of the code for receiving the file
}
long int file_size = get_file_size(fname);
if (file_size > 0) {
    send_all(sockfd, (char *)&file_size, sizeof(long int)); // Send the file size to the server
    send_txt_file(sockfd, BUFFER_SIZE, fname); // Send the file content to the server
}

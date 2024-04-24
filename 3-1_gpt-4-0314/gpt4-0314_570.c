// server.c

... // include and other declarations

int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0;
    ssize_t b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, len)) > 0)
        {
            total += b;
            fwrite(buffer, 1, b, fp);
            len -= b;
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

... // rest of the main

    // Inside the while loop

        // place the following line after receiving the filename
        filename[strlen(filename)-1] = 0;

        // remove the memset for buffer
        int file_length;
        sscanf(buffer, "%d", &file_length);
        recv_txt_file(client_fd, file_length, filename);

// client.c

... // include and other declarations

int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int b = 0, sent = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp == NULL)
    {
        perror("Error while openning file");
        return 0;
    }

    while ((b = fread(buffer, 1, (sent + BUFFER_SIZE <= len) ? BUFFER_SIZE : len - sent, fp)) > 0)
    {
        send_all(sockfd, buffer, b);
        memset(buffer, '\0', BUFFER_SIZE);
        sent += b;
    }

    fclose(fp);
    return 1;
}

... // rest of the main

        // Inside the while loop

            // place the following line after receiving the filename
            fname[strlen(fname)-1] = 0;

            int file_size = get_file_size(fname);
            sprintf(buffer, "%d", file_size);
            send_all(sockfd, buffer, BUFFER_SIZE);
            err = recv_all(sockfd, buffer, BUFFER_SIZE);

          send_txt_file(sockfd, fname);

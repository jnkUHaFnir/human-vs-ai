int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int b;
    long int file_size;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    // Get the file size
    file_size = get_file_size(filename);

    // Send the file size to the server
    send(sockfd, &file_size, sizeof(file_size), 0);

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        send_all(sockfd, buffer, b);
        memset(buffer, '\0', BUFFER_SIZE);
    }

    fclose(fp);
    return 1;
}

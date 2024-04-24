int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Send filesize
    send(sockfd, &filesize, sizeof(filesize), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    int bytes_read;

    while ( (bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0){
        send_all(sockfd, buffer, bytes_read);
    }

    fclose(fp);
    return 1;
}
int recv_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    // Receive filesize
    int filesize;
    recv(sockfd, &filesize, sizeof(filesize), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    int bytes_received = 0;
    int bytes_read;

    while ( filesize > 0 && (bytes_read = recv(sockfd, buffer, sizeof(buffer), 0)) > 0 ){
        fwrite(buffer, 1, bytes_read, fp);
        filesize -= bytes_read;
    }

    fclose(fp);
    return 1;
}

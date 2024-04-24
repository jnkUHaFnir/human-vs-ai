int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        if (send_all(sockfd, buffer, bytes_read) < 0)
        {
            perror("Error while sending file data");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

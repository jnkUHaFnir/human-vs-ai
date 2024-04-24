int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (fp != NULL)
    {
        long int file_size = -1;
        do {
            b = recv_all(sockfd, buffer, BUFFER_SIZE);
            if (b < 0) {
                perror("Receiving");
                break;
            }
            total += b;
            fwrite(buffer, 1, b, fp);

            // if we don't know the file size yet, try to get it from the received data
            if (file_size < 0) {
                file_size = get_file_size(filename);
                if (file_size >= 0) {
                    printf("Expecting file of size %ld bytes\n", file_size);
                }
            }
        } while (total < file_size);

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

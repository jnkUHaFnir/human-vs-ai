int recv_txt_file(int sockfd, long int file_size, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while (total < file_size)
        {
            b = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (b < 0)
            {
                perror("Receiving");
                break;
            }
            total += b;
            fwrite(buffer, 1, b, fp);
        }

        printf("Received %ld bytes\n", total);

        fclose(fp);
    }
    else
    {
        perror("File");
    }
    close(sockfd);

    return total == file_size ? 1 : 0;
}
memset(buffer, BUFFER_SIZE, '\0');
memset(fname, BUFFER_SIZE, '\0');
memset(buffer, '\0', BUFFER_SIZE);
memset(fname, '\0', BUFFER_SIZE);
memset(buffer, BUFFER_SIZE, '\0');
memset(filename, BUFFER_SIZE, '\0');
memset(buffer, '\0', BUFFER_SIZE);
memset(filename, '\0', BUFFER_SIZE);

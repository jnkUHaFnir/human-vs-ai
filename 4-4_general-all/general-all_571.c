int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        while ((b = recv_all(sockfd, buffer, BUFFER_SIZE)) > 0) {
            fwrite(buffer, 1, b, fp);
            total += b;
            if (b < BUFFER_SIZE) {
                // Reached end of file
                break;
            }
        }

        if (b < 0) {
            perror("Receiving");
        }

        printf("Received bytes: %d\n", total);
        fclose(fp);
    }
    else
    {
        perror("File");
    }
    close(sockfd);
    return 1;
}

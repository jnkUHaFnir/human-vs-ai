int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, b = 0;
    char buffer[BUFFER_SIZE];

    if (fp != NULL)
    {
        do {
            b = recv_all(sockfd, buffer, BUFFER_SIZE);
            if (b == 0) {
                break; // EOF reached
            } else if (b < 0) {
                perror("Receiving");
                break;
            }
            total += b;
            fwrite(buffer, 1, b, fp);
        } while (1);

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

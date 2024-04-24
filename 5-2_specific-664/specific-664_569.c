int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("File");
        return 0;
    }

    int total = 0;
    char buffer[BUFFER_SIZE];

    while (len > 0) {
        int b = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (b <= 0) {
            if (b < 0)
                perror("Receiving");
            break;
        }

        total += b;
        fwrite(buffer, 1, b, fp);

        len -= b;
    }

    printf("Received bytes: %d\n", total);

    fclose(fp);
    close(sockfd);
    return 1;
}

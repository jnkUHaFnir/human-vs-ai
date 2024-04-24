int send_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int b;
    char buffer[BUFFER_SIZE];

    if (fp == NULL)
    {
        perror("Error while opening file");
        return 0;
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0){
        if (send_all(sockfd, buffer, b) < 0) {
            perror("Error while sending file");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}
send_txt_file(sockfd, fname); // Pass 'b' instead of 'BUFFER_SIZE'

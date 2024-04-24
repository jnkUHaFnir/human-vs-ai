int recv_txt_file(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];
    if (fp != NULL) {
        int bytesToRead;
        recv(sockfd, (char*)&bytesToRead, sizeof(bytesToRead), 0); // Assumes the client sends file size first
        printf("Receiving file of size: %d bytes\n", bytesToRead);

        while (bytesToRead > 0 && (b = recv(sockfd, buffer, min(BUFFER_SIZE, bytesToRead), 0)) > 0) {
            fwrite(buffer, 1, b, fp);
            bytesToRead -= b;
            total += b;
        }
        
        printf("Received byte: %d\n", total);
        if (b < 0) perror("Receiving");
        fclose(fp);
    } else {
        perror("File");
    }
    // Don't close(socketfd) here if you expect more communications after file transfer
}
int send_txt_file(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    char buffer[BUFFER_SIZE];

    if (fp == NULL) {
        perror("Error opening file");
        return 0;
    }

    // Send file size first
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    send(sockfd, (char*)&fileSize, sizeof(fileSize), 0);

    // Then send file content
    int b;
    while ((b = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        send_all(sockfd, buffer, b);
    }
    fclose(fp);
    return 1;
}

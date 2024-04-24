int recv_txt_file(int sockfd, long int file_size, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    int total = 0, b;
    char buffer[BUFFER_SIZE];

    if (fp != NULL) {
        while (total < file_size) {
            b = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (b <= 0) {
                fprintf(stderr, "Error receiving file data\n");
                fclose(fp);
                return -1;
            }
            total += b;
            fwrite(buffer, 1, b, fp);
        }

        printf("Received bytes: %d\n", total);

        fclose(fp);
        return 1;
    } else {
        perror("File");
        return -1;
    }
}
    // Receive file size from the client
    long int file_size;
    if (recv(client_fd, &file_size, sizeof(file_size), 0) <= 0) {
        fprintf(stderr, "Error receiving file size\n");
        break;
    }

    // Confirm file size received
    int ok = 1;
    send(client_fd, &ok, sizeof(ok), 0);

    // Receive file content
    if (recv_txt_file(client_fd, file_size, filename) < 0) {
        fprintf(stderr, "Error receiving file\n");
        break;
    }
int send_txt_file(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "r");
    long int file_size;
    char buffer[BUFFER_SIZE];

    if (fp == NULL) {
        perror("Error while opening file");
        return -1;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Send file size to server
    send(sockfd, &file_size, sizeof(file_size), 0);

    // Wait for server confirmation
    int confirm;
    if (recv(sockfd, &confirm, sizeof(confirm), 0) <= 0) {
        fprintf(stderr, "Error receiving confirmation\n");
        fclose(fp);
        return -1;
    }

    // Send file content
    while (!feof(fp)) {
        size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);
        send(sockfd, buffer, bytes_read, 0);
    }

    fclose(fp);
    return 1;
}

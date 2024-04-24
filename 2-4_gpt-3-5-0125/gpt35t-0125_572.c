long int file_size = get_file_size(filename);
if (file_size < 0) {
    printf("Error getting file size\n");
    return 1;
}
if (send(sockfd, &file_size, sizeof(file_size), 0) < 0) {
    perror("Error sending file size");
    return 1;
}

while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
    send_all(sockfd, buffer, b);
    memset(buffer, '\0', BUFFER_SIZE);
}
long int file_size;
if (recv(client_fd, &file_size, sizeof(file_size), 0) < 0) {
    perror("Error receiving file size");
    return 0;
}

... // Continue with receiving file content as before

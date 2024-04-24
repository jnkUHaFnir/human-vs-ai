// Server pseudo-code for handling reads with a message length prefix
int read_message_length(int sockfd) {
    int length;
    // Read the fixed-size length prefix first
    // This assumes an integer is used to specify the length (4 bytes)
    // Error handling omitted for brevity
    read(sockfd, &length, sizeof(length));
    // Convert to host byte order, if necessary
    length = ntohl(length);
    return length;
}

void read_message(int sockfd, int length) {
    char* buffer = malloc(length + 1); // Allocate buffer based on length
    read(sockfd, buffer, length); // Read the message
    buffer[length] = '\0'; // Null-terminate the string
    // Now buffer contains the whole message of 'length' bytes
    printf("Received: %s\n", buffer);
    free(buffer);
}

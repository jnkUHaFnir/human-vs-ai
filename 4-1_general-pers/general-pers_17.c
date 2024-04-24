// Server.c

int n = 0;
while ((n = read(newsockfd, buffer, 255)) > 0) {
    buffer[n] = '\0'; // Null-terminate the received string
    printf("Here is the message: %s\n", buffer);

    // Process the message if needed

    n = write(newsockfd, "Received your message", 20);
    if (n < 0) {
        error("ERROR writing to socket");
    }
}

if (n < 0) {
    error("ERROR reading from socket");
}
// Client.c

printf("Please enter the message: ");
if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    error("Failed to read message");
}
size_t len = strlen(buffer);
if (len > 0 && buffer[len - 1] == '\n') {
    buffer[--len] = '\0'; // Remove the newline character if present
}

n = write(sockfd, buffer, len);
if (n < 0) {
    error("ERROR writing to socket");
}

if (n > 0) {
    printf("(Message length %d) message from Client: %s\n", n, buffer);
    if (strcmp("q", buffer) == 0) {
        printf("The client is trying to close the connection\n");
        close(socketfd);
        close(newsocketfd);
        break; // Exit the loop when the client wants to close the connection
    } else {
        printf("Data received from the client: %s\n", buffer);
    }
} else {
    close(socketfd);
    close(newsocketfd);
    error("Error reading message \n");
}

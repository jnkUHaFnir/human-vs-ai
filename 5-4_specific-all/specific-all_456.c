while(1){
    if((n = read(newsocketfd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0'; // Null terminate the received message
        printf("(Message length %d) Message from Client: %s\n", n, buffer);

        if(strcmp("q", buffer) == 0) {
            printf("Client is trying to close the connection\n");
            break; // Exit the loop if client sends "q"
        } else {
            printf("Data received from the client: %s\n", buffer);
        }

        if(write(newsocketfd, response, strlen(response)) > 0) {
            printf("Writing response to Client socket\n");
        } else {
            error("Error writing message\n");
        }
    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message\n");
    }
}
do {
    printf("Please type your message: ");
    fgets(buffer, 255, stdin);

    // Remove the newline character at the end of the input
    buffer[strcspn(buffer, "\n")] = 0;

    n = write(socketfd, buffer, strlen(buffer));
    if(n < 0) {
        error("Error writing to socket\n");
    } else {
        printf("Message sent\n");
    }

    n = read(socketfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        error("Error reading from socket\n");
    } else {
        buffer[n] = '\0'; // Null terminate the received message
        printf("\nMessage from server: %s\n", buffer);
    }
} while (strcmp("q", buffer) != 0);

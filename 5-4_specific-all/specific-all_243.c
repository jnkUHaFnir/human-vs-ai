while(1){
    if((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
        buffer[n - 1] = '\0'; // Remove the newline character
        printf("(Message length %d) Message from Client: %s\n", n, buffer);
    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message\n");
    }

    if(strcmp("q", buffer) == 0) {
        printf("Client is trying to close the connection: %s\n", buffer);
        break; // Exit the loop when client sends "q"
    } else {
        printf("Data received from the client: %s\n", buffer);
    }

    if(write(newsocketfd, response, 255) > 0) {
        printf("Writing response to Client socket\n");
    } else {
        error("Error writing message\n");
    }
}

return EXIT_SUCCESS;
do {
    printf("Please, type your message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    n = write(socketfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket\n");
    } else {
        printf("Message sent\n");

        n = read(socketfd, buffer, sizeof(buffer));
        if (n < 0) {
            error("Error reading from socket\n");
        } else {
            printf("\nMessage from server: %s\n", buffer);
        }
    }
} while (strcmp("q\n", buffer) != 0); // Compare with "q\n" to account for newline


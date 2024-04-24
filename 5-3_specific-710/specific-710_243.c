while(1) {

    if((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
        buffer[n] = '\0'; // Add null terminator to properly terminate the string
        printf("(Message length %d) message from Client:  %s\n", n, buffer);

        if(strcmp("q", buffer) == 0) {
            printf("Client wants to close the connection: %s\n", buffer);
            break; // Break out of the loop to close the connection
        } else {
            printf("Data received from the client: %s\n", buffer);
        }

    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message\n");
    }

    if(write(newsocketfd, response, strlen(response)) > 0)
        printf("Writing response to Client socket\n");
    else
        error("Error writing message\n");

}

return EXIT_SUCCESS;
do {
    printf("Please, type your message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    // Find the length of the actual message entered by the user
    size_t msg_len = strlen(buffer);

    n = write(socketfd, buffer, msg_len);
    if (n < 0) {
        error("Error writing to socket\n");
        break;
    } else {
        printf("...Message sent\n");
    }

    n = read(socketfd, buffer, 255);
    if (n < 0) {
        error("Error reading from socket\n");
        break;
    } else {
        buffer[n] = '\0'; // Add null terminator to properly terminate the string
        printf("\nMessage from server: %s\n", buffer);
    }

} while (strcmp("q", buffer) != 0);

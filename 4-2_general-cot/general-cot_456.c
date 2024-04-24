while(1){
    if((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
        printf("(Message length %d) Message from Client: %s\n", n, buffer);
        if(buffer[0] == 'q') {
            printf("Client wants to close the connection: %s\n", buffer);
            break; // Exit the loop to close connection
        }
        else {
            printf("Data received from the client: %s\n", buffer);
        }
    }
    else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message \n");
    }

    if(write(newsocketfd, response, 255) > 0) {
        printf("Writing response to Client socket\n");
    }
    else {
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
        printf("...Message sent\n");
    }

    n = read(socketfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("Error reading from socket\n");
    } else {
        printf("\nMessage from server: %s\n", buffer);
    }
} while (buffer[0] != 'q');


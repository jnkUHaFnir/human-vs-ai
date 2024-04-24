while(1){
    if((n = read(newsocketfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';  // Null terminate the received message
        printf("(Message length %d) message from Client: %s\n", n, buffer);

        if(strcmp("q", buffer) == 0) {
            printf("Client wants to close the connection: %s\n", buffer);
            close(socketfd);
            close(newsocketfd);
            break; // Exit the loop to close the connection
        } else {
            printf("Received data from the client: %s\n", buffer);
        }

        if(write(newsocketfd, response, sizeof(response)) > 0) {
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

return EXIT_SUCCESS;

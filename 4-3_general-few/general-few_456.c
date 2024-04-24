while(1){
    if((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
        buffer[n] = '\0'; // Null-terminate the string
        printf("(Message length %d) Message from Client: %s\n", n, buffer);

        if (strcmp("q", buffer) == 0) {
            printf("Client is trying to close the connection\n");
            break; // Break out of the loop to close the connection
        } else {
            printf("Data received from the client %s\n", buffer);
        }

        if (write(newsocketfd, response, strlen(response)) > 0) {
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


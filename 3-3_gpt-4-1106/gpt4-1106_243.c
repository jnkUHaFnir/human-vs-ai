while (1) {
    n = read(newsocketfd, buffer, sizeof(buffer) - 1); // Leave space for null terminator
    if (n > 0) {
        buffer[n] = '\0'; // Null terminate the received data
        printf("(Mlength %d) message from Client:  %s\n", n, buffer);
    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message \n");
    }

    // Check if the first character is 'q' and followed by either a newline or nothing else.
    if (buffer[0] == 'q' && (buffer[1] == '\n' || buffer[1] == '\0')) {
        printf("El cliente intenta cerrar la conexión %s\n", buffer);
        break; // Exit the loop and close connections
    } else {
        printf("Se recibieron datos desde el cliente %s\n", buffer);
    }

    // Send response to the client
    if (write(newsocketfd, response, 255) <= 0) {
        error("Error writing message \n");
    } else {
        printf("Writing response to Client socket \n");
    }
}

// Don't forget to close the sockets when done
close(newsocketfd);
close(socketfd);

return EXIT_SUCCESS;
do {
    printf("Please, type your message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    // Remove newline character at the end of the string
    buffer[strcspn(buffer, "\n")] = '\0';

    n = write(socketfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket \n");
    } else {
        printf("...Message sent \n");
    }

    n = read(socketfd, buffer, sizeof(buffer) - 1); // Leave space for null terminator
    if (n < 0) {
        error("Error writing to socket \n");
    } else {
        buffer[n] = '\0'; // Null terminate the received data
        printf("\n Message from server: %s \n", buffer);
    }

} while (strcmp("q", buffer) != 0);

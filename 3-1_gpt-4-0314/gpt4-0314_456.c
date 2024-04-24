while (1) {
    bzero(buffer, 256);
    if ((n = read(newsocketfd, buffer, sizeof(buffer) - 1)) > 0) {
        printf("(Mlength %d) message from Client:  %s\n", n, buffer);
    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message\n");
    }

    if (strcmp("q\n", buffer) == 0) {
        printf("El cliente intenta cerrar la conexión %s\n", buffer);
        break;
    } else {
        printf("Se recibieron datos desde el cliente %s\n", buffer);
    }

    if (write(newsocketfd, response, 255) > 0)
        printf("Writing response to Client socket \n");
    else
        error("Error writing message \n");
}

close(socketfd);
close(newsocketfd);
return EXIT_SUCCESS;
do {
    // Prompt and read message
    printf("Please, type your message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    // Send message
    n = write(socketfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket\n");
    else
        printf("...Message sent\n");

    // Read server response
    memset(buffer, 0, sizeof(buffer));
    n = read(socketfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        error("Error reading from socket\n");
    } else {
        printf("\nMessage from server: %s\n", buffer);
    }

} while (strcmp("q\n", buffer) != 0);


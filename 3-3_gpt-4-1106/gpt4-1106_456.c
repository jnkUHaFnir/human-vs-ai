while(1) {
    // Clear the buffer before using it.
    bzero(buffer, sizeof(buffer));

    // Read data from the client.
    n = read(newsocketfd, buffer, sizeof(buffer) - 1); // -1 to leave space for '\0'
    if (n > 0) {
        printf("(Mlength %d) Message from Client: %s\n", n, buffer);
        buffer[n] = '\0'; // Null-terminate the string received.
    } else {
        close(newsocketfd); // Close the connection if read failed.
        error("Error reading message \n");
        break; // Break out of the loop so the server stops looping.
    }

    // Compare the buffer to the exit command "q".
    if (strcmp(buffer, "q") == 0) { // Compare "q" to the start of the buffer.
        printf("El cliente intenta cerrar la conexión %s\n", buffer);
        close(newsocketfd); // Handle the exit operation or close connection.
        break; // If you want to exit the loop after the client sends "q".
    } else {
        printf("Se recibieron datos desde el cliente %s\n", buffer);
    }

    // Write a response back to the client.
    if (write(newsocketfd, response, strlen(response)) < 0) {
        error("Error writing message \n");
        close(newsocketfd); // Close the connection since write failed.
        break; // Again, consider breaking out of the loop.
    }
}
do {
    printf("Please, type your message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    // Send only the text that was entered, up to and including the newline.
    n = write(socketfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket \n");
        break; // Exit the loop in case of error.
    } else {
        printf("...Message sent \n");
    }

    bzero(buffer, 256); // Clear the buffer before reading the response.
    n = read(socketfd, buffer, 255); // Read the server's response.
    if (n < 0) {
        error("Error reading from socket \n");
        break; // Exit the loop in case of error.
    } else {
        printf("\nMessage from server: %s\n", buffer);
    }
} while (strcmp(buffer, "q\n") != 0); // Since fgets() includes the newline, we compare with "q\n".

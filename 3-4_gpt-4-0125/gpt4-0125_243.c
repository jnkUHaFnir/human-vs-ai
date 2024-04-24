while(1){
    bzero(buffer, sizeof(buffer)); // Clearing the buffer to avoid garbage from previous messages
    n = read(newsocketfd, buffer, sizeof(buffer)-1);  // Reading one less than the size to leave room for null terminator
    if(n > 0) {
        buffer[n] = '\0'; // Ensure the string is null-terminated
        printf("(Mlength %d) message from Client: %s\n", n, buffer);
    } else{
        close(socketfd);
        close(newsocketfd);
        error("Error reading message \n");
    }

    if(strcmp("q", buffer) == 0) {
        printf("El cliente intenta cerrar la conexión %s\n", buffer);
        break; // Assuming you want to break the loop and close on 'q'
    } else {
        printf("Se recibieron datos desde el cliente %s\n", buffer);
    }

    // Your response logic...
}

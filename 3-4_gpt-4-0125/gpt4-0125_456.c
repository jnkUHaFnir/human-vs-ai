// Ensure the buffer is null-terminated to avoid reading garbage.
buffer[n] = '\0';

// Compare the whole buffer with "q". Assuming you want to close on single "q" message.
if(strcmp(buffer, "q") == 0) {
    printf("El cliente intenta cerrar la conexión\n");
    // Here you could break out of the loop to clean up and close connections.
    break; // Assuming this is part of a loop, you would break out here.
} else {
    printf("Se recibieron datos desde el cliente: %s\n", buffer);
}
// Assume buffer has been defined
n = read(socketfd, buffer, sizeof(buffer) - 1);
if (n < 0) {
    error("Error reading from socket \n");
} else {
    buffer[n] = '\0'; // Null-terminate the string
    printf("\nMessage from server: %s\n", buffer);
}
// Continue with the comparison and loop...

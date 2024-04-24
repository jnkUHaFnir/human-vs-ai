while (1) {
    client_len[socket_index] = sizeof(client_address[socket_index]);
    puts("waiting for client");
    client_sockfd[socket_index] = accept(server_sockfd, (struct sockaddr*)&client_address[socket_index], &client_len[socket_index]);
    if (client_sockfd[socket_index] < 0) {
        perror("Cannot accept connection\n");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    pthread_create(&threads[socket_index], NULL, forClient, (void*)client_sockfd[socket_index]);

    if (BUFSIZ == socket_index) {
        socket_index = 0;
    } else {
        ++socket_index;
    }
}
void sigint_handler(int signo) {
    if (signo == SIGINT) {
        // Handle SIGINT signal
        // For example, set a global flag to stop the while loop in your main function
        printf("SIGINT received. Exiting...\n");
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Other code

    // Register SIGINT handler
    signal(SIGINT, sigint_handler);

    // Main loop
    while (1) {
        // Your main loop code here
    }

    // Other cleanup code
}

while (1) {
    client_len[socket_index] = sizeof(client_address[socket_index]);
    puts("waiting for client");
    client_sockfd[socket_index] = accept(
                           server_sockfd,
                           (struct sockaddr*)&client_address[socket_index],
                           &client_len[socket_index]
                           );
    if (client_sockfd[socket_index] < 0) {
        perror("Cannot accept connection\n");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    pthread_create(&threads[socket_index], NULL, forClient, (void*)client_sockfd[socket_index]);

    if(BUFSIZ == socket_index) {
        socket_index = 0;
    } else {
        ++socket_index;
    }
}
volatile sig_atomic_t sigint_received = 0;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        sigint_received = 1;
        printf("!!  OUCH,  CTRL - C received on client  !!\n");
    }
}

int main(int argc, char **argv) {
    // Other code

    signal(SIGINT, sig_handler);

    while (!sigint_received) {
        // Main client code loop
        // Handle user input, send/receive data, etc.
    }

    // Cleanup and exit code

    return 0;
}

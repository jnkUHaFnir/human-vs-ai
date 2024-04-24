void* forClient(void* ptr) {
    int connect_socket = (int)ptr;
    // Handle client request here
    close(connect_socket); // Close the socket when done
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Initialize variables and create socket

    while (1) {
        // Accept client connection

        // Create a thread for the client
        pthread_create(&threads[socket_index], NULL, forClient, (void*)client_sockfd[socket_index]);

        if (BUFSIZ == socket_index) {
            socket_index = 0;
        } else {
            ++socket_index;
        }
    }

    // Join threads outside the loop
    for (int i = 0; i < BUFSIZ; ++i) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!! OUCH, CTRL-C received on client !!\n");
        // Clean up resources and exit gracefully
        // Close sockets, free allocated memory, etc.
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Set up signal handler
    signal(SIGINT, sig_handler);

    // Main code logic

    return EXIT_SUCCESS;
}

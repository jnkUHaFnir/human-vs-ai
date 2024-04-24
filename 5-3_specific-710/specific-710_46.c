// Move pthread_join outside the loop
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

    if (BUFSIZ == socket_index) {
        socket_index = 0;
    } else {
        ++socket_index;
    }
}

// Correct implementation of forClient function
void* forClient(void* ptr) {
    int connect_socket = (int) ptr;
    int filefd;
    // other variable declarations

    // Thread number means client's id
    printf("Thread number %ld\n", pthread_self());
    pthread_mutex_lock(&mutex1);

    // Critical section for receiving and saving file
    // Additional error handling and file closing logic

    pthread_mutex_unlock(&mutex1);

    fprintf(stderr, "Client dropped connection\n");
    close(connect_socket);
    pthread_exit(NULL);
}
// Set up signal handler to handle SIGINT
void sigint_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH, CTRL-C received on client !!\n");
        // Perform cleanup operations if needed
        exit(EXIT_SUCCESS);
    }
}

// In the main function
int main(int argc, char **argv) {
    // Other variable declarations

    // Set up signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    // Rest of the client code
}

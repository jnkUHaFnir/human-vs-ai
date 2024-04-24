void* forClient(void* ptr) {
    int connect_socket = (int) ptr;
    ssize_t read_return;
    char buffer[BUFSIZ];
    char receiveFileName[BUFSIZ];

    // Thread number means client's id
    printf("Thread number %ld\n", pthread_self());
    pthread_mutex_lock(&mutex1);

    // Receive the file path from the client
    while (recv(connect_socket, receiveFileName, sizeof(receiveFileName), 0)) {
        char *file_path = receiveFileName;

        fprintf(stderr, "Received file name: %s\n", file_path);

        int filefd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (filefd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        do {
            read_return = read(connect_socket, buffer, BUFSIZ);
            if (read_return == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            if (write(filefd, buffer, read_return) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        } while (read_return > 0);

        close(filefd);
    }

    pthread_mutex_unlock(&mutex1);
    fprintf(stderr, "Client dropped connection\n");
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Initialization code

    while (1) {
        // Accept client connection and create a new thread
        // Inside the loop
    }

    // Move pthread_join outside the loop

    return EXIT_SUCCESS;
}
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH, CTRL - C received !!\n");
        // Clean up or perform any necessary actions before exiting
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Initialization code

    // Register the signal handler
    signal(SIGINT, sig_handler);

    while (1) {
        // Main loop code
    }

    // Cleanup and close sockets before exiting

    return EXIT_SUCCESS;
}

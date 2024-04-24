#include <pthread.h>
#include <signal.h>
#include <stdbool.h>

// Global variables and data structures
typedef struct client_info {
    int sockfd;
    pthread_t thread_id;
} client_info;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
bool server_running = true;

// The signal handler is now setting the global server_running variable to false.
// When the server receives SIGINT, it will exit the main loop and do the cleanup.
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received  by server !!\n");
        server_running = false;
    }
}

// ...

int main(int argc, char **argv) {

    // ...

    signal(SIGINT, sig_handler);

    // We now use a dynamic array for client connections and threads.
    client_info *clients = NULL;
    int num_clients = 0;

    while (server_running) {
        // ...

        // Reallocate and add a new client to the array
        clients = realloc(clients, sizeof(client_info) * (num_clients + 1));
        clients[num_clients].sockfd = client_sockfd[socket_index];
        pthread_create(
                &clients[num_clients].thread_id, NULL, forClient,
                (void *)(long)clients[num_clients].sockfd);
        ++num_clients;

    }

    // Do the cleanup: close sockets and join threads
    for (int i = 0; i < num_clients; ++i) {
        close(clients[i].sockfd);
        pthread_join(clients[i].thread_id, NULL);
    }
    free(clients);
    close(server_sockfd);

    return EXIT_SUCCESS;
}
int main(int argc, char **argv) {

    // ...

    while (1) {

        signal(SIGINT, sig_handler);

        // ...

        // Fixed the problem with scanf by using fgets and strtol to read the user input
        char input_buffer[32];
        fgets(input_buffer, sizeof input_buffer, stdin);
        select = (int)strtol(input_buffer, NULL, 10);

        // ...

        // When the client wants to exit the application, it breaks the while loop
        case 5:
            break;
    }

    // Clean up and exit
    close(sockfd);
    exit(EXIT_SUCCESS);
}

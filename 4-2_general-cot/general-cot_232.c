#include <signal.h>
volatile sig_atomic_t stop = 0;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received by server !!\n");
        stop = 1;
    }
}

int main(int argc, char **argv) {
    // Existing code ...

    // Setup SIGINT signal handler
    signal(SIGINT, sig_handler);

    while (!stop) {
        // Accept client connection and create a thread
        pthread_create(&threads[socket_index], NULL, forClient, (void*)(intptr_t)client_sockfd[socket_index]);
        socket_index = (socket_index + 1) % BUFSIZ;
    }

    // Close all client connections before exiting
    for (int i = 0; i < BUFSIZ; i++) {
        if (client_sockfd[i] != -1) {
            close(client_sockfd[i]);
        }
    }

    return EXIT_SUCCESS;
}
void sig_handler(int signo) {
    if (signo == SIGINT)
        printf("!!  OUCH,  CTRL - C received on client  !!\n");
}

int main(int argc, char **argv) {
    // Existing code ...

    signal(SIGINT, sig_handler);

    while (1) {
        printf("---------------------\n");
        printf("|1 - listLocal|\n|2 - listServer|\n|3 - sendFile|\n|4 - help|\n|5 - exit|\n");
        printf("---------------------\n");

        scanf("%d", &select);

        switch (select) {
            // Existing cases...

            case 5:
                free(user_input);
                free(server_reply);
                close(sockfd); // Close socket before exiting
                exit(EXIT_SUCCESS);

            default:
                puts("Wrong selection!");
                break;
        }
    }

    free(user_input);
    free(server_reply);
    close(sockfd); // Close socket before exiting
    exit(EXIT_SUCCESS);
}

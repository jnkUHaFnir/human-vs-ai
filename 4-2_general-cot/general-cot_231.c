#include <signal.h>

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received  by server !!\n");
        // Close server socket and free resources gracefully
        close(server_sockfd);
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Other code remains the same

    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = sig_handler;
    sigaction(SIGINT, &action, NULL);

    while (1) {
        // Accepting clients and handling connections
        // pthread_create and pthread_join
    }

    // Close server socket and free resources
    close(server_sockfd);
    return EXIT_SUCCESS;
}
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received on client !!\n");
        // Close client socket and free resources gracefully
        close(sockfd);
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Other code remains the same

    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = sig_handler;
    sigaction(SIGINT, &action, NULL);

    while (1) {
        // Main client functionality with signal handling
    }

    // Close client socket and free resources
    close(sockfd);
    return EXIT_SUCCESS;
}

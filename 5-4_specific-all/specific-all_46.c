#include <signal.h>

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received  !!\n");
        // Clean up and exit gracefully
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Set up signal handler
    signal(SIGINT, sig_handler);
    
    // Your existing code
}
while (1) {
    // Accept client connection and create thread

    // Join threads outside the loop
    for (int i = 0; i < socket_index; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Close client connections
}

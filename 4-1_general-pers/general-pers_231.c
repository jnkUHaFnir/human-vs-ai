#include <signal.h>

volatile sig_atomic_t flag = 0;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        flag = 1;
    }
}

int main(int argc, char **argv) {
    // existing code
    
    signal(SIGINT, sig_handler);
    
    while (1) {
        // existing code
        
        if (flag) {
            fprintf(stderr, "Server received SIGINT. Cleaning up and exiting...\n");
            close(server_sockfd);
            exit(EXIT_SUCCESS);
        }
    }
    return EXIT_SUCCESS;
}
#include <signal.h>

volatile sig_atomic_t flag = 0;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        flag = 1;
    }
}

int main(int argc, char **argv) {
    // existing code
    
    signal(SIGINT, sig_handler);
    
    while (1) {
        // existing code
        
        if (flag) {
            fprintf(stderr, "Client received SIGINT. Cleaning up and exiting...\n");
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
    }
    return EXIT_SUCCESS;
}

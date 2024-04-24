// Add the following snippet in both server.c and client.c to properly handle SIGINT

#include <signal.h>

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received !!\n");
        // Add any necessary cleanup code here before exiting
        exit(EXIT_SUCCESS); // or handle cleanup and exit gracefully
    }
}

int main(int argc, char **argv) {
    // Other code
    
    // Register SIGINT signal handler
    signal(SIGINT, sig_handler);
    
    // Other code
    
    return EXIT_SUCCESS;
}

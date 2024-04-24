// Include necessary libraries
#include <signal.h> // for signal handling

// Define global variables for signal handling
volatile sig_atomic_t server_running = 1;

// Signal handler for Ctrl-C
void sig_handler(int signo) {
    if (signo == SIGINT) {
        server_running = 0;
        printf("Server received SIGINT. Shutting down...\n");
    }
}

int main(int argc, char **argv) {
    // Existing code remains the same

    signal(SIGINT, sig_handler); // Register signal handler for Ctrl-C

    while (server_running) {
        // Existing code for accepting clients in a loop
    }
}
// Include necessary libraries
#include <signal.h> // for signal handling

// Signal handler for Ctrl-C
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("Client received SIGINT. Exiting...\n");
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Existing code remains the same

    signal(SIGINT, sig_handler); // Register signal handler for Ctrl-C

    // Main client functionality loop
    while (1) {
        // Existing code for client functionality and user input
    }
}

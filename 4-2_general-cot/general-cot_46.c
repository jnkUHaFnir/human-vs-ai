#include <signal.h>

void sigint_handler(int signo) {
    if (signo == SIGINT) {
        printf("SIGINT signal received. Exiting...\n");
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    // Register the signal handler
    signal(SIGINT, sigint_handler);

    // Add this code in both server.c and client.c
    // Replace the existing sig_handler with sigint_handler
    // Also, remove the redundant code related to signals

    // Rest of the code...
}
// Inside the case 3: section of the client.c file
write(sockfd, buffer, 0); // Send an empty message to indicate the end of file

// After sending the file, wait for acknowledgment from the server
char ack_msg[BUFSIZ];
read(sockfd, ack_msg, BUFSIZ);
printf("Server Acknowledgment: %s\n", ack_msg);

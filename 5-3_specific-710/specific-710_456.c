#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, newsocketfd, n;
    char buffer[256];
    char response[256] = "Message received.";

    // Setup your server socket and accept connections

    while (1) {
        if ((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
            buffer[n] = '\0'; // Null-terminate the received message
            printf("(Message length %d) Message from Client: %s\n", n, buffer);

            if (strcmp("q", buffer) == 0) {
                printf("Client is attempting to close the connection: %s\n", buffer);
                break; // Break out of the loop to close the connection
            } else {
                printf("Data received from the client: %s\n", buffer);
            }

            if (write(newsocketfd, response, strlen(response)) > 0) {
                printf("Writing response to Client socket\n");
            } else {
                error("Error writing message\n");
            }
        } else {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message\n");
        }
    }

    close(socketfd);
    close(newsocketfd);

    return EXIT_SUCCESS;
}

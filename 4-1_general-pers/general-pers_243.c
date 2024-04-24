#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, newsocketfd, n;
    char buffer[256];
    char response[] = "Response from server";

    // Server socket initialization, binding, and listening code should come here

    while (1) {
        // Read message from client
        if ((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
            buffer[n] = '\0'; // Null-terminate the received message
            printf("(Message length %d) Message from Client: %s\n", n, buffer);

            if (strcmp("q", buffer) == 0) {
                printf("The client is trying to close the connection: %s\n", buffer);
                break; // Exit the loop to close the connection
            } else {
                printf("Data received from the client: %s\n", buffer);
            }

            // Write response to client
            if (write(newsocketfd, response, strlen(response) + 1) > 0) {
                printf("Writing response to Client socket \n");
            } else {
                error("Error writing message \n");
            }
        } else {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message \n");
        }
    }

    close(socketfd);
    close(newsocketfd);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, newsocketfd;
    char buffer[256];
    char response[256] = "Message received.";

    // Accept and handle connection
    // Assuming socket and newsocket are initialized

    while (1) {
        int n = read(newsocketfd, buffer, sizeof(buffer));
        if (n > 0) {
            printf("(Message length %d) Message from Client: %s\n", n, buffer);

            if (strncmp("q", buffer, 1) == 0) {
                printf("Client tries to close the connection: %s\n", buffer);
                break; // Exit loop if "q" received
            } else {
                printf("Data received from client: %s\n", buffer);
            }

            if (write(newsocketfd, response, strlen(response) + 1) > 0) {
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd;
    char buffer[256];

    // Connect to server
    // Assuming socketfd is initialized and connected to the server

    do {
        printf("Please, type your message: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        int n = write(socketfd, buffer, strlen(buffer) + 1);
        if (n < 0) {
            error("Error writing to socket\n");
        } else {
            printf("...Message sent\n");
        }

        n = read(socketfd, buffer, sizeof(buffer));
        if (n < 0) {
            error("Error reading from socket\n");
        } else {
            printf("\nMessage from server: %s\n", buffer);
        }
    } while (strcmp("q", buffer) != 0);

    close(socketfd);
    return EXIT_SUCCESS;
}

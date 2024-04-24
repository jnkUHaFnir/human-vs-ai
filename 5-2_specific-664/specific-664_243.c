#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {

    char buffer[256];
    int socketfd, newsocketfd, n;
    char response[255] = "Message Received";

    // Initialize your socket and accept connections

    while (1) {
        if ((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
            printf("(Message length %d) Message from Client: %s\n", n, buffer);
            
            buffer[n] = '\0'; // Ensure buffer is null-terminated

            if (strcmp("q", buffer) == 0) {
                printf("Client wants to close the connection: %s\n", buffer);
                break; // Exit the loop to close the connection
            } else {
                printf("Data received from the client: %s\n", buffer);
            }

            if (write(newsocketfd, response, strlen(response)) < 0) {
                error("Error writing message \n");
            } else {
                printf("Writing response to Client socket \n");
            }
        } else {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message \n");
        }
    }

    close(socketfd);
    close(newsocketfd);

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {

    char buffer[256];
    int socketfd, n;

    // Connect to the server

    do {
        printf("Please, type your message: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        n = write(socketfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error writing to socket \n");
        } else {
            printf("...Message sent \n");
        }

        n = read(socketfd, buffer, sizeof(buffer));
        if (n < 0) {
            error("Error reading from socket \n");
        } else {
            printf("\nMessage from server: %s \n", buffer);
        }

    } while (strcmp("q\n", buffer) != 0); // Compare with "q\n" due to newline added by fgets

    close(socketfd);

    return EXIT_SUCCESS;
}

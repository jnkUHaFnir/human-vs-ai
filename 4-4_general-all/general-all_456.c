#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, newsocketfd, n;
    char buffer[256];
    char response[] = "Message received.";

    // Assume socket initialization and connecting with the client

    while (1) {
        if ((n = read(newsocketfd, buffer, sizeof(buffer) - 1)) <= 0) {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message \n");
        }

        buffer[n] = '\0'; // Null-terminate the received message

        if (strcmp("q", buffer) == 0) {
            printf("Client requested to close the connection.\n");
            break; // Exit the loop to close the connection
        } else {
            printf("Received message from the client: %s\n", buffer);

            if (write(newsocketfd, response, strlen(response)) <= 0)
                error("Error writing message \n");
            else
                printf("Response sent to the client.\n");
        }
    }

    close(socketfd);
    close(newsocketfd);

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, n;
    struct sockaddr_in server_addr;
    char buffer[256];

    // Assume socket creation and connecting to the server

    do {
        printf("Please type your message: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        n = write(socketfd, buffer, strlen(buffer));
        if (n < 0)
            error("Error writing to socket\n");
        else
            printf("Message sent.\n");

        n = read(socketfd, buffer, sizeof(buffer) - 1);
        if (n < 0)
            error("Error reading from socket\n");
        else {
            buffer[n] = '\0'; // Null-terminate the received message
            printf("Message from server: %s\n", buffer);
        }

    } while (strcmp("q\n", buffer) != 0); // Note the newline character added here for comparison

    close(socketfd);

    return EXIT_SUCCESS;
}

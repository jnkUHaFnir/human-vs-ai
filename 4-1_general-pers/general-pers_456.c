#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd = /* your socket creation code here */;
    int newsocketfd = /* your accept code here */;
    char buffer[256];
    char response[256] = "Response from server";

    while (1) {
        int n = read(newsocketfd, buffer, sizeof(buffer));
        if (n < 0) {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message \n");
        } else {
            buffer[n] = '\0'; // Ensure the received message is null-terminated
            printf("(Message length %d) Message from Client: %s\n", n, buffer);

            if (strcmp("q", buffer) == 0) {
                printf("Client wants to close the connection: %s\n", buffer);
                break; // Exit the loop to close the connection
            } else {
                printf("Data received from the client: %s\n", buffer);
            }

            if (write(newsocketfd, response, strlen(response)) < 0) {
                error("Error writing response to socket \n");
            } else {
                printf("Writing response to Client socket \n");
            }
        }
    }

    close(socketfd);
    close(newsocketfd);
    return EXIT_SUCCESS;
}

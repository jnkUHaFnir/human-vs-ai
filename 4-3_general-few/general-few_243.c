#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, newsocketfd, n;
    char buffer[256];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Server setup code skipped for brevity

    while (1) {
        if ((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
            buffer[n] = '\0'; // Null-terminate the received message
            printf("(Message length %d) message from Client: %s\n", n, buffer);
        } else {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message\n");
        }

        if (strcmp("q", buffer) == 0) {
            printf("Client requested to close the connection\n");
            break;
        } else {
            printf("Data received from the client: %s\n", buffer);
        }

        if (write(newsocketfd, "Response from server", 20) > 0) {
            printf("Writing response to Client socket\n");
        } else {
            error("Error writing message\n");
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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int socketfd, n;
    char buffer[256];
    struct sockaddr_in server_addr;

    // Client setup code skipped for brevity

    do {
        printf("Please, type your message: ");
        bzero(buffer, 256); // Clear the buffer
        fgets(buffer, 255, stdin);
        
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove the newline character
        }

        n = write(socketfd, buffer, strlen(buffer) + 1); // Include the null terminator
        if (n < 0) {
            error("Error writing to socket\n");
        } else {
            printf("Message sent\n");

            n = read(socketfd, buffer, sizeof (buffer));
            if (n < 0) {
                error("Error reading from socket\n");
            } else {
                printf("Message from server: %s\n", buffer);
            }
        }
    } while (strcmp("q", buffer) != 0);

    close(socketfd);

    return EXIT_SUCCESS;
}

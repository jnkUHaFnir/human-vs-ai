#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Setup address structure
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Initialize file descriptor set for select
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(clientSocket, &readfds);

    int activity, valread;
    char buffer[MAX_BUFFER_SIZE] = {0};

    while (1) {
        // Select for read
        activity = select(clientSocket + 1, &readfds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR)) {
            printf("Select error");
        }

        if (FD_ISSET(clientSocket, &readfds)) {
            // Read data from server
            valread = read(clientSocket, buffer, MAX_BUFFER_SIZE);
            if (valread == 0) {
                printf("Server disconnected\n");
                break;
            } else if (valread < 0) {
                printf("Error reading from server\n");
                break;
            }

            printf("Server response: %s\n", buffer);

            // Do something with the data received

            // Clear the buffer
            memset(buffer, 0, MAX_BUFFER_SIZE);
        }
    }

    close(clientSocket);

    return 0;
}

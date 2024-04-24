#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, max_sd, activity, valread;
    int client_sockets[MAX_CLIENTS] = {0};
    fd_set readfds;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    // Create a server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set non-blocking mode for the server socket
    fcntl(server_fd, F_SETFL, O_NONBLOCK);

    // Bind and listen
    // Initialize address struct...
    
    // Add server_fd to readfds set
    FD_SET(server_fd, &readfds);
    max_sd = server_fd;

    while (1) {
        // Copy the file descriptor set
        fd_set temp_fds = readfds;

        // Wait for activity on any socket
        activity = select(max_sd + 1, &temp_fds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR)) {
            perror("select error");
        }

        // Check if there is activity on the server socket
        if (FD_ISSET(server_fd, &temp_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            // Set non-blocking mode for the new_socket
            fcntl(new_socket, F_SETFL, O_NONBLOCK);

            // Add the new_socket to the client_sockets array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;

                    // Add the new_socket to the readfds set
                    FD_SET(new_socket, &readfds);
                    if (new_socket > max_sd) {
                        max_sd = new_socket;
                    }
                    break;
                }
            }
        }

        // Check data from clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (FD_ISSET(sd, &temp_fds)) {
                if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    // Client disconnected
                    close(sd);
                    client_sockets[i] = 0;
                    FD_CLR(sd, &readfds);
                } else {
                    // Handle incoming data
                    // Process the received data...

                    // Clear the buffer
                    memset(buffer, 0, BUFFER_SIZE);
                }
            }
        }
    }

    return 0;
}

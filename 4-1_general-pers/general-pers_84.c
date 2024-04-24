#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Server IP address

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return 1;
    }

    // Set up the POST request
    char *post_data = "Hello, server!";
    char request[1024];
    snprintf(request, sizeof(request), "POST / HTTP/1.1\r\nContent-Length: %ld\r\n\r\n%s",
             strlen(post_data), post_data);

    // Send the POST request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending data");
        close(sockfd);
        return 1;
    }

    // Receive the response
    char response[1024];
    ssize_t bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        close(sockfd);
        return 1;
    }

    // Print the response
    response[bytes_received] = '\0';
    printf("Response from server:\n%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}

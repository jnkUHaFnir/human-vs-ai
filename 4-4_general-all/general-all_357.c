#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define POST_DATA "key1=value1&key2=value2"

void sendHttpPostRequest() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return;
    }

    // Initialize server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(sockfd);
        return;
    }

    // Send the HTTP POST request
    const char *postRequest = "POST / HTTP/1.1\r\nHost: localhost\r\nContent-Length: %zu\r\n\r\n%s";
    char requestBuffer[1024];
    sprintf(requestBuffer, postRequest, strlen(POST_DATA), POST_DATA);
    send(sockfd, requestBuffer, strlen(requestBuffer), 0);

    // Close the socket
    close(sockfd);
}

int main() {
    sendHttpPostRequest();
    return 0;
}

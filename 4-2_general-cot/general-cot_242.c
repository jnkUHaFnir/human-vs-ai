#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_MSG_SIZE 1024

struct Message {
    size_t length;
    char contents[MAX_MSG_SIZE - sizeof(size_t)];
};

int main() {
    struct Message message;
    // Fill in the message struct with the information you want to send

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    send(clientSocket, &message, sizeof(message), 0);

    close(clientSocket);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_MSG_SIZE 1024

struct Message {
    size_t length;
    char contents[MAX_MSG_SIZE - sizeof(size_t)];
};

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr, clientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    listen(serverSocket, 5);
    int clientSocket = accept(serverSocket, NULL, NULL);

    struct Message message;
    recv(clientSocket, &message, sizeof(message), 0);

    // Use the received message struct here

    close(serverSocket);
    close(clientSocket);

    return 0;
}

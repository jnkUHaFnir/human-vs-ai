#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define MAXPENDING 100

int main() {

    char get[] = "GET";
    char head[] = "HEAD";
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&serverAddress.sin_zero, '\0', 8);

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, MAXPENDING);

    for (;;) {
        struct sockaddr_in clientAddress;
        int clientAddressLength = sizeof(clientAddress);
        int clientSocket;

        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);

        char buf[BUFSIZE];
        int bytesRec;

        while ((bytesRec = recv(clientSocket, buf, BUFSIZE, 0)) > 0) {
            buf[bytesRec] = '\0'; // Null-terminate received data

            char *result;
            result = strtok(buf, " ");

            printf("result: %s\n", result);

            if (strcmp(result, get) == 0) {
                char answer[] = "You want GET";
                send(clientSocket, answer, strlen(answer), 0);
            } else if (strcmp(result, head) == 0) {
                char answer[] = "You want HEAD";
                send(clientSocket, answer, strlen(answer), 0);
            } else {
                char answer[] = "HTTP/1.1 400 Bad Request";
                send(clientSocket, answer, strlen(answer), 0);
            }
        }
        close(clientSocket); // Close the client socket
    }

    return 0;
}

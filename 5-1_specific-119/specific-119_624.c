#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE         1024
#define MAXPENDING      100

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

        bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
        while (bytesRec > 0) {

            char *result;
            result = strtok(buf, " \n"); // Added newline character as a delimiter

            printf("result %s\n", result);

            if (strcmp(result, get) == 0) {
                char answer[] = "You want GET";
                send(clientSocket, answer, strlen(answer), 0);
            } else {
                if (strcmp(result, head) == 0) {
                    char answer[] = "You want HEAD";
                    send(clientSocket, answer, strlen(answer), 0);
                } else {
                    char answer[] = "HTTP/1.1 400 Bad Request";
                    send(clientSocket, answer, strlen(answer), 0);
                }
            }

            bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {

    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in clientAddress;
    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = 0;
    clientAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&clientAddress.sin_zero, '\0', 8/*sizeof(clientAddress.sin_zero)*/);

    bind(clientSocket, (struct sockaddr*)&clientAddress, sizeof(clientAddress));

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&serverAddress.sin_zero, '\0', 8);

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        printf("error in connecting!\n");
        return 0;
    }

    char serverReply[1024]; // Changed to array of chars

    for (;;) {
        char request[100];
        printf("Enter your request: ");
        scanf("%s", request); // Removed '&' before request
        strcat(request, "\n"); // Added newline character at the end of the request
        send(clientSocket, request, strlen(request), 0);
        if (recv(clientSocket, serverReply, sizeof(serverReply), 0) < 0) {
            printf("failure in receiving from server!\n");
        } else {
            printf("%s\n", serverReply);
        }
    }

    close(clientSocket);

    return 0;
}

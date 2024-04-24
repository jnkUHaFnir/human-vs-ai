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

    // Server configuration

    for (;;) {
        // Accept client connection

        char buf[BUFSIZE];
        int bytesRec;

        bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
        while (bytesRec > 0) {
            // Process client request

            char *token;
            char tempBuf[BUFSIZE];
            strcpy(tempBuf, buf);
            token = strtok(tempBuf, " ");

            if (strcmp(token, get) == 0) {
                char answer[] = "You want GET";
                send(clientSocket, answer, strlen(answer), 0);
            } 
            else if (strcmp(token, head) == 0) {
                char answer[] = "You want HEAD";
                send(clientSocket, answer, strlen(answer), 0);
            } 
            else {
                char answer[] = "HTTP/1.1 400 Bad Request";
                send(clientSocket, answer, strlen(answer), 0);
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

    // Client configuration

    for (;;) {
        char request[100];
        printf("Enter your request: ");
        scanf("%s", request);
        send(clientSocket, request, strlen(request), 0);

        char serverReply[1024]; // Changed from char* serverReply[1024];

        int receivedBytes = recv(clientSocket, serverReply, sizeof(serverReply), 0);
        if (receivedBytes < 0) {
            printf("Failure in receiving from server!\n");
        } else {
            serverReply[receivedBytes] = '\0'; // Ensure null termination
            printf("%s\n", serverReply);
        }
    }

    close(clientSocket);

    return 0;
}

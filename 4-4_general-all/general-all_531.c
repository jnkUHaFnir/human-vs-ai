#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE         1024
#define MAXPENDING      100

int main(){

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

    for(;;){
        struct sockaddr_in clientAddress;
        int clientAddressLength = sizeof(clientAddress);
        int clientSocket;

        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);

        char buf[BUFSIZE];
        int bytesRec;

        bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
        while(bytesRec > 0){

            buf[bytesRec] = '\0'; // Ensure received data is null-terminated

            char *result;
            result = strtok(buf, " ");

            printf("result %s\n", result);

            // Compare result with get and head without referencing the arrays
            if(strcmp(result, get) == 0){
                char answer[] = "You want GET";
                send(clientSocket, answer, strlen(answer), 0);
            }else if(strcmp(result, head) == 0){
                char answer[] = "You want HEAD";
                send(clientSocket, answer, strlen(answer), 0);
            }else{
                char answer[] = "HTTP/1.1 400 Bad Request";
                send(clientSocket, answer, strlen(answer), 0); 
            }

            bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
        }
        close(clientSocket); // Close the client socket after processing the request
    }
    close(serverSocket); // Close the server socket after finishing all requests

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(){

    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&serverAddress.sin_zero, '\0', 8);

    if(connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1){
        printf("error in connecting!\n");
        return 1;
    }

    char serverReply[1024]; // Changed to char array from char pointer

    for(;;){
        char request[100];
        printf("Enter your request: ");
        scanf("%s", request); // Removed unnecessary & before request

        send(clientSocket, request, strlen(request), 0);
        int bytesReceived = recv(clientSocket, serverReply, sizeof(serverReply), 0);

        if(bytesReceived < 0){
            printf("failure in receiving from server!\n");
        }else{
            serverReply[bytesReceived] = '\0'; // Ensure received data is null-terminated
            printf("%s\n", serverReply);
        }
    }

    close(clientSocket);

    return 0;
}

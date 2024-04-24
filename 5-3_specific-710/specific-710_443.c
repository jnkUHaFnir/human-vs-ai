#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define MESSAGE_SIZE 256

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char message[MESSAGE_SIZE + 1]; // +1 for null terminator
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");
    
    listen(sockfd, 5);
    
    clilen = sizeof(cli_addr);
    
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    
    if (newsockfd < 0) 
        error("ERROR on accept");

    bzero(message, MESSAGE_SIZE + 1);
    
    n = read(newsockfd, message, MESSAGE_SIZE);
    
    if (n < 0) 
        error("ERROR reading from socket");
    
    printf("Here is the message: %s\n", message);
    
    n = write(newsockfd, "U got your message", 17); // Response message length is fixed
    
    if (n < 0) 
        error("ERROR writing to socket");
    
    close(newsockfd);
    close(sockfd);
    
    return 0; 
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define MESSAGE_SIZE 256

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char message[MESSAGE_SIZE + 1]; // +1 for null terminator
    
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    server = gethostbyname(argv[1]);
    
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    
    printf("Please enter the message: ");
    bzero(message, MESSAGE_SIZE + 1);
    fgets(message, MESSAGE_SIZE, stdin);
    
    n = write(sockfd, message, strlen(message));
    
    if (n < 0) 
        error("ERROR writing to socket");
    
    bzero(message, MESSAGE_SIZE + 1);
    
    n = read(sockfd, message, MESSAGE_SIZE);
    
    if (n < 0) 
        error("ERROR reading from socket");
    
    printf("%s\n", message);
    
    close(sockfd);
    
    return 0;
}

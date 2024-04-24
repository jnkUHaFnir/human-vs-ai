#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVERPORT "4950"    // the port users will be connecting to
#define MAXBUFLEN 100

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;
    struct sockaddr_storage their_addr;
    socklen_t addr_len;
    char buf[MAXBUFLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and make a socket
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                              p->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        // Bind to the desired source port
        struct sockaddr_storage my_addr;
        struct addrinfo my_hints;
        struct addrinfo *my_info;
        memset(&my_hints, 0, sizeof my_hints);
        my_hints.ai_family = p->ai_family;
        my_hints.ai_socktype = SOCK_DGRAM;
        my_hints.ai_flags = AI_PASSIVE;  // Use system-assigned outgoing address
        char my_port[] = "4950"; // Your desired source port

        if ((rv = getaddrinfo(NULL, my_port, &my_hints, &my_info)) != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
            return 1;
        }

        if (bind(sockfd, my_info->ai_addr, my_info->ai_addrlen) == -1) {
            perror("talker: bind");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "talker: failed to create socket or bind");
        return 2;
    }
    
    freeaddrinfo(servinfo);

    printf("Sending message to %s...\n", argv[1]);

    if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0,
                           p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }

    printf("Message sent. Waiting for response...\n");

    addr_len = sizeof their_addr;
    if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN , 0,
                             (struct sockaddr *)&their_addr, &addr_len)) == -1) {
        perror("talker: recvfrom");
        exit(1);
    }

    printf("Response received: %s\n", buf);

    close(sockfd);

    return 0;
}

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
    struct sockaddr_storage my_addr;  // Client's address structure
    int rv;
    int numbytes;
    struct sockaddr_storage their_addr;
    socklen_t addr_len;
    char buf[MAXBUFLEN];

    addr_len = sizeof their_addr;

    if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Loop through all the results and make a socket
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        // Client address setup
        memset(&my_addr, 0, sizeof my_addr);
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *my_addr_ipv4 = (struct sockaddr_in*)&my_addr;
            my_addr_ipv4->sin_family = AF_INET;
            my_addr_ipv4->sin_port = htons(4950); // Fixed known source port
            inet_pton(AF_INET, "0.0.0.0", &my_addr_ipv4->sin_addr); // Bind to any local address
        } else if (p->ai_family == AF_INET6) { // IPv6
            struct sockaddr_in6 *my_addr_ipv6 = (struct sockaddr_in6*)&my_addr;
            my_addr_ipv6->sin6_family = AF_INET6;
            my_addr_ipv6->sin6_port = htons(4950); // Fixed known source port
            my_addr_ipv6->sin6_addr = in6addr_any; // Bind to any local address
        } else {
            fprintf(stderr, "Unsupported address family\n");
            return 1;
        }

        // Bind the client socket to the fixed source port
        if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
            perror("talker: bind");
            return 1;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }

    if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0,
             p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }

    freeaddrinfo(servinfo);

    printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);

    // Now, receive the response
    if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) {
        perror("talker: recvfrom");
        exit(1);
    }

    printf("Received packet\n");

    close(sockfd);

    return 0;
}

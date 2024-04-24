...

#define CLIENTPORT "4950" // the fixed, known source port number

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo hints, *servinfo, *p, *clientinfo, *q;
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

    // Set up hints for server
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    // Get server address info
    if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Set up hints for client
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; // Use local IP

    // Get client address info
    if ((rv = getaddrinfo(NULL, CLIENTPORT, &hints, &clientinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Loop through all results for client and server
    for (q = clientinfo; q != NULL; q = q->ai_next) {
        for (p = servinfo; p != NULL; p = p->ai_next) {
            if ((sockfd = socket(q->ai_family, q->ai_socktype, q->ai_protocol)) == -1) {
                perror("talker: socket");
                continue;
            }

            if (bind(sockfd, q->ai_addr, q->ai_addrlen) == -1) {
                close(sockfd);
                perror("talker: bind");
                continue;
            }

            break;
        }

        if (p != NULL) {
            break;
        }
    }

    if (q == NULL || p == NULL) {
        fprintf(stderr, "talker: failed to create socket or bind\n");
        return 2;
    }

    if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0,
             p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }

    freeaddrinfo(servinfo);
    freeaddrinfo(clientinfo);

    printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);

    // Receive response
    if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN , 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) {
        perror("talker: recvfrom");
        exit(1);
    }

    printf("talker: received %d bytes\n", numbytes);

    close(sockfd);

    return 0;
}

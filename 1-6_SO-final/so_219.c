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
    
    #define LOCALPORT  "4950"     // the port users will be sending from
    #define SERVERPORT "4950"    // the port users will be connecting to
    #define MAXBUFLEN  65535
    
    int main(int argc, char *argv[])
    {
        int sockfd;
        struct addrinfo hints, *myinfo, *servinfo, *pserv, *plocal;
        int rv;
        int numbytes;
        char buf[MAXBUFLEN]; 
        char ipstr[INET6_ADDRSTRLEN];
        fd_set readfds;
        struct timeval tv;
        bool stop = false;
    
        if (argc < 3) {
            fprintf(stderr, "usage: talker destaddr message [localaddr]\n");
            return 1;
        }
    
        // get all of the server addresses
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_DGRAM;
        hints.ai_protocol = IPPROTO_UDP;
    
        if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
            return 2;
        }
    
        // loop through all the server addresses
        for(pserv = servinfo; (pserv != NULL) && (!stop); pserv = pserv->ai_next) {
            // get all of the matching local addresses
            memset(&hints, 0, sizeof hints);
            hints.ai_family = pserv->ai_family;
            hints.ai_socktype = pserv->socktype;
            hints.ai_protocol = pserv->protocol;
    
            if ((rv = getaddrinfo(argc > 3 ? argv[3] : NULL, LOCALPORT, &hints, &myinfo)) != 0) {
                fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
                continue;
            }
    
            // loop through all the local addresses, sending the
            // message from each one until a reply is received
            for(plocal = myinfo; (plocal != NULL) && (!stop); plocal = plocal->ai_next) {
                if ((sockfd = socket(plocal->ai_family, plocal->ai_socktype, plocal->ai_protocol)) == -1) {
                    perror("socket");
                    continue;
                }
    
                // make sure this server address is the only one we talk to
                if (connect(sockfd, pserv->ai_addr, pserv->ai_addrlen) == -1) {
                    perror("connect");
                    close(sockfd);
                    continue;
                }
    
                if ((numbytes = send(sockfd, argv[2], strlen(argv[2]), 0)) == -1) {
                    perror("send");
                    close(sockfd);
                    continue;
                }
    
                memset(ipstr, 0, sizeof(ipstr));
                switch (pserv->ai_family)
                {
                    case AF_INET:
                        inet_ntop(AF_INET, &(((struct sockaddr_in*)pserv->ai_addr)->sin_addr), ipstr, INET_ADDRSTRLEN);
                        break;
                    case AF_INET6:
                        inet_ntop(AF_INET6, &(((struct sockaddr_in6*)pserv->ai_addr)->sin6_addr), ipstr, INET6_ADDRSTRLEN);
                        break;
                }
    
                printf("talker: sent %d bytes to %s\n", numbytes, ipstr);
    
                FD_ZERO(&readfds);
                FD_SET(sockfd, &readfds);
    
                tv.tv_sec = 5;
                tv.tv_usec = 0;
    
                rv = select(sockfd+1, &readfds, NULL, NULL, tv);
                if (rv == -1)
                {
                    perror("select");
                    close(sockfd);
                    continue;
                }
    
                if (rv == 0)
                {
                    printf("talker: no reply for 5 seconds\n");
                    close(sockfd);
                    continue;
                }
    
                if ((numbytes = recv(sockfd, buf, MAXBUFLEN, 0)) == -1) 
                {
                    perror("recv");
                    close(sockfd);
                    continue;
                }
    
                printf("talker: received %d bytes from %s\n", numbytes, ipstr);
    
                close(sockfd);
    
                stop = true;
                break;
            }
    
            freeaddrinfo(myinfo);
        }
    
        freeaddrinfo(servinfo);
    
        close(sockfd);
    
        return 0;
    }
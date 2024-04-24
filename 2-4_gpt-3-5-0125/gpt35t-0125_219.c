struct addrinfo hints, *servinfo, *p, *myinfo;
int rv;
int numbytes;
struct sockaddr_storage their_addr;
socklen_t addr_len;
addr_len = sizeof their_addr;

if (argc != 3) {
    fprintf(stderr,"usage: talker hostname message\n");
    exit(1);
}

memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_DGRAM;

if ((rv = getaddrinfo(NULL, SERVERPORT, &hints, &myinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
}

// Loop through myinfo to find the suitable address
struct sockaddr *my_addr = myinfo->ai_addr;
socklen_t my_addr_len = myinfo->ai_addrlen;

if (bind(sockfd, my_addr, my_addr_len) < 0) {
    perror("talker: bind");
    exit(1);
}
if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0,
        p->ai_addr, p->ai_addrlen)) == -1) {
    perror("talker: sendto");
    exit(1);
}
if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) {
    close(sockfd);
    perror("talker: recvfrom");    
    exit(1);
}

close(sockfd);

printf("Got packet\n");

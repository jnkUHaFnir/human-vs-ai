if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
    perror("talker: socket");
    continue;
}

// Create a placeholder for the client socket address
struct sockaddr_storage client_addr;
memset(&client_addr, 0, sizeof client_addr);

if (p->ai_family == AF_INET) { // IPv4
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)&client_addr;
    ipv4->sin_family = AF_INET;
    ipv4->sin_addr.s_addr = INADDR_ANY;
    ipv4->sin_port = htons(4950); // Fixed source port number
} else { // IPv6
    struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)&client_addr;
    ipv6->sin6_family = AF_INET6;
    ipv6->sin6_addr = in6addr_any;
    ipv6->sin6_port = htons(4950); // Fixed source port number
}

// Bind the client socket to the fixed source port
if (bind(sockfd, (struct sockaddr *)&client_addr, sizeof client_addr) == -1) {
    perror("talker: bind");
    exit(1);
}

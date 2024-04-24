/* socket */
if ((context->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("Failed to create socket");
    exit(-1);
}

/* connect */
if (connect(context->socket, &context->tx_addr, sizeof(struct sockaddr)) != 0) {
    perror("Couldn't connect to server");
    exit(-1);
}

/* create header */
snprintf(context->packet, BUFF_SIZE,
         "GET %s HTTP/1.1\r\n" \
         "Host: %s\r\n\r\n", 
         conf->request, conf->host);

/* send header */
ssize_t sent_bytes = send(context->socket, context->packet, strlen(context->packet), 0);
if (sent_bytes < 0) {
    perror("Failed to send");
    exit(-1);
}

/* receive response */
ssize_t received;
while ((received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0)) > 0) {
    context->packet[received] = '\0';
    printf("%s", context->packet);
}

if (received < 0) {
    perror("Failed to receive");
    exit(-1);
}

close(context->socket); // Close the socket after receiving the response

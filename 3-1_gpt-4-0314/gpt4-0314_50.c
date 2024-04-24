/* socket */
if ((context->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("Failed to create socket");
    exit(-1);
}

/* connect */
if (connect(context->socket, (struct sockaddr*)&context->tx_addr, sizeof(struct sockaddr)) != 0) {
    perror("Couldn't connect to server");
    exit(-1);
}

/* create header */
snprintf(context->packet, BUFF_SIZE,
         "GET %s HTTP/1.1\r\n" \
         "Host: %s\r\n" \
         "Connection: close\r\n\r\n", 
         conf->request, conf->host);

/* send header */
int packet_len = strlen(context->packet);
if ((send(context->socket, context->packet, packet_len, 0)) != packet_len) {
    perror("Failed to send");
    exit(-1);
}

/* receive response */
do {
    if ((received = recv(context->socket, context->packet, BUFF_SIZE, 0)) < 0) {

        /* THIS is where RST occurs with some servers */

        perror("Failed to receive");
        exit(-1);
    }

    if (received >= 0)     
            context->packet[received] = '\0';
    printf("%s", context->packet);

} while (received > 0);

// Close the socket
close(context->socket);

/* socket */
if ((context->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("Failed to create socket");
    exit(-1);
}

/* connect */
if (connect(context->socket, (const struct sockaddr *)&context->tx_addr, sizeof(struct sockaddr)) != 0) {
    perror("Couldn't connect to server");
    exit(-1);
}

/* create header */
int header_length = snprintf(context->packet, BUFF_SIZE,
                             "GET %s HTTP/1.1\r\n" \
                             "Host: %s\r\n" \
                             "Connection: keep-alive\r\n\r\n",  // Optional: keep-alive header
                             conf->request, conf->host);
if (header_length >= BUFF_SIZE) {
    fprintf(stderr, "Header too large for buffer");
    exit(-1);
}

/* send header */
if ((send(context->socket, context->packet, header_length, 0)) != header_length) {
    perror("Failed to send");
    exit(-1);
}

/* receive response */
do {
    received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0);
    if (received < 0) {
        // Handle RST or other recv errors
        perror("Failed to receive");
        exit(-1);
    } else if (received == 0) {
        // Graceful closure by the server
        break;
    }

    context->packet[received] = '\0';
    printf("%s", context->packet);

} while (received > 0);

// Optional: graceful shutdown sequence
shutdown(context->socket, SHUT_WR);
while ((received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0)) > 0) {
    // Optionally, process any remaining data
}
close(context->socket);

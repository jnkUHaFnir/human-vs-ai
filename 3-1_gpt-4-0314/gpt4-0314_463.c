/* create header */
snprintf(context->packet, BUFF_SIZE,
         "GET %s HTTP/1.1\r\n" \
         "Host: %s\r\n" \
         "Connection: close\r\n\r\n", 
         conf->request, conf->host);
/* create header */
snprintf(context->packet, BUFF_SIZE,
         "GET %s HTTP/1.1\r\n" \
         "Host: %s\r\n" \
         "Connection: keep-alive\r\n\r\n", 
         conf->request, conf->host);
/* send header */
if ((send(context->socket, context->packet, strlen(context->packet), 0)) != strlen(context->packet)) {
    perror("Failed to send");
    exit(-1);
}

/* receive response */
do {
    if ((received = recv(context->socket, context->packet, BUFF_SIZE, 0)) < 0) {

        /* THIS is where RST occurs with some servers */

        perror("Failed to receive");
        exit(-1)
    }

    if (received >= 0)     
            context->packet[received] = '\0';
    printf("%s", context->packet);

} while (received > 0);

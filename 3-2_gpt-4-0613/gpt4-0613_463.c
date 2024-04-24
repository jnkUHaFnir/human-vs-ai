int len = strlen(context->packet);
if ((send(context->socket, context->packet, len, 0)) != len) {
    perror("Failed to send");
    exit(-1);
}
do {
    if ((received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0)) < 0) {

        /* THIS is where RST occurs with some servers */

        perror("Failed to receive");
        exit(-1)
    }

    if (received >= 0)     
            context->packet[received] = '\0';
    printf("%s", context->packet);

} while (received > 0);
